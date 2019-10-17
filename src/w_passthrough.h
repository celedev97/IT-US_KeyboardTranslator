#include <keyboard_interpreter.h>

void passthrough(uint8_t detected){
    if(!release){
        keyPress(detected);
    }else{
        keyRelease(detected);
    }
}