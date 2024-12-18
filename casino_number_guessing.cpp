#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

class CasinoGame {
private:
    int randomNumber;
    int lowerLimit;
    int upperLimit;
    int prizeMoney;

    
    void generateRandomNumber() {
        randomNumber = rand() % (upperLimit - lowerLimit + 1) + lowerLimit;
    }

public:
    
    CasinoGame() : randomNumber(0), lowerLimit(1), upperLimit(10), prizeMoney(0) {}

   
    void setDifficulty(int choice) {
        switch (choice) {
            case 1:
                lowerLimit = 1;
                upperLimit = 10;
                prizeMoney = 50;
                break;
            case 2:
                lowerLimit = 1;
                upperLimit = 50;
                prizeMoney = 500;
                break;
            case 3:
                lowerLimit = 1;
                upperLimit = 100;
                prizeMoney = 1000;
                break;
            default:
                cout << "Invalid choice! Defaulting to Easy level.\n";
                lowerLimit = 1;
                upperLimit = 10;
                prizeMoney = 50;
        }
        generateRandomNumber();
    }

    
    void startGame() {
        int guess;
        cout << "Guess the number (between " << lowerLimit << " and " << upperLimit << "): ";
        while (true) {
            cin >> guess;

            if (guess < lowerLimit || guess > upperLimit) {
                cout << "Please guess within the range (" << lowerLimit << "-" << upperLimit << "): ";
                continue;
            }

            if (guess == randomNumber) {
                cout << "Congratulations! You guessed the correct number.\n";
                cout << "You win $" << prizeMoney << " 🎉\n";
                break;
            } else if (guess < randomNumber) {
                cout << "Too low! Try again: ";
            } else {
                cout << "Too high! Try again: ";
            }
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));  

    CasinoGame game;
    char playAgain;

    do {
        cout << "🎲 Welcome to the Casino Number Guessing Game 🎲\n";
        cout << "Select Difficulty Level:\n";
        cout << "1. Easy (Range 1-10) - Prize: $50\n";
        cout << "2. Medium (Range 1-50) - Prize: $500\n";
        cout << "3. Hard (Range 1-100) - Prize: $1000\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        game.setDifficulty(choice);
        game.startGame();

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing! Goodbye.\n";
    return 0;
}
