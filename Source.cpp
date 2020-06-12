#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>

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

bool check_enemy_position(string** field, string checker, int row, int column) {
	string enemy_checker, enemy_king;
	row -= 1;
	column -= 1;
	if (checker == WHITE || checker == KING_WHITE) {
		enemy_checker = BLACK;
		enemy_king = KING_BLACK;
	}
	else {
		enemy_checker = WHITE;
		enemy_king = KING_WHITE;
	}
	if (field[row][column] == enemy_checker || field[row][column] == enemy_king)
		return true;
	return false;
}

void move(string** field, string checker, int row, int next_row, int column, int next_column) {
	if (checker != KING_WHITE || checker != KING_BLACK) {
		while (1) {
			if (!(abs(row - next_row) <= 2 && abs(column - next_column) <= 2)) {
				if (!check_enemy_position(field, checker, next_row, next_column)) {
					cout << "Try again" << endl;
					cin >> next_row >> next_column;
					next_column -= 1;
					next_row -= 1;
				}
			}
			else
				break;
		}
		if (field[next_row][next_column] == EMPTY) {
			field[row][column] = EMPTY;
			field[next_row][next_column] = checker;
		}
	}
	else {
		while (1) {

		}
	}
}

void run(string** field) {
	show_field(field);
	int row, column, next_row, next_column;
	cout << "Choose your fighter" << endl;
	cin >> row >> column;
	while (row > SIZE && column > SIZE) {
		cout << "Try again" << endl;
		cin >> row >> column;
	}
	cout << "Choose next position" << endl;
	cin >> next_row >> next_column;
	row -= 1;
	column -= 1;
	next_row -= 1;
	next_column -= 1;
	string checker = field[row][column];

	while (1) {
		if (!check_enemy_position(field, checker, next_row, next_column)) {
			cout << "Try again"
		}
	}

}

bool out(string** field, string name) {
	int counter_white = 0, counter_black = 0;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (field[i][j] == WHITE || field[i][j] == KING_WHITE) {
				counter_white += 1;
			}
			if (field[i][j] == BLACK || field[i][j] == KING_BLACK) {
				counter_black += 1;
			}
		}
	}

	if (counter_white == 0) {
		cout << name << " win!";
		return true;
	}
	if (counter_black == 0) {
		cout << name << " win!";
		return true;
	}

	return false;
}

int main() {
	string** field = new string*[SIZE];
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			field[i] = new string[SIZE];
		}
	}

	starting_field(field);

	string player_white, player_black;
	cout << "Player of white checkers" << endl;
	cin >> player_white;

	cout << "Player of black checkers" << endl;
	cin >> player_black;

	while (1) {
		run(field);
		if (out(field, player_white)) {
			return 0;
		}
		run(field);
		if (out(field, player_black)) {
			return 0;
		}
	}

	return 0;
}