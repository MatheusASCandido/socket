#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()
#define MAX 4000
#define PORT 8080
#define SA struct sockaddr
void func(int sockfd)
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
                //printf(" %s \n", buff);

                printf("Digite o Nome do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);
                strcat(buff,",");
                //printf(" %s \n", buff);


                printf("Digite o Sobrenome do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);
                strcat(buff,",");
                //printf(" %s \n", buff);

                printf("Digite a Residência do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);
                strcat(buff,",");
                //printf(" %s \n", buff);

                printf("Digite a Formação Acadêmica do usuário: ");
                char aux[100];
                fgets(aux, 100, stdin);
                fgets(str, 100, stdin);
                str[strcspn(str, "\n")] = 0;
                strcat(buff,str);
                strcat(buff,",");
                //printf(" %s \n", buff);

                printf("Digite o Ano de Formação do usuário: ");
                scanf("%s",variavel);
                strcat(buff,variavel);
                strcat(buff,",");
                //printf(" %s \n", buff);

                printf("Digite as Habilidades do usuário: ");
                //scanf("%[%s^\n]",&variavel);
                fgets(str, 100, stdin);
                fgets(str, 100, stdin);
                strcat(buff,str);
                //printf(" %s \n", buff);
                //printf("%s", str);

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
 
int main()
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
 
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
 
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
 
    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr))
        != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");
 
    // function for chat
    func(sockfd);
 
    // close the socket
    close(sockfd);
}