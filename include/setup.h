//#define CDCCON_DISABLE //TOGLI IL COMMENTO SOLO SE SEI SICURO CHE IL PROGRAMA SIA OK!!!

#ifndef CDCCON_DISABLE
    #define DEBUG
#endif

#define USBCON
#define IRQ_PIN   3 //Data+ (green)
#define DATA_PIN  5 //Data- (white)

#define TRANSLATE_PIN 7

#include <commonlibs.h>

PS2KeyRaw ps2;

#include <t_leds.h>
#include <w_passthrough.h>
#include <w_translate.h>

bool translatorOn;

void setup() {
    //if i'm still in test phase
    #ifdef DEBUG
    Serial.begin(9600);
    while (!Serial) ;
    #endif

    //initializing PS2 and HID
    ps2.begin(DATA_PIN,IRQ_PIN);
    _initKeyboard();

    //getting operation mode
    pinMode(TRANSLATE_PIN, INPUT_PULLUP);
    translatorOn = (digitalRead(TRANSLATE_PIN) == LOW);

    Serial.print("Status: ");
    Serial.println(translatorOn ? "TRANSLATE":"PASSTROUGH");
}