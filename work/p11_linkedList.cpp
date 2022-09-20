
#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
int main()
{
	
	int list[1000];
	int list_p[1000];

	srand((unsigned)time(NULL));

	for (int i = 0; i < 1000; i++) {
		list_p[i] = -1;
	}
	int now_pos = 0;
	for (int i = 0; i < 30; i++) {
		int j = rand() % 1000;
		if (list_p[j] == -1) {
			list[j]= rand() % 6;
			list_p[now_pos] = j;
			now_pos = j;
		}
	}
   

	now_pos = 0;
	while (true)
	{

		now_pos = list_p[now_pos];
		if (now_pos == -1)
		{
			break;
		}
		printf("%d\n", list[now_pos]);
	}

	int last_link;
	int last_last_link;

	now_pos = 0;
	last_last_link = list_p[now_pos];

	last_link = list_p[last_last_link];

	now_pos = list_p[last_link];

	list_p[last_last_link] = -1;

	while (true)
	{
		list_p[last_link] = last_last_link;

		last_last_link = last_link;
		last_link = now_pos;
		now_pos = list_p[now_pos];

		list_p[last_link] = last_link;
		if (now_pos == -1)
		{
			break;
		}
	}
	list_p[last_link] = last_last_link;
	list_p[0] = last_link;

	printf("_______________________\n");
	now_pos = 0;
	int have_found = 0;
	while (true)
	{

		now_pos = list_p[now_pos];
		if (now_pos == -1)
		{
			break;
		}
		if (list[now_pos] == 5) {
			printf("%d\n", now_pos);
			have_found = 1;
		}
	}
	if (!have_found)
	{
		printf("-1");
	}

}
