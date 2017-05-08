#include <iostream>
#include <stdlib.h>
#include <sys/time.h>		// Nem todos os compiladores rodam esta biblioteca no WINDOWS
#include <fstream>


using namespace std;
/*
*	este programa mede o tempo de que o computador leva para atribuir um certo valor
*	a um vetor dinamico grande.
*/

int main(){

int tam = 1000;		   
int cont = 0;		   
double total = 0;	   
double media ;		   
double t1,t2;	   	   

ofstream fout("tempoEstaticoLINUX.dat");

struct timeval time;	// esta variavel sera usada pela função gettimeofday

while(tam < 2000000){                                   // inicio do laco de incremento do vetor   
		while(cont < 50){                                   // inicio do laco de incremento da variavel cont
			gettimeofday(&time, NULL);        	            // marca o tempo inicial
			t1 = (double)(time.tv_sec + time.tv_usec/1e6);    // t1 recebe o valor do tempo antes das atribuicoes
			int i[tam];	                                    
			i[0] = 0;		
			
			for(int j = 1 ;j <= tam; j++){         // inicio do laco de atribuicao do vetor
				i[j] = 0;	                
			}		   // fim do laco de atribuicao do vetor

		   gettimeofday(&time, NULL);   // marca o tempo final	
		   t2 = (double)(time.tv_sec + time.tv_usec/1e6);   // t2 recebe o valor do tempo apos as atribuicoes 
		   total += t2 - t1;     // total eh incrementado com a diferenca os tempos           
		   cont++;                                               
		}   // fim do laco de incremento da variavel cont

		media = total/50;                                    
		cout << tam<< "\t"<< 1000*media<< endl;		//saida pelo terminal
		fout << tam <<"   " << 1000*media<< endl;	//saida por arquivo
		tam += 1000;	
		total = 0;
		cont = 0;
	}
fout.close();
}
