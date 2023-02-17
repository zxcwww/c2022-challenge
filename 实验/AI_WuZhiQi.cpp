
#include < stdlib.h >
#include<stdio.h>
#include<Windows.h>
#include <io.h>
#include<graphics.h>

#include"find_value.h"
#include"find_action.h"
#include"UI_and_Input.h"
#include<random>
#include<time.h>
void Ai_Player_Play(int ai_1);
void Player_Ai_Play(int ai_1);
void Two_Ai_Play(int ai_1, int ai_2);
void CMD_Input();
const int chess_long = 15;
int ai_side = 2, player_side = 1;
pos_2D last_pos={8,8};
int** chessboard_p;
int chessboard[chess_long][chess_long] = {

    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};


bool is_start = false;


int main()
{

    if (_access("save_value.txt", 4) != 0) {
        Save_Value();
    }
    if (_access("save_value_for_find_road.txt", 4) != 0) {
            Save_Value_For_Find_Road();
        }
  
        Load_Value();

    

     chessboard_p = (int**)malloc(sizeof(int*) * chess_long);
    for (int i = 0; i < chess_long; i++) {
        chessboard_p[i] = chessboard[i];
    }

    CMD_Input();
    
      Sleep(1000000);

}


void CMD_Input() {
    int get_input_1 = 0;
    int get_input_2 = 0;
    int get_input_3 = 0;


    printf("输入你的选择：\n1:和ai对战\n2:看ai打架\n");
    scanf_s("%d", &get_input_1);
    printf("输入ai_1：\n1:深度8，广度8\n2:深度10，广度8\n3:深度8，广度10\n");
    scanf_s("%d", &get_input_2);
    if (get_input_1 == 1) {

        printf("输入你是先手还是后手：\n1:先手\n2:后手\n3：随机\n");
        scanf_s("%d", &get_input_3);
    }
    else {
        printf("输入ai_2：\n1:深度8，广度8\n2:深度10，广度8\n3:深度8，广度10\n");
        scanf_s("%d", &get_input_3);
    }
    Show_Arrow_2D(chessboard_p, chess_long);

    int ai_input = 0;
    switch (get_input_2)
    {

    case 1:
        ai_input = 16;

        break;
    case 2:
        ai_input = 17;

        break;
    default:
        ai_input = 18;

        break;
    }
    int ai_input_2 = 0;
    switch (get_input_3)
    {
    case 1:
        ai_input_2 = 16;

        break;
    case 2:
        ai_input_2 = 17;

        break;
    default:
        ai_input_2 = 18;

        break;
    }
    switch (get_input_1)
    {
    case 1:
        switch (get_input_3)
        {
        case 1:
            Player_Ai_Play(ai_input);
            break;
        case 2:
            Ai_Player_Play(ai_input);

            break;
        case 3:
            srand(clock());
            if (rand() % 2 == 0)
                Player_Ai_Play(ai_input);
            else
                Ai_Player_Play(ai_input);

            break;
        }
        break;
    case 2:
        Two_Ai_Play(ai_input, ai_input_2);
        break;
    }


    Sleep(100000);
}

void Player_Ai_Play(int ai_1 ) {
    int pause_time = 500;

    while (true) {
        if (Is_Input()) {


            pos_2D pos = Get_Mouse_Input(chess_long);
            last_pos = pos;

            if (pos.x >= 0 && pos.x < chess_long && pos.y >= 0 && pos.y < chess_long) {
                if (chessboard_p[pos.y][pos.x] == 0) {
                    Change_Chessboard(pos.y,pos.x,player_side,chessboard_p);

                    Add_Chess(pos.x, pos.y, player_side, chess_long);
                    if (Find_Win(chessboard_p, chess_long, pos.x, pos.y, player_side)) {

                        outtextxy(10, 20, (LPCTSTR)L"You Win");
                        break;
                    }
                    Sleep(pause_time);
                    pos_2D pos = Find_Action(chessboard_p, chess_long, ai_side, is_start, ai_1, last_pos);
                    last_pos = pos;


                    Change_Chessboard(pos.y,pos.x,ai_side,chessboard_p);
                    Add_Chess(pos.x, pos.y, ai_side, chess_long);
                    if (Find_Win(chessboard_p, chess_long, pos.x, pos.y, ai_side)) {
                        outtextxy(10, 20, (LPCTSTR)L"Ai Win");
                        break;
                    }
                }
            }
        }
    }
}
void Ai_Player_Play(int ai_1) {
    int pause_time = 500;
    ai_side = 1;
    player_side = 2;
    is_start = true;

    Sleep(pause_time);
    pos_2D pos = Find_Action(chessboard_p, chess_long, ai_side, is_start, ai_1,last_pos);


    Change_Chessboard(pos.y,pos.x,ai_side,chessboard_p);
    Add_Chess(pos.x, pos.y, ai_side, chess_long);
    while (true) {
        if (Is_Input()) {


            pos_2D pos = Get_Mouse_Input(chess_long);
            last_pos = pos;
            if (pos.x >= 0 && pos.x < chess_long && pos.y >= 0 && pos.y < chess_long) {
                if (chessboard_p[pos.y][pos.x] == 0) {
                    Change_Chessboard(pos.y,pos.x,player_side,chessboard_p);

                    Add_Chess(pos.x, pos.y, player_side, chess_long);
                    if (Find_Win(chessboard_p, chess_long, pos.x, pos.y, player_side)) {

                        outtextxy(10, 20, (LPCTSTR)L"You Win");
                        break;
                    }
                    Sleep(pause_time);
                    pos_2D pos = Find_Action(chessboard_p, chess_long, ai_side, is_start, ai_1, last_pos);
                    last_pos = pos;

                    Change_Chessboard(pos.y,pos.x,ai_side,chessboard_p);
                    Add_Chess(pos.x, pos.y, ai_side, chess_long);
                    if (Find_Win(chessboard_p, chess_long, pos.x, pos.y, ai_side)) {
                        outtextxy(10, 20, (LPCTSTR)L"Ai Win");
                        break;
                    }
                }
            }
        }



    }

}
    
void Two_Ai_Play(int ai_1 , int ai_2 ) {
    is_start = true;
 
    int pause_time = 0;
    while (true) {
       
        Sleep(pause_time);
        pos_2D pos = Find_Action(chessboard_p, chess_long, player_side, is_start, ai_1, last_pos);
        last_pos = pos;
        Change_Chessboard(pos.y,pos.x,player_side,chessboard_p);
        Add_Chess(pos.x, pos.y, player_side, chess_long);
        if (Find_Win(chessboard_p, chess_long, pos.x, pos.y, player_side)) {
            outtextxy(10, 20, (LPCTSTR)L"Ai_1 Win");
            break;
        }
                    Sleep(pause_time);
                    pos = Find_Action(chessboard_p, chess_long, ai_side, is_start, ai_2, last_pos);
                    last_pos = pos;
                    Change_Chessboard(pos.y,pos.x,ai_side,chessboard_p);
                    Add_Chess(pos.x, pos.y, ai_side, chess_long);
                    if (Find_Win(chessboard_p, chess_long, pos.x, pos.y, ai_side)) {
                        outtextxy(10, 20, (LPCTSTR)L"Ai_2 Win");
                        break;
                    }



    }
}

