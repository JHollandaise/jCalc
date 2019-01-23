
add_executable(exe RunAllTests.cpp SurdFracTest.cpp CalculationResultTests.cpp  ErrorManagerTest.cpp
        ../catch.h
        ../../src/core/MathFunc.cpp ../../src/core/MathFunc.h
        ../../src/core/SurdFrac.h
        ../../src/core/CalculationResult.cpp ../../src/core/CalculationResult.h
        ../../src/errorMgt/ErrorManager.h ../../src/errorMgt/ErrorManager.cpp
        ../../src/GUI/GraphicsController.h ../../src/GUI/GraphicsController.cpp
        ../../src/GUI/tigr.h ../../src/GUI/tigr.c
        )
