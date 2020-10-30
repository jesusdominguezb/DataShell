#include "DataShell.h"

void controlador_Proceso(char * archivo)
{
  int validacion_nombre;
  FILE * archivo_lectura;

  //Corregimos el '\n' que se lee con fgets
  modelo_Correcion_Nombre(archivo);
  
  //Validamos si el nombre es correcto.
  validacion_nombre = modelo_Valida_Nombre(archivo);

  
  if(validacion_nombre == 0 || validacion_nombre == -1)
  {
    vista_Error_Menos1();
  }

  else//Si la validacion salio correctamente, podemos continuar con el proceso.
  { 
    archivo_lectura = modelo_Abre_Archivo(archivo);

    
    //Proceso chingon que separa las cosas y asì
    

    fclose(archivo_lectura);
  }
}
