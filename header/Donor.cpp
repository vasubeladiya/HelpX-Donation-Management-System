#include "Donor.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
typedef unsigned long long ull;

Donor ::Donor()
{
     front = rear = NULL;
     balance = new int[9];
     money = 5000000;

     for (int i = 0; i < 9; i++)
     {
          balance[i] = 1000;
     }
}

void Donor ::DataBase()
{
     Insert("Vasu Beladiya", 9023231383, 45, 0);
     money += 1500000;
     Insert("Jensi Bodrya", 8141807761, 40, 0);
     money += 1500000;
     Insert("Brij Sojitra", 9499512139, 50, 0);
     money += 1000000;
     Insert("Aastha Patel", 8849177491, 35, 0);
     money += 1000000;
}

bool Donor::isEmpty()
{
     if (front == NULL)
          return true;

     else
          return false;
}

void Donor::Insert(string s, ull n, int a, int ch)
{
     Node *new_node = new Node;
     new_node->age = a;
     new_node->phone = n;
     new_node->name = s;
     new_node->index = ch;
     new_node->next = NULL;
     //Checking the condition that is linked list is empty than create new node and point front and rear on new node*
     if (isEmpty())
     {
          front = new_node;
          rear = new_node;
     }
     //else point rear on new node*
     else
     {
          rear->next = new_node;
          rear = new_node;
     }
}

void Donor::display(int i)
{
     Node *temp = front;
     int flag = 0;

     //Traversing the linked list*
     while (temp)
     {
          if (temp->index == i)
          {
               flag = 1;
               break;
          }
          temp = temp->next;
     }
     if (flag == 0)
     {
          cout << "No Donors !!"
               << endl
               << endl;
     }

     else
     {

          cout << "=========================================================" << endl;
          cout << "|| NAME                           ||  AGE || PHONE NO.  ||" << endl;
          cout << "=========================================================" << endl;

          while (temp)
          {
               if (temp->index == i)
               {

                    cout << "|| " << temp->name << string(30 - (temp->name).length(), ' ') << " || " << temp->age << string((int)log10(temp->age) + 1, ' ') << " || " << temp->phone << " ||" << endl;
               }

               temp = temp->next;
          }
          cout << "=========================================================" << endl;
     }
}

void Donor::user_data()
{
     cout << "Enter Your name "
          << endl;
     cin.ignore();
     getline(cin, name);

     cout << endl;
     cout << "Enter Your Phone Number"
          << endl;
     cin >> phone;
     cout << endl;
     cout << "Enter Your age "
          << endl;
     cin >> age;
     cout << endl;
}

void Donor::benefits()
{
     cout << "============================================================================================"
          << endl;
     cout << "                      Benefits of Blood Donation "
          << endl;
     cout << "============================================================================================"
          << endl;

     cout << "--> Alleviates Risk of Heart Attack"
          << endl;
     cout << "--> Reduce chances of Cancer"
          << endl;
     cout << "--> Reveals Potential Health Problems"
          << endl;
     cout << "--> Boosts Immunity"
          << endl;
     cout << "--> Psychological Benefits"
          << endl
          << endl;
}

void Donor ::money_()
{
     cout << "============================================================================================"
          << endl;
     cout << "                      Why Donate Money ? "
          << endl;
     cout << "============================================================================================"
          << endl;

     cout << "--> A small amount can change the life of a Student." << endl
          << "--> Education is basic need of our Sociaty, Through education student can lead normal lives." << endl
          << "--> Nowadays they are many students who are really capable, "
          << "but because of financial issues they can't fulfil their dreams, " << endl
          << "    Our organazation helps needy students to make their dreams true."
          << endl;

     cout << "-------------------------------------------------------------------------------" << endl
          << endl;
}

void Donor::blood_grp()
{
     cout << endl;
     cout << "=================================================================================" << endl;
     cout << "||      1. A+       ||      2. B+       ||      3.AB+      ||      4. O+       ||" << endl;
     cout << "=================================================================================" << endl;
     cout << "||      5. A-       ||      6. B-       ||      7.AB-      ||      8. O-       ||" << endl;
     cout << "=================================================================================" << endl;
     cout << endl;
}

void Donor::Blood_donors_list()
{
     while (1)
     {
          cout << endl;
          cout << "----------------------------------------------------------------------------------------------" << endl;

          cout << "1. For Blood Donor list "
               << endl;
          cout << "2. If you are not interested "
               << endl;
          cout << "----------------------------------------------------------------------------------------------" << endl;

          int ch;
          cin >> ch;

          switch (ch)
          {

          case 1:
          {
               blood_grp();
               cout << "9. if You are not interested..."
                    << endl
                    << endl;

               int x;
               cin >> x;
               switch (x)
               {
               case 1:
                    cout << "Total storage of the blood A+ is : " << balance[x] << endl
                         << endl;
                    cout << "Donors list :" << endl;
                    cout << endl;

                    display(x);

                    break;
               case 2:
                    cout << "Total storage of the blood B+ is : " << balance[x] << endl
                         << endl;
                    cout << "Donors list :" << endl;
                    cout << endl;

                    display(x);
                    break;
               case 3:
                    cout << "Total storage of the blood AB+ is : " << balance[x] << endl
                         << endl;
                    cout << "Donors list :" << endl;
                    cout << endl;

                    display(x);
                    break;
               case 4:
                    cout << "Total storage of the blood O+ is : " << balance[x] << endl
                         << endl;
                    cout << "Donors list :" << endl;
                    cout << endl;

                    display(x);
                    break;
               case 5:
                    cout << "Total storage of the blood A- is : " << balance[x] << endl
                         << endl;
                    cout << "Donors list :" << endl;
                    cout << endl;

                    display(x);
                    break;
               case 6:
                    cout << "Total storage of the blood B- is : " << balance[x] << endl
                         << endl;
                    cout << "Donors list :" << endl;
                    cout << endl;

                    display(x);
                    break;
               case 7:
                    cout << "Total storage of the blood AB- is : " << balance[x] << endl
                         << endl;
                    cout << "Donors list :" << endl;
                    cout << endl;

                    display(x);
                    break;
               case 8:
                    cout << "Total storage of the blood O- is : " << balance[x] << endl
                         << endl;
                    cout << "Donors list :" << endl;
                    cout << endl;

                    display(x);
                    break;
               }

               break;
          }

          case 2:
               goto end;
          }
     }

end:
{
}
}

void Donor ::Money_donors_list()
{
     cout << "-------------------------------------------------------------------------------" << endl;
     cout << "Enter 1 If you want to know the money donor list "
          << endl;
     cout << "Enter 2 If you are not interested " << endl;
     cout << "-------------------------------------------------------------------------------" << endl;

     int ch;
     cin >> ch;
     if (ch == 1)
     {
          cout << "Total Fund is : " << money << endl;
          cout << "Donors list : " << endl;

          display(0);
     }
}

void Donor::blood_donated(int ch)
{

     int b_d;
     cout << "How much Blood (in ml) that donor have Donated : ";
     cin >> b_d;
     balance[ch] += b_d;
     cout << "---------------------------------------------------------------" << endl;
     cout << "Thank You So much for Donating Blood..!" << endl;
     cout << "---------------------------------------------------------------" << endl;
}

void Donor ::money_donated()
{

     int m_d;
     cout << "How much Fund You want to donate : ";
     cin >> m_d;
     money += m_d;

     cout << endl;
}

bool Donor ::same_donor(string n, ull ph, int a)
{
     Node *p = front;

     while (p)
     {
          if (p->phone == ph)
          {
               p->name = n;
               p->age = a;
               return true;
          }

          p = p->next;
     }

     return false;
}
