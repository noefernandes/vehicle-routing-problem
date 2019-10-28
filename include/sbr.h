#ifndef SBR_H
#define SBR_H

#include <vector>
#include <iostream>

const int BusCapacity =  1000; 

struct Pair{
	int leftVertex;
	int rightVertex;
	double saved;

	Pair(){
		leftVertex = -1;
		rightVertex = -1;
		saved = 0;
	}
};

class SBR{
	
	public:

		//Construtor.
		SBR(int n){
			//Alocando a matriz  de adjacência.
			V = n;
			double** ma = new double*[V];
			for(auto i(0); i < V; i++){
				ma[i] = new double[V];
				for(auto j(0); j < V; j++){
					ma[i][j] = 0;
				}
			}

			m = ma;			

			//Alocando vetor de cargas.
			int *Ca = new int[V];
			for(auto i(0); i < V; i++){
				Ca[i] = 0;
			}

			C = Ca; 

			//Colocando numero de rotas.
			routes.resize(3);
		}

		//Destrutor.
		~SBR(){
			for(auto i(0); i < V; i++){
				delete[] m[i];
			}
			delete m;			
		}

	/*********************************************** FUNÇÕES DE MANIPULAÇÃO DO GRAFO *********************************************/
	//Retorna a matriz de adjacência.
	double** getAdjacencyMatrix(void);
	//Insere uma aresta no grafo.
	void insertEdge(int a, int b, double cost);
	//Remove uma aresta do grafo.
	void removeEdge(int a, int b);
	//Retorna o vértice adjacente de menor custo.
	int smallestAdjacentVertex(int a);
	//Retorna o custo do aresta.
	double getEdgeCost(int a, int b);
	//Realiza a leitura pelo da carga de alunos por parada.
	void loadStudentsPerStop(std::string filename);
	//Eurística de Clark & Wright na versão sequencial: encontra as rotas que cada ônibus percorrerá.
	void clarkeAndWright(void);

	/***************************************************** FUNÇÕES DE AUXÍLIO ****************************************************/
	//Mostra o estado do grafo.
	void showGraph(void);
	void showStudentsPerStop(void);
	double getRouteDistance(int i);
	int getNumberOfStops(int i);
	double getWeight(int i);
	bool cicleTimeIsCorrect(double cicleTime, int vertex, int mode, int i);
	bool weightIsCorrect(double weightTotal, int vertex, int i);


	private:
		//Matriz de adjacência contendo as distâncias entre os vértices (não adjcência representada pelo valor 0).
		double** m;
		//Número de vértices.
		int V;
		//Número de ônibus. 
		int numberOfBus = 3;
		//Carga a ser coletada (Número de alunos nas paradas).
		int* C;
		//Vector com todas as rotas formadas.
		std::vector<std::vector<int>> routes;
};

#endif