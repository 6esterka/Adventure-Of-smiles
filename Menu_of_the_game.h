#pragma once
using namespace std;
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"Level1.h"
FILE *fb;

bool menuActive = true;
bool level_menu = false;
bool exit_button = false;
bool level_1 = false;
bool level_2 = false;
bool level_3 = false;

int cursor_pos = 0;

enum Lines {
	Horizontal_Line = 205,
	Vertical_Line = 186,
	First_Corner = 201,
	Second_Corner = 187,
	Third_Corner = 188,
	Forth_Corner = 200,
	Empty_symbol = 0
};
void Print_menu_parts(int symbol_begin, int symbol_center, int symbol_end) {
	cout << (char)symbol_begin;
	for (int i = 0; i < 22; ++i) {
		cout << (char)symbol_center;
	}
	cout << (char)symbol_end << endl;
}

void Draw_menu() {
	Print_menu_parts(First_Corner, Horizontal_Line, Second_Corner);
	Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	cout << (char)Vertical_Line << "  Adventure of Smile  " << (char)Vertical_Line << endl;
	//Calling 2 times of function
	Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	cout << (char)Vertical_Line << "Game by casper_bool   " << (char)Vertical_Line<<endl;
	Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	cout << (char)Vertical_Line << "Music Pygmalion_m     " << (char)Vertical_Line << endl;
	for (int i = 0; i < 3; i++) {
		Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	cout << (char)Vertical_Line << "      Start Game      " << (char)Vertical_Line << endl;
	if (cursor_pos == 0) {
		cout << (char)Vertical_Line << "      ----------      " << (char)Vertical_Line << endl;
	}
	else {
		Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	cout << (char)Vertical_Line << "      High Score      " << (char)Vertical_Line << endl;
	if (cursor_pos == 2) {
		cout << (char)Vertical_Line << "      ----------      " << (char)Vertical_Line << endl;
	}
	else {
		Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	cout << (char)Vertical_Line << "         Exit         " << (char)Vertical_Line << endl;
	if (cursor_pos == 4) {
		cout << (char)Vertical_Line << "         ----         " << (char)Vertical_Line << endl;
	}
	else {
		Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	Print_menu_parts(Forth_Corner, Horizontal_Line, Third_Corner);
}

void Draw_Level_menu() {
	Print_menu_parts(First_Corner, Horizontal_Line, Second_Corner);
	Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	cout << (char)Vertical_Line << "  Adventure of Smile  " << (char)Vertical_Line << endl;
	//Calling 3 times of function
	for (int i = 0; i < 3; i++) {
		Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	cout << (char)Vertical_Line << "      Level 1         " << (char)Vertical_Line << endl;
	if (cursor_pos == 0) {
		cout << (char)Vertical_Line << "      -------         " << (char)Vertical_Line << endl;
	}
	else {
		Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	cout << (char)Vertical_Line << "      Level 2         " << (char)Vertical_Line << endl;
	if (cursor_pos == 2) {
		cout << (char)Vertical_Line << "      -------         " << (char)Vertical_Line << endl;
	}
	else {
		Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	cout << (char)Vertical_Line << "      Level 3         " << (char)Vertical_Line << endl;
	if (cursor_pos == 4) {
		cout << (char)Vertical_Line << "      -------         " << (char)Vertical_Line << endl;
	}
	else {
		Print_menu_parts(Vertical_Line, Empty_symbol, Vertical_Line);
	}
	Print_menu_parts(Forth_Corner, Horizontal_Line, Third_Corner);
}

void hide_cursor() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}




void Move_Cursor() {
	char inputCharMenu = _getch();
	inputCharMenu = tolower(inputCharMenu);
	switch (inputCharMenu) {
		//UP
	case 'w':
		if (cursor_pos > 0) {
			cursor_pos -= 2;
		}
		break;
		//DOWN
	case 's':
		if (cursor_pos < 4) {
			cursor_pos += 2;
		}
		break;
		//Enter (Going to the levels menu or Select the level)
	case 13:
		if (level_menu == false) {
			if (cursor_pos == 0) {
				menuActive = false;
				level_menu = true;
			}
			else if (cursor_pos == 2) {
				//open highscore.bin file for viewing
				FILE *file = nullptr;
				const int rank_num = 10;
				int rank_list[rank_num]{};
				fopen_s(&file,"highscore.bin","rb");
				fread_s(rank_list,sizeof(int)*rank_num, sizeof(int), 10*sizeof(int), file);
				for (int i = 0; i < rank_num; ++i) {
					cout << i+1 << "." << rank_list[i]<<endl;
				}
				fclose(file);
				system("pause");
			}
			else if (cursor_pos == 4) {
				menuActive = false;
				exit_button = true;
			}
			break;
		}
		else if (level_menu == true) {
			if (cursor_pos == 0) {
				level_1 = true;
				level_menu = false;

			}
			else if (cursor_pos == 2) {
				level_2 = true;
				level_menu = false;
				const int final_row = 1;
				const int final_col = 2;
			}
			else if (cursor_pos == 4) {
				level_3 = true;
				level_menu = false;
			}
		}
	}
}