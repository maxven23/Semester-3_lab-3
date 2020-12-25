#include "Graph.h"


int main() {
	int menu = -1;
	Graph<char, int>* graph = new Graph<char, int>();

	while (true) {
		system("cls");

		cout << "\n\t======================================\n\n";
		cout << "\t1.\tAdd an Edge\n";
		cout << "\t2.\tAdd a Vertex\n";
		cout << "\n";
		cout << "\t3.\tGet an Adjacency Matrix\n";
		cout << "\t4.\tFind minimal distances from a vertex\n";
		cout << "\n";
		cout << "\t5.\tRemove an Edge\n";
		cout << "\t6.\tGet Matrix of Paths\n";
		cout << "\n";
		cout << "\t7.\tGet a visualisation\n";
		cout << "\n";
		cout << "\t8.\tExample Graph #1\n";
		cout << "\t9.\tExample Graph #2\n";

		cout << "\n\t0.\tExit\n";
		cout << "\n\t======================================\n\n\t";
		cin >> menu;

		switch (menu)
		{
		case 1:
		{
			char from;
			char to;
			int weight;

			system("cls");

			cout << "\n\tEnter 'from' Vertex:\t";
			cin >> from;
			cout << "\n\tEnter 'to' Vertex:\t";
			cin >> to;
			cout << "\n\tEnter the Weight of Edge:\t";
			cin >> weight;

			graph->addEdge(from, to, weight);
			system("pause>>void");
			break;
		}

		case 2:
		{
			char name;

			system("cls");

			cout << "\n\tEnter a Vertex:\t";
			cin >> name;

			graph->addVertex(name);
			system("pause>>void");
			break;
		}

		case 3:
		{
			system("cls");

			cout << "\n\n\t     " << "Adjacency Matrix:\n";
			vector<vector<int>> vect = graph->getAdjMatrix();
			ListSequence<Graph<char, int>::Vertex<char>*>* Names = graph->getVetex();
			cout << "\t" << "    ";
			for (int i = 0; i < graph->getVertexCount(); i++) {
				cout << Names->Get(i)->getName() << "    ";
			}
			cout << endl << "\t" << "  ";
			for (int i = 0; i < graph->getVertexCount(); i++) {
				cout << "-----";
			}
			cout << endl;
			for (int i = 0; i < graph->getVertexCount(); i++) {
				cout << "\t" << Names->Get(i)->getName() << " | ";
				for (int j = 0; j < graph->getVertexCount(); j++) {

					cout.width(3);
					cout.setf(ios::left);

					if (vect[i][j] != 9999) {
						cout << vect[i][j] << "  ";
					}
					else {
						cout << "-" << "  ";
					}
				}
				cout << endl;
			}
			system("pause>>void");
			break;
		}

		case 4:
		{
			char from;
			char to;

			system("cls");
			cout << "\n\tEnter a name of Start Vertex:\t";
			cin >> from;
			cout << "\n\tEnter a name of End Vertex:\t";
			cin >> to;

			//cout << "\n\n\t     " << "Min Distances from '" << from << "':";
			graph->dijkstra(from, to);
			system("pause>>void");
			break;
		}

		case 5:
		{
			char from, to;

			system("cls");
			cout << "\n\tEnter 'from' Vertex:\t";
			cin >> from;
			cout << "\n\tEnter 'to' Vertex:\t";
			cin >> to;
			
			graph->removeEdge(from, to);
			system("pause>>void");
			break;
		}

		case 6:
		{
			system("cls");
			graph->getSmallestPaths();
			system("pause>>void");
			break;
		}

		case 7: 
		{
			system("cls");
			string graphAPI;

			ListSequence<Graph<char, int>::Edge<char, int>*>* G = graph->getEdges();
			if (G->GetSize() > 0) {
				ListSequence<Graph<char, int>::Vertex<char>*>* E = graph->getVetex();
				graphAPI = "https://chart.apis.google.com/chart?cht=gv&chl=digraph{";
				for (int i = 0; i < graph->getVertexCount(); i++) {
					graphAPI += E->Get(i)->getName();
					graphAPI += " ";
				}
				string label = "[label=\"";
				for (int i = 0; i < graph->getEdgeCount(); i++) {
					graphAPI += G->Get(i)->getVertex().first->getName();
					graphAPI += "->";
					graphAPI += G->Get(i)->getVertex().second->getName();
					graphAPI += label;
					graphAPI += to_string(G->Get(i)->getWeight());
					graphAPI += "\"] ";
				}
				graphAPI += "}";
			}
			else {
				ListSequence<Graph<char, int>::Vertex<char>*>* E = graph->getVetex();
				graphAPI = "https://chart.apis.google.com/chart?cht=gv&chl=graph{";
				for (int i = 0; i < graph->getVertexCount(); i++) {
					graphAPI += E->Get(i)->getName();
					graphAPI += " ";
				}
				graphAPI += "}";
			}
			
			cout << "\n\n\tGraph Visualisation: \t" << graphAPI << "\n\n\n\t(!JUST COPY AND PASTE AS URL!) \n";
			system("pause>>void");
			break;
		}
		case 8:
		{
			graph->addEdge('A', 'B', 2);
			graph->addEdge('A', 'C', 4);
			graph->addEdge('A', 'D', 3);
			graph->addEdge('B', 'C', 1);
			graph->addEdge('D', 'B', 5);
			graph->addEdge('E', 'A', 4);
			graph->addEdge('E', 'C', 1);
			graph->addEdge('B', 'A', 10);
			break;
		}
		
		case 9:
		{
			graph->addEdge('A', 'B', 1);
			graph->addEdge('A', 'C', 3);
			graph->addEdge('B', 'C', 1);
			graph->addEdge('B', 'E', 5);
			graph->addEdge('C', 'B', 2);
			graph->addEdge('D', 'B', 1);
			break;
		}

		case 0: 
		{
			delete graph;
			exit(0);
		}
		default:
		{
			break;
		}
		}
		
	}

	
	/*
	Graph<char, int>* graph = new Graph<char, int>();
	graph->addEdge('A', 'B', 2);
	graph->addEdge('A', 'C', 4);
	graph->addEdge('A', 'D', 3);
	graph->addEdge('B', 'C', 1);
	graph->addEdge('D', 'B', 5);
	graph->addEdge('E', 'A', 4);
	graph->addEdge('B', 'A', 10);

	ListSequence<Graph<char, int>::Edge<char, int>*>* G = graph->getEdges();
	string graphAPI = "https://chart.apis.google.com/chart?cht=gv&chl=digraph{";
	string label = "[label=\"";
	for (int i = 0; i < graph->getCountEdges(); i++) {
		graphAPI += G->Get(i)->getVertex().first->getName();
		graphAPI += "->";
		graphAPI += G->Get(i)->getVertex().second->getName();
		graphAPI += label;
		graphAPI += to_string(G->Get(i)->getWeight());
		graphAPI += "\"] ";
	}
	graphAPI += "}";
	

	cout << "\n\n\t\t" << "Vertexes:\n";
	graph->returnVertexList();

	cout << "\n\n\t\t" << "Edges:\n";
	graph->returnEdgeList();

	cout << "\n\n\t     " << "Adjacency Matrix:\n";
	vector<vector<int>> vect = graph->getAdjMatrix();
	ListSequence<Graph<char, int>::Vertex<char>*>* Names = graph->vertexList;
	cout << "\t" << "    ";
	for (int i = 0; i < graph->getVertexCount(); i++) {
		cout << Names->Get(i)->getName() << "    ";
	}
	cout << endl << "\t" << "  ";
	for (int i = 0; i < graph->getVertexCount(); i++) {
		cout << "-----";
	}
	cout << endl;
	for (int i = 0; i < graph->getVertexCount(); i++) {
		cout << "\t" << Names->Get(i)->getName() << " | ";
		for (int j = 0; j < graph->getVertexCount(); j++) {
		
			cout.width(3);
			cout.setf(ios::left);
			
			if (vect[i][j] != 9999) {
				cout << vect[i][j] << "  ";
			}
			else {
				cout << "-" << "  ";
			}
		}
		cout << endl;
	}

	cout << "\n\n\t     " << "MIN Distances from 'A':";
	graph->dijkstra('A');

	cout << "\n\n\tGraph Visualisation: \t" << graphAPI << "\n\n\n\t(!JUST COPY AND PASTE AS URL!) \n";
	*/
	return 0;
}



