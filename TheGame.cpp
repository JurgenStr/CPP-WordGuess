#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <ctime>
using namespace std;

int check = 0, n, hp = 8, att = 0, saved = 0, combo = 0, temp = 0;
string assign, nama;
char arr[100], strip[100], attempt[100], guess, mode = '0', category = '0', pass = '0';
bool finish = 1, cont = 1, confirm = false;

struct player {
	string name;
	int solved;
};

void match(char f, int n);
void attempts(char f);
void initiate();
void choose();
void input();
void the_game();
void continues();
void color();
void country();
void food();
void intro();
void sorting();

int main() {
	player plays[4];
	plays[0].name = "JOE";
	plays[1].name = "IVN";
	plays[2].name = "BOT";
	plays[3].name = "Unknown";
	plays[0].solved = 6;
	plays[1].solved = 2;
	plays[2].solved = 20;
	plays[3].solved = 0;
	
	cout << "===================================================" << endl;
	cout << "\t    Welcome to 'Guess the Word!'" << endl << endl;
	cout << "\t\t    Created by:" << endl;
	cout << "\t\t     JurgenStr" << endl << endl;
	cout << "\t     Press any key to continue..." << endl;
	cout << "===================================================" << endl;
	system("pause");
	system("cls");
	cout << "===================================================" << endl;
	cout << "\t     Hello! What's your name?" << endl;
	cout << "\t	3 characters needed." << endl;
	cout << "===================================================\t" << endl;
	while (nama.length() < 3 || nama.length() > 3) {
		getline(cin, nama);
		for (int i=0;i<nama.length();i++) {
			nama[i] = toupper(nama[i]);
		}
		plays[3].name = nama;
	}
	
	while (cont == 1) {
	plays[3].solved = temp;
	combo = 0;
	initiate();
		while (mode == '1') {
		input();
		the_game();
		continues();
	}
		while (mode == '2') {
		choose();
		while (category == '1') {
 			country();
		   	the_game();
		   	continues();
		}
		while (category == '2') {
			color();
			the_game();
			continues();
		}
   		while (category == '3') {
			food();
			the_game();
			continues();
		}
	}
	while (mode == '3') {
		intro();
		}
	while (mode == '4') {
		plays[3].solved = temp;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
			if(plays[i].solved > plays[j].solved){
				swap(plays[j],plays[i]);
			}
		}
	}
		cout << "===================================================" << endl;
		cout << "		   LEADERBOARD" << endl;
		cout << "===================================================" << endl;
		for (int i=0; i<4; i++) {
			cout << i+1 << ". " << plays[i].name << "\t\t\t\t" << plays[i].solved << endl;
		}
		cout << endl;
		mode = '0';
		system("pause");
		system("cls");
	}
	while (mode == '5') {
		system("cls");
		return 0;
	}
}}

// Algorithm to check match
void match (char f, int n) {
	system("cls");
	finish = 1;
	for (int i=0;i<n;i++) {
		if (toupper(f) == arr[i]) {
			strip[i] = toupper(f);
			saved = 1;
		}}
	if (att >= 1) {
		for (int i=0;i<att;i++) {
			if (toupper(f) == attempt[i]) {
				saved = 2;
			}}}
	if (saved == 0) {
		cout << "===================================================" << endl;
		cout << "\t\t   Oof, wrong!" << endl;
		--hp;
		attempts(f);} 
	if (saved == 1) {
		cout << "===================================================" << endl;
		cout << "\t\tYou got it right!" << endl;
		attempts(f);}
	if (saved == 2) {
		cout << "===================================================" << endl;
		cout << "\t\tYou've tried that before..." << endl;}
}

void attempts (char f) {
	attempt[att] = toupper(f);
	att++;}

void initiate() {
	while (mode != '1' && mode != '2' && mode != '3' && mode != '4' && mode != '5') {
	system("cls");
	cout << "===================================================" << endl;
	cout << "Player: " << nama << endl;
	cout << "===================================================" << endl;
	cout << "Choose mode:" << endl;
	cout << "1. Manual Input" << endl;
	cout << "2. Preset Words" << endl;
	cout << "3. How to Play" << endl;
	cout << "4. Leaderboard" << endl;
	cout << "5. Quit Game" << endl << endl;
	cout << "Enter number to choose: ";
	cin >> mode;
	cin.ignore();
	}
	system("cls");}
	
void choose() {
	while (category != '1' && category != '2' && category != '3'){
	system("cls");
	cout << "===================================================" << endl;
	cout << "		   PRESET MODE" << endl;
	cout << "===================================================" << endl;
	cout << "In this mode, you'll be given a mystery word." << endl;
	cout << "The goal is simple, guess the word." << endl;
	cout << "Each time you guessed the word, you'll get +2 HP." << endl << endl;
	cout << "Until now, you've completed " << combo << " rounds." << endl << endl;
	system("pause");
	system("cls");
	cout << "===================================================" << endl;
	cout << "		   PRESET MODE" << endl;
	cout << "===================================================" << endl;
	cout << "Health Points (Remaining Attempts): " << hp << endl << endl;
	cout << "Rounds completed: " << combo << endl << endl;
	cout << "Choose category:" << endl;
	cout << "1. Country" << endl;
	cout << "2. Color" << endl;
	cout << "3. Food" <<endl << endl;
	cout << "Enter '1' or '2' or '3' to choose: ";
	cin >> category;
	cin.ignore();
	}
	system("cls");}

void country() {
	string words[17] = {
	"indonesia", "inggris", "jepang", "malaysia", "thailand", "afrika selatan",
	"china", "singapura", "myanmar", "vietnam", "brazil",
	"argentina", "belanda", "jerman", "rusia",
	"honduras", "senegal"
	};
	srand(time(0));
	int r = (rand() % 16);
	assign = words[r];
	n = assign.size();
	for (int j = 0; j < n; j++) {
		assign[j] = toupper(assign[j]);
	}
	assign.copy(arr, assign.size() + 1);
	arr[n] = '\0';
	system("cls");}

void color() {
	string words[17] = {
	"merah", "hitam", "orange", "magenta", "violet", "perak",
	"kuning", "putih", "abu abu", "emas", "nila",
	"hijau", "ungu", "pink", "dongker",
	"biru", "coklat"
	};
	srand(time(0));
	int r = (rand() % 16);
	assign = words[r];
	n = assign.size();
	for (int j = 0; j < n; j++) {
		assign[j] = toupper(assign[j]);
	}
	assign.copy(arr, assign.size() + 1);
	arr[n] = '\0';
	system("cls");}

void food() {
	string words[17] = {
	"nasi goreng", "burger", "kentang goreng", "nugget", "risol", "nasi telur",
	"mie goreng", "pizza", "es kepal milo", "sosis", "tahu bakso crispy",
	"magelangan", "roti bakar", "bakwan kawi", "bakso",
	"ikan bakar", "ayam goreng"
	};
	srand(time(0));
	int r = (rand() % 16);
	assign = words[r];
	n = assign.size();
	for (int j = 0; j < n; j++) {
		assign[j] = toupper(assign[j]);
	}
	assign.copy(arr, assign.size() + 1);
	arr[n] = '\0';
	system("cls");}

void input() {
	cout << "===================================================" << endl;
	cout << "		   MANUAL MODE" << endl;
	cout << "===================================================" << endl;
	cout << "2 players needed." << endl;
	cout << "The first player will give the mystery word." << endl;
	cout << "The second player must guess the word with 8 HP." << endl << endl;
	system("pause");
	cout << endl << "Input the mystery word here: ";
	do {
		getline(cin, assign);
		n = assign.size();
		for (int j = 0; j < n; j++) {
			assign[j] = toupper(assign[j]);
		}
		assign.copy(arr, assign.size() + 1);
		arr[n] = '\0';
		check++;
	} while (check == 0);
	system("cls");}

void the_game() {
	// Game Start
	cout << "----------GAME READY----------" << endl;
	for (int i=0;i<n;i++) {
		strip[i] = '*';
		if (assign[i] == ' ') {
			strip[i] = assign[i]; }
	}
	system("pause");
	system("cls");
	while (pass == '0') {
		saved = 0;
		if (mode == '1') {
				cout << "===================================================" << endl;
				cout << "		   MANUAL MODE" << endl;
				cout << "===================================================" << endl;
		}
		if (mode == '2') {
				cout << "===================================================" << endl;
				cout << "		   PRESET MODE" << endl;
				cout << "===================================================" << endl;
		}
		cout << "Words: " << n << endl;
		cout << "HP: " << hp << endl << endl;
		for (int i=0;i<n;i++) {
			cout << strip[i];
		}
		cout << endl;
		cout << "Input attempts: ";
		if (att != 0) {
			for (int j = 0;j <= att; j++) {
			cout << attempt[j] << " ";
			}
		}
		cout << endl;
		do {
		cin >> guess;}
		while (! (( guess >= 'a' && guess <= 'z' ) || ( guess >= 'A' && guess <= 'Z' )) );
		cin.ignore();
		match(guess, n);
	// Checking if finished
		for (int i=0;i<n;i++) {
			if (strip[i] != arr[i]) {
				finish = 0;
				break;
			}
			if (i == (n-1) && finish == 1) {
				cout << endl << "\t\t     ";
				for (int j=0;j<n;j++) {
					cout << strip[j];
				}
				cout << "\n\n\t     Good job! You solved it!" << endl;
				cout << "===================================================\n\n";
				pass = '1';
				att++;
			}
	}
	if (hp <= 0) {
		system("cls");
		cout << "===================================================" << endl;
		cout << "GAME OVER" << endl << endl;
		cout << "The word was: " << endl;
		pass = '2';
		for (int i=0;i<n; i++) {
			cout << assign[i];
		}
		cout << "\n\n===================================================" << endl;
		cout << endl;
		}} system("pause");}

void continues() {
	system("cls");
	if (mode == '2' && pass == '1') {
		combo++;
		temp++;
		++hp; ++hp;
		confirm = true;
	}
	cout << "===========================================================" << endl;
	cout << "\t\t\tContinue?\n\n";
	cout << "      Press any key to continue, or press 'N' to stop." << endl;
	cout << "===========================================================" << endl;
	cin >> guess;
	cin.ignore();
	if (confirm) {
		if (guess == 'n' || guess == 'N') {
			pass = '0';
			for (int i=0;i<att;i++) {
			attempt[i] = ' ';}
			att = 0;
			category = '0';
			temp = combo;
			mode = '0';
			confirm = 0;
			//temp = combo;
			initiate();
	}}
	if (guess == 'n' || guess == 'N') {
		cont = false;}
	category = '0';
	if (confirm == 1) {
		pass = '0';
		confirm = 0;
		for (int i=0;i<att;i++) {
		attempt[i] = ' ';}
		att = 0;
		choose();
	}
	if (mode == '1' || pass == '2') {
		pass = '0';
		hp = 8;
		combo = 0;
		mode = '0';
	}
	if (mode == '2' && pass == '2') {
		pass = '0';
		hp = 8;
		temp = combo;
		mode = '0';
	}
	for (int i=0;i<att;i++) {
		attempt[i] = ' ';
	} 
	att = 0;
//	att = 0;
//	pass = '0';
//	category = '0';
	system("cls");
}

void intro() {
	cout << "=====================================================================" << endl;
	cout << "\t\tWelcome to Guess The Word!" << endl << endl;
	cout << "Your task is simple. Guess the mysterious word in each round!" << endl;
	cout << "You'll be given 8 HP (Health Points) in the beginning of the game." << endl;
	cout << "Every time you guessed the word, 2 HP will be added to your HP pool." << endl << endl;
	cout << "Press 'Enter' to go back..." << endl;
	cout << "=====================================================================" << endl;
	getchar();
	att = 0;
	mode = '0';
	category = '0';
	system("cls");
}

/*		do {
		cin >> guess;}
		while (! (( guess >= 'a' && guess <= 'z' ) || ( guess >= 'A' && guess <= 'Z' )) );
		cin.ignore(); */
