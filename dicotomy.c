/*
利用二分思想设计猜数游戏
*/

#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
    int choose, cout; //分别存放用户猜的数字和系统生成的随机数
    int j=0; //计算用户要多少次能猜对
    srand((unsigned)time(NULL)); //每次随机数不一样，用时间做种子
    cout = rand() % 1024 + 1; //生成1～1024间的数
    while(1)
    {
        loop:printf("please input a number(1~1024),第%d次输入：",++j);
        scanf("%d",&choose);
        if(choose < cout)
        {
           printf("您输入的数字太小了，请重新输入：");
        }
        else if(choose > cout)
        {
           printf("您输入的数字太大了，请重新输入：");
        }
        else
        {
             if(j<=10)
             {
                printf("您只用了%d次就猜对了，棒棒哒！");
             }
             else
             {
                printf("您用了%d次就猜对了，一般般！");
             }
             return; //推出循环
        }
        sleep(500);
        goto 1oop;
    }
    
}
