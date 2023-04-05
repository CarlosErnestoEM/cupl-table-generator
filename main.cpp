#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main(){
    string typed;
    ofstream pld("file.pld");
    cout << "Bienvenido al Editor de CUPL" << endl;
    cout << "de Carlitos jiji" << endl << endl;

    cout << "El programa genera una solucion usando la instruccion TABLE" << endl;
    cout << "Enter para continuar"; cin.ignore();


    //Save file with custom name
    cout << "Da el nombre al archivo sin espacios: ";
    cin >> typed;
    typed = typed + ".pld";
    char* fileName = new char[typed.length() + 1];
    strcpy(fileName, typed.c_str());

    //Creating file
    pld << "Name    " << typed << " ;"<< endl;
    pld << "PartNo  " << "00" << " ;"<< endl;
    pld << "Date  " << "09/03/2022" << " ;"<< endl;
    pld << "Revision  " << "01" << " ;"<< endl;
    pld << "Designer  " << "Estrada Carlos" << " ;"<< endl;
    pld << "Company  " << "ESIME" << " ;"<< endl;
    pld << "Assembly  " << "None" << " ;"<< endl;
    pld << "Location  " << " " << " ;"<< endl;
    pld << "Device  " << "G22V10" << " ;"<< endl;
    pld << "PIN [1..4] = [E0..3] ;"<< endl;
    pld << "PIN [23..16] = [S0..7] ;"<< endl << endl;
    pld << "FIELD entrada = [E0..3] ;"<< endl;
    pld << "FIELD salida = [S0..7] ;"<< endl;
    pld << "TABLE entrada => salida {"<< endl;
    //Create table using an array

    pld << "}";
    pld.close();

    if (rename("file.pld", fileName) != 0)
		perror("Error renaming file");
	else
		cout << "Creado con exito. Para salir oprima cualquier tecla";
        cin.ignore();
}