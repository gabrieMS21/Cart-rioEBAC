//Primeiro deve-se incluir bibliotecas ao seu código.
#include <stdio.h> //Biblioteca de comunicação de usuário.
#include <stdlib.h> //Biblioteca de alocação de Memória.
#include <locale.h> //Biblioteca de alocação de texto por região.
#include <string.h> //Biblioteca responsável por cuidar das string

//funções para serem chamadas.
int registro()
{
	setlocale(LC_ALL, "portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);           //Aqui coletamos os Atráves do 'scanf("%s" ' o cpf e depois colocamos ele no CHAR CPF ',cpf);'
	
	strcpy(arquivo, cpf); 		//Responsalvel por copiar os valores da string.
	
	FILE *file; 				//Comando para acessar um arquivo de determinado como uma busca, e depois criar um arquivo.
	file = fopen(arquivo, "w"); //'= fopen' dentro do aquivo aberto, indica que iremos escrever W de WRITE.
	fprintf(file,cpf); 			//salva o valor da variavel.
	fclose(file); 				//fecha o aquivo.
	
	file = fopen(arquivo, "a"); //'= fopen' dentro do aquivo aberto, indica que iremos Acrescentar 'A' No caso acresentamos uma virgula para identação.
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
	scanf("%s", cpf);         //salvando oque o usuario digitar no comando %s e guardando na váriavel 'cpf'

	FILE *file;
	file = fopen(cpf,"r");   //O programa esta buscando no file, no caso arquivo, abrindo ele e lendo com 'r' a váriavel cpf dentro do arquivo que ja foi criado préviamente.
	
	
	if(file == NULL)      //SE não foi encontrado nenhum valor em CPF, vai acionar o print. (==) Igual/comparação.
	{
		printf("Não foi localizado nenhum CPF.\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\n Essas São as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "portuguese"); // colocando a linguaguem para português na saída.
	
	char cpf[40]; //criando uma variável cpf que não conversa com nenhuma outra
	
	printf("Digite o CPF do usuário que dejesa deletar: ");
	scanf("%s", cpf); //recebendo oque o usuário digitar e guardando na váriavel cpf que foi criada acima.
	
	FILE *file; 
	file = fopen(cpf, "r"); //abre o arquivo atráves do 'fopen' especifica que dentro do arquivo ele vai ler oque está escrito no cpf através da função 'r' = 'read'  = Ler

	if(file == NULL)
	{
		printf("Este cpf não foi encontrado no sistema.\n");
		system("pause");
	}
	else // Se não ele executa as instruções a baixo.
	{
		fclose(file); //fecha o arquivo que foi aberto acima. (Ajuda a otimizar o sistema.)
	}
		if (remove(cpf) == 0)  //remove(cpf) tenta deletar o arquivo que é armazenado em cpf, se conseguir ele retorna 0 com  == de comparação e executa o comando a baixo.
		{
    		printf("O usuário com CPF %s foi excluído com sucesso.\n", cpf);	
			system("pause");
		} 
		else //se não ele executa oque esta em baixo.
		{
    		printf("Erro ao excluir o usuário com CPF %s.\n", cpf);
			system("pause");
		}
		

}

int sairdoprograma()
{
	printf("Saindo do Cártorio EBAC.....");
	exit(0); //fecha a aplicação.
		
}

//fim das funções.

//Função principal que sempre aparece.
int main() //comando principal da nossa aplicação.
	{
		int opcao=0; //definindo váriaveis.
		int laco=1;//váriavel do laço com valor 1 
		char senhadigitada[10]="a";
		int comparacao;
	
		//Começo da validação, fazendo o pedido de senha e logo após validando. 
		setlocale(LC_ALL, "portuguese");
		printf("### Cartório da EBAC ###\n\n");
		printf("Login de Administrador\n\n");
		printf("Digite a sua senha: ");
		scanf("%s", senhadigitada); //captura atráves do %s que captura string digitada pelo usuário e joga dentro da variavel'senha digitada'
		
		comparacao = strcmp(senhadigitada, "admin");// lógia de comparação que não entendi ainda.
		
		if(comparacao == 0) //'SE' a variavel 'comparadacao' for igual a *0*, 0 quer dizer que é igual a senha digitada a comparação feita pela variavel 'comparacao' ele executa normal o programa
		{
			for(laco=1;laco=1;) //laço de repetição 'FOR' para repetir sempre com valor 1  e equanto estiver 1 ele repete.
				{
					system("cls"); //comando para limpar interface
					
		  	 		setlocale(LC_ALL, "portuguese"); //definindo a linguagem. (Dentro da função)
			 
			 		printf("### Cartório da EBAC ### \n\n");//Inicio do menu
			 		printf("Escolha a opção desejada do menu: \n\n");
				 	printf("\t 1 - Registrar nomes. \n");
					printf("\t 2 - Consultar nomes. \n");
					printf("\t 3 - Deletar nomes. \n"); 
					printf("\t 4 - Sair do Programa. \n\n"); 
					printf("Digite a opção que você deseja:"); //Fim do menu.
				
					scanf("%d", &opcao); // armazenando escolha do usuário / scanf = comando de captura, codigo = '&d' para capturar somente numeros inteiros.
				
					system("cls"); //comando para limpar interface para entrada das opções do menu.
				
					//Opções do menu abaixo.
					
					switch(opcao) //comando para agrupar escolhas do menu.
					{
						case 1:
							registro(); //*chamada de função*
							break; //fim do primeiro caso
							
						case 2:
							consulta(); //*chamada de função*
							break; //fim do primeiro caso
							
						case 3:
							deletar(); //*chamada de função*
							break; //fim do terceiro caso
							
						case 4:
							sairdoprograma();//*chamada de função*
							break;	//fim do quarto caso.
							
						default: //se o usuário não usar nenhum desses casos acima, default é acionado com a operação de aviso.
							printf("Esta opção não está disponivel.\n");
							system("pause");
							break; //fim do ultimo caso	
					}
					
				}
		}
		else //"se não" ele executa essas linhas abaixo
			printf("Senha Incorreta.\n"); 
			sairdoprograma(); //chamando função de sair do programa
		
	}
