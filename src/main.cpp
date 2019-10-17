//#include <setup.h>
#include <commonlibs.h>

void run();
#ifdef DEBUG
void test();
#endif

void loop() {
    if(ps2.available()){
        test();
    }*/
    test();
}

void run(){
    //read status
    checkLeds();
    detected = detect(ps2.read());

    if(detected != 0){
        #ifdef DEBUG
        Serial.print("\nHIDCODE: ");
        Serial.println(detected);
        #endif
        if(translatorOn){
            translate(detected);
        }else{
            passthrough(detected);
        }
    }
}
#ifdef DEBUG
void test() {
    delay(2000);
    uint8_t status = Keyboard.getLedStatus();
    Serial.print("CPSLOCK: ");
    Serial.print(status & LED_CAPS_LOCK);
    Serial.print("NUMLOCK: ");
    Serial.print(status & LED_NUM_LOCK);
    Serial.print("SCRLOCK: ");
    Serial.print(status & LED_SCROLL_LOCK);
    
    Serial.println();
}
#endif