#include "DataShell.h"

void controlador_Proceso(char * archivo)
{
  size_t count = 0, columns;
  
  int i,j;
  int validacion_nombre;
  FILE * archivo_lectura;

  char linea_leida[BUFSIZ];

  float * Matriz_Datos[BUFSIZ];
  float * float_ptr;

  float * buffer;

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
      strcpy(linea_leida, controlador_linea(linea_leida));

      //La separamos
      Matriz_Datos[count] = modelo_Tokenizer(linea_leida,buffer);

      count++;

      free(buffer);
    }

    fclose(archivo_lectura);

    //Calculamos la cantidad de columnas ayudàndonos con la ultima linea leida.
    columns = modelo_Columnas(linea_leida);

    printf("%zu columns and %zu rows read\n\n",columns,count);

    //EL siguiente bloque de còdigo es para pura verificacion, se borrara en futuras implementaciones.
    for(i=0 ; i<count ; i++)
    {
      float_ptr = Matriz_Datos[i];
      
      for(j=0 ; j<columns; j++)
      {
	if(j==0)
	{
	  printf("%.0f -> ",float_ptr[j]);
	}

	else
	{
	  printf("%f ",float_ptr[j]);
	}
      }

      printf("\n");
    }
    
  }
}
