#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //blibioteca de alocac�es de texto por regi�o
#include <string.h> // biblioteca da string

int registro ()// fun��o do registro de nomes
{
	 setlocale(LC_ALL, "Portuguese"); 
	//criando vari�veis
	char informacao [40];
	char arquivo [40];
	char cpf [40];	
	char nome [50];
	char sobrenome [55];
	char cargo [40];
	int laco2=1;
	 //fim da cria��o
	 
	printf ("/tDigite o CPF a ser cadastrado:\n ");//coletando informa��o do usu�rio
	scanf ("%s", cpf);//%s=string
	
	strcpy(arquivo, cpf); //copia os valores das strings
	
	FILE *file; // cria/recebe o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo e "w"=escrever o que significa que estamos criando o arquivo
	fprintf(file, cpf); // salva o valor da vari�vel
	fclose (file); // fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o aqruivo e usa o "a" para atualizar
	fprintf(file,",");// adiciona a v�rgula
	fclose (file);//fecha o arquivo
	
	printf ("Digite o nome a ser cadastrado:\n ");
	scanf ("%s", nome);
	
	file = fopen(arquivo, "a");//abre o aqruivo e o atualiza
	fprintf(file,nome);// adicionando informaa��es do aluno ao arquivo
	fclose (file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e o atualiza
	fprintf(file,",");
	fclose (file);//fecha o arquivo

	printf ("digite o sobrenome a ser cadastrado:\n ");//coletando informa��es do usu�rio
	scanf("%s", sobrenome);//armazenando informa��es na string
	
	file = fopen (arquivo, "a");
	fprintf (file, sobrenome);
	fclose (file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose (file);
	
	printf ("Digite o cargo a ser cadastrado:\n ");
	scanf ("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf (file, cargo);
	fclose (file);
	

	system ("pause");//pausa o sistema para podermos visualiza-lo 
	
}
	
int consulta ()//fun��o da consulta
{ 
     setlocale(LC_ALL, "Portuguese"); //linguagem
 
	char cpf [40];//definindo valor das vari�veis
	char conteudo [200];
	
	printf ("Digite o cpf a ser consultado:\n ");//coletando informa��es
	scanf ("%s", cpf);//armazenando-as
	
	FILE *file;//criando o arquivo
	file = fopen (cpf, "r");// o "r" � de read (ler), para "lembrar" do arquivo digamos assim
	
	if (file == NULL)//definindo condi��es
	{
		printf ("\t\tUsu�rio n�o localizado\n");
	}
	  
	  	printf ("\nEsses s�o os dados do usu�rio correspodente:\n ");
		    
    while (fgets(conteudo, 200, file) !=NULL);
	{
		printf ("%s", conteudo);
		printf ("\n\n\n;)\n");
	}

	system ("pause");//pausando o sistema	
}

int deletar ()
{
	char cpf [40];
    int resposta = 0;
	
	printf ("digite o CPF do usu�rio a ser deletado:\n");
	scanf ("%d", cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	if (file == NULL);
	{
		printf ("este usu�rio n�o est� no sistema.\n");
	}
	
	system ("pause");
}

int main()
{
	int opcao=0; // definindo as vari�veis.
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	 printf ("### cart�rio da EBAC ###\n\n");
	 printf ("Login de admin!\n\nDigite sua senha: ");
	 scanf("%s", senhadigitada);
	 
	 comparacao = strcmp(senhadigitada, "admin");
	 
	 if (comparacao == 0)
	 {
	  
    	for (laco=1;laco=1;)
	 {
		
	   system ("cls");
	  
	     setlocale(LC_ALL, "Portuguese"); // definindo a linguagem	
         printf ("### cart�rio da EBAC ###\n\n");//in�cio do menu
      	 printf ("escolha a op��o desejada do menu:\n\n");
     	 printf ("\t1 - Registrar nomes\n");
    	 printf ("\t2 - Consultar nomes\n");
	     printf ("\t3 - deletar nomes\n");//�ltima opc�o do menu
	     printf ("\t4 - sair\n\n");
    	 printf ("op��o:");
	
         scanf  ("%d", &opcao); // armazenando a escolha do usu�rio
    
         system ("cls");//limpa a tela
        
         switch(opcao)
         {
             case 1:
             registro();
         	 break;
         	
             case 2:
             consulta();
         	 break;
         	
             case 3:
         	 deletar();
		     break;
		    
		     case 4:
		     printf ("obrigado por utilizar o sistema\n");
		     return 0;
		     break;
		     
		     default:
		     printf ("\t\tN�mero inv�lido, tente novamente\n");
		     system ("pause");
		     break;
          } 
    
        }
        
	
     }
     
     
	 else;
	  {
	  	printf ("senha incorreta");
	  }
	  
        
}
     
