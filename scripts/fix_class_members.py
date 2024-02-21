"""
Used for fixing RSV Values from the way geode them implemented to something else...

You can test this script with 

```
python fix_class_members.py --file GM_class_members.txt
```
"""

import click
import pyperclip


def split_RSV(_var:str):
    return f"\tint {_var}_Random;\n\tint {_var}_Seed;\n\tint {_var};"

def split_RS(_var:str):
    return f"\tint {_var}_Random;\n\tint {_var}_Seed;"

def split_VSR(_var:str):
    return f"\n\tint {_var}_Seed;\n\tint {_var};\n\tint {_var}_Random;"


def fix_value(line:str):
    _type, _var = line.strip().rsplit(' ', 1)
    _var = _var.rstrip(';')
    if 'gd::' in _type:
        _type = _type.replace('gd::', 'std::')
    elif 'geode::SeedValueRSV' in _type or 'geode::SeedValueRSV' == _type:
        return split_RSV(_var)
    elif 'geode::SeedValueRS' in _type or 'geode::SeedValueRS' == _type:
        return split_RS(_var)
    elif 'geode::SeedValueVSR' in _type or 'geode::SeedValueVSR' == _type:
        return split_VSR(_var)
    if 'geode::' in _type:
        return f'\t//' + _type + '  ' + _var + ';  // TODO: Fix this...'

    return f"\t{_type} {_var};"


def read_lines(file:str):
    with open(file,'r') as r:
        for line in r: 
            # Empty lines are prohibited...
            if line.strip():
                yield line


def write_multiple(lines:list[str]):
    return '\n'.join(map(fix_value, lines))
    


@click.command
@click.option('--file', prompt=True, type=click.Path(file_okay=True, dir_okay=False, readable=True))
def write_all(file:str):
    '''repairs and translates geode shit to readable class members...'''
    code = write_multiple(list(read_lines(file)))
    print(code)
    pyperclip.copy(code)
    print('Code Generated...')



if __name__ == "__main__":
    write_all()
