#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;

class Nodo{
	public:
		int info;
		Nodo* izq;
		Nodo* der;	
};

class Arbol{
	private:
		Nodo* raiz; // apuntador al inicio del arbol
	public:
		Arbol(); // constructor
		
		Nodo* creaArbol();
		void muestraArbol(Nodo *apnodo, int nivel);
		
		//Metodos de recorrido
		void preorden(Nodo* apnodo);	
		void inorden(Nodo* apnodo);	
		void posorden(Nodo* apnodo);
		bool verificaArbolCompleto(Nodo* apnodo);
		
		int altura(Nodo *apnodo);	
		int contarNodos(Nodo *apnodo);	
		int contarHojas(Nodo *apnodo);	
};

//constructor prederteminado
Arbol::Arbol(){
	raiz=NULL;
}

void Arbol::muestraArbol(Nodo *apnodo, int nivel){
	//
	if(apnodo != NULL){
		muestraArbol(apnodo->der, nivel + 1);  // Primero mostrar el subarbol derecho

		cout << setw(nivel * 5) << " " << apnodo->info << endl;  // Imprimir nodo con sangria

		muestraArbol(apnodo->izq, nivel + 1);  // Luego mostrar el subarbol izquierdo
	}
	//
}

Nodo*  Arbol::creaArbol(){
	bool resp;
	Nodo* apnodo =new Nodo();
	
	cout<<"\nIngrese el valor del nodo: ";
	cin>>apnodo->info;
	
	cout<<"\nExiste nodo por izquierda 1(SI) - 0(NO)? ";
	cin>>resp;
	if(resp==1){
		apnodo->izq=creaArbol();
	}else{
		apnodo->izq=NULL;
	}
	
	cout<<"\nExiste nodo por derecha 1(SI) - 0(NO)? ";
	cin>>resp;
	if(resp==1){
		apnodo->der=creaArbol();
	}else{
		apnodo->der=NULL;
	}
	return apnodo;
}

//Recorrido en Preorden : Raiz -subarbol izquierdo - subarbol derecho
void Arbol::preorden(Nodo* apnodo){
	if(apnodo!=NULL){
		cout<<apnodo->info<<" ";
		preorden(apnodo->izq);
		preorden(apnodo->der);
	}
}

//Recorrido en Inorden :subarbol izquierdo -raiz- subarbol derecho
void Arbol::inorden(Nodo* apnodo){
	if(apnodo!=NULL){
		inorden(apnodo->izq);
		cout<<apnodo->info<<" ";
		inorden(apnodo->der);
	}
}

//Recorrido en Posorden : subarbol izquierdo -subarbol derecho - raiz
void Arbol::posorden(Nodo* apnodo){
	if(apnodo!=NULL){
		posorden(apnodo->izq);
		posorden(apnodo->der);
		cout<<apnodo->info<<" ";
	}
}

//altura del arbol
int Arbol::altura(Nodo* apnodo){
	if(apnodo==NULL){
		return 0;
	}else{
		return 1 + max(altura(apnodo->izq),altura(apnodo->der)) ;
	}
}


//cantidad de nodos de un arbol
int Arbol::contarNodos(Nodo* apnodo){
	if(apnodo==NULL){
		return 0;
	}else{
		return 1 + contarNodos(apnodo->izq) + contarNodos(apnodo->der);
	}
}

int Arbol::contarHojas(Nodo *apnodo){
	//
	if(apnodo == NULL){
		return 0;
	}
	if(apnodo->izq == NULL && apnodo->der == NULL){
		cout<<"Hoja encontrada: "<<apnodo->info<<endl;
		return 1;
	}
	return contarHojas(apnodo->izq) + contarHojas(apnodo->der);
	//
	
}
//funcion que verifique si el arbol  binario esta completo
bool Arbol::verificaArbolCompleto(Nodo* apnodo) {
	return (contarNodos(apnodo)==(pow(2,altura(apnodo))-1)) ? true:false;
}

void menu(){
	Arbol arbol;
	Nodo* raiz=NULL;
	int op,hoja;
	
	do{
		cout<<"\n-----MENU DE OPCIONES- ARBOL BINARIO-------"<<endl
			<<"1.- Crear arbol"<<endl
			<<"2.- Mostrar arbol (forma estructurada)"<<endl
			<<"3.-Recorrido en Preorden"<<endl
			<<"4.-Recorrido en Inorden"<<endl
			<<"5.-Recorrido en Posorden"<<endl
			<<"6.-Altura del arbol"<<endl
			<<"7.-Contar todos los nodos"<<endl
			<<"8.- Contar nodos hoja"<<endl
			<<"9.- Verifica si el arbol esta completo"<<endl
			<<"0.- SALIR"<<endl;
		cout<<"Ingrese una opcion: ";
		cin>>op;
			
			switch(op){
				case 1:
					raiz=arbol.creaArbol();
					break;
				case 2:
					if(raiz==NULL)
						cout<<"El arbol esta vacio\n";
					else
						arbol.muestraArbol(raiz,0);
					break;	
				case 3:
					if(raiz==NULL){
						cout<<"El arbol esta vacio\n";
					}else{
						cout<<" Recorrido Preorden: ";
						arbol.preorden(raiz);
						cout<<"\n";
					} 
					break;	
				case 4:
					if(raiz==NULL){
						cout<<"El arbol esta vacio\n";
					}else{
						cout<<" Recorrido Inorden: ";
						arbol.inorden(raiz);
						cout<<"\n";
					} 
					break;
				case 5:
					if(raiz==NULL){
						cout<<"El arbol esta vacio\n";
					}else{
						cout<<" Recorrido Posorden: ";
						arbol.posorden(raiz);
						cout<<"\n";
					} 
					break;
				case 6:
					if(raiz==NULL){
						cout<<"El arbol esta vacio\n";
					}else{
						cout<<"Altura del arbol: "<<arbol.altura(raiz)<<endl;
						
					}	
					break;
				case 7:
					if(raiz==NULL){
						cout<<"El arbol esta vacio\n";
					}else{
						cout<<"Cantidad total de nodos: "<<arbol.contarNodos(raiz)<<endl;
						
					}	
					break;
				case 8:
					if(raiz==NULL){
						cout<<"El arbol esta vacio\n";
					}else{
						hoja=arbol.contarHojas(raiz);
						cout<<"Cantidad de nodos hoja: "<<hoja<<endl;
						
					}	
					break;
				case 9:
					cout<<"Esta completo ? "<<(arbol.verificaArbolCompleto(raiz) ? "SI" : "NO")<<endl;
					break;	
				case 0:
					cout<<"Saliendo del programa....\n";
					break;	
				default:
					cout<<"Opcion invalida. Intente nuevamente.\n";
					
			}			
	}while(op!=0);
}

int main(){
	menu();
	return 0;
}
