#include"find_action.h"



pos_2D Find_Action(int** chessboard, int chess_long, int ai_side,bool &is_start,int which_ai,pos_2D last_pos) {
	
	if (is_start)
	{
		is_start = false;
		pos_2D pos;
		pos.x = pos.y=chess_long / 2;
		return pos;
	}

	switch (which_ai) {
	case 13:
		return Alpha_Beta_Tree_Dir_Roll_Seach_Control(chessboard, chess_long, ai_side, 1, last_pos);
	case 14:
		return Alpha_Beta_Tree_Dir_Roll_Seach_Control(chessboard, chess_long, ai_side, 2, last_pos);
	case 15:
		return Alpha_Beta_Tree_Dir_Roll_Seach_Control(chessboard, chess_long, ai_side, 3, last_pos);
	default:
		return Alpha_Beta_Tree_Dir_Roll_Seach_Control(chessboard, chess_long, ai_side, 1, last_pos);

	}

	
}

pos_2D Alpha_Beta_Tree_Dir_Roll_Seach_Control(int** chessboard, int chess_long, int ai_side, int deep_of_tree,pos_2D last_pos) {
	pos_2D pos;
	const int MAX = 1000000000, MIN = -1000000000;
	int max_now = MIN, min_now = MAX;
	
	for (int limit = 1;;limit++) {

		if (last_pos.y - limit<0 && last_pos.x + limit > chess_long-1 && last_pos.y + limit > chess_long-1 && last_pos.x - limit < 0) {
			break;
		}
		//up
		if (last_pos.y - limit >= 0) {
			
			for (int i = last_pos.y - limit,
				j = Limit(last_pos.x - limit, 0, chess_long-1);
				j < Limit(last_pos.x + limit, 0, chess_long);
				j++)
			{
				Alpha_Beta_Tree_Check_Value_Unit_Control(chessboard, chess_long,  ai_side,  deep_of_tree,
					 max_now,  last_pos,   pos,  j,  i);
				
			}
		}
		
		//right
		if (last_pos.x + limit <=chess_long-1) {

			for (int i = Limit(last_pos.y - limit, 0, chess_long-1),
				j = last_pos.x + limit;
				i < Limit(last_pos.y + limit, 0, chess_long);
				i++)
			{
				Alpha_Beta_Tree_Check_Value_Unit_Control(chessboard, chess_long, ai_side, deep_of_tree,
					max_now, last_pos, pos, j, i);
			}
		}

		//down
		if (last_pos.y + limit <=chess_long-1) {

			for (int i = last_pos.y + limit, 
				j = Limit(last_pos.x + limit, 0, chess_long-1); 
				j > Limit(last_pos.x - limit, -1, chess_long-1); j--)
			{
				Alpha_Beta_Tree_Check_Value_Unit_Control(chessboard, chess_long, ai_side, deep_of_tree,
					max_now, last_pos, pos, j, i);
			}

		}

		//left
		if (last_pos.x - limit >=0) {

			for (int i = Limit(last_pos.y + limit, 0, chess_long-1),
				j = last_pos.x - limit;
				i > Limit(last_pos.y - limit, -1, chess_long-1); i--)
			{
				Alpha_Beta_Tree_Check_Value_Unit_Control(chessboard, chess_long, ai_side, deep_of_tree,
					max_now, last_pos, pos, j, i);
			}

		}

	}


	return pos;
}

void Alpha_Beta_Tree_Check_Value_Unit_Control(int** chessboard, int chess_long, int ai_side, int deep_of_tree, int& max_now, pos_2D last_pos, pos_2D& pos, int x, int y) {
	if (chessboard[y][x] == 0) {

		int value_here = Find_Value_Totle(chessboard, chess_long, x, y, ai_side, 6);
		Change_Chessboard(y, x, ai_side, chessboard);
		int value =
			Alpha_Beta_Tree_Dir_Roll_Seach
			(chessboard, chess_long, ai_side, deep_of_tree - 1, false,
				max_now - value_here, last_pos);
		value += value_here;
		Change_Chessboard(y, x, 0, chessboard);
		if (value > max_now) {
			max_now = value;
			pos.x = x;
			pos.y = y;

		}

	}
}

int Alpha_Beta_Tree_Dir_Roll_Seach(int** chessboard, int chess_long, int ai_side, int deep_of_tree, bool is_max_side, int now_value,pos_2D last_pos) {
	const int MAX = 1000000000, MIN = -1000000000;

	int max_now = MIN, min_now = MAX;

	//当前层级结论的最大，最小值

	//这一个节点是求最大的，上一个节点是求最小的，若该节点的子节点中有超过最小的，该节点也会超，该节点会无效，终止遍历
	if (is_max_side) {
		min_now = now_value;

	}
	//这一个节点是求最小的，上一个节点是求最大的，若该节点的子节点中有小过最小的，该节点也会小过最小，该节点会无效，终止遍历
	else {
		max_now = now_value;

	}


	for (int limit = 1;; limit++) {

		if (last_pos.y - limit<0 && last_pos.x + limit > chess_long - 1 && last_pos.y + limit > chess_long - 1 && last_pos.x - limit < 0) {
			break;
		}
		//up
		if (last_pos.y - limit >= 0) {

			for (int i = last_pos.y - limit,
				j = Limit(last_pos.x - limit, 0, chess_long - 1);
				j < Limit(last_pos.x + limit, 0, chess_long - 1);
				j++)
			{

				bool need_return=false;
				Alpha_Beta_Tree_Dir_Roll_Seach_Unit(chessboard, chess_long, ai_side,
					deep_of_tree, is_max_side, max_now, min_now, last_pos, i, j, need_return);
				if (need_return)
					return is_max_side ? min_now : max_now;
			}
		}

		//right
		if (last_pos.x + limit <= chess_long - 1) {

			for (int i = Limit(last_pos.y - limit, 0, chess_long - 1),
				j = last_pos.x + limit;
				i < Limit(last_pos.y + limit, 0, chess_long - 1);
				i++)
			{
				bool need_return = false;
				Alpha_Beta_Tree_Dir_Roll_Seach_Unit(chessboard, chess_long, ai_side,
					deep_of_tree, is_max_side, max_now, min_now, last_pos, i, j, need_return);
				if (need_return)
					return is_max_side ? min_now : max_now;
			}
		}

		//down
		if (last_pos.y + limit <= chess_long - 1) {

			for (int i = last_pos.y + limit, j = Limit(last_pos.x + limit, 0, chess_long - 1); j > Limit(last_pos.x - limit, 0, chess_long - 1); j--)
			{
				bool need_return = false;
				Alpha_Beta_Tree_Dir_Roll_Seach_Unit(chessboard, chess_long, ai_side,
					deep_of_tree, is_max_side, max_now, min_now, last_pos, i, j, need_return);
				if (need_return)
					return is_max_side ? min_now : max_now;
			}

		}

		//left
		if (last_pos.x - limit >= 0) {

			for (int i = Limit(last_pos.y + limit, 0, chess_long - 1), j = last_pos.x - limit; i > Limit(last_pos.y - limit, 0, chess_long - 1); i--)
			{
				bool need_return = false;
				Alpha_Beta_Tree_Dir_Roll_Seach_Unit(chessboard, chess_long, ai_side,
					deep_of_tree, is_max_side, max_now, min_now, last_pos, i, j, need_return);
				if (need_return)
					return is_max_side ? min_now : max_now;
			}

		}

	}

	return is_max_side ? max_now : min_now;

}




void Alpha_Beta_Tree_Dir_Roll_Seach_Unit(int** chessboard, int chess_long, int ai_side, int deep_of_tree, bool is_max_side, int& max_now, int &min_now, pos_2D last_pos, int i, int j,bool &need_retun) {
	
	if (deep_of_tree == 0) {
		if (is_max_side) {
			
			if (chessboard[i][j] == 0) {
				int value = Find_Value_Totle(chessboard, chess_long, j, i, ai_side, 6);
				if (value > max_now) {
					max_now = value;

					if (min_now <= max_now) {
						need_retun = true;
					}
				}

			}

		}
		else {
			if (chessboard[i][j] == 0) {

				int value = Find_Value_Totle(chessboard, chess_long, j, i, ai_side, 7);

				if (value < min_now) {
					min_now = value;

					if (min_now <= max_now) {
						need_retun = true;
					}
				}

			}
		}

	}
	else {
		if (is_max_side) {

			if (chessboard[i][j] == 0) {


				int value_here = Find_Value_Totle(chessboard, chess_long, j, i, ai_side, 6);

				Change_Chessboard(i, j, ai_side, chessboard);

				int value =
					Alpha_Beta_Tree_Dir_Roll_Seach
					(chessboard, chess_long, ai_side, deep_of_tree - 1, false,
						max_now - value_here, last_pos);
				value += value_here;
				Change_Chessboard(i, j, 0, chessboard);

				if (value > max_now) {
					max_now = value;

					if (min_now <= max_now) {
						need_retun = true;
					}
				}

			}

		}

		else {

			if (chessboard[i][j] == 0) {
				int value_here = Find_Value_Totle(chessboard, chess_long, j, i, ai_side, 7);
				Change_Chessboard(i, j,3- ai_side, chessboard);


				int value =
					Alpha_Beta_Tree_Dir_Roll_Seach
					(chessboard, chess_long, ai_side, deep_of_tree - 1, true,
						min_now - value_here,last_pos);//mark
				value += value_here;

				Change_Chessboard(i, j, 0, chessboard);

				if (value < min_now) {
					min_now = value;

					if (min_now <= max_now) {
						need_retun = true;
					}
				}

			}


		}

	}


}


int Find_Value_Totle(int** chessboard, int chess_long, int x, int y, int ai_side, int type) {
	int value=0;
	switch (type)
	{
	case 6:
		//A看A
		if (ai_side == 1) {
			return Load_Value_for_1(y, x, 1, chessboard);
		}
		else 
		return Load_Value_for_2(y, x, 1, chessboard);

		

	case 7:
		//B看A
		if (ai_side == 1) {
		return -Load_Value_for_2(y, x, 1, chessboard);
	}
		  else
		return -Load_Value_for_1(y, x, 1, chessboard);
	
	default:
		return 0;
	}

	
}
int Limit(int input, int min_limit, int max_limit) {
	if (input < min_limit)
		return min_limit;
	else if (input > max_limit)
		return max_limit;
	else
		return input;
}