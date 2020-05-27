// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
	int i = 0;
	int n = 0;//记录要求记录的个数
	int t = 0;//用于数据读取
	FILE *fp;
	fp = fopen_s(argv[2], "r");//以只读方式打开文件
	char buf[BUFSIZ];//建立一个缓冲区，放置文件内容
	while (!feof(fp))
	{
		if (fscanf_s(fp, "%c", &buf[t]) != 1)
			break;
		t++;
		fgetc(fp);//过滤度掉分隔符知
	}
	fclose(fp);
	if (!strcmp("-c", argv[1])) {
		printf("字符数量是%d\n", (int)strlen(buf));
	}//处理字符数
	else {
		while (i != strlen(buf))
		{
			if (buf[i] == ',' || buf[i] == ' ')
				n++;
			i++;
		}
		if (buf[i - 1] != ',') n++;
		printf("单词数量是%d\n", n);
	}//处理单词数
	return 0;
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
