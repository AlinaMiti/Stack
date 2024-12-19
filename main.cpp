#include "Stack.h"
#include "Formula.h"
#include "CorrectChecker.h"
#include "Table.h"
#include <optional>

std::optional<std::string> create(bool b){
    if(b)
        return "ghh";
    return std::nullopt;
}

int main(){
    std::string s = "(a+a)^b+c";
    CorrectChecker CC;
    std::cout << (CC.CheckFormula(s)?"No":"Yes") <<  " trouble \n" << std::endl;
    CorrectChecker y;
    y.FillVariable(s);
    Table VarTable = y.GetVarTable();
    //VarTable.Print();
    if(y.GetState()){
        Formula g(s);

        double res = g.Calculate(VarTable);
        std::cout << res << std::endl;
    }
    




    
    // std::cout << array.Check() <<std::endl;
    // std::cout << array.Pop() <<std::endl;
    // std::cout << "Стек пуст?  " << (array.IsEmpty()?"Да":"Нет" )<<std::endl;
    // std::cout << "Стек полон?  " << (array.IsFull()?"Да":"Нет" )<<std::endl;
    // std::cout << array.GetLenght() << std::endl;

    

    return 0;
}
