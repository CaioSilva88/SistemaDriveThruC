#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
#include<windows.h>
#include<dos.h>
#include<dir.h>

float lanche1 = 9.50;
float lanche2 =8.50;
float lanche3 =7.50;
float total_lanche1=0;
float total_lanche2=0;
float total_lanche3=0;
float total_compra=0;
int opcao;
int quantidade =0;
int escolha=0;
float compra_final=0;
int pagamento;

int validacao(){
	char cartao[16];
	int tamanho;
	 FILE *cat=fopen("Cartao.txt", "w+");
	do{
		printf("\nDigite o numero de seu cart�o:");
		scanf("%s",&cartao);
		
		tamanho=strlen(cartao);
		putchar(cartao[4]='*');
		putchar(cartao[5]='*');
		putchar(cartao[6]='*');
		putchar(cartao[7]='*');
		putchar(cartao[8]='*');
		putchar(cartao[9]='*');
		putchar(cartao[10]='*');
		putchar(cartao[11]='*');
	
		if(tamanho!=16){
			system("cls");
			printf("\n Numero de cart�o inv�lido!");
		}
		else{
			
			printf("\nNumero de cart�o validado!\n");
			printf("\n Total pago em Cart�o");
			fprintf(cat,"\n Pagamento efetuado com cart�o\n Numero:%s", cartao);
		}
		
	}while(tamanho!=16);
}

int main(void)
 {
 	
 	FILE *file= fopen("Produtos.txt","w+");
 	setlocale(LC_ALL,"portuguese");
 	printf("\n Bem-Vindo(a) ao Drive Thru do Mickey & Donalds!\n");
 	do{
	 
 	printf("\n Esse � o nosso card�pio. Por favor, escolha qual deseja:\n");
 	printf("\n Para sair, digite '0' e d� <Enter>\n\n");
 	printf("\n Op��o 1 - Mic Burguer.............R$9.50");
 	printf("\n Op��o 2 - Mic Duplo Furioso.......R$8.50");
 	printf("\n Op��o 3 - Mic Chicken.............R$7.50\n");
 	scanf("%i", &opcao);
 		if(opcao>3){
		 
 			printf("\nOp��o escolhida � inv�lida");
 			return 0;}
 			else
 		 
 	switch(opcao)
	  {
	case 0:
	 	printf("\n Obrigado. Volte semmpre!");
	 	return 0;
	 	break;
	case 1:
		system("cls");
		printf("\n Op��o escolhida: Mic Burguer....R$9.50");
		printf("\n Por favor, informe quantos deseja:\n");
		scanf("%i", &quantidade);
		if(quantidade==0){
			printf("\n Nenhum lanche pedido! Pedido finalizado");
			return 0;
		}else
		system("cls");
		printf("Registramos seu pedido!");
		total_lanche1= lanche1*quantidade;
		fprintf(file, "Lanche selecionado: Mic burguer");
		fprintf(file,"\nQuantidade de Mic Burguer: %i", quantidade);
		fprintf(file,"\nO valor unit�rio �: R$9,50");
		
		
		break;
	case 2:
		system("cls");
		printf("\n Op��o escolhida: Mic Duplo Furioso....R$8.50");
		printf("\n Por favor, informe quantos deseja:\n");
		scanf("%i", &quantidade);
			if(quantidade==0){
			printf("\n Nenhum lanche pedido! Pedido finalizado");
			return 0;
		}else
		system("cls");
		printf("Registramos seu pedido!");
		total_lanche2= lanche2*quantidade;
		fprintf(file,"\nLanche selecionado: Mic Duplo Furioso");
		fprintf(file,"\nQuantidade de Mic Duplo Furioso: %i", quantidade);
		fprintf(file,"\n O valor unit�rio �: R$8,50");
		break;
	case 3:
		system("cls");
		printf("\n Op��o escolhida: Mic Chicken....R$7.50");
		printf("\n Por favor, informe quantos deseja:\n");
		scanf("%i", &quantidade);
			if(quantidade==0){
			printf("\n Nenhum lanche pedido! Pedido finalizado");
			return 0;
		}else
		system("cls");
		printf("Registramos seu pedido!");
		total_lanche3=lanche3*quantidade;
		fprintf(file,"\nLanche selecionado: Mic Chicken");
		fprintf(file,"\nQuantidade de Mic Chicken: %i", quantidade);
		fprintf(file,"\nO valor unit�rio �: R$7,50");
		break; 
	 }

    
	 printf("\nDeseja Finalizar compra?\n");
	 printf("\n 1-sim");
	 printf("\n2-n�o");
	 scanf("%i", &escolha);
	 system("cls");
	
	 	if(escolha==1){
	 	printf("\nEstamos finalizando seu pedido!");
	 	compra_final=total_lanche1+total_lanche2+total_lanche3;
	 	fprintf(file,"\nO valor total deu:R$ %.2f\n", compra_final);
		}else if(escolha>2)
		{  printf("\n Escolha inv�lida!");
		return 0;
		}else if(escolha<1)
		{ printf("\n Escolha inv�lida!");
		return 0;
		}
	
}while(escolha==2);
	int i;
	srand(time(NULL));
	for(i=0;i<1;i++){
		fprintf(file,"\nSeu c�digo de pedido �: %d", rand()%1000);
		
	}

 SetConsoleTitle("Cores com system");
 FILE *fil=fopen("Pagamento.txt","w+");
 printf("\n\n Estamos quase acabando! Por favor, informe a forma de pagamento:\n");
 printf("\n O valor total foi de:R$%.2f\n", compra_final);
 printf("\n 1 - Dinheiro   \n 2 - Cart�o Cr�dito\n 3 - Cart�o D�bito \n 4 - Cheque\n");
 scanf("%i", &pagamento);
 	if(pagamento==1)
 	{
 		printf("\nTotal pago em: Dinheiro");
 		fprintf(fil,"Pagamento em Dinheiro\n");
 		fprintf(fil,"O valor pago foi de:R$%.2f", compra_final);
 		system("cls");
 		system("color 2");
 		printf("\nPedido pago com: Dinheiro");
 		
	 }
	 else if(pagamento==2){
			  
	 	printf("\n Pagamento  em Cart�o Cr�dito\n");
	 	validacao();
	 	system("cls");
	 	system("color D");
	 	printf("\nPedido pago com Cart�o Cr�dito");
	 	fprintf(fil,"\n Pagamento em Cart�o Cr�dito");
	 	fprintf(fil,"\nO valor total pago foi de: R$%.2f", compra_final);
	 	}
	 	
	 	else if(pagamento==3){
	 		printf("\n Pagamento com: Cart�o D�bito\n");
	 		validacao();
	 			system("cls");
	 	system("color D");
	 	printf("\nPedido pago com Cart�o D�bito");
	 		fprintf(fil,"\n Pagamento em Cart�o D�bito\n");
	 		fprintf(fil,"\nO valor total pago foi de:R$%.2f", compra_final);

		 }
	     else if(pagamento==4){
	     	system("cls");
	     	system("color 9");
	     	printf("\n Pedido pago com: Cheque\n");
	     	
	     	fprintf(fil,"\nPagamento em Cheque\n");
	     	fprintf(fil,"\nO valo total pago foi de:R$%.2f", compra_final);
		 } else if(pagamento>4){
		 	system("cls");
		 	printf("\n Forma de pagamento inexistente!");
		 	return 0;
		 }else if(pagamento<1){
		 	system("cls");
		 	printf("\n forma de pagamento inexistente!");
		 	return 0;
		 }
		 
}
 	
	

	

 
 
 	
 	
 	
 
