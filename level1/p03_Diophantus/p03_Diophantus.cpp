
#include <stdio.h>

int having_equal=0;

float x_number = 0;
float value = 0;



int ne_weight;

void Save(char* s);
int C2I(char* c);

int main()
{
	//char f[] = "2x=12+x+x/2";
	char f[] = "x=x/6+x/12+x/7+5+x/2+4";


	char save[10];

	
	for (int i = 0, s_i = 0; 1 ; i++,s_i++) {

		if (f[i] == '\0')
		{
			save[s_i] = '\n';
			Save(save);

			break;
			
		}
		
		if (f[i] == '=')
		{
			save[s_i] = '\n';
			s_i = 0;
			
			i++;
			Save(save);
			having_equal = 1;
		}
		else if(f[i] == '+' )
		{
			save[s_i] = '\n';
			s_i = 0;
			i++;
			Save(save);
		}
		else if( f[i] == '-') {
			save[s_i] = '\n';
			s_i = 0;
			ne_weight = -1;
			i++;
			Save(save);
		}

		ne_weight = 1;
		save[s_i] = f[i];

	}
//	printf("%f", -value / x_number );
//	printf("%f,%f\n", x_number, value);
//	printf("%f", -value / x_number + 4);

	if (-value / x_number > int(-value / x_number + 4)) {

		printf("%d", int(-value / x_number + 4) + 1);
	}
	else {
		printf("%d", int(-value / x_number + 4) );
	}
	
}

void Save(char* s) 
{
	int l = 0;
	int having_x = 0;
	int x_pos = 0;
	for (l = 0; 1; l++) {
		if (s[l] == 'x') {
			having_x = 1;
			x_pos = l;
		}
		else if (s[l] == '\n')
			break;
	}
	float value_weight;
	if (having_equal) {
		value_weight = -1;
	}
	else
	{
		value_weight = 1;
	}
	if (!having_x) {
		
		for (int i = 0; i < l; i++) {
			int w=1;
			for (int j = 0; j < i; j++) {
				w *= 10;
			}
			value += ne_weight*value_weight * w * (s[l - i -1 ]-'0');
		}
	}
	else
	{
		float x_v = 1;

		char x_s[10];
		if (x_pos != 0) {
			for (int i = 0; i < x_pos; i++) {
				x_s[i] = s[i];
			}
			x_s[x_pos] = '\n';
			x_v *= C2I(x_s);
		}
		if (x_pos != l - 1) {
			for (int i = 0; i < l-2-x_pos; i++) {
				x_s[i] = s[x_pos+2 +i];
			}
			x_s[l-x_pos-2] = '\n';
			x_v /= C2I(x_s);
		}
		x_number += ne_weight * value_weight *  x_v;

	}


}

int C2I(char* c)
{
	int sum = 0;
	int l = 0;
	for (l = 0; 1; l++) {
		if (c[l] == '\n')
			break;
	}


	for (int i = 0; i < l; i++) {
		int w = 1;
		for (int j = 0; j < i; j++) {
			w *= 10;
		}
		sum += w * (c[l - 1 - i] - '0');
	}
	return sum;
}