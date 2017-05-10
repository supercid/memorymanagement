#include "lista.h"
#include <sys/time.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(){

int tam = 0, cont;
double t1, t2, media, total = 0;
struct timeval time;
ofstream fout("tempo_Lista_linux.dat");

while(tam < 2000000){
	while(cont < 50){

		lista list;	
		gettimeofday(&time, NULL);
		t1 = (double)(time.tv_sec + (time.tv_usec/1e6));
	
		for(int i = 0; i < tam; i++){
			list.headInsert(0);
		}
		gettimeofday(&time, NULL);
		t2 = (double)(time.tv_sec + (time.tv_usec/1e6));
		total += t2 - t1;
		cont++;	
	}
		media = total/50;                                    
		cout << tam<< "\t"<< 1000*media<< endl;
		fout << tam <<"   " << 1000*media<< endl;
		tam += 1000;	
		total = 0;
		cont = 0;
}
   fout.close();

return 0;
}
