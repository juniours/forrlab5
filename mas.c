#include "mas.h"

#define N 35

int mass(){
	srand(time(NULL));
	int min=0,i, m[N];
	for(i=0;i<N;i++){
	 		m[i]=-50 + rand()%100;
	 		printf ("%d\t",m[i]);}
	 for(i=0;i<N;i++){
	 		if (m[i]<min) min=m[i];
	 }
	 printf("min=%d\n",min);
	 for(i=0;i<N;i++){
	 		if(m[i]==min) printf("min[%d]\n",i);}
	 		return 0;
}