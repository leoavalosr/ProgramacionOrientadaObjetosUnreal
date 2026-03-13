#include <iostream>
using namespace std;

// https://github.com/toitolucho/Learning-Game-Development-with-POO/tree/main/05%20AutoBus

class AutoBus {
private:
	double combustible;
	int pasajeros;
	int capacidadTanque = 100;
	int pasajerosBajaron = 0;

public:
	int asientos;
	double tarifa;

	// constructores
	AutoBus(){
		combustible = 0;
		asientos = 50;
		tarifa = 1.0;
		pasajeros = 0;
	}
	AutoBus(int comb){
		if (comb <= capacidadTanque){
			combustible = comb;
		} else {
			cout<<"La capacidad maxima es de "<<capacidadTanque<<" litros"<<endl;
		}
	}
	AutoBus(int comb, int asi, float tar){
		if (comb > capacidadTanque){
			cout<<"La capacidad maxima es de "<<capacidadTanque<<" litros"<<endl;
			return;
		}
		combustible = comb;
		asientos = asi;
		tarifa = tar;
		pasajeros = 0;
	}

	bool esCantidadNegativa(double num){
		return num<0;
	}

	void imprimir(){
		cout<<"\n-------------------------------"<<endl;
		cout<<"INFORMACION DEL BUS"<<endl;
		cout<<"-------------------------------"<<endl;
		cout<<"Nro pasajeros: "<<pasajeros<<endl;
		cout<<"Asientos: "<<asientos<<endl;
		cout<<"Asientos libres: "<<calcularCantidadAsientosDisponibles()<<endl;
		cout<<"Tarifa: "<<tarifa<<endl;
		cout<<"Combustible: "<<combustible<<endl;
		cout<<"-------------------------------"<<endl;
	}

	void cargarCombustible(float cantidad){
		if (esCantidadNegativa(cantidad))
			return;
		cout<<"\nCargando combustible..."<<endl;
		if (combustible+cantidad > capacidadTanque){
			cantidad = capacidadTanque-combustible;
		}
		combustible += cantidad;
		cout<<cantidad<<" litros recargados"<<endl;
	}
	void recogerPasajeros(int subenPasajeros){
		if (esCantidadNegativa(subenPasajeros))
			return;
		cout<<"\nRecogiendo pasajeros..."<<endl;
		int asientosDisponibles = calcularCantidadAsientosDisponibles();
		if (subenPasajeros > asientosDisponibles){
			subenPasajeros = asientosDisponibles;
		}
		pasajeros += subenPasajeros;
		cout<<subenPasajeros<<" pasajeros recogidos"<<endl;
	}

	int calcularCantidadAsientosDisponibles(){
		return asientos-pasajeros;
	}
	bool hayEspacio(){
		return calcularCantidadAsientosDisponibles() > 0;
	}
	bool estaVacio(){
		return pasajeros==0;
	}
	float calcularPagoLLenarTanque(float precio_litro){
		return precio_litro*(capacidadTanque-combustible);
	}

	float calcularMontoRecaudado(){
		return (pasajeros+pasajerosBajaron)*tarifa;
	}

	void bajarPasajeros(int bajanPasajeros){
		if (bajanPasajeros > pasajeros)
			return;
		pasajeros -= bajanPasajeros;
		pasajerosBajaron += bajanPasajeros;
	}

	int getCombustible(){
		return combustible;
	}
	int getPasajeros(){
		return pasajeros;
	}
};

int main(){
	AutoBus bus1(50, 40, 2.5);
	bus1.imprimir();

	bus1.recogerPasajeros(15);
	cout<<"Hay espacio?: "<<(bus1.hayEspacio() ? "si" : "no")<<endl;
	bus1.cargarCombustible(20);
	bus1.cargarCombustible(25);
	bus1.cargarCombustible(30);

	cout<<"\nMonto recaudado: $"<<bus1.calcularMontoRecaudado()<<endl;

	bus1.imprimir();

	return 0;
}
