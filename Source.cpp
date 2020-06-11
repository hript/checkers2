#include <iostream>
#include <string>
#include <Windows.h>

#define SIZE 8
#define WHITE "Wh"
#define BLACK "Bl"
#define KING_WHITE "kWh"
#define KING_BLACK "kBl"
#define EMPTY "-"

using namespace std;

void show_field(string** field) {
	system("cls");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << field[i][j];
		}
		cout << endl;
	}
}

void starting_field(string** field) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			field[i][j] = EMPTY;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				field[i][j] = WHITE;
			}
			if (i % 2 != 0 && j % 2 != 0) {
				field[i][j] = WHITE;
			}
		}
	}

	for (int i = 5; i < 8; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i % 2 != 0 && j % 2 == 0){
				field[i][j] = BLACK;
			}
			if (i % 2 == 0 && j % 2 != 0) {
				field[i][j] = BLACK;
			}
		}
	}
}

void run(string** field, string name) {
	show_field(field);
	int row, column;
	cin >> row >> column;
	row -= 1;
	column -= 1;




}

int main() {
	string** field = new string*[SIZE];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			field[i] = new string[SIZE];
		}
	}

	starting_field(field);

	int player_white, player_black;
	cout << "Player of white checkers" << endl;
	cin >> player_white;

	cout << "Player of black checkers" << endl;
	cin >> player_black;



	return 0;
}