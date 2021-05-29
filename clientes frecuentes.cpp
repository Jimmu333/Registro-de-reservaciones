#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

void clienteFrecuente(), ver();

char var[30];   
main (){
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
	
	
	
