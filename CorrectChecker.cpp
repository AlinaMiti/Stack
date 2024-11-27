#include "CorrectChecker.h"
#include "Table.h"


bool CorrectChecker::CheckBrackets(const std::string& s){
    Table<int, int> table1("(  ", ")  ", 20);
    for(size_t i = 0; i < s.size(); i++){
        if(s[i] == '('){
            _brackets.Push(i);
        }
        if(s[i] == ')'){
            try{
                table1.AppendRow(_brackets.Pop(), i);
            }
            catch(const char* error_message){
                table1.AppendRow(std::nullopt, i);
                table1.Print();
                std::cout << "Error is brackets" << std::endl;
                return false;
            }
        }
    }
    // bool isBracketsStackEmpty = _brackets.IsEmpty();
    // if(!isBracketsStackEmpty ){
        while (!_brackets.IsEmpty()){
            table1.AppendRow(_brackets.Pop(), std::nullopt);
        }
    //}

    table1.Print();
    return _brackets.IsEmpty();
}

//пометить галочкой места, где проёб со скобками  (a-b)+c)
//                                                       ^
//запрос пользователю на ввод значений переменных и корректность ввода
//таблица со скобками и ещё одна со значениями переменных
//tab3["-"] табличка с приоритетами операций. 