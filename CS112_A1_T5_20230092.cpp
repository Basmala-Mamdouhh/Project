#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

bool winner(vector<int>& win_test) { // Function to check winner
    if (win_test.size() < 3)
        return false;

    for (size_t i = 0; i < win_test.size(); ++i) {
        for (size_t j = i + 1; j < win_test.size(); ++j) {
            for (size_t k = j + 1; k < win_test.size(); ++k) {
                if (win_test[i] + win_test[j] + win_test[k] == 15)
                    return true; // Return true if only player win
            }
        }
    }
    return false; // Return false if no winning combination is found
}

void scrabble_game() {
    cout << "*" << endl;
    cout << "Welcome to Number Scrabble Game!\nIn this game, each player choose a number between 1 and 9." << endl;
    cout << "The first player to collect numbers that add up to 15 wins.Players cannot choose the same number." << endl;
    cout << "If both players do not collect 15, then the game will end in a draw." << endl;
    cout << "*\n" << endl;

    vector<int> n_scrabble{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> player1_list;
    vector<int> player2_list;
    cout << "Numbers: ";
    for (int num: n_scrabble)
        cout << num << " ";
    cout << endl;

    bool game_running = true; // Variable to track game state

    while (game_running) { // loop to 2 players to check the winner or the draw game
        // choice player 1
        int choice1;
        cout << "Player1: Please enter a number from list: ";
        cin >> choice1;

        if (cin.fail() || choice1 < 1 || choice1 > 9) {  // condition to check if the input is valid or not
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }

        if (find(n_scrabble.begin(), n_scrabble.end(), choice1) == n_scrabble.end()) {
            cout << "Number already chosen or invalid. Choose a different number." << endl;
            continue;
        }

        // put choice1 in player1_list and remove it from n_scrabble
        player1_list.push_back(choice1);
        n_scrabble.erase(remove(n_scrabble.begin(), n_scrabble.end(), choice1), n_scrabble.end());
        cout << "==========================================================================" << endl;
        cout << "Numbers of list become: ";
        for (int num: n_scrabble)
            cout << num << " ";
        cout << endl;

        if (winner(player1_list)) { // call winner function to check the win
            cout << "==========================================================================" << endl;
            cout << "Numbers of player1 : ";
            for (int num: player1_list)
                cout << num << " ";
            cout << endl;
            cout << "Congratulations! player1 wins" << endl;
            game_running = false; // End the game if player1 wins
            break;
        }

        if (n_scrabble.empty()) { // if there are no numbers in n_scrabble and no winner the game ends in draw
            cout << "==========================================================================" << endl;
            cout << "Numbers of player1 : ";
            for (int num: player1_list)
                cout << num << " ";
            cout << endl;
            cout << "Numbers of player2 : ";
            for (int num: player2_list)
                cout << num << " ";
            cout << endl;
            cout << "No winner! The game ends in a draw." << endl;
            game_running = false; // End the game if no winner
            break;
        }

        // choice player 2
        int choice2;
        cout << "Player2: Please enter a number from list: ";
        cin >> choice2;

        if (cin.fail() || choice1 < 1 || choice1 > 9) { // condition to check if the input is valid or not
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;
        }

        if (find(n_scrabble.begin(), n_scrabble.end(), choice2) == n_scrabble.end()) {
            cout << "Number already chosen or invalid. Choose a different number." << endl;
            continue;
        }

        // put choice2 in player2_list and remove it from n_scrabble
        player2_list.push_back(choice2);
        n_scrabble.erase(remove(n_scrabble.begin(), n_scrabble.end(), choice2), n_scrabble.end());
        cout << "==========================================================================" << std::endl;
        cout << "Numbers of list become: ";
        for (int num: n_scrabble)
            cout << num << " ";
        cout << endl;

        if (winner(player2_list)) { // call winner function to check the win
            cout << "==========================================================================" << endl;
            cout << "Numbers of player2 : ";
            for (int num: player2_list)
                cout << num << " ";
            cout << endl;
            cout << "Congratulations! player2 wins" << endl;
            game_running = false; // End the game if player2 wins
            break;
        }

        if (n_scrabble.empty()) { // if there are no numbers in n_scrabble and no winner the game ends in draw
            cout << "==========================================================================" << endl;
            cout << "Numbers of player1 : ";
            for (int num: player1_list)
                cout << num << " ";
            cout << endl;
            cout << "Numbers of player2 : ";
            for (int num: player2_list)
                cout << num << " ";
            cout << endl;
            cout << "No winner! The game ends in a draw." << endl;
            game_running = false; // End the game if no winner
            break;
        }
    }
    while (true){
        // ask user to play again or not
        cout << "" << endl;
        cout << "Do you want to play again? (yes/no)" << endl;
        string choice;
        cin >> choice ;
        cout << "\n";
        if (choice == "yes"){
            scrabble_game();
            break;
        }
        else if (choice == "no"){
            cout << "Thank you for playing!" << endl;
            break;
        }
        else{
            cout << "Please enter a valid choice." << endl;
            continue;
        }

    }
}
int main() {
    scrabble_game();
    return 0;
}