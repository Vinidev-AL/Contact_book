#include <stdlib.h>
#include <stdio.h>
#include "ListaEstatica.h"
#include <string.h>
#define TAM_MAX 2

// Fun��es secundarias

	// Fun��o para quebrar linha nivel 1, quebra uma linha 
	void LineBreak1(){
		printf("\n");
	}
	
	// Fun��o para quebrar linha nivel 2, quebra duas linhas
	void LineBreak2(){
		printf("\n\n");
	}
	
	// Fun��o para quebrar linha nivel 3, quebra tr�s linhas 
	void LineBreak3(){
		printf("\n\n\n");
	}
	
	
	// Fun��o para verificar se � n�mero, caso seja letra, altera o valor de letra para "true"
	void VerificarSeNumero(char *digitado, bool *letra, int *valorRetornado) {
	    int i;
	
	    // Remove o caractere de nova linha, se presente
	    for (i = 0; digitado[i] != '\0'; i++) {
	        if (digitado[i] == '\n') {
	            digitado[i] = '\0';
	            break;
	        }
	    }
	
	    // Verifica se todos os caracteres s�o d�gitos
	    *letra = false;  // Inicializa como falso assumindo que � um n�mero v�lido
	    for (i = 0; digitado[i] != '\0'; i++) {
	        if (!isdigit(digitado[i])) {
	            *letra = true;  // Define como verdadeiro se encontrar um caractere n�o num�rico
	            break;
	        }
	    }
	
	    // Converte a string para um inteiro
	    if (!*letra) {
	        *valorRetornado = atoi(digitado);
	    } else {
	        *valorRetornado = 0;  // Define como 0 se n�o for um n�mero v�lido
	    }
	}




// Fun��es principais

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
			
			printf("Digite o n�mero do telefone: ");
			fflush(stdin);
			fgets(contato.telefone.numero, sizeof(contato.telefone.numero), stdin);
			
			printf("Digite o email do contato: ");
			fflush(stdin);
			fgets(contato.email, sizeof(contato.email), stdin);	
			
			listaContatos[*tamanho_lista] = contato;
			tamanho_lista += 1;
		} 
		else{
			printf("M�ximo de contatos atingido.");
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
	
	
