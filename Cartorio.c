#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de aloacação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel pelas strings
	
int registro()//int função=
{
	char arquivo[40]; //char variavel
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF do usuário a ser cadastrado:" );
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

	printf("Digite o CPF do usuário a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//"r" lê o arquivo
	
	if(file == NULL)
	{
		printf("Usuário não encontrado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//fgets busca arquivo
	{
		printf("\n Informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar()
{
	char cpf[40];
	printf("Digite o CPF do usuário a ser deletado: \n");
	scanf("%s", &cpf);
	
	FILE *file; 
	file = fopen(cpf, "r");

	if (file == NULL)
	{
		printf("Usuário não encontrado! \n");
		system("pause");
		fclose(file);
	}
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usuário deletado com sucesso! \n");
		system("pause");
	}
	
}
	
	int main()
	{	
		int opcao=0;//Definindo variáveis =
		int laco=1;
	
		for(laco=1;laco=1;)//for=enquanto
		{
	
			system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
			printf("### Central De Usuários ###\n\n");  //printf=texto  /n=pular linha
			printf("Escolha a opção desejada:\n\n");
			printf("\t1- Registrar Usuários\n");  // "/"paragrafo
			printf("\t2- Consultar Usuários\n");
			printf("\t3- Deletar Usuários\n\n");
			printf("Opção: ");
		
			scanf("%d", &opcao);//armazena informações
	
			system("cls"); //cls limpa a tela
	
	
			switch(opcao)
			{
				case 1://chama funções
				registro();
				break;
		
				case 2:
				consulta();
				break;
		
				case 3:
				deletar();
				break;
			
				default:
				printf("Essa opção está indisponivel!\n");
				system("pause");
				break;
			}
			
   		 }
	}
