/*
* ------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACION
* CC3086 - Programacion de microprocesadores
* ------------------------------------------------------------
* Laboratorio 02 - Parte 2
* Descripción: Almacenamiento de datos y estructura de orden
* -------------------------------------------------------------
*/

#include <iostream>
using namespace std;

int cantDPIs, *numDPIs;

struct dpis{
  char nombre[20];
  char apellido[20];
  int CUI;
  int ultimoCUI;
  char expiracion[20];
} dpiN;

int main (){
  cout << "---Bienvenido al ordenador de DPI's---\n" << endl;

  cout << "Ingrese la cantidad de DPIs a ingresar: ";
  cin >> cantDPIs;
  //creacion del array
  numDPIs = new int[cantDPIs];
  for (int i = 0; i < cantDPIs; i++)
    {
      cin.getline (dpiN.apellido, 20, '\n');
      //solicita el nombre
      cout << "Nombre: " << endl;
      cin.getline (dpiN.nombre, 20, '\n');

      //solicita el apellido
      cout << "Apellido:" << endl;
      cin.getline (dpiN.apellido, 20, '\n');

      //solicita el CUI
      cout << "CUI: " << endl;
      cin >> numDPIs[i];

      //solicita el ultimo numero del CUI
      cout << "Ultimo numero del CUI: " << endl;
      cin >> dpiN.ultimoCUI;

      //solicita la fecha de expiracion
      cout << "Expiracion:" << endl;
      cin.getline (dpiN.expiracion, 20, '\n');

      cout << "/n";
    }
    
  int aux;

  for (int i = 0; i < cantDPIs; i++){
      for (int j = 1; j < cantDPIs - 1; j++){   
	  if (*(numDPIs + j) > *(numDPIs + j + 1)){
	      aux = *(numDPIs + j);
	      *(numDPIs + j) = *(numDPIs + j + 1);
	      *(numDPIs + j + 1) = aux;
	    }
      }
    }

  cout << "\nDPIs ordenados de menor a mayor por su ultimo digito: \n";
  for (int i = 0; i < cantDPIs; i++){
      cout << *numDPIs++ << endl;
    }
  return 0;
}