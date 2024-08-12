#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H
#include <stdbool.h>

// Structs

	// Struct de contato
	typedef struct{
		char ddd[5];
		char numero[11];
	}Telefone;
	
	typedef struct{
		char nome[50];
		Telefone telefone;
		char email[256];
		int id;
	} Contato;

// Funções
	
	// Funções principais
	void AdicionarContato(Contato *listaContatos, int *tamanho_lista, char *status, int *codigoDeResposta);
	void BuscarContato(Contato *listaContatos, int *tamanho_lista, char *status, int *codigoDeResposta);
	void AtualizarContato(Contato *listaContatos, int *tamanho_lista, char *status, int *codigoDeResposta);
	void RemoverContato(Contato *listaContatos, int *tamanho_lista, char *status, int *codigoDeResposta);

	// Funções secundarias
		// Funções de quebra de linha
		void LineBreak1();
		void LineBreak2();
		void LineBreak3();
		
		// Função para verificar se é número
		void VerificarSeNumero(char *digitado, bool *letra, int *valorRetornado);
		
		// Função para verificar se é número e se tem o limite máximo de cacteres
		bool ENumeroValido(const char *entrada, int maximo_de_numeros);
		
		// Função converter string para minusculo
		void converter_minusculo(char *str);
		
		// Função para remover \n gerado pelo fgets
		void removerNovaLinha(char *str);
		
		// Função para limpar o buffer do teclado
		void limpar_buffer();
		
		// Printar o tipo de retorno boolean
		void printBoolean(bool value);

#endif
