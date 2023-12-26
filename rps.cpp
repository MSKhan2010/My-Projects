#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const char* play();
bool is_win(int player, int opponent);

const char* play() {
    srand(static_cast<unsigned int>(time(NULL)));

    int user;

    cout << "Enter user choice rock(1) paper(2) scissors(3): \n";
    cin >> user;

    int computer_choice = rand() % 3 + 1; // Ensuring range of 1-3

    if (computer_choice == user) {
        return "tie";
    }

    if (is_win(user, computer_choice)) {
        return "you won";
    }
    return "you lost";
}

bool is_win(int player, int opponent) {
    if ((player == 1 && opponent == 2) || (player == 2 && opponent == 3) || (player == 3 && opponent == 1)) {
        return true;
    }
    return false;
}

int main() {
    while (true) {
        const char* result = play();
        cout << result << endl;
    }

    return 0;
}
