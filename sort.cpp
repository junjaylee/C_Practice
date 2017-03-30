#include <iostream>
using namespace std;

void printData(int *arr, const int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insertSort(int *arr, const int n)  //插入排序，升序
{
	int arrTmp[n], tmp;
    arrTmp[0] = arr[0];
    for (int i = 1; i < n; ++i)
    {
    	arrTmp[i] = arr[i];
    	for (int j = i; j > 0; --j)
    	{
    		if (arrTmp[j] < arrTmp[j-1])
    	    {
    		    tmp = arrTmp[j];
    		    arrTmp[j] = arrTmp[j-1];
    		    arrTmp[j-1] = tmp;
    	    }
    	}
    }

    for (int i = 0; i < n; ++i)
    {
    	arr[i] = arrTmp[i];
    }
}

void bubbleSort(int *arr, const int n)   //冒泡，升序
{
	int tmp;

	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < n-1-i; ++j)
		{
			if (arr[j] > arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

void selectSort(int *arr, const int n) //选择，升序
{
    int k_min = 0;
    int tmp;

	for (int i = 0; i < n-1; ++i)
	{
		k_min = i;
		for (int j = i+1; j < n-i; ++j)
		{
			if (arr[j] < arr[k_min])
			{
				k_min = j;
			}
		}
		if (k_min != i)
		{
			tmp = arr[k_min];
			arr[k_min] = arr[i];
			arr[i] = tmp;
		}
	}
}

int main(int argc, const char *argv[])
{
    int arrData[] = {3,4,2,1,8,6,7,5,0,9};
    const int n = sizeof(arrData)/sizeof(*arrData);
    
    insertSort(arrData, n);
    printData(arrData, n);

    bubbleSort(arrData, n);
    printData(arrData, n);

    selectSort(arrData, n);
    printData(arrData, n);

	return 0;
}