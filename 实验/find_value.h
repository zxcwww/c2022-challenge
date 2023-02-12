#pragma once
int Find_Value(int** chessboard, int chess_long, int x, int y, int ai_side);
int Find_Sum_Value(int** chessboard, int chess_long, int ai_side);

int Change_Side(int number);
bool Find_Win(int** chessboard, int chess_long, int x, int y, int side);
int Find_Value_Dir(int** chessboard, int chess_long, int x, int y, int ai_side);
int Find_Value_Not_Skip(int** chessboard, int chess_long, int x, int y, int ai_side);
