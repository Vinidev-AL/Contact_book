#include <stdlib.h>
#include <stdio.h>
#include "ListaEstatica.h"
#include <string.h>
#define TAM_MAX 100
#define TAM_MAX_255 255

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

	// Função para converter strings para minusculo
	void converter_minusculo(char *str) {
		 int i;
 		 for ( i = 0; str[i]; i++) {
  	 	 str[i] = tolower(str[i]);
   		 }
    }

	// Função para tirar o \n gerado pelo fgets
	void removerNovaLinha(char *str) {
	    size_t len = strcspn(str, "\n");
	    if (str[len] == '\n') {
	        str[len] = '\0';
	    }
	}

// Funções principais

	void AdicionarContato(Contato *listaContatos, int *tamanho_lista) {
		Contato contato;
		
		if (*tamanho_lista <= TAM_MAX) {
			printf("Digite o nome do contato: "); 
			fflush(stdin);
			fgets(contato.nome, sizeof(contato.nome), stdin);
			removerNovaLinha(contato.nome);
			LineBreak1();
			
			printf("Digite o DDD do telefone: ");
			fflush(stdin);
			fgets(contato.telefone.ddd, sizeof(contato.telefone.ddd), stdin);
			removerNovaLinha(contato.telefone.ddd);
			
			printf("Digite o número do telefone: ");
			fflush(stdin);
			fgets(contato.telefone.numero, sizeof(contato.telefone.numero), stdin);
			removerNovaLinha(contato.telefone.numero);
			
			printf("Digite o email do contato: ");
			fflush(stdin);
			fgets(contato.email, sizeof(contato.email), stdin);
			removerNovaLinha(contato.email);	
			
			listaContatos[*tamanho_lista] = contato;
			tamanho_lista += 1;
		} 
		else{
			printf("Máximo de contatos atingido.");
		}
	}
	
	void BuscarContato(Contato *listaContatos, int *tamanho_lista) {
		int i, vef = 0, tam_array_contatos_encontrados = 0;
		char busca[TAM_MAX];
		Contato ContatosEncontrados[TAM_MAX];
		
		printf("Digite o nome do contato ou o telefone: ");
		fgets(busca, sizeof(busca), stdin);	
		removerNovaLinha(busca);
	
	

		for(i=0;i<= *tamanho_lista; i++){
			
			char nome[TAM_MAX];
			char ddd[TAM_MAX];
			char telefone[30];
			char telefoneCompleto[TAM_MAX];
			
			strcpy(nome, listaContatos[i].nome);
			strcpy(ddd, listaContatos[i].telefone.ddd);
			strcpy(telefone, listaContatos[i].telefone.numero);
			
	
			strcat(ddd, telefone);
			strcpy(telefoneCompleto, ddd);
			
			converter_minusculo(busca);
			converter_minusculo(nome);
			converter_minusculo(telefoneCompleto);		
				
			if (strcmp(busca, nome) == 0){
				// Achou o contato pelo nome
				printf("Achou pelo nome");
				ContatosEncontrados[tam_array_contatos_encontrados] = listaContatos[i];
				tam_array_contatos_encontrados++;
				vef = 1;
			} 
			else {
				 if (strcmp(busca, telefoneCompleto) == 0){
				 	// Achou o contato pelo telefone
				 	printf("Achou pelo telefone");
					ContatosEncontrados[tam_array_contatos_encontrados] = listaContatos[i];
					tam_array_contatos_encontrados++;				 	
				 	vef = 1;
				 }
			}			
		}
		
		if(vef != 1){
			printf("Nenhum contato encontrado!"); LineBreak1();
		}
		else{
			printf("veja os contatos encontrados");
   			for (i = 0; i < tam_array_contatos_encontrados; i++) {
   		 		printf("Nome: %s, Telefone: %s%s, e-mail: %s\n",
                ContatosEncontrados[i].nome,
                ContatosEncontrados[i].telefone.ddd,
                ContatosEncontrados[i].telefone.numero,
                ContatosEncontrados[i].email);
        }
		}

	}
	
	void AtualizarContato() {
		printf("Atualizar contato");
	}
	
	void RemoverContato() {
		printf("Remover contato");
	}
	
	
