#pragma once
#include "Stack.h"
#include <optional>

class CorrectChecker{
private:
    Stack<int> _brackets;
public:
    bool CheckBrackets(const std::string& s);

};