#include <iostream>
#include <string>
using namespace std;
char** provisionarMatriz(int,int);
//liberar memoria de la matriz
void liberarMatriz(char**&,int);

//imprimir la matriz
void printMatrix(char**,int,int);

char** llenarlinera(char**,int,int);
char** llenar(char**, int, int);
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
		matriz= llenar(matriz,tamaX,tamaY);			








		liberarMatriz(matriz,tamaX);
		cout << "desea reingresar 1) si 2) no " << endl;
	       	cin >>salir;	
	}//fin respuesta usuario
}//fin main
char** llenar(char** mat,int x,int y){
	int izq=0;
	int cen=0;
	int der=0;
	for(int i=1; i<x ; i++){//1 va a ser . 2 va a ser ^
		for(int j=0;j<y;j++){
			if( (j-1<0)&&(mat[i-1][j]=='^')&&(mat[i-1][j+1]=='^')){
				
			}else if((j+1>=x)&&(mat[i-1][j]=='.')&&(mat[i-1][j+1]=='^')){
				
			}else if((mat[i-1][j-1]=='^')&&(mat[i-1][j]=='^')&&(mat[i-1][j+1]=='.')){
				mat[i][j]='^';
			}else if((mat[i-1][j-1]=='.')&&(mat[i-1][j]=='^')&&(mat[i-1][j+1]=='^')){
				mat[i][j]='^';
			}else if((mat[i-1][j-1]=='^')&&(mat[i-1][j]=='.')&&(mat[i-1][j+1]=='.')){
				mat[i][j]='^';
			}else if((mat[i-1][j-1]=='.')&&(mat[i-1][j]=='.')&&(mat[i-1][j+1]=='^')){
			mat[i][j]=='^';
			}
				
		}
	}
	return mat;
}//fin metodo
char** llenarlinera(char** matriz,int y,int x){
	char valor=' ';
	bool valido= false;
	for(int i=0;i<x ;i++){
		valido=false;
		cout << valido<< endl;
		cout <<"ingrese el valor de la casila" << i << " :"<< endl;
		cin >> valor;
		if(valor =='.' ||valor== '^' ){
			matriz[0][i]=valor;
			valido=true;
		}
		cout << valido << endl;
		while(valido==false){
			cout << "ingreso un caracter no valido " << endl;
			cout <<"ingrese el valor de la casila" << i << " :"<< endl;
                	cin >> valor;
			if(valor =='.' ||valor== '^' ){
	                        matriz[0][i]=valor;
        	                valido=true;
               		 }

		}
		//cout << "valor " << valor << endl
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
