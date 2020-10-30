#include "DataShell.h"

void modelo_Tokenizer(char * linea)
{
  char * ptr = linea;
  float temp;

  while(ptr != linea + strlen(linea))
  {
    temp = strtof(ptr,&ptr);
    
    printf("%f ",temp);
  }

  printf("\n");

}
