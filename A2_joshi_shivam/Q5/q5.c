//shivam joshi
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
void *quartercompare(void *arg);
int sum ,count;
int a[20];
int b[20];
int i=0,j=5,k=0;
int main(int argc, char **argv)
{
    for(int i=0;i<20;i++)
    {  
        a[i]=i*2;
    }
    for(int i=0;i<20;i++)
    {  
        b[i]=i*3;
    }
	    pthread_t thread1, thread2,thread3,thread4;
	    pthread_create(&thread1, NULL, quartercompare, NULL);
	    pthread_create(&thread2, NULL, quartercompare, NULL);
	    pthread_create(&thread3, NULL, quartercompare, NULL);
	    pthread_create(&thread4, NULL, quartercompare, NULL);
        
	   sleep(5);//This is to ensure  that aa threads are created by putting main function in wait 
                    // else there will be possibility that none of thread will get executed
        printf("exit:");

	
	
}

void *quartercompare(void *arg)
{
    printf("\n Threadid: %ld",pthread_self());
   
	while(i<j)
	{
	   for(k=0 ;k<20;k++)
	   {
	       if(a[i]==b[k]){
	       printf("\t%d",a[i]);
	       k++;
	       break;
	       }
	   }
	   i++;
	   
	}
	
	j+=5;
	
	pthread_exit(NULL);
}
