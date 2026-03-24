#include <iostream>
using namespace std;

#include <random>

class Player{
public:
	short jugada;
	int puntaje;
	string nombre;

	void seleccionar(){
		cout<<"Introduzca su opcion: ";
		cin>>jugada;
	}
};

class PlayerPc : public Player{
public:
	void seleccionar(){
		random_device rd;  // semilla aleatoria
		mt19937 gen(rd()); // generador Mersenne Twister
		uniform_int_distribution<> dist(1, 3); // rango
		
		int numero = dist(gen);
		jugada = numero;
	}
};

int main () {
	Player p1;
	PlayerPc p2;
	for (int i=0; i<1; i++){
		p1.seleccionar();
		p2.seleccionar();
	}

	cout<<"Jugada de player 1: "<<p1.jugada<<endl;
	cout<<"Jugada de player 2 (PC): "<<p2.jugada<<endl;

	return 0;
}
