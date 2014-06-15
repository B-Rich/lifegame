#include "def.h"
#include <stdio.h>
#include <sys/time.h>

field_t gfield[2][1+M+1][1+N+1];
int tid, nthreads;

int main()
{
	struct timeval start_time, end_time;

	clean_field(gfield[0]);
	clean_field(gfield[1]);
	random_field(gfield[0]);

	output_field(gfield[0], 0);

#pragma omp parallel private(tid)
{
	int i;
	int start_M, end_M;

	tid=omp_get_thread_num();
	if(tid==0)
		nthreads=omp_get_num_threads();
#pragma omp barrier

	printf("thread(%d/%d): initialized\n", tid, nthreads);
	fflush(stdout);
#pragma omp barrier

	start_M=1+(1+M+1-1)*tid/nthreads;
	end_M=1+(1+M+1-1)*(tid+1)/nthreads;

	gettimeofday(&start_time, NULL);

	for(i=1; i<=TURN; i++){
		if(tid==0){
			printf("Turn: %d\n", i);
		}

		update_field(gfield[i%2], gfield[(i+1)%2], start_M, end_M);

		if(tid==0){
			output_field(gfield[i%2], i);
		}
#pragma omp barrier
	}

	gettimeofday(&end_time, NULL);
}

	printf("%f\n", (end_time.tv_sec+end_time.tv_usec/1000000.0)-(start_time.tv_sec+start_time.tv_usec/1000000.0));

	return 0;
}
