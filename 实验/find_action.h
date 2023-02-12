
#pragma once
#include"find_value.h"
struct pos_2D {
	int x,y;
};
int Find_Value_Totle(int** chessboard, int chess_long, int x, int y, int ai_side, int type);
pos_2D Find_Action(int** chessboard, int chess_long,  int ai_side,bool &is_start, int which_ai, pos_2D last_pos);
pos_2D Alpha_Beta_Tree_Control(int** chessboard, int chess_long, int ai_side, int which_ai, int deep_of_tree);
int Alpha_Beta_Tree(int** chessboard, int chess_long, int ai_side, int which_ai, int deep_of_tree, bool is_max_side, int now_value);
int Alpha_Beta_Tree_Dir(int** chessboard, int chess_long, int ai_side, int deep_of_tree, bool is_max_side, int now_value);
pos_2D Alpha_Beta_Tree_Dir_Control(int** chessboard, int chess_long, int ai_side, int deep_of_tree);
pos_2D Alpha_Beta_Tree_Dir_Roll_Seach_Control(int** chessboard, int chess_long, int ai_side, int deep_of_tree, pos_2D last_pos);
void Alpha_Beta_Tree_Check_Value_Unit_Control(int** chessboard, int chess_long, int ai_side, int deep_of_tree, int& max_now, pos_2D last_pos, pos_2D& pos, int x, int y);
int Limit(int input, int min_limit, int max_limit);
void Alpha_Beta_Tree_Dir_Roll_Seach_Unit(int** chessboard, int chess_long, int ai_side, int deep_of_tree, bool is_max_side, int& max_now, int& min_now, pos_2D last_pos, int i, int j, bool& need_retun);
int Alpha_Beta_Tree_Dir_Roll_Seach(int** chessboard, int chess_long, int ai_side, int deep_of_tree, bool is_max_side, int now_value, pos_2D last_pos);
