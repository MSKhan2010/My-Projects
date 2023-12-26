#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Account structure to store user details
struct Account {
    string name;
    string dob;
    string phoneNumber;
    string email;
    string cardNumber;
    string expiryDate;
    int securityCode;
};

// Function to generate a random 4-digit number for the security code
int generate_security_code() {
    return rand() % 9000 + 1000; // Generates a number between 1000 and 9999
}

string generate_card_number() {
    string cardNumber = "4";
    for (int i = 0; i < 15; ++i) {
        cardNumber += to_string(rand() % 10);
        if ((i + 1) % 4 == 0 && i != 14) {
            cardNumber += " ";
        }
    }
    return cardNumber;
}

string generate_expiry_date() {
    int currentYear = 2023; // Assuming current year is 2023
    int expiryYear = currentYear + rand() % 5;
    int expiryMonth = rand() % 12 + 1;
    return to_string(expiryMonth) + "/" + to_string(expiryYear);
}

bool validate_date(const string& dob) {
    // Basic check for date format (MM/DD/YYYY or MM-DD-YYYY)
    if (dob.length() != 10 || dob[2] != '/' || dob[5] != '/') {
        cout << "Please enter date of birth in format MM/DD/YYYY" << endl;
        return false;
    }
    // Additional validation for digits at appropriate places can be added here if needed
    return true;
}

void create_account(vector<Account>& accounts)
{
    Account newAccount;
    
    cout << "Enter name: ";
    cin >> newAccount.name;
    
    cout << "Enter dob (MM/DD/YYYY): ";
    cin >> newAccount.dob;
    while (!validate_date(newAccount.dob)) {
        cout << "Enter dob (MM/DD/YYYY): ";
        cin >> newAccount.dob;
    }
    
    cout << "Enter phone number: ";
    cin >> newAccount.phoneNumber;
    
    cout << "Enter email: ";
    cin >> newAccount.email;
    
    // Generate random card details
    newAccount.cardNumber = generate_card_number();
    newAccount.expiryDate = generate_expiry_date();
    newAccount.securityCode = generate_security_code();
    
    accounts.push_back(newAccount); // Add new account to the list
    
    cout << "Account Created Successfully!" << endl;
}

void list_accounts(const vector<Account>& accounts) {
    cout << "Accounts Information: " << endl;
    cout << "----------------------------------------------" << endl;
    cout << setw(20) << "Name" << setw(15) << "DOB" << setw(20) << "Phone Number" << setw(25) << "Email" << endl;
    cout << "----------------------------------------------" << endl;
    for (const auto& account : accounts) {
        cout << setw(20) << account.name << setw(15) << account.dob << setw(20) << account.phoneNumber << setw(25) << account.email << endl;
    }
}

void withdraw_funds()
{
    // Function logic for withdrawing funds
    // ...
}

int main(int argc, const char * argv[])
{
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    vector<Account> accounts; // Vector to store accounts
    
    bool running = true;
    
    while (running)
    {
        int opt;
        
        cout << "Welcome to Da Bank! What would you like to do?" << endl;
        cout << "1) Create an Account 2) Withdraw Funds 3) List Accounts 4) Exit" << endl;
        cin >> opt;
        
        switch (opt)
        {
            case 1:
                create_account(accounts);
                break;
            case 2:
                withdraw_funds();
                break;
            case 3:
                list_accounts(accounts);
                break;
            case 4:
                running = false;
                break;
            default:
                cout << "Invalid option. Please select a valid option." << endl;
                break;
        }
    }
    
    return 0;
}
