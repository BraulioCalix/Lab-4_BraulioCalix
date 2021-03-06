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
		matriz=llenarlinera(matriz,tamaX,tamaY);
		matriz= llenar(matriz,tamaX,tamaY);			
		printMatrix(matriz,tamaX,tamaY);
		liberarMatriz(matriz,tamaX);
		cout << "desea reingresar 1) si 2) no " << endl;
	       	cin >>salir;	
	}//fin respuesta usuario
}//fin main
char** llenar(char** mat,int x,int y){
	for(int i=1; i<x ; i++){//1 va a ser . 2 va a ser ^
		for(int j=0;j<y;j++){
			if( (j==0)&&(mat[i-1][j]=='^')&&(mat[i-1][j+1]=='^')){
				mat[i][j]='^';
							
			}else if((j==y-1)&&(mat[i-1][j]=='.')&&(mat[i-1][j-1]=='^')){
				mat[i][j]='^';
			}else if((j==0)&&(mat[i-1][j]=='.')&&(mat[i-1][j+1]=='^')){
                                mat[i][j]='^';
			
			}else if((j==y-1)&&(mat[i-1][j]=='^')&&(mat[i-1][j-1]=='^')){
				mat[i][j]='^';
			}else if((mat[i-1][j-1]=='^')&&(mat[i-1][j]=='^')&&(mat[i-1][j+1]=='.')){
				mat[i][j]='^';
			}else if((mat[i-1][j-1]=='.')&&(mat[i-1][j]=='^')&&(mat[i-1][j+1]=='^')){
				mat[i][j]='^';
			}else if((mat[i-1][j-1]=='^')&&(mat[i-1][j]=='.')&&(mat[i-1][j+1]=='.')){
				mat[i][j]='^';
			}else if((mat[i-1][j-1]=='.')&&(mat[i-1][j]=='.')&&(mat[i-1][j+1]=='^')){
				mat[i][j]='^';
			}else{
				mat[i][j]='.';
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
		cout <<"ingrese el valor de la casila " << i << " :"<< endl;
		cin >> valor;
		if(valor =='.' ||valor== '^' ){
			matriz[0][i]=valor;
			valido=true;
		}
	
		while(valido==false){
			cout << "ingreso un caracter no valido " << endl;
			cout <<"ingrese el valor de la casila" << i << " :"<< endl;
                	cin >> valor;
			if(valor =='.' ||valor== '^' ){
	                        matriz[0][i]=valor;
        	                valido=true;
               		 }

		}
		
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
