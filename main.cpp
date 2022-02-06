#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

//a) Dise�e y programe las estructuras necesarias para almacenar la informaci�n de los pedidos (2 pts.)
typedef struct
{
    char cliente[20]; //esta es la segunda versión del mismo examen 
    int cantidad;
    char alimento[20];
} pedido_virtual;

typedef struct
{
    pedido_virtual vec[50];
    int ultimo=-1;
} lista_pedidos;

//b) Escriba las funciones o procedimientos necesarios para leer el archivo Pedidos.txt y llenar sus estructuras (3 pts.)

lista_pedidos leerarchivo ()
{
    lista_pedidos lp;
    int cont=0;
    ifstream archivo("C:\\Users\\59175\\inge_soft\\primeros_pasos\\examen luis Gil progra 1\\pedidos.txt");
    while (!archivo.eof())
    {
        archivo>>lp.vec[cont].cliente;
        archivo>>lp.vec[cont].cantidad;
        archivo>>lp.vec[cont].alimento;
        lp.ultimo++;
        cont++;
    }
    archivo.close ();
    return lp;
}

void mostrarlista (lista_pedidos lp)
{
    for(int cont=0; cont<=lp.ultimo; cont++)
    {
        cout<<lp.vec[cont].cliente<<" ";
        cout<<lp.vec[cont].cantidad<<" ";
        cout<<lp.vec[cont].alimento<<endl;
    }
}

lista_pedidos devolver_mayor (int x, lista_pedidos lp, char alimento[20])
{
    lista_pedidos lp2;
    int cont2=0;
    for (int cont=0; cont<=lp.ultimo; cont++)
    {
        if (lp.vec[cont].cantidad>x && strcmp(alimento,lp.vec[cont].alimento)==0)
        {
            lp2.vec[cont2]=lp.vec[cont];
            cont2++;
            lp2.ultimo++;
        }
    }
    return lp2;
}
int main()
{
    int x;
    char alimento[20];
    lista_pedidos lp, lp2;
    lp=leerarchivo();
    mostrarlista(lp);
    cin>>x;
    cin>>alimento;
    lp2=devolver_mayor(x,lp,alimento);
    mostrarlista(lp2);
    return 0;
}
