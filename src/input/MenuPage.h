//
// Created by Joseph Holland  on 22/01/2019.
//

#ifndef JCALC_MENUPAGE_H
#define JCALC_MENUPAGE_H

#include <vector>
#include <string>
#include <GUI/GraphicsController.h>
#include "UserInputController.h"

class MenuPage {
private:

    const std::string* title;

    const std::vector<std::string>* selectionStrings;

    MenuPage *parent;

    const std::vector<MenuPage*>* childrenMenuPages;

    const std::vector<unsigned short>* tokenSelections;

    // currently accessed page
    unsigned int page;

    // GraphicsController to send MenuPage display requests
    GraphicsController* graphicsController;

    // userinputController to get user choice
    UserInputController* userInputController;

    unsigned int GetUserChoice();



public:

    MenuPage(std::vector<unsigned short>* _tokenSelections,
            std::vector<std::string>* _selectionStrings,
            std::string* _title,
            MenuPage *_parent,
            std::vector<MenuPage*>* _childrenMenuPages);

    // note the use of pointers to variables, nullptr if unused (this is used extensively for checks in the logic
    // perhaps needs improving?)

    inline void setParent(MenuPage* newParent){parent = newParent;}

    void setIOControllers(GraphicsController*, UserInputController*);

    inline const std::vector<MenuPage*>* getChildrenMenuPages(){return childrenMenuPages;}

    unsigned short GetActionToken();

};

// give access to predefined menus
namespace MenuPages {

    extern MenuPage hyperbolic;
    extern MenuPage mode;
    extern MenuPage drg;
    extern MenuPage clear;
    extern MenuPage baseN;

    extern MenuPage setup;
}


#endif //JCALC_MENUPAGE_H
