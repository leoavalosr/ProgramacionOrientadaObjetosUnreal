#include <iostream>
#include <string>

using namespace std;

// Juego piedra, papel o tijera, programacion orientada a objetos
// 1 [] piedra
// 2 () papel
// 3 8< tijera

// variables globales
int rondas = 0;

class Player{
private:
	static int contador;
	int id;

public:
	string nombre;
	string simbolo;
	short opcionJugada;
	int puntos;

	// constructor
	Player(string nom){
		nombre = nom;
		contador += 1;
		id = contador;
		puntos = 0;
	}

	int evaluar(Player &rival){
		if (getJugada() == rival.getJugada()){
			return 0;
		} else if ((getJugada()==1 && rival.getJugada()==3) || (getJugada()==2 && rival.getJugada()==1) || (getJugada()==3 && rival.getJugada()==2)){
			return 1;
		} else {
			return -1;
		}
	}

	void seleccionar(){
		short j;
		cout << nombre << ", elija (1: Piedra, 2: Papel, 3: Tijera): ";
		cin >> j;
		setJugada(j);
	}
	string traducir(){
		if (opcionJugada == 1){
			simbolo = "()";
		} else if (opcionJugada == 2){
			simbolo = "[]";
		} else if (opcionJugada == 3){
			simbolo = "8<";
		}
		return simbolo;
	}

	void setJugada(short j){
		opcionJugada = j;
	}

	short getJugada(){
		return opcionJugada;
	}

	float obtenerEficiencia(int rondasJugadas){
		return static_cast<float>(puntos) / rondasJugadas *100;
	}

	void jugar(Player &rival){
		// Mensaje indicar simbolos
		cout << "\n" << nombre << " " << traducir() << " VS " << rival.nombre << " " << rival.traducir() << endl;

		int resultado = evaluar(rival);
		if (resultado == 0){
			cout<<">>> RESULTADO: ¡Empate tecnico!"<<endl;
		} else if (resultado == 1){
			cout<<">>> RESULTADO: ¡"<<nombre<<" gana la ronda!"<<endl;
			puntos += 1;
		} else if (resultado == -1){
			cout<<">>> RESULTADO: ¡"<<rival.nombre<<" gana la ronda!"<<endl;
			rival.puntos += 1;
		}
	}
	
	void imprimir(){
		cout<<id<<". "<<nombre<<"  : "<< obtenerEficiencia(rondas)<<"%"<<endl;
	}
};
int Player::contador = 0;

int main(){
	Player j1("SubZero");
	Player j2("Scorpion");
	Player j3("Reptile");

	cout<<"Cantidad de rondas: ";
	cin>>rondas;

	cout<<"==========================================="<<endl;
	cout<<"          DUELO DE JUGADORES (POO)"<<endl;
	cout<<"==========================================="<<endl;
	for (int i=1; i<=rondas; i++){

		cout<<"\n[PARTIDA "<<i<<": "<<j1.nombre<<" vs "<<j2.nombre<<"]"<<endl;

		j1.seleccionar();
		j2.seleccionar();
		j1.jugar(j2);
	}

	cout<<"\n-------------------------------------------"<<endl;
	cout<<"RESUMEN DE EFICIENCIA (Tras "<<rondas<<" Partidas):"<<endl;
	cout<<"-------------------------------------------"<<endl;
	j1.imprimir();
	j2.imprimir();
	j3.imprimir();
	cout<<"==========================================="<<endl;

	return 0;
}
