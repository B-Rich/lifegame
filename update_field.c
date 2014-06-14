#include "def.h"

void update_field (field_t dst_field[1+M+1][1+N+1], field_t src_field[1+M+1][1+N+1])
{
	int i, j;

	for(i=1; i<1+M+1-1; i++){
		for(j=1; j<1+N+1-1; j++){
			int cnt=0;
			if(src_field[i-1][j-1]==1)
				cnt++;
			if(src_field[i-1][j	]==1)
				cnt++;
			if(src_field[i-1][j+1]==1)
				cnt++;
			if(src_field[i	][j-1]==1)
				cnt++;
			if(src_field[i	][j+1]==1)
				cnt++;
			if(src_field[i+1][j-1]==1)
				cnt++;
			if(src_field[i+1][j	]==1)
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
