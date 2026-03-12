#include <iostream>

// https://github.com/toitolucho/Learning-Game-Development-with-POO/tree/main/19%20Pieza%20Torre%20Ajedrez%20POO 

using namespace std;

class Torre{
private:
	int fila;
	int columna;
	bool esNegra;

public:

	Torre(bool negra, int nFila, int nCol){
		esNegra = negra;
		fila = nFila;
		columna = nCol;
	}

	string dibujar(){
		if (esNegra){
			return "[##]";
		} else {
			return "[TT]";
		}
	}
	bool validarMovimiento(int nFila, int nCol){
		if (fila == nFila || columna == nCol){
			return true;
		} else {
			return false;
		}
	}
	void mover(int nFila, int nCol){
		cout<<"\n>>> PROCESANDO..."<<endl;
		if ((nFila>8 || nCol>8) || (nFila<1 || nCol<1)){
			cout<<">>> MOVIMIENTO INVALIDO: Movimiento fuera del tablero"<<endl;
			return;
		}
		if (validarMovimiento(nFila, nCol)){
			fila = nFila;
			columna = nCol;
			cout<<">>> MOVIMIENTO EXITOSO: "<<dibujar()<<" se ha desplazado."<<endl;
		} else {
			cout<<">>> MOVIMIENTO INVALIDO: Movimiento diagonal no permitido para la Torre"<<endl;
		}
	}
	void imprimirEstado(){
		string color = "Blanca";
		if (esNegra){
			color = "Negra";
		}
		cout<<dibujar()<<" "<<color<<" en fila: "<<fila<<", Col: "<<columna<<endl;
	}
};

int main(){
	Torre t1(false, 1, 1), t2(true, 8,8);
	int nFila,nCol;

	cout << "\n===========================================" << endl;
	cout << "          SISTEMA DE CONTROL: TORRE        " << endl;
	cout << "===========================================" << endl;
	cout << "[ESTADO ACTUAL DEL TABLERO]" << endl;
	cout << "Pieza 1: ";
	t1.imprimirEstado();
	cout << "Pieza 2: ";
	t2.imprimirEstado();

	cout << "\n-------------------------------------------" << endl;
	cout << "MOVIMIENTO: Torre Blanca " << t1.dibujar() << endl;
	cout << "-------------------------------------------" << endl;
	cout<<"Introduzca nueva Fila (1-8): ";
	cin>>nFila;
	cout<<"Introduzca nueva Columna (1-8): ";
	cin>>nCol;
	t1.mover(nFila, nCol);

	cout<<"\n-------------------------------------------"<<endl;
	cout<<"[NUEVO ESTADO DEL TABLERO]"<<endl;
	cout<<"Pieza 1: ";
	t1.imprimirEstado();
	cout<<"Pieza 2: ";
	t2.imprimirEstado();
	cout<<"==========================================="<<endl;

	return 0;
}
