

#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Account
{
private:

    vector <unsigned int> generalAccountIDs = {};
    vector <unsigned int> privateAccountIDs = {};
    vector<float> generalAccountMoneyBalances = {};
    vector<float> privateAccountMoneyBalances = {};
    vector<float> generalAccountCryptoBalances = {};
    vector<float> privateAccountCryptoBalances = {};
    vector<unsigned int> generalAccountFirstDeposit = {};
    vector<unsigned int> privateAccountFirstDeposit = {};
    unsigned int dayCounter = 0;
    int generalAccountCounter = 0;
    int privateAccountCounter = 0;

public:

    unsigned int day = 12;
    unsigned int month = 12;
    unsigned int year = 2023;
    float generalAccountCryptoValue = 1.0;
    float privateAccountCryptoValue = 1.0;



    void menu()
    {

        do
        {
            unsigned int menuChoice;

            cout << setw(20) << " M E N U " << endl;
            cout << "-------------------------------" << endl;
            cout << " 1. Create general account" << endl
                << " 2. Create private account" << endl
                << " 3. Deposit money" << endl
                << " 4. Withdraw money" << endl
                << " 5. Buy crypto currency" << endl
                << " 6. Sell crypto currency" << endl
                << " 7. Date" << endl
                << " 8. List Accounts" << endl
                << " 9. Day Skip " << endl
                << " 10. Profit " << endl
                << " General Account CRY/TRY : " << Account::generalAccountCryptoValue << endl
                << " Private Account CRY/TRY : " << Account::privateAccountCryptoValue << endl
                << " Current Date: " << Account::day << " / " << Account::month << " / " << Account::year << endl;
            cout << "-------------------------------" << endl;

            cout << "What do you want to do? (Enter the number of your request) :";
            cin >> menuChoice;
            cout << endl;

            switch (menuChoice)
            {
            case 1:
                Account::createGeneralAccount();
                break;
            case 2:
                Account::createPrivateAccount();
                break;
            case 3:
                Account::depositMoney();
                break;
            case 4:
                Account::withdrawMoney();
                break;
            case 5:
                Account::buy();
                break;
            case 6:
                Account::sell();
                break;
            case 7:
                Account::date();
                break;
            case 8:
                Account::listAccounts();
                break;
            case 9:
                Account::daySkip();
                break;
            case 10:
                Account::profit();
            default:
                cout << " Invalid option. " << endl;
                break;
            }
            system("pause");
            system("CLS");
        } while (1);

    }

    void buy()
    {
        char choice;
        do
        {

            cout << "Which type of account do you have? (g/p) : ";
            cin >> choice;
            if (choice == 'g')
            {
                cout << setw(18) << "Account ID" << setw(18) << "TRY Balance" << setw(18) << "Crypto Balance" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                for (int i = 0; i < generalAccountCounter; i++)
                    cout << i + 1 << setw(18) << generalAccountIDs[i] << setw(18) << generalAccountMoneyBalances[i] << setw(18) << generalAccountCryptoBalances[i] << endl;
                unsigned int accountChoice;
                if (generalAccountCounter == 0)
                {
                    char yesOrNoChoice;
                    do
                    {
                        cout << "There is no existing account. Do you want to create one? (y/n) : ";
                        cin >> yesOrNoChoice;
                        switch (yesOrNoChoice)
                        {
                        case 'y':
                            Account::createGeneralAccount();
                            break;
                        case 'n':
                            Account::menu();
                            break;
                        default:
                            cout << "Invalid option." << endl;
                            break;
                        }
                    } while (yesOrNoChoice != 'y' && yesOrNoChoice != 'n');
                }
                else
                {
                    cout << "Which account is yours? (Enter the number of your account): ";
                    cin >> accountChoice;
                    cout << " CRY/TRY : " << generalAccountCryptoValue << endl;
                    float buyChoice;
                    cout << " How many crypto currency do you want to buy? : ";
                    cin >> buyChoice;
                    if (generalAccountMoneyBalances[accountChoice - 1] < buyChoice * generalAccountCryptoValue)
                    {
                        cout << " Insufficient balance !" << endl;
                        cout << endl;
                        Account::buy();
                    }
                    else
                    {
                        generalAccountMoneyBalances[accountChoice - 1] -= (float)buyChoice * generalAccountCryptoValue;
                        generalAccountCryptoBalances[accountChoice - 1] += (float)buyChoice;
                        system("pause");
                        system("CLS");
                        Account::menu();
                    }
                }
            }
            if (choice == 'p')
            {
                cout << setw(18) << "Account ID" << setw(18) << "TRY Balance" << setw(18) << "Crypto Balance" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                for (int i = 0; i < privateAccountCounter; i++)
                    cout << i + 1 << setw(18) << privateAccountIDs[i] << setw(18) << privateAccountMoneyBalances[i] << setw(18) << privateAccountCryptoBalances[i] << endl;
                unsigned int accountChoice2;
                if (privateAccountCounter == 0)
                {
                    char yesOrNoChoice;
                    do
                    {
                        cout << "There is no existing account. Do you want to create one? (y/n) : ";
                        cin >> yesOrNoChoice;
                        switch (yesOrNoChoice)
                        {
                        case 'y':
                            Account::createPrivateAccount();
                            break;
                        case 'n':
                            Account::menu();
                            break;
                        default:
                            cout << "Invalid option." << endl;
                            break;
                        }
                    } while (yesOrNoChoice != 'y' && yesOrNoChoice != 'n');
                }
                else
                {
                    cout << "Which account is yours? (Enter the number of your account): ";
                    cin >> accountChoice2;
                    cout << " CRY/TRY : " << privateAccountCryptoValue << endl;
                    float buyChoice2;
                    cout << " How many crypto currency do you want to buy? : ";
                    cin >> buyChoice2;
                    if (privateAccountMoneyBalances[accountChoice2 - 1] < ((float)buyChoice2 * privateAccountCryptoValue))
                    {
                        cout << " Insufficient balance !" << endl;
                        cout << endl;
                        Account::buy();
                    }
                    else
                    {
                        privateAccountMoneyBalances[accountChoice2 - 1] -= ((float)buyChoice2 * privateAccountCryptoValue);
                        privateAccountCryptoBalances[accountChoice2 - 1] += buyChoice2;
                        system("pause");
                        system("CLS");
                        Account::menu();
                    }
                }
            }
        } while (choice != 'g' && choice != 'p');
    }

    void sell()
    {
        char choice;
        do
        {

            cout << "Which type of account do you have? (g/p) : ";
            cin >> choice;
            if (choice == 'g')
            {
                cout << setw(18) << "Account ID" << setw(18) << "TRY Balance" << setw(18) << "Crypto Balance" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                for (int i = 0; i < generalAccountCounter; i++)
                    cout << i + 1 << setw(18) << generalAccountIDs[i] << setw(18) << generalAccountMoneyBalances[i] << setw(18) << generalAccountCryptoBalances[i] << endl;
                unsigned int accountChoice;
                if (generalAccountCounter == 0)
                {
                    char yesOrNoChoice;
                    do
                    {
                        cout << "There is no existing account. Do you want to create one? (y/n) : ";
                        cin >> yesOrNoChoice;
                        switch (yesOrNoChoice)
                        {
                        case 'y':
                            Account::createGeneralAccount();
                            break;
                        case 'n':
                            Account::menu();
                            break;
                        default:
                            cout << "Invalid option." << endl;
                        }
                    } while (yesOrNoChoice != 'y' && yesOrNoChoice != 'n');
                }
                else
                {
                    cout << "Which account is yours? (Enter the number of your account): ";
                    cin >> accountChoice;
                    cout << " CRY/TRY : " << generalAccountCryptoValue << endl;
                    float sellChoice;
                    cout << " How many crypto currency do you want to sell? : ";
                    cin >> sellChoice;
                    if (generalAccountCryptoBalances[accountChoice - 1] < sellChoice)
                    {
                        cout << " Insufficient balance !" << endl;
                        cout << endl;
                        Account::sell();
                    }
                    else
                    {
                        generalAccountMoneyBalances[accountChoice - 1] += (float)sellChoice * generalAccountCryptoValue;
                        generalAccountCryptoBalances[accountChoice - 1] -= (float)sellChoice;
                        system("pause");
                        system("CLS");
                        Account::menu();
                    }
                }
            }
            if (choice == 'p')
            {
                cout << setw(18) << "Account ID" << setw(18) << "TRY Balance" << setw(18) << "Crypto Balance" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                for (int i = 0; i < privateAccountCounter; i++)
                    cout << i + 1 << setw(18) << privateAccountIDs[i] << setw(18) << privateAccountMoneyBalances[i] << setw(18) << privateAccountCryptoBalances[i] << endl;
                unsigned int accountChoice2;
                if (privateAccountCounter == 0)
                {
                    char yesOrNoChoice;
                    do
                    {
                        cout << "There is no existing account. Do you want to create one? (y/n) : ";
                        cin >> yesOrNoChoice;
                        switch (yesOrNoChoice)
                        {
                        case 'y':
                            Account::createPrivateAccount();
                            break;
                        case 'n':
                            Account::menu();
                            break;
                        default:
                            cout << "Invalid option." << endl;
                        }
                    } while (yesOrNoChoice != 'y' && yesOrNoChoice != 'n');
                }
                else
                {
                    cout << "Which account is yours? (Enter the number of your account): ";
                    cin >> accountChoice2;
                    cout << " CRY/TRY : " << privateAccountCryptoValue << endl;
                    float sellChoice;
                    cout << " How many crypto currency do you want to sell? : ";
                    cin >> sellChoice;
                    if (privateAccountCryptoBalances[accountChoice2 - 1] < sellChoice)
                    {
                        cout << " Insufficient balance !" << endl;
                        cout << endl;
                        Account::sell();
                    }
                    else
                    {
                        privateAccountMoneyBalances[accountChoice2 - 1] += sellChoice * privateAccountCryptoValue;
                        privateAccountCryptoBalances[accountChoice2 - 1] -= sellChoice;
                        system("pause");
                        system("CLS");
                        Account::menu();
                    }
                }
            }
        } while (choice != 'g' && choice != 'p');
    }; // provides to sell crypto currency

    void profit()
    {

        char choice;
        do
        {

            cout << "Which type of account do you have? (g/p) : ";
            cin >> choice;
            if (choice == 'g')
            {
                cout << setw(18) << "Account ID" << setw(18) << "TRY Balance" << setw(18) << "Crypto Balance" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                for (int i = 0; i < generalAccountCounter; i++)
                    cout << i + 1 << setw(18) << generalAccountIDs[i] << setw(18) << generalAccountMoneyBalances[i] << setw(18) << generalAccountCryptoBalances[i] << endl;
                unsigned int accountChoice;
                if (generalAccountCounter == 0)
                {
                    char yesOrNoChoice;
                    do
                    {
                        cout << "There is no existing account. Do you want to create one? (y/n) : ";
                        cin >> yesOrNoChoice;
                        switch (yesOrNoChoice)
                        {
                        case 'y':
                            Account::createGeneralAccount();
                            break;
                        case 'n':
                            Account::menu();
                            break;
                        default:
                            cout << "Invalid option." << endl;
                        }
                    } while (yesOrNoChoice != 'y' && yesOrNoChoice != 'n');
                }
                else
                {
                    cout << "Which account is yours? (Enter the number of your account): ";
                    cin >> accountChoice;
                    float profit2 = (generalAccountMoneyBalances[accountChoice - 1] + generalAccountCryptoBalances[accountChoice - 1] * generalAccountCryptoValue) - generalAccountFirstDeposit[accountChoice - 1];
                    cout << "Your Profit :" << profit2;
                }
            }
            if (choice == 'p')
            {
                cout << setw(18) << "Account ID" << setw(18) << "TRY Balance" << setw(18) << "Crypto Balance" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                for (int i = 0; i < privateAccountCounter; i++)
                    cout << i + 1 << setw(18) << privateAccountIDs[i] << setw(18) << privateAccountMoneyBalances[i] << setw(18) << privateAccountCryptoBalances[i] << endl;
                unsigned int accountChoice2;
                if (privateAccountCounter == 0)
                {
                    char yesOrNoChoice;
                    do
                    {
                        cout << "There is no existing account. Do you want to create one? (y/n) : ";
                        cin >> yesOrNoChoice;
                        switch (yesOrNoChoice)
                        {
                        case 'y':
                            Account::createPrivateAccount();
                            break;
                        case 'n':
                            Account::menu();
                            break;
                        default:
                            cout << "Invalid option." << endl;
                        }
                    } while (yesOrNoChoice != 'y' && yesOrNoChoice != 'n');
                }
                else
                {
                    cout << "Which account is yours? (Enter the number of your account): ";
                    cin >> accountChoice2;
                    float profit = (privateAccountMoneyBalances[accountChoice2 - 1] + privateAccountCryptoBalances[accountChoice2 - 1] * privateAccountCryptoValue) - privateAccountFirstDeposit[accountChoice2 - 1];
                    cout << "Your Profit : " << profit;
                }
            }
        } while (choice != 'g' && choice != 'p');

    } // calculates the total profit since account's opening date


    void setFirstDate()
    {
        unsigned int firstDay;
        unsigned int firstMonth;
        unsigned int firstYear;

        cout << " You must choose a date before using the program (dd/mm/yy) : ";
        cin >> firstDay >> firstMonth >> firstYear;
        cout << endl;
        day = firstDay;
        month = firstMonth;
        year = firstYear;
        system("CLS");
    }

    void date()
    {

        char setDateChoice;
        cout << "Current Date : " << day << " / " << month << " / " << year << endl << endl;
        cout << "Do you want to set date? (y/n) :";
        cin >> setDateChoice;
        cout << endl;

        if (setDateChoice == 'y')
        {
            int formerDay = day;
            int formerMonth = month;
            int formerYear = year;
            do
            {
                cout << "Please enter day, month, year: ";
                cin >> day >> month >> year;
                if (month > 12 || month == 0)
                {
                    cout << "Please enter a valid month. " << endl;
                }
                if (month == 2 && year % 4 == 0 && day > 29 || day == 0)
                {
                    cout << "Please enter a valid day. " << endl;
                }
                else if (month == 2 && year % 4 != 0 && day > 28)
                {
                    cout << "Please enter a  valid day." << endl;
                }
            } while (month > 12 || month == 0 || day > 31 || day == 0 || (month == 2 && year % 4 == 0 && day > 29 || day == 0) || (month == 2 && year % 4 != 0 && day > 28));


            int sumOfDays = 0;

            if (year == formerYear)
            {
                if (month > formerMonth)
                    if (day >= formerDay)
                        sumOfDays = 30 * (month - formerMonth) + abs(int(day - formerDay));
                    else if (day < formerDay)
                        sumOfDays = 30 * (month - formerMonth) - abs(int(day - formerDay));
                    else if (month == formerMonth)
                    {
                        if (day >= formerDay)
                            sumOfDays = day - formerDay;
                        else
                            sumOfDays = 0;
                    }
                    else
                        sumOfDays = 0;
            }
            else if (year > formerYear)
            {
                if (month >= formerMonth)
                {
                    if (day == formerDay)
                        sumOfDays = 365 * (year - formerYear) + 30 * (month - formerMonth);
                    else if (day > formerDay)
                        sumOfDays = 365 * (year - formerYear) + 30 * (month - formerMonth) + (day - formerDay);
                    else
                        sumOfDays = 365 * (year - formerYear) + (30 * (month - formerMonth) - abs(int(day - formerDay)));
                }
                else
                    sumOfDays = 30 * (12 - abs(int(month - formerMonth)));
            }
            else
                sumOfDays = 0;

            for (int i = 0; i < sumOfDays; i++)
                Account::daySkip();
        }

        else if (setDateChoice == 'n')
        {
            system("CLS");
            Account::menu();
        }
    }

    void createGeneralAccount()
    {
        unsigned int accountIdEntered;
        float firstDeposit;
        cout << "Please enter an account ID: (It must contain only numbers) ";
        cin >> accountIdEntered;
        generalAccountIDs.push_back(accountIdEntered);
        cout << "How much do you want to deposit? : ";
        cin >> firstDeposit;
        generalAccountMoneyBalances.push_back(firstDeposit);
        generalAccountCryptoBalances.push_back(0);
        generalAccountFirstDeposit.push_back(firstDeposit);
        generalAccountCounter++;
    }

    void createPrivateAccount()
    {
        unsigned int accountIdEntered;
        float firstDeposit;
        cout << "Please enter an account ID: (It must contain only numbers) ";
        cin >> accountIdEntered;
        privateAccountIDs.push_back(accountIdEntered);
        cout << "How much do you want to deposit? : ";
        cin >> firstDeposit;
        privateAccountMoneyBalances.push_back(firstDeposit);
        privateAccountCryptoBalances.push_back(0);
        privateAccountFirstDeposit.push_back(firstDeposit);
        privateAccountCounter++;
    }
    void depositMoney()
    {
        char accountType;
        cout << "Which type of account do you want to deposit? (g/p) :";
        cin >> accountType;
        cout << endl;
        switch (accountType)
        {
        case 'g':
            unsigned int accountNumberChoice;
            float deposit;
            cout << setw(18) << "Account ID" << setw(18) << "TRY Balance" << setw(18) << "Crypto Balance" << endl;
            cout << "--------------------------------------------------------------------------" << endl;

            if (generalAccountCounter == 0)
            {
                char choice;
                cout << "There is no existing account. Do you want to create one? (y/n) :";
                cin >> choice;
                if (choice == 'y')
                {
                    Account::createGeneralAccount();
                    system("pause");
                    system("CLS");
                    Account::menu();
                }
                else if (choice == 'n')
                {
                    system("pause");
                    system("CLS");
                    Account::menu();
                }

            }

            else
            {
                for (int i = 0; i < generalAccountCounter; i++)
                    cout << i + 1 << setw(18) << generalAccountIDs[i] << setw(18) << generalAccountMoneyBalances[i] << setw(18) << generalAccountCryptoBalances[i] << endl;
                cout << "Which account do you want to deposit? (Enter the number of account) :";
                cin >> accountNumberChoice;
                cout << "How much money do you want to deposit? :";
                cin >> deposit;
                generalAccountMoneyBalances[accountNumberChoice - 1] += deposit;
                break;
            }
        case 'p':
            int accountNumberChoice2;
            float deposit2;
            cout << setw(18) << "Account ID" << setw(18) << "TRY Balance" << setw(18) << "Crypto Balance" << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            if (privateAccountCounter == 0)
            {
                char choice;
                cout << "There is no existing account. Do you want to create one? (y/n) : ";
                cin >> choice;
                if (choice == 'y')
                {
                    Account::createPrivateAccount();
                    system("pause");
                    system("CLS");
                    Account::menu();
                }
                else if (choice == 'n')
                {
                    system("pause");
                    system("CLS");
                    Account::menu();
                }
            }
            for (int i = 0; i < privateAccountCounter; i++)
                cout << i + 1 << setw(18) << privateAccountIDs[i] << setw(18) << privateAccountMoneyBalances[i] << setw(18) << privateAccountCryptoBalances[i] << endl;
            cout << "Which account do you want to deposit? (Enter the number of account) :";
            cin >> accountNumberChoice2;
            cout << "How much money do you want to deposit? :";
            cin >> deposit2;
            privateAccountMoneyBalances[accountNumberChoice2 - 1] += deposit2;
            break;

        }
    }

    void withdrawMoney()
    {
        char accountType;
        cout << "Which type of account do you want to withdraw from? (g/p) :";
        cin >> accountType;
        switch (accountType)
        {
        case 'g':
            unsigned int accountNumberChoice;
            float withdraw;
            cout << setw(18) << "Account ID" << setw(18) << "TRY Balance" << setw(18) << "Crypto Balance" << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            for (int i = 0; i < generalAccountCounter; i++)
                cout << i + 1 << setw(18) << generalAccountIDs[i] << setw(18) << generalAccountMoneyBalances[i] << setw(18) << generalAccountCryptoBalances[i] << endl;
            cout << "Which account do you want to withdraw from? (Enter the number of account) : ";
            cin >> accountNumberChoice;
            cout << "How much do you want to withdraw? : ";
            cin >> withdraw;
            cout << endl;
            if (generalAccountMoneyBalances[accountNumberChoice - 1] < withdraw)
            {
                cout << setw(18) << "Account ID" << setw(18) << "TRY Balance" << setw(18) << "Crypto Balance" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                for (int i = 0; i < generalAccountCounter; i++)
                    cout << i + 1 << setw(18) << generalAccountIDs[i] << setw(18) << generalAccountMoneyBalances[i] << setw(18) << generalAccountCryptoBalances[i] << endl;
                cout << " Insufficient balance. Do you want to withdraw another amount? (y/n) : ";
                char withdrawMoneyChoice;
                cin >> withdrawMoneyChoice;
                if (withdrawMoneyChoice == 'y')
                    Account::withdrawMoney();
                else if (withdrawMoneyChoice == 'n')
                    Account::menu();
            }
            else
                generalAccountMoneyBalances[accountNumberChoice - 1] -= withdraw;
            break;
        case 'p':
            int accountNumberChoice2;
            float withdraw2;
            cout << setw(18) << "Account ID" << setw(18) << "TRY Balance" << setw(18) << "Crypto Balance" << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            for (int i = 0; i < privateAccountCounter; i++)
                cout << i + 1 << setw(18) << privateAccountIDs[i] << setw(18) << privateAccountMoneyBalances[i] << setw(18) << privateAccountCryptoBalances[i] << endl;
            cout << "Which account do you want to withdraw from? (Enter the number of account) :";
            cin >> accountNumberChoice2;
            cout << "How much do you want to withdraw? :";
            cin >> withdraw2;
            if (privateAccountMoneyBalances[accountNumberChoice2 - 1] < withdraw2)
            {
                cout << setw(18) << "Account ID" << setw(18) << "TRY Balance" << setw(18) << "Crypto Balance" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                for (int i = 0; i < privateAccountCounter; i++)
                    cout << i + 1 << setw(18) << privateAccountIDs[i] << setw(18) << privateAccountMoneyBalances[i] << setw(18) << privateAccountCryptoBalances[i] << endl;
                cout << " Insufficient balance. Do you want to withdraw another amount? (y/n) : ";
                char withdrawMoneyChoice;
                cin >> withdrawMoneyChoice;
                if (withdrawMoneyChoice == 'y')
                    Account::withdrawMoney();
                else if (withdrawMoneyChoice == 'n')
                    Account::menu();
            }
            else
                privateAccountMoneyBalances[accountNumberChoice2 - 1] -= withdraw2;
            break;
        }
    }

    void listAccounts()
    {
        char listAccountsAnswer;

        do
        {
            cout << "Which type of accounts do you want to list? (g/p) : ";
            cin >> listAccountsAnswer;

            if (listAccountsAnswer == 'g')
            {
                cout << setw(18) << "Account ID" << setw(18) << "TRY Balance" << setw(18) << "Crypto Balance" << setw(18) << "Account Type" << endl;
                cout << "----------------------------------------------------------------------------------" << endl;

                for (int i = 0; i < (generalAccountCounter); i++)
                {
                    cout << i + 1 << setw(18) << generalAccountIDs[i] << setw(18) << generalAccountMoneyBalances[i] << setw(18) << generalAccountCryptoBalances[i] << setw(18) << "General" << endl;
                }
                system("pause");
                system("CLS");
                Account::menu();
            }
            else if (listAccountsAnswer == 'p')
            {
                cout << setw(18) << "Account ID" << setw(18) << "TRY Balance" << setw(18) << "Crypto Balance" << setw(18) << "Account Type" << endl;
                cout << "----------------------------------------------------------------------------------" << endl;

                for (int i = 0; i < (privateAccountCounter); i++)
                {
                    cout << i + 1 << setw(18) << privateAccountIDs[i] << setw(18) << privateAccountMoneyBalances[i] << setw(18) << privateAccountCryptoBalances[i] << setw(18) << "Private" << endl;
                }
                system("pause");
                system("CLS");
                Account::menu();
            }
            else
            {
                cout << "Invalid option..." << endl;
                system("pause");
                Account::listAccounts();
            }

        } while (listAccountsAnswer != 'p' && listAccountsAnswer != 'g');
    }
    void daySkip()
    {
        dayCounter++;
        day++;

        if (dayCounter % 15 != 0)
            generalAccountCryptoValue += generalAccountCryptoValue * 1 / 100;
        else
            generalAccountCryptoValue -= generalAccountCryptoValue * 5 / 100;

        int randomDayDecrease1;
        int randomDayDecrease2;
        int randomDayDecrease3;
        srand(time(0));
        randomDayDecrease1 = rand() % 31;
        randomDayDecrease2 = rand() % 31;
        randomDayDecrease3 = rand() % 31;

        do
        {

            randomDayDecrease1 = rand() % 31;
            randomDayDecrease2 = rand() % 31;
            randomDayDecrease3 = rand() % 31;

        } while (randomDayDecrease1 == randomDayDecrease2 || randomDayDecrease1 == randomDayDecrease3 || randomDayDecrease2 == randomDayDecrease3);

        if (dayCounter == randomDayDecrease1)
            privateAccountCryptoValue -= privateAccountCryptoValue * 1 / 10;
        else if (dayCounter == randomDayDecrease2)
            privateAccountCryptoValue -= privateAccountCryptoValue * 1 / 10;
        else if (dayCounter == randomDayDecrease3)
            privateAccountCryptoValue -= privateAccountCryptoValue * 1 / 10;
        else
            privateAccountCryptoValue += privateAccountCryptoValue * 5 / 100;


        if (day > 30)
        {
            month++;
            day = 1;

            if (month == 13)
            {
                year++;
                month = 1;
            }
        }

    }
};


int main()
{
    Account account;

    account.setFirstDate();

    do
    {
        unsigned int menuChoice;

        cout << setw(20) << " M E N U " << endl;
        cout << "-------------------------------" << endl;
        cout << " 1. Create general account" << endl
            << " 2. Create private account" << endl
            << " 3. Deposit money" << endl
            << " 4. Withdraw money" << endl
            << " 5. Buy crypto currency" << endl
            << " 6. Sell crypto currency" << endl
            << " 7. Date" << endl
            << " 8. List Accounts" << endl
            << " 9. Day Skip " << endl
            << " 10. Profit" << endl
            << " General Account CRY/TRY : " << account.generalAccountCryptoValue << endl
            << " Private Account CRY/TRY : " << account.privateAccountCryptoValue << endl
            << " Current Date: " << account.day << " / " << account.month << " / " << account.year << endl;
        cout << "-------------------------------" << endl;

        cout << "What do you want to do? (Enter the number of your request) :";
        cin >> menuChoice;
        cout << endl;

        switch (menuChoice)
        {
        case 1:
            account.createGeneralAccount();
            break;
        case 2:
            account.createPrivateAccount();
            break;
        case 3:
            account.depositMoney();
            break;
        case 4:
            account.withdrawMoney();
            break;
        case 5:
            account.buy();
            break;
        case 6:
            account.sell();
            break;
        case 7:
            account.date();
            break;
        case 8:
            account.listAccounts();
            break;
        case 9:
            account.daySkip();
            break;
        case 10:
            account.profit();
            break;
        default:
            cout << " Invalid option. " << endl;
            break;
        }
        system("pause");
        system("CLS");
    } while (1);





}
