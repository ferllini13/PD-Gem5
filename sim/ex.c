#include <stdio.h>
#include <omp.h>
#include <math.h>



void exP(int n, float x){
    
    int factor=1;
    double result=1;
    double start_time, run_time;
    start_time = omp_get_wtime();
    omp_set_num_threads(4);

    #pragma omp parallel for
    for (int i=1; i<n; i++) {
        factor *= i;
        result += pow(x,i)/factor;

    }
    
    run_time = omp_get_wtime() - start_time;
    printf("seconds %f\n",run_time); 
}


int main(){
	
	exP(50, 2.0);
	
    return 0;
}
