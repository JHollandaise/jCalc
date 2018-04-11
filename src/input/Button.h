//
// Created by Joseph Holland  on 06/04/2018.
//

#ifndef JCALC_BUTTON_H
#define JCALC_BUTTON_H

#include "../InputDefs.h"

/* Structure defining the type nature of the button that was pressed
 */

struct Button {

    Button(int _modifier, char _value):modifier(_modifier), value(_value) {}

    Button():modifier((char)255),value((char)255) {}

    char modifier;

    char value;


};


#endif //JCALC_BUTTON_H
