#include <iostream>
#include <string>

using namespace std;
            // QUESTION ONE (1)

    int main()
{
    const int MAX_ACCOUNTS = 1000; // maximum number of accounts that the ATM machine can hold
    string userIds[MAX_ACCOUNTS];  // an array to store the user ids
    string passwords[MAX_ACCOUNTS]; // an array to store the password corresponding to the userids
    double balances[MAX_ACCOUNTS] = {0.0};
    int My_account = 0; // counts being created on the ATM machine
    int loggedInIndex = -1;

    char option; // variable to store the main menu option

    cout << "Hi! Welcome to KHIT ATM Machine!\n";
    cout << "ENJOY THE SMART BANK\n";


    do { // options to be displayed on the main menu
        cout << "Please select an option from the menu below:\n";
        cout << "l -> Login\n";
        cout << "C -> Create New Account\n";
        cout << "Q -> Quit\n";
        cout << "->  ";
        cin >> option;

        switch (option) {
            case 'C': // creating a new account
            case 'c': {
                if (My_account >= MAX_ACCOUNTS) { // checking if the maximum number of accounts is reached
                    cout << "Sorry, maximum number of accounts reached.\n";
                    break;
                }

                string userId, password;// storing the new password and user id of the new account created
                cout << "Please enter your user id: ";
                cin >> userId;


                //checking if the user id exists
                bool exists = false;
                for (int i = 0; i < My_account; i++) {
                    if (userIds[i] == userId) { // comparing the new user id with the rest of the existing ids
                        exists = true; // if match found then the user id is set to esist
                        break;
                    }
                }

                //if the user id exists then it will prompt the user to try a different one
                if (exists) {
                    cout << "User id already exists. Try a different id.\n";
                } else {
                    cout << "Please enter your password: ";
                    cin >> password;

                    userIds[My_account] = userId;
                    passwords[My_account] = password;
                    balances[My_account] = 0.0;
                    My_account++;

                    // message to be displayed when the user account has been successfully created
                    cout << "Thank You! Your account has been created!\n";
                    cout <<"ITS TIME TO ENJOY THE BEST ATM MACHINE\n";
                }
                break;
            }

            case 'L'://logging in
            case 'l':
                {
                string userId, password;
                cout << "Please enter your user id: ";
                cin >> userId;
                cout << "Please enter your password: ";
                cin >> password;

                //checking if the login names and password are correct
                loggedInIndex = -1;
                for (int i = 0; i < My_account; i++) {
                    if (userIds[i] == userId && passwords[i] == password) {
                        loggedInIndex = i;
                        break;
                    }
                }

                if (loggedInIndex != -1) { //if logging in is successful then a message will be displayed
                    cout << "PERMISSION Granted!\n";
                    char subOption;

                    do { //dispplay the logged in menu
                        cout << "d -> Deposit Money\n";
                        cout << "w -> Withdraw Money\n";
                        cout << "r -> Request Balance\n";
                        cout << "q -> Quit\n";
                        cout << "> ";
                        cin >> subOption;

                        switch (subOption) {
                            case 'D':
                            case 'd': {
                                double amount;
                                cout << "Amount of deposit: UGX";
                                cin >> amount;
                                balances[loggedInIndex] += amount;
                                cout << "UGX" << amount << " was deposited successfully.\n";
                                break;
                            }
                            case 'W':
                            case 'w': {
                                double amount;
                                cout << "Amount of withdrawal: UGX";
                                cin >> amount;

                                if (amount <= balances[loggedInIndex]) {
                                    balances[loggedInIndex] -= amount;
                                    cout << "UGX" << amount << " was withdrawn successfully.\n";
                                } else {
                                    cout << "Insufficient funds.\n";
                                }
                                break;
                            }
                            case 'R':
                            case 'r':
                                cout << "Your balance is UGX" << balances[loggedInIndex] << ".\n";
                                break;

                            case 'Q':
                            case 'q':
                                loggedInIndex = -1;  // Log out
                                break;

                            default:
                                cout << "Invalid option. Please try again.\n";
                        }
                    } while (subOption != 'q' && loggedInIndex != -1);
                } else {
                    cout << "*** LOGIN FAILED! ***\n";
                }
                break;
            }

            case 'Q':
            case 'q':
                cout << "Thank you for using the BEST KHIT ATM Machine!\n";
                cout << "HAVE A GOOD DAY\n";
                break;
                return 0;

            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (option != 'q');



    return 0;
}
