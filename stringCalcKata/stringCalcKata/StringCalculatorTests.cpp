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

#include <string>
#include <sstream>


int ParseString(std::string inputStr)
{
    if(inputStr == ""){
        return 0;
    }
    else{
        int retVal = std::stoi(inputStr);
        return retVal;
    }
    return -1;
}

TEST_CASE("Empty string returns 0", "[StringEval]") {
    REQUIRE(ParseString("") == 0);
}

TEST_CASE("Single string returns its value", "[StringEval]") {
    REQUIRE(ParseString("1") == 1);
    REQUIRE(ParseString("2") == 2); 
}
