
#include <stdio.h>
void hanor(int i, char start, char end);
int main()
{
    hanor(64, 'A', 'B');
}

//64!: a2b
//=63!:a2c+64:a2b+63!:c2b

void hanor(int i, char start,char end) {
    if (i == 1)
    {

        printf("%c->%c\n", start, end);
    }
    else {
        hanor(i - 1, start, 'A' + 'B' + 'C' - start - end);
        printf("%c->%c\n", start, end);
        hanor(i - 1, 'A' + 'B' + 'C' - start - end, end);

    }
}