//
// Created by Joseph Holland  on 18/01/2019.
//

#include "ErrorManager.h"

void ErrorManager::AddToStream(const std::exception *e) {
    exceptionStream.push_back(*e);
}
