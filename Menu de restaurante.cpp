#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
using namespace std;

int main(){
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
    cout<<"|------------------------------------|"endl;
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


