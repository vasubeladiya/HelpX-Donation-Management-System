#include "../header/Donor.cpp"
#include "../header/requirement.cpp"
#include <dos.h>
#include <iostream>
#include <string>
#include <stdlib.h>
typedef unsigned long long ull;
using namespace std;

void welcome();
void dashboard(); // Display the dashboard

int main()
{
    //Four linled list for donation and requirement*
    Donor Blood_Donor, Money_Donor;
    requirement Blood_Requiter, Money_Requiter;

    Money_Donor.DataBase();

    while (1)
    {

        int ch;
        dashboard();

        cin >> ch;
        cout << endl;

        //For Displaying Donation list*
        if (ch == 3)
        {

            cout << "----------------------------------------------------------------------------------" << endl;
            cout << "1. To see Blood Donor List "
                 << endl;
            cout << "2. To see Money Donor List "
                 << endl;
            cout << "----------------------------------------------------------------------------------" << endl;

            int c;
            cin >> c;

            if (c == 1)
            {
                Blood_Donor.Blood_donors_list();
            }
            else
            {
                Money_Donor.Money_donors_list();
            }

            goto end;
        }

        //For Displaying Requirement list*
        else if (ch == 4)
        {

            cout << "----------------------------------------------------------------------------------" << endl;

            cout << "1.Blood Requiters List "
                 << endl;
            cout << "2. Money Requiters List "
                 << endl;
            cout << "----------------------------------------------------------------------------------" << endl;

            int c;
            cin >> c;

            if (c == 1)
            {
                Blood_Requiter.blood_requiters_list();
            }
            else
            {
                Money_Requiter.money_requiters_list();
            }

            goto end;
        }
        //For Displaying benifits*
        else if (ch == 5)
        {
            Blood_Donor.benefits();
            Money_Donor.money_();

            goto end;
        }
        //For exit*
        else if (ch == 6)
            exit(0);

        Blood_Donor.user_data();

        switch (ch)
        {
        //For Donoating*
        case 1:
        {
            Blood_Donor.benefits();
            Money_Donor.money_();

            cout << "----------------------------------------------------------------------------------------------" << endl;

            cout << "1. If You want to donate ....Blood...."
                 << endl;
            cout << "2. If You want to donate ....Money...."
                 << endl
                 << endl;

            cout << "----------------------------------------------------------------------------------------------" << endl;

            int c;
            cin >> c;
            cout << endl;

            switch (c)
            {
            case 1:

                if (Blood_Donor.age >= 18 && Blood_Donor.age <= 45)
                {
                    Blood_Donor.blood_grp();

                    int ch;
                    cin >> ch;
                    cout << endl;

                    int flag = 0;

                    if (Blood_Donor.same_donor(Blood_Donor.name, Blood_Donor.phone, Blood_Donor.age))
                    {
                        int b_d;
                        cout << "How much Blood (in ml) donor have donated: ";
                        cin >> b_d;
                        Blood_Donor.balance[ch] += b_d;
                        cout << endl;
                    }
                    else
                    {
                        Blood_Donor.Insert(Blood_Donor.name, Blood_Donor.phone, Blood_Donor.age, ch);
                        Blood_Donor.blood_donated(ch);
                    }

                    Blood_Donor.Blood_donors_list();
                }
                else
                {
                    cout << "You can't donate the blood !!"
                         << endl;
                }

                break;

            case 2:

                if (Money_Donor.same_donor(Blood_Donor.name, Blood_Donor.phone, Blood_Donor.age))
                {
                    int m_d;
                    cout << "How much Fund You want to donate : ";
                    cin >> m_d;
                    Money_Donor.money += m_d;
                    cout << endl;
                }
                else
                {
                    Money_Donor.Insert(Blood_Donor.name, Blood_Donor.phone, Blood_Donor.age, 0);
                    Money_Donor.money_donated();
                }

                Money_Donor.Money_donors_list();

                break;
            }

            break;
        }

        //For requirement*
        case 2:
        {

            cout << "----------------------------------------------------------------------------------------------" << endl;

            cout << "1. if You have requiremwnt of blood"
                 << endl;
            cout << "2. if You have requiremwnt of money"
                 << endl;
            cout << "----------------------------------------------------------------------------------------------" << endl;

            int ch;
            cin >> ch;

            switch (ch)
            {
            case 1:
            {
                int ch;
                Blood_Requiter.blood_grp();
                cin >> ch;

                int br = Blood_Requiter.blood_Required();

                if (Blood_Donor.balance[ch] >= br)
                {
                    Blood_Requiter.Insert(Blood_Donor.name, Blood_Donor.phone, Blood_Donor.age, ch);
                    Blood_Donor.balance[ch] -= br;
                    cout << "Thank you for contact us...!!"
                         << endl;
                }
                else
                {
                    cout << "Sorry, we don't have enough blood storage"
                         << endl;
                }

                Blood_Requiter.blood_requiters_list();

                break;
            }

            case 2:
            {
                int year;
                int income;
                float percentage;

                string n;

                cout << "Enter Your name (name as 12th Result) : \n";
                cin.ignore();
                getline(cin, n);

                if (Money_Requiter.criteria(n, Blood_Donor.phone, Blood_Donor.age, &year, &income, &percentage))
                {
                    Money_Requiter.Insert_(n, Blood_Donor.phone, Blood_Donor.age, year, income, percentage);
                    cout << "----------------------------------------------------------------------------------------------" << endl;

                    cout << "Congratulations...You are eligible for scholarship..!"
                         << endl
                         << endl;
                    cout << "----------------------------------------------------------------------------------------------" << endl;

                    Money_Donor.money -= 50000;
                }
                else
                {
                    cout << "Sorry, You are not eligible for scholarship..!"
                         << endl
                         << endl;
                }

                cout << "Total Fund: " << Money_Donor.money << endl
                     << endl;
                Money_Requiter.money_requiters_list();

                break;
            }
            }

            break;
        }
        }

    end:
    {
    };
    }
    return 0;
}

void welcome()
{
    cout << endl;
    cout << "     =================================================================================================================================="
         << endl;
    cout << "                                                         Welcome to HelpX "
         << endl;
    cout << "     =================================================================================================================================="
         << endl;
    cout << endl;
}

void dashboard()
{
    system("PAUSE");
    system("CLS");

    welcome();
    cout << string(18, ' ');
    cout << "==================================================================================================" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(10, ' ') << "1. DONATE" << string(11, ' ') << "||" << string(9, ' ') << "2. REQUIREMENT" << string(7, ' ') << "||" << string(7, ' ') << "3. DONOR LIST" << string(10, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "==================================================================================================" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(6, ' ') << "4. Requiters List" << string(7, ' ') << "||" << string(7, ' ') << "5. BENEFITS OF" << string(9, ' ') << "||" << string(11, ' ') << "6. EXIT" << string(12, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(7, ' ') << "   DONATION" << string(12, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << string(30, ' ') << "||" << endl;
    cout << string(18, ' ');

    cout << "==================================================================================================" << endl;
}