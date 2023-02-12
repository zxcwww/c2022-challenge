#include"find_value.h"

//{value,need_to_read,chees[need_to_read]}
int TYPE_CONUT = 20;
int value_type[22][10] = {
    //5
    {10000000,5,1,1,1,1,1},
    //t4
    {1000000,6,0,1,1,1,1,0},
    //t3,f4
    {10000,6,0,1,1,1,0,0},{10000,6,0,1,1,0,1,0} ,
    {10000,6,2,1,1,1,1,0}, {10000,6,2,1,1,1,0,1}, {10000,6,2,1,1,0,1,1}, {10000,6,2,1,0,1,1,1},


    //t2,f3
    {1000,5,0,0,1,1,0},{1000,6,0,1,0,1,0},{1000,6,0,1,0,0,1,0},
    {1000,6,2,1,1,1,0,0},{1000,6,2,1,0,1,1,0},{1000,6,2,1,1,0,1,0},{1000,6,2,1,1,0,1,0},{1000,6,2,1,1,0,0,1},
    //f2
    {100,6,2,1,1,0,0,0},{100,6,2,1,0,1,0,0},{100,6,2,1,0,0,1,0},{100,6,2,1,0,0,0,1},

    {10,7,0,0,0,0,1,0,0},
};


int test[8] = { 100000,5,1,1,1,1,1 };

int pause_time = 500;

int Find_Sum_Value(int** chessboard, int chess_long, int ai_side) {
    int sum = 0;
    for (int i = 0; i < chess_long; i++) {
        for (int j = 0; j < chess_long; j++) {
           
                sum+= Find_Value_Not_Skip(chessboard, chess_long, j, i, ai_side);

               
            
        }
    }


    return sum;
}
int Find_Value(int** chessboard, int chess_long, int x, int y, int ai_side) {
    int sum_value = 0;

    //八个方向
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int best_value=0;
            for (int row_number = 0; row_number < TYPE_CONUT; row_number++) {


                for (int pos = 0; pos < value_type[row_number][1]; pos++) {
                    int is_same = true;
                    for (int k = -pos; k < value_type[row_number][1] - pos; k++) {
                        //不判断落子位置
                        if (k == 0) {
                            continue;
                        }

                        //出界
                            if ((y + i * k) < 0 || (y + i * k) >= chess_long || (x + j * k) < 0 || (x + j * k) >= chess_long) {
                                if ((k + pos == 0 && value_type[row_number][2] == 2) || (k + pos == value_type[row_number][1] - 1 && value_type[row_number][2 + k + pos] == 2)) {
                                    continue;
                                }
                                is_same = false;
                                break;
                            }
                        
                        //不符合
                        if (ai_side == 1) {
                            if (chessboard[y + i * k][x + j * k] != value_type[row_number][2 + k + pos]) {
                                is_same = false;
                                break;
                            }
                        }
                        else if (ai_side == 2) {
                           
                                if (chessboard[y + i * k][x + j * k] != Change_Side(value_type[row_number][2 + k + pos])) {
                                    is_same = false;
                                    break;
                                }
                            
                        }

                    }
                    if (is_same) {
                        if (value_type[row_number][0] > best_value) {
                            best_value = value_type[row_number][0];
                        }
                    }
                }
            }
            sum_value += best_value;
        }
    }
    return sum_value;
}

int Find_Value_Dir(int** chessboard, int chess_long, int x, int y, int ai_side) {
    int sum_value = 0;

    //八个方向
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int best_value = 0;
            for (int row_number = 0; row_number < TYPE_CONUT; row_number++) {


                for (int pos = 0; pos < value_type[row_number][1]; pos++) {
                    int is_same = true;
                    for (int k = -pos; k < value_type[row_number][1] - pos; k++) {
                        

                        //出界
                        if ((y + i * k) < 0 || (y + i * k) >= chess_long || (x + j * k) < 0 || (x + j * k) >= chess_long) {
                            if ((k + pos == 0 && value_type[row_number][2] == 2) || (k + pos == value_type[row_number][1] - 1 && value_type[row_number][2 + k + pos] == 2)) {
                                continue;
                            }
                            is_same = false;
                            break;
                        }

                        //不符合
                        if (ai_side == 1) {
                            if (chessboard[y + i * k][x + j * k] != value_type[row_number][2 + k + pos]) {
                                is_same = false;
                                break;
                            }
                        }
                        else if (ai_side == 2) {

                            if (chessboard[y + i * k][x + j * k] != Change_Side(value_type[row_number][2 + k + pos])) {
                                is_same = false;
                                break;
                            }

                        }

                    }
                    if (is_same) {
                        if (value_type[row_number][0] > best_value) {
                            best_value = value_type[row_number][0];
                        }
                    }
                }
            }
            sum_value += best_value;
        }
    }
    return sum_value;
}


int Find_Value_Not_Skip(int** chessboard, int chess_long, int x, int y, int ai_side) {
    int sum_value = 0;

    //八个方向
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if ((i == 0 && j == 0)
               // ||(i==0&&j==-1)
                ){
                continue;
            }
            int best_value = 0;
            for (int row_number = 0; row_number < TYPE_CONUT; row_number++) {
                int pos = 0;
                    int is_same = true;
                    for (int k = -pos; k < value_type[row_number][1] - pos; k++) {
                        
                        

                        //出界
                        if ((y + i * k) < 0 || (y + i * k) >= chess_long || (x + j * k) < 0 || (x + j * k) >= chess_long) {
                            if ((k + pos == 0 && value_type[row_number][2] == 2) || (k + pos == value_type[row_number][1] - 1 && value_type[row_number][2 + k + pos] == 2)) {
                                continue;
                            }
                            is_same = false;
                            break;
                        }

                        //不符合
                        if (ai_side == 1) {
                            if (chessboard[y + i * k][x + j * k] != value_type[row_number][2 + k + pos]) {
                                is_same = false;
                                break;
                            }
                        }
                        else if (ai_side == 2) {

                            if (chessboard[y + i * k][x + j * k] != Change_Side(value_type[row_number][2 + k + pos])) {
                                is_same = false;
                                break;
                            }

                        }

                    }
                    if (is_same) {
                        if (value_type[row_number][0] > best_value) {
                            best_value = value_type[row_number][0];
                        }
                    }
                
            }
            sum_value += best_value;
        }
    }
    return sum_value;
}


    int Change_Side(int number)
    {
        switch (number)
        {
        case 0:
            return 0;
            
        case 1:
            return 2;
        case 2:
            return 1;
        }
    }
    bool Find_Win(int** chessboard, int chess_long, int x, int y, int side) {
        int sum_value = 0;

        //八个方向
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int best_value = 0;
                int row_number = 0;


                for (int pos = 0; pos < value_type[row_number][1]; pos++) {
                    int is_same = true;
                    for (int k = -pos; k < value_type[row_number][1] - pos; k++) {
                        //不判断落子位置
                        if (k == 0) {
                            continue;
                        }

                        //出界
                        if ((y + i * k) < 0 || (y + i * k) >= chess_long || (x + j * k) < 0 || (x + j * k) >= chess_long) {
                            if ((k + pos == 0 && value_type[row_number][2] == 2) || (k + pos == value_type[row_number][1] - 1 && value_type[row_number][2 + k + pos] == 2)) {
                                continue;
                            }
                            is_same = false;
                            break;
                        }

                        //不符合
                        if (side == 1) {
                            if (chessboard[y + i * k][x + j * k] != value_type[row_number][2 + k + pos]) {
                                is_same = false;
                                break;
                            }
                        }
                        else if (side == 2) {

                            if (chessboard[y + i * k][x + j * k] != Change_Side(value_type[row_number][2 + k + pos])) {
                                is_same = false;
                                break;
                            }

                        }

                    }
                    if (is_same) {
                        return true;
                    }
                }


            }
        }
        return false;
    }
