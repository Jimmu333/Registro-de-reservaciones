#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
using namespace std;
int codigo;
string nombre,calorias,precio;
int  main(){
	system("color A");
		int opc,p,b;
		do{
		cout<<" Menu "<<endl;
		cout<<"1.PLATILLOS"<<endl;
		cout<<"2.BEBIDAS"<<endl;
		cout<<"3.POSTRES"<<endl;
		cout<<"4. SALIR"<<endl;
		cin>>opc;
		switch(opc){
			case 1:{
				do{
				system("cls");
				cout<<"LOS PLATILLOS SON :"<<endl;
				int p;
				system("cls");
					cout<<"1.GUARDAR NUEVOS PLATILLOS "<<endl;
					cout<<"2.MOSTRAR MENU DE PLATILLOS "<<endl;
					cout<<"3.EDITAR PLATILLOS "<<endl;
					cout<<"4.ELIMINAR PLATILLOS"<<endl;
					cout<<"5.SALIR"<<endl;
					cin>>p;
	//////////////////////////////MENU PLATILLOS///////////////////////////////////////////
				switch(p){
					case 1:{
					
						break;
					}
					case 2:{
					
						break;
					}
					case 3:{
						
						break;
					} 
					case 4:{
						
						break;
					}
					case 5:{
						return opc;
        			}  
				}
				
			}
			while(p !=5);
			system ("pause");	
			return opc;
			
			}
	///////////////////////MENU BEBIDAS/////////////////////////////////////////
			case 2:{
				
				switch(b){
					case 1:{
						
						break;
					}
					case 2:{
						
						break;
					}
					case 3:{
					
						break;
					} 
					case 4:{
						
						break;
					}
					case 5:{
						break; 
        			}   
				}
			
				break;
			}
	/////////////////////MENU POSTRES//////////////////////////////7
			case 3:{
				
				break;
			}
			default:
				break;
				
		}
	
}
while(opc !=4);
	system("pause");
			
}	

