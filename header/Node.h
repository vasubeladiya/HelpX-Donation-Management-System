#pragma once
#include<string>
typedef unsigned long long ull;
using namespace std ;

//Structure of Node*
class Node
{
    int age,index;   
    ull phone;
    string name;
 
    int Year, Income;
    float Percentage;

    Node *next;   //pointer to next node*


    friend class Donor;           // use of the friend class*
    friend class requirement;
};