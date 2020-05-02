/*
HOJA DE TRABAJO #4

EJERCICIO#1
El programa debe ser capaz de:

- Modificar el número de unidades vendidas, solicitando al usuario el día y código de articulo
    (modificación del archivo)
- Eliminación de un día especifico de venta (modificación del archivo)
-Calcular el total recaudado por modelo en los 30 días.
-Calcular cuál fue el modelo que se vendió mas en los 30 días 

*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <regex>

using namespace std;

void insert_data_db();
void mp();
void eliminar();
void modificar();

int main(){	
			
}
void mp(){
	int resp;

	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Librería "<<"\n";
		cout<<" 2 - Reporte "<<"\n";
		cout<<" 3 - Eliminar Registro"<<"\n";
		cout<<" 4 - Modificar Registro"<<"\n";
		cout<<" 5 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			insert_data_db();			
		}
		else if (resp==2){		
			system("CLS");
			leer_data_db();
		}
		else if (resp==3){		
			system("CLS");
			eliminar();	
		}			
		else if (resp==4){
			system("CLS");
			modificar();
		}
		else if (resp==5)
			break;
		else 
			break;
		
	} while(resp!=5);	
}

void insert_data_db(){

    char modelo; 
	int cantidad ;     
	int dia; 
	
	//variables de apoyo 
	string s;    
	int lineas;
	char lmodelo;
	float cantidad;
	float dia;
	int precio;
	float 1precio=10.00;
	float 2precio=15.00;
	float 3precio=18.50;
	float 4precio=25.00;
	
	//Ingreso de datos
	cout<<"Ingrese que tipo de cuadeno quiere de la libreria:  \n"<<endl;
	cout<<"Ingrese Modelo de cuaderno:  "<<endl;
	cin>>modelo;
	cout<<"Ingrese la catidad de cuaderno quiere:  "<<endl;
	cin>>color;
	cout<<"pon el dia que compro el cuaderno:  "<<endl;
	cin>>edad;
	//validaciones
	modelo=toupper(modelo);
	color =toupper(color);
	if (modelo=='1'){
			cantidad=cantidad*1precio			
	
	}
	
	else if (modelo=='2'){
		cantidad=cantidad*1precio
	
	}
	
	else if (modelo==?'3'){
		cantidad=cantidad*1precio
	
	}

	else if (modelo== '4'){
		precio=cantidad*1precio

}	
	
	ofstream registrofumigacion;
	
	cout.precision(5);
	cout<<"Modelo: "<<modelo<<endl;
	cout<<"cantidad:  "<<color<<endl;
	cout<<"dia:   "<<edad<<endl;
	cout<<"\n\nPrecio a pagar del cuaderno:  "<<1precio,2precio,3precio,4precio<<endl;
	//Grabar al archivo
	ofstream miarchivo;
	system("PAUSE");
	try {
		miarchivo.open("Libreria.txt",ios::out);
		miarchivo<<modelo<<"\t"<<cantidad<<"\t"<<precio<<"/t"<<dia<<endl;
		miarchivo.close();
		cout<<"Datos grabados en el archivo";
	}
	catch(exception X){
		cout<<"Error al grabar en el archivo";
		system("PAUSE");
	}
return 0;

}

void eliminar(){
	ifstream db_a; 
	ofstream db_n; 
	int aux,oid,onota,flag;
	string onombre;
	remove("Temporal.txt");
	
	db_a.open("Libreria.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese ID que desea borrar: "<<endl;
	cin>>aux;
	
	while (db_a>>onombre>>oid>>onota){
		if(aux==oid){
			cout<<"Registro Eliminado...."<<endl;
			flag =1;
		}			
		else if(aux!=oid)
			db_n<<onombre<<"\t"<<oid<<"\t"<<onota<<endl;
		
							
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("Libreria.txt");
		rename("Temporal.txt","Libreria.txt");
	}	
	system("Pause");
}

void modificar(){
	ifstream db_a;  
	ofstream db_n; 
	int aux,oid,onota,flag,inota;
	string onombre;
	char respuesta;
	remove("Temporal.txt");
	
	db_a.open("Libreria.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese ID al que modificara informacion: "<<endl;
	cin>>aux;
	do {
		cout<<"Ingrese Nota a modificar: "<<endl;
		cin>>inota;
		cout<<"\n\nEsta Seguro? S/N";
		cin>>respuesta;
		cout<<"\n"<<endl;
		respuesta = toupper(respuesta);		
	} while (respuesta!='S');	
	
	//leer archivo anterior
	while (db_a>>onombre>>oid>>onota){
		if(aux==oid){
			db_n<<onombre<<"\t"<<oid<<"\t"<<inota<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag =1;
		}			
		else if(aux!=oid)
			db_n<<onombre<<"\t"<<oid<<"\t"<<onota<<endl;
						
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("Libreria.txt");
		rename("Temporal.txt","Libreria.txt");
	}	
	system("Pause");
}
