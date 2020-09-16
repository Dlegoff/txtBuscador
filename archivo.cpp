#include "archivo.h"
#include <iostream>
#include <fstream>
#include <string.h>



using namespace std;
archivo::archivo()
{

}

void archivo::setPalabra(char* palabra)
{
    this->palabraBuscada=palabra;
}

int archivo::cantidadCaracteresPalabra (const char *palabra)
{
    int contador=0;
    for(int i=0; palabra[i]!='\0'; i++)
    {
        contador++;
    }
   return contador;
}

bool archivo::buscarPalabra(const char *palabra,const char * path){

    int c=0;
    int t1= this->cantidadCaracteresPalabra(palabra);
    int ini=0;
    int fin=t1;
    while (palabra[ini]==' ') {
        ini++;
    }
    while (palabra[fin-1]==' ')
    {
        fin--;

    }
    int tamPal=0;
    for (int i=ini;i<fin;i++)
    {
        tamPal++;
    }
    char  buffer [256];
           ifstream archi(path); //abre el archivo para leerlo.
           if (!archi.is_open()) // pregunta si esta abierto
            {
               return false;
                //2= error de apertura ||nose que se te ocurre a vos para mostrar alguna variable e ir debagueando.
            } else //sino tiro error
              {
           while (!archi.eof()) //puede que recorra todo el archivo
           {
              archi.getline(buffer,100); // recorre linea por linea
              for(int i=0; buffer[i]!='\0' ;i++)  // llega hasta el fin de linea, lee cada letra
               {   //0//hola      --hola
                   //1//como va
                            if (palabra[ini]==buffer[i])
                            {
                                c=1;
                              int k=i+1;
                              for (int j=ini+1;j<fin;j++)
                               {

                                   if(palabra[j]==buffer[k])
                                   {

                                    c++;
                                    k++;
                                   }else
                                    {
                                      j=fin;
                                      c=0;
                                    }

                               }
                                if(c==tamPal)
                                {
                                 return true;
                                }else{
                                    return false;
                                }

                            }
                            //cout<<"esto es palencont"<<palabraEncontrada<<endl;

                }
             // cout<<buffer<<endl;
           }

           archi.close();
           }
           if(c==tamPal){
              return true;
           }else{
               return false;}

}



archivo::~archivo()
{

}

char * archivo::borraEspacios(const char *palabra)
{
    int t1= this->cantidadCaracteresPalabra (palabra);
    int cont=0;
    int ini=0;
    int fin=t1;

    while (palabra[ini]==' ') {
        ini++;
    }
    while (palabra[fin-1]==' ')
    {
    fin--;
    }

    for(int i=ini;i<fin;i++){
        cont++;
    }

    char * sinEspacio = new char [cont];
    int j=0;
        for(int i=ini;i<fin;i++){
            sinEspacio[j]=palabra[i];
            j++;
        }
        return sinEspacio;
}

int archivo::cuentapalabras(const char *palabra, const char * path)
{
     const char *auxpal;
     auxpal=(palabra);
     int t1=0;
     t1=this->cantidadCaracteresPalabra(auxpal);
     int cantPal=0;
     char  buffer [256];
     int c=0;

     int k=0;
     ifstream archi(path);
     if (!archi.is_open())
        {

         return cantPal;
        } else
          {

             while (!archi.eof())
             {
              archi.getline(buffer,100);
              char *aux=buffer;
              int ca=this->cantcortecadena(aux, ' ');
              char ** vecpalaux = new char *[ca];
              vecpalaux=this->cortecadena(buffer, ' ');

              for(int i=0;i<ca;i++)
              {   int limit=this->cantidadCaracteresPalabra(vecpalaux[i]);

                  k=0;
                  for (int j=0;j<limit;j++)
                  {

                       if(auxpal[k]==vecpalaux[i][j])
                       {

                           c++;
                           k++;

                       }

                  }
                  if(c==this->cantidadCaracteresPalabra(auxpal))
                   {

                    cantPal++;

                   }

                  c=0;

              }


           }
           return(cantPal);

         }

}



char ** archivo::cortecadena(char *palabras, char caracter)
{
    char *auxpal=this->borraEspacios(palabras);
    int t1= this->cantidadCaracteresPalabra(auxpal);
    int cantpal=1;
    int ini=0;
    int fin=t1;
    while (palabras[ini]==caracter) {
        ini++;
    }
    while (palabras[fin-1]==caracter) {
        fin--;
    }

    for (int i=ini;i<fin;i++) {
        if (palabras[i]==caracter&&palabras[i+1]!=palabras[i]) {
            cantpal++;
        }
    }

   int indpalabra=0;
   int indcaracter=0;
   char ** vecpalabras=new char *[cantpal];
   for(int i=ini;i<fin;i++)
    {
          if(palabras[i]!=caracter)
          {
           indcaracter++;
          }
          else if(indcaracter>0)
          {

           vecpalabras[indpalabra]= new char [indcaracter];
           indpalabra++;
           indcaracter=0;

          }

      }
   vecpalabras[indpalabra]= new char [indcaracter];
   indpalabra=0;
   indcaracter=0;

   for(int i=ini;i<fin;i++)
      {
          if(palabras[i]!=caracter)
          {
           vecpalabras[indpalabra][indcaracter]=palabras[i];
           indcaracter++;

          }
          else if(indcaracter>0)
          {
           vecpalabras[indpalabra][indcaracter]='\0';
           indpalabra++;
           indcaracter=0;
          }

      }
   vecpalabras[indpalabra][indcaracter]='\0';

return vecpalabras;

}

int archivo::cantcortecadena(const char *palabra, char caracter)
{
    int cant_palabras=0;
   const  char *auxpal=(palabra);
    int tamanio=this->cantidadCaracteresPalabra(auxpal);
    int ini=0;
    while(palabra[ini]==caracter)
    {
        ini++;
    }
    int fin=tamanio-1;
    while (palabra[fin]==caracter) {
        fin--;
    }

    for(int i=ini; i<fin;i++)
    {
        if(palabra[i]==caracter&&palabra[i]!=palabra[i+1])
        {
           cant_palabras++;
        }
    }


    return cant_palabras+1;

}



bool archivo::verificaPalabra(const char *palabra)
{
    int t1=0;
    t1=this->cantidadCaracteresPalabra(palabra);
    char palabraaux[t1];
    for(int i=0;i<t1;i++)
    {
     palabraaux[i]=palabra[i];
    }
    char *prep[46]={
        "a","durante","según",
        "ante","en","sin",
        "bajo","entre","so",
        "cabe","hacia","sobre",
        "con","hasta","tras",
        "contra","mediante","versus",
        "de","para","vía",
        "desde","por",
        "A","DURANTE","SEGÚN",
        "ANTE","EN","SIN",
        "BAJO","ENTRE","SO",
        "CABE","HACIA","SOBRE",
        "CON","HASTA","TRAS",
        "CONTRA","MEDIANTE","VERSUS",
        "DE","PARA","VÍA",
        "DESDE","POR"};

         char * palabraaux2;
         palabraaux2 = strlwr(palabraaux);
        for(int i=0; i<46; i++){
            if((strcmp(palabraaux2, prep[i])) == 0)
            {
                    return false;
            }
            return true;
        }
}

int archivo::cantidadtotalpalabras(const char *path)
{


     char  buffer [256];
     int c=0;
     int acu=0;
     int k=0;
     ifstream archi(path);
     if (!archi.is_open())
        {

         return acu;
        } else
          {
             while (!archi.eof())
             {
              archi.getline(buffer,100);
              char *aux=buffer;
              int ca=this->cantcortecadena(aux, ' ');
              acu=acu+ca;
              char ** vecpalaux = new char *[ca];
              vecpalaux=this->cortecadena(buffer, ' ');
              if(vecpalaux[0][0]=='\0')
              {
                  acu--;
              }

              }

           return(acu);

         }


//     for(int i=ini; i<fin;i++)
//     {
//         if(palabra[i]==' '&&palabra[i]!=palabra[i+1])
//         {
//            cantPal++;
//         }
//     }



}

