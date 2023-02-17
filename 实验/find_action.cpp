#include"find_action.h"

const int POW_CHESS_LONG = 225;
const int MIN_OF_INT = -1000000000;
const int MAX_OF_INT = 1000000000;


int find_win_deep;
int start_deep;
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
		return Alpha_Beta_Tree_Dir_Roll_Seach_Control(chessboard, chess_long, ai_side, 3, last_pos);
	case 15:
		return Alpha_Beta_Tree_Dir_Roll_Seach_Control(chessboard, chess_long, ai_side, 5, last_pos);
	case 16:
		return Alpha_Beta_Tree_Extent_Limit_Seach_Control(chessboard, chess_long, ai_side, 7, 8,last_pos);
	default:
		return Alpha_Beta_Tree_Dir_Roll_Seach_Control(chessboard, chess_long, ai_side, 1, last_pos);
	}

	
}
void Sort_Arr_With_Need(int* arr, int* sub_arr, int arr_length, int need) {
	for (int i = 0; i < arr_length; i++) {
		sub_arr[i] = i;
	}
	for (int i = arr_length; i > (arr_length - need); i--) {
		for (int j = i - 1; j >=0; j--) {
			if (arr[j] < arr[j + 1]) {
				int save = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = save;
				save = sub_arr[j + 1];
				sub_arr[j + 1] = sub_arr[j];
				sub_arr[j] = save;
			}
		}
	}
}
bool Check_Win(int value) {
	if (value > 9000000) {
		return true;
	}
	else {
		return false;
	}

}
void Find_Road(int** chessboard, int* sub_arr, int chess_long, int ai_side, bool is_max_side, int deep_of_tree, int extent_limit) {
	int find_road[POW_CHESS_LONG];

	int type = is_max_side ? 8 : 9;

	for (int i = 0; i < POW_CHESS_LONG; i++) {
		if (chessboard[i / chess_long][i % chess_long] == 0) {
			find_road[i] = Find_Value_Totle(chessboard, chess_long, i % 15, i / 15, ai_side, type, deep_of_tree);
		}
		else {
			find_road[i] = 0;
		}
	}
	 Sort_Arr_With_Need(find_road, sub_arr, POW_CHESS_LONG, extent_limit);
}
pos_2D Alpha_Beta_Tree_Extent_Limit_Seach_Control(int** chessboard, int chess_long, int ai_side, int deep_of_tree, int extent_limit,pos_2D last_pos) {
	pos_2D pos;
	int max_now = MIN_OF_INT, min_now = MAX_OF_INT;

	find_win_deep = -1;
	start_deep = deep_of_tree;

	int sub_arr[POW_CHESS_LONG];
	Find_Road(chessboard, sub_arr, chess_long,  ai_side, true, deep_of_tree, extent_limit);

	for (int i = 0; i < extent_limit; i++) {
		Alpha_Beta_Tree_Extent_Limit_Check_Value_Unit_Control(chessboard, chess_long, ai_side, deep_of_tree, extent_limit,
			max_now, last_pos, pos, sub_arr[i] % chess_long, sub_arr[i] / chess_long);
	}


	if (find_win_deep == 0 || find_win_deep == -1) {
		return pos;
	}
	else {
		return pos;

		//return Alpha_Beta_Tree_Extent_Limit_Seach_Control(chessboard, chess_long, ai_side, start_deep - find_win_deep, extent_limit, last_pos);
	}
}
void Alpha_Beta_Tree_Extent_Limit_Check_Value_Unit_Control(int** chessboard, int chess_long, int ai_side, int deep_of_tree, int extent_limit,int& max_now, pos_2D last_pos, pos_2D& pos, int x, int y) {
	if (chessboard[y][x] == 0) {
		int value = 0;

		int value_here = Find_Value_Totle(chessboard, chess_long, x, y, ai_side, 6, deep_of_tree);
		if (Check_Win(value_here)) {
			value = 20000000 * (1 + deep_of_tree);
		}
		else {
			Change_Chessboard(y, x, ai_side, chessboard);
			if (deep_of_tree != 0) {

				value =
					Alpha_Beta_Tree_Dir_Extent_Limit
					(chessboard, chess_long, ai_side, deep_of_tree - 1, extent_limit, false,
						max_now - value_here, last_pos);

			}
			value += value_here;
			Change_Chessboard(y, x, 0, chessboard);
		}
		
		if (value > max_now) {
			max_now = value;
			pos.x = x;
			pos.y = y;

		}

	}
}


pos_2D Alpha_Beta_Tree_Dir_Roll_Seach_Control(int** chessboard, int chess_long, int ai_side, int deep_of_tree,pos_2D last_pos) {
	pos_2D pos;
	int max_now = MIN_OF_INT, min_now = MAX_OF_INT;

	find_win_deep = -1;
    start_deep = deep_of_tree;

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

	if (find_win_deep == 0 || find_win_deep==-1) {
		return pos;

	}
	else {
		return Alpha_Beta_Tree_Dir_Roll_Seach_Control( chessboard,  chess_long,  ai_side, start_deep -find_win_deep,  last_pos);
	}
}



void Alpha_Beta_Tree_Check_Value_Unit_Control(int** chessboard, int chess_long, int ai_side, int deep_of_tree, int& max_now, pos_2D last_pos, pos_2D& pos, int x, int y) {
	if (chessboard[y][x] == 0) {

		int value_here = Find_Value_Totle(chessboard, chess_long, x, y, ai_side, 6,deep_of_tree);
		
		Change_Chessboard(y, x, ai_side, chessboard);
		int value=0;
		if (deep_of_tree != 0) {

			value =
				Alpha_Beta_Tree_Dir_Roll_Seach
				(chessboard, chess_long, ai_side, deep_of_tree - 1, false,
					max_now - value_here, last_pos);
			
		}
		value += value_here;
		Change_Chessboard(y, x, 0, chessboard);
		if (value > max_now) {
			max_now = value;
			pos.x = x;
			pos.y = y;

		}

	}
}
int Alpha_Beta_Tree_Dir_Extent_Limit(int** chessboard, int chess_long, int ai_side, int deep_of_tree,int extent_limit, bool is_max_side, int now_value, pos_2D last_pos) {

	int max_now = MIN_OF_INT, min_now = MAX_OF_INT;

	//当前层级结论的最大，最小值

	//这一个节点是求最大的，上一个节点是求最小的，若该节点的子节点中有超过最小的，该节点也会超，该节点会无效，终止遍历
	if (is_max_side) {
		min_now = now_value;

	}
	//这一个节点是求最小的，上一个节点是求最大的，若该节点的子节点中有小过最大的，该节点也会小过最大，该节点会无效，终止遍历
	else {
		max_now = now_value;

	}


	if (deep_of_tree != 0) {

		int sub_arr[POW_CHESS_LONG];
		Find_Road(chessboard, sub_arr, chess_long, ai_side, is_max_side, deep_of_tree, extent_limit);
		for (int i = 0; i < extent_limit; i++) {
			bool need_return = false;
			Alpha_Beta_Tree_Dir_Extent_Limit_Unit(chessboard, chess_long, ai_side,
				deep_of_tree,extent_limit, is_max_side, max_now, min_now, last_pos, sub_arr[i] /chess_long, sub_arr[i] % chess_long, need_return);
			if (need_return)
				return is_max_side ? min_now : max_now;
		}

	}
	else{

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

					bool need_return = false;
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

	}
	return is_max_side ? max_now : min_now;

}
int Alpha_Beta_Tree_Dir_Roll_Seach(int** chessboard, int chess_long, int ai_side, int deep_of_tree, bool is_max_side, int now_value,pos_2D last_pos) {

	int max_now = MIN_OF_INT, min_now = MAX_OF_INT;

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


void Alpha_Beta_Tree_Dir_Extent_Limit_Unit(int** chessboard, int chess_long, int ai_side, int deep_of_tree, int extent_limit, bool is_max_side, int& max_now, int& min_now, pos_2D last_pos, int y, int x, bool& need_retun) {

	
		if (is_max_side) {

			if (chessboard[y][x] == 0) {
				int value=0;

				int value_here = Find_Value_Totle(chessboard, chess_long, x, y, ai_side, 6, deep_of_tree);
				if (Check_Win(value_here)) {
					value = 20000000 * (1 + deep_of_tree);
				}
				else {

					Change_Chessboard(y, x, ai_side, chessboard);

					value =
						Alpha_Beta_Tree_Dir_Extent_Limit
						(chessboard, chess_long, ai_side, deep_of_tree - 1, extent_limit, false,
							max_now - value_here, last_pos);
					value += value_here;
					Change_Chessboard(y, x, 0, chessboard);

				}
				if (value > max_now) {
					max_now = value;

					if (min_now <= max_now) {
						need_retun = true;
					}
				}

			}

		}

		else {

			if (chessboard[y][x] == 0) {
				int value = 0;
				int value_here = Find_Value_Totle(chessboard, chess_long, x, y, ai_side, 7, deep_of_tree);
				if (Check_Win(-value_here)) {
					value = -20000000 * (1 + deep_of_tree);
				}
				else {
					Change_Chessboard(y, x, 3 - ai_side, chessboard);


					 value =
						Alpha_Beta_Tree_Dir_Extent_Limit
						(chessboard, chess_long, ai_side, deep_of_tree - 1, extent_limit, true,
							min_now - value_here, last_pos);//mark
					value += value_here;

					Change_Chessboard(y, x, 0, chessboard);
				}
				if (value < min_now) {
					min_now = value;

					if (min_now <= max_now) {
						need_retun = true;
					}
				}

			}


		}

	


}

void Alpha_Beta_Tree_Dir_Roll_Seach_Unit(int** chessboard, int chess_long, int ai_side, int deep_of_tree, bool is_max_side, int& max_now, int &min_now, pos_2D last_pos, int i, int j,bool &need_retun) {
	
	if (deep_of_tree == 0) {
		if (is_max_side) {
			
			if (chessboard[i][j] == 0) {
				int value = Find_Value_Totle(chessboard, chess_long, j, i, ai_side, 6, deep_of_tree);
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

				int value = Find_Value_Totle(chessboard, chess_long, j, i, ai_side, 7, deep_of_tree);

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


				int value_here = Find_Value_Totle(chessboard, chess_long, j, i, ai_side, 6, deep_of_tree);

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
				int value_here = Find_Value_Totle(chessboard, chess_long, j, i, ai_side, 7, deep_of_tree);
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


int Find_Value_Totle(int** chessboard, int chess_long, int x, int y, int ai_side, int type,int deep_of_tree) {
	int value=0;
	switch (type)
	{
	case 6:
		//A看A
		if (ai_side == 1) {
			value = Load_Value_for_1(y, x, 1, chessboard);
		}
		else 
			value = Load_Value_for_2(y, x, 1, chessboard);
		break;
		

	case 7:
		//B看A
		if (ai_side == 1) {
			value = -Load_Value_for_2(y, x, 1, chessboard);
	}
		  else
			value = -Load_Value_for_1(y, x, 1, chessboard);
		break;
	case 8:
		//启发式函数
		//A看A
		if (ai_side == 1) {
			value = Load_Value_for_Find_Road_1(y, x, 1, chessboard);
		}
		else
			value = Load_Value_for_Find_Road_2(y, x, 1, chessboard);
		break;


	case 9:
		//启发式函数
		//B看A
		if (ai_side == 1) {
			value = Load_Value_for_Find_Road_2(y, x, 1, chessboard);
		}
		else
			value = Load_Value_for_Find_Road_1(y, x, 1, chessboard);
		break;
	default:
		if (ai_side == 1) {
			value = Load_Value_for_1(y, x, 1, chessboard);
		}
		else
			value = Load_Value_for_2(y, x, 1, chessboard);
		break;

	}

	return value;
}
int Limit(int input, int min_limit, int max_limit) {
	if (input < min_limit)
		return min_limit;
	else if (input > max_limit)
		return max_limit;
	else
		return input;
}