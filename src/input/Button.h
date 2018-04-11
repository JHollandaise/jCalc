//
// Created by Joseph Holland  on 06/04/2018.
//

#ifndef JCALC_BUTTON_H
#define JCALC_BUTTON_H

#include "../InputDefs.h"

/* Structure defining the type nature of the button that was pressed
 */

struct Button {

    Button(unsigned char _modifier, unsigned char _value):modifier(_modifier), value(_value) {}

    Button():modifier((char)255),value((char)255) {}

    unsigned char modifier;

    unsigned char value;


};


#endif //JCALC_BUTTON_H
