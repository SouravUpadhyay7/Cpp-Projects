#include <iostream>
#include <fstream> 
#include <string>  
using namespace std;


void registerUser();
bool loginUser();
void showMenu();

int main() {
    int choice;

    do {
        showMenu();
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1: // Register
                registerUser();
                break;

            case 2: // Login
                if (loginUser()) {
                    cout << "🎉 Login successful! Welcome back.\n";
                } else {
                    cout << "❌ Invalid username or password. Please try again.\n";
                }
                break;

            case 3: // Exit
                cout << "Exiting the program. Goodbye! 👋\n";
                break;

            default:
                cout << "❌ Invalid choice. Please select from the menu.\n";
        }
    } while (choice != 3);

    return 0;
}

void showMenu() {
    cout << "\n--- Login and Registration System ---\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
}

void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ofstream file;
    file.open(username + ".txt");
    file << username << endl << password;
    file.close();

    cout << "✅ Registration successful! You can now log in.\n";
}

bool loginUser() {
    string username, password, storedUsername, storedPassword;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream file;
    file.open(username + ".txt");
    if (file.is_open()) {
        getline(file, storedUsername);
        getline(file, storedPassword);
        file.close();

        if (storedUsername == username && storedPassword == password) {
            return true;
        }
    }
    return false;
}
