#pragma once
#include <iostream>
#include <string>
using namespace std;

class Item
{
public:
    
    Item() //기본 생성자가 있어야 함
    {
        name_ = "";
        price_ = 0;
    } 
    
    //생성자 (이름, 가격)
    Item(string name, int price)
    {
        name_ = name;
        price_ = price;
    }

    //정보 출력
    void PrintInfo() const
    {
        cout << "[아이템 : " << name_ << ", 가격 : " << price_ << "G]" << endl;
    }

private:
    string name_;
    int price_;
};