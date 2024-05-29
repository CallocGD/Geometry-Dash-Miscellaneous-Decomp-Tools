"""Sometimes Ghidra Produces some Very BullShit Code when decompiling C++. 
This tool attempts to take out a lot of stress from editing the code  """

import re
import click 
from pathlib import Path 

# def read():
#     with open("test.cpp", "r") as r:
#         code = r.read()
#     return code

def fix_nulls(code:str):
    return re.sub(r"\([A-Za-z0-0]+\s\*\)0x0" , "nullptr", code)

def remove_this(code:str):
    return code.replace("this->", "")

def strip_wanrings(code:str):
    return code.replace("/* WARNING: Subroutine does not return */", "")

def remove_unimportant_calls(code:str):
    return re.sub(r"NAN\(([^\)]+)\)", r"\1", code)


def cancel_matching_pairs(code:str):
    better_code = code 
    for m in re.finditer(r"(\w+)\s\=\s(\w+);", code):
        if m.group(1) == m.group(2):
            better_code = better_code.replace(m.group(0), "")
    return better_code


WRAPPED_COCOS2D_VTABLES = re.compile(r"\(\*\(code\s\*\)(m_[A-Za-z0-9]+)->vtable->cocos2d_[^_]+_(\w+)\)\s*\(([^\)]*)\);", re.MULTILINE)

def unwrap_cocos2d_vtable_calls(code:str):
    """Cleans up Compiler optimizations from ghidra vtables that look like this 
        ```c++
        (*(code *)m_sprite->vtable->cocos2d_CCSprite_setOpacity)(m_sprite,0)
        ```
        to this 
        ```c++
        m_sprite->setOpacity(0)
        ```
        WARNING! this currently may only work with some cocos2d objects
    """
    better_code = code
    for m in WRAPPED_COCOS2D_VTABLES.finditer(code):
        caller, func, _args = m.groups()

        # Fix arguments related to the first member and then refix the arguments in the function
        args = _args.split(",")
        if args and args[0] == caller:
            # remove if first member and caller match
            args.pop(0)
        args = [a.replace(" ", "") for a in args]
        
        # Create our new call to replace the old vtable call
        new_call = caller + "->"  + func + F"({','.join(args)})"
        print("[DEBUG] ", new_call)
        better_code = better_code.replace(m.group(0), new_call)
    return better_code

def fix_strings(code:str):
    return re.sub(r"std::basic_string::\~basic_string\((?:[^;]+);", "", code, flags=re.MULTILINE)\
        .replace("std::basic_string::basic_string(", "std::string(")


def fix_arguments_in_calls(code:str):
    """Experimentally replaces (hell o) with (hello)"""
    better_code = code
    for x in re.finditer(r"\(([^\)]+)\)", code):
        for arg in x.group(0).split(","):
            if re.match(r"[A-Za-z0-9]+\s[A-Za-z0-9]+", arg):
                _arg = arg
                arg = arg.replace(" ", "")
                better_code.replace(_arg, arg)
    return better_code

def fix_this_call(code:str):
    better_code = code
    for m in re.finditer(r"(\w+) __thiscall ([^\(]+)\((\w+\s+\*this)([^\)]+)\)", code , flags=re.M):
        ret, func, _ , args = m.groups()
        # Fix torn up arguments that look like this  ->  (m ytools)
        args = [a.replace(" ", "") for a in args]
        new_code = ret + " " + func + "(" + args.lstrip(",") + ")"
        better_code = better_code.replace(m.group(0) , new_code)
    return better_code


def fix_spaces(code:str):
    better_code = []
    for line in code.splitlines():
        # print("DEBUG LINE %s" % line)
        if line.strip():
            # Provide an extra line before if checks
            if line.strip().startswith(("if", "else")):
                better_code.append("")
            
            spaces = line[:line.find(line.strip()[0])]
            if "\t" in spaces:
                better_code.append(spaces.replace("\t", "    ") + line.strip())
            if " " in spaces:
                better_code.append((spaces * 2) + line.strip())
            else:
                better_code.append(line.strip())
        else:
            better_code.append(line)
    
    return "\n".join(better_code)



@click.command()
@click.argument("file", type=str)
def main(file:str):
    """Modifies Ghidra code automatically in an attempt to take out the stress of needing to edit some parts of code over to C++"""
    code = Path(file).read_text()
    new_code = unwrap_cocos2d_vtable_calls(cancel_matching_pairs(remove_this(fix_nulls(code))))
    code = remove_unimportant_calls(fix_arguments_in_calls(fix_this_call(fix_strings(new_code))))
    print(cancel_matching_pairs(fix_spaces(strip_wanrings(code))))

if __name__ == "__main__":
    main()
