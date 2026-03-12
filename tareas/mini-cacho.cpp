#include <iostream>

// Juego Mini-cacho, programacion secuencial

void ImprimirMarcador(int ronda, int puntajeRonda, int puntajeAcumulado){
	std::cout << "Ronda " << ronda << " | Puntos ganados: " << puntajeRonda << " | Total acumulado: " << puntajeAcumulado << std::endl;
}

bool EsEscalera(short d1, short d2, short d3){
	return d1+1 == d2 && d2+1 == d3;
}

bool EsTrio(short d1, short d2, short d3){
	return d1 == d2 && d2 == d3;
}

int CalcularPuntaje(short d1, short d2, short d3){
	int puntaje = 0;
	if (EsTrio(d1,d2,d3)){
		puntaje = 50;
	} else if (EsEscalera(d1,d2,d3)){
		puntaje = 25;
	} else {
		puntaje += d1+d2+d3;
	}
	return puntaje;
}

void JugarPartida(int cantidadRondas){
	short d1,d2,d3;
	int puntajeRonda = 0;
	int puntajeAcumulado = 0;
	for (int i=1; i<=cantidadRondas; i++){
		std::cout << "\nLanza 3 dados e ingresalos en orden: ";
		std::cin >> d1 >> d2 >> d3;
		puntajeRonda = CalcularPuntaje(d1,d2,d3);
		puntajeAcumulado += puntajeRonda;
		ImprimirMarcador(i,puntajeRonda,puntajeAcumulado);
	}
	std::cout << "\nPuntaje Final: " << puntajeAcumulado << std::endl;
}

int main(){
	int rondas;

	std::cout << "Bienvenido a Mini Cacho!" << std::endl;
	std::cout << "Cuantas rondas desea jugar?: ";
	std::cin >> rondas;

	JugarPartida(rondas);

	return 0;
}
