
#include <stdio.h>
#include<windows.h>
#include <conio.h>


int C2I(char *c);
void I2C(int i, char* c);
int Is_Same(char* a, char* b);
void Copy_File(const char* a, const char* b);
void Z2N(char* c);
int main()
{
	while (1) {
		printf("1: 显示存货列表\n");
		printf("2: 入库\n");
		printf("3: 出库\n");
		printf("4：退出程序\n");

		int input;
		scanf_s("%d", &input);

		system("cls");

		char name[100];
		int number;

		FILE* fp;
		FILE* fp_save;
		fopen_s(&fp, "list", "r");

		char having_c[10];
		fgets(having_c, 6, fp);
		int having_i = C2I(having_c);

		int end = 0;
		int i = 0;

		int having = 0;
		char c[10];
		char save[100];
		int enough = 1;
		int should_cut = 0;

		switch (input)
		{
		case 1:
			printf("名称            数量\n");
			for (int i = 0; i < having_i; i++) {
				char save[100];
				fgets(save, 100, fp);
				for (int i = 0; 1; i++) {
					if (save[i] == '\n')
					{ save[i] = '\0';
					break;
					}
						
				}
				printf("%s        ", save);
				fgets(save, 100, fp);
				printf("%s\n", save);

			}

			fclose(fp);
			break;
		case 2:
			printf("请输入入库物品的名称\n");
			
			gets_s(c);
			gets_s(name);
			printf("请输入要入库的数量\nps:库存上限99\n");
			scanf_s("%d", &number);

			Z2N(name);

			for (i = 0; i < having_i; i++) {
				
				fgets(save, 100, fp);
				if (Is_Same(save, name))
				{
					fgets(save, 100, fp);
					having = 1;
					break;
				}
				fgets(save, 100, fp);

			}
			
			fopen_s(&fp_save, "list_save", "w");

			fclose(fp);
			fopen_s(&fp, "list", "r");



			fgets(having_c, 6, fp);
			char save[100];
			if (having) {
				for (int k = 0; 1; k++) {
					fputc(having_c[k], fp_save);
					if (having_c[k] == '\n') {
						break;
					}

				}

				for (int j = 0; j < having_i; j++) {

					fgets(save, 100, fp);

					for (int k = 0; 1; k++) {
						fputc(save[k], fp_save);
						if (save[k] == '\n') {
							break;
						}

					}
					fgets(save, 100, fp);
					if (j == i) {
						int s = C2I(save);
						s += number;
						I2C(s, save);
					}
					for (int k = 0; 1; k++) {
						fputc(save[k], fp_save);
						if (save[k] == '\n') {
							break;
						}

					}
				}
			}
			else
			{
				int save_having = C2I(having_c);
				save_having++;
				I2C(save_having, having_c);

				for (int k = 0; 1; k++) {
					fputc(having_c[k], fp_save);
					if (having_c[k] == '\n') {
						break;
					}

				}
				for (int j = 0; j < having_i; j++) {

					fgets(save, 100, fp);

					for (int k = 0; 1; k++) {
						fputc(save[k], fp_save);
						if (save[k] == '\n') {
							break;
						}

					}
					fgets(save, 100, fp);

					for (int k = 0; 1; k++) {
						fputc(save[k], fp_save);
						if (save[k] == '\n') {
							break;
						}

					}
				}
				for (int k = 0; 1; k++) {
					
					fputc(name[k], fp_save);
					if (name[k] == '\n') {
						break;
					}

				}

				char save_number[30];
				I2C(number, save_number);
				for (int k = 0; 1; k++) {
					fputc(save_number[k], fp_save);
					if (save_number[k] == '\n') {
						break;
					}

				}
			}



			fclose(fp);
			fclose(fp_save);

			remove("list");
			rename("list_save", "list");




			break;
		case 3:
			printf("请输入出库物品的名称\n");
			gets_s(c);
			gets_s(name);
			printf("请输入要出库的数量\nps:库存上限99\n");
			scanf_s("%d", &number);
			Z2N(name);

			number = -number;

			
			for (i = 0; i < having_i; i++) {
				char save[100];
				fgets(save, 100, fp);
				if (Is_Same(save, name))
				{
					fgets(save, 100, fp);
					int n = C2I(save);
					if (n + number < 0)
					{
						printf("库中物品不足\n");
						
						enough = 0;
						
					}
					else if (n + number == 0) {
						should_cut = 1;
					}
					having = 1;
					break;
				}
				fgets(save, 100, fp);

			}
			
			fopen_s(&fp_save, "list_save", "w");

			fclose(fp);
			fopen_s(&fp, "list", "r");



			fgets(having_c, 6, fp);
			
			
			if (having) {
				if (!enough)
					break;
				if (!should_cut) {
					for (int k = 0; 1; k++) {

						fputc(having_c[k], fp_save);
						if (having_c[k] == '\n') {
							break;
						}

					}

					for (int j = 0; j < having_i; j++) {

						fgets(save, 100, fp);

						for (int k = 0; 1; k++) {
							fputc(save[k], fp_save);
							if (save[k] == '\n') {
								break;
							}

						}
						fgets(save, 100, fp);
						if (j == i) {
							int s = C2I(save);
							s += number;
							I2C(s, save);
						}
						for (int k = 0; 1; k++) {
							fputc(save[k], fp_save);
							if (save[k] == '\n') {
								break;
							}

						}
					}

				}

				else {
					int save_having = C2I(having_c);
					save_having--;
					I2C(save_having, having_c);

					for (int k = 0; 1; k++) {
						fputc(having_c[k], fp_save);
						if (having_c[k] == '\n') {
							break;
						}

					}
					for (int j = 0; j < having_i; j++) {

						if (j == i) {
							fgets(save, 100, fp);
							fgets(save, 100, fp);
							continue;
						}
							
						fgets(save, 100, fp);

						for (int k = 0; 1; k++) {
							fputc(save[k], fp_save);
							if (save[k] == '\n') {
								break;
							}

						}
						fgets(save, 100, fp);

						for (int k = 0; 1; k++) {
							fputc(save[k], fp_save);
							if (save[k] == '\n') {
								break;
							}

						}
					}

					
				}
			}
			else
			{
				printf("库中无此物品\n");
				fclose(fp);
				fclose(fp_save);
				break;
			}



			fclose(fp);
			fclose(fp_save);

			remove("list");
			rename("list_save", "list");




			break;
		case 4:
			fclose(fp);
			end = 1;
			break;

		}

		if (end) {
			break;
		}
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
void I2C(int i, char* c) {

	int size = 0;
	for (int j = 10; 1; j *= 10, size++) {
		if (j > i)
			break;
	}
	c[size + 1] = '\n';
	for (; size > -1; size--) {
		c[size] = i % 10 +'0';
		i -= i % 10;
		i /= 10;


	}
}
void Z2N(char* c) {
	for (int i = 0; 1; i++) {
		if (c[i] == '\0') {
			c[i] ='\n';
			c[i + 1] = '\0';
			break;
		}
	}
}
int Is_Same(char* a, char* b) {
	for (int i = 0; 1; i++) {
		if (a[i] != b[i]) 
			return 0;
		
		else if (a[i] == '\n' || a[i]=='\0')
			return 1;
	}
}

void Copy_File(const char* a, const char* b)
{
	
	char save[1000];
	FILE* fp, *fp_save;

	fopen_s(&fp, a, "r");
	fopen_s(&fp_save, b, "w");

	char having_c[10];
	fgets(having_c, 6, fp);
	int having_i = C2I(having_c);



	for (int k = 0; 1; k++) {
		fputc(having_c[k], fp_save);
		if (having_c[k] == '\n') {
			break;
		}

	}
	for (int j = 0; j < having_i; j++) {

		fgets(save, 100, fp);

		
		for (int k = 0; 1; k++) {
			
			fputc(save[k], fp_save);
			if (save[k] == '\n') {
				break;
			}
			

		}

		fgets(save, 100, fp);


		for (int k = 0; 1; k++) {

			fputc(save[k], fp_save);
			if (save[k] == '\n') {
				break;
			}


		}
	}
}