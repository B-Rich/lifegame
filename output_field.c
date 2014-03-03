#include "def.h"
#include <stdio.h>
#include <stdlib.h>

/* output as pbm file */
void output_field(field_t field[1+M+1][1+N+1], int turn)
{
  int i, j;
  FILE *fp;
  char filename[0xff];

  sprintf(filename, "turn%d.pbm", turn);
  fp=fopen(filename, "w");

  fprintf(fp, "P1\n# Turn: %d\n%d %d\n", turn, N, M);

  for(i=1; i<1+M+1-1; i++){
    for(j=1; j<1+N+1-1-1; j++)
      fprintf(fp, "%d ", field[i][j]);
    fprintf(fp, "%d\n", field[i][N-1-1]);
  }

  fclose(fp);

  return;
}
