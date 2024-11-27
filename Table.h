#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T1, typename T2>

class Table{
private:
    size_t _tableSize;
    std::optional<T1>* _col1;
    std::optional<T2>* _col2;
    size_t _count;
    std::string _titleCol1;
    std::string _titleCol2;
public:
    /// @brief конструктор класса 
    /// @param size 
    /// @param _titleCol1 
    /// @param _titleCol2 
    Table(std::string titleCol1, std::string titleCol2, size_t size = 20){
        _titleCol1 = titleCol1;
        _titleCol2 = titleCol2;
        _tableSize = size;
        _col1 = new std::optional<T1>[_tableSize];
        _col2 = new std::optional<T2>[_tableSize];
        _count = 0;
    }
    void AppendRow(std::optional<T1> t1, std::optional<T2> t2){
        //std::obtional загуглить
        _col1[_count] = t1;
        _col2[_count] = t2;
        _count++;
        //подумать о переполнении(по возможности)
    }
    void Print(){
        std::cout << std::endl;
        for(size_t i = 0; i < 15; i++){
            std::cout << "~";
        }   
        std::cout << std::endl;
        std::cout << "| " << setw( 4 ) << _titleCol1 << "| " << setw( 5 ) << _titleCol2 << "| " << std::endl;
        for(size_t i = 0; i < 15; i++){
            std::cout << "~";
        }    
        std::cout << std::endl;
        for(size_t i = 0; i < _count; i++){
            
            cout << "| " << setw( 4 )  << _col1[i].value() << "| " << setw( 5 ) <<  _col2[i].value() << "| " << endl;
           
        }
        for(size_t i = 0; i < 15; i++){
            std::cout << "~";
        }    
        std::cout << std::endl;
    }
};
