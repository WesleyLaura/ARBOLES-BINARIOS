#include <iostream>
#include <iomanip> 
#include <windows.h>

using namespace std;


class Nodo {
public:
    string info;
    Nodo* izq;
    Nodo* der;
};

class Arbol {
private:
    Nodo* raiz;

public:
    Arbol();

    Nodo* regresaRaiz();

    void insertarNodo(Nodo*& apnodo, string dato);


	string maximo(Nodo*);
	string minimo(Nodo*);
    void muestraArbol(Nodo* apnodo, int nivel);


    void inorden(Nodo* apnodo);

};

Arbol::Arbol() {
    raiz = NULL;
}

Nodo* Arbol::regresaRaiz() {
    return raiz;
}

void Arbol::insertarNodo(Nodo*& apnodo, string dato) {
    if (apnodo != NULL) {
        if (dato < apnodo->info) {
            insertarNodo(apnodo->izq, dato);
        } else if (dato > apnodo->info) {
            insertarNodo(apnodo->der, dato);
        } else {
            cout << "La información ya se encuentra en el árbol." << std::endl;
        }
    } else {
        Nodo* otro = new Nodo;
        otro->info = dato;
        otro->izq = NULL;
        otro->der = NULL;
        apnodo = otro;
    }
}






string Arbol::maximo(Nodo* apnodo){
	if(apnodo == NULL){
		return "";
	}
	if(apnodo->der == NULL){
		return apnodo->info;
	}
	return maximo(apnodo->der);
	
}
string Arbol::minimo(Nodo* apnodo){
	if(apnodo == NULL){
		return "";
	}
	if(apnodo->izq == NULL){
		return apnodo->info;
	}
	return minimo(apnodo->izq);
	
}


void Arbol::muestraArbol(Nodo* apnodo, int nivel) {
    if (apnodo != NULL) {
        muestraArbol(apnodo->der, nivel + 1);
        for (int i = 0; i < nivel; i++)
            cout << "                  ";
        cout << apnodo->info << endl;
        muestraArbol(apnodo->izq, nivel + 1);
    }
}


void Arbol::inorden(Nodo* apnodo) {
    if (apnodo != NULL) {
        inorden(apnodo->izq);
        cout << apnodo->info << "-";
        inorden(apnodo->der);
    }
}


int main() {
	SetConsoleOutputCP(CP_UTF8);
    Arbol arbol;
    Nodo* raiz = arbol.regresaRaiz();
    string signos[] = {"piscis","acuario","capricornio","cancer","sagitario","virgo" ,"leo" , "escorpión", "libra" , "géminis" , "aries" , "tauro"};
    for (int i = 0; i < 12; i++) {
		arbol.insertarNodo(raiz, signos[i]);
    }

    
    
    cout << "\nÁrbol (vista en consola):\n";
    arbol.muestraArbol(raiz, 0);

    cout << "\nRecorrido Inorden:\n\n";
    arbol.inorden(raiz);
	cout<<"\n";
    
    cout << "\nMAXIMO: "<<arbol.maximo(raiz)<<endl;
    cout<<"\n";
	cout << "\nMINIMO: "<<arbol.minimo(raiz)<<endl;
    return 0;
}
