#ifndef KBOARD_IMPORTED_0
#define KBOARD_IMPORTED_0

#include <commonlibs.h>

bool release = false;
bool ddq = false;

bool CTRL = false;
bool SHIFT = false;
bool ALT = false;
bool WIN = false;

uint8_t detected;

Keyboard_ hidKeyboard;

void _initKeyboard(){
    hidKeyboard.begin();
}

void keyPress(uint8_t hid_code){
    #ifdef DEBUG
    Serial.print("KEY_PRESS: ");
    Serial.println(hid_code);
    #endif
    hidKeyboard.press(hid_code);
}

void keyRelease(uint8_t hid_code){
    #ifdef DEBUG
    Serial.print("KEYRELASE: ");
    Serial.println(hid_code);
    #endif
    hidKeyboard.release(hid_code);
}

uint8_t detect(int inputKey){
  if(inputKey == SCAN_RELEASE){
    release = true;
  }else if(inputKey == SCAN_DDQ){
    ddq = true;
  }else{
    uint8_t output;
    /*if(ddq){
      switch(inputKey){
        case SCAN_DDQ_LEFT_WIN:
          output = KEY_LEFT_GUI;
        break;
        case SCAN_DDQ_RIGHT_ALT:
          output = KEY_RIGHT_ALT;
          ALT = !release;
          CTRL = !release;
        break;
        case SCAN_DDQ_PRINT:
          output = KEY_PRINT;
        break;
        case SCAN_DDQ_PAUSE:
          output = KEY_PAUSE;
        break;
        case SCAN_DDQ_INS:
          output = KEY_INSERT;
        break;
        case SCAN_DDQ_HOME:
          output = KEY_HOME;
        break;
        case SCAN_DDQ_PG_UP:
          output = KEY_PAGE_UP;
        break;
        case SCAN_DDQ_PG_DOWN:
          output = KEY_PAGE_DOWN;
        break;
        case SCAN_DDQ_DEL:
          output = KEY_DELETE;
        break;
        case SCAN_DDQ_END:
          output = KEY_END;
        break;
        case SCAN_DDQ_UP:
          output = KEY_UP_ARROW;
        break;
        case SCAN_DDQ_LEFT:
          output = KEY_LEFT_ARROW;
        break;
        case SCAN_DDQ_RIGHT:
          output = KEY_RIGHT_ARROW;
        break;
        case SCAN_DDQ_DOWN:
          output = KEY_DOWN_ARROW;
        break;
        case SCAN_DDQ_NUMPAD_DIVIDE:
          output = HID_KEYPAD_MEMORY_DIVIDE;
        break;
        case SCAN_DDQ_NUMPAD_ENTER:
          output = HID_KEYPAD_ENTER;
        break;
        case SCAN_FN_DDQ_MUSIC:
          output = KEY_ERROR_UNDEFINED;
        break;
        case SCAN_FN_DDQ_VOL_DOWN:
          output = KEY_ERROR_UNDEFINED;//HID_KEYBOARD_VOLUME_DOWN;
        break;
        case SCAN_FN_DDQ_VOL_UP:
          output = KEY_ERROR_UNDEFINED;//HID_KEYBOARD_VOLUME_UP;
        break;
        case SCAN_FN_DDQ_VOL_MUTE:
          output = KEY_ERROR_UNDEFINED;//HID_CONSUMER_MUTE;
        break;
        case SCAN_FN_DDQ_PLAY_BACK:
          output = KEY_ERROR_UNDEFINED;//MEDIA_PREV;
        break;
        case SCAN_FN_DDQ_PLAY_FWD:
          output = KEY_ERROR_UNDEFINED;//MEDIA_NEXT;
        break;
        case SCAN_FN_DDQ_PLAY_PAUSE:
          output = KEY_ERROR_UNDEFINED;//MEDIA_PLAY_PAUSE;
        break;
        case SCAN_FN_DDQ_PLAY_STOP:
          output = KEY_ERROR_UNDEFINED;//MEDIA_STOP;
        break;
        case SCAN_FN_DDQ_HOME:
          output = KEY_ERROR_UNDEFINED;//CONSUMER_BROWSER_HOME;
        break;
        case SCAN_FN_DDQ_MAIL:
          output = KEY_ERROR_UNDEFINED;//CONSUMER_EMAIL_READER;
        break;
        case SCAN_FN_DDQ_PC:
          output = KEY_ERROR_UNDEFINED;//KEY_;
        break;
        case SCAN_FN_DDQ_FAV:
          output = KEY_ERROR_UNDEFINED;//CONSUMER_BROWSER_BOOKMARKS;
        break;
      }
    }else{
      switch (inputKey){
        case SCAN_LEFT_SHIFT:
          output = KEY_LEFT_SHIFT;
          SHIFT = !release;
        break;
        case SCAN_LEFT_CTRL:
          output = KEY_LEFT_CTRL;
          CTRL = !release;
        break;
        case SCAN_LEFT_ALT:
          output = KEY_LEFT_ALT;
          ALT = !release;
        break;
        case SCAN_RIGHT_SHIFT:
          output = KEY_RIGHT_SHIFT;
          SHIFT = !release;
        break;
        case SCAN_TAB:
          output = KEY_TAB;
        break;
        case SCAN_CAPS:
          output = KEY_CAPS_LOCK;
        break;
        case SCAN_BACKSPACE:
          output = KEY_BACKSPACE;
        break;
        case SCAN_SPACEBAR:
          output = KEY_SPACE;
        break;
        case SCAN_ESC:
          output = KEY_ESC;
        break;
        case SCAN_ENTER:
          output = KEY_RETURN;
        break;
        case SCAN_SCROLL:
          output = KEY_SCROLL_LOCK;
        break;
        case SCAN_NUMPAD_LOCK:
          output = KEY_NUM_LOCK;
        break;
        case SCAN_NUMPAD_MULTIPLY:
          output = HID_KEYPAD_MULTIPLY;
        break;
        case SCAN_NUMPAD_MINUS:
          output = HID_KEYPAD_SUBTRACT;
        break;
        case SCAN_NUMPAD_SUM:
          output = HID_KEYPAD_ADD;
        break;
        case SCAN_NUMPAD_DECIMAL:
          output = HID_KEYPAD_DECIMAL;
        break;
        case SCAN_NUMPAD_7:
          output = HID_KEYPAD_7_AND_HOME;
        break;
        case SCAN_NUMPAD_8:
          output = HID_KEYPAD_8_AND_UP_ARROW;
        break;
        case SCAN_NUMPAD_9:
          output = HID_KEYPAD_9_AND_PAGE_UP;
        break;
        case SCAN_NUMPAD_4:
          output = HID_KEYPAD_4_AND_LEFT_ARROW;
        break;
        case SCAN_NUMPAD_5:
          output = HID_KEYPAD_5;
        break;
        case SCAN_NUMPAD_6:
          output = HID_KEYPAD_6_AND_RIGHT_ARROW;
        break;
        case SCAN_NUMPAD_1:
          output = HID_KEYPAD_1_AND_END;
        break;
        case SCAN_NUMPAD_2:
          output = HID_KEYPAD_2_AND_DOWN_ARROW;
        break;
        case SCAN_NUMPAD_3:
          output = HID_KEYPAD_3_AND_PAGE_DOWN;
        break;
        case SCAN_NUMPAD_0:
          output = HID_KEYPAD_0_AND_INSERT;
        break;
        case SCAN_NUM_1:
          output = HID_KEYBOARD_1_AND_EXCLAMATION_POINT;
        break;
        case SCAN_NUM_2:
          output = HID_KEYBOARD_2_AND_AT;
        break;
        case SCAN_NUM_3:
          output = HID_KEYBOARD_3_AND_POUND;
        break;
        case SCAN_NUM_4:
          output = HID_KEYBOARD_4_AND_DOLLAR;
        break;
        case SCAN_NUM_5:
          output = HID_KEYBOARD_5_AND_PERCENT;
        break;
        case SCAN_NUM_6:
          output = HID_KEYBOARD_6_AND_CARAT;
        break;
        case SCAN_NUM_7:
          output = HID_KEYBOARD_7_AND_AMPERSAND;
        break;
        case SCAN_NUM_8:
          output = HID_KEYBOARD_8_AND_ASTERISK;
        break;
        case SCAN_NUM_9:
          output = HID_KEYBOARD_9_AND_LEFT_PAREN;
        break;
        case SCAN_NUM_0:
          output = HID_KEYBOARD_0_AND_RIGHT_PAREN;
        break;
        case SCAN_MINUS:
          output = KEY_MINUS;
        break;
        case SCAN_EQUAL:
          output = KEY_EQUAL;
        break;
        case SCAN_Q:
          output = KEY_Q;
        break;
        case SCAN_W:
          output = KEY_W;
        break;
        case SCAN_E:
          output = KEY_E;
        break;
        case SCAN_R:
          output = KEY_R;
        break;
        case SCAN_T:
          output = KEY_T;
        break;
        case SCAN_Y:
          output = KEY_Y;
        break;
        case SCAN_U:
          output = KEY_U;
        break;
        case SCAN_I:
          output = KEY_I;
        break;
        case SCAN_O:
          output = KEY_O;
        break;
        case SCAN_P:
          output = KEY_P;
        break;
        case SCAN_A:
          output = KEY_A;
        break;
        case SCAN_S:
          output = KEY_S;
        break;
        case SCAN_D:
          output = KEY_D;
        break;
        case SCAN_F:
          output = KEY_F;
        break;
        case SCAN_G:
          output = KEY_G;
        break;
        case SCAN_H:
          output = KEY_H;
        break;
        case SCAN_J:
          output = KEY_J;
        break;
        case SCAN_K:
          output = KEY_K;
        break;
        case SCAN_L:
          output = KEY_L;
        break;
        case SCAN_Z:
          output = KEY_Z;
        break;
        case SCAN_X:
          output = KEY_X;
        break;
        case SCAN_C:
          output = KEY_C;
        break;
        case SCAN_V:
          output = KEY_V;
        break;
        case SCAN_B:
          output = KEY_B;
        break;
        case SCAN_N:
          output = KEY_N;
        break;
        case SCAN_M:
          output = KEY_M;
        break;
        case SCAN_BRACKET_OPEN:
          output = KEY_LEFT_BRACE;
        break;
        case SCAN_BRACKET_CLOSE:
          output = KEY_RIGHT_BRACE;
        break;
        case SCAN_BACKSLASH:
          output = KEY_BACKSLASH;
        break;
        case SCAN_SEMICOLON:
          output = KEY_SEMICOLON;
        break;
        case SCAN_QUOTE:
          output = KEY_QUOTE;
        break;
        case SCAN_QUOTE_TILDE:
          output = KEY_TILDE;
        break;
        case SCAN_COMMA:
          output = KEY_COMMA;
        break;
        case SCAN_DOT:
          output = KEY_PERIOD;
        break;
        case SCAN_SLASH:
          output = KEY_SLASH;
        break;
      }
    }
    
    if(output != 0){
      return output;
    }*/
    
    release = false;
    ddq = false;
  }
  return 0;
}

#endif