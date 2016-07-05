#include <stdio.h>
int main(void)
{
    long int N,A[5000],sum;
    int M,P[5000],min;
    while (scanf("%d %d", &N, &M)==2){
    	int i=0;
    	for(i=0;i<M;i++){
    		scanf("%d %d", &P[i], &A[i]);	
    	} 
    	min = A[0];
    	while(N>0){
    		for(i=0;i<M;i++){
    			if(P[i]<P[min])
    				min = i;
    		} 
    		if(A[min]>=N){
    			sum += N*P[min];
    			P[min] = 2000;
    			N = 0;
    		}else{
    			sum += A[min]*P[min];
    			P[min] = 2000;
    			N -= A[min];
    		}
    	}
    	printf("%ld\n",sum);
    }
    return 0;
}
