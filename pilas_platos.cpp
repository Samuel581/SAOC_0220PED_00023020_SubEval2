#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct platosLimpios{
    string material;
    string color;
    bool estado;
};

struct platosSucios{
    string material;
    string color;
    bool estado;
};

typedef struct platosLimpios Limpios;
typedef struct platosSucios Sucios;

int main(){
    int platosAIngresar, opcion=0;
    stack<Limpios> pilaDeLimpios;
    stack<Sucios> pilaDeSucios;

    cout << "Inserte cuantos platos desea ingresar: ";
    cin >> platosAIngresar;

    for(int i=0; i<platosAIngresar;i++){
        Limpios platoLimpio;
        cin.ignore();
        cout << "Material: "; getline(cin, platoLimpio.material);
        cout << "Color: "; getline(cin, platoLimpio.color);
        platoLimpio.estado=true;
        pilaDeLimpios.push(platoLimpio);
        cout << endl;
    }

    cout << "Menu";
    cin >> opcion;

    
    if(opcion==1){
    Limpios platoLimpio;
    Sucios platoSucio;
    platoLimpio=pilaDeLimpios.top();
    platoSucio.color=platoLimpio.color;
    platoSucio.material=platoLimpio.material;
    platoSucio.estado=false;
    pilaDeLimpios.pop();
    }
    else if(opcion==2){
        int cantidadPlatos=0;
        Limpios platoLimpio;
        Sucios platoSucio;
        cout << "Inserte cantidad de platos a ensuciar: ";
        cin >> cantidadPlatos;
        for(int i=0;i<cantidadPlatos;i++){
            platoLimpio=pilaDeLimpios.top();
            platoSucio.color=platoLimpio.color;
            platoSucio.material=platoLimpio.material;
            platoSucio.estado=false;
            pilaDeLimpios.pop();
        }
    }
    else if(opcion==3){
        Limpios platoLimpio;
        Sucios platoSucio;
        platoSucio=pilaDeSucios.top();
        platoLimpio.color=platoSucio.color;
        platoLimpio.material=platoSucio.material;
        platoLimpio.estado=true;
        pilaDeSucios.pop(); 
    }
    else if(opcion==4){
        int cantidadPlatos=0;
        Limpios platoLimpio;
        Sucios platoSucio;
        cout << "Inserte cantidad de platos a ensuciar: ";
        cin >> cantidadPlatos;
        for(int i=0;i<cantidadPlatos;i++){
            platoSucio=pilaDeSucios.top();
            platoLimpio.color=platoSucio.color;
            platoLimpio.material=platoSucio.material;
            platoLimpio.estado=true;
            pilaDeSucios.pop(); 
        }
    }
    else if(opcion==5){
        while(!pilaDeLimpios.empty()){
            Limpios limpioDeEncima = pilaDeLimpios.top();
            cout << "Plato limpio [" << limpioDeEncima.material;
            cout << " , " << limpioDeEncima.color << "]\n";
            pilaDeLimpios.pop(); // Solo asi puedo recorrer una Pila por ahora 
        }
        
    }
    else if(opcion==6){
        while(!pilaDeLimpios.empty()){
            Sucios sucioDeEncima = pilaDeSucios.top();
            cout << "Plato limpio [" << sucioDeEncima.material;
            cout << " , " << sucioDeEncima.color << "]\n";
            pilaDeSucios.pop();
        }
    }
    

}


