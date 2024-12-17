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
    std::string s = "1+2/(3-3)";
    // CorrectChecker CC;
    // std::cout << (CC.CheckBrackets(s)?"No":"Yes") <<  " trouble \n" << std::endl;
    // CorrectChecker y;
    // y.FillVariable(s);

    Formula g(s);
    g.BuildPostfix();




    // Table<std::string, double> arr("g", "h", 20);
    // arr.AppendRow("a", 5);
    // arr.AppendRow("d", 4.44);
    // arr.AppendRow("cfg", 443);
    // arr.Print();





    // Stack<int> array(5);
    // array.Push(3);
    // array.Push(5);
    // array.Push(77);
    // array.Push(4);
    // array.Push(3);

    
    // std::cout << array.Check() <<std::endl;
    // std::cout << array.Pop() <<std::endl;
    // std::cout << "Стек пуст?  " << (array.IsEmpty()?"Да":"Нет" )<<std::endl;
    // std::cout << "Стек полон?  " << (array.IsFull()?"Да":"Нет" )<<std::endl;
    // std::cout << array.GetLenght() << std::endl;

    // try{
    //     array.Pop();
    //     array.Pop();
    //     array.Pop();
    //     array.Pop();
    //     array.Pop();
    //     array.Pop();
    // }
    // catch(const char* error_message)
    // {
    //     std::cout << error_message << std::endl;
    // }

    

    return 0;
}
