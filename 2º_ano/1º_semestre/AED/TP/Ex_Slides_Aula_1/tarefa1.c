#include <stdio.h>
/*

	   Tarefa 1 – Calculadora simples
	
	Desenvolva um programa que implemente uma calculadora simples
	que permite ao utilizador escolher a operação (+, −, ×, ÷) e introduzir o
	valor dos dois operandos (valores inteiros).
	A operação ÷ corresponde à divisão real.

*/

int main(void){
	double num1, num2;
	char op;
	printf("Insira um número: ");
	scanf("%lf",&num1);
	printf("Insira a operação ( +, -, ×, ÷): ");
	scanf(" %c",&op);
	printf("Insira outro número: ");
	scanf("%lf", &num2);
	double resposta;
	switch(op){
		case '+':
			resposta = num1+num2;
			break;
		case '-':
			resposta = num1-num2;
			break;
		case 'x':
			resposta = num1*num2;
			break;
		case '/':
			resposta = num1/num2;
			break;
		default:
			printf("Operação inválida...");
	}
	printf("\nResposta de %.2f %c %.2f = %.2f\n", num1, op, num2, resposta);
	return 0;
}
