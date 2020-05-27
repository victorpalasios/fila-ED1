#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<locale.h>
#include <iostream>
#include <string.h>

typedef struct node Node;

struct node {
    int pid;
    int fila;
    char nome[60];
    Node *prox;
};

Node *inicioListac;
Node *finalListac;
Node *inicioListap;
Node *finalListap;
 
void inserir();
void executar();
void imprimirLista();
void Menu();

int main()
{
setlocale(LC_ALL,"portuguese");
	int escolha = 0;
	
	while(escolha != 4){
			Menu();
	    	scanf("%d", &escolha);
			system("cls");
			
    	    switch (escolha)
    	    {
    		    case 1:
					inserir();
            	break;
            	
            	case 2:
            		executar();
				
				break;
            	
            	case 3:
            		imprimirLista();
            		
            	break;
				
				case 4:
					system("cls");
					printf("Obrigado pela permanência! Volte sempre!");	
			
			}
		
		if(escolha > 4 && escolha<1){
			printf("\n Opção Inválida");
		}
			
	}
}


void inserir(){
	int filains;
	Node *novop;
	Node *novoc;
	
	printf("Insira o tipo de fila \n1-Preferencial / 2-Comum\n");
	scanf("%i",&filains);

	if(filains == 1){	
		novop = (Node*)malloc(sizeof(Node));
	
		printf("\nInsira o nome:\n");
		scanf("%s", &novop->nome);
	
		printf("\nInsira o ID do Processo\n");
		scanf("%i",&novop->pid);
	
		novop->fila = filains;
	
			if(inicioListap == NULL && finalListap == NULL){
				inicioListap = novop;
				finalListap = novop;
				finalListap->prox = NULL;
			}
		
			else{
			
				if(inicioListap == finalListap){
					finalListap = novop;
					inicioListap->prox = finalListap;
					finalListap->prox = NULL;
				}
				
				else{
					finalListap -> prox = novop;
					finalListap = novop;
					finalListap -> prox = NULL;
				}
			
		}
}
	
	if(filains == 2){
		novoc = (Node*)malloc(sizeof(Node));
	
		printf("\n\t==== Inserção ====");
	
		printf("\nInsira o nome:\n");
		scanf("%s", &novoc->nome);
	
		printf("\nInsira o ID do Processo\n");
		scanf("%i",&novoc->pid);
	
		novoc->fila = filains;	
	
			if(inicioListac == NULL && finalListac == NULL){
				inicioListac = novoc;
				finalListac = novoc;
				finalListac->prox = NULL;
			}
			
			else{
			
				if(inicioListac == finalListac){
					finalListac = novoc;
					inicioListac->prox =finalListac;
					finalListac -> prox = NULL;
				}
				
				else{
					finalListac -> prox = novoc;
					finalListac = novoc;
					finalListac -> prox = NULL;
				}
			}
	}
	
}


void executar(){
	Node *aux;
	if(inicioListap != NULL && finalListap != NULL){
		if(inicioListap == finalListap){
			aux = inicioListap;
			inicioListap = NULL;
			finalListap= NULL;
			free(aux);
		}
		else{
			aux = inicioListap;
			inicioListap = inicioListap->prox;
			free(aux);
		}
	}
	
	else if(inicioListac != NULL && finalListac != NULL){
		if(inicioListac == finalListac){
			aux = inicioListac;
			inicioListac = NULL;
			finalListac = NULL;
			free(aux);
		}
		else{
			aux= inicioListac;
			inicioListac = inicioListac->prox;
			free(aux);
		}
	}
	
	else if(inicioListap == NULL && inicioListac == NULL){
		printf("\n Listas Vazias\n");
	}
}

void imprimirLista(){
	Node *auxInserir;

	printf("\n\t==== Lista Preferencial ====");
		if(inicioListap != NULL){
			auxInserir = inicioListap;
			while(auxInserir != NULL){
				printf("\n PID: %d | Processo: %s\n", auxInserir->pid, auxInserir->nome);
				auxInserir = auxInserir->prox;
			}
		}
	else
		printf("\nLista Vazia\n");
		
	printf("\n\t==== Lista Comum ====");
		if(inicioListac != NULL){
			auxInserir = inicioListac;
			while(auxInserir != NULL){
				printf("\n PID: %d | Processo: %s\n", auxInserir->pid, auxInserir->nome);
				auxInserir = auxInserir->prox;
			}
		}
	else
		printf("\n Lista Vazia\n");
}

void Menu(){
    printf("\n====== Menu de Gerenciamento ======");
    printf("\n1 - Inserir");
    printf("\n2 - Executar");
    printf("\n3 - Imprimir Fila");
    printf("\n4 - Sair");
    printf("\nEscolha uma das Opções: ");
}


