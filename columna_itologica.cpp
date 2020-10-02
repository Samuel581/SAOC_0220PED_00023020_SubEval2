#include <iostream>

using namespace std;

struct perfilSuelo{
    string tipo;
    float grosor=-1;
    float dureza=-1;
};

typedef struct perfilSuelo Perfil;

struct nodo{
    Perfil elemento;
    struct nodo *siguiente;
};

typedef struct nodo *Pila;

void initialize(Pila *s);
bool empty(Pila *s);
void push(Pila *s, Perfil e);
Perfil pop(Pila *s);
Perfil top(Pila *s);
int size(Pila *s);
void promedio(Pila *s, int n);

int main(){
    Pila capa;

    initialize(&capa);

    bool continuar = true;
    do{
        int opcion = 0;
        cout << "1- Añadir una capa" << endl << "2-Eliminar una capa" << endl << "3-Eliminar todas las capas" << endl << "4-Sacar promedio de dureza y finalizar" <<endl << "5-Salir" << endl << ">>> ";

        cin >> opcion;
        
        if(opcion == 1){
            Perfil unaCapa;
            cin.ignore();
            cout << "Tipo de suelo: ";getline(cin, unaCapa.tipo);
            while(unaCapa.grosor<=0){
                cout << "Grosor: ";cin >> unaCapa.grosor;
            }
            cin.ignore();
            while(unaCapa.dureza<=0){
                cout << "Dureza: ";cin >> unaCapa.dureza;
            }
            push(&capa, unaCapa);
        }
        else if(opcion==2){
            pop(&capa);
        }
        else if(opcion==3){
            while(!empty(&capa)){
                pop(&capa);
            }
        }
        else if(opcion == 4){
            int n=size(&capa);
            promedio(&capa, n);

        }
        else if(opcion == 5){
            continuar = false;
        }
        else
            cout << "Opcion no valida!" << endl;
    }while(continuar);
    return 0;
}

void initialize(Pila *s){
    *s = NULL;
}

bool empty(Pila *s){
    return *s == NULL;
}

void push(Pila *s, Perfil e){
    struct nodo *unNodo = new struct nodo;
    unNodo->elemento = e;
    unNodo->siguiente = *s;
    *s = unNodo;
}

Perfil pop(Pila *s){
    if(!empty(s)){
        struct nodo *unNodo = *s;
        Perfil e = (*s)->elemento;
        *s = (*s)->siguiente;
        delete(unNodo);
        return e;
    }
    else // Underflow!
        cout << "Error, datos vacios" << endl;
}

int size(Pila *s){
    struct nodo *unNodo = *s;
    int i=0;
    while(!empty(&unNodo)){
        i++;
        unNodo=(unNodo)->siguiente;
    };
    return i;
}

void promedio(Pila *s, int n){// Nada mas logre hacer una que sacaba promedio pero la elimina a la vez :(
    float promedio=0, suma=0;
    if(empty(s)){
        cout << "Error, datos vacios" << endl;
    }
    while(!empty(s)){
        float elemento=0;
        struct nodo *unNodo = *s;
        elemento=(*s)->elemento.dureza;
        suma+=elemento;
        pop(&*s);
    }
    if(empty(s)){
        promedio=suma/n;
        cout <<  promedio << endl; 
    }
    
}
