#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
using namespace std;
    
struct registro{
   int codigo;
   char cliente[40];
   int telefono;
   char direccion[40];
}; 

void guardarCliente(),mostrarCliente(),buscarCliente(),modificarCliente(),eliminarCliente(),ver();
char var[30];   
registro reg1[3];
main (){
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
	archivo<<codigo<<","<<cliente<<","<<telefono<<","<<direccion<<endl;
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
