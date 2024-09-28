#include <iostream>
using namespace std;
int main()
{   
    int opcion;
    do
    {
        cout<<"El problema a resolver:"<<endl;
        cout<<"1. Visualizar la información de los productos:"<<endl;
        cout<<"2. Vender un producto:"<<endl;
        cout<<"3. Abastecer la tienda con un producto:"<<endl;
        cout<<"4. Cambiar un producto:"<<endl;
        cout<<"5. Calcular estadísticas de ventas:"<<endl;
        cin>>opcion;
       
        switch (opcion)
        {
            case 1:
            {
               
            }
            break;
            case 2:
            {
             
            }
            break;
            case 3:
            {
             
            }
            break;
            case 4:
            {
             
            }
            break;
            case 5:
            {
             
            }
            break;
            default:
             cout<<"opción no valida.";
            break;
        }
    }
    while(opcion!=5);
}
