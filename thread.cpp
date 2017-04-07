#include <iostream>
#include <pthread.h>
using namespace std;

#define NUM_THREAD 5

void* say_hello(void* args)
{
	cout<<"hello..."<<endl;
}

int main(int argc, char const *argv[])
{
    pthread_t tids[NUM_THREAD];
    for (int i = 0; i < NUM_THREAD; ++i)
    {
    	int ret = pthread_create(&tids,NULL,say_hello,NULL);
    	if (ret!=0)
    	{
    		cout<<"pthread_create error="<<ret<<endl;
    	}
    }
    pthread_exit(NULL);
	return 0;
}