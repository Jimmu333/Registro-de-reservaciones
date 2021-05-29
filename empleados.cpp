#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
 
 
using namespace std;

 
 void guardar(),mostrar(),buscar(),modificar(),eliminar(),ver();

int main () 
{
	int opc;
	do{
	system("cls");
    cout<<"\n\t\t\t\t\t| ----Empleados---- |";    
    cout<<"\n\t\t\t\t\t| 1. Guardar nuevo  |";
    cout<<"\n\t\t\t\t\t| 2. Mostrar todos  |";
    cout<<"\n\t\t\t\t\t| 3. Buscar         |";
    cout<<"\n\t\t\t\t\t| 4. Modificar      |";
    cout<<"\n\t\t\t\t\t| 5. Eliminar       |";
    cout<<"\n\t\t\t\t\t| 6. Salir          |";
    cout<<"\n\t\t\t\t\t| ----------------- |";
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
         exit(0);   
        }       
        default :{
            cout<<"\n \t\t\tOpcion no encontrada"<<endl;
            system("pause");
            
            break;
           }    
    }
		

	}while(opc!=6);
    
    
    return 0;
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
	cout<<"Codigo: "<<codigo2<<endl;
	cout<<"Nombre: " <<nombre2<<endl;
	cout<<"Edad: " <<edad2 <<endl;
	cout<<"Telefono: "<<telefono2<<endl;
	cout<<"Direccion: "<<direccion2 <<endl;
	cout<<"Fecha de contratacion: "<<fechaContratacion2 <<endl;
	cout<<"Puesto: "<<puesto2 <<endl;
	cout<<"Salario: " <<salario2 <<endl;
	cout<<"--------------------------------"<<endl;
	
	Leer.getline(linea,sizeof(linea));
	Temp<<codigo2<<", "<<nombre2<<", "<<edad2<<", "<<telefono2<<", "<<direccion2<<", "<<fechaContratacion2<<", "<<puesto2<<", "<<salario2<<endl;
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
			cout<<"Esta seguro que desea eliminar el registro?";
	cout<<"\n\t\t\t1 para confirmar";
	cout<<"\t\t\t0 para cancelar\n";
	cin>>confirmacion;
				
			switch(confirmacion){
							case 0:{
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
						cout<<"\t\t\t\t¡¡¡Respuesta invalida!!!";

				break;
			}
			}

		}
		
			system("pause");


}
