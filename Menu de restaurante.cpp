#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
using namespace std;
struct registro{
   int codigo;
   int nombre;
   int calorias;
   int precio;
};   

main(){
	system("color A");
		int opc;
		int p;
		int b; 
		int t;
		do{
		cout<<" Menu "<<endl;
		cout<<"1.PLATILLOS"<<endl;
		cout<<"2.BEBIDAS"<<endl;
		cout<<"3.POSTRES"<<endl;
		cout<<"4. SALIR"<<endl;
		cin>>opc;
		switch(opc){
///////////////////////////////PLATILLOS///////////////////////////////
			case 1:{
				int p;
				 do{
        system("cls");
    cout<<"------PLATILLOS-------"<<endl;    
    cout<<"1. Guardar" <<endl;
    cout<<"2. Mostrar todos" <<endl;
    cout<<"3. Buscar" <<endl;
    cout<<"4. Modificar" <<endl;
    cout<<"5. Eliminar" <<endl;
    cout<<"6. Salir" <<endl;
    cin>>p;
    system("cls");
    
    switch(p){

     case 1:{
     	/////////// GUARDAR ///////////////////7
	        ofstream archivo;
		    system("cls");
			archivo.open("platillos.txt",ios::app);
			int codigo;
		string nombre,calorias, precio;
		cout<<"Ingrese codigo: "<<endl;
		cin>>codigo;
			cin.ignore();
		cout<<"Ingrese nombre de platillo : "<<endl;
		getline(cin,nombre);
		cout<<"Ingrese la caloria del platillo: "<<endl;
		getline(cin,calorias);
		cout<<"Ingrese el precio del platillo : "<<endl;
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
		cout<<"------------DATOS--------------------"<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"Codigo: "<<codigo<<endl;
		cout<<"Noombre del platillo : "<<nombre<<endl;
		cout<<"caloria: "<<calorias<<endl;
		cout<<"precio: "<<precio<<endl;
		cout<<"-------------------------------------"<<endl;
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
	bool bandera=false;
	ifstream Leer;
	int contador=0;
	system("cls");
	Leer.open("platillos.txt");
	cout<<"Ingrese un codigo a buscar"<<endl;
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
		cout<<"--------------DATOS---------------"<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<"Codigo: "<<codigo<<endl;
		cout<<"Nombre de platillo : "<<nombre<<endl;
		cout<<"Calorias: "<<calorias<<endl;
		cout<<"Precio: "<<precio<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<"----------------------------------"<<endl;
		cout<<endl;	
		Leer.getline(linea,sizeof(linea));
		}
			else{
		Leer.getline(linea,sizeof(linea));
	}
		}
			if(bandera==false){
				cout<<"EL REGISTRO NO EXISTE"<<endl;
			}
		Leer.close();
		system("pause");
	         break;
	        }
	        case 4:{
	///////////// MODIFICAR ///////////////////7
		           int codigo,cod;
		char nombre[10],calorias[10],precio[10];
		string nombre_,calorias_,precio_;
		bool bandera=false;
		ifstream Leer;
		ofstream Temp;
		int contador=0;
		system("cls");
		Leer.open("platillos.txt");
		Temp.open("Temp.txt");
		cout<<"Ingrese un codigo a modificar"<<endl;
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
		cout<<"--------REGISTRO ACTUAL---------"<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<"Codigo: "<<codigo<<endl;
		cout<<"Nombre de platillo : "<<nombre<<endl;
		cout<<"Calorias: "<<calorias<<endl;
		cout<<"Precio: "<<precio<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<endl;	
		
		cout<<"Ingrese nuevo nombre de platillo: "<<endl;
		getline(cin,nombre_);
		cout<<"Ingrese nueva calorias: "<<endl;
		getline(cin,calorias_);
		cout<<"Ingrese nuevo precio: "<<endl;
		getline(cin,precio_);
		Leer.getline(linea,sizeof(linea));
		Temp<<codigo<<","<<nombre_<<","<<calorias_<<","<<precio_<<endl;
	
		cout<<"---------NUEVO REGISTRO---------"<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<"Codigo: "<<codigo<<endl;
		cout<<"Nombre de platillo : "<<nombre_<<endl;
		cout<<"Calorias: "<<calorias_<<endl;
		cout<<"Precio: "<<precio_<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<endl;	
		Leer.getline(linea,sizeof(linea));
		}
			else{
	 	
	    Leer.getline(linea,sizeof(linea));
	    Temp<<codigo<<","<<nombre<<","<<calorias<<","<<precio<<endl;
	}
		}
			if(bandera==false){
				cout<<"EL REGISTRO NO EXISTE"<<endl;
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
		cout<<"Ingrese un codigo a eliminar: "<<endl;
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
		cout<<"-------REGISTRO ELIMINADO--------"<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<"Codigo: "<<codigo<<endl;
		cout<<"Nombre platillo : "<<nombre<<endl;
		cout<<"Calorias : "<<calorias<<endl;
		cout<<"Precio : "<<precio<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<"---------------------------------"<<endl;
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
		Leer.close();
		Temp.close();
	    remove("platillos.txt");
		rename("Temp.txt","platillos.txt");
		system("pause");
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
    }while(p!=6);   		
    } 
	///////////////////////MENU BEBIDAS/////////////////////////////////////////
			case 2:{
			int b;
			 do{
        system("cls");
    cout<<"------BEBIDAS-------"<<endl;    
    cout<<"1. Guardar" <<endl;
    cout<<"2. Mostrar todos" <<endl;
    cout<<"3. Buscar" <<endl;
    cout<<"4. Modificar" <<endl;
    cout<<"5. Eliminar" <<endl;
    cout<<"6. Salir" <<endl;
    cin>>b;
    system("cls");
    
    switch(b){
     case 1:{
    //////////// GUARDAR ////////////////////77
    	ofstream archivo;
	system("cls");
		archivo.open("bebidas.txt",ios::app);
		int codigo;
	string nombre,calorias, precio;
	cout<<"Ingrese codigo: "<<endl;
	cin>>codigo;
		cin.ignore();
	cout<<"Ingrese nombre de bebida : "<<endl;
	getline(cin,nombre);
	cout<<"Ingrese la caloria de la bebida: "<<endl;
	getline(cin,calorias);
	cout<<"Ingrese el precio de la bebida : "<<endl;
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
	cout<<"------------DATOS--------------------"<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Noombre del bebida : "<<nombre<<endl;
	cout<<"caloria: "<<calorias<<endl;
	cout<<"precio: "<<precio<<endl;
	cout<<"-------------------------------------"<<endl;
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
    /////////////////// BUSCAR ///////////////////
    int codigo,cod;
	char nombre[10],calorias[10],precio[10];
	bool bandera=false;
	ifstream Leer;
	int contador=0;
	system("cls");
	Leer.open("bebidas.txt");
	cout<<"Ingrese un codigo a buscar"<<endl;
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
	cout<<"--------------DATOS---------------"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre de bebida : "<<nombre<<endl;
	cout<<"Calorias: "<<calorias<<endl;
	cout<<"Precio: "<<precio<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	}
		else{
	Leer.getline(linea,sizeof(linea));
}
	}
		if(bandera==false){
			cout<<"EL REGISTRO NO EXISTE"<<endl;
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
	cout<<"Ingrese un codigo a modificar"<<endl;
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
	cout<<"--------REGISTRO ACTUAL---------"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre de bebida : "<<nombre<<endl;
	cout<<"Calorias: "<<calorias<<endl;
	cout<<"Precio: "<<precio<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<endl;	
	
	cout<<"Ingrese nuevo nombre de bebida : "<<endl;
	getline(cin,nombre_);
	cout<<"Ingrese nueva calorias: "<<endl;
	getline(cin,calorias_);
	cout<<"Ingrese nuevo precio: "<<endl;
	getline(cin,precio_);
	Leer.getline(linea,sizeof(linea));
	Temp<<codigo<<","<<nombre_<<","<<calorias_<<","<<precio_<<endl;

	cout<<"---------NUEVO REGISTRO---------"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre de bebida : "<<nombre_<<endl;
	cout<<"Calorias: "<<calorias_<<endl;
	cout<<"Precio: "<<precio_<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<codigo<<","<<nombre<<","<<calorias<<","<<precio<<endl;
}
	}
		if(bandera==false){
			cout<<"EL REGISTRO NO EXISTE"<<endl;
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
	cout<<"Ingrese un codigo a eliminar: "<<endl;
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
	cout<<"-------REGISTRO ELIMINADO--------"<<endl;
	cout<<"---------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre de bebida: "<<nombre<<endl;
	cout<<"Calorias : "<<calorias<<endl;
	cout<<"Precio : "<<precio<<endl;
	cout<<"---------------------------------"<<endl;
	cout<<"---------------------------------"<<endl;
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
	Leer.close();
	Temp.close();
    remove("bebidas.txt");
	rename("Temp.txt","bebidas.txt");
	system("pause");
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
    }while(b!=6);   
	break;
	}
	/////////////////////MENU POSTRES//////////////////////////////
			case 3:{
				int t;
    do{
        system("cls");
    cout<<"------POSTRES-------"<<endl;    
    cout<<"1. Guardar" <<endl;
   	cout<<"2. Mostrar todos" <<endl;
    cout<<"3. Buscar" <<endl;
    cout<<"4. Modificar" <<endl;
    cout<<"5. Eliminar" <<endl;
    cout<<"6. Salir" <<endl;
    cin>>t;
    system("cls");
    
    switch(t){
     case 1:{
    ///////////// GUARDAR ///////////////
    ofstream archivo;
	system("cls");
		archivo.open("postres.txt",ios::app);
		int codigo;
	string nombre,calorias, precio;
	cout<<"Ingrese codigo: "<<endl;
	cin>>codigo;
		cin.ignore();
	cout<<"Ingrese nombre del postre : "<<endl;
	getline(cin,nombre);
	cout<<"Ingrese la caloria del postre: "<<endl;
	getline(cin,calorias);
	cout<<"Ingrese el precio delpostre : "<<endl;
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
	cout<<"------------DATOS--------------------"<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Noombre del postre: "<<nombre<<endl;
	cout<<"caloria: "<<calorias<<endl;
	cout<<"precio: "<<precio<<endl;
	cout<<"-------------------------------------"<<endl;
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
    ///////////7 BUSCAR ///////////////
    int codigo,cod;
	char nombre[10],calorias[10],precio[10];
	bool bandera=false;
	ifstream Leer;
	int contador=0;
	system("cls");
	Leer.open("postres.txt");
	cout<<"Ingrese un codigo a buscar"<<endl;
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
	cout<<"--------------DATOS---------------"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre del postre : "<<nombre<<endl;
	cout<<"Calorias: "<<calorias<<endl;
	cout<<"Precio: "<<precio<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	}
		else{
	Leer.getline(linea,sizeof(linea));
}
	}
		if(bandera==false){
			cout<<"EL REGISTRO NO EXISTE"<<endl;
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
	bool bandera=false;
	ifstream Leer;
	ofstream Temp;
	int contador=0;
	system("cls");
	Leer.open("postres.txt");
	Temp.open("Temp.txt");
	cout<<"Ingrese un codigo a modificar"<<endl;
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
	cout<<"--------REGISTRO ACTUAL---------"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre del postre : "<<nombre<<endl;
	cout<<"Calorias: "<<calorias<<endl;
	cout<<"Precio: "<<precio<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<endl;	
	
	cout<<"Ingrese nuevo nombre del postre: "<<endl;
	getline(cin,nombre_);
	cout<<"Ingrese nueva calorias: "<<endl;
	getline(cin,calorias_);
	cout<<"Ingrese nuevo precio: "<<endl;
	getline(cin,precio_);
	Leer.getline(linea,sizeof(linea));
	Temp<<codigo<<","<<nombre_<<","<<calorias_<<","<<precio_<<endl;

	cout<<"---------NUEVO REGISTRO---------"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre del postre : "<<nombre_<<endl;
	cout<<"Calorias: "<<calorias_<<endl;
	cout<<"Precio: "<<precio_<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<endl;	
	Leer.getline(linea,sizeof(linea));
	}
		else{
 	
    Leer.getline(linea,sizeof(linea));
    Temp<<codigo<<","<<nombre<<","<<calorias<<","<<precio<<endl;
}
	}
		if(bandera==false){
			cout<<"EL REGISTRO NO EXISTE"<<endl;
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
	cout<<"Ingrese un codigo a eliminar: "<<endl;
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
	cout<<"-------REGISTRO ELIMINADO--------"<<endl;
	cout<<"---------------------------------"<<endl;
	cout<<"Codigo: "<<codigo<<endl;
	cout<<"Nombre del postre : "<<nombre<<endl;
	cout<<"Calorias : "<<calorias<<endl;
	cout<<"Precio : "<<precio<<endl;
	cout<<"---------------------------------"<<endl;
	cout<<"---------------------------------"<<endl;
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
	Leer.close();
	Temp.close();
    remove("postres.txt");
	rename("Temp.txt","postres.txt");
	system("pause");
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
    }while(t!=6);   
	break;
	}
	case 4:{
		break;
	}
	default:{
	break;
	}
}

}
while(opc !=4);
	system("pause");	
}

	

