#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
using namespace std;

// ++++++++++++RESERVACIONES+++++++++++++++ 

class fecha{
public:
 int dia;
 int mes; 
 int anio;   
} ;   

void guardarReservacion(),mostrarReservacion(),reservacionFecha(),reservacionCliente(),modificarReservacion(),eliminarReservacion(),ver();
char var[30];   
main (){
    int opc;
    do{
        system("cls");
    cout<<"--------REGISTRO DE RESERVACIONES---------"<<endl;    
    cout<<"1. Guardar nueva reservacion" <<endl;
    cout<<"2. Mostrar todas las reservaciones" <<endl;
    cout<<"3. Buscar reservacion por fecha" <<endl;
    cout<<"4. Buscar reservacion por cliente" <<endl;
    cout<<"5. Modificar reservacion" <<endl;
    cout<<"6. Eliminar reservacion" <<endl;
    cout<<"7. Salir" <<endl;
    
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
    }while(opc!=6);   
}
//------------------GUARDAR-----------------
void guardarReservacion(){
	ofstream archivo;
	system("cls");
	archivo.open("Reservaciones.txt",ios::app);
	int codigoReservacion,numeroMesa,codigoClienteReservacion;
	fecha fechaReservacion;
	
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
 numeroMesa=atoi(var);
 if(strcmp(var,"0")==0){
  numeroMesa=0;
 
  break; 
 }   }while(numeroMesa==0);
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
    
	cout<<"Ingres el dia de la reservacion: "<<endl;
	
	    do{
 cin>>var;
 cout<<"                   "<<endl;
 fechaReservacion.dia=atoi(var);
 if(strcmp(var,"0")==0){
  fechaReservacion.dia=0;
 
  break; 
 }   }while(fechaReservacion.dia==0);
 
 	cout<<"Ingres el mes de la reservacion: "<<endl;
	
	    do{
 cin>>var;
 cout<<"                   "<<endl;
 fechaReservacion.mes=atoi(var);
 if(strcmp(var,"0")==0){
  fechaReservacion.mes=0;
 
  break; 
 }   }while(fechaReservacion.mes==0);
	
		cout<<"Ingres el anio de la reservacion: "<<endl;
	
	    do{
 cin>>var;
 cout<<"                   "<<endl;
 fechaReservacion.anio=atoi(var);
 if(strcmp(var,"0")==0){
  fechaReservacion.anio=0;
 
  break; 
 }   }while(fechaReservacion.anio==0);
	
	archivo<<codigoReservacion<<","<<numeroMesa<<","<<codigoClienteReservacion<<","<<fechaReservacion.dia<<","<<fechaReservacion.mes<<","<<fechaReservacion.anio<<endl;
    archivo.close();
	system("pause");
}
//--------------MOSTRAR TODOS------------
void mostrarReservacion(){
	int numero;
	char sillas[30],ubicacion[30];
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
				numero=atoi(puntero);
			}else if(i==1){
				puntero=strtok(NULL,",");
				strcpy(sillas,puntero);
			}else if(i==2){
				puntero=strtok(NULL,",");
				strcpy(ubicacion,puntero);
			}else if(i==3){
				puntero=strtok(NULL,",");
				strcpy(ubicacion,puntero);
			}else if(i==4){
				puntero=strtok(NULL,",");
				strcpy(ubicacion,puntero);
			}// awqui
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

//--------------BUSCAR POR FECHA------------
void reservacionFecha(){
	int numero,cod;
	char sillas[20],ubicacion[30];
	ifstream Leer;
	int contador=0;
	bool bandera=false;
	system("cls");
	Leer.open("Reservaciones.txt");
	cout<<"Ingrese el codigo a buscar"<<endl;
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
//----------BUSCAR POR CLIENTE-------------

void reservacionCliente(){

}

//--------------MODIFICAR----------------
void modificarCliente(){
	int numero,cod;
	char ubicacion[30],sillas[30];
	
	
	string ubicacionNuevo, sillasNuevo;
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	int contador=0;
	system("cls");
	Leer.open("Reservaciones.txt");
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
	cout<<"----------REGISTRO ANTERIOR-----------"<<endl;
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

	cout<<"------------NEVO REGISTRO-----------"<<endl;
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
    remove("Reservaciones.txt");
	rename("Temp.txt","Reservaciones.txt");
	system("pause");
}

//--------------ELIMINAR-----------------
void eliminarCliente(){
 	int numero,cod;
	char sillas[30],ubicacion[30];
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	int contador=0;
	system("cls");
	Leer.open("Reservaciones.txt");
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
	cout<<"---------REGISTRO ELIMINADO-----------"<<endl;
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
	Leer.close();
	Temp.close();
    remove("Reservaciones.txt");
	rename("Temp.txt","Reservaciones.txt");
	system("pause");   
}
