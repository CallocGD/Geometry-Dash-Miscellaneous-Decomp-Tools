"""
I use this script to fix and get rid of annoyances and incorrectly decompiled code in ghidra where 
any code for cocos2d::CCString::createWithFormat isn't written correctly. This takes away the burden 
of reading and overriding all signatures in ghidra by hand especially long ones like 
cocos2d::CCString::createWithFormat("%i_%s_%s_%s_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i_%i");
"""


import re 
import pyperclip


def write_CCFormat_Signature(STR:str):
    code = "cocos2d::CCString::createWithFormat(char* format,"
    data = []
    # TODO Write a C++ Version based on how printf works which will allow for more format keywords to be utilized such as %zu , %lu  %d etc... 
    for m in re.findall(r"\%[A-Za-z]", STR):
        if m[1] == 'i':
            data.append('int')
        elif m[1] == 's':
            data.append("char*")
        elif m[1] == 'c':
            data.append("char")

    code += ','.join(data) + ")"
    return code

if __name__ == "__main__":
    fmt = input("Enter in the string to format:")
    sig = write_CCFormat_Signature(fmt)
    print(sig)
    pyperclip.copy(sig)
    print("Your Code has been copied to your clipboard")
