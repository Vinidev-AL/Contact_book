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

// Fun��es
	
	// Fun��es principais
	void AdicionarContato(Contato *listaContatos, int *tamanho_lista, char *status, int *codigoDeResposta);
	void BuscarContato(Contato *listaContatos, int *tamanho_lista, char *status, int *codigoDeResposta);
	void AtualizarContato(Contato *listaContatos, int *tamanho_lista, char *status, int *codigoDeResposta);
	void RemoverContato(Contato *listaContatos, int *tamanho_lista, char *status, int *codigoDeResposta);

	// Fun��es secundarias
		// Fun��es de quebra de linha
		void LineBreak1();
		void LineBreak2();
		void LineBreak3();
		
		// Fun��o para verificar se � n�mero
		void VerificarSeNumero(char *digitado, bool *letra, int *valorRetornado);
		
		// Fun��o para verificar se � n�mero e se tem o limite m�ximo de cacteres
		bool ENumeroValido(const char *entrada, int maximo_de_numeros);
		
		// Fun��o converter string para minusculo
		void converter_minusculo(char *str);
		
		// Fun��o para remover \n gerado pelo fgets
		void removerNovaLinha(char *str);
		
		// Fun��o para limpar o buffer do teclado
		void limpar_buffer();
		
		// Printar o tipo de retorno boolean
		void printBoolean(bool value);

#endif
