
#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

void Encrypt();
void Decrypt();
char input[1000];

int main()
{
	printf("input '1' to encrypt , input '2' to decrypt\n");

	int which_mode;

	scanf_s("%d", &which_mode);

	getchar();
	if (which_mode == 1)
	{
		printf("plese input what you want to encrypt\n");

		gets_s(input);

		Encrypt();

		
	}
	else
	{
		printf("plese input what you want to decrypt\n");

		gets_s(input);

		Decrypt();

	}



	for (int i = 0; 1; i++)
	{
		if (input[i] == '\0')
		{
			break;
		}
		else
		{
			printf("%c", input[i]);
		}
	}
}
void Encrypt()
{
	char save[1000];

	srand((unsigned)time(NULL));
	
	for (int i = 0; 1; i++) {
		if (input[i] == '\0') {
			save[i * 2] = '\0';
			break;
		}
		else {
			input[i] -= 32;
			if (input[i] <2) {
				save[i * 2] = rand() % (input[i]+60) +33;
				save[i * 2 + 1] = input[i]+130 - save[i * 2];
			}
			else {

				save[i * 2] = rand() % (input[i]-2)+1;
				save[i * 2 + 1] = input[i] - save[i * 2];
			}
		}
	}

	for (int i = 0; 1; i++) {
		if (save[i] == '\0') {
			input[i] = '\0';
			break;
		}
		else {
			input[i] = save[i]+32;
		}
	}
}
void Decrypt() {
	char save[1000];


	for (int i = 0; 1; i++) {
		if (input[i*2] == '\0') {
			save[i] = '\0';
			break;
		}
		else {
			if (input[i * 2] + input[i * 2 + 1] > 125 +32)
			{
				save[i] = input[i * 2] + input[i * 2 + 1] - 130 -32;
			}
			else
			save[i ] = input[i*2]+input[i * 2+1] - 32;
		}
	}

	for (int i = 0; 1; i++) {
		if (save[i] == '\0') {
			input[i] = '\0';
			break;
		}
		else {
			input[i] = save[i] ;
		}
	}
}