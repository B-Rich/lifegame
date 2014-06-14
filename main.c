#include "def.h"
#include <stdio.h>

field_t gfield[2][1+M+1][1+N+1];
int tid, nthreads;

int main()
{
	clean_field(gfield[0]);
	clean_field(gfield[1]);
	random_field(gfield[0]);

	output_field(gfield[0], 0);

#pragma omp parallel private(tid)
{
	int i;

	tid=omp_get_thread_num();
	if(tid==0)
		nthreads=omp_get_num_threads();
#pragma omp barrier

	printf("thread(%d/%d): initialized\n", tid, nthreads);
	fflush(stdout);
#pragma omp barrier

	for(i=1; i<=TURN; i++){
		if(tid==0){
			printf("Turn: %d\n", i);
		}

		update_field(gfield[i%2], gfield[(i+1)%2], tid, nthreads);

		if(tid==0){
			output_field(gfield[i%2], i);
		}
#pragma omp barrier
	}
}
	return 0;
}
