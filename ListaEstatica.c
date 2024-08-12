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
	
	// Função limpar o buffer do teclado
	void limpar_buffer() {
    	 int c;
    	 while ((c = getchar()) != '\n' && c != EOF);
	}
	
	// Função para verificar se tem letra e se tem a quantidade máxima de numeros perimitida
bool ENumeroValido(const char *entrada, int maximo_de_numeros) {
    int len = strlen(entrada);

    // Verifica se o comprimento da entrada não excede o máximo permitido
    if (len > maximo_de_numeros) {
        return false;
    }
    
    // Verifica se a entrada contém apenas dígitos
    size_t i;
    for (i = 0; i < len; i++) {
        if (!isdigit((unsigned char)entrada[i])) {
            return false;
        }
    }

    return true;
}
	
	// Verificador de valor de boolean
	void printBoolean(bool value) {
	    if (value) {
	        printf("true\n");
	    } else {
	        printf("false\n");
	    }
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

	void AdicionarContato(Contato *listaContatos, int *tamanho_lista, char *status, int *codigoDeResposta) {
		
		// Guia: 
		   // Função removerNovaLinha, tira o \n do final das strings lidas pelo fgets.
		   // LineBreak equivale a \n.
		
		// Booleanos que verificam a sintaxe da entrada de dados
		bool sintaxe_pergunta_ddd = false;
		bool sintaxe_pergunta_numero = false;
		
		
		Contato contato;
		
		// Verifica de a lista já atingiu o tamanho máximo, caso seja true, cai no else.
		if (*tamanho_lista <= TAM_MAX) {
			printf("Digite o nome do contato: "); 
			fflush(stdin);
			fgets(contato.nome, sizeof(contato.nome), stdin);
			removerNovaLinha(contato.nome);
			LineBreak1();
			

            while(sintaxe_pergunta_ddd == false){
                printf("Digite o DDD do telefone: ");
                fflush(stdin);
                fgets(contato.telefone.ddd, sizeof(contato.telefone.ddd), stdin);
                removerNovaLinha(contato.telefone.ddd);
                sintaxe_pergunta_ddd = ENumeroValido(contato.telefone.ddd, 3);
				int t = strlen(contato.telefone.ddd);
                if(sintaxe_pergunta_ddd == false){
                    printf("Por favor, digite números a não ultrapasse 3 digitos"); LineBreak1();
                } 
            }
            
            while(sintaxe_pergunta_numero == false) {
				printf("Digite o número do telefone: ");
				fflush(stdin);				
				fgets(contato.telefone.numero, sizeof(contato.telefone.numero), stdin);
				removerNovaLinha(contato.telefone.numero);
				sintaxe_pergunta_numero = ENumeroValido(contato.telefone.numero, 9);	
                if(sintaxe_pergunta_numero == false){
                    printf("Por favor, digite números a não ultrapasse 9 digitos"); LineBreak1();
                } 				
				
			}
			printf("Digite o email do contato: ");
			fflush(stdin);
			fgets(contato.email, sizeof(contato.email), stdin);
			removerNovaLinha(contato.email);	
			
			contato.id = *tamanho_lista + 1;
			
			// O array que guarda os contatos recebe o novo contato na posição apontada pela variavel "tamanho_lista".
			listaContatos[*tamanho_lista] = contato;
			*tamanho_lista += 1;
			
			
			// Substitui a variavel status pela resposta da "requisição"
			strcpy(status, "Contato criado com sucesso!");
			*codigoDeResposta = 2;
			
			system("cls");
		} 
		else{
			// Substitui a variavel status pela resposta da "requisição"
			strcpy(status, "Máximo de contatos atingido.");
			*codigoDeResposta = 1;
			system("cls");
		}
	}
	
	void BuscarContato(Contato *listaContatos, int *tamanho_lista, char *status, int *codigoDeResposta) {
		int i, vef = 0, tam_array_contatos_encontrados = 0;
		
		// String que guarda o valor digitado pelo usuário
		char busca[TAM_MAX];
		
		// Array que guarda temporariamente os contato encontrados
		Contato ContatosEncontrados[TAM_MAX];
		
		printf("Para pesquisar todos os contatos, deixe em branco, ou"); LineBreak1();
		printf("Digite o nome, telefone ou email do contato: ");
		fgets(busca, sizeof(busca), stdin);	
		removerNovaLinha(busca);
	
	

		for(i=0;i <= *tamanho_lista; i++){
			
			char nome[TAM_MAX];
			char ddd[TAM_MAX];
			char telefone[30];
			char telefoneCompleto[TAM_MAX];
			char email[TAM_MAX_255];
			
			strcpy(nome, listaContatos[i].nome);
			strcpy(ddd, listaContatos[i].telefone.ddd);
			strcpy(telefone, listaContatos[i].telefone.numero);
			strcpy(email, listaContatos[i].email);
			
	
			strcat(ddd, telefone);
			strcpy(telefoneCompleto, ddd);
			
			converter_minusculo(busca);
			converter_minusculo(nome);
			converter_minusculo(telefoneCompleto);	
			converter_minusculo(email);	
				
			if (strstr(nome, busca) != NULL){
				// Achou o contato pelo nome
				
				if(listaContatos[i].id !=0){
					LineBreak1();
					ContatosEncontrados[tam_array_contatos_encontrados] = listaContatos[i];
					tam_array_contatos_encontrados += 1;
					vef = 1;
				}
			} 
			else {
				 if (strstr(telefoneCompleto, busca) != NULL){
				 	// Achou o contato pelo telefone
					if(listaContatos[i].id !=0){
						LineBreak1();
						ContatosEncontrados[tam_array_contatos_encontrados] = listaContatos[i];
						tam_array_contatos_encontrados += 1;
						vef = 1;
					}			 	

				 }
				 else{
				 	if (strstr(email, busca) != NULL) {
				 		//Achou pelo email
						if(listaContatos[i].id !=0){
							LineBreak1();
							ContatosEncontrados[tam_array_contatos_encontrados] = listaContatos[i];
							tam_array_contatos_encontrados += 1;
							vef = 1;
						}					 		
					 }
				 }
			}			
		}
		
		if(vef != 1){
			system("cls");
			strcpy(status, "Nenhum contato encontrado!");
			*codigoDeResposta = 1;
		}
		else{
			system("cls");
			strcpy(status, "Busca realizada!");
			*codigoDeResposta = 2;
			printf("Resultado: "); LineBreak2();
   			for (i = 0; i < tam_array_contatos_encontrados; i++) {
   				if (ContatosEncontrados[i].nome == '\0'){
   					
			   }
			   
			   else {
 
   		 		printf("{\nNome: %s\nTelefone: %s%s\ne-mail: %s\nID: %d\n}\n",
                ContatosEncontrados[i].nome,
                ContatosEncontrados[i].telefone.ddd,
                ContatosEncontrados[i].telefone.numero,
                ContatosEncontrados[i].email,
                ContatosEncontrados[i].id);       
            }
        	}
        	system("pause");
		}

	}
	
	void AtualizarContato(Contato *listaContatos, int *tamanho_lista, char *status, int *codigoDeResposta) {
		strcpy(status, "");
		int i, vef = 0, tam_array_contatos_encontrados = 0, ID, opc;
		bool vef_atualizar = true;
		
		// Booleanos que verificam a sintaxe da entrada de dados
		bool sintaxe_pergunta_ddd = false;
		bool sintaxe_pergunta_numero = false;		
		
		// String que guarda o valor digitado pelo usuário
		char busca[TAM_MAX];
		
		// Array que guarda temporariamente os contato encontrados
		Contato ContatosEncontrados[TAM_MAX];
		
		printf("Digite o nome, telefone ou email do contato: ");
		fgets(busca, sizeof(busca), stdin);	
		removerNovaLinha(busca);
	
	

		for(i=0;i <= *tamanho_lista; i++){
			
			char nome[TAM_MAX];
			char ddd[TAM_MAX];
			char telefone[30];
			char telefoneCompleto[TAM_MAX];
			char email[TAM_MAX_255];
			
			strcpy(nome, listaContatos[i].nome);
			strcpy(ddd, listaContatos[i].telefone.ddd);
			strcpy(telefone, listaContatos[i].telefone.numero);
			strcpy(email, listaContatos[i].email);
			
	
			strcat(ddd, telefone);
			strcpy(telefoneCompleto, ddd);
			
			converter_minusculo(busca);
			converter_minusculo(nome);
			converter_minusculo(telefoneCompleto);	
			converter_minusculo(email);	
				
			if (strstr(nome, busca) != NULL){
				// Achou o contato pelo nome
				if(listaContatos[i].id !=0){
					LineBreak1();
					ContatosEncontrados[tam_array_contatos_encontrados] = listaContatos[i];
					tam_array_contatos_encontrados += 1;
					vef = 1;
				}
			} 
			else {
				 if (strstr(telefoneCompleto, busca) != NULL){
				 	// Achou o contato pelo telefone
					if(listaContatos[i].id !=0){
						LineBreak1();
						ContatosEncontrados[tam_array_contatos_encontrados] = listaContatos[i];
						tam_array_contatos_encontrados += 1;
						vef = 1;
					}
				 }
				 else{
				 	if (strstr(email, busca) != NULL) {
				 		//Achou pelo email
						if(listaContatos[i].id !=0){
							LineBreak1();
							ContatosEncontrados[tam_array_contatos_encontrados] = listaContatos[i];
							tam_array_contatos_encontrados += 1;
							vef = 1;
						}				 		
					 }
				 }
			}			
		}
		
		if(vef != 1){
			system("cls");
			strcpy(status, "Nenhum contato encontrado!");
			*codigoDeResposta = 1;
		}
		else{
			system("cls");
			strcpy(status, "Busca realizada!");
			*codigoDeResposta = 2;
			printf("Resultado: "); LineBreak2();
   			for (i = 0; i < tam_array_contatos_encontrados; i++) {
   		 		printf("{\nNome: %s\nTelefone: %s%s\ne-mail: %s\nID: %d\n}\n",
                ContatosEncontrados[i].nome,
                ContatosEncontrados[i].telefone.ddd,
                ContatosEncontrados[i].telefone.numero,
                ContatosEncontrados[i].email,
                ContatosEncontrados[i].id);
        	}	
			
			printf("Digite o ID do contato que deseja atualizar: ");
			scanf("%d", &ID);
			ID = ID-1;
			limpar_buffer();
			LineBreak2();
			
			printf("Contato de ID %d tem as seguintes informações: ", ID+1);
			LineBreak2();
			
			if (listaContatos[ID].telefone.ddd[0] == '\0'){
				strcpy(status, "Esse contato não existe ou está em branco");	
			}
			
			else {
			
   		 		printf("{\nNome: %s\nTelefone: %s%s\ne-mail: %s\nID: %d\n}\n",
                listaContatos[ID].nome,
                listaContatos[ID].telefone.ddd,
                listaContatos[ID].telefone.numero,
                listaContatos[ID].email,
                listaContatos[ID].id);	
						
			LineBreak1();
			
			while(vef_atualizar != false) {

				printf("Selecione a opção desejada");
				LineBreak1();
				printf("[1] - Atualizar nome"); LineBreak1();
				printf("[2] - Atualizar telefone"); LineBreak1();
				printf("[3] - Atualizar email"); LineBreak1();
				printf("[4] - Voltar"); LineBreak1();	
				
				printf("-> ");
				scanf("%d", &opc);
				limpar_buffer();
				
				switch(opc){
					case 1: {
						printf("Digite o nome atualizado: ");
						fflush(stdin);
						fgets(listaContatos[ID].nome, sizeof(listaContatos[ID].nome), stdin);
						removerNovaLinha(listaContatos[ID].nome);
						strcpy(status, "Contato atualizado!");
						*codigoDeResposta = 2;
						break;
					}
					
					case 2: {					
						while(sintaxe_pergunta_ddd == false){
							printf("Digite o DDD atualizado: ");
							fflush(stdin);
							fgets(listaContatos[ID].telefone.ddd, sizeof(listaContatos[ID].telefone.ddd), stdin);
							removerNovaLinha(listaContatos[ID].telefone.ddd);	
	                		sintaxe_pergunta_ddd = ENumeroValido(listaContatos[ID].telefone.ddd, 3);
	                		if(sintaxe_pergunta_ddd == false){
	                    	printf("Por favor, digite números e não ultrapasse 3 digitos"); LineBreak1();
                			} 
            			}
												
						while(sintaxe_pergunta_numero == false){
							printf("Digite o número atualizado: ");
							fflush(stdin);
							fgets(listaContatos[ID].telefone.numero, sizeof(listaContatos[ID].telefone.numero), stdin);
							removerNovaLinha(listaContatos[ID].telefone.numero);	
	                		sintaxe_pergunta_numero = ENumeroValido(listaContatos[ID].telefone.numero, 10);
	                		if(sintaxe_pergunta_numero == false){
	                 		   	printf("Por favor, digite números e não ultrapasse 9 digitos"); LineBreak1();
                			} 
            			}
						
							
						strcpy(status, "Contato atualizado!");	
						*codigoDeResposta = 2;								
						break;
					}
					
					case 3: {
						printf("Digite o email atualizado: ");
						fflush(stdin);
						fgets(listaContatos[ID].email, sizeof(listaContatos[ID].nome), stdin);	
						removerNovaLinha(listaContatos[ID].email);	
						strcpy(status, "Contato atualizado!");	
						*codigoDeResposta = 2;			
						break;
					}
					
					case 4: {
						vef_atualizar = false;
						break;
					}
					
					default: {
						printf("Opção inválida!");
						break;
					}
				}							
			}
		}
		}
	}
	
	void RemoverContato(Contato *listaContatos, int *tamanho_lista, char *status, int *codigoDeResposta) {
		strcpy(status, "");
		int i, vef = 0, tam_array_contatos_encontrados = 0, ID, opc, valorRetornado;;
		bool vef_atualizar = true, letra = false, loop = true;
		
		char apagaOuNao[TAM_MAX];
		

		
		// String que guarda o valor digitado pelo usuário
		char busca[TAM_MAX];
		
		// Array que guarda temporariamente os contato encontrados
		Contato ContatosEncontrados[TAM_MAX];
		
		printf("Digite o nome, telefone ou email do contato: ");
		fgets(busca, sizeof(busca), stdin);	
		removerNovaLinha(busca);
	
	

		for(i=0;i <= *tamanho_lista; i++){
			
			char nome[TAM_MAX];
			char ddd[TAM_MAX];
			char telefone[30];
			char telefoneCompleto[TAM_MAX];
			char email[TAM_MAX_255];
			
			strcpy(nome, listaContatos[i].nome);
			strcpy(ddd, listaContatos[i].telefone.ddd);
			strcpy(telefone, listaContatos[i].telefone.numero);
			strcpy(email, listaContatos[i].email);
			
	
			strcat(ddd, telefone);
			strcpy(telefoneCompleto, ddd);
			
			converter_minusculo(busca);
			converter_minusculo(nome);
			converter_minusculo(telefoneCompleto);	
			converter_minusculo(email);	
				
			if (strstr(nome, busca) != NULL){
				// Achou o contato pelo nome
				LineBreak1();
				ContatosEncontrados[tam_array_contatos_encontrados] = listaContatos[i];
				tam_array_contatos_encontrados += 1;
				vef = 1;
			} 
			else {
				 if (strstr(telefoneCompleto, busca) != NULL){
				 	// Achou o contato pelo telefone
				 	LineBreak1();
					ContatosEncontrados[tam_array_contatos_encontrados] = listaContatos[i];
					tam_array_contatos_encontrados += 1;				 	
				 	vef = 1;
				 }
				 else{
				 	if (strstr(email, busca) != NULL) {
				 		//Achou pelo email
				 		LineBreak1();
						ContatosEncontrados[tam_array_contatos_encontrados] = listaContatos[i];
						tam_array_contatos_encontrados += 1;				 	
					 	vef = 1;				 		
					 }
				 }
			}			
		}
		
		if(vef != 1){
			system("cls");
			strcpy(status, "Nenhum contato encontrado!");
			*codigoDeResposta = 1;
		}
		else{
			system("cls");
			printf("Resultado: "); LineBreak2();
   			for (i = 0; i < tam_array_contatos_encontrados; i++) {
   		 		printf("{\nNome: %s\nTelefone: %s%s\ne-mail: %s\nID: %d\n}\n",
                ContatosEncontrados[i].nome,
                ContatosEncontrados[i].telefone.ddd,
                ContatosEncontrados[i].telefone.numero,
                ContatosEncontrados[i].email,
                ContatosEncontrados[i].id);
        	}	
			
			printf("Digite o ID do contato que deseja remover: ");
			scanf("%d", &ID);
			limpar_buffer();
			LineBreak2();
			ID = ID-1;
			
			printf("Contato de ID %d tem as seguintes informações: ", ID+1);
			LineBreak2();
			
			if (listaContatos[ID].telefone.ddd[0] == '\0'){
				strcpy(status, "Esse contato não existe ou está em branco");	
			}
			
			else {
			
   		 		printf("{\nNome: %s\nTelefone: %s%s\ne-mail: %s\nID: %d\n}\n",
                listaContatos[ID].nome,
                listaContatos[ID].telefone.ddd,
                listaContatos[ID].telefone.numero,
                listaContatos[ID].email,
                listaContatos[ID].id);	
						
			LineBreak1();
			
			printf("Deseja realmente apagar?");
			LineBreak1();
			
			printf("[1] - SIM");LineBreak1();
			printf("[2] - NÃO");LineBreak1();
			printf("-> ");
			
		do {
			fflush(stdin);
			fgets(apagaOuNao, sizeof(apagaOuNao), stdin);
			VerificarSeNumero(apagaOuNao, &letra, &valorRetornado); // Essa função verifica se a pessoa digitou relamente um número, se for número, letra retorna false.
			
			
			if (letra != true){ // Se letra for false, ele executa o código, caso contrário, cai no else.
				switch(valorRetornado){
					case 1:  {
					strcpy(status, "Contato removido!");
					*codigoDeResposta = 2;
						loop = false;
						listaContatos[ID].nome[0] = '\0';
						listaContatos[ID].telefone.ddd[0] = '\0';
						listaContatos[ID].telefone.numero[0] = '\0';
						listaContatos[ID].email[0] = '\0';
						listaContatos[ID].id = 0;
					}
					case 2: {
						loop = false;
						return;
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
			
}
	
	
