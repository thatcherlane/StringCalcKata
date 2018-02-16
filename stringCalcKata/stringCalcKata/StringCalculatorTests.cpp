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
    if(inputStr.empty()){
        return 0;
    }
    
    else if(inputStr.find(',') != std::string::npos) {
        std::stringstream ss(inputStr);

        std::vector<int> individualNumbers;

        while(ss.good())
        {
            std::string temp;
            getline(ss,temp,',');
            int tempInt = std::stoi(temp);
            individualNumbers.push_back(tempInt);
        }

        int sum = 0;
        for(const auto & n : individualNumbers)
        {
            sum += n;
        }

        return sum;

    }

    else if (inputStr.find('\n') != std::string::npos){
        std::stringstream ss(inputStr);

        std::vector<int> individualNumbers;

        while(ss.good())
        {
            std::string temp;
            getline(ss,temp,'\n');
            int tempInt = std::stoi(temp);
            individualNumbers.push_back(tempInt);
        }

        int sum = 0;
        for(const auto & n : individualNumbers)
        {
            sum += n;
        }

        return sum;
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

TEST_CASE("Two numbers comma delimited, returns the sum", "[StringEval]"){
    REQUIRE(ParseString("1,2") == 3);
    REQUIRE(ParseString("1,3") == 4);
}

TEST_CASE("Two numbers delimited by a new line, returns the sum", "[StringEval]"){
    REQUIRE(ParseString("1\n2") == 3);
    REQUIRE(ParseString("1\n3") == 4);
}
