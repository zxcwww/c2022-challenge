// p09_maze.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <conio.h>


const int height = 10, width = 10;

int step = 0;
int box_y[10], box_x[10];
char maze[height][width];
int box_number;
// x:墙 ; o:目标位置; ' '：空白;B:箱子;
void Try_Move(int y_change, int x_change);
int your_pos_y = 0, your_pos_x = 0;
//*=you;
const char* Translate_map(int level);
const char* Translate_step(int level);

int main()
{
	FILE* fp;
	FILE* fp2;
	int level;
	printf("chose leve: 1 or 2\n");
	scanf_s("%d", &level);

	fopen_s(&fp, Translate_map(level), "r");
	fopen_s(&fp2, Translate_step(level), "r+");
	

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			maze[i][j] = ' ';
		}
	}
	
	
	char best_step[6];

	fgets(best_step, 6, fp2);

	for (int i = 0; i < height; i++) {
		fgets(maze[i], 10, fp);
		for (int j = 0; j <width; j++) {
			if (maze[i][j] == '*') {
				maze[i][j] = ' ';
				your_pos_y = i;
				your_pos_x = j;
			}
			else if(maze[i][j] == 'B') {
				maze[i][j] = ' ';
				box_y[box_number] = i;
				box_x[box_number] = j;
				box_number++;
			}
		}
	}


	
	
	

	while (1)
	{
		system("cls");
		printf("best_step:");
		for (int i = 0; i < 6; i++) {

			printf("%c", best_step[i]);
			if (best_step[i] == '\n') {
				break;
			}
		}
		printf("now_step:%d\n",step);
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int is_box = 0;
				if (i == your_pos_y && j == your_pos_x)
				{
					printf("*");
				}
				else {
					for (int k = 0; k < box_number; k++) {
						if (i == box_y[k] && j == box_x[k])
						{
							printf("B");
							is_box = 1;
							break;
						}
					}
				
				if(!is_box) {
					printf("%c", maze[i][j]);
					if (maze[i][j] == '\n') {
						break;
					}
				}
				}

				
				
			}
		}

		int box_is_ok = 1;
		for (int i = 0; i < box_number; i++)
		{
			if (maze[box_y[i]][box_x[i]] != 'o') {
				box_is_ok = 0;
			}
		}
		if (box_is_ok)
		{

			printf("YOU WIN !!!");
			if (best_step[1] == '\n') {
				if (step < best_step[0] - 48)
				{
					fclose(fp2);
					fopen_s(&fp2, Translate_step(level), "w");
					
					fputc(step + '0', fp2);
					fputc('\n', fp2);
				}
			}
			else if (best_step[2] == '\n') {
				if (step < (best_step[0] - 48)*10+ (best_step[1] - 48))
				{
					fclose(fp2);
					fopen_s(&fp2, Translate_step(level), "w");

					fputc((step-(step % 10 ))/10+ '0', fp2);
					fputc(step%10 + '0', fp2);

					fputc('\n', fp2);
				}
			}
			break;
		}


		switch (_getch())
		{
		case 72:
			Try_Move(-1, 0);
			break;
		case 80:
			Try_Move(1, 0);
			break;
		case 75:
			Try_Move(0, -1);
			break;
		case 77:
			Try_Move(0, 1);
			break;
		}


	}
	
}

void Try_Move(int y_change,int x_change) {
	if (maze[your_pos_y + y_change][your_pos_x + x_change] != 'x')
	{
		int is_box = 0;
		int i;
		for (i = 0; i < box_number; i++) {
			if (your_pos_y + y_change == box_y[i] && your_pos_x + x_change == box_x[i])
			{

				is_box = 1;
				break;
			}
		}

		if (is_box) {

			if (maze[your_pos_y + y_change*2][your_pos_x + x_change*2] != 'x')
			{
				your_pos_y += y_change;;
				box_y[i] += y_change;
				your_pos_x += x_change;;
				box_x[i] += x_change;
				step++;
			}
		}
		else
		{
			your_pos_y += y_change;
			your_pos_x += x_change;
			step++;
		}


	}

}

const char* Translate_map(int level) {
	switch (level)
	{
	case 1:return "1_map";

	case 2:return "2_map";

	default:return "1_map";
	}
}
const char* Translate_step(int level) {
	switch (level)
	{
	case 1:return "1_step";

	case 2:return "2_step";

	default:return "1_step";
	}
}