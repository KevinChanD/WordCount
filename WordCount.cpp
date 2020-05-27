#include <stdio.h>
#include <string.h>
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
