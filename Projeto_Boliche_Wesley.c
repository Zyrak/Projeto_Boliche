#include <stdio.h>
#include <conio.h>
#include <string.h>

void menu() {
	
    system("cls");
	printf("____________________________________\n");
	printf("        --Boliche Strikez--          \n");
	printf("\n___________Menu_Principal___________\n\n");
	printf("                                    \n");
	printf(" 1 - Incluir                        \n");
	printf(" 2 - Editar                         \n");
	printf(" 3 - Excluir                        \n");
	printf(" 4 - Buscar                         \n");
	printf(" 5 - Relatorio                      \n");
	printf(" 0 - Sair                           \n");
	printf("____________________________________\n\n");
	printf("Opcao: ");
}
 
int main()
{
  	
struct cadastro{
	int ID; //ID da reserva
	int pista; //numero da pista
	char nome[50]; //nome do cliente
	char tel[15]; //telefone do cliente
	char CPF[11]; //cpf do cliente
	float valor; //valor da pista
	int status; //controle de exclusão  	
	};
	
  FILE *pont_arq;
  char texto_str[250];
  char* token;
  	
	float cont=0;
	struct cadastro C[250];
	int i=0,menurp;
	int x=0,j,pos,d;

	
  pont_arq = fopen("banco.txt", "r");
 
  while(fgets(texto_str, 250, pont_arq) != NULL) {
  	token = strtok(texto_str, "@");
   while (token != NULL) {
        
     if (x==0)   {
        //campo pista
        C[i].pista = atoi(token);
		x++;
      }else if (x==1) {
      	//campo nome
      	strcpy(C[i].nome,token);
        x++;
	  }else if (x==2) {
	  	//campo telefone
	  	strcpy(C[i].CPF,token);
		x++;
	  }else if (x==3) {
	  	//campo CPF
	  	strcpy(C[i].tel,token);
        x++;
	  }else if (x==4) {
	  	//campo Valor
        sscanf(token, "%f", &C[i].valor);
		x++;
	  }else if (x==5) {
	  	//campo status
        C[i].status = atoi(token);
		x++;
	  }
	  
        token = strtok(NULL, "@");
       
    }
     x=0;
     i++;
}
  
  fclose(pont_arq);
   
  menu(); 
  scanf("%d",&menurp);
  
  while (menurp != 0) {
  	
  	
  	switch(menurp) {
  		case 1:
  				system("cls");
				printf("___________________________________\n");
				printf("          Reserva de Pista          \n");
				printf("\n_____________Cadastro______________\n\n");
                C[i].ID = i;
				printf("ID: %d\n",C[i].ID);
				printf("Informe os dados do cliente abaixo:\n");
				printf("Nome: ");
				scanf("%s",&C[i].nome);		
				printf("Telefone: ");
				scanf("%s",&C[i].tel);		
				printf("CPF: ");
				scanf("%s",&C[i].CPF);
				printf("Numero da Pista: ");
				scanf("%d",&C[i].pista);
				printf("Valor a pagar: ");
				scanf("%f",&C[i].valor);
				printf("\n");
				C[i].status = 1;
				i++;
  			break;
  		case 2:
				system("cls");
				printf("___________________________________\n");
				printf("          Reserva de Pista          \n");
				printf("\n______________Edicao_______________\n\n");
				printf("Informe o ID para edicao: ");
  				scanf("%d",&pos);
  					printf("Numero da Pista: %d\n",C[pos].pista);
					printf("Nome do Cliente: %s\n",C[pos].nome);		
					printf("Telefone do Cliente: %s\n",C[pos].tel);		
					printf("CPF do Cliente: %s\n",C[pos].CPF);
					printf("Valor a pagar: %.2f\n\n",C[pos].valor);
					printf("___________________________________\n\n");
  			 	printf("Informe os novos dados: \n");		
				printf("ID: %d\n",C[pos].ID);
				if(C[pos].status == 1){
				printf("Status: Ativo\n");
				}else if(C[pos].status == 0){
				printf("Status: Inativo\n");
				}
				printf("Nome: ");
				scanf("%s",&C[pos].nome);		
				printf("Telefone: ");
				scanf("%s",&C[pos].tel);		
				printf("CPF: ");
				scanf("%s",&C[pos].CPF);
				printf("Numero da Pista: ");
				scanf("%d",&C[pos].pista);
				printf("Valor a pagar: ");
				scanf("%f",&C[pos].valor);

		break;
  		case 3:
  				system("cls");
				printf("___________________________________\n");
				printf("          Reserva de Pista          \n");
				printf("\n________Exclusao_de_Reserva________\n\n");
				printf("Informe o ID da reserva: ");
				scanf("%d",&pos);
				  	printf("Numero da Pista: %d\n",C[pos].pista);
					printf("Nome do Cliente: %s\n",C[pos].nome);		
					printf("Telefone do Cliente: %s\n",C[pos].tel);		
					printf("CPF do Cliente: %s\n",C[pos].CPF);
					printf("Valor a pagar: %.2f\n\n",C[pos].valor);
					printf("___________________________________\n");
					printf("Deseja realmente excluir esta reserva? \n");
					printf("1-SIM 2-NAO\nOpcao:");
					scanf("%d",&d);
					if(d==1){
					C[pos].status = 0;
					printf("Exclusao do cadastro acima realizado com sucesso!\n\n");
					system("pause");
					}
					printf("\n___________________________________\n");
					
  			
  		break;
  		case 4:
  				system("cls");
  				printf("___________________________________\n");
				printf("          Reserva de Pista          \n");
				printf("\n______________Busca_________________\n\n");
				printf("Informe o ID da reserva: ");
				scanf("%d",&pos);
				if(C[pos].status == 1){
				printf("Status: Ativo\n");
				}else if(C[pos].status == 0){
				printf("Status: Inativo\n");
				}
				printf("Numero da Pista: %d\n",C[pos].pista);
				printf("Nome do Cliente: %s\n",C[pos].nome);		
				printf("Telefone do Cliente: %s\n",C[pos].tel);		
				printf("CPF do Cliente: %s\n",C[pos].CPF);
				printf("Valor a pagar: %.2f\n",C[pos].valor);
				printf("___________________________________\n");
				
  			system("pause");
  		break;
  		case 5:
				system("cls");
				printf("\n________________________________________________________________________________\n");
				printf("                           Reserva de Pista                                      \n");
				printf("\n___________________________Relatorio_Geral______________________________________\n\n");
					
					for(j=0;j<i;j++){
					if (C[j].status == 1){
						printf("ID: %d  Nro Pista: %d  Cliente: %s  Valor: %.2f\n",j,C[j].pista,C[j].nome,C[j].valor);
						cont=cont+C[j].valor;
						}
					}
				printf("\n_____________________________Totalizador________________________________________\n");
				printf("Valor Total: %.2f\n",cont);
				printf("________________________________________________________________________________\n");
			
				system("pause");
				cont=0;
		break;
  	
  		default:
  			printf("Opcao invalida!\n");
		break;  
		
  		
	  }
  	menu();
  	scanf("%d",&menurp);  	
  	  	
  }
  
  pont_arq = fopen("banco.txt", "w");
  
  for(j=0; j<i; j++) {
  	
    if (C[j].status == 1){
	  	fprintf(pont_arq,"%d@%s@%s@%s@%.2f@%d\n", C[j].pista, C[j].nome, C[j].CPF, C[j].tel, C[j].valor, C[j].status);
    }
  }
  
  fclose(pont_arq);
  
}
