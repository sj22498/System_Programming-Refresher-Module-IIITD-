#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include<sys/wait.h>


#define PORT 4444
//shiavm joshi
int temp,count;
int main(){

	int sockfd, ret;
	 struct sockaddr_in serverAddr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	char buffer[1024];
	char reply[1024];
	pid_t childpid;
 	pthread_t thread1;
 	//char*str="Hello Welocme to XYZ Bank ";
 	//char*str1="Enter your Account number ";

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("Error in connection.\n");
		exit(1);
	}
	printf("Socket creation: success.\n");

	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");//previously we were using AnnyAddr
							    // now i have used inet_addr to give specific ip

	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("Error in binding.\n");
		exit(1);
	}
	printf("Binding to %d\n", 4444);

	if(listen(sockfd, 2) == 0){
		printf("Listening..\n");
	}else{
		printf("Error in binding.\n");
	}


	while(1){
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newSocket < 0){
			exit(1);
		}
		printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
		//send(newSocket, str, strlen(str), 0);
		//send(newSocket, str1, strlen(str1), 0);
		//printf("\nWelcome to xyz Bank ");
		//printf("\nEnter your Account Number :");
		childpid=fork();
		if(childpid  == 0){
			close(sockfd);
			count++;
			if(count==1)
			{
			    temp=childpid;  // it wont wait since its the first child
			    
			}
			else{
			    //waitpid(0,0,0);//after creation of 2nd child this wait condition will allow the exec in order
						// of child cretion i.e in the order of incoming request.
			}
			printf("\nParent id of child is %d:",getpid());
			while(1){
				read(newSocket, buffer, 1024);
				if(strcmp(buffer, "Bye") == 0){
					printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
					break;
				}else{
					
					printf("\nClient: %s\n", buffer);
					bzero(reply, sizeof(reply));
					scanf("%s", reply);
					//printf("\nserver waiting for 15 secs");
					sleep(15);
					send(newSocket, reply, strlen(reply), 0);
					bzero(buffer, sizeof(buffer));

				}
			}
			
		}
		

	}

	close(newSocket);


	return 0;
}
