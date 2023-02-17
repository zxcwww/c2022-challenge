
#pragma once
#include"find_value.h"
struct pos_2D {
	int x,y;
};
void Find_Road(int** chessboard, int* sub_arr, int chess_long, int ai_side, bool is_max_side, int deep_of_tree, int extent_limit) 	;
bool Check_Win(int value);
void Sort_Arr_With_Need(int* arr, int* sub_arr, int arr_length, int need);
int Find_Value_Totle(int** chessboard, int chess_long, int x, int y, int ai_side, int type, int deep_of_tree);
pos_2D Find_Action(int** chessboard, int chess_long, int ai_side, bool& is_start, int which_ai, pos_2D last_pos);
int Limit(int input, int min_limit, int max_limit);
void Alpha_Beta_Tree_Dir_Roll_Seach_Unit(int** chessboard, int chess_long, int ai_side, int deep_of_tree, bool is_max_side, int& max_now, int& min_now, pos_2D last_pos, int y, int x, bool& need_retun);

pos_2D Alpha_Beta_Tree_Extent_Limit_Seach_Control(int** chessboard, int chess_long, int ai_side, int deep_of_tree, int extent_limit, pos_2D last_pos);
void Alpha_Beta_Tree_Extent_Limit_Check_Value_Unit_Control(int** chessboard, int chess_long, int ai_side, int deep_of_tree, int extent_limit, int& max_now, pos_2D last_pos, pos_2D& pos, int x, int y);
int Alpha_Beta_Tree_Dir_Extent_Limit(int** chessboard, int chess_long, int ai_side, int deep_of_tree, int extent_limit, bool is_max_side, int now_value, pos_2D last_pos);
void Alpha_Beta_Tree_Dir_Extent_Limit_Unit(int** chessboard, int chess_long, int ai_side, int deep_of_tree, int extent_limit, bool is_max_side, int& max_now, int& min_now, pos_2D last_pos, int y, int x, bool& need_retun);