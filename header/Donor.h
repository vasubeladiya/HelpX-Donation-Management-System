#pragma once
#include "Node.h"
#include <string>
using namespace std;
typedef unsigned long long ull;

//Donor class Declaration*
class Donor
{

private:
  Node *front;
  Node *rear;

public:
  int *balance;
  ull money;

  string name;
  ull phone;
  int age;

//Donor class methods*
  Donor();                                  // constructor
  void DataBase();                          // Initialize data base
  void Insert(string s, ull n, int a, int); //Take user's data and add it into List
  bool isEmpty();                           //Check wheter List is Empty or not
  void display(int i);                      //Display data
  void user_data();                         //Take user's basic data
  void benefits();                          //Display benefits of Blood Donation
  void money_();                           //Display why to donate money
  void blood_grp();                     //For choosing Blood Grp.
  void data_addition(string, ull, int); //Take user's data and add it into Queue
  void blood_donated(int);              //Display storage of the Blood
  void money_donated();                 //Display Total Fund
  void Blood_donors_list();             //Display Blood Donors list
  void Money_donors_list();             //Display Money Donos list
  bool same_donor(string, ull, int);    // Return Ture if donor is appearce again

  friend class requirement;
};
