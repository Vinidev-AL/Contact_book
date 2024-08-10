#include <stdio.h>
#include <stdlib.h>
#include "ListaEstatica.h"
#include <locale.h>
#include <stdbool.h>
#include <ctype.h>
#define TAM_MAX 100

int main() {
	while(1){
		// configuração de formatação no padrão UTF-8
		setlocale(LC_ALL, "portuguese");
		
		// variáveis
		Contato listaContatos[TAM_MAX];
		int tamanho_lista = 0;
		char opcao[TAM_MAX];
		int valorRetornado;
		bool loop = true, letra = false;
		
		// corpo
		printf("Bem-vindo a sua agenda de contatos");
		LineBreak2();
		
		printf("DIGITE A OPÇÃO DESEJADA");
		LineBreak2();
	
		printf("[1] - Adicionar Contato"); LineBreak1();
		printf("[2] - Buscar Contato"); LineBreak1();
		printf("[3] - Atulizar Contato"); LineBreak1();
		printf("[4] - Remover Contato"); LineBreak1();
		LineBreak2();
		printf("-> ");
		
		do {
			fflush(stdin);
			fgets(opcao, sizeof(opcao), stdin);
			VerificarSeNumero(opcao, &letra, &valorRetornado);
			
			
			if (letra != true){
				switch(valorRetornado){
					case 1:  {
						loop = false;
						AdicionarContato(listaContatos, &tamanho_lista);
						break;
					}
					case 2: {
						loop = false;
						BuscarContato(listaContatos, &tamanho_lista);
						break;
					}
					case 3: {
						loop = false;
						AtualizarContato();
						break;
					}
					case 4: {
						loop = false;
						RemoverContato();
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
