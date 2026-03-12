#include <iostream>
#include <string>

// Juego piedra, papel o tijera, programacion secuencial
// 1 [] piedra
// 2 () papel
// 3 8< tijera

int main(){
	int j1,j2;
	std::string simJ1,simJ2,simJ3;

	std::cout<<"Introduzca la opcion del jugador 1: ";
	std::cin>>j1;

	std::cout<<"Introduzca la opcion del jugador 2: ";
	std::cin>>j2;

	// Asignacion de simbolos: jugador 1
	if (j1 == 1){
		simJ1 = "()";
	} else if (j1 == 2){
		simJ1 = "[]";
	} else if (j1 == 3){
		simJ1 = "8<";
	}

	// Asignacion de simbolos: jugador 2
	if (j2 == 1){
		simJ2 = "()";
	} else if (j2 == 2){
		simJ2 = "[]";
	} else if (j2 == 3){
		simJ2 = "8<";
	}

	// Fase de salida visual
	std::cout << simJ1 << " VS " << simJ2 << std::endl;

	// Fase de evaluación lógica
	if (j1 == j2){
		std::cout << "EMPATE" << std::endl;
	} else if ((j1 == 1 && j2 == 3) || (j1 == 2 && j2 == 1) || (j1 == 3 && j2 == 2)){
		std::cout << "GANO EL JUGADOR 1" << std::endl;
	} else {
		std::cout << "GANO EL JUGADOR 2" << std::endl;
	}

	return 0;
}
