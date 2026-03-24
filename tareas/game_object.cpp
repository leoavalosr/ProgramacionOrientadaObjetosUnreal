#include <iostream>
#include <string>

using namespace std;

// declaracion anticipada para poder usar en GameScene
class GameObject;

class GameScene{
public:
	int ancho;
	int alto;
	int num_objetos = 0;
	GameObject* objetos[50];

	// Constructores
	GameScene(){
		ancho = alto = 10;
	}
	GameScene(int ancho0, int alto0){
		ancho = ancho0;
		alto = alto0;
	}

	void añadirObjeto(GameObject* objeto){
		if (num_objetos < 50){
			objetos[num_objetos] = objeto;
			num_objetos++;
		}
	}
	void listaObjetos();
};
GameScene escenario(20, 10);

class GameObject{
public:
	float x;
	float y;

	// Constructores
	GameObject(){
		x = y = 0;
		escenario.añadirObjeto(this);
	}
	GameObject(int x0, int y0){
		x = x0;
		y = y0;
		escenario.añadirObjeto(this);
	}

	void imprimir(){
		cout<<"["<<x<<", "<<y<<"]"<<endl;
	}
	void resetTo(char dir){
		if (dir == 'N'){
			x = 0;
			y = escenario.alto/2;
		} else if (dir == 'S'){
			x = 0;
			y = -(escenario.alto/2);
		} else if (dir == 'E'){
			x = escenario.ancho/2;
			y = 0;
		} else if (dir == 'O'){
			x = -(escenario.ancho/2);
			y = 0;
		}
	}
	void moverA(char dir, float unidades){
		if (dir == 'N'){
			x += unidades;
		} else if (dir == 'S'){
			x -= unidades;
		} else if (dir == 'E'){
			y += unidades;
		} else if (dir == 'O'){
			y -= unidades;
		}
	}
};

// Implementado despues de GameObject para acceder a sus metodos
void GameScene::listaObjetos(){
	for (int i=0; i<num_objetos; i++){
		cout<<"  "<<i+1<<". coords: ";
		objetos[i]->imprimir();
	}
}


int main () {
	GameObject ob1, ob2;
	GameObject *pob1, *pob2;

	pob1 = new GameObject(3,4);
	pob2 = &ob2;

	cout<<">>> INFORMACION DEL ESCENARIO"<<endl;
	cout<<"Tamaño del escenario: "<<escenario.ancho<<"x"<<escenario.alto<<endl;
	cout<<"Cantidad de objetos: "<<escenario.num_objetos<<endl;
	cout<<"Lista de objetos: "<<endl;
	escenario.listaObjetos();

	cout<<"\nRotar 3er objeto en sentido horario"<<endl;
	pob1->resetTo('N'); pob1->imprimir();
	pob1->resetTo('E'); pob1->imprimir();
	pob1->resetTo('S'); pob1->imprimir();
	pob1->resetTo('O'); pob1->imprimir();

	cout<<"\nRotar 2do objeto sentido anti horario"<<endl;
	char dir[4] = {'N','O','S','E'};
	for (int i=0; i<4; i++){
		pob2->resetTo(dir[i]);
		pob2->imprimir();
	}

	cout<<"\nMover el objeto x unidades hacia una direccion: "<<endl;
	cout<<"Estado inicial: "; ob1.imprimir();
	cout<<"Mover 5 unidades al Norte: ";
	ob1.moverA('N', 5);
	ob1.imprimir();
	cout<<"Mover 3 unidades al Oeste: ";
	ob1.moverA('O', 3);
	ob1.imprimir();


	cout<<"\nMover 1 a 100 unidades hacia el norte"<<endl;
	ob1.x = ob1.y = 0;
	cout<<"Estado inicial: "; ob1.imprimir();
	for (int u=1; u<=100; u++){
		ob1.moverA('N', u);
		ob1.imprimir();
	}

	return 0;
}
