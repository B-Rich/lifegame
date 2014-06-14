#ifndef _DEF_INSIDE_
#define _DEF_INSIDE_

#include <omp.h>

typedef _Bool field_t;

extern field_t gfield[2][1+M+1][1+N+1];

void clean_field(field_t field[1+M+1][1+N+1]);
void random_field(field_t field[1+M+1][1+N+1]);
void update_field(field_t dst_field[1+M+1][1+N+1], field_t src_field[1+M+1][1+N+1], int tid, int nthreads, int start_M, int end_M);
void output_field(field_t field[1+M+1][1+N+1], int turn);

#endif /* _DEF_INSIDE_ */
