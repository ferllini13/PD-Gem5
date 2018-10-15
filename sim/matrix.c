#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

double mm(int n){
	double start_time, run_time;

	int m1[n][n], m2[n][n], m3[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 1;
		}
	}

	start_time = omp_get_wtime();
	#pragma omp parallel
	{
		int add = 0;
		#pragma omp for 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k = 0; k < n; k++){
					add += (m1[i][k] * m2[j][k]);
				}
				m3[i][j] = add;
				add = 0;
			}
		}
	}
	run_time = omp_get_wtime() - start_time;
    /*printf("seconds %f\n",run_time);
	printf("\nResult: \n");

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", m3[i][j]);
		}
		printf("\n");
	}*/
	return run_time;
}

int main(int argc, char const *argv[]){

	int size = atoi(argv[1]);
	int cant= atoi(argv[2]);
	double prom=0;

	for (int x = 0; x < cant;++x){
		prom += mm(size);
	}
	prom=prom/cant;
	printf("Prom: %f para %d datos ",prom,cant);
}