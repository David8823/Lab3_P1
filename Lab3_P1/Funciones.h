#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <cmath>
#ifndef FUNCIONES_H
#define FUNCIONES_H
using namespace std;
#endif // FUNCIONES_H


string binacimal(string cod){

string mensaje="";
char letra=' ';
int longi=cod.length(),ascii=0,pot=7;
int pos=0;
while(pos<longi){
  ascii=(cod[pos])*pow(2,pot)+ascii;
  if(pot==0){
    letra=ascii+'0';
    pot=8;
    ascii=0;

    mensaje+=letra;
  }
  pot--;
  pos++;
}

return mensaje;
}


string leeryguardar(string inp){

    string archivo="../manejoArchivos/BD/";
    string data;
    ifstream infile;
    archivo+=inp;
    archivo+=".bin";

    infile.open(archivo);

    // Se comprueba si el archivo fue abierto exitosamente
    if (!infile.is_open())
    {
      cout << "Error abriendo el archivo" << endl;
      exit(1);
    }

    infile >> data;

    int letras=data.length();




    infile.close();



return data;
}


void  escribirbin(string outp,string entrada) {
   string archivo="../manejoArchivos/BD/";
   bool data;
   archivo+=outp;
   archivo+=".bin";
   int k=entrada.length();

   // abrir un archivo en modo escritura
   ofstream outfile;


   outfile.open(archivo);

   if (!outfile.is_open())
   {
     cout << "Error abriendo el archivo" << endl;
     exit(1);
   }



   for(int i=0; i<k ;i++){

       if(entrada[i]=='1'){

           data=1;
           outfile << data;

       }

       else{

           data=0;
           outfile << data;

       }

   }

   // Se cierra el archivo
   outfile.close();

}

void  escribirtxt(string outp,string entrada) {
   string archivo="../manejoArchivos/BD/";
   archivo+=outp;
   archivo+=".txt";

   // abrir un archivo en modo escritura
   ofstream outfile;


   outfile.open(archivo);

   if (!outfile.is_open())
   {
     cout << "Error abriendo el archivo" << endl;
     exit(1);
   }


   outfile << entrada;


   // Se cierra el archivo
   outfile.close();

}

string mover(string h){

//string h="bienvenidos";
string hmod="";
int f=h.length();
int j=f-1;

for(int i=0;i<f ;i++){

    hmod+=h[i+j];

    if(j==f-1){
        j=-1;

    }

}



cout<< hmod <<endl;
return hmod;
}


string conversion(int decimal){

    string ascii;
    bool binario[8];

    for (int i = 0; i < 8; i++)
    {
        binario[i] = decimal % 2;
        decimal /= 2;
    }


    for (int i = 0; i<8 ; i++)
    {
       if(binario[i]==1){

           ascii.insert(0,"1");

       }

    else{

       ascii.insert(0,"0");

       }


    }


return ascii;
}


string leerybinario(string inp){

    string archivo="../manejoArchivos/BD/";
    string data;
    string save;
    ifstream infile;
    archivo+=inp;
    archivo+=".txt";

    infile.open(archivo);

    // Se comprueba si el archivo fue abierto exitosamente
    if (!infile.is_open())
    {
      cout << "Error abriendo el archivo" << endl;
      exit(1);
    }

    infile >> data;

    int letras=data.length();


    infile.close();

   // hasta aqui en este punto data tiene todo el archivo almacenado

    string bin;

    int letra;
    for(int pos=letras-1; pos>=0 ;pos--){

        letra= data[pos];

        //funcion que entrega un string con el valor binario de letra
        bin=conversion(letra);

        save.insert(0,bin);



    }

return save;
}


int contar(string o){
    int con=0;
    int a=0;
    int b=0;
    int lon=o.length();
    for(int y=0; y<lon ;y++){


        if(o[y]=='1'){

            a++;


        }
        else{

            b++;

        }

    }

if(a>b){
    con=1;
   }

else if(a<b){

    con=2;
}

else if(a==b){

    con=3;
}

return con;
}


string metodo1(int t,string f){


int y=0;
string g="";
int p=0;

string copyf=f;
int k= f.length();
int h=0;


for(int w=0; w<t ;w++){

if(copyf.at(w)=='1'){

    copyf.at(w)='0';
}

else{

    copyf.at(w)='1';

}

}



while(h<(k/t)-1){

h++;
g="";

g.append(f,p,t);

y=contar(g);

switch(y){

case 1:

    g="";
    g.append(f,p+t,t);

    for(int q=2; q<t ;q=q+3){

        if(g[q]=='1'){
            g[q]='0';

        }
        else{
           g[q]='1';

        }

    }

copyf.replace(p+t,t,g);


break;


case 2:


    g="";
    g.append(f,p+t,t);

    for(int q=1; q<t ;q=q+2){

        if(g[q]=='1'){
            g[q]='0';

        }
        else{
           g[q]='1';

        }

    }

copyf.replace(p+t,t,g);


break;


case 3:


    g="";
    g.append(f,p+t,t);

    for(int q=0; q<t ;q=q+1){

        if(g[q]=='1'){
            g[q]='0';

        }
        else{
           g[q]='1';

        }

    }

copyf.replace(p+t,t,g);


break;


default:

    cout<<"error"<<endl;

    break;

}


p=p+t;
}

if(k%t!=0){


    g="";
    g.append(f,p,t);

    y=contar(g);

    g="";

    g.append(f,p+t,k%t);





    switch(y){

    case 1:



           for(int q=2; q<k%t ;q=q+3){

            if(g[q]=='1'){
                g[q]='0';

            }
            else{
               g[q]='1';

            }

        }

    copyf.replace(p+t,k%t,g);


    break;


    case 2:




        for(int q=1; q<k%t ;q=q+2){

            if(g[q]=='1'){
                g[q]='0';

            }
            else{
               g[q]='1';

            }

        }

    copyf.replace(p+t,k%t,g);


    break;


    case 3:



        for(int q=0; q<k%t ;q=q+1){

            if(g[q]=='1'){
                g[q]='0';

            }
            else{
               g[q]='1';

            }

        }

    copyf.replace(p+t,k%t,g);


    break;


    default:

        cout<<"error"<<endl;

        break;


}


}



return copyf;
}


string metodo2(int sed,string lel){


    string copylel=lel;
    int len=lel.length();

    string g="";
    int cont=0;
    int ini=0;


    while(cont<len/sed){

        cont++;

        g="";

        g.append(lel,ini,sed);

        g=mover(g);

        copylel.replace(ini,sed,g);

        ini=ini+sed;


    }


  if(len%sed!=0){

      g="";

      g.append(lel,ini,len%sed);

      g=mover(g);

      copylel.replace(ini,len%sed,g);

  }







return copylel;
}


void codificar(int seed,int mod,string in,string out){

    string codificado;
    string archivos;

    archivos=leerybinario(in);

    switch (mod) {

    case 1 :

    codificado=metodo1(seed,archivos);



    //aqui va una funcion que escribe en un documento

    escribirbin(out,codificado);

    break;


    case 2:

    codificado=metodo2(seed,archivos);



    //aqui va una funcion que escribe en un documento

    escribirbin(out,codificado);

    break;



    }

}


string invmetodo1(int t,string f){


int y=0;
string g="";
int p=0;
string copyf=f;
int k= f.length();
int h=0;


for(int w=0; w<t ;w++){

if(copyf.at(w)=='1'){

    copyf.at(w)='0';
}

else{

    copyf.at(w)='1';

}

}



while(h<(k/t)-1){

h++;
g="";

g.append(copyf,p,t);

y=contar(g);

switch(y){

case 1:

    g="";
    g.append(copyf,p+t,t);

    for(int q=2; q<t ;q=q+3){

        if(g[q]=='1'){
            g[q]='0';

        }
        else{
           g[q]='1';

        }

    }

copyf.replace(p+t,t,g);


break;


case 2:


    g="";
    g.append(copyf,p+t,t);

    for(int q=1; q<t ;q=q+2){

        if(g[q]=='1'){
            g[q]='0';

        }
        else{
           g[q]='1';

        }

    }

copyf.replace(p+t,t,g);


break;


case 3:


    g="";
    g.append(copyf,p+t,t);

    for(int q=0; q<t ;q=q+1){

        if(g[q]=='1'){
            g[q]='0';

        }
        else{
           g[q]='1';

        }

    }

copyf.replace(p+t,t,g);


break;


default:

    cout<<"error"<<endl;

    break;

}


p=p+t;
}

if(k%t!=0){


    g="";
    g.append(copyf,p,t);

    y=contar(g);

    g="";

    g.append(copyf,p+t,k%t);





    switch(y){

    case 1:



           for(int q=2; q<k%t ;q=q+3){

            if(g[q]=='1'){
                g[q]='0';

            }
            else{
               g[q]='1';

            }

        }

    copyf.replace(p+t,k%t,g);


    break;


    case 2:




        for(int q=1; q<k%t ;q=q+2){

            if(g[q]=='1'){
                g[q]='0';

            }
            else{
               g[q]='1';

            }

        }

    copyf.replace(p+t,k%t,g);


    break;


    case 3:



        for(int q=0; q<k%t ;q=q+1){

            if(g[q]=='1'){
                g[q]='0';

            }
            else{
               g[q]='1';

            }

        }

    copyf.replace(p+t,k%t,g);


    break;


    default:

        cout<<"error"<<endl;

        break;


}


}



return copyf;
}



string invmover(string h){


string hmod="";
int f=h.length();
int j=1;

for(int i=0;i<f ;i++){

    hmod+=h[i+j];

    if(i==2){
        j=-3;

    }

}
return hmod;
}



string invmetodo2(int sed,string lel){


    string copylel=lel;
    int len=lel.length();

    string g="";
    int cont=0;
    int ini=0;


    while(cont<len/sed){

        cont++;

        g="";

        g.append(lel,ini,sed);

        g=invmover(g);

        copylel.replace(ini,sed,g);

        ini=ini+sed;


    }


  if(len%sed!=0){

      g="";

      g.append(lel,ini,len%sed);

      g=invmover(g);

      copylel.replace(ini,len%sed,g);

  }







return copylel;
}



void decodificar(int seed,int mod,string in,string out){

    string codificado;
    string archivos;

    archivos=leeryguardar(in);

    switch (mod) {

    case 1 :

    codificado=invmetodo1(seed,archivos);



    //aqui va una funcion que escribe en un documento

    codificado=binacimal(codificado);



    escribirtxt(out,codificado);

    break;


    case 2:

    codificado=invmetodo2(seed,archivos);



    //aqui va una funcion que escribe en un documento

    codificado=binacimal(codificado);



    escribirtxt(out,codificado);

    break;



    }
}












