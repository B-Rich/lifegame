#include "def.h"

void clean_field(field_t field[1+M+1][1+N+1])
{
  int i, j;

  for(i=0; i<1+M+1; i++)
    for(j=0; j<1+N+1; j++)
      field[i][j]=0;

  return;
}
