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
int i=4;

int validacao(){
	char cartao[16];
	int tamanho;
	 FILE *cat=fopen("Cartao.txt", "w+");
	do{
		printf("\nDigite o numero de seu cartão:");
		scanf("%s",&cartao);
		
		
		
		tamanho=strlen(cartao);
		for(i=4;i<12;i++){
			putchar(cartao[i]='*');
		}
		
	
			if(tamanho!=16){
			system("cls");
			printf("\n Numero de cartão inválido!");
		}
		else{
			
			printf("\nNumero de cartão validado!\n");
			printf("\n Total pago em Cartão");
			fprintf(cat,"\n Pagamento efetuado com cartão\n Numero:%s", cartao);
		}
		
	}while(tamanho!=16);
}

int main(void)
 {
 	
 	FILE *file= fopen("Produtos.txt","w+");
 	setlocale(LC_ALL,"portuguese");
 	printf("\n Bem-Vindo(a) ao Drive Thru do Mickey & Donalds!\n");
 	do{
	 
 	printf("\n Esse é o nosso cardápio. Por favor, escolha qual deseja:\n");
 	printf("\n Para sair, digite '0' e dê <Enter>\n\n");
 	printf("\n Opção 1 - Mic Burguer.............R$9.50");
 	printf("\n Opção 2 - Mic Duplo Furioso.......R$8.50");
 	printf("\n Opção 3 - Mic Chicken.............R$7.50\n");
 	scanf("%i", &opcao);
 		if(opcao>3){
		 
 			printf("\nOpção escolhida é inválida");
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
		printf("\n Opção escolhida: Mic Burguer....R$9.50");
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
		fprintf(file,"\nO valor unitário é: R$9,50");
		
		
		break;
	case 2:
		system("cls");
		printf("\n Opção escolhida: Mic Duplo Furioso....R$8.50");
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
		fprintf(file,"\n O valor unitário é: R$8,50");
		break;
	case 3:
		system("cls");
		printf("\n Opção escolhida: Mic Chicken....R$7.50");
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
		fprintf(file,"\nO valor unitário é: R$7,50");
		break; 
	 }

    
	 printf("\nDeseja Finalizar compra?\n");
	 printf("\n 1-sim");
	 printf("\n2-não");
	 scanf("%i", &escolha);
	 system("cls");
	
	 	if(escolha==1){
	 	printf("\nEstamos finalizando seu pedido!");
	 	compra_final=total_lanche1+total_lanche2+total_lanche3;
	 	fprintf(file,"\nO valor total deu:R$ %.2f\n", compra_final);
		}else if(escolha>2)
		{  printf("\n Escolha inválida!");
		return 0;
		}else if(escolha<1)
		{ printf("\n Escolha inválida!");
		return 0;
		}
	
}while(escolha==2);
	int i;
	srand(time(NULL));
	for(i=0;i<1;i++){
		fprintf(file,"\nSeu código de pedido é: %d", rand()%1000);
		
	}

 SetConsoleTitle("Cores com system");
 FILE *fil=fopen("Pagamento.txt","w+");
 printf("\n\n Estamos quase acabando! Por favor, informe a forma de pagamento:\n");
 printf("\n O valor total foi de:R$%.2f\n", compra_final);
 printf("\n 1 - Dinheiro   \n 2 - Cartão Crédito\n 3 - Cartão Débito \n 4 - Cheque\n");
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
			  
	 	printf("\n Pagamento  em Cartão Crédito\n");
	 	validacao();
	 	system("cls");
	 	system("color D");
	 	printf("\nPedido pago com Cartão Crédito");
	 	fprintf(fil,"\n Pagamento em Cartão Crédito");
	 	fprintf(fil,"\nO valor total pago foi de: R$%.2f", compra_final);
	 	}
	 	
	 	else if(pagamento==3){
	 		printf("\n Pagamento com: Cartão Débito\n");
	 		validacao();
	 			system("cls");
	 	system("color D");
	 	printf("\nPedido pago com Cartão Débito");
	 		fprintf(fil,"\n Pagamento em Cartão Débito\n");
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
