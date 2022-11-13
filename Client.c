// Client side C/C++ program to demonstrate Socket
// programming
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 1234

void show(char x[])
{
	printf("GAME LOOKS LIKE : \n");
    for(int i=0;x[i]!='\0';i++)
    {
        if(i==5 || i==11)
            printf("\n");
        else
            printf("%c",x[i]);
    }
	printf("\n");
}

void change(char a[],char b[])
{
    for(int i=0;a[i]!='\0';i++)
        if(a[i]==b[1])
		{
            a[i]=b[0];
			break;
		}
}

int main(int argc, char const* argv[])
{
	int sock = 0, valread, client_fd;
	struct sockaddr_in serv_addr;
	char* hello = "Hello from client";
	char buffer[1024] = { 0 };
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 addresses from text to binary
	// form
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
		<= 0) {
		printf(
			"\nInvalid address/ Address not supported \n");
		return -1;
	}

	if ((client_fd
		= connect(sock, (struct sockaddr*)&serv_addr,
				sizeof(serv_addr)))
		< 0) {
		printf("\nConnection Failed \n");
		return -1;
	}

	valread = read(sock, buffer, 1024);
	show(buffer);

	printf("ENTER (X/0) : ");
	char a1,a2;
	scanf("%c",&a1);
	fflush(stdin);
	printf("ENTER THE POSITION (0-8) : ");
	scanf("%c",&a2);
	char b[5];
	b[0]=a1;
	b[1]=a2;
	change(buffer,b);

	hello=buffer;
	send(sock, hello, strlen(hello), 0);
	// closing the connected socket
	close(client_fd);
	return 0;
}
