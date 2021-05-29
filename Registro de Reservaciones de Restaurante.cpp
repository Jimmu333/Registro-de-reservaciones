#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
using namespace std;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/ +++++++++REGISTRO DE RESERVACIONES+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void clientes(),mesas(),reservaciones(),clientesFrecuentes(),empleados(),menu();
char var[30];   
main (){
    int opc;
    do{
        system("cls");
    cout<<"|------REGISTRO DE RESRVACIONES DE RESTAURANTE-------| "<<endl;    
    cout<<"| 1. Clientes                                        | " <<endl;
    cout<<"| 2. Mesas                                           | " <<endl;
    cout<<"| 3. Reservaciones                                   | " <<endl;
    cout<<"| 4. Clientes Frecuentes                             | " <<endl;
    cout<<"| 5. Empleados                                       | " <<endl;
    cout<<"| 6. Menu del restaurante                            | " <<endl;
    cout<<"| 7. Salir                                           | " <<endl;
    cout<<"|----------------------------------------------------| "<<endl; 
    
    do{
 cin>>var;
 cout<<"                   "<<endl;
 opc=atoi(var);
 if(strcmp(var,"0")==0){
  opc=0;
 
  break; 
 }   }while(opc==0);
    
    switch(opc){
     case 1:{
         clientes();
         break;
        }   
        case 2:{
      mesas();
         break;
        }
        case 3:{
      reservaciones();
         break;
        }
        case 4:{
           clientesFrecuentes();
         break;
        }
        case 5:{
          empleados();
         break;
        } 
        case 6:{
         menu();
		 break;   
        }  
		 case 7:{
		 break;   
        }    
        default :{
            cout<<"Opcion no encontrada "<<endl;
            system("pause");
            break;
           }       
    } 
    }while(opc!=7);   
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+++++++++CLIENTES+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void clientes(){

void guardarCliente(),mostrarCliente(),buscarCliente(),modificarCliente(),eliminarCliente(),ver();
char var[30];   


    int opc;
    do{
        system("cls");
    cout<<"|------REGISTRO DE CLIENTES-------|"<<endl;    
    cout<<"| 1. Guardar cliente              |" <<endl;
    cout<<"| 2. Mostrar todos los clientes   |" <<endl;
    cout<<"| 3. Buscar cliente               |" <<endl;
    cout<<"| 4. Modificar cliente            |" <<endl;
    cout<<"| 5. Eliminar cliente             |" <<endl;
    cout<<"| 6. Salir                        |" <<endl;
    cout<<"|---------------------------------|"<<endl; 
    
    do{
 cin>>var;
 cout<<"                   "<<endl;
 opc=atoi(var);
 if(strcmp(var,"0")==0){
  opc=0;
 
  break; 
 }   }while(opc==0);
    
    switch(opc){
     case 1:{
        guardarCliente();
         break;
        }   
        case 2:{
        mostrarCliente();
         break;
        }
        case 3:{
        buscarCliente();
         break;
        }
        case 4:{
        modificarCliente();
         break;
        }
        case 5:{
          eliminarCliente();
         break;
        } 
        case 6:{
         break;   
        }    
        default :{
            cout<<"Opcion no encontrada "<<endl;
            system("pause");
            break;
           }       
    } 
    }while(opc!=6);   
}
//------------------GUARDAR-----------------
void guardarCliente(){
	ofstream archivo;
	system("cls");
	archivo.open("Clientes.txt",ios::app);
	int codigo;
	string cliente, telefono, direccion;
	cout<<"Ingrese codigo para el cliente: "<<endl;
	cin>>codigo;
	cin.ignore();
	cout<<"Ingrese el nombre y el apellido del cliente en minusculas: "<<endl;
	getline(cin,cliente);
	cout<<"Ingrese el numero de telefono del clientes: "<<endl;
	getline(cin,telefono);
	cout<<"Ingrese la direccion de vivienda del cliente: "<<endl;
	getline(cin,direccion);
	archivo<<codigo<<","<<cliente<<","<<telefono<<","<<direccion<<",1"<<endl;
    archivo.close();
	system("pause");
}
//--------------MOSTRAR TODOS------------
void mostrarCliente(){
	int codigo;
	char cliente[30],telefono[20],direccion[30];
	ifstream Leer;
	int contador=0;
	system("cls");
	Leer.open("Clientes.txt");
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(cliente,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(telefono,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(direccion,puntero);
			}
		}
	cout<<"--------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre del cliente: "<<cliente<<endl;
	cout<<"Numero de telefono: "<<telefono<<endl;
	cout<<"Direccion de vivienda: "<<direccion<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	contador++;
	}
		cout<<"El total de registros es "<<contador<<endl;
	Leer.close();
	system("pause");
}

//--------------BUSCAR------------
void buscarCliente(){
	int codigo,cod;
	char cliente[30],telefono[20],direccion[30];
	ifstream Leer;
	int contador=0;
	bool bandera=false;
	system("cls");
	Leer.open("Clientes.txt");
	cout<<"Ingrese el codigo del cliente a buscar"<<endl;
	cin>>cod;
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(cliente,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(telefono,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(direccion,puntero);
			}
		}
	
	if(cod==codigo) {
		bandera=true;
	cout<<"--------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre del cliente: "<<cliente<<endl;
	cout<<"Numero de telefono: "<<telefono<<endl;
	cout<<"Direccion de vivienda: "<<direccion<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<endl;
	Leer.getline(linea,sizeof(linea));
	} else {
		Leer.getline(linea,sizeof(linea));
	}
	}	
	if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
	Leer.close();
	system("pause");
}

//--------------MODIFICAR----------------
void modificarCliente(){
	int codigo,cod;
	char cliente[30],telefono[20],direccion[30];
	
	string clientenu, telefononu, direccionnu;
	
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	int contador=0;
	system("cls");
	Leer.open("Clientes.txt");
	Temp.open("Temp.txt");
	cout<<"Ingrese el codigo del cliente del que se va a modificar la informacion: "<<endl;
	cin>>cod;
	cin.ignore();
	
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(cliente,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(telefono,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(direccion,puntero);
			}
		}
	
	if(cod==codigo){
		bandera=true;	
		
	cout<<"--------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre del cliente: "<<cliente<<endl;
	cout<<"Numero de telefono: "<<telefono<<endl;
	cout<<"Direccion de vivienda: "<<direccion<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<endl;	
	
	cout<<"Ingrese el nombre y apellido del cliente en minusculas: "<<endl;
	getline(cin,clientenu);
	cout<<"Ingrese el numero de telefono: "<<endl;
	getline(cin,telefononu);
	cout<<"Ingrese la direccion de vivienda del cliente: "<<endl;
	getline(cin,direccionnu);

	cout<<"\n";

	cout<<"--------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre del cliente: "<<clientenu<<endl;
	cout<<"Numero de telefono: "<<telefononu<<endl;
	cout<<"Direccion de vivienda: "<<direccionnu<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<endl;	
	
	Leer.getline(linea,sizeof(linea));
	Temp<<codigo<<","<<clientenu<<","<<telefononu<<","<<direccionnu<<endl;
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<codigo<<","<<cliente<<","<<telefono<<","<<direccion<<endl;
}
	}
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
	Leer.close();
	Temp.close();
    remove("Clientes.txt");
	rename("Temp.txt","Clientes.txt");
	system("pause");
}

//--------------ELIMINAR-----------------
void eliminarCliente(){
	int codigo,cod;
	char cliente[30],telefono[10],direccion[10];
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	int contador=0;
	system("cls");
	Leer.open("Clientes.txt");
	Temp.open("Temp.txt");
	cout<<"Ingrese el codigo del cliente que desea eliminar: "<<endl;
	cin>>cod;
	cin.ignore();
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(cliente,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(telefono,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(direccion,puntero);
			}
		}
	if(cod==codigo){
		bandera=true;	
	cout<<"--------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre del cliente: "<<cliente<<endl;
	cout<<"Numero de telefono: "<<telefono<<endl;
	cout<<"Direccion de vivienda: "<<direccion<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<codigo<<","<<cliente<<","<<telefono<<","<<direccion<<endl;
}
	}
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
		
		else{
			int confirmacion;
			cout<<"Esta seguro que desea eliminar el registro?"<<endl;
	cout<<"1 para confirmar"<<endl;
	cout<<"2 para cancelar\n";
	cin>>confirmacion;
				
			switch(confirmacion){
							case 2:{
				Leer.close();
	Temp.close();
    remove("Temp.txt");
	cout<<"El registro NO fue eliminado\n";
	
				break;
			}
			case 1:{
				Leer.close();
	Temp.close();
    remove("Clientes.txt");
	rename("Temp.txt","Clientes.txt");
	cout<<"Registro eliminado con exito\n";

					break;
			}
			default:{
						cout<<"Opcion no encontrada"<<endl;
						cout<<"El registro NO fue eliminado\n";

				break;
			}
			}

		}
		
			system("pause");


}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/ +++++++++MESAS+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/



void mesas(){

void guardarMesa(),mostrarMesa(),buscarMesa(),modificarMesa(),eliminarMesa(),ver();
char var[30];
// ++++++++++++MESAS+++++++++++++++ 
   

    int opc;
    do{
        system("cls");
    cout<<"|------REGISTRO DE MESAS-------|"<<endl;    
    cout<<"| 1. Guardar mesa              |" <<endl;
    cout<<"| 2. Mostrar todas las mesas   |" <<endl;
    cout<<"| 3. Buscar mesa               |" <<endl;
    cout<<"| 4. Modificar mesa            |" <<endl;
    cout<<"| 5. Eliminar mesa             |" <<endl;
    cout<<"| 6. Salir                     |" <<endl;
    cout<<"|------------------------------|"<<endl; 
    
    do{
 cin>>var;
 cout<<"                   "<<endl;
 opc=atoi(var);
 if(strcmp(var,"0")==0){
  opc=0;
 
  break; 
 }   }while(opc==0);
    
    switch(opc){
     case 1:{
         guardarMesa();
         break;
        }   
        case 2:{
      mostrarMesa();
         break;
        }
        case 3:{
      buscarMesa();
         break;
        }
        case 4:{
           modificarMesa();
         break;
        }
        case 5:{
          eliminarMesa();
         break;
        } 
        case 6:{
         break;   
        }    
        default :{
            cout<<"Opcion no encontrada "<<endl;
            system("pause");
            break;
           }       
    } 
    }while(opc!=6);   
}
//------------------GUARDAR-----------------
void guardarMesa(){
	ofstream archivo;
	system("cls");
	archivo.open("Mesas.txt",ios::app);
	int numero;
	string sillas,ubicacion;
	cout<<"Ingrese numero de mesa: "<<endl;
	cin>>numero;
	cin.ignore();
	cout<<"Ingrese numero de sillas de la mesa: "<<endl;
	getline(cin,sillas);
	cout<<"Ingrese la ubicacion de la mesa: "<<endl;
	getline(cin,ubicacion);
	archivo<<numero<<","<<sillas<<","<<ubicacion<<endl;
    archivo.close();
	system("pause");
}
//--------------MOSTRAR TODOS------------
void mostrarMesa(){
	int numero;
	char sillas[30],ubicacion[30];
	ifstream Leer;
	int contador=0;
	system("cls");
	Leer.open("Mesas.txt");
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				numero=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(sillas,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(ubicacion,puntero);
			}
		}
	cout<<"--------------------------------"<<endl;
	cout<<"Numero de mesa: "<<numero<<endl;
	cout<<"Numero de sillas: "<<sillas<<endl;
	cout<<"Ubicacion de la mesa: "<<ubicacion<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	contador++;
	}
		cout<<"El total de registros es "<<contador<<endl;
	Leer.close();
	system("pause");
}

//--------------BUSCAR------------
void buscarMesa(){
	int numero,cod;
	char sillas[20],ubicacion[30];
	ifstream Leer;
	int contador=0;
	bool bandera=false;
	system("cls");
	Leer.open("Mesas.txt");
	cout<<"Ingrese el codigo de la mesa a buscar:"<<endl;
	cin>>cod;
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				numero=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(sillas,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(ubicacion,puntero);
			}
		}
	
	if(cod==numero) {
		bandera=true;
	cout<<"--------------------------------"<<endl;
	cout<<"Numero de mesa: "<<numero<<endl;
	cout<<"Numero de sillas: "<<sillas<<endl;
	cout<<"Ubicacion de la mesa: "<<ubicacion<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<endl;
	Leer.getline(linea,sizeof(linea));
	} else {
		Leer.getline(linea,sizeof(linea));
	}
	}	
	if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
	Leer.close();
	system("pause");
}

//--------------MODIFICAR----------------
void modificarMesa(){
	int numero,cod;
	char ubicacion[30],sillas[30];
	
	
	string ubicacionNuevo, sillasNuevo;
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	int contador=0;
	system("cls");
	Leer.open("Mesas.txt");
	Temp.open("Temp.txt");
	cout<<"Ingrese el numero de mesa a modificar: "<<endl;
	cin>>cod;
	cin.ignore();
	
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				numero=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(sillas,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(ubicacion,puntero);
			}
		}
	if(cod==numero){
		bandera=true;	
	cout<<"------ ----REGISTRO ACTUAL------------"<<endl;
	cout<<"Numero de mesa: "<<numero<<endl;
	cout<<"Numero de sillas: "<<sillas<<endl;
	cout<<"Ubicacion de la mesa: "<<ubicacion<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<endl;	
	cout<<"Ingrese nuevo numero de sillas de la mesa: "<<endl;
	getline(cin,sillasNuevo);
	cout<<"Ingrese la nueva ubicacion de la mesa: "<<endl;
	getline(cin,ubicacionNuevo);
	cout<<"\n";

	cout<<"------------NUEVO REGISTRO-----------"<<endl;
	cout<<"Numero de mesa: "<<cod<<endl;
	cout<<"Numero de sillas: "<<sillasNuevo<<endl;
	cout<<"Ubicacion de la mesa: "<<ubicacionNuevo<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	Temp<<numero<<","<<sillasNuevo<<","<<ubicacionNuevo<<endl;
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<numero<<","<<sillas<<","<<ubicacion<<endl;
}
	}
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
	Leer.close();
	Temp.close();
    remove("Mesas.txt");
	rename("Temp.txt","Mesas.txt");
	system("pause");
}

//--------------ELIMINAR-----------------
void eliminarMesa(){
	int numero,cod;
	char sillas[30],ubicacion[30];
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	int contador=0;
	system("cls");
	Leer.open("Mesas.txt");
	Temp.open("Temp.txt");
	cout<<"Ingrese el numero de mesa a eliminar: "<<endl;
	cin>>cod;
	cin.ignore();
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				numero=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(sillas,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(ubicacion,puntero);
			}
		}
	if(cod==numero){
		bandera=true;	
	cout<<"---------REGISTRO A ELIMINAR----------"<<endl;
	cout<<"Numero de mesa: "<<cod<<endl;
	cout<<"Numero de sillas: "<<sillas<<endl;
	cout<<"Ubicacion de la mesa: "<<ubicacion<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<numero<<","<<sillas<<","<<ubicacion<<endl;
}
	}
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
		
		else{
			int confirmacion;
			cout<<"¿Esta seguro que desea eliminar el registro?"<<endl;
	cout<<"1 para confirmar"<<endl;
	cout<<"2 para cancelar\n";
	cin>>confirmacion;
				
			switch(confirmacion){
							case 2:{
				Leer.close();
	Temp.close();
    remove("Temp.txt");
	cout<<"El registro NO fue eliminado\n";
	
				break;
			}
			case 1:{
	Leer.close();
	Temp.close();
    remove("Mesas.txt");
	rename("Temp.txt","Mesas.txt");
	cout<<"Registro eliminado con exito\n";

					break;
			}
			default:{
						cout<<"Opcion no encontrada"<<endl;
						cout<<"El registro NO fue eliminado\n";

				break;
			}
			}

		}
		
			system("pause");


}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/ +++++++++RESERVACIONES+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void reservaciones(){
	

// ++++++++++++RESERVACIONES+++++++++++++++ 
  

void guardarReservacion(),mostrarReservacion(),reservacionFecha(),reservacionCliente(),modificarReservacion(),eliminarReservacion(),ver();
char var[30];   

    int opc;
    do{
        system("cls");
    cout<<"|--------REGISTRO DE RESERVACIONES---------|"<<endl;    
    cout<<"| 1. Guardar nueva reservacion             |" <<endl;
    cout<<"| 2. Mostrar todas las reservaciones       |" <<endl;
    cout<<"| 3. Buscar reservacion por fecha          |" <<endl;
    cout<<"| 4. Buscar reservacion por cliente        |" <<endl;
    cout<<"| 5. Modificar reservacion                 |" <<endl;
    cout<<"| 6. Eliminar reservacion                  |" <<endl;
    cout<<"| 7. Salir                                 |" <<endl;
    cout<<"|------------------------------------------|" <<endl;
    
    do{
 cin>>var;
 cout<<"                   "<<endl;
 opc=atoi(var);
 if(strcmp(var,"0")==0){
  opc=0;
 
  break; 
 }   }while(opc==0);
    
    switch(opc){
     case 1:{
         guardarReservacion();
         break;
        }   
        case 2:{
      mostrarReservacion();
         break;
        }
        case 3:{
      reservacionFecha();
         break;
        }
        case 4:{
           reservacionCliente();
         break;
        }
        case 5:{
          modificarReservacion();
         break;
        } 
        case 6:{
            eliminarReservacion();
         break;   
        } 
        case 7:{
         break;   
        }   
        default :{
            cout<<"Opcion no encontrada "<<endl;
            system("pause");
            break;
           }       
    } 
    }while(opc!=7);   
}
//------------------GUARDAR-----------------
void guardarReservacion(){
	ofstream archivo;
	system("cls");
	archivo.open("Reservaciones.txt",ios::app);
	int codigoReservacion,codigoClienteReservacion,numeroMesaReservacion,frecuenciaNueva=0;
	string fechaReservacion;
	
	cout<<"Ingrese codigo de reservacion: "<<endl;
	
	    do{
 cin>>var;
 cout<<"                   "<<endl;
 codigoReservacion=atoi(var);
 if(strcmp(var,"0")==0){
  codigoReservacion=0;
 
  break; 
 }   }while(codigoReservacion==0);
 
 
	cin.ignore();
	
	cout<<"Ingrese numero de mesa: "<<endl;
	
	    do{
 cin>>var;
 cout<<"                   "<<endl;
 numeroMesaReservacion=atoi(var);
 if(strcmp(var,"0")==0){
  numeroMesaReservacion=0;
 
  break; 
 }   }while(numeroMesaReservacion==0);
    cin.ignore();
    
    cout<<"Ingrese codigo del cliente: "<<endl;
	
	    do{
 cin>>var;
 cout<<"                   "<<endl;
 codigoClienteReservacion=atoi(var);
 if(strcmp(var,"0")==0){
  codigoClienteReservacion=0;
 
  break; 
 }   }while(codigoClienteReservacion==0);
 
 
	cin.ignore();
    
	cout<<"Ingrese fecha de la reservacion (dd/mm/aa): "<<endl;
	getline(cin,fechaReservacion);
	
	
	archivo<<codigoReservacion<<","<<numeroMesaReservacion<<","<<codigoClienteReservacion<<","<<fechaReservacion<<endl;
    archivo.close();
    
    
    int codigo;
	char cliente[30],telefono[20],direccion[30];
	
	string clientenu, telefononu, direccionnu;
	
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	Leer.open("Clientes.txt");
	Temp.open("Temp.txt");
	
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<5;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(cliente,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(telefono,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(direccion,puntero);
			} else if (i==4){
			    puntero=strtok(NULL,",");
				frecuenciaNueva=atoi(puntero);
			}
		}
	
	if(codigoClienteReservacion==codigo){
		bandera=true;	
	
	Leer.getline(linea,sizeof(linea));
	Temp<<codigo<<","<<cliente<<","<<telefono<<","<<direccion<<","<<(frecuenciaNueva+1)<<endl;
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<codigo<<","<<cliente<<","<<telefono<<","<<direccion<<","<<(frecuenciaNueva)<<endl;
}
	}
		
	Leer.close();
	Temp.close();
    remove("Clientes.txt");
	rename("Temp.txt","Clientes.txt");
    
    
	system("pause");

	
}
//--------------MOSTRAR TODOS--------------
void mostrarReservacion(){
	int codigoReservacion,numeroMesaReservacion,codigoClienteReservacion;
	char fechaReservacion[10];
	ifstream Leer;
	int contador=0;
	system("cls");
	Leer.open("Reservaciones.txt");
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<6;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigoReservacion=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				numeroMesaReservacion=atoi(puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				codigoClienteReservacion=atoi(puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(fechaReservacion,puntero);
			}
		}
	cout<<"---------------------------------------"<<endl;
	cout<<"Codigo de la reservacion: "<<codigoReservacion<<endl;
	cout<<"Codigo del cliente: "<<codigoClienteReservacion<<endl;
	cout<<"Fecha de la reservacion: "<<fechaReservacion<<endl;
	cout<<"Numero de mesa de la reservacion: "<<numeroMesaReservacion<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	contador++;
	}
		cout<<"El total de registros es "<<contador<<endl;
	Leer.close();
	system("pause");
}

//--------------BUSCAR POR FECHA------------
void reservacionFecha(){
	int codigoReservacion,numeroMesaReservacion,codigoClienteReservacion;
	char fechaReservacion[15], fechaReservacionBuscar[15];
	ifstream Leer;
	int contador=0;
	bool bandera=false;
	system("cls");
	Leer.open("Reservaciones.txt");
	cout<<"Ingrese la fecha que desea que desea desplegar (dd/mm/aa): "<<endl;
	cin>>fechaReservacionBuscar;
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<6;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigoReservacion=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				numeroMesaReservacion=atoi(puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				codigoClienteReservacion=atoi(puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(fechaReservacion,puntero);
			}
		}
	if((strcmp(fechaReservacion,fechaReservacionBuscar)==0)) {
		bandera=true;
	cout<<"---------------------------------------"<<endl;
	cout<<"Fecha de la reservacion: "<<fechaReservacion<<endl;
	cout<<"Codigo de la reservacion: "<<codigoReservacion<<endl;
	cout<<"Codigo del cliente: "<<codigoClienteReservacion<<endl;
	cout<<"Numero de mesa de la reservacion: "<<numeroMesaReservacion<<endl;	
	cout<<"---------------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));

	} else {
		Leer.getline(linea,sizeof(linea));
	}
	}	
	if(bandera==false){
			cout<<"No existen registros para esa fecha"<<endl;
		}
	Leer.close();
	system("pause");
}
//----------BUSCAR POR CLIENTE-------------

void reservacionCliente(){
	
	int codigoReservacion,numeroMesaReservacion,codigoClienteReservacion,cod;
	char fechaReservacion[15];
	ifstream Leer;
	int contador=0;
	bool bandera=false;
	system("cls");
	Leer.open("Reservaciones.txt");
	cout<<"Ingrese el numero de cliente del que desea buscar registros de reservaciones: "<<endl;
	cin>>cod;
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<6;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigoReservacion=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				numeroMesaReservacion=atoi(puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				codigoClienteReservacion=atoi(puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(fechaReservacion,puntero);
			}
		}
	if(cod==codigoClienteReservacion) {
		bandera=true;
	cout<<"---------------------------------------"<<endl;
	cout<<"Codigo del cliente: "<<codigoClienteReservacion<<endl;
	cout<<"Codigo de la reservacion: "<<codigoReservacion<<endl;
	cout<<"Fecha de la reservacion: "<<fechaReservacion<<endl;
	cout<<"Numero de mesa de la reservacion: "<<numeroMesaReservacion<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	} else {
		Leer.getline(linea,sizeof(linea));
	}
	}	
	if(bandera==false){
			cout<<"No existen registros para ese cliente"<<endl;
		}
	Leer.close();
	system("pause");	

}

//--------------MODIFICAR----------------
void modificarReservacion(){
	int codigoReservacion,numeroMesaReservacion,codigoClienteReservacion,cod;
	char fechaReservacion[15];
	
	int numeroMesaReservacionNuevo,codigoClienteReservacionNuevo;
	string fechaReservacionNuevo;
	
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	int contador=0;
	system("cls");
	Leer.open("Reservaciones.txt");
	Temp.open("Temp.txt");
	cout<<"Ingrese el codigo de reservacion a modificar: "<<endl;
	cin>>cod;
	cin.ignore();
	
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<6;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigoReservacion=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				numeroMesaReservacion=atoi(puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				codigoClienteReservacion=atoi(puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(fechaReservacion,puntero);
			}
		}
		
	if(cod==codigoReservacion){
		bandera=true;	
	cout<<"------------REGISTRO ACTUAL------------"<<endl;
    cout<<"Codigo de la reservacion: "<<codigoReservacion<<endl;
	cout<<"Codigo del cliente: "<<codigoClienteReservacion<<endl;
	cout<<"Fecha de la reservacion: "<<fechaReservacion<<endl;
	cout<<"Numero de mesa de la reservacion: "<<numeroMesaReservacion<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<endl;	
	
	
	
	cout<<"Ingrese nuevo numero de mesa: "<<endl;
	
	    do{
 cin>>var;
 cout<<"                   "<<endl;
 numeroMesaReservacionNuevo=atoi(var);
 if(strcmp(var,"0")==0){
  numeroMesaReservacionNuevo=0;
 
  break; 
 }   }while(numeroMesaReservacionNuevo==0);
    cin.ignore();
    
    cout<<"Ingrese nuevo codigo del cliente: "<<endl;
	
	    do{
 cin>>var;
 cout<<"                   "<<endl;
 codigoClienteReservacionNuevo=atoi(var);
 if(strcmp(var,"0")==0){
  codigoClienteReservacionNuevo=0;
 
  break; 
 }   }while(codigoClienteReservacionNuevo==0);
 
 
	cin.ignore();
    
	cout<<"Ingrese nueva fecha de la reservacion (dd/mm/aa): "<<endl;
	getline(cin,fechaReservacionNuevo);
	
	
	

	cout<<"------------NEVO REGISTRO-----------"<<endl;
	cout<<"Codigo de la reservacion: "<<codigoReservacion<<endl;
	cout<<"Codigo del cliente: "<<codigoClienteReservacionNuevo<<endl;
	cout<<"Fecha de la reservacion: "<<fechaReservacionNuevo<<endl;
	cout<<"Numero de mesa de la reservacion: "<<numeroMesaReservacionNuevo<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	Temp<<codigoReservacion<<","<<numeroMesaReservacionNuevo<<","<<codigoClienteReservacionNuevo<<","<<fechaReservacionNuevo<<endl;
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<codigoReservacion<<","<<numeroMesaReservacion<<","<<codigoClienteReservacion<<","<<fechaReservacion<<endl;
}
}
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
	Leer.close();
	Temp.close();
    remove("Reservaciones.txt");
	rename("Temp.txt","Reservaciones.txt");
	system("pause");
}

//--------------ELIMINAR-----------------
void eliminarReservacion(){
int codigoReservacion,numeroMesaReservacion,codigoClienteReservacion,cod;
	char fechaReservacion[15];
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	int contador=0;
	system("cls");
	Leer.open("Reservaciones.txt");
	Temp.open("Temp.txt");
	cout<<"Ingrese el codigo de reservacion a eliminar: "<<endl;
	cin>>cod;
	cin.ignore();
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<6;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigoReservacion=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				numeroMesaReservacion=atoi(puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				codigoClienteReservacion=atoi(puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(fechaReservacion,puntero);
			}
		}
	if(cod==codigoReservacion){
		bandera=true;	
	cout<<"---------REGISTRO A ELIMINAR----------"<<endl;
    cout<<"Codigo de la reservacion: "<<codigoReservacion<<endl;
	cout<<"Codigo del cliente: "<<codigoClienteReservacion<<endl;
	cout<<"Fecha de la reservacion: "<<fechaReservacion<<endl;
	cout<<"Numero de mesa de la reservacion: "<<numeroMesaReservacion<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<codigoReservacion<<","<<numeroMesaReservacion<<","<<codigoClienteReservacion<<","<<fechaReservacion<<endl;
}
}
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
		
		else{
			int confirmacion;
			cout<<"¿Esta seguro que desea eliminar el registro?"<<endl;
	cout<<"1 para confirmar"<<endl;
	cout<<"2 para cancelar\n";
	cin>>confirmacion;
				
			switch(confirmacion){
							case 2:{
				Leer.close();
	Temp.close();
    remove("Temp.txt");
	cout<<"El registro NO fue eliminado\n";
	
				break;
			}
			case 1:{
				Leer.close();
	Temp.close();

    remove("Reservaciones.txt");
	rename("Temp.txt","Reservaciones.txt");
	cout<<"Registro eliminado con exito\n";

					break;
			}
			default:{
						cout<<"Opcion no encontrada"<<endl;
						cout<<"El registro NO fue eliminado\n";

				break;
			}
			}

		}
		
			system("pause");


	
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/ +++++++++CLIENTES FRECUENTES++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void clientesFrecuentes(){

using namespace std;

void clienteFrecuente(), ver();

char var[30];   

    int opc;
    do{
        system("cls");
    cout<<"|------CLIENTES FRECUENTES-----------|"<<endl;    
    cout<<"| 1. Mostrar la frecuencia           |" <<endl;
    cout<<"| 2. Salir                           |" <<endl;
    cout<<"|------------------------------------|"<<endl; 
    
    do{
 cin>>var;
 cout<<"                   "<<endl;
 opc=atoi(var);
 if(strcmp(var,"0")==0){
  opc=0;
 
  break; 
 }   }while(opc==0);
    
    switch(opc){
     case 1:{
        clienteFrecuente();
         break;
        }   
        case 2:{
        break;
		}
        default :{
            cout<<"Opcion no encontrada "<<endl;
            system("pause");
            break;
           }       
    } 
    }while(opc!=2);   
}
	
void clienteFrecuente(){
	
	int codigo, frecuenciaNueva;
	char cliente[30],telefono[20],direccion[30];
	ifstream Leer;
	int contador=0;
	system("cls");
	Leer.open("Clientes.txt");
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<5;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(cliente,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(telefono,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(direccion,puntero);
			} else if (i==4){
			    puntero=strtok(NULL,",");
				frecuenciaNueva=atoi(puntero);
			}
		}
	cout<<"--------------------------------"<<endl;
	cout<<"Frecuencia del cliente: "<<frecuenciaNueva<<endl;
	cout<<"Codigo del cliente: "<<codigo<<endl;
	cout<<"Nombre del cliente: "<<cliente<<endl;
	cout<<"Numero de telefono: "<<telefono<<endl;
	cout<<"Direccion de vivienda: "<<direccion<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	contador++;
	}
		cout<<"El total de registros es "<<contador<<endl;
	Leer.close();
	system("pause");
	
}


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/ +++++++++EMPLEADOS++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void empleados(){
 
using namespace std;

 
 void guardar(),mostrar(),buscar(),modificar(),eliminar(),ver();

	int opc;
	do{
	system("cls");
    cout<<"| ----Empleados---- |"<<endl;    
    cout<<"| 1. Guardar nuevo  |"<<endl;
    cout<<"| 2. Mostrar todos  |"<<endl;
    cout<<"| 3. Buscar         |"<<endl;
    cout<<"| 4. Modificar      |"<<endl;
    cout<<"| 5. Eliminar       |"<<endl;
    cout<<"| 6. Salir          |"<<endl;
    cout<<"| ----------------- |";
    cout<<"\nIngrese la opcion: "<<endl;
    cin>>opc;
		
switch(opc){
     case 1:{
         guardar ();
         break;
     }
     case 2:{
      mostrar();
         break;
        }
        case 3:{
      buscar();
         break;
        }
        case 4:{
           modificar();
         break;
        }
        case 5:{
          eliminar();
         break;
        } 
        case 6:{
         break;  
        }       
        default :{
            cout<<"\n \t\t\tOpcion no encontrada"<<endl;
            system("pause");
            
            break;
           }    
    }
		

	}while(opc!=6);
    
    
}

//------------------GUARDAR-----------------
void guardar(){
	ofstream archivo;
	system("cls");
	archivo.open("Empleados.txt",ios::app);

	int codigo, edad;
	float salario;
	string nombre, fechaContratacion, telefono, direccion, puesto;
	
	cout<<"Ingrese el codigo: "<<endl;
	cin>>codigo;
	cin.ignore();
	cout<<"Ingrese nombre completo: "<<endl;
	getline(cin, nombre);
	cout<<"Ingrese edad: "<<endl;
	cin>>edad;
	cin.ignore();
	cout<<"Ingrese telefono: "<<endl;
	getline(cin, telefono);
	cout<<"Ingrese direccion: "<<endl;
	getline(cin, direccion);
	cout<<"Ingrese fecha de contratacion: "<<endl;
	getline(cin, fechaContratacion);
	cout<<"Ingrese el puesto: "<<endl;
	getline(cin, puesto);
	cout<<"Ingrese salario: "<<endl;
	cin>>salario;
	
	archivo<<codigo<<", "<<nombre<<", "<<edad<<", "<<telefono<<", "<<direccion<<", "<<fechaContratacion<<", "<<puesto<<", "<<salario<<endl;
    archivo.close();
	system("pause");
}

//--------------MOSTRAR TODOS------------
void mostrar(){
	int codigo, edad;
	float salario;
	char nombre[50], fechaContratacion[15], telefono[12], direccion[50], puesto[20];
	
	ifstream Leer;
	
	int contador=0;
	system("cls");
	Leer.open("Empleados.txt");
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<8;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				edad=atoi(puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(telefono,puntero);
			}else if(i==4){
				puntero=strtok(NULL,",");
				strcpy(direccion,puntero);
			}else if(i==5){
				puntero=strtok(NULL,",");
				strcpy(fechaContratacion,puntero);
			}else if(i==6){
				puntero=strtok(NULL,",");
				strcpy(puesto,puntero);
			}else if(i==7){
				puntero=strtok(NULL,",");
				salario=atoi(puntero);
			}
		}
	cout<<"\t\t\tLos datos ingresados son" <<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre: " <<nombre<<endl;
	cout<<"Edad: " <<edad <<endl;
	cout<<"Telefono: "<<telefono<<endl;
	cout<<"Direccion: "<<direccion <<endl;
	cout<<"Fecha de contratacion: "<<fechaContratacion <<endl;
	cout<<"Puesto: "<<puesto <<endl;
	cout<<"Salario: " <<salario <<endl;
	cout<<"--------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	contador++;
	}
		cout<<"El total de empleados registrados es:"<<contador<<endl;
	Leer.close();
	system("pause");
}

//--------------BUSCAR------------
void buscar(){
	int codigo,cod, edad;
	bool bandera=false;
	float salario;
	char nombre[50], fechaContratacion[15], telefono[12], direccion[50], puesto[20];
	
	ifstream Leer;
	
	int contador=0;
	system("cls");
	Leer.open("Empleados.txt");
	cout<<"Ingrese el codigo a buscar"<<endl;
	cin>>cod;
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<8;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				edad=atoi(puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(telefono,puntero);
			}else if(i==4){
				puntero=strtok(NULL,",");
				strcpy(direccion,puntero);
			}else if(i==5){
				puntero=strtok(NULL,",");
				strcpy(fechaContratacion,puntero);
			}else if(i==6){
				puntero=strtok(NULL,",");
				strcpy(puesto,puntero);
			}else if(i==7){
				puntero=strtok(NULL,",");
				salario=atoi(puntero);
			}
		}
	if(cod==codigo){
		bandera=true;	
	cout<<"-------REGISTRO ENCONTRADO-------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre: " <<nombre<<endl;
	cout<<"Edad: " <<edad <<endl;
	cout<<"Telefono: "<<telefono<<endl;
	cout<<"Direccion: "<<direccion <<endl;
	cout<<"Fecha de contratacion: "<<fechaContratacion <<endl;
	cout<<"Puesto: "<<puesto <<endl;
	cout<<"Salario: " <<salario <<endl;
	cout<<"--------------------------------"<<endl;
	Leer.getline(linea,sizeof(linea));
	}else{
		Leer.getline(linea,sizeof(linea));
	}
}
	
	if(bandera==false){
		cout<<"El registro no existe"<<endl;
	}
	Leer.close();
	system("pause");
}

//--------------MODIFICAR----------------
void modificar(){
	int codigo,cod, edad;
	bool bandera=false;
	float salario;
	char nombre[50], fechaContratacion[15], telefono[12], direccion[50], puesto[20];
	
	int codigo2, edad2;
	float salario2;
	string nombre2, fechaContratacion2, telefono2, direccion2, puesto2;
	
	ifstream Leer;
	ofstream Temp;
	
	int contador=0;
	system("cls");
	Leer.open("Empleados.txt");
	Temp.open("Temp.txt");
	cout<<"Ingrese el codigo a modificar"<<endl;
	cin>>cod;
	cin.ignore();
cout<<"Ingrese nombre completo: "<<endl;
	getline(cin, nombre2);
	cout<<"Ingrese edad: "<<endl;
	cin>>edad2;
	cin.ignore();
	cout<<"Ingrese telefono: "<<endl;
	getline(cin, telefono2);
	cout<<"Ingrese direccion: "<<endl;
	getline(cin, direccion2);
	cout<<"Ingrese fecha de contratacion: "<<endl;
	getline(cin, fechaContratacion2);
	cout<<"Ingrese el puesto: "<<endl;
	getline(cin, puesto2);
	cout<<"Ingrese salario: "<<endl;
	cin>>salario2;
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	
	while(!Leer.eof()){
		for(int i=0;i<8;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				edad=atoi(puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(telefono,puntero);
			}else if(i==4){
				puntero=strtok(NULL,",");
				strcpy(direccion,puntero);
			}else if(i==5){
				puntero=strtok(NULL,",");
				strcpy(fechaContratacion,puntero);
			}else if(i==6){
				puntero=strtok(NULL,",");
				strcpy(puesto,puntero);
			}else if(i==7){
				puntero=strtok(NULL,",");
				salario=atoi(puntero);
			}
		}
	if(cod==codigo){
		bandera=true;	
	cout<<"--------REGISTRO ACTUAL---------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre: " <<nombre<<endl;
	cout<<"Edad: " <<edad <<endl;
	cout<<"Telefono: "<<telefono<<endl;
	cout<<"Direccion: "<<direccion <<endl;
	cout<<"Fecha de contratacion: "<<fechaContratacion <<endl;
	cout<<"Puesto: "<<puesto <<endl;
	cout<<"Salario: " <<salario <<endl;
	cout<<"--------------------------------"<<endl;	
	cout<<"\n\n";

	cout<<"---------NUEVO REGISTRO---------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre: " <<nombre2<<endl;
	cout<<"Edad: " <<edad2 <<endl;
	cout<<"Telefono: "<<telefono2<<endl;
	cout<<"Direccion: "<<direccion2 <<endl;
	cout<<"Fecha de contratacion: "<<fechaContratacion2 <<endl;
	cout<<"Puesto: "<<puesto2 <<endl;
	cout<<"Salario: " <<salario2 <<endl;
	cout<<"--------------------------------"<<endl;
	
	Leer.getline(linea,sizeof(linea));
	Temp<<codigo<<", "<<nombre2<<", "<<edad2<<", "<<telefono2<<", "<<direccion2<<", "<<fechaContratacion2<<", "<<puesto2<<", "<<salario2<<endl;
	}
	
	else{
		Leer.getline(linea,sizeof(linea));
		Temp<<codigo<<", "<<nombre<<", "<<edad<<", "<<telefono<<", "<<direccion<<", "<<fechaContratacion<<", "<<puesto<<", "<<salario<<endl;

	}
}
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
	Leer.close();
	Temp.close();
    remove("Empleados.txt");
	rename("Temp.txt","Empleados.txt");
	system("pause");
}

//--------------ELIMINAR-----------------
void eliminar(){
	
		int codigo,cod, edad;
	bool bandera=false;
	float salario;
	char nombre[50], fechaContratacion[15], telefono[12], direccion[50], puesto[20];
	
	ifstream Leer;
	ofstream Temp;


	int contador=0;
	system("cls");
	Leer.open("Empleados.txt");
	Temp.open("Temp.txt");

	cout<<"Ingrese el codigo a eliminar"<<endl;
	cin>>cod;





char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<8;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				edad=atoi(puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(telefono,puntero);
			}else if(i==4){
				puntero=strtok(NULL,",");
				strcpy(direccion,puntero);
			}else if(i==5){
				puntero=strtok(NULL,",");
				strcpy(fechaContratacion,puntero);
			}else if(i==6){
				puntero=strtok(NULL,",");
				strcpy(puesto,puntero);
			}else if(i==7){
				puntero=strtok(NULL,",");
				salario=atoi(puntero);
			}
		}
	if(cod==codigo){
		bandera=true;	
	cout<<"-------Datos del empleado--------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre: " <<nombre<<endl;
	cout<<"Edad: " <<edad <<endl;
	cout<<"Telefono: "<<telefono<<endl;
	cout<<"Direccion: "<<direccion <<endl;
	cout<<"Fecha de contratacion: "<<fechaContratacion <<endl;
	cout<<"Puesto: "<<puesto <<endl;
	cout<<"Salario: " <<salario <<endl;
	cout<<"--------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<codigo<<", "<<nombre<<", "<<edad<<", "<<telefono<<", "<<direccion<<", "<<fechaContratacion<<", "<<puesto<<", "<<salario<<endl;
}
	}
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}else{
			int confirmacion;
			cout<<"Esta seguro que desea eliminar el registro?"<<endl;
	cout<<"1. para confirmar"<<endl;
	cout<<"2. para cancelar\n";
	cin>>confirmacion;
				
			switch(confirmacion){
							case 2:{
				Leer.close();
	Temp.close();
    remove("Temp.txt");
	cout<<"\t\t\tRegistro no eliminado\n";
	
				break;
			}
			case 1:{
				Leer.close();
	Temp.close();
    remove("Empleados.txt");
	rename("Temp.txt","Empleados.txt");
	cout<<"Registro del empleado eliminado con exito!!!\n";
				system("pause");

	cout<<"<<<<<<<<<<<<<<Los empleados existentes son:>>>>>>>>>>>>";
	mostrar();
					break;
			}
			default:{
						cout<<"Opcion no encontrada";

				break;
			}
			}

		}
		
			system("pause");


}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/ +++++++++MENU+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void menu(){
	
		int opc,p,b,t;
		do{
			system("cls");
		cout<<"|-------MENU---------|"<<endl;
		cout<<"| 1. Platillos       |"<<endl;
		cout<<"| 2. Bebidas         |"<<endl;
		cout<<"| 3. Postres         |"<<endl;
		cout<<"| 4. Salir           |"<<endl;
		cout<<"|--------------------|"<<endl;
		cin>>opc;
		switch(opc){
///////////////////////////////PLATILLOS///////////////////////////////
			case 1:{
				int p;
				 do{
        system("cls");
    cout<<"|-----------REGISTRO DE PLATILLOS----------|"<<endl;    
    cout<<"| 1. Guardar plaitllo                      |" <<endl;
    cout<<"| 2. Mostrar todos los platillos           |" <<endl;
    cout<<"| 3. Buscar platillo                       |" <<endl;
    cout<<"| 4. Modificar platillo                    |" <<endl;
    cout<<"| 5. Eliminar plaitllo                     |" <<endl;
    cout<<"| 6. Salir                                 |" <<endl;
    cout<<"|------------------------------------------|"<<endl;
    cin>>p;
    
    switch(p){

     case 1:{
     	/////////// GUARDAR ///////////////////7
	    ofstream archivo;
		system("cls");
		archivo.open("platillos.txt",ios::app);
		int codigo;
		string nombre,calorias, precio;
		cout<<"Ingrese codigo de platillo: "<<endl;
		cin>>codigo;
			cin.ignore();
		cout<<"Ingrese nombre de platillo : "<<endl;
		getline(cin,nombre);
		cout<<"Ingrese las caloria del platillo: "<<endl;
		getline(cin,calorias);
		cout<<"Ingrese  precio del platillo: "<<endl;
		getline(cin,precio);
		archivo<<codigo<<","<<nombre<<","<<calorias<<","<<precio<<endl;
		 archivo.close();
		system("pause");
        break;
        }   
        case 2:{
    /////////// MOSTRAR /////////////////7
	      int codigo;
		char nombre[10],calorias[10], precio[10];
		ifstream Leer;
		int contador=0;
		system("cls");
		Leer.open("platillos.txt");
		char linea[120];
		Leer.getline(linea,sizeof(linea));
		while(!Leer.eof()){
			for(int i=0;i<4;i++){
				char *puntero;
				if(i==0){
					puntero=strtok(linea,",");
					codigo=atoi(puntero);
				}else if(i==1){
					puntero=strtok(NULL,",");
					strcpy(nombre,puntero);
				}else if(i==2){
					puntero=strtok(NULL,",");
					strcpy(calorias,puntero);
				}else if(i==3){
					puntero=strtok(NULL,",");
					strcpy(precio,puntero);
				}
			}
		cout<<"------------------------------------"<<endl;
		cout<<"Codigo del platillo:  "<<codigo<<endl;
		cout<<"Noombre del platillo:  "<<nombre<<endl;
		cout<<"caloria del platillo:  "<<calorias<<endl;
		cout<<"Precio del platillo:  "<<precio<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<endl;	
		Leer.getline(linea,sizeof(linea));
		contador++;
		}
			cout<<"El total de registros es "<<contador<<endl;
		Leer.close();
		system("pause");
         break;
        }
        case 3:{
    //////////////// BUSCAR ////////////////////
      int codigo,cod;
	char nombre[10],calorias[10],precio[10];
	ifstream Leer;
	int contador=0;
	bool bandera=false;
	system("cls");
	Leer.open("platillos.txt");
	cout<<"Ingrese un codigo de platillo a buscar"<<endl;
	cin>>cod;
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(calorias,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(precio,puntero);
		}
	}
	if(cod==codigo){
			bandera=true;	
		cout<<"-------------------------------"<<endl;
		cout<<"Codigo de platillo:  "<<codigo<<endl;
		cout<<"Nombre de platillo:  "<<nombre<<endl;
		cout<<"Calorias del platillo:  "<<calorias<<endl;
		cout<<"Precio del platillo:  "<<precio<<endl;
		cout<<"-------------------------------"<<endl;
		cout<<endl;	
		Leer.getline(linea,sizeof(linea));
		}
			else{
		      Leer.getline(linea,sizeof(linea));
	}
		}
			if(bandera==false){
				cout<<"El registro no existe"<<endl;
			}
		Leer.close();
		system("pause");
	         break;
	        }
	        case 4:{
	///////////// MODIFICAR ///////////////////7
		int codigo,cod;
		char nombre[10],calorias[10],precio[10];
		string nombreNuevo,caloriasNuevo,precioNuevo;
		bool bandera=false;
		ifstream Leer;
		ofstream Temp;
		int contador=0;
		system("cls");
		Leer.open("platillos.txt");
		Temp.open("Temp.txt");
		cout<<"Ingrese el codigo de platillo a modificar"<<endl;
		cin>>cod;
		cin.ignore();
		
		char linea[120];
		Leer.getline(linea,sizeof(linea));
		while(!Leer.eof()){
			for(int i=0;i<4;i++){
				char *puntero;
				if(i==0){
					puntero=strtok(linea,",");
					codigo=atoi(puntero);
				}else if(i==1){
					puntero=strtok(NULL,",");
					strcpy(nombre,puntero);
				}else if(i==2){
					puntero=strtok(NULL,",");
					strcpy(calorias,puntero);
				}else if(i==3){
					puntero=strtok(NULL,",");
					strcpy(precio,puntero);
				}
			}
		if(cod==codigo){
			bandera=true;	
		cout<<"---------REGISTRO ACTUAL----------"<<endl;
		cout<<"Codigo del platillo:  "<<codigo<<endl;
		cout<<"Nombre de platillo:  "<<nombre<<endl;
		cout<<"Calorias del platillo:  "<<calorias<<endl;
		cout<<"Precio del platillo:  "<<precio<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<"\n";	
		cout<<"Ingrese nuevo nombre de platillo: "<<endl;
		getline(cin,nombreNuevo);
		cout<<"Ingrese nuevas calorias del platillo: "<<endl;
		getline(cin,caloriasNuevo);
		cout<<"Ingrese nuevo precio del patillo: "<<endl;
		getline(cin,precioNuevo);
		cout<<"\n";	
	
		cout<<"---------NUEVO REGISTRO----------"<<endl;
		cout<<"Codigo del platillo:  "<<codigo<<endl;
		cout<<"Nombre de platillo:  "<<nombreNuevo<<endl;
		cout<<"Calorias del platillo:  "<<caloriasNuevo<<endl;
		cout<<"Precio del platillo:  "<<precioNuevo<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<endl;	
		Leer.getline(linea,sizeof(linea));
		Temp<<codigo<<","<<nombreNuevo<<","<<caloriasNuevo<<","<<precioNuevo<<endl;
		}
			else{
	 	
	    Leer.getline(linea,sizeof(linea));
	    Temp<<codigo<<","<<nombre<<","<<calorias<<","<<precio<<endl;
	}
		}
			if(bandera==false){
				cout<<"El registro no existe"<<endl;
			}
		Leer.close();
		Temp.close();
	    remove("platillos.txt");
		rename("Temp.txt","platillos.txt");
		system("pause");
	         break;
	        }
	        case 5:{
	//////////////// ELIMINAR /////////////////////
		int codigo,cod;
		char nombre[10],calorias[10], precio[5];
		bool bandera=false;
		ifstream Leer;
		ofstream Temp;
		int contador=0;
		system("cls");
		Leer.open("platillos.txt");
		Temp.open("Temp.txt");
		cout<<"Ingrese un codigo de platillo a eliminar: "<<endl;
		cin>>cod;
		cin.ignore();
		char linea[120];
		Leer.getline(linea,sizeof(linea));
		while(!Leer.eof()){
			for(int i=0;i<4;i++){
				char *puntero;
				if(i==0){
					puntero=strtok(linea,",");
					codigo=atoi(puntero);
				}else if(i==1){
					puntero=strtok(NULL,",");
					strcpy(nombre,puntero);
				}else if(i==2){
					puntero=strtok(NULL,",");
					strcpy(calorias,puntero);
				}else if(i==3){
					puntero=strtok(NULL,",");
					strcpy(precio,puntero);
				}
			}
		if(cod==codigo){
			bandera=true;	
		cout<<"--------REGISTRO A ELIMINAR--------"<<endl;
		cout<<"Codigo del platillo:  "<<codigo<<endl;
		cout<<"Nombre platillo:  "<<nombre<<endl;
		cout<<"Calorias del platillo:  "<<calorias<<endl;
		cout<<"Precio del platillo:  "<<precio<<endl;
		cout<<"-----------------------------------"<<endl;
		cout<<endl;	
		Leer.getline(linea,sizeof(linea));
		}
			else{
	 	
	    Leer.getline(linea,sizeof(linea));
	    Temp<<codigo<<","<<nombre<<","<<calorias<<","<<precio<<endl;
	}
		}
			if(bandera==false){
				cout<<"El registro no existe"<<endl;
			}
			else {
				int confirmacion;
				cout<<"Esta seguro que desea eliminar el registro"<<endl;
				cout<< "1 para confirmar   "<<endl;
				cout<< "2 para cancelar \n"<<endl;
				switch(confirmacion){
					case 2:{
						Leer.close();
						Temp.close();
						remove("platillos.txt");
					cout<<"El registro  NO fue eliminado \n";	
						system("pause");
						break;
					}
					case 1:{
						Leer.close();
						Temp.close();
					    remove("platillos.txt");
						rename("Temp.txt","platillos.txt");
						cout<<"El registro  eliminado con exito \n";
						system("pause");
						break;
						}
		}
		}		
		} 
		case 6:{
		break;   
		}    
		default :{
		cout<<"Opcion no encontrada "<<endl;
		system("pause");
		break;
        }       
    } 
    
    }while(p!=6);   
	break;		
      } 
	////////////////////////MENU BEBIDAS/////////////////////////////////////////
	case 2:{
	int b;
			 do{
        system("cls");
    cout<<"|-----------REGISTRO BEBIDAS---------|"<<endl;    
    cout<<"| 1. Guardar bebida                  |" <<endl;
    cout<<"| 2. Mostrar todas las bebidas       |" <<endl;
    cout<<"| 3. Buscar  bebidas                 |" <<endl;
    cout<<"| 4. Modificar bebida                |" <<endl;
    cout<<"| 5. Eliminar bebida                 |" <<endl;
    cout<<"| 6. Salir                           |" <<endl;
    cout<<"|------------------------------------|"<<endl;
    cin>>b;
    
    switch(b){
     case 1:{
    //////////// GUARDAR ////////////////////77
    ofstream archivo;
	system("cls");
	archivo.open("bebidas.txt",ios::app);
	int codigo;
	string nombre,calorias, precio;
	cout<<"Ingrese codigo de bebida: "<<endl;
	cin>>codigo;
	cin.ignore();
	cout<<"Ingrese nombre de la bebida : "<<endl;
	getline(cin,nombre);
	cout<<"Ingrese las calorias de bebida: "<<endl;
	getline(cin,calorias);
	cout<<"Ingrese el percio de bebida: "<<endl;
	getline(cin,precio);

	archivo<<codigo<<","<<nombre<<","<<calorias<<","<<precio<<endl;
 	archivo.close();
	system("pause");
    break;
    }   
        case 2:{
    //////////////// MOSTRAR TODOS ////////////////7
    int codigo;
	char nombre[10],calorias[10], precio[10];
	ifstream Leer;
	int contador=0;
	system("cls");
	Leer.open("bebidas.txt");
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(calorias,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(precio,puntero);
			}
		}
	cout<<"----------------------------------"<<endl;
	cout<<"Codigo de bebida:  "<<codigo<<endl;
	cout<<"Nombre del bebida :  "<<nombre<<endl;
	cout<<"caloria de bebida:  "<<calorias<<endl;
	cout<<"precio de bebida:  "<<precio<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	contador++;
	}
	cout<<"El total de registros es "<<contador<<endl;
	Leer.close();
	system("pause");
         break;
        }
        case 3:{
    /////////////////// BUSCAR ///////////////////
    int codigo,cod;
	char nombre[10],calorias[10],precio[10];
	ifstream Leer;
	int contador=0;
	bool bandera=false;
	system("cls");
	Leer.open("bebidas.txt");
	cout<<"Ingrese un codigo de bebida a  buscar"<<endl;
	cin>>cod;
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(calorias,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(precio,puntero);
		}
	}
	if(cod==codigo){
		bandera=true;	
	cout<<"----------------------------------"<<endl;
	cout<<"Codigo de bebida:  "<<codigo<<endl;
	cout<<"Nombre de bebida :  "<<nombre<<endl;
	cout<<"Calorias de bebida:  "<<calorias<<endl;
	cout<<"Precio de bebida:  "<<precio<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	}
		else{
	Leer.getline(linea,sizeof(linea));
}
	}
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
	Leer.close();
	system("pause");
    break;
    }
        case 4:{
    /////////////// MODIFICAR ///////////////777
    int codigo,cod;
	char nombre[10],calorias[10],precio[10];
	string nombre_,calorias_,precio_;
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	int contador=0;
	system("cls");
	Leer.open("bebidas.txt");
	Temp.open("Temp.txt");
	cout<<"Ingrese un codigo de bebida a modificar"<<endl;
	cin>>cod;
	cin.ignore();
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(calorias,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(precio,puntero);
			}
		}
	if(cod==codigo){
		bandera=true;	
	cout<<"---------REGISTRO ACTUAL----------"<<endl;
	cout<<"Codigo de bebida: "<<codigo<<endl;
	cout<<"Nombre de bebida : "<<nombre<<endl;
	cout<<"Calorias de bebida: "<<calorias<<endl;
	cout<<"Precio de bebida: "<<precio<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<endl;	
	cout<<"Ingrese nuevo nombre de bebida : "<<endl;
	getline(cin,nombre_);
	cout<<"Ingrese nueva calorias de bebida: "<<endl;
	getline(cin,calorias_);
	cout<<"Ingrese nuevo precio de bebida: "<<endl;
	getline(cin,precio_);
	cout<<endl;	

	cout<<"-----------NUEVO REGISTRO--------"<<endl;
	cout<<"Codigo de bebida: "<<codigo<<endl;
	cout<<"Nombre de bebida : "<<nombre_<<endl;
	cout<<"Calorias de bebida: "<<calorias_<<endl;
	cout<<"Precio  de bebida: "<<precio_<<endl;
	cout<<"---------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	Temp<<codigo<<","<<nombre_<<","<<calorias_<<","<<precio_<<endl;
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<codigo<<","<<nombre<<","<<calorias<<","<<precio<<endl;
}
	}
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
	Leer.close();
	Temp.close();
    remove("bebidas.txt");
	rename("Temp.txt","bebidas.txt");
	system("pause");
         break;
        }
        case 5:{
    /////////////// ELIMINAR ////////////7
    int codigo,cod;
	char nombre[10],calorias[10], precio[5];
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	int contador=0;
	system("cls");
	Leer.open("bebidas.txt");
	Temp.open("Temp.txt");
	cout<<"Ingrese un codigo de bebida a eliminar: "<<endl;
	cin>>cod;
	cin.ignore();
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(calorias,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(precio,puntero);
			}
		}
	if(cod==codigo){
		bandera=true;	
	cout<<"------REGISTRO A ELIMINAR---------"<<endl;
	cout<<"Codigo de bebida: "<<codigo<<endl;
	cout<<"Nombre de bebida : "<<nombre<<endl;
	cout<<"Calorias de bebida: "<<calorias<<endl;
	cout<<"Precio de bebida: "<<precio<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<codigo<<","<<nombre<<","<<calorias<<","<<precio<<endl;
}
	}
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
		else{
			int confirmacion;
			cout<<"Esta seguro que desea eliminar el registro?"<<endl;
			cout<<"1 para confirmar   "<<endl;
			cout<<"2 para cancelar\n"<<endl;
			cin>>confirmacion;
			switch(confirmacion){
				case 2:{
	Leer.close();
	Temp.close();
    remove("Temp.txt");
	cout<<"El registro NO fue eliminado\n";
		system("pause");
					break;
				}
				case 1:{
					Leer.close();
	Temp.close();
    remove("bebidas.txt");
	rename("Temp.txt","bebidas.txt");
	cout<<"Registro eliminado con exito\n";
	system("pause");
	
					break;
				}
			}
		}
		}
        case 6:{
         break;   
        }    
        default :{
            cout<<"Opcion no encontrada "<<endl;
            system("pause");
            break;
           }       
    } 
    }while(b!=6);   
	break;
	}
	/////////////////////MENU POSTRES//////////////////////////////
			case 3:{
				int t;
    do{
        system("cls");
    cout<<"|-----------MENU POSTRES-------------|"<<endl;   
    cout<<"| 1. Guardar postre                  |" <<endl;
    cout<<"| 2. Mostrar todos los postres       |" <<endl;
    cout<<"| 3. Buscar postre                   |" <<endl;
    cout<<"| 4. Modificar postre                |" <<endl;
    cout<<"| 5. Eliminar postre                 |" <<endl;
    cout<<"| 6. Salir                           |" <<endl;
    cout<<"|------------------------------------|"<<endl;
    cin>>t;
    
    switch(t){
     case 1:{
    ///////////// GUARDAR ///////////////
    ofstream archivo;
	system("cls");
		archivo.open("postres.txt",ios::app);
		int codigo;
	string nombre,calorias, precio;
	cout<<"Ingrese codigo del postre: "<<endl;
	cin>>codigo;
		cin.ignore();
	cout<<"Ingrese nombre del postre : "<<endl;
	getline(cin,nombre);
	cout<<"Ingrese las calorias del postre: "<<endl;
	getline(cin,calorias);
	cout<<"Ingrese el precio del postre: "<<endl;
	getline(cin,precio);

	archivo<<codigo<<","<<nombre<<","<<calorias<<","<<precio<<endl;
 archivo.close();
	system("pause");
         break;
        }   
        case 2:{
    //////////// MOSTRAR /////////////////
    int codigo;
	char nombre[10],calorias[10], precio[10];
	ifstream Leer;
	int contador=0;
	system("cls");
	Leer.open("postres.txt");
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(calorias,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(precio,puntero);
			}
		}
	cout<<"-------------------------------"<<endl;
	cout<<"Codigo del postre: "<<codigo<<endl;
	cout<<"Noombre del postre : "<<nombre<<endl;
	cout<<"caloria del postre: "<<calorias<<endl;
	cout<<"precio del postre: "<<precio<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	contador++;
	}
		cout<<"El total de registros es "<<contador<<endl;
	Leer.close();
	system("pause");
         break;
        }
        case 3:{
    ///////////7 BUSCAR ///////////////
    int codigo,cod;
	char nombre[10],calorias[10],precio[10];
	bool bandera=false;
	ifstream Leer;
	int contador=0;
	system("cls");
	Leer.open("postres.txt");
	cout<<"Ingrese un codigo de postre a buscar"<<endl;
	cin>>cod;
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(calorias,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(precio,puntero);
		}
	}
	if(cod==codigo){
		bandera=true;	
	cout<<"-----------------------------"<<endl;
	cout<<"Codigo del postre: "<<codigo<<endl;
	cout<<"Nombre del postre : "<<nombre<<endl;
	cout<<"Calorias del postre: "<<calorias<<endl;
	cout<<"Precio del postre: "<<precio<<endl;
	cout<<"-----------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	}
		else{
	Leer.getline(linea,sizeof(linea));
}
	}
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
	Leer.close();
	system("pause");
         break;
        }
        case 4:{
    /////////// MODIFICAR ///////////////
    int codigo,cod;
	char nombre[10],calorias[10],precio[10];
	string nombre_,calorias_,precio_;
	ifstream Leer;
	ofstream Temp;
	bool bandera=false;
	int contador=0;
	system("cls");
	Leer.open("postres.txt");
	Temp.open("Temp.txt");
	cout<<"Ingrese un codigo de postre a modificar"<<endl;
	cin>>cod;
	cin.ignore();
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(calorias,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(precio,puntero);
			}
		}
	if(cod==codigo){
		bandera=true;	
	cout<<"----------REGISTRO ACTUAL---------"<<endl;
	cout<<"Codigo del postre: "<<codigo<<endl;
	cout<<"Nombre del postre : "<<nombre<<endl;
	cout<<"Calorias del postre: "<<calorias<<endl;
	cout<<"Precio del postre: "<<precio<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<endl;	
	
	cout<<"Ingrese nuevo nombre del postre: "<<endl;
	getline(cin,nombre_);
	cout<<"Ingrese nueva calorias del postre: "<<endl;
	getline(cin,calorias_);
	cout<<"Ingrese nuevo precio del postre: "<<endl;
	getline(cin,precio_);
	cout<<endl;	

	cout<<"---------NUEVO REGISTRO-----------"<<endl;
	cout<<"Codigo del postre: "<<codigo<<endl;
	cout<<"Nombre del postre : "<<nombre_<<endl;
	cout<<"Calorias del postre: "<<calorias_<<endl;
	cout<<"Precio del postre: "<<precio_<<endl;
	cout<<"-----------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	Temp<<codigo<<","<<nombre_<<","<<calorias_<<","<<precio_<<endl;
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<codigo<<","<<nombre<<","<<calorias<<","<<precio<<endl;
}
	}
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
	Leer.close();
	Temp.close();
    remove("postres.txt");
	rename("Temp.txt","postres.txt");
	system("pause");
         break;
        }
        case 5:{
    ////////// ELIMINAR ///////////////
    int codigo,cod;
	char nombre[10],calorias[10], precio[5];
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	int contador=0;
	system("cls");
	Leer.open("postres.txt");
	Temp.open("Temp.txt");
	cout<<"Ingrese un codigo de postre a eliminar: "<<endl;
	cin>>cod;
	cin.ignore();
	char linea[120];
	Leer.getline(linea,sizeof(linea));
	while(!Leer.eof()){
		for(int i=0;i<4;i++){
			char *puntero;
			if(i==0){
				puntero=strtok(linea,",");
				codigo=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(nombre,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(calorias,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(precio,puntero);
			}
		}
	if(cod==codigo){
		bandera=true;	
	cout<<"-------REGISTRO  A ELIMINAR------"<<endl;
	cout<<"Codigo del postre: "<<codigo<<endl;
	cout<<"Nombre del postre : "<<nombre<<endl;
	cout<<"Calorias del postre: "<<calorias<<endl;
	cout<<"Precio del postre: "<<precio<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<codigo<<","<<nombre<<","<<calorias<<","<<precio<<endl;
}
	}
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
		else {
			int confirmacion;
			cout<<"Esta seguro que desea eliminar el registro?"<<endl;
	cout<<"1 para confirmar  "<<endl;
	cout<<"2 para cancelar\n"<<endl;
	cin>>confirmacion;
	switch(confirmacion){
		case 2:{
			Leer.close();
	Temp.close();
    remove("Temp.txt");
	cout<<"El registro NO fue eliminado\n";
	system("pause");
			break;
		}
		case 1:{
			Leer.close();
	Temp.close();
    remove("postres.txt");
	rename("Temp.txt","postres.txt");
	cout<<"Registro eliminado con exito\n";
	system("pause");
			break;
		}
	}
		}
	}
        case 6:{
         break;   
        }    
        default :{
            cout<<"Opcion no encontrada "<<endl;
            system("pause");
            break;
           }       
    } 
    }while(t!=6);   
	break;
	}
	case 4:{
		break;
	}
	default :{
            cout<<"Opcion no encontrada "<<endl;
            system("pause");
            break;
    } 
}
}
while(opc !=4);
	system("pause");	
}


