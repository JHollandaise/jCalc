//
// Created by Joseph Holland  on 18/01/2019.
//

#ifndef JCALC_ERRORMANAGER_H
#define JCALC_ERRORMANAGER_H

#include <vector>
#include <GUI/GraphicsController.h>
#include "Error.h"

/**
 * @brief Handles Errors.
 *
 *
 */
class ErrorManager {

public:
    explicit ErrorManager(GraphicsController *_graphicsController):graphicsController(_graphicsController){};


    void AddToStream(const std::exception *);

    void PrintLatestError();
private:

    // send error messages to graphics controller
    GraphicsController *graphicsController;

    // logged exeptions
    std::vector<const std::exception> exceptionStream;

};


#endif //JCALC_ERRORMANAGER_H
