/*Librerias*/
#include <conio.h>
#include <stdio.h>
#include <windows.h>

/*prototipo de funciones*/
void altaProducto();
void consultarProducto();
void modificarProducto();
void bajaProducto();
void ingresoStock();
void salidaStock();
void listarProductos();

void barra_horizontal();
void menu();/*Prototipo de la funcion menu, la cual solo nos va a mostrar las distintas opciones con las que cuenta el programa*/

/*Estructuras principales*/
    struct Producto
    {  
        int codigo;
        char descripcion[50];
        float precioCompra;
        float precioVenta;
        int stock;
        int stockMinimo;
        bool borrado;
    };

/*programa Principal*/
int main()
{
	int opcion;
	do
	{
		system("cls");
		system("color E1");
		
		barra_horizontal();
		menu();
		
		printf("\nSeleccione una opcion: ");
		scanf("%d",&opcion);
		
		switch(opcion)
		{
			case 1:
				altaProducto();
				break;
				
			case 2:
				consultarProducto();
				break;
				
			case 3:
				modificarProducto();
				break;
			
			case 4:
				bajaProducto();
				break;
				
			case 5:
				ingresoStock();
				break;
				
			case 6:
				salidaStock();
				break;
				
			case 7:
				listarProductos();
				break;
				
			case 0:
				printf("\nSaliendo del sistema...");
				break;
				
			default:
				printf("\nOpcion invalida");
				getch();
		}		
	}while(opcion!=0);
	
	return 0;
}

/*Funciones para el menú e interfaz visual*/
void barra_horizontal()
{
	int n=3,m=55,i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("*");
		}
		printf("\n");	
	}
	
}
void menu()
{
	printf("\n");
	printf("========================================\n");
	printf("    SISTEMA DE GESTION COMERCIAL v0.2\n");
	printf("========================================\n");
	
	printf("1. Alta de Producto\n");
	printf("2. Consultar Productos\n");
	printf("3. Modificar productos\n");
	printf("4. Baja de producto\n");
	printf("5. Ingreso de stock\n");
	printf("6. Salida de Stock\n");
	printf("7. Listar productos\n");
	printf("0. Salir\n");
}

/*------------------------------------------------------*/
/*Funciones de proceso*/
void altaProducto()
{
	system("cls");
    Producto producto;
    FILE *arch;
    int n,i;

    /*Alta*/
    printf("Ingrese la cantidad de productos: ");
    scanf("%d",&n);
    
    arch=fopen("productos.dat","a+b");
    
    if(arch==NULL)
    {
    	printf("Error al abrir el archivo");
    	getch();
    	return;
	}
    
    for (i = 0; i < n ; i++)
    {
	    printf("\n\nProducto\n\n");
        do
        {
        	printf("Codigo: ");
        	scanf("%d",&producto.codigo);
		}while(producto.codigo <= 0);
		
		_flushall();
        
        printf("Descripcion: ");
        fgets(producto.descripcion,sizeof(producto.descripcion),stdin);
        _flushall();
        
        do
        {
        	printf("Precio de Compra: ");
        	scanf("%f",&producto.precioCompra);
		}while(producto.precioCompra <= 0);
        
        do
        {
        	printf("Precio de Venta: ");
        	scanf("%f",&producto.precioVenta);
		}while(producto.precioVenta <= 0);
        
        do
        {
        	printf("Stock: ");
        	scanf("%d",&producto.stock);
		}while(producto.stock < 0);
        
        do
        {
        	printf("Stock Minimo: ");
        	scanf("%d",&producto.stockMinimo);
		}while(producto.stockMinimo < 0);
        
        producto.borrado=false;
        fwrite(&producto,sizeof(producto),1,arch);
     }
 fclose(arch);
system("PAUSE");
}
		
void consultarProducto()
{
	system("cls");
	printf("Usted esta por cargar un registro");
	system("PAUSE");
}
void modificarProducto()
{
	system("cls");
	printf("Usted esta por cargar un registro");
	system("PAUSE");
}
void bajaProducto()
{
	system("cls");
	printf("Usted esta por dar de baja un registro");
	getch();
}
void ingresoStock()
{
	system("cls");
	printf("Usted esta por ordenar el registro");
	system("PAUSE");
}

void salidaStock()
{
	system("cls");
	printf("Usted esta por ordenar el registro");
	system("PAUSE");
}


void listarProductos()
{
    system("cls");

    Producto producto;
    FILE *arch;

    arch = fopen("productos.dat","rb");

    if(arch == NULL)
    {
        printf("No existen productos cargados.\n");
        system("PAUSE");
        return;
    }

    printf("========================================\n");
    printf("       LISTADO DE PRODUCTOS\n");
    printf("========================================\n\n");

    while(fread(&producto,sizeof(producto),1,arch)==1)
    {
        if(producto.borrado==false)
        {
            printf("Codigo: %d\n",producto.codigo);
            printf("Descripcion: %s",producto.descripcion);
            printf("Precio Compra: %.2f\n",producto.precioCompra);
            printf("Precio Venta : %.2f\n",producto.precioVenta);
            printf("Stock        : %d\n",producto.stock);
            printf("Stock Minimo : %d\n",producto.stockMinimo);

            printf("----------------------------------------\n");
        }
    }

    fclose(arch);

    system("PAUSE");
}
