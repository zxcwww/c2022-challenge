
#include <stdio.h>
#include <time.h>

int is_ok(int goal);

int prime[100];
int mark = 0;

int main()
{


	for (int i = 2; i < 101; i++)
	{
		int is_prime = 1;
		for (int j = 2; j < i / j + 1; j++)
		{
			if (i % j == 0)
			{
				is_prime = 0;
				break;
			}

		}
		if (is_prime)
		{
			prime[mark] = i;
			mark++;
		}
	}

	int ok = 1;
	for (int goal = 6; goal < 101; goal++)
	{
		if (!is_ok(goal)) 
		{
			
			ok = 0;
		}
		
	}
	if (ok) {
		printf("is_ok");
	}
	else
	{
		printf("is_not_ok");
	}
	
	 
} 
int is_ok(int goal) {
	for (int i =0; i < mark; i++)
	{
		for (int j = i; j < mark; j++)
		{
			for (int k = j; k < mark; k++)
			{
				if (prime[i] + prime[j] + prime[k] == goal) {
					return 1;
				}
			}
		}
	}
	return 0;
}
