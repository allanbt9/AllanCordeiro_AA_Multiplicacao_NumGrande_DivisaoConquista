#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
multiplicação de um inteiro u por um inteiro v com
no máximo n dígitos.
*/

/*a função pegarTeto serve para
pegar o teto de um numero dado
caso esse numero seja inteiro ele retorna o proprio numero

*/

int pegarTeto(double num){
	if(num < 1)
		return 1;

	int parteInteira = num;

	double result = num / parteInteira;

	if(result == 1)
		return num;

	else
		return (parteInteira+1);
	

}

int karatsuba(int u, int v, int n){
	if(n <= 3){
		return (u*v);
	}else{
		int m = pegarTeto(n/2);

		float pegar = pow(10,m);
		int aux = pegar;

		int p = u/aux;
		int q = (u % aux);

		int r = v / aux;
		int s = v % aux;

		int pr = karatsuba(p, r, m);
		int qs = karatsuba(q, s, m);
		int y = karatsuba(p+q, r+s, m+1);

		int elv = 2 * m;
		float pegar2 = pow(10,elv);
		int aux2 = pegar2;

		int x = (pr * aux2) + ((y - pr - qs) * aux) + qs;

		return x;	
	}
}


int main(){
	int u = 3458;

	int v = 5543;

	int n = 4;

	printf("multiplicacao sem a funcao:\n");
	printf("result1: %d\n",u * v);

	printf("\nmultiplicacao com a funcao:\n");
	printf("result2: %d\n",karatsuba(u, v, n));

	return 0;
}
