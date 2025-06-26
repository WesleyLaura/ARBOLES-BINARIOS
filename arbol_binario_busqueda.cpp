#include <iostream>
#include <iomanip>
using namespace std;

class Nodo
{
public:
    int info;
    Nodo* izq;
    Nodo* der;
};

class Arbol
{
private:
    Nodo* raiz; // apuntador al inicio del arbol

public:
    Arbol(); // constructor

    Nodo*& regresaRaiz();
    void insertarNodo(Nodo*& apnodo, int dato);
    void insertarNodo2(Nodo*& apnodo, int dato);
    void insertarNodoIterativo(Nodo*& apnodo, int dato);
    void busquedaABB(Nodo* apnodo, int dato);
    bool busquedaABB2(Nodo* apnodo, int dato);
    void busquedaABBIterativa(Nodo* apnodo, int dato);
    void muestraArbol(Nodo* apnodo, int nivel);

    // Metodos de recorrido
    void preorden(Nodo* apnodo);
    void inorden(Nodo* apnodo);
    void posorden(Nodo* apnodo);

    int altura(Nodo* apnodo);
    int contarNodos(Nodo* apnodo);
    int contarHojas(Nodo* apnodo);
    
    void maximoArbol(Nodo* apnodo);
    void minimoArbol(Nodo* apnodo);
    void eliminarABB(Nodo* &apnodo, int dato);
    void podarArbol(Nodo*&apnodo);
};

// constructor predeterminado
Arbol::Arbol()
{
    raiz = NULL;
}

// regresa el apuntador a la raiz
Nodo*& Arbol::regresaRaiz(){
    return raiz;
}
//cuando el arbol tiene nodos ya creados
void Arbol::insertarNodo(Nodo*& apnodo, int dato){
    if(dato < apnodo->info){
        if(apnodo->izq == NULL){
            Nodo* otro = new Nodo();
            otro->info = dato;
            otro->izq = NULL;
            otro->der = NULL;
            apnodo->izq = otro;
        } else {
            insertarNodo(apnodo->izq, dato);
        }
    } else {
        if(dato > apnodo->info){
            if(apnodo->der == NULL){
                Nodo* otro = new Nodo();
                otro->info = dato;
                otro->izq = NULL;
                otro->der = NULL;
                apnodo->der = otro;
            } else {
                insertarNodo(apnodo->der, dato);
            }
        } else {
            cout << "El nodo "<< dato <<" ya se encuentra en el arbol."<< endl;
        }
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

//altura del arbol
int Arbol::altura(Nodo* apnodo){
	if(apnodo==NULL){
		return 0;
	}else{
		return 1 + max(altura(apnodo->izq),altura(apnodo->der)) ;
	}
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
//aqui el arbol esta vacio
void Arbol::insertarNodo2(Nodo*& apnodo, int dato)
{
	if(apnodo!=NULL){
		if(dato<apnodo->info){
			return insertarNodo2(apnodo->izq,dato);
		}else{
			if(dato>apnodo->info){
				return insertarNodo2(apnodo->der,dato);
			}else{
				cout<<"La informacion ya se encuentra en el arbol.\n";
			}
		}
	}else{
		Nodo *otro=new Nodo();
		otro->info=dato;
		otro->der=NULL;
		otro->izq=NULL;
		apnodo=otro;
	}
}

void Arbol::insertarNodoIterativo(Nodo*& apnodo, int dato){
    Nodo *otro=new Nodo();
    otro->info=dato;
    otro->der=NULL;
    otro->izq=NULL;
    if(apnodo==NULL){
    	apnodo=otro;
	}else{
		Nodo *h,*p=new Nodo();
		h=apnodo;
		p=NULL;
		while(h!=NULL){
			p=h;
			if(dato<h->info){
				h=h->izq;
			}else{
				h=h->der;
			}
		}
		if(p->info>dato){
			p->izq=otro;
		}else{
			p->der=otro;
		}
	}
}
//busqueda modo recursiva cuando tiene subarboles
void Arbol::busquedaABB(Nodo* apnodo, int dato){
    if(dato<apnodo->info){
    	if(apnodo->izq==NULL){
    		cout<<"La informacion no se encuentra en el arbol\n";
		}else{
			return busquedaABB(apnodo->izq,dato);
		}
	}else{
		if(dato>apnodo->info){
    		if(apnodo->der==NULL){
    		cout<<"La informacion no se encuentra en el arbol\n";
			}else{
			return busquedaABB(apnodo->der,dato);
			}
		}else{
			cout<<"La informacion esta en el arbol\n";
		}	
	}
}
//modo de busqueda recursiva, valida tambien si el arbol binario esta vacia
bool Arbol::busquedaABB2(Nodo* apnodo, int dato)
{
    if(apnodo != NULL){
        if(dato < apnodo->info){
            return busquedaABB2(apnodo->izq, dato);
        } else {
            if(dato > apnodo->info){
                return busquedaABB2(apnodo->der, dato);
            } else {
                // cout << "La informacion se encuentra en el arbol";
                return true;
            }
        }
    } else {
        // cout << "La informacion no se encuentra en el arbol";
        return false;
    }
}
//modo de busqueda iterativa
void Arbol::busquedaABBIterativa(Nodo* apnodo, int dato){
	while(apnodo!= NULL && apnodo->info!=dato){
		if(apnodo->info>dato){
			apnodo=apnodo->izq;
		}else{
			apnodo=apnodo->der;
		}
	}
	
	if(apnodo!=NULL){
		cout<<"La informacion se encuentra en el arbol\n";
	}else{
		cout<<"La informacion No se encuentra en el arbol\n";
	}
}

//metodo para hallar el maximo subarbvol de un arbol binario
void Arbol::maximoArbol(Nodo* apnodo){
	if(apnodo->der==NULL){
		cout<<"VALOR MAXIMO: "<<apnodo->info<<endl;
	}else{
		return maximoArbol(apnodo->der);
	}
}

void Arbol::minimoArbol(Nodo *apnodo){
	if(apnodo->izq==NULL){
		cout<<"VALOR MINIMO: "<<apnodo->info<<endl;
	}else{
		return maximoArbol(apnodo->izq);
	}
}

//metodo para elimnar un subarbol de un arbol binario
void Arbol::eliminarABB(Nodo*& apnodo, int dato){
	bool BO;
	if(apnodo!=NULL){
		if(dato<apnodo->info){
			return eliminarABB(apnodo->izq, dato);
		}else{
			if(dato>apnodo->info){
				return eliminarABB(apnodo->der, dato);
			}else{
				Nodo* otro,*AUX, *AUX1=new Nodo();
				otro=apnodo;
				if(otro->der==NULL){
					apnodo=otro->izq;
				}else{
					if(otro->izq==NULL){
						apnodo=otro->der;
					}else{
						AUX=apnodo->izq;
						BO=false;
						while(AUX->der!=NULL){
							AUX1=AUX;
							AUX=AUX->der;
							BO=true;
						}
						apnodo->info=AUX->info;
						otro=AUX;
							if(BO){
								AUX1->der=AUX->izq;
							}else{
								apnodo->izq=AUX->izq;
							}
					}
					delete(otro);
				}
			}
		}
		
	}else{
		cout<<"La informacion a eliminar no se encuentra en el arbol\n";
		return;
	}
}

//funcion independiente de remover raiz
Nodo* removerRaiz(Nodo* raizActual) {
    Nodo *padre, *reemplazo;
    if (raizActual == NULL) return NULL;

    if (raizActual->izq == NULL) {
        reemplazo = raizActual->der;
        delete raizActual;
        return reemplazo;
    }

    padre = raizActual;
    reemplazo = raizActual->izq;

    while (reemplazo->der != NULL) {
        padre = reemplazo;
        reemplazo = reemplazo->der;
    }

    if (padre != raizActual) {
        padre->der = reemplazo->izq;
        reemplazo->izq = raizActual->izq;
    }

    reemplazo->der = raizActual->der;
    delete raizActual;
    return reemplazo;
}

//funcion que elimine todos los nodos del arbol
void Arbol::podarArbol(Nodo*& apnodo){
	if(apnodo!=NULL){
		podarArbol(apnodo->izq);
		podarArbol(apnodo->der);
		delete apnodo;
		apnodo=NULL;
	}
	
}
void menu(){
	Arbol arbol;
	Nodo *&raiz= arbol.regresaRaiz();
	//Nodo *raiz=NULL;
	int op, dato;
		do{
			system("cls");
			cout<<"\tMENU DE OPCIONES - ARBOLES BINARIO"<<endl
				<<"1.- Insertar nodo (insertaNodo)"<<endl
				<<"2.- Insertar nodo (insertaNodo2)"<<endl
				<<"3.- Insertar nodo (InsertarNodoIteterativo)"<<endl
				<<"4.- Mostrar arbol (forma estructurada)"<<endl
				<<"5.- Recorrido en Preorden"<<endl
				<<"6.- Recorrido en Inorden"<<endl
				<<"7.- Recorrido en Posorden"<<endl
				<<"8.- Buscar dato(busquedaABB)"<<endl
				<<"9.- Buscar dato(busquedaABB2)"<<endl
				<<"10.- Buscar dato(busquedaIterativa)"<<endl
				<<"11.- Altura del arbol"<<endl
				<<"12.- Contar todos los nodos"<<endl
				<<"13.- Contar nodos hojas"<<endl
				<<"14.- Maximo valor"<<endl
				<<"15.- Minimo Valor"<<endl
				<<"16.- EliminarABB"<<endl
				<<"17.- Remover Raiz"<<endl
				<<"18.- Podar Arbol(eliminar todo los nodos)"<<endl
				<<"SALIR"<<endl;
			cout<<"Ingrese la opcion: "; cin>>op;
			
				switch(op){
					case 1:
						system("cls");
						cout<<"Ingrese dato a insertar (insertarNodo): ";
						cin>>dato;
						if(raiz==NULL){
							raiz=new Nodo{dato,NULL,NULL};
						}else{
							arbol.insertarNodo(raiz,dato);
						}
						system("pause")
;						break;
					case 2:
						system("cls");
						cout<<"Ingrese dato a insertar (insertaNodo2): ";
						cin>>dato;
						arbol.insertarNodo2(raiz,dato);
						system("pause");
						break;
					case 3:
						system("cls");
						cout<<"Ingrese dato a insertar (insertarNodoIterativo): ";
						cin>>dato;
						arbol.insertarNodoIterativo(raiz,dato);
						system("pause");
						break;	
					case 4:
						system("cls");
						if(raiz==NULL)
						cout<<"El arbol esta vacia\n";
						else
							arbol.muestraArbol(raiz,0);
							system("pause");
						 break;
					case 5:
						system("cls");
						if(raiz==NULL)
						cout<<"El arbol esta vacia\n";
						else{
							cout<<"Recorrido Preorden: ";
							arbol.preorden(raiz);
							cout<<endl;
						}
						system("pause");
						break;
					case 6:
						system("cls");
						if(raiz==NULL)
						cout<<"El arbol esta vacia\n";
						else{
							cout<<"Recorrido Inorden: ";
							arbol.inorden(raiz);
							cout<<endl;
						}
						system("pause");
						break;
					case 7:
						system("cls");
						if(raiz==NULL)
						cout<<"El arbol esta vacia\n";
						else{
							cout<<"Recorrido Posorden: ";
							arbol.posorden(raiz);
							cout<<endl;
						}
						system("pause");
						break;
					case 8:
						system("cls");
						cout<<"Ingrese el dato a buscar: ";
						cin>>dato;
						arbol.busquedaABB(raiz,dato);
						system("pause");
						break;
					case 9:
						system("cls");
						cout<<"Ingrese el dato a buscar: ";
						cin>>dato;
						if(arbol.busquedaABB2(raiz,dato))
							cout<<"Dato encontrado en el arbol.\n";
						else
							cout<<"Dato NO encontrado.\n";
							system("pause");
						break;
					case 10:
						system("cls");
						cout<<"Ingrese el dato a buscar: ";
						cin>>dato;
						arbol.busquedaABBIterativa(raiz,dato);
						system("pause");
						break;
										
					case 11:
						system("cls");
						if(raiz==NULL)
							cout<<"El arbol esta vacio.\n";
						else
							cout<<"Altura del arbol: "<<arbol.altura(raiz)<<endl;
							system("pause");
						break;
					case 12:
						system("cls");
						if(raiz==NULL)
							cout<<"El arbol esta vacio.\n";
						else
							cout<<"Cantidad total de nodos: "<<arbol.contarNodos(raiz)<<endl;
							system("pause");
						break;
					case  13:
						system("cls");
						if(raiz==NULL)
							cout<<"El arbol esta vacio.\n";
						else
							cout<<"Cantidad total de nodos HOJA: "<<arbol.contarHojas(raiz)<<endl;
							system("pause");
						break;	
					case 14:
						system("cls");
						arbol.maximoArbol(raiz);
						system("pause");
						break;		
					case 15:
						system("cls");
						arbol.minimoArbol(raiz);
						system("pause")	;
						break;		
					case 16:
						system("cls");
						cout<<"Ingrese el dato a eliminar: ";
						cin>>dato;
						arbol.eliminarABB(raiz,dato);
						system("pause")	;
						break;		
					case 17:
						system("cls");
						if(raiz==NULL){
							cout<<"Arbol binario vacio\n";
						}else{
							raiz=removerRaiz(raiz);
							cout<<"Raiz removida correctamente\n";
						}
						system("pause")	;
						break;		
					case 18:
						system("cls");
							arbol.podarArbol(raiz);
							cout<<"ELIMINADOS CORRECTAMENTE\n";
						system("pause")	;
						break;		
					case 0:
						cout<<"Saliendo del programa....\n";
						break;
					default:
						cout<<"Opcion invalida. Intente nuevamente.\n";								 
				}	
		}while(op !=0);
}

int main(){
	menu();
	return 0;
}
