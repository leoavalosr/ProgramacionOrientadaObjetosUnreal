#include <iostream>
using namespace std;

bool enLimiteCombustible(int combustible){
	bool valido = false;
	if (combustible>=0 && combustible<=100){
		valido = true;
	}
	return valido;
}


class AutoBus {
private:
	float combustible;
	int pasajeros;
	int capacidadTanque = 50;

public:
	int asientos;
	float tarifa;

	// constructores
	AutoBus(){
		combustible = 0;
		asientos = 50;
		tarifa = 1.0;
		pasajeros = 0;
	}
	AutoBus(int comb){
		if (enLimiteCombustible(comb)){
			combustible = comb;
		} else {
			cout<<"Combustible maximo 100"<<endl;
		}
	}
	AutoBus(int comb, int asi, float tar){
		combustible = comb;
		asientos = asi;
		tarifa = tar;
		pasajeros = 0;
	}
	AutoBus(int asi, float tar){
		combustible = 250;
		asientos = asi;
		tarifa = tar;
		pasajeros = 0;
	}
	// crear un constructor que configure el tamanio y el prcio del bus asumiendo que se tiene 250 combustible y la tarifa de 3

	void imprimir(){
		cout<<endl;
		cout<<"Combustible: "<<combustible<<endl;
		cout<<"Tarifa: "<<tarifa<<endl;
		cout<<"Nro pasajeros: "<<pasajeros<<endl;
		cout<<"Asientos totales: "<<asientos<<endl;
		cout<<"Asientos libres: "<<calcularAsientosLibres()<<endl;
	}

	void cargarCombustible(float cantidad){
		cout<<"\nCargando combustible..."<<endl;
		if (combustible+cantidad > capacidadTanque){
			combustible = capacidadTanque;
		} else {
			combustible += cantidad;
		}
	}

	void recogerPasajeros(int masPasajeros){
		cout<<"\nRecogiendo pasajeros..."<<endl;
		if (pasajeros+masPasajeros > asientos){
			pasajeros = asientos;
		} else {
			pasajeros += masPasajeros;
		}
	}

	int calcularAsientosLibres(){
		return asientos-pasajeros;
	}

	float calcularPagoLLenarTanque(float precio_litro){
		return precio_litro*(capacidadTanque-combustible);
	}

	int getCombustible(){
		return combustible;
	}
	int getPasajeros(){
		return pasajeros;
	}

	void setCombustible(int comb){
		combustible = comb;
	}
	void setPasajeros(int pas){
		pasajeros = pas;
	}

};

int main(){
	AutoBus bus1;
	bus1.imprimir();

	bus1.cargarCombustible(20);
	bus1.recogerPasajeros(2);
	float costoAPagar = bus1.calcularPagoLLenarTanque(3.5);

	bus1.imprimir();

	return 0;
}
