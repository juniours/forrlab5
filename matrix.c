#include "matrix.h"
#define N 8
#define M 5

int matrixx(){
	srand(time(NULL));
	int min=0,i,j, m[N][M];
	for(i=0;i<N;i++){
	 	for (j=0;j<M;j++){
	 		m[i][j]=-50 + rand()%100;  
	 		    printf("%d\t",m[i][j]);}
                printf("\n");}
	 for(i=0;i<N;i++){
	 	for (j=0;j<M;j++){
	 		if (m[i][j]<min) min=m[i][j];
	 	}
	 }
	 printf("min=%d\n",min);
	 for(i=0;i<N;i++){
	 	for (j=0;j<M;j++){
	 		if(m[i][j]==min) printf("min[%d][%d]\n",i,j);}}
	 		return 0;
}