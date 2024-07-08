//Primeiro deve-se incluir bibliotecas ao seu c�digo.
#include <stdio.h> //Biblioteca de comunica��o de usu�rio.
#include <stdlib.h> //Biblioteca de aloca��o de Mem�ria.
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o.
#include <string.h> //Biblioteca respons�vel por cuidar das string

//fun��es para serem chamadas.
int registro()
{
	setlocale(LC_ALL, "portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);           //Aqui coletamos os Atr�ves do 'scanf("%s" ' o cpf e depois colocamos ele no CHAR CPF ',cpf);'
	
	strcpy(arquivo, cpf); 		//Responsalvel por copiar os valores da string.
	
	FILE *file; 				//Comando para acessar um arquivo de determinado como uma busca, e depois criar um arquivo.
	file = fopen(arquivo, "w"); //'= fopen' dentro do aquivo aberto, indica que iremos escrever W de WRITE.
	fprintf(file,cpf); 			//salva o valor da variavel.
	fclose(file); 				//fecha o aquivo.
	
	file = fopen(arquivo, "a"); //'= fopen' dentro do aquivo aberto, indica que iremos Acrescentar 'A' No caso acresentamos uma virgula para identa��o.
	fprintf(file,","); 
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",	nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);	
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s",	sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s",	cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF do aluno a ser consultado: ");
	scanf("%s", cpf);         //salvando oque o usuario digitar no comando %s e guardando na v�riavel 'cpf'

	FILE *file;
	file = fopen(cpf,"r");   //O programa esta buscando no file, no caso arquivo, abrindo ele e lendo com 'r' a v�riavel cpf dentro do arquivo que ja foi criado pr�viamente.
	
	
	if(file == NULL)      //SE n�o foi encontrado nenhum valor em CPF, vai acionar o print. (==) Igual/compara��o.
	{
		printf("N�o foi localizado nenhum CPF.\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\n Essas S�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "portuguese"); // colocando a linguaguem para portugu�s na sa�da.
	
	char cpf[40]; //criando uma vari�vel cpf que n�o conversa com nenhuma outra
	
	printf("Digite o CPF do usu�rio que dejesa deletar: ");
	scanf("%s", cpf); //recebendo oque o usu�rio digitar e guardando na v�riavel cpf que foi criada acima.
	
	FILE *file; 
	file = fopen(cpf, "r"); //abre o arquivo atr�ves do 'fopen' especifica que dentro do arquivo ele vai ler oque est� escrito no cpf atrav�s da fun��o 'r' = 'read'  = Ler

	if(file == NULL)
	{
		printf("Este cpf n�o foi encontrado no sistema.\n");
		system("pause");
	}
	else // Se n�o ele executa as instru��es a baixo.
	{
		fclose(file); //fecha o arquivo que foi aberto acima. (Ajuda a otimizar o sistema.)
	}
		if (remove(cpf) == 0)  //remove(cpf) tenta deletar o arquivo que � armazenado em cpf, se conseguir ele retorna 0 com  == de compara��o e executa o comando a baixo.
		{
    		printf("O usu�rio com CPF %s foi exclu�do com sucesso.\n", cpf);	
			system("pause");
		} 
		else //se n�o ele executa oque esta em baixo.
		{
    		printf("Erro ao excluir o usu�rio com CPF %s.\n", cpf);
			system("pause");
		}
		

}

int sairdoprograma()
{
	printf("Saindo do C�rtorio EBAC.....");
	exit(0); //fecha a aplica��o.
		
}

//fim das fun��es.

//Fun��o principal que sempre aparece.
int main() //comando principal da nossa aplica��o.
	{
		int opcao=0; //definindo v�riaveis.
		int laco=1;//v�riavel do la�o com valor 1 
		char senhadigitada[10]="a";
		int comparacao;
	
		//Come�o da valida��o, fazendo o pedido de senha e logo ap�s validando. 
		setlocale(LC_ALL, "portuguese");
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Login de Administrador\n\n");
		printf("Digite a sua senha: ");
		scanf("%s", senhadigitada); //captura atr�ves do %s que captura string digitada pelo usu�rio e joga dentro da variavel'senha digitada'
		
		comparacao = strcmp(senhadigitada, "admin");// l�gia de compara��o que n�o entendi ainda.
		
		if(comparacao == 0) //'SE' a variavel 'comparadacao' for igual a *0*, 0 quer dizer que � igual a senha digitada a compara��o feita pela variavel 'comparacao' ele executa normal o programa
		{
			for(laco=1;laco=1;) //la�o de repeti��o 'FOR' para repetir sempre com valor 1  e equanto estiver 1 ele repete.
				{
					system("cls"); //comando para limpar interface
					
		  	 		setlocale(LC_ALL, "portuguese"); //definindo a linguagem. (Dentro da fun��o)
			 
			 		printf("### Cart�rio da EBAC ### \n\n");//Inicio do menu
			 		printf("Escolha a op��o desejada do menu: \n\n");
				 	printf("\t 1 - Registrar nomes. \n");
					printf("\t 2 - Consultar nomes. \n");
					printf("\t 3 - Deletar nomes. \n"); 
					printf("\t 4 - Sair do Programa. \n\n"); 
					printf("Digite a op��o que voc� deseja:"); //Fim do menu.
				
					scanf("%d", &opcao); // armazenando escolha do usu�rio / scanf = comando de captura, codigo = '&d' para capturar somente numeros inteiros.
				
					system("cls"); //comando para limpar interface para entrada das op��es do menu.
				
					//Op��es do menu abaixo.
					
					switch(opcao) //comando para agrupar escolhas do menu.
					{
						case 1:
							registro(); //*chamada de fun��o*
							break; //fim do primeiro caso
							
						case 2:
							consulta(); //*chamada de fun��o*
							break; //fim do primeiro caso
							
						case 3:
							deletar(); //*chamada de fun��o*
							break; //fim do terceiro caso
							
						case 4:
							sairdoprograma();//*chamada de fun��o*
							break;	//fim do quarto caso.
							
						default: //se o usu�rio n�o usar nenhum desses casos acima, default � acionado com a opera��o de aviso.
							printf("Esta op��o n�o est� disponivel.\n");
							system("pause");
							break; //fim do ultimo caso	
					}
					
				}
		}
		else //"se n�o" ele executa essas linhas abaixo
			printf("Senha Incorreta.\n"); 
			sairdoprograma(); //chamando fun��o de sair do programa
		
	}
