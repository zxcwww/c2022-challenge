#pragma once
#include<stdio.h>
void Change_Chessboard(int y, int x, int chess_type, int** chessboard_p);
void Test_Save( int* const p);
void Save_Value();
void Load_Value();
int Load_Value_for_1(int y, int x, int chess_type, int** chessboard_p);
int Load_Value_for_2(int y, int x, int chess_type, int** chessboard_p);

int Change_Side(int number);
bool Find_Win(int** chessboard, int chess_long, int x, int y, int side);
int Find_Value_Dir_Unit_test_for_1(int* chessboard, int chess_long, int x, int i);
int Find_Value_Dir_Unit_test_for_2(int* chessboard, int chess_long, int x, int i);
