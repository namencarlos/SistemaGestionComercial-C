/*Librerias necesarias para el programa*/
#include <conio.h>
#include <stdio.h>
#include <windows.h>

/*prototipo de funciones*/
void crear();
void consultar();
void modificar();
void cargar();
void baja();
void ordenar();
void barra_horizontal();
void menu();/*Prototipo de la funcion menu, la cual solo nos va a mostrar las distintas opciones con las que cuenta el programa*/

/*programa Principal*/
main()
{
	int opcion;
	system("color E1");
	barra_horizontal();
	menu();
	printf("\n");
	printf("Por favor, elija una opcion: ");
	scanf("%d",&opcion);
	while(opcion!=0)
	{
		if(opcion == 1)
		{
			crear();
		}
		else if(opcion == 2)
		      {
		        consultar();
			  }
			 else if(opcion == 3)
			       {
			 	     modificar();
			       }  
			      else if(opcion == 4)
			            {
			            	cargar();
                        }
			            
			           else if(opcion == 5)
			                 {
			                 	baja();
                                //return 0;
                              }
                            else if(opcion == 6)
			                 {
			                 	ordenar();
                                //return 0;
                              }  
    system("cls");
    barra_horizontal();
	menu();
	printf("\nPor favor, elija una opcion: ");
	scanf("%d",&opcion);
					            
	}
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
	printf("\n\t\tMenu de opciones\n");
	printf("\n\t1-Crear Listado de Concurrentes");
	printf("\n\t2-Consultar Listado de Concurrentes");
	printf("\n\t3-Modificar Listado de Concurrentes ");
	printf("\n\t4-Cargar Nuevo Concurrente");
	printf("\n\t5-Baja de Concurrente");
	printf("\n\t6-Ordenar Listado de Concurrentes");
	printf("\n\t0-Salir");
	printf("\n\n\n");
}
/*------------------------------------------------------*/
/*Funciones de proceso*/
void crear()
{
	system("cls");
    struct FecNac
    {
	    int dd,mm,aa;
    };
    struct concurrentes
    {  
        int dni,edad,numafil;
        char apeynom[30];
        float arancel;
        struct FecNac fec;
        bool borrado;
    };

    struct concurrentes reg;
    FILE *arch;
    int n,i;

    /*Alta*/
    printf("Ingrese la cantidad de concurrentes: ");
    scanf("%d",&n);
    //if(n!=)
    arch=fopen("concurrentes.dat","w+b");

    for (i=0;i<n;i++)
    {
	    printf("\n\nIngrese los datos del concurrente\n\n");
        printf("Nro de DNI: ");
        scanf("%d",&reg.dni);
        _flushall();
        printf("Nro de Afiliado: ");
        scanf("%d",&reg.numafil);
        _flushall();
        printf("Apellido y Nombre: ");
        gets(reg.apeynom);
        printf("Fecha de nacimiento\n");
        printf("DD: ");
        scanf("%d",&reg.fec.dd);
        printf("MM: ");
        scanf("%d",&reg.fec.mm);
        printf("AAAA: ");
        scanf("%d",&reg.fec.aa);
        printf("Edad : ");
        scanf("%d",&reg.edad);
        printf("Valor de prestacion : ");
        scanf("%f",&reg.arancel);
        reg.borrado=false;
        fwrite(&reg,sizeof(reg),1,arch);
     }
 fclose(arch);
system("PAUSE");
}
		
void consultar()
{
	system("cls");
	printf("Usted esta por consultar un registro");
	struct FecNac
    {
	    int dd,mm,aa;
    };
    struct concurrentes
    {  
        int dni,edad,numafil;
        char apeynom[30];
        float arancel;
        struct FecNac fec;
        bool borrado;
    };
	struct concurrentes reg;
	FILE *arch;
	arch=fopen("concurrentes.dat","r+b");
    fread(&reg,sizeof(reg),1,arch);
    printf("\n\nListado de Concurrentes Activos\n\n");
    while (!feof(arch))
    {
       printf("Nro de DNI:%d\n",reg.dni);
       printf("Nro de Afiliado: %d\n",reg.numafil);
       printf("Apellido y Nombre:%s\n",reg.apeynom); 
       printf("Fecha de nacimiento:%d/%d/%d\n",reg.fec.dd,reg.fec.mm,reg.fec.aa);
       printf("Edad : %d\n",reg.edad);
       printf("Valor de prestacion :%.2f\n",reg.arancel);
       fread(&reg,sizeof(reg),1,arch);
       printf("--------------------------------\n");
    }
    fclose(arch);
	system("PAUSE");
}
void modificar()
{
	struct FecNac
    {
	    int dd,mm,aa;
    };
    struct concurrentes
    {  
        int dni,edad,numafil;
        char apeynom[30];
        float arancel;
        struct FecNac fec;
        bool borrado;
    };
	system("cls");
	printf("Usted esta por modificar un registro");
	struct concurrentes reg;
    FILE *arch;
    bool band;
    int leg;
    system("CLS");
    printf("Ingrese el dni a dar de baja= ");
    scanf("%d",&leg);
    arch=fopen("concurrentes.dat","r+b");
    fread(&reg,sizeof(reg),1,arch);
    band=false;
    while(feof(arch)==0 && band==false)
    {
        if (reg.dni==leg && reg.borrado==false)
    {
        reg.borrado=true;
        fseek(arch,- sizeof(reg),SEEK_CUR);
        fwrite(&reg,sizeof(reg),1,arch);
        printf("Registro dado de baja\n\n");
        getch();
        band=true;
    }
    else
    {
        fread(&reg,sizeof(reg),1,arch);
    }
    }
    rewind(arch);
    fread(&reg,sizeof(reg),1,arch);
    while(!feof(arch))
    {
       if (reg.borrado==false)
    {
        printf("Nro de DNI:%d\n",reg.dni);
        printf("N° de Afiliado: %d\n",reg.numafil);
        printf("Apellido y Nombre:%s\n",reg.apeynom); 
        printf("Fecha de nacimiento:%d/%d/%d\n",reg.fec.dd,reg.fec.mm,reg.fec.aa);
        printf("Edad : %d\n",reg.edad);
        printf("Valor de prestacion :%.2f\n",reg.arancel);
        fread(&reg,sizeof(reg),1,arch);
        printf("--------------------------------\n");
    }
    fread(&reg,sizeof(reg),1,arch);
    }
    fclose(arch);
	system("PAUSE");
}
void cargar()
{
	system("cls");
	printf("Usted esta por cargar un registro");
	system("PAUSE");
}
void baja()
{
	system("cls");
	printf("Usted esta por dar de baja un registro");
	getch();
}
void ordenar()
{
	system("cls");
	printf("Usted esta por ordenar el registro");
	system("PAUSE");
}