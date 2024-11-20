#include "Stack.h"
#include "Formula.h"
#include "CorrectChecker.h"


int main(){
    std::string s = "(a+b)+(c+(b-d))";
    CorrectChecker CC;
    std::cout << "Trouble? " << (CC.CheckBrackets(s)?"No":"Yes") << std::endl;









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