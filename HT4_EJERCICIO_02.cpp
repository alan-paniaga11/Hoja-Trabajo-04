/*
HOJA DE TRABAJO #5

EJERCICIO#2

Realice un programa que, dado el peso, la altura, la edad y el género (M/F) de un grupo de N personas
que pertenecen a un departamento de la república, obtenga un promedio de peso, altura y edad de esta
población. Los datos deben guardarse de forma ordenada por edad en un archivo de datos. Así mismo
el programa debe ser capaz leer los datos del archivo y generar un reporte con la media del peso, altura
y la edad. 
*/


#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
int main (){

int muestra=0;
int i=0;
int edad=0;
int niño=0;
int joven=0;
int adulto=0;
int adultomayor=0;


cout<<"Ingrese el numero de la muestra: "<<endl;
cin>>muestra;

cout<<"Ingrese la edad:  "<<endl;
cin>>edad=0;

for(int i=1; i<=muestra; i=i+1);
{
	if(edad <= 12){
	niño += 1;
}
	else if(edad >= 13 && edad <=29){
	joven += 1;
}
	else if(edad >= 30 && edad <= 59){
	adulto  += 1;
}
	else if(edad >= 60){
	adultomayor += 1;
}
}
	ofstream muestraedades;
	system("PAUSE");
	try {
		muestraedades.open("seguro.txt",ios::out);
		muestraedades<<edad<<"\t"<<niño<<"\t"<<joven<<"\t"<<adulto"\t"<<<<adultomayor<<endl;
		muestraedades.close();
		cout<<"Datos grabados en el archivo";
	}
	catch(exception X){
		cout<<"Error al grabar en el archivo";
		system("PAUSE");
	} //fin try/catch
	system("CLS"); 
	ifstream leerarchivo;
	leerarchivo.open("muestraedades.txt",ios::in);
	leerarchivo>>ledad>>lniño>>ljoven>>ladulto>>ladultomayor;	
	leerarchivo.close();

return 0;

}
