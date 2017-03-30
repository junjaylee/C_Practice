#include <stdio.h>
#define N 7

int main()
{
    for(int i=0; i<N; i++)
    {
       for(int j=0; j<N; j++)
       {
           if(i==(N/2))
           {
              for(int k=0; k<i; k++)
              {
                 printf(" ");
              }
              printf("$");
              break;
           }
           else if((i ==j) || (i+j == N-1))
           {
              printf("$");
           }
           else printf(" ");
       }
       printf("\n");
    }

    printf("\n");
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            printf("%d*%d=%2d  ", i+1, j+1, (i+1)*(j+1));
        }
        printf("\n");
    }   

   printf("\n");
   for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(j<=i)
            {
                printf("%d*%d=%2d  ", i+1, j+1, (i+1)*(j+1));
            }
        }
        printf("\n");
    }   
    
    printf("\n");
    for(int i=0; i<9; i++)
    {
        for(int j=9; j>0; j--)
        {
            printf("%d*%d=%2d  ", i+1, j, (i+1)*j);
        }
        printf("\n");
    }

    printf("\n");
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(j>=8-i)
            {
                printf("%d*%d=%2d  ", i+1, j+1, (i+1)*(j+1));
            }
        }
        printf("\n");
    }

    printf("\n");
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(j>=8-i)
            {
                printf("%d*%d=%2d  ", i+1, j+1, (i+1)*(j+1));
            }
            else 
            {
                printf("        ");
            }
        }
        printf("\n");
    }

    printf("\n");
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(j>=8-i)
            {
                printf("%d*%d=%2d  ", i+1, (9-j), (i+1)*(9-j));
            }
            else
            {
                printf("        ");
            }
        }
        printf("\n");
    }

   return 0;
}
