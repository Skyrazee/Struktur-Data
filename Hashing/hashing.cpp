#include <iostream>
#include <string>
#include <bitset>
#include <unordered_map>

using namespace std;

// Define a structure to store account information
struct Account {
    string username, pass;
};

// Function to calculate a simple hash for a password
string CalculateHash(string pass) {
    int totalAscii = 0;
    for (int i = 0; i < pass.length(); i++) {
        char ch = pass[i];
        int ascii = static_cast<int>(ch);
        totalAscii += ascii;
    }
   
    // Convert the total ASCII value to a binary string
    string hash = bitset<16>(totalAscii).to_string();
    return hash;
}

int main() {
    // Create an unordered map to store accounts
    unordered_map<string, Account> accountMap(256);
    string user, pass;
   
    // Allow the user to create two accounts
    for (int i = 1; i < 3; i++) {
        cout << "Enter Username: ";
        cin >> user;
        cout << "Enter Password: ";
        cin >> pass;
        string hashedPass = CalculateHash(pass);

        // Create an account and store it in the map using the hash as the key
        Account account;
        account.username = user;
        account.pass = pass;
        accountMap[hashedPass] = account;

        cout << "Account added" << endl << "------------------------------------" << endl;
    }

    // Display all account details stored in the map
    for (const auto& entry : accountMap) {
        cout << "All Account details" << endl;
        cout << "Key: " << entry.first << endl;
        cout << "Username: " << entry.second.username << endl;
        cout << "Password: " << entry.second.pass << endl;
        cout << "------------------------------------" << endl;
    }

    // Allow the user to access an account by providing the hash
    while(true) {
        string accessKey;
        cout << "Enter Access Key: ";
        cin >> accessKey;
        if (accountMap.find(accessKey) != accountMap.end()) {
            cout << "------------------------------------" << endl;
            cout << "Account Details: " << endl;
            cout << "Username: " << accountMap[accessKey].username << endl;
            cout << "Password: " << accountMap[accessKey].pass << endl;
            break;
        } else {
            cout << "You have the wrong key, please try again next year.";
        }
    }   
}
