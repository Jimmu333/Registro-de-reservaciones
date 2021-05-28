#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
using namespace std;

// ++++++++++++MESAS+++++++++++++++ 

void guardarMesa(),mostrarMesa(),buscarMesa(),modificarMesa(),eliminarMesa(),ver();
char var[30];   
main (){
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
		
