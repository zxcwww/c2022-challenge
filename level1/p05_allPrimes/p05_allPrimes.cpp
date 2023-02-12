
#include <stdio.h>
#include <time.h>

int main()
{
	 
	 clock_t start = clock();

	 for (int i = 2; i < 1001; i++)
	 {
		 int is_prime = 1;
		 for (int j = 2; j < i/j+1; j++)
		 {
			 if (i % j == 0)
			 {
				 is_prime = 0;
				 break;
			 }

		 }
		 if (is_prime)
		 {
			 printf("%d\n", i);
		 }
	 }
	

	 printf("using_time=%f",(double)((clock()-start)*1000/CLOCKS_PER_SEC));

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
