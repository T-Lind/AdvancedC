cmake_minimum_required(VERSION 3.23)
project(AdvancedC C)

set(CMAKE_C_STANDARD 99)

add_executable(AdvancedC learning.c basicmodules/Printing.h basicmodules/DataTypes.h
        basicmodules/Arrays.h basicmodules/Strings.h basicmodules/Loops.h intermediatemodules/Functions.h intermediatemodules/Structures.h
        projects/PostfixCalculator.h projects/Tictactoe.h projects/Boolean.h projects/MatrixFunctions.h projects/OptimizedMatrixFunctions.h
        projects/VisionCalculations.h
        )
