#include<iostream>
using namespace std;

struct productos
    {
    //atributos
        string nombres [12]={"Lapiz","Cuaderno","Carpeta","Esfero","Arroz","Pan tajado","Pasta","Frijol","Acetaminofen","Ibuprofeno","Noxpirin","Losartan"};
        int unidades [12]= {25,15,20,50,25,15,10,8,6,14,13,9};
        float precios [12]= {1800,3700,4000,1200,2200,5600,5300,5800,1300,4800,2500,2400};
        int ventas [12]= {0,0,0,0,0,0,0,0,0,0,0,0};
    //método
        void MostrarInfProdPape();
        void MostrarInfProdDro();
        void MostrarInfProdSup();
        
    };
    
    void productos :: MostrarInfProdPape()
    {
        for(int i=0; i<4; i++)
        {
            cout<<"-Nombres:"<<nombres[i];
        }
        cout<<endl;
        for(int i=0; i<4; i++)
        {
            cout<<"-Precios:"<<precios[i];
        }
        cout<<endl;
        for(int i=0; i<4; i++)
        {
            cout<<"-Unidades:"<<unidades[i];
        }
        cout<<endl;
    };
    
    void productos :: MostrarInfProdSup()
    {
        for(int i=4; i<8; i++)
        {
            cout<<"-Nombres:"<<nombres[i];
        }
        cout<<endl;
        for(int i=4; i<8; i++)
        {
            cout<<"-Precios:"<<precios[i];
        }
        cout<<endl;
        for(int i=4; i<8; i++)
        {
            cout<<"-Unidades:"<<unidades[i];
        }
        cout<<endl;
    };
  
  void productos :: MostrarInfProdDro()
    {
        for(int i=8; i<12; i++)
        {
            cout<<"-Nombres:"<<nombres[i];
        }
        cout<<endl;
        for(int i=5; i<12; i++)
        {
            cout<<"-Precios:"<<precios[i];
        }
        cout<<endl;
        for(int i=5; i<12; i++)
        {
            cout<<"-Unidades:"<<unidades[i];
        }
        cout<<endl;
    };
  
  
  
    
int main(){

	int Opc_Menu;
	int Opc_Producto;
    
    
	do{
	    cout <<"Digite el numero de la opcción que desea\n\n";
    	cout <<"1.Visualizar la información de los productos\n";
    	cout <<"2.Vender un producto\n";
    	cout <<"3.Abastecer la tienda con un producto\n";
    	cout <<"4.Cambiar un producto\n";
	    cout <<"5.Calcular estadisticas de ventas\n\n";
	
    	cin>>Opc_Menu;
	
    	switch (Opc_Menu)
    	{
	    	case 1:
	    	cout <<"Digite el número del producto el cual desea ver la información\n";
	    	cout <<"1.Papeleria\n";
	    	cout <<"2.Supermercado\n";
	    	cout <<"3.Drogueria\n\n";
	    	
	    	cin>>Opc_Producto;
	    	switch (Opc_Producto)
	    	{
	    	    case 1:
	    	    {
	    	        cout<<"-----------------Información productos------------------------"<<endl;
	    	        cout<<"-----------------Papeleria------------------------"<<endl;
                    productos productosPapeleria;
                    productosPapeleria.MostrarInfProdPape();
	    	    }
	    	    break;
	    	    case 2:
	    	    {
	    	        cout<<"-----------------Información productos------------------------"<<endl;
                    cout<<"-----------------Supermercado------------------------"<<endl;
                    productos productosSupermercad;
                    productosSupermercad.MostrarInfProdSup();
	    	    }
	    	    break;
	    	    case 3:
	    	    {
	    	        cout<<"-----------------Información productos------------------------"<<endl;
                    cout<<"-----------------Drogueria------------------------"<<endl;
                    productos productosDrogeria;
                    productosDrogeria.MostrarInfProdDro();
	    	    }
	    	    break;
	            default:
	            break;
	    	}
	    	break;
	    	case 2:
	    	break;
	    	case 3:
	    	break;
	    	case 4:
	    	break;
    		case 5:
    		break;
	    	default:
	    	cout<<"Opción no valida";
	    	break;
    	}
	}
	while (Opc_Menu<5);
	
	
}
