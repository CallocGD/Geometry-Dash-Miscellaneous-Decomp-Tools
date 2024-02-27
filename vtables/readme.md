# VTables

These Are Meant To be class Tables for Libcoscos and Geometry Dash class Objects as [Ghidra has no way of resolving VTables To help me figure out what's being called](https://github.com/NationalSecurityAgency/ghidra/issues/516) 
And My code still has Missing VTables With Unknown Function Calls.


```c++
/* NOTE: Ghidra decompiled this and I resolved almost all of it's class members on android v2.205 
CCTextInputNode::addTextArea(TextArea*) */

void __thiscall CCTextInputNode::addTextArea(CCTextInputNode *this,TextArea *tArea)

{
  char *__s;
  TextArea *_textArea;
  code *pcVar1;
  undefined8 uVar2;
  undefined auStack_30 [4];
  undefined auStack_2c [8];
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (this->m_textArea == (TextArea *)0x0) {
    this->m_textArea = tArea;
    uVar2 = (*(code *)this->field0_0x0[0x37])();
    _textArea = this->m_textArea;
    pcVar1 = *(code **)(_textArea->field0_0x0 + 0x5c);
    cocos2d::CCPoint::CCPoint((CCPoint *)auStack_2c,(float)uVar2,(float)((ulonglong)uVar2 >> 0x20) );
    (*pcVar1)(_textArea,auStack_2c);
    (*(code *)this->m_textField->vtable[0x29])(this->m_textField,0);
    __s = (char *)(*(code *)this->m_textField->vtable[0x9a])();
    std::basic_string::basic_string((basic_string *)auStack_2c,__s,(size_t)auStack_30);
    updateLabel(this,(basic_string)auStack_2c);
    std::basic_string::~basic_string((basic_string *)auStack_2c);
    std::basic_string::basic_string((basic_string *)auStack_2c,&this->m_textArea->m_text);
    updateDefaultFontValues(this,(basic_string)auStack_2c);
    std::basic_string::~basic_string((basic_string *)auStack_2c);
  }
  if (local_24 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}
```

However I made a discovery on how to find this bullshit we want, cocos2dx's order in it's header file matches to its correct call following `CCScriptEngineProtocol`.
.So in order to find our function we want which it's adding to it's pointer by 4 we divide 4 by 4 and get 1, and when we go to our vtable we find that  `~CCScriptEngineProtocol` should be our correct answer  
```c++
/* Ghidra's Version cocos2d::CCScriptEngineManager::removeScriptEngine() */

void __thiscall cocos2d::CCScriptEngineManager::removeScriptEngine(CCScriptEngineManager *this)

{
  if ((int *)this->m_pScriptEngine != (int *)0x0) {
    (**(code **)(*(int *)this->m_pScriptEngine + 4))();
    this->m_pScriptEngine = (CCScriptEngineProtocol *)0x0;
  }
  return;
}
```

And when we go to the actual code we find that we are indeed correct.

```c++
/* Actual C++ function */
void CCScriptEngineManager::removeScriptEngine(void)
{
    if (m_pScriptEngine)
    {
        delete m_pScriptEngine;
        m_pScriptEngine = NULL;
    }
}
```
Based on this knowelege it means that our vtable for `CCScriptEngineProtocol` should be laid out in this order 
```
~CCScriptEngineProtocol
getScriptType
removeScriptObjectByCCObject
removeScriptHandler    
reallocateScriptHandler    
executeString    
executeScriptFile
executeGlobalFunction
executeNodeEvent
executeMenuItemEvent
executeNotificationEvent
executeCallFuncActionEvent
executeSchedule
executeLayerTouchesEvent
executeLayerTouchEvent
executeLayerKeypadEvent
executeAccelerometerEvent
executeEvent  
executeEventWithArgs
handleAssert
parseConfig
```
Since Ghidra has problems with finding virtual functions that prevent me from learning the shit I want to know about. 
I will be dumping all the correct Vtables for cocos2d and Geometry dash class objects into this repository and I will 
be writing a python script to call upon them so that we can eventually reverse engineer any parts of Geometry Dash we 
need without any issues. This way class objects such as `CCTextInputNode` will be completely reverse engineered correctly 
and without any issues which will help me be able to better understand stuff such as Geometry Dash's Swearword filter. I 
will also make a script for building out subclass vtables based on how they should be written in C++.

I will write a simple example on how to use the python scripts soon.





