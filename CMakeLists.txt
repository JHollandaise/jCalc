cmake_minimum_required(VERSION 3.8)
project(jCalc)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS "-framework OpenGL -framework Cocoa")

include_directories(src)

set(SOURCE_FILES
        src/core/main.cpp
        src/input/UserInputController.cpp
        src/input/UserInputController.h
        src/input/Button.h
        src/InputDefs.h
        src/core/Calculator.cpp
        src/core/Calculator.h
        src/input/InputParser.cpp
        src/input/InputParser.h
        src/core/FunctionStream.cpp
        src/core/FunctionStream.h
        src/errorMgt/Error.cpp
        src/errorMgt/Error.h
        src/init/TermInit.cpp
        src/init/TermInit.h
        src/init/Initialiser.cpp
        src/init/Initialiser.h
        src/init/MbedInit.cpp
        src/init/MbedInit.h
        src/input/buttonMaps/Maths.h
        src/core/MemoryMgr.cpp
        src/core/MemoryMgr.h
        src/input/buttonMaps/Menu.h
        src/OperationMode.h
        src/GUI/GraphicsController.cpp
        src/GUI/GraphicsController.h
        src/input/buttonMaps/BaseN.h
        src/core/CalculationResult.h
        src/core/Evaluator.cpp
        src/core/Evaluator.h
        src/core/ResultValue.h
        src/core/SurdFrac.h
        src/core/CalculationResult.cpp
        src/core/MathFunc.cpp
        src/core/MathFunc.h
        src/GUI/tigr.c
        src/GUI/tigr.h src/errorMgt/ErrorManager.cpp src/errorMgt/ErrorManager.h src/GUI/MenuStrings.h src/input/MenuPage.cpp src/input/MenuPage.h)

add_executable(jCalc ${SOURCE_FILES})

add_subdirectory(jCalc_tests)



