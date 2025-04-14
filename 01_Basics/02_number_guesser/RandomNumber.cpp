#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // For input validation

using namespace std;

int main() {
    srand(time(0));
    
    // Game configuration
    int maxNumber = 100;
    int maxAttempts = 0;
    int difficulty;
    
    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Choose difficulty:\n";
    cout << "1. Easy (1-50, unlimited guesses)\n";
    cout << "2. Medium (1-100, 15 guesses)\n";
    cout << "3. Hard (1-200, 10 guesses)\n";
    cout << "Enter choice (1-3): ";
    
    // Validate difficulty input
    while (!(cin >> difficulty) || difficulty < 1 || difficulty > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter 1, 2, or 3: ";
    }
    
    // Set game parameters based on difficulty
    switch(difficulty) {
        case 1:
            maxNumber = 50;
            maxAttempts = 0; // Unlimited
            break;
        case 2:
            maxNumber = 100;
            maxAttempts = 15;
            break;
        case 3:
            maxNumber = 200;
            maxAttempts = 10;
            break;
    }
    
    int secretNumber = rand() % maxNumber + 1;
    int guess;
    int attempts = 0;
    bool hasWon = false;
    
    cout << "\nI'm thinking of a number between 1 and " << maxNumber << ". Can you guess it?\n";
    
    // Main game loop
    while (maxAttempts == 0 || attempts < maxAttempts) {
        cout << "Enter your guess (" << (maxAttempts - attempts) << " left): ";
        
        // Validate guess input
        while (!(cin >> guess)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        
        attempts++;
        
        if (guess == secretNumber) {
            hasWon = true;
            break;
        } else if (guess < secretNumber) {
            cout << "Too low! ";
        } else {
            cout << "Too high! ";
        }
        
        // Give hint after 3 attempts
        if (attempts == 3) {
            if (secretNumber % 2 == 0) {
                cout << "(Hint: The number is even) ";
            } else {
                cout << "(Hint: The number is odd) ";
            }
        }
    }
    
    // Game result
    if (hasWon) {
        cout << "\nCongratulations! You guessed the number in " << attempts << " attempts!\n";
    } else {
        cout << "\nGame over! The number was " << secretNumber << ".\n";
    }
    
    return 0;
}