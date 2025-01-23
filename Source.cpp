#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <stdio.h>
using namespace std;
/*Game Plan:
each game starts off showing user's balance
$2 min bet $100 max per bet

dealer rolls dice 3 times last is the roll

user auto rolls dice has to be higher than dealer's
if win double amt bet
if lose take money bet

game ends when a -1 bet is placed, outputs 
*/
int balance = 10;

class Dice {
public:
	vector<int> sides;
	Dice() { sides = { 2,3,4,5,6,7,8,9,10,11,12 }; };
	//int rolldice();
};

int rollDice() {
	srand(time(NULL));
	int i = rand() % 11 + 2;
	return i;
}


void getBalance() {
	cout << "Current balance is: " << balance << endl;
}
void playGame(char move) {
	int bet, dealer_roll, user_roll;
	char c =move;
	while (balance > 2 && c!='q') {
		if (c == 'p') {
			cout << "How much are you willing to bet (min: 2, max: 100): ";
			std::cin >> bet;
			if (bet > balance) {
				cout << "Cannot bet more than balance. " << endl;
				bet = 0;
			}
			while (bet < 2 || bet > 100) { cout << "You\'re not playing this round then." << endl; bet = 0; break; }
			if (bet != 0) {
				//play game normally
				for (int i = 0; i < 3; i++) { dealer_roll = rollDice(); }
				cout << "Dealer\'s roll: " << dealer_roll << endl;
				user_roll = rollDice();
				if (user_roll > dealer_roll) {
					cout << "Winner! With: " << user_roll << endl;
					bet *= 2;
					balance += bet;
					cout << "Balance now: " << balance << endl;
				}
				else {
					cout << "Lost with " << user_roll << endl;
					balance -= bet;
					cout << "Balance now: " << balance << endl;
				}
			}
			else {
				cout << "-------------Out this round--------------" << endl;
				for (int i = 0; i < 3; i++) { dealer_roll = rollDice(); }
				cout << "Dealer\'s roll: " << dealer_roll << endl;
				user_roll = rollDice();
				cout << "----User\'s roll: " << user_roll << endl;

			}
		}
		else if (c == 's') {
			//play game without user
			cout << "-------------Out this round--------------" << endl;
			for (int i = 0; i < 3; i++) { dealer_roll = rollDice(); }
			cout << "Dealer\'s roll: " << dealer_roll << endl;
			cout << "----User\'s roll: " << user_roll << endl;
		}
		else if (c == 'b') { getBalance(); }

		cout << "Wanna keep playing?: (\'q\' quit, \'p\' play, \'b\' balance, \'s\' skip_turn) ";
		std::cin >> c;
		if (c == 'q') break;
	}
}
/*
void playGame() {
	int bet, dealer_roll, user_roll;
	char c ='a';
	while (balance > 2 && c!='q') {
		cout << "How much are you willing to bet (min: 2, max: 100): ";
		std::cin >> bet;
		if (bet > balance) {
			cout << "Cannot bet more than balance. " << endl;
			bet = 0;
		}
		while (bet < 2 || bet > 100) { cout << "You\'re not playing this round then." << endl; bet = 0; break; }
		if (bet != 0) {
			//play game normally
			for (int i = 0; i < 3; i++) { dealer_roll = rollDice(); }
			cout << "Dealer\'s roll: " << dealer_roll << endl;
			user_roll = rollDice();
			if (user_roll > dealer_roll) {
				cout << "Winner! With: " << user_roll << endl;
				bet *= 2;
				balance += bet;
				cout << "Balance now: " << balance << endl;
			}
			else {
				cout << "Lost with " << user_roll << endl;
				balance -= bet;
				cout << "Balance now: " << balance << endl;
			}
		}
		else if(c=='s'){
			//play game without user
			cout << "-------------Out this round--------------" << endl;
			for (int i = 0; i < 3; i++) { dealer_roll = rollDice(); }
			cout << "Dealer\'s roll: " << dealer_roll << endl;
		}


		cout << "Wanna keep playing?: (\'q\' quit, \'p\' play, \'b\' balance, \'s\' skip_turn) ";
		std::cin >> c;
	}
}
*/

int main() {
	cout << "Hello! Let\'s play" << endl;
	char c;
	int bet;
	int dealer_roll;
	int user_roll, rando_roll;
	cout << "Enter a command: (\'q\' quit, \'p\' play, \'b\' balance) ";
	cin >> c;
	while (c != 'q') {
		if (c == 'p') {
			playGame(c);
		}
		else if (c == 'b') {
			getBalance();
		}
		cout << "Enter a command: (\'q\' quit, \'p\' play, \'b\' balance) ";
		cin >> c;
	}
	return 0;
	}