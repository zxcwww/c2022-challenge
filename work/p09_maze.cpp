// p09_maze.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <conio.h>

int o_y, o_x;
void Random_Pos();
void Creat_Safe_Road();
void Creat_X();
const int height = 10, width = 100;

char maze[height][width];
char safe_road[height][width];
// x:墙 ; o:出口; ' '：空白;

int your_pos_y = 0, your_pos_x = 0;
//*=you;

int main()
{

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			maze[i][j] = ' '; 
			safe_road[i][j] = 0;
		}
	}

	for (int i = 0; i < height; i++)
	{
		
			maze[i][0] = 'x';
			maze[i][width-1] = 'x';
		
	}
	for (int i = 0; i < width; i++)
	{

		maze[0][i] = 'x';
		maze[height-1][i] = 'x';

	}
	

	srand((unsigned)time(NULL));
	Random_Pos();
	Creat_Safe_Road();
	for (int i = 0; i < height*width/2; i++)
	{
		Creat_X();
	}

	while (1)
	{
		system("cls");
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == your_pos_y && j == your_pos_x)
				{
					printf("*");
				}
				else
				{
					printf("%c", maze[i][j]);
				}
			}
			printf("\n");
		}
		if (your_pos_y == o_y
			&&
			your_pos_x == o_x)
		{

			printf("YOU WIN !!!");
			break;
		}
		else
		{
			printf("// x:墙 ; o:出口; ' '：路; *：你");
		}
		

		switch (_getch())
		{
		case 72:
			if (maze[your_pos_y - 1][your_pos_x] != 'x')
			{
				your_pos_y--;
			}
			break;
		case 80:
			if (maze[your_pos_y + 1][your_pos_x] != 'x')
			{
				your_pos_y++;
			}
			break;
		case 75:
			if (maze[your_pos_y ][your_pos_x-1] != 'x')
			{
				your_pos_x--;
			}
			break;
		case 77:
			if (maze[your_pos_y ][your_pos_x+1] != 'x')
			{
				your_pos_x++;
			}
			break;
		}

		
	}
	
}

void Random_Pos()
{

	your_pos_y = rand() % (height - 2) + 1;
	your_pos_x = rand() % (width - 2) + 1;
	 o_y = rand() % (height - 2) + 1;
	o_x =rand() % (width - 2) + 1;

	if (your_pos_y - o_y <1 &&your_pos_y - o_y>-1
		&& 
		your_pos_x - o_x <1 && your_pos_x - o_x>-1)
	{
		Random_Pos();
	}
	else
	{
		maze[o_y][o_x] = 'o';
	}
}

void Creat_Safe_Road() 
{
	int safe_y = rand() % (height - 2) + 1;
	int safe_x = rand() % (width - 2) + 1;

	
		if (o_x > your_pos_x)
		{
			for (int i = your_pos_x; i < o_x+1; i++)
			{
				
				safe_road[safe_y][i] = 1;

			}

		}
		else
		{
			for (int i = o_x; i < your_pos_x+1; i++)
			{

				safe_road[safe_y][i] = 1;

			}
		}

		if (o_y > safe_y)
		{
			for (int i = safe_y; i < o_y + 1; i++)
			{

				safe_road[i][o_x] = 1;

			}

		}
		else
		{
			for (int i = o_y; i <safe_y + 1; i++)
			{

				safe_road[i][o_x] = 1;

			}
		}
		if (your_pos_y > safe_y)
		{
			for (int i = safe_y; i < your_pos_y + 1; i++)
			{

				safe_road[i][your_pos_x] =1;

			}

		}
		else
		{
			for (int i = your_pos_y; i < safe_y + 1; i++)
			{

				safe_road[i][your_pos_x] = 1;

			}
		}

	


}

void Creat_X() {
	int x_y = rand() % (height - 2) + 1;
	int x_x = rand() % (width - 2) + 1;

	if (!safe_road[x_y][x_x])
	{
		maze[x_y][x_x] = 'x';
	}
}