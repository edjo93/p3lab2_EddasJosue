#ifndef BITACORA_CPP
#define BITACORA_CPP
	#include<vector>
	#include<string>
	#include <iostream>
	using namespace std;
	class Bitacora{
		private:
			vector<string> stringContent;
			vector<bool> boolContent;
		public:
			void agregar(string str,bool status){
				stringContent.push_back(str);
				boolContent.push_back(status);
			}
			void print(){
				for(int i=0;i<stringContent.size();i++){//we can use either size
					cout<<endl;
					cout<<stringContent.at(i)<<":";
					if(boolContent.at(i)==1 ){
						cout<<"exito" ;
					}else{
						cout<<"failed";
					}
					cout<<endl;
				}
			}	
			void eliminar_ultimo(){
				stringContent.pop_back();
				boolContent.pop_back();
			}
			void clear(){
				stringContent.clear();
				boolContent.clear();
			}
	};
#endif
