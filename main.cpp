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



    pld.close();
    //Save file with custom name
    cout << "Da el nombre al archivo sin espacios: ";
    cin >> typed;
    typed = typed + ".pld";
    char* fileName = new char[typed.length() + 1];
    strcpy(fileName, typed.c_str());

    if (rename("file.pld", fileName) != 0)
		perror("Error renaming file");
	else
		cout << "Creado con exito. Para salir oprima cualquier tecla";
        cin.ignore();
}