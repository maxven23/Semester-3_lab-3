#include "Graph.h"
#include "UnderectedGraph.h"

int main() {
	int menu = -1;
	int type = -1;

	while (type == -1) {
		system("cls");
		cout << "\n\tChoose Type of your Graph:";
		cout << "\n\n\t1. Directed";
		cout << "\n\t2. Undirected";
		cout << "\n\n\t";
		cin >> type;
		if (type > 2 || type < 1) {
			type = -1;
		}
	}

	if (type == 1) {
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
				cout << "\n";

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

				if (graph->containsVertex(from) == 1 && graph->containsVertex(to) == 1) {
					cout << "\n\tThere are NO such Vertexes (one or both) in Graph!";
				}
				else {
					cout << "\n\tThere are NO such Vertexes (one or both) in Graph!";
					graph->dijkstra(from, to);
				}
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
				graph->getGraphAPI();
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
				graph->addEdge('A', 'M', 7);
				graph->addEdge('M', 'B', 8);
				graph->addEdge('V', 'G', 6);
				graph->addEdge('V', 'A', 5);
				graph->addEdge('M', 'G', 31);
				graph->addEdge('B', 'R', 1);
				graph->addEdge('R', 'C', 1);
				graph->addEdge('R', 'D', 9);
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
	}
	else {
		UndirectedGraph<char, int>* graph = new UndirectedGraph<char, int>();

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
			ListSequence<UndirectedGraph<char, int>::Vertex<char>*>* Names = graph->getVetex();
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

			if (graph->containsVertex(from) == 1 && graph->containsVertex(to) == 1) {
				cout << "\n\tThere are NO such Vertexes (one or both) in Graph!";
			}
			else {
				cout << "\n\tThere are NO such Vertexes (one or both) in Graph!";
				graph->dijkstra(from, to);
			}
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
			graph->getGraphAPI();
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
			graph->addEdge('A', 'M', 7);
			graph->addEdge('M', 'B', 8);
			graph->addEdge('V', 'G', 6);
			graph->addEdge('V', 'A', 5);
			graph->addEdge('M', 'G', 31);
			graph->addEdge('B', 'R', 1);
			graph->addEdge('R', 'C', 1);
			graph->addEdge('R', 'D', 9);
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
	}

	return 0;
}