#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H
#include <stdbool.h>

// Structs

	// Struct de contato
	typedef struct{
		char ddd[4];
		char numero[10];
	}Telefone;
	
	typedef struct{
		char nome[50];
		Telefone telefone;
		char email[256];
	} Contato;

// Funções
	
	// Funções principais
	void AdicionarContato(Contato *listaContatos, int *tamanho_lista);
	void BuscarContato(Contato *listaContatos, int *tamanho_lista);
	void AtualizarContato();
	void RemoverContato();

	// Funções secundarias
		// Funções de quebra de linha
		void LineBreak1();
		void LineBreak2();
		void LineBreak3();
		
		// Função para verificar se é número
		void VerificarSeNumero(char *digitado, bool *letra, int *valorRetornado);
		

#endif
