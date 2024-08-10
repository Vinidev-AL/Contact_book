#include <stdlib.h>
#include <stdio.h>
#include "ListaEstatica.h"
#include <string.h>
#define TAM_MAX 2

// Funções secundarias

	// Função para quebrar linha nivel 1, quebra uma linha 
	void LineBreak1(){
		printf("\n");
	}
	
	// Função para quebrar linha nivel 2, quebra duas linhas
	void LineBreak2(){
		printf("\n\n");
	}
	
	// Função para quebrar linha nivel 3, quebra três linhas 
	void LineBreak3(){
		printf("\n\n\n");
	}
	
	
	// Função para verificar se é número, caso seja letra, altera o valor de letra para "true"
	void VerificarSeNumero(char *digitado, bool *letra, int *valorRetornado) {
	    int i;
	
	    // Remove o caractere de nova linha, se presente
	    for (i = 0; digitado[i] != '\0'; i++) {
	        if (digitado[i] == '\n') {
	            digitado[i] = '\0';
	            break;
	        }
	    }
	
	    // Verifica se todos os caracteres são dígitos
	    *letra = false;  // Inicializa como falso assumindo que é um número válido
	    for (i = 0; digitado[i] != '\0'; i++) {
	        if (!isdigit(digitado[i])) {
	            *letra = true;  // Define como verdadeiro se encontrar um caractere não numérico
	            break;
	        }
	    }
	
	    // Converte a string para um inteiro
	    if (!*letra) {
	        *valorRetornado = atoi(digitado);
	    } else {
	        *valorRetornado = 0;  // Define como 0 se não for um número válido
	    }
	}




// Funções principais

	void AdicionarContato(Contato *listaContatos, int *tamanho_lista) {
		Contato contato;
		
		if (*tamanho_lista <= TAM_MAX) {
			printf("Digite o nome do contato: "); 
			fflush(stdin);
			fgets(contato.nome, sizeof(contato.nome), stdin);
			LineBreak1();
			
			printf("Digite o DDD do telefone: ");
			fflush(stdin);
			fgets(contato.telefone.ddd, sizeof(contato.telefone.ddd), stdin);
			
			printf("Digite o número do telefone: ");
			fflush(stdin);
			fgets(contato.telefone.numero, sizeof(contato.telefone.numero), stdin);
			
			printf("Digite o email do contato: ");
			fflush(stdin);
			fgets(contato.email, sizeof(contato.email), stdin);	
			
			listaContatos[*tamanho_lista] = contato;
			tamanho_lista += 1;
		} 
		else{
			printf("Máximo de contatos atingido.");
		}
	}
	
	void BuscarContato(Contato *listaContatos, int *tamanho_lista) {
		char busca[TAM_MAX];
		printf("Digite o nome do contato ou o telefone: ");
		fgets(busca, sizeof(busca), stdin);	
		printf("%s", busca);
	}
	
	void AtualizarContato() {
		printf("Atualizar contato");
	}
	
	void RemoverContato() {
		printf("Remover contato");
	}
	
	
