#pragma once
#include<iostream>

class Stack{
    private:
        int number;

    public:
        Stack(int number){
            this->number = number;
        };

        ~Stack(){

        };

        int GetNumber();
};