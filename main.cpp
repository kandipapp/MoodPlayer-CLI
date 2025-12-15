/**
 * Program: Mood-based Music Recommender
 * File: main.cpp
 * Description: Driver program to test the MoodPlayer class.
 */

#include <iostream>
#include "MoodPlayer20615981.h"

using namespace std;

int main() {
    MoodPlayer myPlayer; // Create object
    int choice;
    string inputMood;
    string lineInput; // Buffer for safe input reading

    cout << "========================================" << endl;
    cout << "   Welcome to MoodPlayer 20615981       " << endl;
    cout << "========================================" << endl;

    do {
        // Menu Display
        cout << "\n-------------------------------------------------------" << endl ;
        cout << "|      1. Set Mood (Happy, Sad, Energetic, Relaxed)   |" << endl;
        cout << "|      2. Play Current Track                          |" << endl;
        cout << "|      3. Next Track                                  |" << endl;
        cout << "|      4. Show Mood History                           |" << endl;
        cout << "|      5. Exit                                        |" << endl;
        cout << "-------------------------------------------------------" << endl ;
        cout << "Enter your choice: ";

        // Use getline to prevent infinite loops if user enters non-numeric characters
        getline(cin, lineInput);

        // Simple manual parsing to avoid exceptions
        if (lineInput == "1")
            choice = 1;

        else if (lineInput == "2") choice = 2;
        else if (lineInput == "3") choice = 3;
        else if (lineInput == "4") choice = 4;
        else if (lineInput == "5") choice = 5;
        else {
            // This catches invalid input: "1 sad", "hello", "10", empty lines, etc.
            cout << "Invalid input. Please enter a number 1-5 only." << endl;
            choice = 0; // Set to invalid number to ensure loop continues
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter your mood: ";
                getline(cin, inputMood);
                myPlayer.setMood(inputMood);
                break;

            case 2:
                myPlayer.playTrack();
                break;

            case 3:
                myPlayer.nextTrack();
                break;

            case 4:
                myPlayer.showMoodHistory();
                break;

            case 5:
                cout << "Exiting MoodPlayer. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please select 1-5." << endl;
        }

    } while (choice != 5);

    return 0;
}
