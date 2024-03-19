from cxxheaderparser.simple import parse_string, ClassScope
from cxxheaderparser.types import BaseClass, AnonymousName, Pointer, Array
import orjson 
from typing import NamedTuple
from models import Class, start_db, Subclass, merge_many, Members


class ClassData(NamedTuple):
    name:str
    subclasses:list[str] = []
    members:list[tuple[str,str]] = []

    def to_orm(self, scope:dict[str, "ClassData"]):
        return Class(name=self.name, members=[Members(name=m[1], type=m[0]) for m in self.members], subclasses=[Subclass(ref=scope[sub].to_orm(scope)) for sub in self.subclasses])

    def to_dict(self):
        return {"name":self.name, "subclasses":self.subclasses, "members":[{"name":v,"type":k} for k, v in self.members]}
     


class SubClassData(NamedTuple):
    """A Subclass with all class members of it's base and subclasses mixed into one"""
    name:str
    members:list[tuple[str,str]] = []
    subclasses:list[str] = []
    @classmethod
    def from_scope(cls, current:ClassData, scope:dict[str, ClassData]):
        members:list[tuple[str,str]] = []
        for sub in current.subclasses:
            members.extend(scope[sub].members)
        members.extend(current.members)
        return cls(name=current.name, members=members, subclasses=current.subclasses)

    @property
    def typedef(self):
        return f"typedef struct {self.name} {self.name};"

    @property
    def struct_code(self):
        if self.subclasses:
            code = "/* " + ", ".join(self.subclasses) +  " */\n"
        else:
            code = ""
        code += f"struct {self.name}" + " {\n"
        code += "    void* vtable;\n"
        for m in self.members:
            code += "    " + m[0].removeprefix("struct ") + " " + m[1] + ";\n"
        code += "};\n"
        return code
    

def to_struct_fields(scope:ClassScope):
    # fmt =  scope.class_decl.typename.format()
    # if fmt.startswith("enum"):
    #     code = fmt + "{"
    #     print(scope.__dict__)
    #     input("Hit to continue")
    #     return
    name = scope.class_decl.typename.format().split()[-1]
    if name.startswith("<"):
        return []
    
    fields = []
    seen = set()
    for f in scope.fields:
        if isinstance(f.type, Pointer):
            fields.append((f.type.format(),f.name))
        elif isinstance(f.type, Array):
            fields.append((f.type.format(),f.name))
        elif f.type.typename.has_typename:
            fields.append((f.type.format(),f.name))
        elif f.type.typename.classkey == "union":
            if f.name:
                fields.append(("void*", f.name)) # This is really a union and I'm overriding it - Calloc
        else:
            fields.append((f.type.format(),f.name))
        if f.name:
            seen.add(f.name)

    for c in scope.classes:
        for f in c.fields:
            if f.name and f.name not in seen:
                seen.add(f.name)
                if isinstance(f.type, (Pointer, Array)):
                    fields.append((f.type.format(),f.name))
                elif f.type.typename.has_typename:
                    fields.append((f.type.format(),f.name))
                elif f.type.typename.classkey == "union":
                    if f.name:
                        fields.append(("void*", f.name)) # This is really a union and I'm overriding it - Calloc
                else:
                    fields.append((f.type.format(),f.name))
    return fields

def translateBaseClass(base:BaseClass):
    segs = base.typename.segments
    if isinstance(segs[0], AnonymousName):
        print(segs[0])
    else:
        return segs[0].name

def obtain_subclasses(decl):
    if isinstance(decl.class_decl.typename.segments[0], AnonymousName):
        # print(decl.class_decl.typename.segments[0].__dict__)
        return None, None
    else:
        name = decl.class_decl.typename.segments[0].name
        return ClassData(name , [translateBaseClass(base) for base in decl.class_decl.bases], to_struct_fields(decl))
        

@start_db()
def main():
    print("parsing data.h...")
    data = parse_string(open("data.h", "r", encoding="utf-8").read())
    print("building scope")
    scope = {m.name:m for m in map(obtain_subclasses, data.namespace.classes) if isinstance(m, ClassData)}
    print("dumping to database")    
    merge_many([c.to_orm(scope) for c in scope.values()])
    print("dumpting contents to json...")
    with open("Cocos2d-class-members.json", "wb") as w:
        w.write(orjson.dumps({n:m.to_dict() for n, m in scope.items()}))
    print("finished")


if __name__ == "__main__":
    main()
    
