#include"find_value.h"

//{value,need_to_read,chees[need_to_read]}

const int POWER_OF_4[11] = {1, 4,16,64,256,1024,4096,16384 ,65536,262144,1048576};
int save_value[1048576];
int save_value_for_find_road[1048576];

int sub_chessboard_for_1[25][25] = {
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},

};

int sub_chessboard_for_2[25][25] = {
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
    {3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},

};


int TYPE_CONUT = 19;

int value_type[22][10] = {
    //5
    {10000000,5,1,1,1,1,1},
    //t4
    {1000000,6,0,1,1,1,1,0},
    //t3,f4
    {10000,6,0,1,1,1,0,0},{10000,6,0,0,1,1,1,0}, {10000,6,2,0,1,1,1,0} ,{10000,6,0,1,1,0,1,0} ,
    {10000,6,2,1,1,1,1,0}, {10000,5,1,1,1,0,1}, {5000,5,1,1,0,1,1},


    //t2,f3
    {1000,5,0,0,1,1,0}, {1000,5,0,1,1,0,0},
    {1000,6,2,1,1,1,0,0},{1000,6,2,1,0,1,1,0},{1000,6,2,1,1,0,1,0},{1000,6,2,1,1,0,1,0},{1000,6,2,1,1,0,0,1},
    {500,6,0,1,0,1,0},{500,6,0,1,0,0,1,0},
    //f2
    {100,6,2,1,1,0,0,0},{50,6,2,1,0,1,0,0},{50,6,2,1,0,0,1,0},{50,6,2,1,0,0,0,1},

};
int value_type_back[22][10] = {
    //5
    {10000000,5,2,2,2,2,2},
    //t4
    {2000000,6,0,2,2,2,2,0},
    //t3,f4
    {20000,6,0,2,2,2,0,0},{20000,6,0,0,2,2,2,0} ,{20000,6,1,0,2,2,2,0},{20000,6,0,2,2,0,2,0} ,
    {20000,6,1,2,2,2,2,0}, {20000,5,2,2,2,0,2}, {10000,5,2,2,0,2,2},


    //t2,f3
    {2000,5,0,0,2,2,0},    {2000,5,0,2,2,0,0},
    {2000,6,1,2,2,2,0,0},{2000,6,1,2,0,2,2,0},{2000,6,1,2,2,0,2,0},{2000,6,1,2,2,0,2,0},{2000,6,1,2,2,0,0,2},
    {1000,6,0,2,0,2,0},{1000,6,0,2,0,0,2,0},
    //f1
    {400,6,1,2,2,0,0,0},{200,6,1,2,0,2,0,0},{200,6,1,2,0,0,2,0},{200,6,1,2,0,0,0,2},

};

void Change_Chessboard(int y,int x,int chess_type, int** chessboard_p) {
    chessboard_p[y][x] = chess_type;
    sub_chessboard_for_1[y+5][x+5] = chess_type;
    sub_chessboard_for_2[y + 5][x + 5] = Change_Side(chess_type);

}


void Save_Value() {
    int mark = 0;
    int save_[11];


    for ( save_[0] = 0; save_[0] < 4; save_[0]++) {
        for ( save_[1] = 0; save_[1] < 4; save_[1]++) {
            for ( save_[2] = 0; save_[2] < 4; save_[2]++) {
                for ( save_[3] = 0; save_[3] < 4; save_[3]++) {
                    for ( save_[4] = 0; save_[4] < 4; save_[4]++) {
                        for ( save_[6] = 0; save_[6] < 4; save_[6]++) {
                            for ( save_[7] = 0; save_[7] < 4; save_[7]++) {
                                for ( save_[8] = 0; save_[8] < 4; save_[8]++) {
                                    for ( save_[9] = 0; save_[9] < 4; save_[9]++) {
                                        for ( save_[10] = 0; save_[10] < 4; save_[10]++) {
                                            save_[5] = 0;
                                            save_value[mark] = -Find_Value_Dir_Unit_test_for_1(save_, 11, 5, 1)- Find_Value_Dir_Unit_test_for_1(save_, 11, 5, -1)
                                                + Find_Value_Dir_Unit_test_for_2(save_, 11, 5, 1) + Find_Value_Dir_Unit_test_for_2(save_, 11, 5, -1)
                                                ;
                                            save_[5] = 1;
                                            save_value[mark] += Find_Value_Dir_Unit_test_for_1(save_, 11, 5, 1) + Find_Value_Dir_Unit_test_for_1(save_, 11, 5, -1)
                                                - Find_Value_Dir_Unit_test_for_2(save_, 11, 5, 1) - Find_Value_Dir_Unit_test_for_2(save_, 11, 5, -1)
                                                ;
                                            mark++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    FILE* fp_s = NULL;


    errno_t err = fopen_s(&fp_s, "save_value.txt", "wb");

    fwrite(save_value, sizeof(int), POWER_OF_4[10], fp_s);
    fclose(fp_s);

   

}
void Save_Value_For_Find_Road() {
    int mark = 0;
    int save_[11];


    for (save_[0] = 0; save_[0] < 4; save_[0]++) {
        for (save_[1] = 0; save_[1] < 4; save_[1]++) {
            for (save_[2] = 0; save_[2] < 4; save_[2]++) {
                for (save_[3] = 0; save_[3] < 4; save_[3]++) {
                    for (save_[4] = 0; save_[4] < 4; save_[4]++) {
                        for (save_[6] = 0; save_[6] < 4; save_[6]++) {
                            for (save_[7] = 0; save_[7] < 4; save_[7]++) {
                                for (save_[8] = 0; save_[8] < 4; save_[8]++) {
                                    for (save_[9] = 0; save_[9] < 4; save_[9]++) {
                                        for (save_[10] = 0; save_[10] < 4; save_[10]++) {
                                            save_[5] = 2;
                                            save_value_for_find_road[mark] = -Find_Value_Dir_Unit_test_for_1(save_, 11, 5, 1) - Find_Value_Dir_Unit_test_for_1(save_, 11, 5, -1)
                                                + Find_Value_Dir_Unit_test_for_2(save_, 11, 5, 1) + Find_Value_Dir_Unit_test_for_2(save_, 11, 5, -1)
                                                ;
                                            save_[5] = 1;
                                            save_value_for_find_road[mark] += Find_Value_Dir_Unit_test_for_1(save_, 11, 5, 1) + Find_Value_Dir_Unit_test_for_1(save_, 11, 5, -1)
                                                - Find_Value_Dir_Unit_test_for_2(save_, 11, 5, 1) - Find_Value_Dir_Unit_test_for_2(save_, 11, 5, -1)
                                                ;
                                            mark++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    FILE* fp_s = NULL;


    errno_t err = fopen_s(&fp_s, "save_value_for_find_road.txt", "wb");

    fwrite(save_value_for_find_road, sizeof(int), POWER_OF_4[10], fp_s);
    fclose(fp_s);



}
void Load_Value() {

    FILE* fp_s = NULL;


    errno_t err = fopen_s(&fp_s, "save_value.txt", "rb");

    fread(save_value, sizeof(int), POWER_OF_4[10], fp_s);
    fclose(fp_s);

    err = fopen_s(&fp_s, "save_value_for_find_road.txt", "rb");

    fread(save_value_for_find_road, sizeof(int), POWER_OF_4[10], fp_s);
    fclose(fp_s);
}
int Load_Value_for_1(int y, int x, int chess_type, int** chessboard_p) {
    y += 5;
    x += 5;
    return save_value
        [
            sub_chessboard_for_1[y][x + 5] * POWER_OF_4[0] +
            sub_chessboard_for_1[y][x + 4] * POWER_OF_4[1] +
        sub_chessboard_for_1[y][x + 3] * POWER_OF_4[2] +
        sub_chessboard_for_1[y][x + 2] * POWER_OF_4[3] +
        sub_chessboard_for_1[y][x + 1] * POWER_OF_4[4] +
        sub_chessboard_for_1[y][x - 1] * POWER_OF_4[5] +
        sub_chessboard_for_1[y][x - 2] * POWER_OF_4[6] +
        sub_chessboard_for_1[y][x - 3] * POWER_OF_4[7] +
        sub_chessboard_for_1[y][x - 4] * POWER_OF_4[8] +
        sub_chessboard_for_1[y][x - 5] * POWER_OF_4[9]
        ] +
        save_value
        [
            sub_chessboard_for_1[y+5][x + 5] * POWER_OF_4[0] +
            sub_chessboard_for_1[y+4][x + 4] * POWER_OF_4[1] +
        sub_chessboard_for_1[y+3][x + 3] * POWER_OF_4[2] +
        sub_chessboard_for_1[y+2][x + 2] * POWER_OF_4[3] +
        sub_chessboard_for_1[y+1][x + 1] * POWER_OF_4[4] +
        sub_chessboard_for_1[y-1][x - 1] * POWER_OF_4[5] +
        sub_chessboard_for_1[y-2][x - 2] * POWER_OF_4[6] +
        sub_chessboard_for_1[y-3][x - 3] * POWER_OF_4[7] +
        sub_chessboard_for_1[y-4][x - 4] * POWER_OF_4[8] +
        sub_chessboard_for_1[y-5][x - 5] * POWER_OF_4[9]
        ] +
        save_value
        [
            sub_chessboard_for_1[y - 5][x + 5] * POWER_OF_4[0] +
            sub_chessboard_for_1[y - 4][x + 4] * POWER_OF_4[1] +
        sub_chessboard_for_1[y - 3][x + 3] * POWER_OF_4[2] +
        sub_chessboard_for_1[y - 2][x + 2] * POWER_OF_4[3] +
        sub_chessboard_for_1[y - 1][x + 1] * POWER_OF_4[4] +
        sub_chessboard_for_1[y + 1][x - 1] * POWER_OF_4[5] +
        sub_chessboard_for_1[y + 2][x - 2] * POWER_OF_4[6] +
        sub_chessboard_for_1[y + 3][x - 3] * POWER_OF_4[7] +
        sub_chessboard_for_1[y + 4][x - 4] * POWER_OF_4[8] +
        sub_chessboard_for_1[y + 5][x - 5] * POWER_OF_4[9]
        ] +
        save_value
        [
            sub_chessboard_for_1[y + 5][x ] * POWER_OF_4[0] +
            sub_chessboard_for_1[y + 4][x ] * POWER_OF_4[1] +
        sub_chessboard_for_1[y + 3][x ] * POWER_OF_4[2] +
        sub_chessboard_for_1[y + 2][x ] * POWER_OF_4[3] +
        sub_chessboard_for_1[y + 1][x ] * POWER_OF_4[4] +
        sub_chessboard_for_1[y - 1][x ] * POWER_OF_4[5] +
        sub_chessboard_for_1[y - 2][x] * POWER_OF_4[6] +
        sub_chessboard_for_1[y - 3][x ] * POWER_OF_4[7] +
        sub_chessboard_for_1[y - 4][x ] * POWER_OF_4[8] +
        sub_chessboard_for_1[y - 5][x ] * POWER_OF_4[9]
        ];
}

int Load_Value_for_2(int y, int x, int chess_type, int** chessboard_p) {
    y += 5;
    x += 5;
    return save_value
        [
            sub_chessboard_for_2[y][x + 5] * POWER_OF_4[0] +
            sub_chessboard_for_2[y][x + 4] * POWER_OF_4[1] +
        sub_chessboard_for_2[y][x + 3] * POWER_OF_4[2] +
        sub_chessboard_for_2[y][x + 2] * POWER_OF_4[3] +
        sub_chessboard_for_2[y][x + 1] * POWER_OF_4[4] +
        sub_chessboard_for_2[y][x - 1] * POWER_OF_4[5] +
        sub_chessboard_for_2[y][x - 2] * POWER_OF_4[6] +
        sub_chessboard_for_2[y][x - 3] * POWER_OF_4[7] +
        sub_chessboard_for_2[y][x - 4] * POWER_OF_4[8] +
        sub_chessboard_for_2[y][x - 5] * POWER_OF_4[9]
        ] +
        save_value
        [
            sub_chessboard_for_2[y + 5][x + 5] * POWER_OF_4[0] +
            sub_chessboard_for_2[y + 4][x + 4] * POWER_OF_4[1] +
        sub_chessboard_for_2[y + 3][x + 3] * POWER_OF_4[2] +
        sub_chessboard_for_2[y + 2][x + 2] * POWER_OF_4[3] +
        sub_chessboard_for_2[y + 1][x + 1] * POWER_OF_4[4] +
        sub_chessboard_for_2[y - 1][x - 1] * POWER_OF_4[5] +
        sub_chessboard_for_2[y - 2][x - 2] * POWER_OF_4[6] +
        sub_chessboard_for_2[y - 3][x - 3] * POWER_OF_4[7] +
        sub_chessboard_for_2[y - 4][x - 4] * POWER_OF_4[8] +
        sub_chessboard_for_2[y - 5][x - 5] * POWER_OF_4[9]
        ] +
        save_value
        [
            sub_chessboard_for_2[y - 5][x + 5] * POWER_OF_4[0] +
            sub_chessboard_for_2[y - 4][x + 4] * POWER_OF_4[1] +
        sub_chessboard_for_2[y - 3][x + 3] * POWER_OF_4[2] +
        sub_chessboard_for_2[y - 2][x + 2] * POWER_OF_4[3] +
        sub_chessboard_for_2[y - 1][x + 1] * POWER_OF_4[4] +
        sub_chessboard_for_2[y + 1][x - 1] * POWER_OF_4[5] +
        sub_chessboard_for_2[y + 2][x - 2] * POWER_OF_4[6] +
        sub_chessboard_for_2[y + 3][x - 3] * POWER_OF_4[7] +
        sub_chessboard_for_2[y + 4][x - 4] * POWER_OF_4[8] +
        sub_chessboard_for_2[y + 5][x - 5] * POWER_OF_4[9]
        ] +
        save_value
        [
            sub_chessboard_for_2[y + 5][x] * POWER_OF_4[0] +
            sub_chessboard_for_2[y + 4][x] * POWER_OF_4[1] +
        sub_chessboard_for_2[y + 3][x] * POWER_OF_4[2] +
        sub_chessboard_for_2[y + 2][x] * POWER_OF_4[3] +
        sub_chessboard_for_2[y + 1][x] * POWER_OF_4[4] +
        sub_chessboard_for_2[y - 1][x] * POWER_OF_4[5] +
        sub_chessboard_for_2[y - 2][x] * POWER_OF_4[6] +
        sub_chessboard_for_2[y - 3][x] * POWER_OF_4[7] +
        sub_chessboard_for_2[y - 4][x] * POWER_OF_4[8] +
        sub_chessboard_for_2[y - 5][x] * POWER_OF_4[9]
        ];
}


int Load_Value_for_Find_Road_1(int y, int x, int chess_type, int** chessboard_p) {
    y += 5;
    x += 5;
    return save_value_for_find_road
        [
            sub_chessboard_for_1[y][x + 5] * POWER_OF_4[0] +
            sub_chessboard_for_1[y][x + 4] * POWER_OF_4[1] +
        sub_chessboard_for_1[y][x + 3] * POWER_OF_4[2] +
        sub_chessboard_for_1[y][x + 2] * POWER_OF_4[3] +
        sub_chessboard_for_1[y][x + 1] * POWER_OF_4[4] +
        sub_chessboard_for_1[y][x - 1] * POWER_OF_4[5] +
        sub_chessboard_for_1[y][x - 2] * POWER_OF_4[6] +
        sub_chessboard_for_1[y][x - 3] * POWER_OF_4[7] +
        sub_chessboard_for_1[y][x - 4] * POWER_OF_4[8] +
        sub_chessboard_for_1[y][x - 5] * POWER_OF_4[9]
        ] +
        save_value_for_find_road
        [
            sub_chessboard_for_1[y + 5][x + 5] * POWER_OF_4[0] +
            sub_chessboard_for_1[y + 4][x + 4] * POWER_OF_4[1] +
        sub_chessboard_for_1[y + 3][x + 3] * POWER_OF_4[2] +
        sub_chessboard_for_1[y + 2][x + 2] * POWER_OF_4[3] +
        sub_chessboard_for_1[y + 1][x + 1] * POWER_OF_4[4] +
        sub_chessboard_for_1[y - 1][x - 1] * POWER_OF_4[5] +
        sub_chessboard_for_1[y - 2][x - 2] * POWER_OF_4[6] +
        sub_chessboard_for_1[y - 3][x - 3] * POWER_OF_4[7] +
        sub_chessboard_for_1[y - 4][x - 4] * POWER_OF_4[8] +
        sub_chessboard_for_1[y - 5][x - 5] * POWER_OF_4[9]
        ] +
        save_value_for_find_road
        [
            sub_chessboard_for_1[y - 5][x + 5] * POWER_OF_4[0] +
            sub_chessboard_for_1[y - 4][x + 4] * POWER_OF_4[1] +
        sub_chessboard_for_1[y - 3][x + 3] * POWER_OF_4[2] +
        sub_chessboard_for_1[y - 2][x + 2] * POWER_OF_4[3] +
        sub_chessboard_for_1[y - 1][x + 1] * POWER_OF_4[4] +
        sub_chessboard_for_1[y + 1][x - 1] * POWER_OF_4[5] +
        sub_chessboard_for_1[y + 2][x - 2] * POWER_OF_4[6] +
        sub_chessboard_for_1[y + 3][x - 3] * POWER_OF_4[7] +
        sub_chessboard_for_1[y + 4][x - 4] * POWER_OF_4[8] +
        sub_chessboard_for_1[y + 5][x - 5] * POWER_OF_4[9]
        ] +
        save_value_for_find_road
        [
            sub_chessboard_for_1[y + 5][x] * POWER_OF_4[0] +
            sub_chessboard_for_1[y + 4][x] * POWER_OF_4[1] +
        sub_chessboard_for_1[y + 3][x] * POWER_OF_4[2] +
        sub_chessboard_for_1[y + 2][x] * POWER_OF_4[3] +
        sub_chessboard_for_1[y + 1][x] * POWER_OF_4[4] +
        sub_chessboard_for_1[y - 1][x] * POWER_OF_4[5] +
        sub_chessboard_for_1[y - 2][x] * POWER_OF_4[6] +
        sub_chessboard_for_1[y - 3][x] * POWER_OF_4[7] +
        sub_chessboard_for_1[y - 4][x] * POWER_OF_4[8] +
        sub_chessboard_for_1[y - 5][x] * POWER_OF_4[9]
        ];
}

int Load_Value_for_Find_Road_2(int y, int x, int chess_type, int** chessboard_p) {
    y += 5;
    x += 5;
    return save_value_for_find_road
        [
            sub_chessboard_for_2[y][x + 5] * POWER_OF_4[0] +
            sub_chessboard_for_2[y][x + 4] * POWER_OF_4[1] +
        sub_chessboard_for_2[y][x + 3] * POWER_OF_4[2] +
        sub_chessboard_for_2[y][x + 2] * POWER_OF_4[3] +
        sub_chessboard_for_2[y][x + 1] * POWER_OF_4[4] +
        sub_chessboard_for_2[y][x - 1] * POWER_OF_4[5] +
        sub_chessboard_for_2[y][x - 2] * POWER_OF_4[6] +
        sub_chessboard_for_2[y][x - 3] * POWER_OF_4[7] +
        sub_chessboard_for_2[y][x - 4] * POWER_OF_4[8] +
        sub_chessboard_for_2[y][x - 5] * POWER_OF_4[9]
        ] +
        save_value_for_find_road
        [
            sub_chessboard_for_2[y + 5][x + 5] * POWER_OF_4[0] +
            sub_chessboard_for_2[y + 4][x + 4] * POWER_OF_4[1] +
        sub_chessboard_for_2[y + 3][x + 3] * POWER_OF_4[2] +
        sub_chessboard_for_2[y + 2][x + 2] * POWER_OF_4[3] +
        sub_chessboard_for_2[y + 1][x + 1] * POWER_OF_4[4] +
        sub_chessboard_for_2[y - 1][x - 1] * POWER_OF_4[5] +
        sub_chessboard_for_2[y - 2][x - 2] * POWER_OF_4[6] +
        sub_chessboard_for_2[y - 3][x - 3] * POWER_OF_4[7] +
        sub_chessboard_for_2[y - 4][x - 4] * POWER_OF_4[8] +
        sub_chessboard_for_2[y - 5][x - 5] * POWER_OF_4[9]
        ] +
        save_value_for_find_road
        [
            sub_chessboard_for_2[y - 5][x + 5] * POWER_OF_4[0] +
            sub_chessboard_for_2[y - 4][x + 4] * POWER_OF_4[1] +
        sub_chessboard_for_2[y - 3][x + 3] * POWER_OF_4[2] +
        sub_chessboard_for_2[y - 2][x + 2] * POWER_OF_4[3] +
        sub_chessboard_for_2[y - 1][x + 1] * POWER_OF_4[4] +
        sub_chessboard_for_2[y + 1][x - 1] * POWER_OF_4[5] +
        sub_chessboard_for_2[y + 2][x - 2] * POWER_OF_4[6] +
        sub_chessboard_for_2[y + 3][x - 3] * POWER_OF_4[7] +
        sub_chessboard_for_2[y + 4][x - 4] * POWER_OF_4[8] +
        sub_chessboard_for_2[y + 5][x - 5] * POWER_OF_4[9]
        ] +
        save_value_for_find_road
        [
            sub_chessboard_for_2[y + 5][x] * POWER_OF_4[0] +
            sub_chessboard_for_2[y + 4][x] * POWER_OF_4[1] +
        sub_chessboard_for_2[y + 3][x] * POWER_OF_4[2] +
        sub_chessboard_for_2[y + 2][x] * POWER_OF_4[3] +
        sub_chessboard_for_2[y + 1][x] * POWER_OF_4[4] +
        sub_chessboard_for_2[y - 1][x] * POWER_OF_4[5] +
        sub_chessboard_for_2[y - 2][x] * POWER_OF_4[6] +
        sub_chessboard_for_2[y - 3][x] * POWER_OF_4[7] +
        sub_chessboard_for_2[y - 4][x] * POWER_OF_4[8] +
        sub_chessboard_for_2[y - 5][x] * POWER_OF_4[9]
        ];
}

int Find_Value_Dir_Unit_test_for_1(int* chessboard, int chess_long, int x , int i) {
    int transed_chess[11];
    for (int i = 0; i < 11; i++) {
        if (chessboard[i] == 3) {
            transed_chess[i] = 2;
        }
        else {
            transed_chess[i] = chessboard[i];
        }
    }
    for (int row_number = 0; row_number < TYPE_CONUT; row_number++) {

        for (int pos = 0; pos < value_type[row_number][1]; pos++) {
            int is_same = true;
            for (int k = -pos; k < value_type[row_number][1] - pos; k++) {

                    if (transed_chess[x + i * k] != value_type[row_number][2 + k + pos]) {
                        is_same = false;
                        break;
                    }    
            }

            if (is_same) {

                return value_type[row_number][0];

            }
        }
    }
    return 0;
}
int Find_Value_Dir_Unit_test_for_2(int* chessboard, int chess_long, int x, int i) {
    int transed_chess[11];
    for (int i = 0; i < 11; i++) {
        if (chessboard[i] == 3) {
            transed_chess[i] = 1;
        }
        else {
            transed_chess[i] = chessboard[i];
        }
    }
    for (int row_number = 0; row_number < TYPE_CONUT; row_number++) {

        for (int pos = 0; pos < value_type[row_number][1]; pos++) {
            int is_same = true;
            for (int k = -pos; k < value_type[row_number][1] - pos; k++) {
         
                if (transed_chess[x + i * k] != value_type_back[row_number][2 + k + pos]) {
                    is_same = false;
                    break;
                }

            }

            if (is_same) {

                return value_type[row_number][0];

            }
        }
    }
    return 0;
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

                            if (chessboard[y + i * k][x + j * k] != value_type_back[row_number][2 + k + pos]) {
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
