#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int user_guess(int x) {
    srand(static_cast<unsigned int>(time(NULL)));
    
    int random_number = rand() % x + 1;
    int guessed_number = 0;

    while (guessed_number != random_number) {
        cout << "Guess a number between 1 and " << x << ": ";
        cin >> guessed_number;
        cout << guessed_number << endl;

        if (guessed_number > random_number) {
            cout << "too high... try again." << endl;
        } else if (guessed_number < random_number) {
            cout << "too low... try again." << endl;
        } else if (guessed_number == random_number) {
            cout << "congrats you win!" << endl;
        }
    }

    return 0;
}

int computer_guess(int x){
    int low = 1;
    int high = x;
    char feedback = '\0';

    while(feedback != 'C'){
        int guess = (low + high) / 2;
        cout << "Is " << guess << " too high (H) too low (L) or correct(C)? ";
        cin >> feedback;

        if(feedback == 'H'){
            high = guess - 1;
        } else if(feedback == 'L'){
            low = guess + 1;
        } else if(feedback == 'C'){
            cout << "Well done you have guessed correctly " << guess << endl;
        } else {
            cout << "Invalid input. Please enter H, L, or C." << endl;
        }
    }
    return 0;
}

int main() {
    user_guess(10);
    computer_guess(100);
    return 0;
}
