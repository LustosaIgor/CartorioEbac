#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloaca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel pelas strings
	
int registro()//int fun��o=
{
	char arquivo[40]; //char variavel
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF do usu�rio a ser cadastrado:" );
	scanf("%s", cpf);//%s armzena string
	
	strcpy(arquivo,cpf); //strcpy copia o valor das strings
	
	FILE *file; //FILE biblioteca\file arquivo
	file = fopen(arquivo, "w"); //"w"escreve o arquivo\fopen abre o arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("Nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");

	
	char cpf[40];
	char conteudo[200];

	printf("Digite o CPF do usu�rio a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//"r" l� o arquivo
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//fgets busca arquivo
	{
		printf("\n Informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar()
{
	char cpf[40];
	printf("Digite o CPF do usu�rio a ser deletado: \n");
	scanf("%s", &cpf);
	
	FILE *file; 
	file = fopen(cpf, "r");

	if (file == NULL)
	{
		printf("Usu�rio n�o encontrado! \n");
		system("pause");
		fclose(file);
	}
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usu�rio deletado com sucesso! \n");
		system("pause");
	}
	
}
	
	int main()
	{	
		int opcao=0;//Definindo vari�veis =
		int laco=1;
	
		for(laco=1;laco=1;)//for=enquanto
		{
	
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
			printf("### Central De Usu�rios ###\n\n");  //printf=texto  /n=pular linha
			printf("Escolha a op��o desejada:\n\n");
			printf("\t1- Registrar Usu�rios\n");  // "/"paragrafo
			printf("\t2- Consultar Usu�rios\n");
			printf("\t3- Deletar Usu�rios\n\n");
			printf("Op��o: ");
		
			scanf("%d", &opcao);//armazena informa��es
	
			system("cls"); //cls limpa a tela
	
	
			switch(opcao)
			{
				case 1://chama fun��es
				registro();
				break;
		
				case 2:
				consulta();
				break;
		
				case 3:
				deletar();
				break;
			
				default:
				printf("Essa op��o est� indisponivel!\n");
				system("pause");
				break;
			}
			
   		 }
	}
