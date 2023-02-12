#include<stdlib.h>
#include <stdio.h>
#include<windows.h>

int main()
{
    int L = 0, R = 20;
    int pos=L;

    int touched_time = 0;

    while (true)
    {
        system("cls");
        for (int i = 0; i < pos; i++) 
        {
            printf(" ");
        }
        printf("*");

        if (!(touched_time % 2))
        {
            pos++;
        }
        else {
            pos--;
        }

        if (pos == L || pos == R)
        {
            touched_time++;
        }
        Sleep(20);
    }
   
    
}