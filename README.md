# Geometry-Dash-Miscellaneous-Decomp-Tools
A Slew of Miscellaneous Tools I will and others use to Decompile Geometry Dash however it is primarily focused around versions 2.2 and higher.


## Goals with this repository
- To Educate myself and others on how Geometry dash 2.2 works including missing parts of the code that have not been seen yet in [wyliemaster's decomp of 2.11](https://github.com/Wyliemaster/GD-Decompiled)
- A Readable Coscos2dx Header file that [Ghidra](https://github.com/NationalSecurityAgency/ghidra) will be able to understand and parse correctly including all the datatypes and their correct field types and names.
this will be very different [from this project](https://github.com/HJfod/cocos-headers) since classes will need to be transformed into C structures and fields
for libcoscos. Note that I am not using IDA Pro Since I am poor, hence why I will be making so many things easier to decompile in ghidra to provide a fair advantage.
- Making tools to port android's symbols to windows in the future if we can figure out how to port thunk functions
- I will be more focused around The HTTP Protocols and manager parts of Geometry dash's code As well as Understanding the `GameManager` and `GameLevelManager` to the highest degree possible but you are welcome to propose your own tools by making a pull-request or modifying any of the tools I make avalibe or dump into this repository. 
- Documentation of Geometry dash's functions belonging to the `GameLevelManager` and `GameManager` Class Objects Including Miscellaneous Objects That Decide to point out.
