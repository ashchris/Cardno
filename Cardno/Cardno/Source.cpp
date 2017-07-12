/*Cardno (Project Interdriver)
Development started on 7/12/17
Created by Asher Collier/Pixel for iD Tech
Made on Microsoft Visual Studio 2015
On Windows 10 OS
exe is 32-bit*/
#include <iostream>
#include <string>
#include <random>
#include "error.h"

//Mod this comment for errors

using namespace std;

//Initialize wilo w/ bool cha
void wilo(bool cha);
//Initialize menu
bool menu();

void help();

bool menu() {
	//Ignore all of this; it's not worth your time.
	string menu_inp;
	cout << "Welcome to Version 0.3.7 of Cardno!" << endl;
	cout << "Would you like to:" << endl;
	cout << "(S)tart a new game, or:" << endl;
	cout << "(E)xit?" << endl;
	cin >> menu_inp;

	if (menu_inp == "s" || menu_inp == "S") {
		return false;
	}
	else if (menu_inp == "e" || menu_inp == "E") {
		string ex_qi;

		cout << "Are you sure? (y/n) (n will start a new game)" << endl;
		cin >> ex_qi;

		if (ex_qi == "y" || ex_qi == "Y") {
			return true;
		}
		else {
			return false;
		}
	}
}

void help() {

}

int main() {
	//Initialize exit bool
	bool exgm;

	exgm = menu();

	if (exgm == true) {
		return 0;
	}

	//Initialize vars
	int p_cards[5];
	int e_cards[5];
	int p_choose;
	int e_choose;
	int rang = 0;
	bool lose = false;
	int rand_add;
	int rand_match;
	int rand_card;
	int chs;

	//For loops for generating cards
	for (int i = 0/*Apparrently I can't have a garbage var although I believe it's completely legal*/; i < 5; i++) {
		random_device rang;
		uniform_int_distribution<int> rgn(1, 13);
		p_cards[i] = rgn(rang);
	}

	for (int g = 0; g < 5; g++) {
		random_device rang;
		uniform_int_distribution<int> rgn(1, 13);
		e_cards[g] = rgn(rang);
	}

	bool loopg = true;

	//Set up loop
	while (loopg) {
		//Randomize card add tournaments
		rand_add = rand() % 20 + 1;
		rand_match = rand() % 20 + 1;
		
		if (rand_add == rand_match) {
			//When a wild card appears
			rand_card = rand() % 13 + 1;
			
			cout << "A wild " << rand_card << "has appeared!" << endl;
			cout << "Which card would you like to battle with?" << endl;
			cout << "1: " << p_cards[0] << "  2: " << p_cards[1] << "  3: " << p_cards[2] << "  4: " << p_cards[3] << "  5: " << p_cards[4] << endl;
			cin >> p_choose;

			if (p_choose < 1 || p_choose > 5) {
				cout << "Wow! Your input is so invalid that nobody got the card!\nI can't believe that that's even possible!" << endl;
				continue;
			}

			chs = rand() % 5 + 1;

			cout << chs << " VS " << p_choose;

			if (chs > p_choose) {
				e_cards[chs] = rand_card;
				cout << "Your opponent takes the card!" << endl;
			}
			else if (chs < p_choose) {
				p_cards[p_choose] = rand_card;
				cout << "You take the card!" << endl;
			}
			else if (chs == p_choose) {
				e_cards[chs] = rand_card;
				cout << "Your opponent breaks the deal! He takes the card!" << endl;
			}
			else {
				string er_wild = "Something is happening with chs and p_choose";
				error_rep(er_wild);
			}
		}

		cout << "Your cards:" << endl;
		cout << "1: " << p_cards[0] << "  2: " << p_cards[1] << "  3: " << p_cards[2] << "  4: " << p_cards[3] << "  5: " << p_cards[4] << endl;
		cout << "--------------" << endl;
		cout << "Your opponent's cards:" << endl;
		cout << "1: " << e_cards[0] << "  2: " << e_cards[1] << "  3: " << e_cards[2] << "  4: " << e_cards[3] << "  5: " << e_cards[4] << endl;
		cout << "--------------" << endl;

		if (p_cards[0] == p_cards[2] - 2 && p_cards[4] == p_cards[2] - 2 && p_cards[1] == p_cards[2] - 1 && p_cards[3] == p_cards[2] - 1) {
			lose = false;
			loopg = false;
		}
		else if (e_cards[0] == e_cards[2] - 2 && e_cards[4] == e_cards[2] - 2 && e_cards[1] == e_cards[2] - 1 && e_cards[3] == e_cards[2] - 1) {
			lose = true;
			loopg = false;
		}

		cout << "Choose your choice of your choosing: ";

		cin >> p_choose;

		if (p_choose < 1 || p_choose > 5) {
			cout << "I could not understand. Please try again." << endl;
			cout << "-----------------------------------------" << endl;
			continue;
		}

		p_choose -= 1;

		//Process choice			
		string choose;

		//Do everything in this case (don't want this prototype to have the same fate as TVGVGGTVG)
		cout << "Your opponent is choosing his card." << endl;
		chs = rand() % 4 + 0;
		e_choose = chs;
		cout << "Your opponent chose: Card number " << e_choose << ", which is the card: " << e_cards[e_choose] << "." << endl;
		cout << "Do you wish to trade? (y/n) ";
		
		cin >> choose;	
		if (choose == "y" || choose == "Y") {
			int card_ol = e_cards[e_choose - 1];
			e_cards[e_choose] = p_cards[p_choose - 1];
			p_cards[p_choose] = card_ol;
		}
			
		else if (choose == "n" || choose == "N") {
			cout << "That's a shame. You could've gotten an amazing deal." << endl;
		}
		else {
			cout << "I couldn't recognize your input. Please try selecting your card again." << endl;
			cout << "----------------------------------------------------------------------" << endl;
		}
	}

	//Send lose bool to wilo
	wilo(lose);

	return 0;
}

void wilo(bool cha) {
	if (cha == false) {
		string winpause;
		cout << "Congratulations!" << endl;
		cout << "You have beaten one of the best terminal-based card games!\nYou sure are a genius!" << endl;
		cout << "Created by Asher Collier and Pixel for iD Tech Camps\nCreated on Microsoft Visual Studio 2015\n";
		cout << "Press enter to continue. . .";
		cin >> winpause;
	}
	else if (cha == true) {
		string losepause;
		cout << "Well, looks like your opponent beat you to it. Oh well.\n";
		cout << "Press enter to continue. . .";
		cin >> losepause;
	}
}