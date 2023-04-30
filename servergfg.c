#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // read(), write(), close()
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

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

void determinado_curso(char* curso){
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
                    }
                }
  
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
}

void determinada_habilidade(char* habilidade){
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
                    }
                }
  
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
}

void determinado_ano(char* ano){
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
                    }
                }
  
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
}

void listar_todos(){
    FILE* fp = fopen("database.csv", "r");

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
  
            while (value) {
                if (column == 0) {
                    printf("Email: ");
                }
  
                if (column == 1) {
                    printf("Nome: ");
                }
  
                if (column == 2) {
                    printf("Sobrenome: ");
                }

                if (column == 3) {
                    printf("Residencia: ");
                }
                if (column == 4) {
                    printf("Formação Acadêmica: ");
                }
                if (column == 5) {
                    printf("Ano de Formatura: ");
                }
                if (column == 6) {
                    printf("Habilidades :");
                }
  
                printf("%s\n", value);
                value = strtok(NULL, ",");
                column++;
            }
            printf("\n");
        }
        // Close the file
        fclose(fp);
    }
}
void consultar_email(char* email){
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
                    }
                }
  
                if (column == 1 && correto==1) {
                    printf("Nome: ");
                }
  
                if (column == 2 && correto==1) {
                    printf("Sobrenome: ");
                }

                if (column == 3 && correto==1) {
                    printf("Residencia: ");
                }
                if (column == 4 && correto==1) {
                    printf("Formação Acadêmica: ");
                }
                if (column == 5 && correto==1) {
                    printf("Ano de Formatura: ");
                }
                if (column == 6 && correto==1) {
                    printf("Habilidades :");
                }
                if(correto==1){
                    printf("%s\n", value);
                }
                value = strtok(NULL, ",");
                column++;
            }
        }
        fclose(fp);
    }
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
    int n;
    // infinite loop for chat
    for (;;) {
        bzero(buff, MAX);
   
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
            determinado_curso(curso);
        }
        if(strncmp("3",buff,1)==0){
            printf("determinada habilidade\n");
            char habilidade[102];
            memcpy(habilidade, &buff[2], sizeof(buff)-2);
            determinada_habilidade(habilidade);
        }
        if(strncmp("4",buff,1)==0){
            printf("formada no ano x\n");
            char ano[102];
            memcpy(ano, &buff[2], sizeof(buff)-2);
            determinado_ano(ano);
        }
        if(strncmp("5",buff,1)==0){
            printf("listar todos\n");
            listar_todos();
        }
        if(strncmp("6",buff,1)==0){
            printf("por email\n");
            char email[102];
            memcpy(email, &buff[2], sizeof(buff)-2);
            consultar_email(email);
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
        bzero(buff, MAX);
        n = 0;
        // copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n')
            ;
   
        // and send that buffer to client
        write(connfd, buff, sizeof(buff));
   
        // if msg contains "Exit" then server exit and chat ended.
        
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
}

   
// Driver function
int main()
{
    int sockfd, connfd, len;
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
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
   
    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");
   
    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);
   
    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");
   
    // Function for chatting between client and server
    func(connfd);
   
    // After chatting close the socket
    close(sockfd);
}