"""
This script was built to write multiple RSV values at a time.
I wrote this script mainly because Macros just didn't feel 
readable enough or cut it for me. So my next best idea was 
simply auto-generate the code... 

I left an example of what an input file looks like so that none of you 
are confused you can test it with 

```
python write_multiple_rsvs.py --file test-input.txt
```
"""

import click
import pyperclip

def write_rsv(function:str, value:str):
    """Used for writing reverse engineered Geometry Dash code Mainly C++ RSV Values
        RSV Stands for random-seed-value. It is primarly used for geometry dash's 
        rng patterns in game"""

    code = "void %s(int %s){\n" % (function, value.removeprefix("m_"))
    # Set Value
    code += f"    {value} = {value.strip("m_")};\n"
    # Set Seed
    code += f"    {value}_Seed = (int)((float)rand() / 32767.0) * 1000.0;\n"
    # Set Random
    code += f"    {value}_Random = {value}_Seed + {value};\n"
    # Close Void Function
    code += "}\n"

    return code 


def write_multiple(RSVs:list[tuple[str]]) -> str:
    code:str = "/* -- RSV Values -- \n  * It is primarly used for geometry dash's rng patterns in game \n */\n\n"
    code += "\n".join(write_rsv(*rsv) for rsv in RSVs)
    return code

def read_functions(file:str):
    with open(file, "r") as r:
        for l in r:
            if l.strip():
                a, b = map(lambda x:x.strip() , l.split(",", 1))
                print((a, b))
                yield a, b

@click.command
@click.option("--file", prompt=True, type=click.Path(file_okay=True, dir_okay=False, readable=True))
def write_all(file:str):
    """Writes Many RSV Setting functions"""
    code = write_multiple(list(read_functions(file)))
    print(code)
    pyperclip.copy(code)
    print("Code Generated...")

if __name__ == "__main__":
    write_all()
