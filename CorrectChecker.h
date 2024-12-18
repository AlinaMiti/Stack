#pragma once
#include "Stack.h"
#include <optional>
#include "Table.h"

class CorrectChecker{
private:
    Stack<int> _brackets;
    Table<int,int> _bracketsTable; //заполняем в этом классе
    Table<string, double> _varTable;
    bool _state = false; //если все проверки прошли он будет true
public:
    bool CheckBrackets(const std::string& s);
    bool CheckVariable();    //проверка таблицы на заполненность
    void FillVariable(); 
    bool CheckFormula (const string&);
};
//гет для возвращения таблицы. с константной ссылкой