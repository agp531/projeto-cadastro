#include <stdio.h>
#include <string.h>

int totalAlunos=0;

struct alunos{
	char nome[41];
	int matricula;
	float prova1;
	float prova2;
	float media;
	int faltas;
	int situacao;
};
struct alunos cadastro[40];

void inserirAlunos(){
	int i=totalAlunos,sair=0;
	do{
		printf("Nome do Aluno: ");
		getchar();
		fgets(cadastro[i].nome, 40 ,stdin);
		printf("Numero da matricula: ");
		scanf("%d",&cadastro[i].matricula);
		printf("Nota da prova 1: ");
		scanf("%f",&cadastro[i].prova1);
		printf("Nota da prova 2: ");
		scanf("%f",&cadastro[i].prova2);
		printf("Numero de faltas: ");
		scanf("%d",&cadastro[i].faltas);
		cadastro[i].media = (cadastro[i].prova1 + cadastro[i].prova2)/2;
		if(cadastro[i].media >= 6 && cadastro[i].faltas <=20){
			cadastro[i].situacao = 1;
		}else{
			cadastro[i].situacao = 0;
		}
		i++;
		totalAlunos++;
		do{
			printf("Deseja cadastrar outro aluno?\n");
			printf("[1] SIM\t[2] NAO:\n");
			scanf("%d",&sair);
		}while(sair != 1 && sair !=2);
	}while(sair != 2);
}

void listarAlunos(){
	for(int i=0;i<totalAlunos;i++){
		printf("\nAluno %d\n",i+1);
		printf("Nome: %s",cadastro[i].nome);
		printf("Matricula: %d\n",cadastro[i].matricula);
		printf("Nota prova 1: %.2f\n",cadastro[i].prova1);
		printf("Nota prova 2: %.2f\n",cadastro[i].prova2);
		printf("Media final: %.2f\n",cadastro[i].media);
		printf("Total faltas: %d\n",cadastro[i].faltas);
		if(cadastro[i].situacao == 1){
			printf("Situacao final: Aprovado\n");
		}else{
			printf("Situacao final: Reprovado\n");
		}
	}
	
}

void salvaCadastro()
{
	FILE *arq;
	
	arq = fopen("cadastro-alunos.txt","w");
	if (arq == NULL) 
	{
		fprintf(stderr,"\nErro ao abrir arquivo alunos.txt");
	}
	else
	{
	   fwrite(&cadastro[0], sizeof(struct alunos),totalAlunos,arq);
	   fclose(arq);
	}
}

int carregaCadastro()
{
	FILE *arq;
	int i, lido;
	
	arq = fopen("cadastro-alunos.txt","r");
	if (arq == NULL) 
	{
		fprintf(stderr,"\nErro ao abrir arquivo alunos.txt");
		return (-1);
	}
	else
	{
		i = 0;
		do {
			lido = fread(&cadastro[i], sizeof(struct alunos),1,arq);
			//printf("%s",cadastro[j].nome); testando se esta carregando//
			i++;
		} while (lido == 1);
		fclose(arq);
	}
	return (i-1);
}

int main(){
	int menu;
	do {
		printf("\n\t =======================================================================\n");
		printf("\t |                       Escolha a opcao desejada a seguir:            |\n");
		printf("\t |                                                                     |\n");
		printf("\t | [1] Cadastrar alunos                                                |\n");
		printf("\t | [2] Listar alunos                                                   |\n");	
		printf("\t | [3] Salvar dados                                                    |\n");
		printf("\t | [4] Carregar dados                                                  |\n");
		printf("\t | [5] Sair                                                            |\n");
		printf("\t |                                                                     |\n");
		printf("\t =======================================================================\n");
		printf("Digite a opcao: ");
		scanf("%d",&menu);
		
		switch(menu) {
			case 1:
				inserirAlunos();
			break;
			case 2:
				listarAlunos();
			break;
			
			case 3:
				salvaCadastro();
			break;
			
			case 4:
				carregaCadastro();
			break;
			
		}
		
	} while (menu != 5);
	
	
	return 0;
}


