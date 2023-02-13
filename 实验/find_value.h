#pragma once
#include<stdio.h>
int Find_Value(int** chessboard, int chess_long, int x, int y, int ai_side);
int Find_Sum_Value(int** chessboard, int chess_long, int ai_side);
void Change_Chessboard(int y, int x, int chess_type, int** chessboard_p);
void Test_Save( int* const p);
void Save_Value();
void Load_Value();
int Load_Value_for_1(int y, int x, int chess_type, int** chessboard_p);
int Load_Value_for_2(int y, int x, int chess_type, int** chessboard_p);

int Change_Side(int number);
bool Find_Win(int** chessboard, int chess_long, int x, int y, int side);
int Find_Value_Dir(int** chessboard, int chess_long, int x, int y, int ai_side);
int Find_Value_Dir_Unit(int** chessboard, int chess_long, int x, int y, int ai_side, int i, int j);
int Find_Value_Not_Skip(int** chessboard, int chess_long, int x, int y, int ai_side);
int Find_Value_Dir_Unit_test_for_1(int* chessboard, int chess_long, int x, int i);
int Find_Value_Dir_Unit_test_for_2(int* chessboard, int chess_long, int x, int i);
