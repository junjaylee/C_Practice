/*
**Fuction: int atoi(const char *nptr);
**Unicode: _wtoi();
**Usage: 1.扫描参数nptr字符串，跳过任何空白字符（通过isspace()函数检查；
         2.直到遇到数字或正负符号，开始做转换；
         3.遇到非数字或字符串结束符'\0'结束转换，并将结果返回；
         4.如果没有将nptr转换成int类型或nptr为空字符串，返回0.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char *FILEPATH = "/Volumes/Other/GitHub/C_Practice";

int main(int argc, char const *argv[])
{
	int n;
	char *str = "12345.67";
	n = atoi(str);
	printf("n=%d\n", n);

	char *a = "-123";
	char *b = "100";
	printf("len=%lu\n", strlen(b));
	printf("size=%lu\n", sizeof(*b));
	n = atoi(a) + atoi(b);
	printf("n=%d\n", n);

    //int c = getchar()-'0';
    int c = getchar();
    printf("%d\n", c);
	switch(putchar(c)-'0')
	{
		case 1:
		    printf("haha\n");
		    break;
		default:
		    printf("shabi\n");
		    break;
	}

    char *srcPath = "/Volumes/Other/GitHub/C_Practice/Data/Raw_Data.txt";
	char *desPath = "/Volumes/Other/GitHub/C_Practice/Data/ASC_Data.txt";
    FILE *fp;
    char buff[255];

    fp = fopen(srcPath, "r+");
    if (fp)
    {
    	fgets(buff, 255, fp);   //读取后，存在buff中
        printf("%s\n", buff);   //打印buff中的值

    	fprintf(fp, "test");    //写入“test”到文件
        fscanf(fp, "%s\n", buff);    //读取文件内容，存在buff中
        printf("%s\n", buff);    //打印buff的值

        fputs("fputs called!", fp);  //写入到文件
        fgets(buff, 255, fp);    //读取到buff
        printf("%s\n", buff);    //打印buff

    	fputc('A',fp);    //写入到文件
    	printf("%c\n",fgetc(fp));   //读取一个字符，输出  
    }
    else
    	printf("Error\n");
    fclose(fp);    //关闭文件
    

    FILE *fpCurr;
    char buff2[255];

    fpCurr = fopen("./test.txt", "w");

    fprintf(fpCurr, "Hello,test file!\n");
    fputs("This is testing for fputs..\n", fpCurr);
    
    fscanf(fpCurr,"%s", buff2);
    printf("%s\n", buff2);

    fgets(buff2, 255, fpCurr);
    printf("%s\n", buff2);

    fgets(buff2, 255, fpCurr);
    printf("%s\n", buff2);
    
    fclose(fpCurr);
	return 0;
}

