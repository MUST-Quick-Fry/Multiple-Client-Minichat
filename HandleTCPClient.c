#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for recv() and send() */
#include <unistd.h>     /* for close() */
#include <string.h>

void DieWithError(char *errorMessage);  /* Error handling function */

void HandleTCPClient(int clntSocket, int MAX_SIZE, int *running)
{
    char read_buf[MAX_SIZE];
    char send_buf[MAX_SIZE];            /* Buffer for echo string */
    int sendMsgSize = MAX_SIZE;                    /* Size of received message */
    int readMsgSize = MAX_SIZE;
    /* Receive message from client */
    /* Send received string and receive again until end of transmission */
    do{
        bzero(read_buf, MAX_SIZE);
        bzero(send_buf, MAX_SIZE);
        if((readMsgSize = recv(clntSocket,read_buf,MAX_SIZE,0))<0){
            DieWithError("read() failed");
        }
        if(strncmp(read_buf,"quit",4)==0){
            *running  = 0;
            return;
        }
        else{
            printf("Message from the client:%s\n",read_buf);
        }
        printf("Enter the string to the client: ");
        fgets(send_buf,MAX_SIZE,stdin);
        if(strncmp(send_buf,"quit",4) == 0){
            *running  = 0;
            return;
        }
        /* Echo message back to client */
        if ((sendMsgSize=send(clntSocket, send_buf, sendMsgSize, 0))==-1)
            DieWithError("send() failed");

        /* See if there is more data to receive */
    }while (send_buf[0]!='\n');     /* zero indicates end of transmission */

    close(clntSocket);    /* Close client socket */
}
