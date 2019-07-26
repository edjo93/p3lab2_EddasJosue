#include"Matriz.cpp"
#include"Bitacora.cpp"
#include<iostream>
using namespace std;

char choose;
char*eleccion=NULL;

int main(){
	//objeto Bitacora disponible a lo largo del programa
	Bitacora bit;
	do{
		cout<<"\ncomo desea iniciar?\n1.matriz 5*5 aleatorio\n2.solo aleatorio\n?:";
		cin>>choose;
		eleccion=&choose;
	}while(*eleccion!='1'&&*eleccion!='2');
	Matriz*m=NULL;
	switch(*eleccion){
		case'1':
			
				//se crea una matriz de 5*5 aleatoria
				m=new Matriz();
			
			
			break;
		case'2':
			{
				int filas;
				int columnas;
				cout<<"\nfilas: ";
				cin>>filas;
				while(filas<1){
					cout<<"error/ingrese un numero de filas mayor o igual a 1 :";
					cin>>filas;
				}
				cout<<"\ncolumnas: ";
				cin>>columnas;
				while(columnas<1){
					cout<<"error/ingrese un numero de columnas mayor o igual a 1 :";
					cin>>columnas;
				}	
				//se crea una matriz de tamaño definido por el usuario aleatoriamente
				m=new Matriz(filas,columnas);
			}
			
			
			break;
		default:
			cout<<"\nthere is some problem";
	}
	
	//matrix in memory
	
	//new menu
	do{
		cout<<"\na.suma\nb.resta\nc.multiplicacion\nd.eliminar ultimo registro\ne.vaciar registros\nf.imprimir registros\ns-salir?:";
		cin>>choose;
		eleccion=&choose;
		switch(*eleccion){
			case'a':
				{
					cout<<"\nprincipal: "<<endl;
					m->imprimir_matriz();
					cout<<endl;
					//segundo objeto matriz
					int filas;
					int columnas;
					cout<<"\nfilas: ";
					cin>>filas;
					while(filas<1){
						cout<<"error/ingrese un numero de filas mayor o igual a 1 :";
						cin>>filas;
					}
					cout<<"\ncolumnas: ";
					cin>>columnas;
					while(columnas<1){
						cout<<"error/ingrese un numero de columnas mayor o igual a 1 :";
						cin>>columnas;
					}
					//valid row and columns	
					Matriz m2(filas,columnas);
					cout<<"\nmatriz secundaria\n";
					m2.imprimir_matriz();
					bit.agregar("suma",m->suma(m2));
					//m2.liberar_matriz();
					
					cout<<"\nresultado m1 "<<endl;
					m->imprimir_matriz();
				}
				
				
				break;
			case'b':
				{
					cout<<"\nprincipal: "<<endl;
					m->imprimir_matriz();
					cout<<endl;
					//segundo objeto matriz
					int filas;
					int columnas;
					cout<<"\nfilas: ";
					cin>>filas;
					while(filas<1){
						cout<<"error/ingrese un numero de filas mayor o igual a 1 :";
						cin>>filas;
					}
					cout<<"\ncolumnas: ";
					cin>>columnas;
					while(columnas<1){
						cout<<"error/ingrese un numero de columnas mayor o igual a 1 :";
						cin>>columnas;
					}
					//valid row and columns	
					Matriz m2(filas,columnas);
					cout<<"\nmatriz secundaria\n";
					m2.imprimir_matriz();
					bit.agregar("resta",m->resta(m2));
					//m2.liberar_matriz();
					
					cout<<"\nresultado m1 "<<endl;
					m->imprimir_matriz();
					
				}	
				break;
			case'c'	:
				{
					
					cout<<"\nprincipal: "<<endl;
					m->imprimir_matriz();
					cout<<endl;
					int num;
					cout<<"\ningrese numero >=0: ";
					cin>>num;
					while(num<0){
						cout<<"error/ingrese numero>=0";
						cin>>num;
					}
					m->multiplicacion(num);
					bit.agregar("multiplicacion",true);
					
					cout<<"\nresultado m1 "<<endl;
					m->imprimir_matriz();
					
				}
				break;
			case'd'	:
				bit.eliminar_ultimo();
				break;
			case'e'	:
				bit.clear();
				break;
			case'f'	:
				bit.print();
				break;	
			case's':
				cout<<"\nhasta luego";
				break;
			default:
				cout<<"\nno reconozco esa opcion intente de nuevo"<<endl;	
		}
	}while(*eleccion!='s');
	
	
	
	
	
	return 0;
}

