#include <iostream>
#include "Stack.h"

int main(){
Stack<int> array(10);
array.Push(3);
array.Push(5);
array.Push(77);
array.Push(4);

std::cout << array.Check() <<std::endl;
std::cout << array.Pop() <<std::endl;
std::cout << array.IsEmpty() <<std::endl;



return 0;
}