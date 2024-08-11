#include <stdio.h>
#include <stdlib.h>
#include "ListaEstatica.h"
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#define TAM_MAX 100
#define TAM_MAX_255

int main() {

	// Aqui temos a variavel que guarda o tamanho o array de contatos
	int tamanho_lista = 0;
	
	// Essa variável vai determinar a cor do codigo de resposta, verde ou vermelho
	int codigoDeResposta = 0;
	
	// configuração de formatação no padrão UTF-8
	setlocale(LC_ALL, "portuguese");
	
	// Variavel que guarda o status da "requisição" as funções, ex: "Contato criado com sucesso!"
	char status[100];
	
	// Welcome ;)
	printf("Bem-vindo a sua agenda de contatos");
		 
		 
	// Esse while garante que após o fim de cada função, retornaremos ao menu principal.
	while(1){
		// configuração de formatação no padrão UTF-8.
		setlocale(LC_ALL, "portuguese");
		
		system("cls");
		// variáveis
		Contato listaContatos[TAM_MAX];
		char opcao[TAM_MAX];
		int valorRetornado;
		bool loop = true, letra = false;
		
		// corpo
		if (tamanho_lista != 0){
			if(codigoDeResposta == 1){
				printf("\033[1;31m");
			}
			else if(codigoDeResposta == 2){
				printf("\033[1;32m");
			}
			printf("%s", status);
			printf("\033[0m");
			LineBreak1();
		}
		
		LineBreak2();
		
		printf("DIGITE A OPÇÃO DESEJADA");
		LineBreak2();
	
		printf("[1] - Adicionar Contato"); LineBreak1();
		printf("[2] - Buscar Contato"); LineBreak1();
		printf("[3] - Atualizar Contato"); LineBreak1();
		printf("[4] - Remover Contato"); LineBreak1();
		printf("[5] - Fechar agenda"); LineBreak1();		
		LineBreak2();
		printf("-> ");
		
		
		// Do while para repetir o entrada de dados enquanto o usuário não digita uma opção válida.
		do {
			fflush(stdin);
			fgets(opcao, sizeof(opcao), stdin);
			VerificarSeNumero(opcao, &letra, &valorRetornado); // Essa função verifica se a pessoa digitou relamente um número, se for número, letra retorna false.
			
			
			if (letra != true){ // Se letra for false, ele executa o código, caso contrário, cai no else.
				switch(valorRetornado){
					case 1:  {
						loop = false;
						AdicionarContato(listaContatos, &tamanho_lista, status, &codigoDeResposta);
						break;
					}
					case 2: {
						loop = false;
						BuscarContato(listaContatos, &tamanho_lista, status, &codigoDeResposta);
						break;
					}
					case 3: {
						loop = false;
						AtualizarContato(listaContatos, &tamanho_lista, status, &codigoDeResposta);
						break;
					}
					case 4: {
						loop = false;
						RemoverContato(listaContatos, &tamanho_lista, status, &codigoDeResposta);
						break;
					}
					
					case 5: {
						exit(0);
						break;
					}
					
					default: {
						printf("Número inválido! Escolha novamente"); LineBreak1();
						printf("-> ");
						break;
					}
				}
			}
			
			else {
				printf("Por favor, digite um número -> ");
			}
		} while(loop != false);
	}
}
