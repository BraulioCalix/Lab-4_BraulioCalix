#include <iostream>
#include <string>
//liberar memoria de la matriz
void liberarMatriz(char**&,int);

//imprimir la matriz
void printMatrix(char**,int);



int main(){
	cout << "bienvenido" << endl;
	int salir= 1;//respuesta de usuario
	while(salir!=2){
	


		cout << "desea reingresar 1) si 2) no " << endl;
	       	cin >>salir;	
	}//fin respuesta usuario
}



void printMatrix(char** matrix, int size){
	for(int i=0; i<size ;i++){
		for(int j=0; j<size ;j++){
        	        cout << "[" << matrix[i][j]<< "]" ;
	        }
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
void liberarMatriz(char**& matriz, int size){
	for(int i=0;i<size;i++){
		if(matriz[i]!=NULL){
			delete[] matriz[i];
       			matriz[i]= NULL;
		}
	}

}
