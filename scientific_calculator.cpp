#include <iostream>
#include <cmath> 
#include <limits> 

using namespace std;


void showMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double modulo(int a, int b);
double sine(double x);
double cosine(double x);
double logarithm(double x);

int main() {
    int choice;
    double num1, num2;

    cout << "🎉 Welcome to the Scientific Calculator! 🎉\n";

    do {
        showMenu();
        cout << "Enter your choice (1-8) or 0 to exit: ";
        cin >> choice;

        
        if (cin.fail()) {
            cout << "❌ Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: // Addition
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << add(num1, num2) << endl;
                break;

            case 2: // Subtraction
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << subtract(num1, num2) << endl;
                break;

            case 3: // Multiplication
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << multiply(num1, num2) << endl;
                break;

            case 4: // Division
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                if (num2 != 0) {
                    cout << "Result: " << divide(num1, num2) << endl;
                } else {
                    cout << "❌ Division by zero is not allowed.\n";
                }
                break;

            case 5: // Modulo
                cout << "Enter two integers: ";
                int int1, int2;
                cin >> int1 >> int2;
                if (int2 != 0) {
                    cout << "Result: " << modulo(int1, int2) << endl;
                } else {
                    cout << "❌ Division by zero is not allowed.\n";
                }
                break;

            case 6: // Sine
                cout << "Enter an angle in radians: ";
                cin >> num1;
                cout << "Result: " << sine(num1) << endl;
                break;

            case 7: // Cosine
                cout << "Enter an angle in radians: ";
                cin >> num1;
                cout << "Result: " << cosine(num1) << endl;
                break;

            case 8: // Logarithm
                cout << "Enter a positive number: ";
                cin >> num1;
                if (num1 > 0) {
                    cout << "Result: " << logarithm(num1) << endl;
                } else {
                    cout << "❌ Logarithm is undefined for non-positive numbers.\n";
                }
                break;

            case 0:
                cout << "Exiting the calculator. Thank you for using it! 🎉\n";
                break;

            default:
                cout << "❌ Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}


void showMenu() {
    cout << "\n--- Scientific Calculator ---\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulo\n";
    cout << "6. Sine\n";
    cout << "7. Cosine\n";
    cout << "8. Logarithm\n";
    cout << "0. Exit\n";
}

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }
double modulo(int a, int b) { return a % b; }
double sine(double x) { return sin(x); }
double cosine(double x) { return cos(x); }
double logarithm(double x) { return log(x); }
