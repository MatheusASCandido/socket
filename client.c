/*
** client.c -- a stream socket client demo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <strings.h> // bzero()
#include <arpa/inet.h>

#define PORT "3490" // the port client will be connecting to 
#define MAX 4000
#define MAXDATASIZE 100 // max number of bytes we can get at once 

void server_client(int sockfd)
{
    char buff[MAX];
    int n;
    int opcao=0;
    for (;;) {
        bzero(buff, sizeof(buff));
        printf("\nEscolha a opção desejada : \n1-Cadastrar novo perfil\n2-Listar as pessoas formadas em um determinado curso\n3-Listar as pessoas com determinada habilidade\n4-Listar pessoas formadas em determinado ano\n5-Listar todos os perfis\n6-Consultar perfil via email\n7-Remover perfil\n8-Sair\n");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                //novo usuario
                strcat(buff,"1");
                strcat(buff,":");

                char variavel[100];
                char str[100];
                printf("Digite o Email do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);
                strcat(buff,",");
                

                printf("Digite o Nome do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);
                strcat(buff,",");
               


                printf("Digite o Sobrenome do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);
                strcat(buff,",");
              

                printf("Digite a Residência do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);
                strcat(buff,",");
                

                printf("Digite a Formação Acadêmica do usuário: ");
                char aux[100];
                fgets(aux, 100, stdin);
                fgets(str, 100, stdin);
                str[strcspn(str, "\n")] = 0;
                strcat(buff,str);
                strcat(buff,",");
               

                printf("Digite o Ano de Formação do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);
                strcat(buff,",");
                

                printf("Digite as Habilidades do usuário: ");
               
                fgets(str, 100, stdin);
                fgets(str, 100, stdin);
                strcat(buff,str);
                

                //pega as infos necessarias e vai usando o strcat pra add no buff e sempre separa com ":" cada info
                //pedir as habilidades separadas por ";" por conta do csv
                write(sockfd,buff, sizeof(buff));
                break;
            case 2: 
                // determinado curso
                strcat(buff,"2");
                strcat(buff,":");

                printf("Digite a Formação Acadêmica do usuário: ");
                fgets(str, 100, stdin);
                fgets(str, 100, stdin);
                printf("\n");
                strcat(buff,str);

                //pega as infos necessarias e vai usando o strcat pra add no buff e sempre separa com ":" cada info
                write(sockfd,buff, sizeof(buff));
                break;
            case 3: ;
                //habilidade
                strcat(buff,"3");
                strcat(buff,":");

                printf("Digite a Habilidade do usuário: ");
                fgets(str, 100, stdin);
                fgets(str, 100, stdin);
                printf("\n");
                strcat(buff,str);

                //pega as infos necessarias e vai usando o strcat pra add no buff e sempre separa com ":" cada info
                write(sockfd,buff, sizeof(buff));
                break;
            case 4: 
                //ano
                strcat(buff,"4");
                strcat(buff,":");

                printf("Digite o ano de formação do usuário: ");
                fgets(str, 100, stdin);
                fgets(str, 100, stdin);
                printf("\n");
                strcat(buff,str);

                //pega as infos necessarias e vai usando o strcat pra add no buff e sempre separa com ":" cada info
                write(sockfd,buff, sizeof(buff));
                break;
            case 5:
                //todos
                strcat(buff,"5");
                strcat(buff,":");
                //pega as infos necessarias e vai usando o strcat pra add no buff e sempre separa com ":" cada info
                write(sockfd,buff, sizeof(buff));
                break;
            case 6:
                //via email
                strcat(buff,"6");
                strcat(buff,":");


                printf("Digite o Email do usuário: ");
                fgets(str, 100, stdin);
                fgets(str, 100, stdin);
                printf("\n");
                strcat(buff,str);

                //pega as infos necessarias e vai usando o strcat pra add no buff e sempre separa com ":" cada info
                write(sockfd,buff, sizeof(buff));
                break;
            case 7:
                strcat(buff,"7");
                strcat(buff,":");

                printf("Digite o Email do usuário: ");
                fgets(str, 100, stdin);
                fgets(str, 100, stdin);
                printf("\n");
                strcat(buff,str);

                //pega as infos necessarias e vai usando o strcat pra add no buff e sempre separa com ":" cada info
                write(sockfd,buff, sizeof(buff));
                break;
            case 8:
                write(sockfd, "exit", 5);
                break;
            
        }
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s\n", buff);
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Client Exit...\n");
            break;
       }
        }
        
        
}

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char *argv[])
{
	int sockfd, numbytes;  
	char buf[MAXDATASIZE];
	struct addrinfo hints, *servinfo, *p;
	int rv;
	char s[INET6_ADDRSTRLEN];

	if (argc != 2) {
	    fprintf(stderr,"usage: client hostname\n");
	    exit(1);
	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((rv = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and connect to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("client: socket");
			continue;
		}

		if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			perror("client: connect");
			close(sockfd);
			continue;
		}

		break;
	}

	if (p == NULL) {
		fprintf(stderr, "client: failed to connect\n");
		return 2;
	}

	inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
			s, sizeof s);
	printf("client: connecting to %s\n", s);

	freeaddrinfo(servinfo); // all done with this structure

	// function for chat
    server_client(sockfd);

	close(sockfd);

	return 0;
}
