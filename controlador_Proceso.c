#include "DataShell.h"

void controlador_Proceso(char * archivo)
{
  int validacion_nombre;
  FILE * archivo_lectura;

  validacion_nombre = modelo_Valida_Nombre(archivo);

  if(validacion_nombre == 0 || validacion_nombre == -1)
  {
    vista_Error_Menos1();
  }

  else//Si la validacion salio correctamente, podemos continuar con el proceso.
  {
    printf("\n\nTodo correcto!!\n\n");
  }
}
