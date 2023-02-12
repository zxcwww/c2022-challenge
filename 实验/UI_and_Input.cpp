#include<stdio.h>
#include<graphics.h>
#include"find_action.h"
#include"UI_and_Input.h"
#include<string>
const int height = 800, width = 800;
const int width_of_line = 5;
int now_step=0;
ExMessage  *m;
void Show_Arrow_2D(int** arrow_2D, int chess_long) {
	
	initgraph(height, width);
	setfillcolor(HSLtoRGB(45, 0.8, 0.5));
	solidrectangle(0, 0, height, width);
	MoveWindow(GetHWnd(), 0,0, width + 15, height+40, false);
	setfillcolor(BLACK);
	for (int i = 0; i < chess_long + 1; i++) {
		solidrectangle(i * height / chess_long - width_of_line, 0, i * height / chess_long + width_of_line, height);
		solidrectangle(0, i * height / chess_long - width_of_line, width, i * height / chess_long + width_of_line);
	}


	for (int i = 0; i < chess_long; i++) {
		for (int j = 0; j < chess_long; j++) {
			switch (arrow_2D[i][j]) {
			case 1:
				setfillcolor(BLACK);

				solidcircle((j+1) * width / chess_long-0.5* width / chess_long, (i+1) * height / chess_long - 0.5 * height / chess_long, height / chess_long/2 - width_of_line);
				


				break;
			case 2:
				setfillcolor(WHITE);
				solidcircle((j + 1) * width / chess_long - 0.5 * width / chess_long, (i + 1) * height / chess_long - 0.5 * height / chess_long, height / chess_long/2 - width_of_line);
				
				break;
			}


		}

	}
}
void Add_Chess(int x, int y,int side,int chess_long) {
	now_step++;

	TCHAR s[5];
	switch (side) {
	case 1:
		setfillcolor(BLACK);
		solidcircle((x + 1) * width / chess_long - 0.5 * width / chess_long, (y + 1) * height / chess_long - 0.5 * height / chess_long, height / chess_long / 2 - width_of_line);
		settextcolor(WHITE);

		Number_To_String(now_step, s);
		outtextxy((x + 1) * width / chess_long - 0.5 * width / chess_long, (y + 1) * height / chess_long - 0.5 * height / chess_long, s);
		break;
	case 2:
		setfillcolor(WHITE);
		solidcircle((x + 1) * width / chess_long - 0.5 * width / chess_long, (y + 1) * height / chess_long - 0.5 * height / chess_long, height / chess_long / 2 - width_of_line);
		settextcolor(YELLOW);

		Number_To_String(now_step, s);
		outtextxy((x + 1) * width / chess_long - 0.5 * width / chess_long, (y + 1) * height / chess_long - 0.5 * height / chess_long, s);
		break;
	}
}

bool Is_Input() {
	ExMessage m = getmessage(EX_MOUSE | EX_KEY);

	switch (m.message)
	{


	case WM_LBUTTONDOWN:

		return true;
	
	default:
		if (m.ctrl)
			return true;


	}
	return false;
}
pos_2D Get_Mouse_Input(int chess_long) {

	ExMessage m = getmessage(EX_MOUSE);
	pos_2D pos;
	pos.x = m.x * chess_long / width;
	pos.y = m.y * chess_long / height ;
	return pos;
}
void Number_To_String(int number, TCHAR *tc) {
	char s[5];
	sprintf_s(s, "%d", now_step);
	for (int i = 0;; i++) {
		
			tc[i] = s[i];
			if (s[i] == '\0')
				break;
			
	}
}
