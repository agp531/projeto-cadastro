#include <stdio.h>
#define TAM 100
#include <ctype.h>
#include <string.h>

int main (){
	
	struct Tpessoa{
		int codigo;
		char nome[30];
		char genero;
		int idade;
		float altura;
		float peso;
	};	
	
	struct Tpessoa cadastro[TAM];
	int n,i,pCadastradas=0,novoCadastro,menuAlteracao,delPessoa,tamanho,exibirPessoa,novosCadastrados;
	char menu,delNome[20]={'\0'};
	
		do{
			printf("\t ========================================================================\n");
			printf("\t |                       Escolha a opcao desejada a seguir:             |\n");
			printf("\t |                                                                      |\n");
			printf("\t | [A] Cadastrar Pessoa(s)                                              |\n");
			printf("\t | [B] Alterar os dados de uma pessoa.                                  |\n");	
			printf("\t | [C] Excluir uma pessoa.                                              |\n");
			printf("\t | [D] Mostrar os dados de apenas uma pessoa.                           |\n");
			printf("\t | [E] Mostrar os dados de todos cadastrados.                           |\n");
			printf("\t | [F] Sair.                                                            |\n");
			printf("\t |                                                                      |\n");
			printf("\t ========================================================================\n");
			
			printf("\nDigite a opcao desejada: ");
			scanf(" %c",&menu);
			printf("\n");
			
			menu = toupper(menu);
			switch(menu){
				
				case 'A':
					if(pCadastradas == 0){
						printf("Quantas pessoas deseja cadastrar?: ");
						scanf("%d",&n);
						for(i=0;i<n;i++){
							printf("\nInforme os dados da pessoa %d \n",i+1);
							printf("Nome: ");
							fflush(stdin);
							fgets(cadastro[i].nome,30,stdin);
							tamanho = strlen(cadastro[i].nome)-1;
							cadastro[i].nome[tamanho] = '\0';
							printf("Idade: ");
							scanf(" %d",&cadastro[i].idade);
							printf("Genero [M/F]: ");
							scanf(" %c",&cadastro[i].genero);
							printf("Codigo: ");
							scanf(" %d",&cadastro[i].codigo);
							printf("Altura: ");
							scanf(" %f",&cadastro[i].altura);
							printf("Peso: ");
							scanf(" %f",&cadastro[i].peso);
							pCadastradas++;
						}
					}else{
						printf ("Quantas novas pessoas deseja cadastrar?");
						scanf (" %d",&novosCadastrados);
						for (i=pCadastradas;i<=novosCadastrados;i++) {
							printf ("\nPessoa %d\n",i+1);
							printf ("Nome: ");
							fflush(stdin);
							fgets (cadastro[i].nome,20,stdin);
							tamanho = strlen(cadastro[i].nome)-1;
							cadastro[i].nome[tamanho] = '\0';
							printf ("Codigo: ");
							scanf(" %d",&cadastro[i].codigo);
							printf("Genero [M/F]: ");
							fflush(stdin);
							scanf(" %c",&cadastro[i].genero);
							printf("Idade: ");
							scanf(" %d",&cadastro[i].idade);
							printf("Altura: ");
							scanf(" %f",&cadastro[i].altura);
							printf("Peso: ");
							scanf(" %f",&cadastro[i].peso);
						}
						n += novosCadastrados;
					}
				break;
				
				case 'B':
					if(pCadastradas>0){
						printf("Deseja alterar o cadastro de qual pessoa? *Informe o codigo*: ");
						scanf("%d",&novoCadastro);
						for(i=0;i<n;i++){
							if(cadastro[i].codigo == novoCadastro){
								do{
									printf("\t=========================================================\n");
									printf("\t|                Escolha o que deseja alterar:          |\n");
									printf("\t| [1] Nome                                              |\n");
									printf("\t| [2] Idade                                             |\n");	
									printf("\t| [3] Genero                                            |\n");
									printf("\t| [4] Codigo                                            |\n");
									printf("\t| [5] Altura                                            |\n");
									printf("\t| [6] Peso                                              |\n");
									printf("\t| [7] Sair do menu de alteracao                         |\n");
									printf("\t=========================================================\n");
									printf("Informe a opcao desejada: ");
									scanf(" %d",&menuAlteracao);
									menuAlteracao = toupper(menuAlteracao);
									
									switch(menuAlteracao){
										case 1:
											printf("Informe o novo Nome: ");
											fflush(stdin);
											fgets(cadastro[i].nome,30,stdin);
											tamanho = strlen(cadastro[i].nome)-1;
											cadastro[i].nome[tamanho] = '\0';
											printf("\nNome alterado com sucesso!\n");
										break;
										
										case 2:
											printf("Informe a nova Idade: ");
											scanf(" %d",&cadastro[i].idade);
											printf("\nIdade alterada com sucesso!\n");
										break;
										
										case 3:
											printf("Informe o novo Genero: ");
											scanf(" %c",&cadastro[i].genero);
											printf("\nGenero alterado com sucesso!\n");
										break;
										
										case 4:
											printf("Informe o novo Codigo: ");
											scanf(" %d",&cadastro[i].codigo);
											printf("\nCodigo alterado com sucesso!\n");
										break;
										
										case 5:
											printf("Informe a nova Altura");
											scanf(" %f",&cadastro[i].altura);
											printf("\nAltura alterada com sucesso!\n");
										break;
										
										case 6:
											printf("Informe o novo Peso");
											scanf(" %f",&cadastro[i].peso);
											printf("\nPeso alterado com sucesso!\n");
										break;
									}
									
									
								}while(menuAlteracao != 7);
							}else{
								printf("\nNenhuma pessoa encontrada. Informe um codigo valido!\n");
							}
						}
					}else{
						printf("Nenhuma pessoa cadastrada! *Cadastre alguem antes de acessar isto!*\n");
					}
				break;
				
				case 'C':
					if(pCadastradas>0 ){
						printf("Informe o codigo da pessoa que deseja excluir: ");
						scanf("%d",&delPessoa);
						for(i=0;i<n;i++){
							if(cadastro[i].codigo == delPessoa){
								strcpy (cadastro[i].nome,delNome);
								cadastro[i].idade = 0;
								cadastro[i].genero = '\0';
								cadastro[i].codigo = 0;
								cadastro[i].altura = 0;
								cadastro[i].peso = 0;
							}else{
								printf("\nNenhuma pessoa encontrada. Informe um codigo valido!\n");
							}
							printf("\n Pessoa Excluida com sucesso!\n");
						}
					}else{
						printf("Nenhuma pessoa cadastrada! *Cadastre alguem antes de acessar isto!*\n");
					}
				break;
				
				case 'D':
					if(pCadastradas>0){
						printf("Informe o codigo da pessoa que deseja exibir: ");
						scanf("%d",&exibirPessoa);
						for(i=0;i<n;i++){
							if(cadastro[i].codigo == exibirPessoa){
								printf ("\nPessoa %d\n",i+1);
								printf ("NOME: %s\n",cadastro[i].nome);
								printf ("IDADE: %d\n",cadastro[i].idade);
								printf ("GENERO: %c\n",cadastro[i].genero);
								printf ("CODIGO: %d\n",cadastro[i].codigo);
								printf ("ALTURA: %.2f\n",cadastro[i].altura);
								printf ("PESO: %.2f\n\n",cadastro[i].peso);
							}else{
								printf("\nNenhuma pessoa encontrada. Informe um codigo valido!\n");
							}
						}
					}else{
						printf("Nenhuma pessoa cadastrada! *Cadastre alguem antes de acessar isto!*\n");
					}
				break;
				
				case 'E':
					if (pCadastradas>0){
						for (i=0;i<n;i++){
							printf ("\nPessoa %d\n",i+1);
							printf ("NOME: %s\n",cadastro[i].nome);
							printf ("IDADE: %d\n",cadastro[i].idade);
							printf ("GENERO: %c\n",cadastro[i].genero);
							printf ("CODIGO: %d\n",cadastro[i].codigo);
							printf ("ALTURA: %.2f\n",cadastro[i].altura);
							printf ("PESO: %.2f\n\n",cadastro[i].peso);
						}
					}else if (pCadastradas == 0) {
						printf ("Nenhuma pessoa cadastrada\n");
					}
				break;
			}
		}while(menu != 'F');{
			printf("Obrigado por usar nosso sistema!");
		}

	return 0;
}
	
