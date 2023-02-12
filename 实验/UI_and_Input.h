
#pragma once
#include<string>

void Show_Arrow_2D(int** arrow_2D, int chess_long);
bool Is_Input();
pos_2D Get_Mouse_Input(int chess_long);
void Add_Chess(int x, int y, int side, int chess_long);
void Number_To_String(int number, TCHAR* tc);