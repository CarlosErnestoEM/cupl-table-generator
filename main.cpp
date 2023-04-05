#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>

using namespace std;

int main(){
    string typed,fileName;
    map<int,string> values;
    ofstream pld("file.pld");
    cout << "Bienvenido al Editor de CUPL" << endl;
    cout << "de Carlitos jiji" << endl << endl;

    cout << "El programa genera una solucion usando la instruccion TABLE" << endl;
    cout << "Enter para continuar"; cin.ignore();

    cout << "Introduzca los valores en cada linea usando 00 a FF" << endl;
    cout << "Para salir del llenado oprima S y enter" << endl;
    bool continueWriting = true;
    for(int i = 0; i <= 15; i++){
        if(continueWriting){
            cout << "Ingrese el valor de la tabla en hexadecimal " << i << ":"<< endl;
            cin >> typed;
            if(typed[0] == 'S'){
                continueWriting = false;
                i--;
            }else{
                values[i] = typed;
            }
        }else{
            values[i] = "00";
        }
    }

    //Save file with custom name
    cout << "Da el nombre al archivo sin espacios: ";
    cin >> fileName;

    //Creating file
    pld << "Name    " << fileName << " ;"<< endl;
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

    //Create table using a map
    map<int, string>::iterator it;
    for(it=values.begin(); it!=values.end(); ++it){
        pld << "'d'" << it->first << "=>    'h'" << it->second << ";" << endl; 
    }

    pld << "}";
    pld.close();

    fileName = fileName + ".pld";
    char* fileNamePointer = new char[fileName.length() + 1];
    strcpy(fileNamePointer, fileName.c_str());

    if (rename("file.pld", fileNamePointer) != 0)
		perror("Error renaming file");
	else
		cout << "Creado con exito. Para salir oprima cualquier tecla";
        cin.ignore();
}