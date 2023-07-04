#include "requirement.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void requirement::Insert_(string s, ull n, int a, int y, int i, float p)
{

     Node *new_node = new Node;
     new_node->age = a;
     new_node->phone = n;
     new_node->name = s;
     new_node->Year = y;
     new_node->Income = i;
     new_node->Percentage = p;
     new_node->next = NULL;

     if (isEmpty())
     {
          front = new_node;
          rear = new_node;
     }
     else
     {
          rear->next = new_node;
          rear = new_node;
     }
}
int requirement ::blood_Required()
{
     int blood_req;
     cout << "How much blood (in ml) You have required: "
          << endl;
     cin >> blood_req;

     return blood_req;
}

void requirement ::display()
{
     if (isEmpty())
     {
          cout << "No Requiters !!"
               << endl;
     }
     else
     {
          Node *temp = front;
          cout << "========================================================================================" << endl;
          cout << "|| NAME                           || AGE  || PHONE NO.  || INCOME     || %     || YEAR ||" << endl;
          cout << "========================================================================================" << endl;

          while (temp)
          {
               cout << "|| " << temp->name << string(30 - (temp->name).length(), ' ') << " || " << temp->age << string((int)log10(temp->age) + 1, ' ') << " || " << temp->phone << " || " << temp->Income << string(8 - (int)(log10(temp->Income)) + 1, ' ') << " || " << temp->Percentage << " || " << temp->Year << " ||" << endl;

               temp = temp->next;
          }
          cout << "========================================================================================" << endl;
     }
}

void requirement ::display_(int c)
{
     int flag = 0;

     Node *temp = front;
     cout << "=========================================================" << endl;
     cout << "|| NAME                           || AGE  || PHONE NO.  ||" << endl;
     cout << "==========================================================" << endl;

     while (temp)
     {
          if (temp->index == c)
          {
               cout << "|| " << temp->name << string(30 - (temp->name).length(), ' ') << " || " << temp->age << string((int)log10(temp->age) + 1, ' ') << " || " << temp->phone << " ||" << endl;

               flag = 1;
          }

          temp = temp->next;
     }

     if (flag == 0)
          cout << "|| No Requiters .. !!             ||  -   ||    -       || " << endl;
     cout << "=========================================================" << endl;
}

bool requirement ::criteria(string n, ull ph, int a, int *year, int *income, float *percentage)
{

     cout << endl;
     cout << "Scholarship (50,000 /-) will be provided by HelpX according to criteria that are given below : "
          << endl
          << endl;

     cout << "============================================================================================" << endl;
     cout << "                                   criteria                                              " << endl;
     cout << "============================================================================================" << endl;

     cout << "-->12th passing year must be 2020"
          << endl;
     cout << "-->Income in Income Certificate (Father) must be less than 1,50,000 /-"
          << endl;
     cout << "-->12th percentage must be greater than or equal to 85.00 %"
          << endl
          << endl
          << endl;

     Node *temp = front;

     int flag = 0;

     if (temp == NULL)
     {
          Node *new_node = new Node;
          new_node->name = n;
          temp = new_node;
          temp->next = NULL;
     }
     else
     {

          while (temp)
          {
               if (temp->name == n && temp->phone == ph && temp->age == a)
               {
                    cout << "You are already Registered, Scholarship is already given to you this year..."
                         << endl
                         << endl;
                    flag = 1;
                    break;
               }

               temp = temp->next;
          }
     }

     if (flag == 0)
     {
          cout << "Enter Your 12th passing Year : \n";
          cin >> *year;
          cout << endl;

          if (*year != 2020)
               return false;

          cout << "Enter Income that mentioned in Income Certificate (Father) : \n";
          cin >> *income;
          cout << endl;

          if (*income > 150000)
               return false;

          cout << "Enter 12th percentage that mentioned in result (upto 2 decimal): \n";
          cin >> *percentage;
          cout << endl;

          if (*percentage < 85)
               return false;

          return true;
     }
     else
          return false;
}

void requirement::blood_requiters_list()
{
     while (1)
     {
          int ch;
          cout << endl;

          cout << "----------------------------------------------------------------------------------------------" << endl;

          cout << "1. see Blood Requiters list"
               << endl;
          cout << "2. You are not interested"
               << endl;

          cout << "----------------------------------------------------------------------------------------------" << endl;

          cin >> ch;

          if (ch == 1)
          {
               blood_grp();

               int c;
               cin >> c;

               display_(c);
          }
          else
               break;
     }
}

void requirement ::money_requiters_list()
{

     int ch;
     cout << endl;

     cout << "----------------------------------------------------------------------------------------------" << endl;

     cout << "1. To see Money Requiters list"
          << endl;
     cout << "2. if you are not interested "
          << endl;

     cout << "----------------------------------------------------------------------------------------------" << endl;

     cin >> ch;

     if (ch == 1)
          display();
}
