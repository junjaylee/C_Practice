#include <stdio.h>

//void sort(int a[], int n);
void sort2(int a[], int n);

int main()
{
   int a[] = {1,9,4,2,6,5,3,7,8,0};
   //sort(a,10);
   sort2(a, 10);

   for (int i = 0; i < 10; ++i)
   {
   	printf("%d ",a[i]);
   }

   return 1;
}

void sort(int a[],int n)
{
	int temp;
    for(int i=0; i<n-1; i++)
    {
       for(int j=0; j<n-1-i; j++)
       {
	       if(a[j] < a[j+1])
	       {
	             temp = a[j];
	             a[j] = a[j+1];
	             a[j+1] = temp;
	       }
       }
     }
}

void sort2(int a[], int n)
{
	int temp;
    for (int i = 0; i < n-1; ++i)
    {
    	int minIndex = i;
    	for (int j = i+1; j < n; ++j)
    	{
    		if (a[minIndex] > a[j])
    		{
    			minIndex = j;
    		}
    	}
    	if (minIndex != i)
    	{
    		temp = a[minIndex];
    		a[minIndex] = a[i];
    		a[i] = temp;
    	}
    }
}

