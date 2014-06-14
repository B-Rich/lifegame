#include "def.h"
#include <stdlib.h>

void random_field(field_t field[1+M+1][1+N+1])
{
	int i, j;

	for(i=1; i<1+M+1-1; i++){
		for(j=1; j<1+N+1-1; j++){
			field[i][j]=random()%2;
		}
	}

	return;
}
