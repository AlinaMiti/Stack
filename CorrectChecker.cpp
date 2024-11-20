#include "CorrectChecker.h"
#include "Table.h"

bool CorrectChecker::CheckBrackets(const std::string& s){
    Table<int, int> table1;
    for(size_t i = 0; i < s.size(); i++){
        if(s[i] == '('){
            _brackets.Push(i);
        }
        if(s[i] == ')'){
            try{
                table1.AppendRow(_brackets.Pop(), i);
            }
            catch(const char* error_message){
                std::cout << "Error is brackets" << std::endl;
                return false;
            }
        }
    }
    table1.Print();
    return _brackets.IsEmpty();
}

//найти ошибку если есть только закрывающаяся скобка