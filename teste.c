#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>

#define PORTA 1500

int main(int argc, char *argv[]){
	int soquete, int conexao;
	struct sockaddr_in meusoquete;
	if (argc < 2){
		printf("Ops! Há um problema! Você está usando o programa do modo errado! \nModo de uso: %s <endereço de destino>\n", argv[0]);
		exit(-1);
	}
	// Configuração do struct meusoquete
	meusoquete.sin_addr.s_addr = inet_addr(argv[1]);
	if(meusoquete.sin_addr.s_addr == 0){
		perror("Endereço inválido!");
		exit(-1);
	}
	meusoquete.sin_family = AF_INET;
	meusoquete.sin_port = PORTA;
	//Configura os 8 primeiros bits do endereço de sin_zero com zeros
	memset(&meusoquete.sin_zero, 0, 8);
	soquete = socket(AF_INET, SOCK_DGRAM, 0);
	if (soquete < 0){
		perror("Ops! Há algo de errado com o soquete!");
		exit(-1);
	}
	conexao = connect(soquete, struct sockaddr *) &meusoquete, sizeof(meusoquete));
	return 0;
}
