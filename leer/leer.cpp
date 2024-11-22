#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip> //formato de salida

int main() {
	const int IGV=21;
	string ruc, producto;
	int unidades;
	double precio, neto, total, igv;
	char aux;
	ifstream archivo;
	int contador=0;
	
	archivo.open("compras.txt"); //apertura
	
	if (archivo.is_open()) { //Existe el archivo
		archivo>>ruc; //Primer ruc
		while (ruc!="X") {
			archivo>>unidades>>precio;
			archivo.get(aux); //Salta el espacio
			getline(archivo, producto);
			contador++;
			neto=unidades*precio;
			igv=neto*IGV/100;
			total=neto+igv;
			cout<<"Compra "<<contador<<".-"<<endl;
			cout<<"   "<<producto<<": "<<unidades
				<<" x "<<fixed<<setprecision(2)
				<<precio<<" = "<<neto<<" - I.G.V.: "
				<<igv<<" - Total: "<<total<<endl;
				archivo>>ruc; //Siguiente RUC
		}
		archivo.close(); //Cierre
	} else {
		cout<<"ERROR: No se ha podido abrir el archivo"<<endl;
	} 
	return 0;
}