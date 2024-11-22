#include <iostream>
#include <string>
using namespace std;
#include <fstream>

int main() {
	string ruc, producto;
	int unidades;
	double precio;
	char aux;
	ofstream archivo;
	
	archivo.open("output.txt"); //Apertura (Creacion)
	
	cout<<"RUC del cliente (X para terminar): ";
	cin>>ruc;
	while (ruc!="X") {
		//Queda pendiente el intro anterior...
		cin.get(aux); //Leemos el Intro
		cout<<"Producto: ";
		getline(cin,producto);
		cout<<"Unidades: ";
		cin>>unidades;
		cout<<"Precio: ";
		cin>>precio;
		//Escribimos los datos en una linea del archivo...
		//Con un espacio de separacion entre ellos
		archivo<<ruc<<" "<<unidades<<" "
			<<precio<<" "<<producto<<endl;
		cout<<"RUC del cliente (X para terminar): ";
		cin>>ruc;
	}
	//Escribimps el centinela final...
	archivo<<"X";
	archivo.close(); //Cierre del archivo
	
	return 0;
}