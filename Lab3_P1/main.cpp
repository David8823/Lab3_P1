#include <stdlib.h>
#include <string.h>
#include <fstream>
#include "Funciones.h"

void codificar();

int main () {
cout<< "Escriba 1 o 2 para elegir el metodo de codificacion" <<endl;
int m;
cin>>m;

cout<< "Escriba la semillla con la cual codificar" <<endl;
int s;
cin>>s;

cout<< "Escriba el nombre del archivo de texto a leer" <<endl;
string direc;

cin>>direc;

cout<< "Escriba el nombre del archivo binario donde se guardara la codificacion" <<endl;
string salida;
cin>>salida;

cout<<"Escriba el nombre del archivo binario que sera descodificado"<<endl;
string entrad;
cin>>entrad;


cout<< "Escriba el nombre del archivo de texto con la decodificacion " <<endl;
string salid;
cin>>salid;

codificar(s,m,direc,salida);

decodificar(s,m,salida,salid);

}


