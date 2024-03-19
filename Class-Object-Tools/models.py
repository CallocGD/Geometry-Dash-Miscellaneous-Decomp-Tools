from sqlmodel import SQLModel, Field, select, Session, create_engine, Relationship, update
from typing import Optional, Callable, TypeVar, Generator
from typing_extensions import ParamSpec

P = ParamSpec("P")
T = TypeVar("T")




class Class(SQLModel, table=True):
    """Handles Geometry Dash Class object information"""
    name:str = Field(unique=True)
    id: Optional[int] = Field(default=None, primary_key=True)
    members:list["Members"] = Relationship(back_populates="ref")
    subclasses:list["Subclass"] = Relationship(back_populates="ref")
    vtable:list["VtableFunc"] = Relationship(back_populates="ref") 

    def allMembers(self):
        """Obtains all members and subclass members, this will also attempt to get the information of each of these in order..."""
        if self.subclasses:
            seen:set[str] = set()
            stack = self.subclasses.copy()
            while stack:
                subcls = stack.pop()
                if subcls.name in seen:
                    continue
                seen.add(subcls.name)
                for m in subcls.allMembers():
                    yield m
    
        # Subclass members have been iterated after this point so now get our memebers
        for m in self.members:
            yield m
    
    @property
    def subclass_names(self) -> list[str]:
        return [ref.name for ref in self.subclasses]

    def hasVtable(self):
        return True if self.vtable else False
    



class Members(SQLModel, table=True):
    name:str 
    type:str 
    id: Optional[int] = Field(default=None, primary_key=True)
    class_id:int = Field(default=None, foreign_key="class.id")
    ref:Class = Relationship(back_populates="members")
    """The Refrence back to the class object..."""


class Subclass(SQLModel, table=True):
    id: Optional[int] = Field(default=None, primary_key=True)
    class_id:int = Field(default=None, foreign_key="class.id")
    ref:"Class" = Relationship(back_populates="subclasses")
    """The subclass's class data"""

    @property
    def name(self) -> str:
        """Provides typehinting annotations for `self.data.name`"""
        return self.ref.name
    
    @name.setter
    def set_name(self, name:str):
        self.ref.name = name

    @property
    def members(self) -> list[Members]:
        return self.ref.members
    
    @members.setter
    def set_members(self, members:list[Members]):
        self.ref.members = members
    
    def allMembers(self) -> Generator[None, None, Members]:
        for m in self.ref.allMembers():
            yield m


class VtableFunc(SQLModel, table=True):
    """Handles Vtable Structures and calls for the android version of gd"""
    id: Optional[int] = Field(default=None, primary_key=True)
    callname:str 
    class_id:int = Field(default=None, foreign_key="class.id")
    ref:Optional[Class] = Relationship(back_populates="vtable")
    # TODO Add Parameter tools in a future update...
    def set_ref(self, c:Class):
        self.ref = c
        return self


engine = create_engine("sqlite:///CCDatabase.db", echo=True)


def start_db(echo:bool = True):
    """Starts the CCDatabase.db file"""
    def decorator(func:Callable[P, T]):
        def wrapper(*args:P.args, **kwargs:P.kwargs) -> T:
            # engine = create_engine("sqlite:///CCDatabase.db", echo=echo)
            SQLModel.metadata.create_all(engine)
            return func(*args, **kwargs)
        return wrapper
    return decorator



def merge_many(classes:list[Class]):
    with Session(engine) as session:
        for c in classes:
            session.merge(c)
        session.commit()

def get_class_by_name(name:str):
    with Session(engine) as session:
        result = session.exec(select(Class).where(Class.name == name)).one_or_none()
    return result

def update_class(_class:Class):
    with Session(engine) as session:
        session.merge(_class)
