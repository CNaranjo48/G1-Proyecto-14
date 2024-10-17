#include <iostream>
using namespace std;
int main()
{
    string nombres [12]={"Lapiz","Cuaderno","Carpeta","Esfero","Arroz","Pan tajado","Pasta","Frijol","Acetaminofen","Ibuprofeno","Noxpirin","Losartan"};
    int unidades [12]= {25,15,20,50,25,15,10,8,6,14,13,9};
    float precios [12]= {1800,3700,4000,1200,2200,5600,5300,5800,1300,4800,2500,2400};
    int ventas [12]= {0,0,0,0,0,0,0,0,0,0,0,0};
    int prod,cantidad,opcion;
    do
    {
        cout<<"el problema a resolver:"<<endl;
        cout<<"1. Visualizar la informacion de los productos:"<<endl;
        cout<<"2. Vender un producto:"<<endl;
        cout<<"3. Abastecer la tienda con un producto:"<<endl;
        cout<<"4. Cambiar un producto:"<<endl;
        cout<<"5. Calcular estadísticas de ventas:"<<endl; 
        cin>>opcion;
        
        switch (opcion)
        {
            case 1: //Visualizar inventario
            {
                cout<<"-----------------Información productos------------------------"<<endl;
                 cout<<"-----------------Papeleria------------------------"<<endl;
                for(int i=0; i<4; i++)
                {
                cout<<i+1<<")"<<nombres[i]<<"-precios:"
                <<precios[i]<<"-unidades:"<<unidades[i]<<endl;
                }
                cout<<"-----------------Información productos------------------------"<<endl;
                 cout<<"-----------------Supermercado------------------------"<<endl;
                for(int i=4; i<8; i++)
                {
                cout<<i+1<<")"<<nombres[i]<<"-precios:"
                <<precios[i]<<"-unidades:"<<unidades[i]<<endl;
                }
                cout<<"-----------------Información productos------------------------"<<endl;
                 cout<<"-----------------Drogueria------------------------"<<endl;
                for(int i=8; i<12; i++)
                {
                cout<<i+1<<")"<<nombres[i]<<"-precios:"
                <<precios[i]<<"-unidades:"<<unidades[i]<<endl;
                }
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
             cout<<"opción no valida";
        }
    }
    while (opcion<5);
}
