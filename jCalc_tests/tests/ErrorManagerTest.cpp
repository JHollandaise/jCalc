//
// Created by Joseph Holland  on 21/01/2019.
//

#include "../catch.h"
#include "errorMgt/ErrorManager.h"
#include "GUI/GraphicsController.h"
#include "GUI/tigr.h"

TEST_CASE("AddToStream Test", "[ErrorManager]") {


    GraphicsController graphicsController;
    // initialise screen
    Tigr *screen = tigrWindow(320, 240, "Hello", TIGR_2X);

    graphicsController.SetScreen(screen);

    // initialise an errorManager
    ErrorManager errorManager(&graphicsController);
    std::range_error e("test");

    errorManager.AddToStream(&e);
    errorManager.AddToStream(&e);



}