#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 200
	struct project {
		int codigo;
		char titulo[30];
		char descricao[50];
		int ano;
		char cidade[30];
		char cliente[30];
		char telefone[15];
		int aFazer;
		int fazendo;
		int concluido;
		char manager[30];
	};

void cadProj ();
void listProj ();
void pesqProj ();
void statusFzr ();
void statusFznd ();
void statusConcl ();

struct project proj[TAM];
int i, cont, fzr, fznd, concl;


int main() {
setlocale(LC_ALL,"Portuguese");
	int opt;
	opt = 0;
	
	while (opt != 7){
		printf("======================================\n");
		printf("\tMENU DE OPÇÕES:\n");
		printf("======================================\n");
		printf("[1] - CADASTRAR PROJETOS.\n");
		printf("[2] - LISTAR TODOS OS PROJETOS.\n");
		printf("[3] - PESQUISAR PROJETO POR CÓDIGO.\n");
		printf("[4] - LISTAR PROJETOS A FAZER.\n");
		printf("[5] - LISTAR PROJETOS EM ANDAMENTO.\n");
		printf("[6] - LISTAR PROJETOS CONCLUÍDOS.\n");
		printf("[7] - ENCERRAR.\n\n");
		fflush(stdin);
		scanf ("%d", &opt);		
		switch (opt){
			case 1: cadProj (); 
				break;
			case 2: listProj ();
				break;
			case 3: pesqProj ();
				break;
			case 4: statusFzr ();
				break;
			case 5: statusFznd ();
				break;
			case 6: statusConcl ();
				break;			
			case 7: 
				system("cls");
				printf("FIM...\n");
				break;
			default: 
				system("cls");
				printf("\n**********OPÇÃO INVÁLIDA!**********\n\n");		
		}
	}	
	return 0;
}

void cadProj (){
setlocale(LC_ALL,"Portuguese");
system("cls");
	int op, status; 
	
	do {
		if (cont <TAM){	
			printf("=====================\n");
			printf("CADASTRO DE PROJETOS\n");
			printf("=====================\n\n");	
			proj[cont].codigo = cont+1;
			printf ("CÓDIGO: %d/%d\n\n", proj[cont].codigo, TAM);
			printf("DIGITE O TÍTULO:\n");
			fflush(stdin);
			gets(proj[cont].titulo);
			printf("\nDIGITE A DESCRIÇÃO: \n");
			fflush(stdin);
			gets(proj[cont].descricao);			
			printf ("\nDIGITE O ANO: \n");
			fflush(stdin);
			scanf("%d", &proj[cont].ano);			
			printf("\nDIGITE O NOME DA CIDADE: \n");
			fflush(stdin);
			gets(proj[cont].cidade);
			printf("\nDIGITE O NOME DO CLIENTE: \n");
			fflush(stdin);
			gets(proj[cont].cliente);
			printf("\nTELEFONE P/ CONTATO: \n");
			fflush(stdin);
			gets(proj[cont].telefone);
			printf("\nGERENTE RESPONSÁVEL: \n");
			fflush(stdin);
			gets(proj[cont].manager);			
			printf("\n== STATUS DO PROJETO ==\n\n");
			printf("[1] - A FAZER:\n");
			printf("[2] - FAZENDO:\n");
			printf("[3] - CONCLUÍDO:\n");
			do{
				fflush(stdin);
				scanf("%d", &status);
				if (status == 1){
					proj[cont].aFazer = status;
					fzr++;
				}else if (status == 2){
					proj[cont].fazendo = status;
					fznd++;
				}else if (status == 3){
					proj[cont].concluido = status;
					concl++;
				}else
					printf("VALOR INVÁLIDO\n");
			}while ((status != 1) && (status != 2) && (status != 3));			
			cont++;
			printf("\nCADASTRO REALIZADO COM SUCESSO!!!\n\n");
			system("pause");
			system("cls");
			if (cont<TAM){
				printf("DIGITE 1 PARA CONTINUAR OU QUALQUER TECLA PARA SAIR:\n");
				fflush(stdin);
				scanf ("%d", &op);
				system("cls");
			}
		}else{
			printf("LIMITE DE CADASTROS ATINGIDO!!!\n\n");
			system("pause");
			system("cls");
		}
	} while ((op==1) && (cont<TAM));	
}

void listProj (){
setlocale(LC_ALL,"Portuguese");
system("cls");

	if (cont <= 0){
		printf("NÃO EXISTEM PROJETOS CADASTRADOS!\n\n");
		system("pause");
		system("cls"); 
	}else{
	
		printf("=====================\n");
		printf("LISTA DE PROJETOS\n");
		printf("=====================\n\n");
		
		for (i=0; i<cont; i++){
			printf("CÓDIGO: %d\n", proj[i].codigo);
			if (proj[i].aFazer == 1){
				printf("STATUS: %d - A FAZER\n", proj[i].aFazer);
			}
			if (proj[i].fazendo == 2){
				printf("STATUS: %d - FAZENDO\n", proj[i].fazendo);
			}
			if (proj[i].concluido == 3){
				printf("STATUS: %d - CONCLUÍDO\n", proj[i].concluido);
			}
			printf("TÍTULO: %s\n", proj[i].titulo);
			printf("DESCRIÇÃO: %s\n", proj[i].descricao);
			printf("ANO: %d\n", proj[i].ano);
			printf("CIDADE: %s\n", proj[i].cidade);
			printf("CLIENTE: %s\n", proj[i].cliente);
			printf("TELEFONE P/ CONTATO: %s\n", proj[i].telefone);
			printf("GERENTE RESPONSÁVEL: %s\n", proj[i].manager);				
			printf("======================================\n");
			printf("======================================\n\n");
		}
		system("pause");
		system("cls"); 
	}
}

void pesqProj (){
setlocale(LC_ALL,"Portuguese");
system("cls");

	int acha, busca;
	busca = 0;
	system("cls");
	printf("DIGITE O CÓDIGO A SER PESQUISADO: \n");
	fflush(stdin);
	scanf("%d", &busca);
	i = 0;
	acha = 0;
	while ((i < TAM) && (acha == 0)){
		if (proj[i].codigo == busca){
			acha = 1;
		}else {
			i++;
		}
		if (acha == 1){
			printf("\nCÓDIGO: %d\n", proj[i].codigo);
			if (proj[i].aFazer == 1){
				printf("STATUS: %d - A FAZER\n", proj[i].aFazer);
			}
			if (proj[i].fazendo == 2){
				printf("STATUS: %d - FAZENDO\n", proj[i].fazendo);
			}
			if (proj[i].concluido == 3){
				printf("STATUS: %d - CONCLUÍDO\n", proj[i].concluido);
			}
			printf("TÍTULO: %s\n", proj[i].titulo);
			printf("DESCRIÇÃO: %s\n", proj[i].descricao);
			printf("ANO: %d\n", proj[i].ano);
			printf("CIDADE: %s\n", proj[i].cidade);
			printf("CLIENTE: %s\n", proj[i].cliente);
			printf("TELEFONE P/ CONTATO: %s\n", proj[i].telefone);
			printf("GERENTE RESPONSÁVEL: %s\n", proj[i].manager);				
			printf("======================================\n");
			printf("======================================\n\n");
		}
	}if (acha != 1) {
		printf("\nPROJETO NÃO ENCONTRADO!!!\n\n");
	}
	system("pause");
	system("cls");
}

void statusFzr (){
setlocale(LC_ALL,"Portuguese");
system("cls");

	if (fzr == 0){
		printf("NÃO EXISTEM PROJETOS CADASTRADOS!!!\n\n");
		system("pause");
		system("cls");
	}else{
	
		printf("=====================\n");
		printf("STATUS: A FAZER\n");
		printf("=====================\n\n");
		
		for (i=0; i<cont; i++){
			if (proj[i].aFazer == 1){
				printf("CÓDIGO: %d\n", proj[i].codigo);
				printf("TÍTULO: %s\n", proj[i].titulo);
				printf("DESCRIÇÃO: %s\n", proj[i].descricao);
				printf("ANO: %d\n", proj[i].ano);
				printf("CIDADE: %s\n", proj[i].cidade);
				printf("CLIENTE: %s\n", proj[i].cliente);
				printf("TELEFONE P/ CONTATO: %s\n", proj[i].telefone);
				printf("GERENTE RESPONSÁVEL: %s\n", proj[i].manager);				
				printf("======================================\n");
				printf("======================================\n\n");
			}
		}
		system("pause");
		system("cls");
	}
}

void statusFznd (){
setlocale(LC_ALL,"Portuguese");
system("cls");

	if (fznd == 0){
		printf("NÃO EXISTEM PROJETOS CADASTRADOS!!!\n\n");
		system("pause");
		system("cls");
	}else{
	
		printf("=====================\n");
		printf("STATUS: FAZENDO\n");
		printf("=====================\n\n");
		
		for (i=0; i<cont; i++){
			if (proj[i].fazendo == 2){
				printf("CÓDIGO: %d\n", proj[i].codigo);
				printf("TÍTULO: %s\n", proj[i].titulo);
				printf("DESCRIÇÃO: %s\n", proj[i].descricao);
				printf("ANO: %d\n", proj[i].ano);
				printf("CIDADE: %s\n", proj[i].cidade);
				printf("CLIENTE: %s\n", proj[i].cliente);
				printf("TELEFONE P/ CONTATO: %s\n", proj[i].telefone);
				printf("GERENTE RESPONSÁVEL: %s\n", proj[i].manager);				
				printf("======================================\n");
				printf("======================================\n\n");
			}
		}
		system("pause");
		system("cls");
	}
}

void statusConcl (){
setlocale(LC_ALL,"Portuguese");
system("cls");

	if (concl == 0){
		printf("NÃO EXISTEM PROJETOS CADASTRADOS!!!\n\n");
		system("pause");
		system("cls");
	}else{

		printf("=====================\n");
		printf("STATUS: CONCLUIDO\n");
		printf("=====================\n\n");
		
		for (i=0; i<cont; i++){
			if (proj[i].concluido == 3){
				printf("CÓDIGO: %d\n", proj[i].codigo);
				printf("TÍTULO: %s\n", proj[i].titulo);
				printf("DESCRIÇÃO: %s\n", proj[i].descricao);
				printf("ANO: %d\n", proj[i].ano);
				printf("CIDADE: %s\n", proj[i].cidade);
				printf("CLIENTE: %s\n", proj[i].cliente);
				printf("TELEFONE P/ CONTATO: %s\n", proj[i].telefone);
				printf("GERENTE RESPONSÁVEL: %s\n", proj[i].manager);				
				printf("======================================\n");
				printf("======================================\n\n");
			}
		}
		system("pause");
		system("cls");
	}
}
