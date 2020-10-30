#include "DataShell.h"

void controlador_Proceso(char * archivo)
{
  int i;
  int validacion_nombre;
  FILE * archivo_lectura;

  char linea_leida[BUFSIZ];

  //Corregimos el '\n' que se lee con fgets
  modelo_Correccion_Nombre(archivo);
  
  //Validamos si el nombre es correcto.
  validacion_nombre = modelo_Valida_Nombre(archivo);

  
  if(validacion_nombre == 0 || validacion_nombre == -1)
  {
    vista_Error_Menos1();
  }

  else//Si la validacion salio correctamente, podemos continuar con el proceso.
  { 
    archivo_lectura = modelo_Abre_Archivo(archivo);

    while(!feof(archivo_lectura))
    {
      //Leemos una linea del archivo.
      fscanf(archivo_lectura,"%s\n",linea_leida);

      //Lo siquiente hay que separarlo en un modulo aparte
      for(i=0 ; i<strlen(linea_leida) ; i++)
	{
	  if(linea_leida[i] == ',') 
	    {
	      linea_leida[i] = ' ';
	    }
	}

      //La separamos
      modelo_Tokenizer(linea_leida);
    }

    fclose(archivo_lectura);
  }
}
