#ifndef ARCHIVO_H
#define ARCHIVO_H


class archivo
{
protected:
    char *palabraBuscada;


public:
    archivo();
    void setPalabra(char* palabra);
    bool buscarPalabra( const char *palabra,const char * path);
    ~archivo();
    int cantidadCaracteresPalabra( const char *palabra);
    char * borraEspacios(const char *palabra);
    int cuentapalabras(const char *palabra,const char * path);
    char ** cortecadena( char *palabras, char caracter);
    int cantcortecadena( const char *palabra, char caracter);
    bool verificaPalabra(const char *palabra);
    int cantidadtotalpalabras(const char *path);
};

#endif // ARCHIVO_H
