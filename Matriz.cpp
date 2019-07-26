#ifndef MATRIZ_CPP
#define MATRIZ_CPP
	#include<cstdlib>
	#include<ctime>
	#include<iostream>
	using namespace std;
	class Matriz{
		private:
			int **matriz;
			int filas;
			int columnas;
		public:
			Matriz(){
				//se crea una matriz de 5*5 de numeros aleatorios
				
				filas=5;
				columnas=5;
				matriz=new int*[5];
				for(int i=0;i<5;i++){
					matriz[i]=new int[5];
				}
				
				for(int i=0;i<filas;i++){
					for(int j=0;j<columnas;j++){
						matriz[i][j]=1+rand()%10;
					}
				}
				
				
			}
			Matriz(int filas,int columnas){
				this->filas=filas;
				this->columnas=columnas;
				//se crea una matriz de tamaño definido
				
				matriz=new int*[filas];
				for(int i=0;i<5;i++){
					matriz[i]=new int[columnas];
				}
				
				for(int i=0;i<filas;i++){
					for(int j=0;j<columnas;j++){
						matriz[i][j]=1+rand()%10;
					}
				}
				
			}
			bool suma(Matriz obj){
				if(filas==obj.getFilas()&&columnas==obj.getColumnas()){
					//operamos las matrices
					int**matriz2=obj.getMatriz();//obtenemos la matriz guardada en el objeto
					for(int i=0;i<filas;i++){
						for(int j=0;j<columnas;j++){
							matriz[i][j]=matriz[i][j]+matriz2[i][j];
						}
					}
					return true;
				}else{
					return false;
				}
			}
			void imprimir_matriz(){
				for(int i=0;i<filas;i++){
					for(int j=0;j<columnas;j++){
						cout<<"["<<matriz[i][j]<<"]";
					}
					cout<<endl;
				}
			}	
			
			int**getMatriz(){
				return matriz;
			}
			void setMatriz(int**matriz){
				this->matriz=matriz;
			}
			int getFilas(){
				return filas;
			}
			void setFilas(int filas){
				this->filas=filas;
			}
			int getColumnas(){
				return columnas;
			}
			void setColumnas(int columnas){
				this->columnas=columnas;
			}
			bool resta(Matriz obj){
				if(filas==obj.getFilas()&&columnas==obj.getColumnas()){
					//operamos las matrices
					int**matriz2=obj.getMatriz();//obtenemos la matriz guardada en el objeto
					for(int i=0;i<filas;i++){
						for(int j=0;j<columnas;j++){
							matriz[i][j]=matriz[i][j]-matriz2[i][j];
						}
					}
					return true;
				}else{
					return false;
				}
			}
			
			void multiplicacion(int num){
				for(int i=0;i<filas;i++){
					for(int j=0;j<columnas;j++){
						matriz[i][j]*=num;
					}
				}
			}
			
			void liberar_matriz(){
				for(int i=0;i<filas;i++){
						delete[] matriz[i];
				}
				delete[] matriz;
			}
	};
#endif
