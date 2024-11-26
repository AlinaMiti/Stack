#pragma once
#include "Stack.h"
#include <string>
#include <iostream>


class Formula{
private:
    std::string _expression;  //инфиксная форма
    Stack<std::string> _calcStack;  //стек для подсчета 
    std::string _postfix; //постфиксная форма
public:
    Formula(std::string exp);
    bool CheckBrackets();  //проверка скобок. если не верно то std::cout << error
    bool CheckFormula();   //проверка формулы пункт2
    void EnterVariableValues();  //заставить пользователя ввести значения переменных
    std::string BuildPostfix();
    double Calculate(); //счёт значения

};