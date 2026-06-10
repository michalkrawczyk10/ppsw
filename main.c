#include "servo.h"
#include "keyboard.h"

int main() {
    KeyboardInit();
    ServoInit(50); 

    while(1) {
        switch (eKeyboardRead()) {
            case BUTTON_0:
                ServoCallib();
                break;
            case BUTTON_1:
                ServoGoTo(12);
                break;
            case BUTTON_2:
                ServoGoTo(24);
                break;
            case BUTTON_3:
                ServoGoTo(36);
                break;
            case RELASED:
            default:
                break;
        }
    }
}
