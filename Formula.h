#pragma once
#include "Stack.h"
#include "Table.h"
#include <string>
#include <iostream>
#include "CorrectChecker.h"


class Formula{
private:
    std::string _expression;  //инфиксная форма
    Stack<char> _calcStack;  //стек для подсчета 
    std::string _postfix; //постфиксная форма
    Table<char, int> _prior;
public:
    //Formula(std::string exp);
    Formula(const std::string& exp){
        _expression = exp;
        _prior = Table<char, int>("oper", "prioritet");
        _prior.AppendRow('(', 0);
        _prior.AppendRow(')', 1);
        _prior.AppendRow('+', 2);
        _prior.AppendRow('-', 2);
        _prior.AppendRow('*', 3);
        _prior.AppendRow('/', 3);
    }
    void EnterVariableValues(const std::string& s);//заставить пользователя ввести значения переменных
    
    void BuildPostfix(){
        std::string operazia{"()+-*/"};
        for(int i = 0; i < _expression.size(); i++){
            if(operazia.find(_expression[i]) != std::string::npos){
                if(_prior[_expression[i]].value() == 0 || _prior[_expression[i]].value() > _prior[_calcStack.Check()].value() || _calcStack.IsEmpty()){
                    if(_expression[i] != ')'){
                        _calcStack.Push(_expression[i]);
                    }
                    else{
                        while(_calcStack.Check() != '('){
                            _postfix.push_back(_calcStack.Check());
                            _calcStack.Pop();
                            //std::cout << _postfix << std::endl;
                        }

                    }
                }
                else{
                    while( _prior[_expression[i]].value() <= _prior[_calcStack.Check()].value() &&  !_calcStack.IsEmpty()){
                        if(_calcStack.Check() == '(')
                            _calcStack.Pop();
                        else{
                            _postfix.push_back(_calcStack.Pop());
                        }
                        
                    }
                    if(_expression[i]!=')')
                        _calcStack.Push(_expression[i]);
                }
            }
            else{
                _postfix.push_back(_expression[i]);
            }
        }
    while(!_calcStack.IsEmpty()){
        if(_calcStack.Check() != '(' && _calcStack.Check() != ')'){
            _postfix.push_back(_calcStack.Pop());
        }
        else{
            _calcStack.Pop();
        }
    }
    std::cout << _postfix << std::endl;
    }
    double Calculate(Table<char, double> varTable){ //счёт значения
        //BuildPostfix();
        std::cout << _postfix << std::endl;
        // CorrectChecker y;
        // Table<char, double> varTable = y.GetVarTable();
        Stack<double> stack;
        double oper1 = 0;
        double oper2 = 0;
        std::string operazia{"()+-*/"};
        for(size_t i = 0; i < _postfix.length(); i++){
            if(operazia.find(_postfix[i]) == std::string::npos){
                //std::string tmp {_postfix[i]};
                stack.Push(varTable[_postfix[i]].value());
            }
            else{
                oper2 = stack.Pop();
                oper1 = stack.Pop();
                double res;
                if(_postfix[i] == '-')
                    double res = oper1 - oper2;
                if(_postfix[i] == '+'){
                    double res = oper1 + oper2;
                }
                    
                if(_postfix[i] == '*')
                    double res = oper1 * oper2;
                if(_postfix[i] == '/')
                    double res = oper1 / oper2;
                
                stack.Push(res);
            }
        }
        double resOp = stack.Pop();
        std::cout << resOp << std::endl;
        return resOp;
    }
};
