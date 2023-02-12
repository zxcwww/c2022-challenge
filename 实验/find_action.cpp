#include"find_action.h"



pos_2D Find_Action(int** chessboard, int chess_long, int ai_side,bool &is_start,int which_ai,pos_2D last_pos) {
	
	if (is_start)
	{
		is_start = false;
		pos_2D pos;
		pos.x = pos.y=chess_long / 2;
		return pos;
	}

	if (which_ai == 2)
		return Alpha_Beta_Tree_Control(chessboard, chess_long, ai_side, 5, 1);
	if (which_ai == 12)
		return Alpha_Beta_Tree_Dir_Control(chessboard, chess_long, ai_side,  1);
	if (which_ai == 15)
		return Alpha_Beta_Tree_Dir_Control(chessboard, chess_long, ai_side, 2);
	if (which_ai == 13)
		return Alpha_Beta_Tree_Dir_Roll_Seach_Control(chessboard, chess_long, ai_side, 1, last_pos);
	if (which_ai == 14)
		return Alpha_Beta_Tree_Dir_Roll_Seach_Control(chessboard, chess_long, ai_side, 2, last_pos);
		
	int best_value = -1000000000;
	pos_2D pos;
	for (int i = 0; i < chess_long; i++) {
		for (int j = 0; j < chess_long; j++) {
			if (chessboard[i][j] == 0) {
				int value;
				value = Find_Value_Totle(chessboard, chess_long, j, i, ai_side, which_ai);
				
				if (value > best_value) {
					best_value = value;
					pos.y = i;
					pos.x = j;
				}
			}
		}
	}

	if (best_value == -1000000000) {
		for (int i = 0; i < chess_long; i++) {
			for (int j = 0; j < chess_long; j++) {
				if (chessboard[i][j]==0) {
					pos.y = i;
					pos.x = j;
				}
			}
		}
	}
	//bug,如果棋盘满了，会爆炸
		return pos;
	
}
pos_2D Alpha_Beta_Tree_Control(int** chessboard, int chess_long, int ai_side, int which_ai, int deep_of_tree) {
	pos_2D pos;
	const int MAX = 1000000000, MIN = -1000000000;
	int max_now = MIN, min_now = MAX;

	for (int i = 0; i < chess_long; i++) {
		for (int j = 0; j < chess_long; j++) {
			if (chessboard[i][j] == 0) {
				
				chessboard[i][j] = ai_side;

				int value =
					Alpha_Beta_Tree
					(chessboard, chess_long, ai_side, which_ai, deep_of_tree - 1, false,
						max_now);
				chessboard[i][j] = 0;
				if (value > max_now) {
					max_now = value;
					pos.x = j;
					pos.y = i;
					
				}

			}
		}

	}

	return pos;
}

int Alpha_Beta_Tree(int** chessboard, int chess_long, int ai_side, int which_ai,int deep_of_tree,bool is_max_side,int now_value) {
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
	
	if (deep_of_tree == 0) {
		if (is_max_side) {
			for (int i = 0; i < chess_long; i++) {
				for (int j = 0; j < chess_long; j++) {
					if (chessboard[i][j] == 0) {
						chessboard[i][j] = ai_side;
						int value = Find_Value_Totle(chessboard,  chess_long,  j,  i,  ai_side,  which_ai);
						chessboard[i][j] = 0;
						if (value > max_now) {
							max_now = value;

							if (min_now <= max_now) {
								return min_now;
							}
						}
						
					}
				}

			}
			return max_now;
		}
		else {
			for (int i = 0; i < chess_long; i++) {
				for (int j = 0; j < chess_long; j++) {
					if (chessboard[i][j] == 0) {
						chessboard[i][j] =  3 - ai_side;
						int value = Find_Value_Totle(chessboard, chess_long, j, i, ai_side, which_ai);
						chessboard[i][j] = 0;

						if (value < min_now) {
							min_now = value;

							if (min_now <= max_now) {
								return max_now;
							}
						}

					}
				}

			}
			return min_now;
		}

	}
	else {
		if (is_max_side) {
			for (int i = 0; i < chess_long; i++) {
				for (int j = 0; j < chess_long; j++) {
					if (chessboard[i][j] == 0) {
						int value;

						chessboard[i][j] = ai_side;
						value =
							Alpha_Beta_Tree
							(chessboard, chess_long,ai_side, which_ai, deep_of_tree - 1, false,
								max_now);

						chessboard[i][j] = 0;
						if (value > max_now) {
							max_now = value;

							if (min_now <= max_now) {
								return min_now;
							}
						}

					}
				}

			}

		}

		else {
			for (int i = 0; i < chess_long; i++) {
				for (int j = 0; j < chess_long; j++) {
					if (chessboard[i][j] == 0) {

						chessboard[i][j] =3- ai_side;
						int value =
							Alpha_Beta_Tree
							(chessboard, chess_long, ai_side, which_ai, deep_of_tree - 1, true,
								min_now);
						chessboard[i][j] = 0;

						if (value < min_now) {
							min_now = value;

							if (min_now <= max_now) {
								return max_now;
							}
						}

					}
				}

			}
		}

	}

	if (is_max_side)
		return max_now;
	else
		return min_now;
}

pos_2D Alpha_Beta_Tree_Dir_Control(int** chessboard, int chess_long, int ai_side, int deep_of_tree) {
	pos_2D pos;
	const int MAX = 1000000000, MIN = -1000000000;
	int max_now = MIN, min_now = MAX;

	for (int i = 0; i < chess_long; i++) {
		for (int j = 0; j < chess_long; j++) {
			if (chessboard[i][j] == 0) {

				int value_here=Find_Value_Totle(chessboard, chess_long, j, i, ai_side, 6);

				chessboard[i][j] = ai_side;

				int value =
					Alpha_Beta_Tree_Dir
					(chessboard, chess_long, ai_side, deep_of_tree - 1, false,
						max_now-value_here);
				value += value_here;
				chessboard[i][j] = 0;
				if (value > max_now) {
					max_now = value;
					pos.x = j;
					pos.y = i;

				}

			}
		}

	}

	return pos;
}

int Alpha_Beta_Tree_Dir(int** chessboard, int chess_long, int ai_side, int deep_of_tree, bool is_max_side, int now_value) {
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

	if (deep_of_tree == 0) {
		if (is_max_side) {
			for (int i = 0; i < chess_long; i++) {
				for (int j = 0; j < chess_long; j++) {
					if (chessboard[i][j] == 0) {
						int value = Find_Value_Totle(chessboard, chess_long, j, i, ai_side, 6);
						if (value > max_now) {
							max_now = value;

							if (min_now <= max_now) {
								return min_now;
							}
						}

					}
				}

			}
			return max_now;
		}
		else {
			for (int i = 0; i < chess_long; i++) {
				for (int j = 0; j < chess_long; j++) {
					if (chessboard[i][j] == 0) {
						
						int value = Find_Value_Totle(chessboard, chess_long, j, i, ai_side, 7);

						if (value < min_now) {
							min_now = value;

							if (min_now <= max_now) {
								return max_now;
							}
						}

					}
				}

			}
			return min_now;
		}

	}
	else {
		if (is_max_side) {
			for (int i = 0; i < chess_long; i++) {
				for (int j = 0; j < chess_long; j++) {
					if (chessboard[i][j] == 0) {
						

						int value_here = Find_Value_Totle(chessboard, chess_long, j, i, ai_side, 6);

						chessboard[i][j] = ai_side;

						int value =
							Alpha_Beta_Tree_Dir
							(chessboard, chess_long, ai_side, deep_of_tree - 1, false,
								max_now - value_here);
						value += value_here;
						if (value > max_now) {
							max_now = value;

							if (min_now <= max_now) {
								return min_now;
							}
						}

					}
				}

			}

		}

		else {
			for (int i = 0; i < chess_long; i++) {
				for (int j = 0; j < chess_long; j++) {
					if (chessboard[i][j] == 0) {
						int value_here = Find_Value_Totle(chessboard, chess_long, j, i, ai_side, 7);

						chessboard[i][j] = 3-ai_side;

						int value =
							Alpha_Beta_Tree_Dir
							(chessboard, chess_long, ai_side, deep_of_tree - 1, true,
								min_now - value_here);
						value += value_here;

						chessboard[i][j] = 0;

						if (value < min_now) {
							min_now = value;

							if (min_now <= max_now) {
								return max_now;
							}
						}

					}
				}

			}
		}

	}

	if (is_max_side)
		return max_now;
	else
		return min_now;
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
		chessboard[y][x] = ai_side;
		int value =
			Alpha_Beta_Tree_Dir_Roll_Seach
			(chessboard, chess_long, ai_side, deep_of_tree - 1, false,
				max_now - value_here, last_pos);
		value += value_here;
		chessboard[y][x] = 0;
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

				chessboard[i][j] = ai_side;

				int value =
					Alpha_Beta_Tree_Dir_Roll_Seach
					(chessboard, chess_long, ai_side, deep_of_tree - 1, false,
						max_now - value_here, last_pos);
				value += value_here;
				chessboard[i][j] = 0;

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

				chessboard[i][j] = 3 - ai_side;

				int value =
					Alpha_Beta_Tree_Dir_Roll_Seach
					(chessboard, chess_long, ai_side, deep_of_tree - 1, true,
						min_now - value_here,last_pos);//mark
				value += value_here;

				chessboard[i][j] = 0;

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
	case 0:
		return (Find_Value(chessboard, chess_long, x, y, ai_side) + Find_Value(chessboard, chess_long, x, y, 3 - ai_side));
	case 1:
		return  (Find_Value(chessboard, chess_long, x, y, ai_side) + Find_Value(chessboard, chess_long, x, y, 3 - ai_side) / 2);
	
	case 3:

		chessboard[y][x] = ai_side;
		value += Find_Sum_Value(chessboard, chess_long, ai_side);
		value -= Find_Sum_Value(chessboard, chess_long, 3 - ai_side);
		chessboard[y][x] = 0;


		return value;
	case 4:
		chessboard[y][x] = ai_side;
		value += Find_Sum_Value(chessboard, chess_long, ai_side);
		value -= Find_Sum_Value(chessboard, chess_long, 3 - ai_side)*20 ;
		chessboard[y][x] = 0;
		return value;
	case 5:
		value += Find_Sum_Value(chessboard, chess_long, ai_side);
		value -= Find_Sum_Value(chessboard, chess_long, 3 - ai_side);
		return value;

	//A看A
	case 6:
		value -= (Find_Value_Dir(chessboard, chess_long, x, y, ai_side) - Find_Value_Dir(chessboard, chess_long, x, y, 3 - ai_side));
		chessboard[y][x] = ai_side;
		value += (Find_Value_Dir(chessboard, chess_long, x, y, ai_side) - Find_Value_Dir(chessboard, chess_long, x, y, 3 - ai_side));

		chessboard[y][x] = 0;

		return value;

	//B看A

	case 7:
		value -= (Find_Value_Dir(chessboard, chess_long, x, y, ai_side) - Find_Value_Dir(chessboard, chess_long, x, y, 3 - ai_side));
		chessboard[y][x] =3- ai_side;
		value += (Find_Value_Dir(chessboard, chess_long, x, y, ai_side) - Find_Value_Dir(chessboard, chess_long, x, y, 3 - ai_side));

		chessboard[y][x] = 0;

		return value;
	default:
		return (Find_Value(chessboard, chess_long, x, y, ai_side) + Find_Value(chessboard, chess_long, x, y, 3 - ai_side));
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