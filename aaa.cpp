#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class MathGame {
private:
    int category;
    int friendNum, tutorNum, goalNum;
    static int divideBy;
    double finalValue;
    fstream file;

public:
    // Constructor
    MathGame() {
        friendNum = 50;
        tutorNum = 30;
        goalNum = 100;
        finalValue = 0;
    }

   
    void chooseCategory() {
        cout << "\n=== Welcome to Mathematics Mind Game ===\n";
        cout << "1. One Digit Number (0 - 9)\n";
        cout << "2. Two Digit Number (10 - 99)\n";
        cout << "3. Three Digit Number (100 - 999)\n";
        cout << "Enter your choice: ";
        cin >> category;

        if (category < 1 || category > 3) {
            cout << "Invalid choice! Exiting program...\n";
            exit(0);
        }
    }

 
    void playGame() {
        string confirm;
        cout << "\n can you think a number in your mind? (yes/no): ";
        cin >> confirm;

        if (confirm != "yes" && confirm != "Yes") {
            cout << " than first think a number and came again\n";
            exit(0);
        }

        cout << "\nAdd your friend's number (" << friendNum << ") and press Enter...";
        cin.ignore();
        cin.get();

        cout << "Add your tutor's number (" << tutorNum << ") and press Enter...";
        cin.get();

        cout << "Add your goal target number (" << goalNum << ") and press Enter...";
        cin.get();

        cout << "Now divide the result by " << divideBy << " and press Enter...";
        cin.get();

        cout << "\nEnter the final value you got after all operations: ";
        cin >> finalValue;

       
        double reverseValue = (finalValue * divideBy) - friendNum - tutorNum - goalNum;

        
        cout << "\n----------------------------------------\n";
        cout << "I think the number you had in mind was: " << reverseValue << endl;
        cout << "----------------------------------------\n";

       
        saveToFile(reverseValue);
    }

   
    void saveToFile(double predicted) {
        file.open("math_game_result.txt", ios::out);
        file << "===== Mathematics Mind Game Result =====\n";
        file << "Friend number added: " << friendNum << endl;
        file << "Tutor number added: " << tutorNum << endl;
        file << "Goal number added: " << goalNum << endl;
        file << "Division factor: " << divideBy << endl;
        file << "----------------------------------------\n";
        file << "Predicted Number (User Thought): " << predicted << endl;
        file << "----------------------------------------\n";
        file.close();
       
    }

   
    ~MathGame() {
        cout << "\nThanks for playing the Mathematics Mind Game!\n.";
    }
};


int MathGame::divideBy = 2;

int main() {
    MathGame game;
    game.chooseCategory();
    game.playGame();
    return 0;
}