#include <iostream>

// https://github.com/toitolucho/Learning-Game-Development-with-POO/tree/main/14%20Cuenta%20Bancaria%20POO%20Basic

using namespace std;

class CuentaBancaria{
private:
	int id;
	string nroCuenta;
	double saldo;
public:
	string propietario;

	// constructor
	CuentaBancaria(int i, string nro, string prop){
		id = i;
		nroCuenta = nro;
		propietario = prop;
		saldo = 0;
	}

	void depositar(double monto){
		if (monto <= 0){
			cout<<"No se procesan montos negativos o nulos"<<endl;
			return;
		}
		saldo += monto;
		cout<<"Deposito en cuenta "<<propietario<<": CONFIRMADO"<<endl;
	}
	bool retirar(double monto){
		if (monto > 0 && monto <= saldo){
			saldo -= monto;
			cout<<"Retiro de cuenta "<<propietario<<": CONFIRMADO"<<endl;
			return true;
		} else {
			cout<<"No puede retirar esa cantidad"<<endl;
			return false;
		}
	}
	void transferir(CuentaBancaria &destino, double monto){
		cout<<"\nEJECUTANDO TRANSFERENCIA... Monto solicitado: $"<<monto<<endl;
		if (this == &destino){
			cout<<"No puede transferir a si mismo"<<endl;
			return;
		}

		if (retirar(monto)){
			destino.depositar(monto);
			cout<<"Resultado: Operacion completada con exito."<<endl;
		}
	}
	void verEstado(){
		cout<<"Cuenta "<<nroCuenta;
		cout<<" | Titular: "<<propietario;
		cout<<" | Saldo: $"<<saldo<<endl;
	}
};

int main () {
	CuentaBancaria cuentaA(1, "001", "Juan Perez");
	CuentaBancaria cuentaB(2, "002", "Marta Rojas");

	cuentaA.depositar(1000);

	cout<<"\nESTADO INICIAL:"<<endl;
	cuentaA.verEstado();
	cuentaB.verEstado();

	cuentaA.transferir(cuentaB, 450);

	cout<<"\nESTADO FINAL:"<<endl;
	cuentaA.verEstado();
	cuentaB.verEstado();

	return 0;
}
