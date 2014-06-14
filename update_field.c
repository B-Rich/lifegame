#include "def.h"

void update_field (field_t dst_field[1+M+1][1+N+1], field_t src_field[1+M+1][1+N+1], int start_M, int end_M)
{
	int i, j;

	for(i=start_M; i<end_M; i++){
		for(j=1; j<1+N+1-1; j++){
			int cnt=0;
			if(src_field[i-1][j-1]==1)
				cnt++;
			if(src_field[i-1][j  ]==1)
				cnt++;
			if(src_field[i-1][j+1]==1)
				cnt++;
			if(src_field[i  ][j-1]==1)
				cnt++;
			if(src_field[i  ][j+1]==1)
				cnt++;
			if(src_field[i+1][j-1]==1)
				cnt++;
			if(src_field[i+1][j  ]==1)
				cnt++;
			if(src_field[i+1][j+1]==1)
				cnt++;

			if(src_field[i][j]==1){
				if((cnt==2)||(cnt==3))
					dst_field[i][j]=1;
				else
					dst_field[i][j]=0;
			}else{
				if(cnt==3)
					dst_field[i][j]=1;
				else
					dst_field[i][j]=0;
			}
		}
	}

	return;
}
