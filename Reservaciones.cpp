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
    cout<<"|--------REGISTRO DE RESERVACIONES---------|"<<endl;    
    cout<<"| 1. Guardar nueva reservacion             |" <<endl;
    cout<<"| 2. Mostrar todas las reservaciones       |" <<endl;
    cout<<"| 3. Buscar reservacion por fecha          |" <<endl;
    cout<<"| 4. Buscar reservacion por cliente        |" <<endl;
    cout<<"| 5. Modificar reservacion                 |" <<endl;
    cout<<"| 6. Eliminar reservacion                  |" <<endl;
    cout<<"| 7. Salir                                 |" <<endl;
    cout<<"|------------------------------------------|r" <<endl;
    
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
	int codigoReservacion,codigoClienteReservacion,numeroMesaReservacion;
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
	system("pause");
}
//--------------MOSTRAR TODOS------------
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
	cout<<"Numero de mesa de la reservacion: "<<numeroMesaReservacion<<endl;
	cout<<"Codigo del cliente: "<<codigoClienteReservacion<<endl;
	cout<<"Fecha de la reservacion: "<<fechaReservacion<<endl;
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
	cout<<"Ingrese la fecha que desea que desea desplegar: "<<endl;
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
	cout<<"Codigo de la reservacion: "<<codigoReservacion<<endl;
	cout<<"Numero de mesa de la reservacion: "<<numeroMesaReservacion<<endl;
	cout<<"Codigo del cliente: "<<codigoClienteReservacion<<endl;
	cout<<"Fecha de la reservacion: "<<fechaReservacion<<endl;
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
	cout<<"Codigo de la reservacion: "<<codigoReservacion<<endl;
	cout<<"Numero de mesa de la reservacion: "<<numeroMesaReservacion<<endl;
	cout<<"Codigo del cliente: "<<codigoClienteReservacion<<endl;
	cout<<"Fecha de la reservacion: "<<fechaReservacion<<endl;
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
		}}
		
	if(cod==codigoReservacion){
		bandera=true;	
	cout<<"------------REGISTRO ACTUAL------------"<<endl;
    cout<<"Codigo de la reservacion: "<<codigoReservacion<<endl;
	cout<<"Numero de mesa de la reservacion: "<<numeroMesaReservacion<<endl;
	cout<<"Codigo del cliente: "<<codigoClienteReservacion<<endl;
	cout<<"Fecha de la reservacion: "<<fechaReservacion<<endl;
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
	cout<<"Numero de mesa de la reservacion: "<<numeroMesaReservacionNuevo<<endl;
	cout<<"Codigo del cliente: "<<codigoClienteReservacionNuevo<<endl;
	cout<<"Fecha de la reservacion: "<<fechaReservacionNuevo<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	Temp<<codigoReservacion<<","<<numeroMesaReservacionNuevo<<","<<codigoClienteReservacionNuevo<<","<<fechaReservacionNuevo<<endl;
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<codigoReservacion<<","<<numeroMesaReservacion<<","<<codigoClienteReservacion<<","<<fechaReservacion<<endl;
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
		}}
	if(cod==codigoReservacion){
		bandera=true;	
	cout<<"---------REGISTRO A ELIMINAR----------"<<endl;
    cout<<"Codigo de la reservacion: "<<codigoReservacion<<endl;
	cout<<"Numero de mesa de la reservacion: "<<numeroMesaReservacion<<endl;
	cout<<"Codigo del cliente: "<<codigoClienteReservacion<<endl;
	cout<<"Fecha de la reservacion: "<<fechaReservacion<<endl;
	cout<<"---------------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<codigoReservacion<<","<<numeroMesaReservacion<<","<<codigoClienteReservacion<<","<<fechaReservacion<<endl;
}
	
		if(bandera==false){
			cout<<"El registro no existe"<<endl;
		}
		
		else{
			int confirmacion;
			cout<<"¿Esta seguro que desea eliminar el registro?"<<endl;
	cout<<"1 para confirmar";
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
		
