/*-------------------------------------------------------
 | CS 372: Software Construction                        |
 | Pair Programming: String Calculator                  |
 | Due Date: 2/12/18                                    |
 | File: CalculatorTests.cpp                            |
 | Written By: Thatcher Lane, Collin Lasley,            |
 | Description: Unit tests for String Calculator        |
 ------------------------------------------------------*/

#include "catch2.h"

#include "StringCalculator.h"

#include <sstream>


int ParseString(std::string inputStr)
{
    if(inputStr == ""){
        return 0; 
    }
    return -1;
}

TEST_CASE("Empty string returns 0", "[StringEval]") {
    REQUIRE(ParseString("") == 0);
}
