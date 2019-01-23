//
// Created by Joseph Holland  on 22/01/2019.
//

#ifndef JCALC_MENUPAGE_H
#define JCALC_MENUPAGE_H

#include <vector>
#include <string>

class MenuPage {
private:

    const std::string* title;

    const std::vector<std::string>* selectionStrings;

    MenuPage *parent;

    const std::vector<const MenuPage*>* childrenMenuPages;

    const std::vector<unsigned short>* tokenSelections;

public:

    MenuPage(std::vector<unsigned short>* _tokenSelections,
            std::vector<std::string>* _selectionStrings,
            std::string* _title,
            MenuPage *_parent,
            std::vector<const MenuPage*>* _childrenMenuPages);

    // note the use of pointers to variables, nullptr if unused (this is used extensively for checks in the logic
    // perhaps needs improving?)

    inline void setParent(MenuPage* newParent){parent = newParent;};

    inline const std::vector<MenuPage*>* getChildrenMenuPages(){return childrenMenuPages;}

    unsigned short GetActionToken();

};

namespace MenuPages {

    extern const MenuPage hyperbolic;
    extern const MenuPage mode;
    extern const MenuPage drg;
    extern const MenuPage clear;
    extern const MenuPage baseN;
}


#endif //JCALC_MENUPAGE_H
