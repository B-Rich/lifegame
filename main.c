#include "def.h"
#include <stdio.h>

field_t gfield[2][1+M+1][1+N+1];

int main()
{
	int i=0;

	clean_field(gfield[0]);
	clean_field(gfield[1]);
	random_field(gfield[0]);

	output_field(gfield[0], i);

	for(i=1; i<=TURN; i++){
		printf("Turn: %d\n", i);
		update_field(gfield[i%2], gfield[(i+1)%2]);
		output_field(gfield[i%2], i);
	}

	return 0;
}
