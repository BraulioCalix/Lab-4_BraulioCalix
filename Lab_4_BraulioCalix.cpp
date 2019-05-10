#include <iostream>
#include <string>
using namespace std;
char** provisionarMatriz(int,int);
//liberar memoria de la matriz
void liberarMatriz(char**&,int);

//imprimir la matriz
void printMatrix(char**,int,int);

char** llenarlinera(char**,int,int);

int main(){
	cout << "bienvenido" << endl;
	int salir= 1;//respuesta de usuario
	while(salir!=2){
		cout << "ingrese el tamano horizontal de la matriz " << endl;
		int tamaY=0;
		cin >> tamaY;
		cout << "ingrese el tamano vertical de la matriz: " << endl;
		int tamaX = 0;
		cin >> tamaX;
		char** matriz = NULL;
		matriz= provisionarMatriz(tamaX,tamaY);
		printMatrix(matriz,tamaX,tamaY);
		
		cout << "antes" << endl;
		 matriz=llenarlinera(matriz,tamaX,tamaY);

		printMatrix(matriz,tamaX,tamaY);
		cout << "desp" << endl;
		
		liberarMatriz(matriz,tamaX);
		cout << "desea reingresar 1) si 2) no " << endl;
	       	cin >>salir;	
	}//fin respuesta usuario
}

char** llenarlinera(char** matriz,int y,int x){
	char valor=' ';
	for(int i=0;i<x ;i++){
		cout <<"ingrese el valor de la casila" << i << " :"<< endl;
		cin >> valor;
		cout << "valor " << valor << endl;
		matriz[0][i]=valor;
		cout << matriz[0][i]<< endl;
	}
return matriz;
}

void printMatrix(char** matrix, int x, int y){
	for(int i=0; i<x ;i++){
		for(int j=0; j<y ;j++){
        	        cout << "[" << matrix[i][j]<< "]" ;
	        }
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
void liberarMatriz(char**& matriz, int x){
	for(int i=0;i<x;i++){
		if(matriz[i]!=NULL){
			delete[] matriz[i];
       			matriz[i]= NULL;
		}
	}

}
char** provisionarMatriz (int x,int y){
	char** matriz = NULL;
	matriz = new char* [x];
	for(int i= 0;i< x ; i++){
		matriz[i]= new char[y];
	}
	return matriz;
}
