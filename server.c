/*
** server.c -- a stream socket server demo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h> // read(), write(), close()
#define PORT "3490"  // the port users will be connecting to
#define MAX 4000
#define BACKLOG 10	 // how many pending connections queue will hold

//void novo_user(char* Email,char* Nome, char* Sobrenome,char* Res, char* Form, char* Ano,char* Hab){
void novo_user(char* Nome){ 
    FILE* fp = fopen("database.csv", "a+");

    if (!fp)
        printf("Can't open file\n");

    else {
        //printf("mostrando o nome:%s\n", Nome);
        fprintf(fp, "%s", Nome);
        fclose(fp);
    }
}

char *determinado_curso(char* curso, char* aux){
    FILE* fp = fopen("database.csv", "r");
    curso = strtok(curso, "\n");
    //printf("entrou: %s\n", curso);

    if (!fp)
        printf("Can't open file\n");

    else {
 // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;
        char email[100];
        char nome[100];
  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ",");
  
            while (value) {
                if (column == 0) {
                    strcpy(email, value);
                }
  
                if (column == 1) {
                    strcpy(nome, value);
                }


                if (column == 4) {
                    if(strcmp(value, curso)==0){
                        printf("Email: %s; Nome: %s\n", email, nome);
                        strcat(aux,"Email: ");
                        strcat(aux,email);
                        strcat(aux,"; Nome: ");
                        strcat(aux,nome);
                        strcat(aux,"\n");
                    }
                }
  
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
    return (aux);
}

char *determinada_habilidade(char* habilidade, char* aux){
    FILE* fp = fopen("database.csv", "r");
    habilidade = strtok(habilidade, "\n");
    //printf("entrou: %s\n", curso);

    if (!fp)
        printf("Can't open file\n");

    else {
 // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;
        char email[100];
        char nome[100];
  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ",");
  
            while (value) {
                if (column == 0) {
                    strcpy(email, value);
                }
  
                if (column == 1) {
                    strcpy(nome, value);
                }


                if (column == 6) {
                    //printf("%s %s\n",value, habilidade);
                    if(strstr(value, habilidade)!=NULL){
                        printf("Email: %s; Nome: %s\n", email, nome);
                        strcat(aux,"Email: ");
                        strcat(aux,email);
                        strcat(aux,"; Nome: ");
                        strcat(aux,nome);
                        strcat(aux,"\n");
                    }
                }
  
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
    return (aux);
}

char *determinado_ano(char* ano, char* aux){
    FILE* fp = fopen("database.csv", "r");
    ano = strtok(ano, "\n");
    //printf("entrou: %s\n", curso);

    if (!fp)
        printf("Can't open file\n");

    else {
 // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;
        char email[100];
        char nome[100];
        char curso[100];
  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ",");
  
            while (value) {
                if (column == 0) {
                    strcpy(email, value);
                }
  
                if (column == 1) {
                    strcpy(nome, value);
                }

                if (column == 4) {
                    strcpy(curso, value);
                }

                if (column == 5) {
                    if(strcmp(value, ano)==0){
                        printf("Email: %s; Nome: %s; curso: %s\n", email, nome, curso);
                        strcat(aux,"Email: ");
                        strcat(aux,email);
                        strcat(aux,"; Nome: ");
                        strcat(aux,nome);
                        strcat(aux,"; curso: ");
                        strcat(aux,curso);
                        strcat(aux,"\n");
                    }
                }
  
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
    return(aux);
}

char *listar_todos(char* aux){
    FILE* fp = fopen("database.csv", "r");

    if (!fp)
        printf("Can't open file\n");

    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;
        strcat(aux,"\n");
  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ",");
  
            while (value) {
                if (column == 0) {
                    printf("Email: ");
                    strcat(aux,"Email: ");
                }
  
                if (column == 1) {
                    printf("Nome: ");
                    strcat(aux,"Nome: ");
                }
  
                if (column == 2) {
                    printf("Sobrenome: ");
                    strcat(aux,"Sobrenome: ");
                }

                if (column == 3) {
                    printf("Residencia: ");
                    strcat(aux,"Residencia: ");
                }
                if (column == 4) {
                    printf("Formação Acadêmica: ");
                    strcat(aux,"Formação Acadêmica: ");
                }
                if (column == 5) {
                    printf("Ano de Formatura: ");
                    strcat(aux,"Ano de Formatura: ");
                }
                if (column == 6) {
                    printf("Habilidades :");
                    strcat(aux,"Habilidades: ");
                }
  
                printf("%s\n", value);
                strcat(aux,value);
                strcat(aux,"\n");
                value = strtok(NULL, ",");
                column++;
            }
            printf("\n");
            strcat(aux,"\n");
        }
        // Close the file
        fclose(fp);
    }
    return (aux);
}
char *consultar_email(char* email, char* aux){
    FILE* fp = fopen("database.csv", "r");
    email = strtok(email, "\n");
    //printf("entrou: %s\n", curso);

    if (!fp)
        printf("Can't open file\n");

    else {
 // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;

  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ",");
            int correto = 0;
  
            while (value) {
                if (column == 0) {
                    if(strcmp(value, email)==0){
                        correto = 1;
                        printf("Email: ");
                        strcat(aux,"Email: ");
                    }
                }
  
                if (column == 1 && correto==1) {
                    printf("Nome: ");
                    strcat(aux,"Nome: ");

                }
  
                if (column == 2 && correto==1) {
                    printf("Sobrenome: ");
                    strcat(aux,"Sobrenome: ");

                }

                if (column == 3 && correto==1) {
                    printf("Residencia: ");
                    strcat(aux,"Habilidades: ");
                    
                }
                if (column == 4 && correto==1) {
                    printf("Formação Acadêmica: ");
                    strcat(aux,"Formação Acadêmica: ");
                }
                if (column == 5 && correto==1) {
                    printf("Ano de Formatura: ");
                    strcat(aux,"Ano de Formatura: ");

                }
                if (column == 6 && correto==1) {
                    printf("Habilidades :");
                    strcat(aux,"Habilidades: ");

                }
                if(correto==1){
                    printf("%s\n", value);
                    strcat(aux,value);
                    strcat(aux,"\n");

                }
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
    return(aux);
}

int pegalinha_remove(char* email){
    FILE* fp = fopen("database.csv", "r");
    email = strtok(email, "\n");
    //printf("entrou: %s\n", curso);
    int linha = -1;

    if (!fp)
        printf("Can't open file\n");

    else {
 // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
  
        int row = 0;
        int column = 0;

  
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;
  
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
  
            // Splitting the data
            char* value = strtok(buffer, ",");
            int correto = 0;
  
            while (value) {
                if (column == 0) {
                    if(strcmp(value, email)==0){
                        linha = row;
                    }
                }
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
    return (linha);
}

int remover(int linha){
    FILE* fp = fopen("database.csv", "r");
     FILE *input = fopen("database.csv", "r"); //Arquivo de entrada.
    FILE *output = fopen("transferindo.txt", "w"); //Arquivo de saída.
    char texto[1001] = ""; //Uma string larga o suficiente para extrair o texto total de cada linha.
    if(linha==-1){
        return(0);
    }
    unsigned int linha_selecionada = linha;
    unsigned int linha_atual = 1;
    while(fgets(texto, 1001, input) != NULL){
        if(linha_atual != linha_selecionada){
            fputs(texto, output);
        }
        memset(texto, 0, sizeof(char) * 1001);
        linha_atual += 1;
    }
    fclose(input);
    fclose(output);
    remove("database.csv");
    rename("transferindo.txt", "database.csv");
    return 0;
}

// Function designed for chat between client and server.
void func(int connfd)
{
    char buff[MAX];
    char buff2[MAX];
    int n;
    // infinite loop for chat
    for (;;) {
        bzero(buff, MAX);
        bzero(buff2, MAX);
   
        // read the message from client and copy it in buffer
        read(connfd, buff, sizeof(buff));

        printf("top__ %s\n", buff);
        if(strncmp("exit",buff,4)==0){
            write(connfd, "exit\n", 5);
            printf("Server Exit...\n");
            break;
        }
        if(strncmp("1",buff,1)==0){
            char nome[100];
            memcpy(nome, &buff[2], sizeof(buff)-2);
            novo_user(nome);
        }
        if(strncmp("2",buff,1)==0){
            printf("listar por curso\n");
            char curso[102];
            memcpy(curso, &buff[2], sizeof(buff)-2);
            strcpy(buff,(determinado_curso(curso, buff2)));
            printf("no buff tem: %s", buff);
        }
        if(strncmp("3",buff,1)==0){
            printf("determinada habilidade\n");
            char habilidade[102];
            memcpy(habilidade, &buff[2], sizeof(buff)-2);
            strcpy(buff,(determinada_habilidade(habilidade, buff2)));
            printf("no buff tem: %s", buff);
        }
        if(strncmp("4",buff,1)==0){
            printf("formada no ano x\n");
            char ano[102];
            memcpy(ano, &buff[2], sizeof(buff)-2);
            strcpy(buff,(determinado_ano(ano, buff2)));
            printf("no buff tem: %s", buff);

        }
        if(strncmp("5",buff,1)==0){
            printf("listar todos\n");
            strcpy(buff,listar_todos(buff2));
            printf("agora é o buff:\n%s\n", buff);
        }
        if(strncmp("6",buff,1)==0){
            printf("por email\n");
            char email[102];
            memcpy(email, &buff[2], sizeof(buff)-2);
            strcpy(buff,(consultar_email(email, buff2)));
            printf("agora é o buff:\n%s\n", buff);
        }
        if(strncmp("7",buff,1)==0){
            printf("remover\n");
            char email_r[102];
            memcpy(email_r, &buff[2], sizeof(buff)-2);
            int linha = pegalinha_remove(email_r);
            //printf("linha: %i\n", linha);
            remover(linha);
        }
        // print buffer which contains the client contents
        printf("From client: %s\t To client : ", buff);
        //bzero(buff, MAX);
        n = 0;
        // copy server message in the buffer
        //while ((buff[n++] = getchar()) != '\n')
        //    ;
   
        // and send that buffer to client
        write(connfd, buff, sizeof(buff));
        bzero(buff, MAX);
        //buff[0] = '\0';
        printf("OQ TEM NO BUFF %s e %d", buff, connfd);
   
        // if msg contains "Exit" then server exit and chat ended.
        
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
}

void sigchld_handler(int s)
{
	(void)s; // quiet unused variable warning

	// waitpid() might overwrite errno, so we save and restore it:
	int saved_errno = errno;

	while(waitpid(-1, NULL, WNOHANG) > 0);

	errno = saved_errno;
}


// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(void)
{
	int sockfd, new_fd;  // listen on sock_fd, new connection on new_fd
	struct addrinfo hints, *servinfo, *p;
	struct sockaddr_storage their_addr; // connector's address information
	socklen_t sin_size;
	struct sigaction sa;
	int yes=1;
	char s[INET6_ADDRSTRLEN];
	int rv;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE; // use my IP

	if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	// loop through all the results and bind to the first we can
	for(p = servinfo; p != NULL; p = p->ai_next) {
		if ((sockfd = socket(p->ai_family, p->ai_socktype,
				p->ai_protocol)) == -1) {
			perror("server: socket");
			continue;
		}

		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
				sizeof(int)) == -1) {
			perror("setsockopt");
			exit(1);
		}

		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			perror("server: bind");
			continue;
		}

		break;
	}

	freeaddrinfo(servinfo); // all done with this structure

	if (p == NULL)  {
		fprintf(stderr, "server: failed to bind\n");
		exit(1);
	}

	if (listen(sockfd, BACKLOG) == -1) {
		perror("listen");
		exit(1);
	}

	sa.sa_handler = sigchld_handler; // reap all dead processes
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGCHLD, &sa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}

	printf("server: waiting for connections...\n");

	while(1) {  // main accept() loop
		sin_size = sizeof their_addr;
		new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
		if (new_fd == -1) {
			perror("accept");
			continue;
		}

		inet_ntop(their_addr.ss_family,
			get_in_addr((struct sockaddr *)&their_addr),
			s, sizeof s);
		printf("server: got connection from %s\n", s);

		if (!fork()) { // this is the child process
			func(new_fd);
			close(sockfd); // child doesn't need the listener
			close(new_fd);
			exit(0);
		}
		close(new_fd);  // parent doesn't need this
	}

	close(sockfd);
    close(new_fd);

	return 0;
}
