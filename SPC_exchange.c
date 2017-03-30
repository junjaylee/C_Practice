#include <direct.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define num 82
char *FILEPATH = "/Volumes/Other/GitHub/C_Practice";

typedef struct data

	//01 2722841 01 0991114 16:06:37 16:06:40 1996/09/03 000003 0002 00 03(数据的结构)
	//1E EE 01 09 91 11 4E EE EE EE EE 16 06 37 16 06 40 1996 09 03 00 00 03 00 02 00 03
	char a[3];    //0-2（无用）
	char outC[7];    //3-9（主叫）
	char b[7];    //10-16（无用）
	char called[17];    //17-33（被叫）
	char startTime[9];    //34-42（开始时间）
	char endTime[9];    //43-51（结束时间）
	char date[10];    //52-61（日期）
	char c[20];    //62-81（无用）
}DATA;

void logDeal(int i, char *p);    //日志处理
void logShow();    //日志显示
void dataVarify(char *p);    //数据校验
void codeSwitch();    //码制转换,主函数
void insert(char *des, char *src, int n);    //码制转换 子函数
void changeName(char* p);    //码制转换 子函数
void heapSort();    //数据排序，主函数
void creatHeap(DATA *a, int root, int index);    //创建堆
void sort(DATA *a, int index);    //数据排序
time_t rawTime;    //日志处理 时间用的变量
struct tm *timeInfo;    //日志处理 时间用的结构体


void logDeal(int i, char *p)
{
    FILE *file;
    char filePath[100];
    char filename[30] = "/Data/Log_Data.txt";
    strcpy(filePath, FILEPATH);
    strcat(filePath, filename);  //filePath = "/Volumes/Other/GitHub/C_Practice/Data/Log_Data.txt";

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    file = fopen(filePath, "ab");
    fseek(file, 0L, 2);
    switch(i)
    {
    	case 0:
    	    fprintf(file,"%-15s\t码制转换\t已完成\t%s\r\n", p, asctime(timeInfo));
    	    break;
    	case 1:
    	    fprintf(file, "%-15s\t数据校验\t已完成\t%s\r\n", p, asctime(timeInfo));
    	    break;
    	case 2:
    	    fprintf(file, "%-15s\t数据校验\t已完成\t%s\r\n", p, asctime(timeInfo));
    	    break;
    }
    fclose(file);
}

void logShow()
{

}

/*************************************************************
/*Function: void CodeSystemTransition(char *p)
**Usage: 将BCD码的文件转码为ASCII码文件，保存在另一文件夹
**Input: p -- 需要转码的文件名的指针
**Output: 

**Called functions:
  JudgeWayIsRight, AmendPostfixOfSave, JudgeLumpOfNum, num_switch,
  SaveData,ConnectCharacterString

**Athor:
**Date:

**Modify note:
**Date:

**Version:
***************************************************************/
void CodeSystemTransition(char *p)
{
	char srcPath[N] = "/Data/Raw_Data.txt";
	char desPath[N] = "/Data/ASC_Data.txt";
    char src[100];
    char des[100];
    strcpy(src,FILEPATH);
    strcpy(des,FILEPATH);
	strcat(src,srcPath);
	strcat(des,desPath);
	
	
	if(fopen(src,"rb"))
	{
		printf("Open file failed!\n");
		return;
	}
	

}










