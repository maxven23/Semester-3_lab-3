#pragma once
#include "Headers.h"
#include <vector>

template <class Name, class Weight> 
class Graph {
public:
	template <class Name>
	class Vertex {
	private:
		Name name;
	public:
		Vertex(Name name) {
			this->name = name;
		}

		Name getName() {
			return this->name;
		}
	};

	template <class Name, class Weight>
	class Edge {
	private:
		Weight weight;
		Vertex<Name>* from;
		Vertex<Name>* to;
	public:
		Edge(Name first, Name second, Weight weight) {
			this->weight = weight;
			this->from = new Vertex<Name>(first);
			this->to = new Vertex<Name>(second);
		}

		Weight getWeight() {
			return this->weight;
		}

		pair<Vertex<Name>*, Vertex<Name>*> getVertex() {
			return make_pair(from, to);
		}

	};

public:
	Graph() {
		this->edgeList = new ListSequence<Edge<Name, Weight>*>();
		this->vertexList = new ListSequence<Vertex<Name>*>();
	}

	void addVertex(Name name) {
		bool containVertex = false;
		Vertex<Name>* toAdd = new Vertex<Name>(name);

		for (int i = 0; i < this->getVertexCount(); i++) {
			if (this->vertexList->Get(i)->getName() == name) {
				containVertex = true;
				break;
			}
		}

		if (!containVertex) {
			vertexList->Prepend(toAdd);
		}
	}
	void addEdge(Name first, Name second, Weight weight) {

		Edge<Name, Weight>* edgeToAdd = new Edge<Name, Weight>(first, second, weight);

		this->edgeList->Prepend(edgeToAdd);

		int newVertex = 2;
		int whichToAdd = 0;

		Vertex<Name>* firstToAdd = new Vertex<Name>(first);
		Vertex<Name>* secondToAdd = new Vertex<Name>(second);

		bool containFirst = false;
		bool containSecond = false;

		for (int i = 0; i < getVertexCount(); i++) {
			if (this->vertexList->Get(i)->getName() == first) {
				newVertex--;
				containFirst = true;
			}

			if (this->vertexList->Get(i)->getName() == second) {
				newVertex--;
				containSecond = true;
			}
		}

		if (!containFirst) {
			vertexList->Prepend(firstToAdd);
		}
		if (!containSecond) {
			vertexList->Prepend(secondToAdd);
		}
	}

	int containsVertex(Name name) {
		for (int i = 0; i < this->getVertexCount(); ++i) {
			if (this->vertexList->Get(i)->getName() == name) {
				return i;
			}
		}
		return -1;
	}
	int containsEdge(Name first, Name second) {
		for (int i = 0; i < this->getEdgeCount(); ++i) {
			if (this->edgeList->Get(i)->getVertex().first->getName() == first && this->edgeList->Get(i)->getVertex().second->getName() == second) {
				return i;
			}
		}
		return -1;
	}

	void removeEdge(Name first, Name second) {
		if (containsEdge(first, second) != -1) {
			this->edgeList->RemoveAt(containsEdge(first, second));
		}
		else {
			cout << "\n\tThere are no such Edge in Graph!\n";
		}
	}

	// temp. unavailable
	void removeVertex(Name name) {
		if (containsVertex(name) != -1) {

			for (int i = 0; i < this->getEdgeCount(); ++i) {
				if (this->edgeList->Get(i)->getVertex().first->getName() == name) { 
					removeEdge(this->edgeList->Get(i)->getVertex().first->getName(), this->edgeList->Get(i)->getVertex().second->getName());
					i--;
				}
				if (this->edgeList->Get(i)->getVertex().second->getName() == name) {
					removeEdge(this->edgeList->Get(i)->getVertex().second->getName(), this->edgeList->Get(i)->getVertex().first->getName());
					i--;
				}
			}
			this->vertexList->RemoveAt(this->containsVertex(name));
		}
		else {
			cout << "\n\tThere are no such Vertex in Graph!\n";
		}
	}

	void returnEdgeList() {
		for (int i = 0; i < getEdgeCount(); i++) {
			cout << "\t" << i + 1 << ".  (" << this->edgeList->Get(i)->getVertex().first->getName() << " -> " << this->edgeList->Get(i)->getVertex().second->getName() << "): weight - " << this->edgeList->Get(i)->getWeight() << endl;
		}
	}
	void returnVertexList() {
		for (int i = 0; i < getVertexCount(); i++) {
			cout << "\t" << i + 1 << ".  " << vertexList->Get(i)->getName() << endl;
		}
	}

	// Adjacency Matrix
	vector<vector<Weight>> getAdjMatrix() {
		vector<vector<Weight> > matrix(this->getVertexCount(), std::vector<Weight>(this->getVertexCount(), 0));

		for (int i = 0; i < this->getVertexCount(); ++i) {
			for (int j = 0; j < this->getVertexCount(); ++j) {
				matrix[i][j] = 9999;
			}
		}

		for (int i = 0; i < this->getEdgeCount(); ++i) {
			int frst = 0;
			int scnd = 0;
			for (int j = 0; j < this->getVertexCount(); ++j) {
				if (this->edgeList->Get(i)->getVertex().first->getName() == vertexList->Get(j)->getName()) { frst = j; }
				if (this->edgeList->Get(i)->getVertex().second->getName() == vertexList->Get(j)->getName()) { scnd = j;	}
			}
			if (matrix[frst][scnd] > this->edgeList->Get(i)->getWeight()) {
				matrix[frst][scnd] = this->edgeList->Get(i)->getWeight();
			}
		}
		
		for (int i = 0; i < this->getVertexCount(); ++i) {
			matrix[i][i] = 0;
		}

		return matrix;
	}
	
	// Dijkstra
	void dijkstra(char StartVertex, char EndVertex) {

		int startnode;
		int endnode;
		for (int i = 0; i < this->getVertexCount(); i++) {
			if (this->vertexList->Get(i)->getName() == StartVertex) {
				startnode = i;
			}
			if (this->vertexList->Get(i)->getName() == EndVertex) {
				endnode = i;
			}
		}

		vector<vector<Weight>> G = this->getAdjMatrix();
		vector<vector<Weight> > cost(this->getVertexCount(), std::vector<Weight>(this->getVertexCount(), 0));
		vector<Weight> distance(this->getVertexCount()), pred(this->getVertexCount());

		vector<Weight> visited(this->getVertexCount());
		int count, mindistance, nextnode, i, j;
		for (i = 0; i < this->getVertexCount(); i++)
			for (j = 0; j < this->getVertexCount(); j++)
				if (G[i][j] == 0 || G[i][j] == INF)
					cost[i][j] = INF;
				else
					cost[i][j] = G[i][j];
		for (i = 0; i < this->getVertexCount(); i++) {
			distance[i] = cost[startnode][i];
			pred[i] = startnode;
			visited[i] = 0;
		}
		distance[startnode] = 0;
		visited[startnode] = 1;
		count = 1;
		while (count < this->getVertexCount() - 1) {
			mindistance = INF;
			for (i = 0; i < this->getVertexCount(); i++)
				if (distance[i] < mindistance && !visited[i]) {
					mindistance = distance[i];
					nextnode = i;
				}
			visited[nextnode] = 1;
			for (i = 0; i < this->getVertexCount(); i++)
				if (!visited[i])
					if (mindistance + cost[nextnode][i] < distance[i]) {
						distance[i] = mindistance + cost[nextnode][i];
						pred[i] = nextnode;
					}
			count++;
		}
		for (i = 0; i < this->getVertexCount(); i++)
			if (i != startnode && i == endnode) {
				if (distance[i] != INF) {
					cout << "\n\tDistance to Vertex '" << this->vertexList->Get(i)->getName() << "' = " << distance[i];
					cout << "\n\tPath: \t'" << this->vertexList->Get(i)->getName();
					j = i;
					do {
						j = pred[j];
						cout << "' <- '" << this->vertexList->Get(j)->getName();
					} while (j != startnode);
					cout << "'" << endl;
				}
				else {
					cout << "\n\tYou can't get to Vertex '" << this->vertexList->Get(endnode)->getName() << "' from Vertex '" << this->vertexList->Get(startnode)->getName() << "'\n";
				}
			}
	}

	void getSmallestPaths() {
		vector<vector<string>> mtrx(this->getVertexCount(), std::vector<string>(this->getVertexCount(), ""));
		for (int m = 0; m < this->getVertexCount(); m++) {
			int startnode = m;

			vector<vector<Weight>> G = this->getAdjMatrix();
			vector<vector<Weight>> cost(this->getVertexCount(), std::vector<Weight>(this->getVertexCount(), 0));
			vector<Weight> distance(this->getVertexCount()), pred(this->getVertexCount());

			vector<Weight> visited(this->getVertexCount());
			int count, mindistance, i, j;
			int nextnode = startnode;

			for (i = 0; i < this->getVertexCount(); i++)
				for (j = 0; j < this->getVertexCount(); j++)
					if (G[i][j] == 0 || G[i][j] == INF)
						cost[i][j] = INF;
					else
						cost[i][j] = G[i][j];
			for (i = 0; i < this->getVertexCount(); i++) {
				distance[i] = cost[startnode][i];
				pred[i] = startnode;
				visited[i] = 0;
			}

			distance[startnode] = 0;
			visited[startnode] = 1;
			count = 1;

			while (count < this->getVertexCount() - 1) {
				mindistance = INF;

				for (i = 0; i < this->getVertexCount(); i++)
					if (distance[i] < mindistance && !visited[i]) {
						mindistance = distance[i];
						nextnode = i;
					}

				visited[nextnode] = 1;

				for (i = 0; i < this->getVertexCount(); i++)
					if (!visited[i])
						if (mindistance + cost[nextnode][i] < distance[i]) {
							distance[i] = mindistance + cost[nextnode][i];
							pred[i] = nextnode;
						}
				count++;
			}
			
			string out = "";
			for (i = 0; i < this->getVertexCount(); i++) {
				out = "";
				if (i != startnode) {
					if (distance[i] != INF) {
						
						out += this->vertexList->Get(i)->getName();

						j = i;

						do {
							j = pred[j];
							out += " <- ";
							out += this->vertexList->Get(j)->getName();
						} while (j != startnode);

					}
					else {
						out += "No path";
					}
				}
				else {
					out += "<----->";
				}
				mtrx[startnode][i] = out;
			}
		}
		
		// OUTPUT
		cout << "\n\tMATRIX OF PATHS\n\n";
		cout << "      ";
		for (int i = 0; i < this->getVertexCount(); i++) {
			cout.width(18);
			cout << this->vertexList->Get(i)->getName();
		}
		cout << endl << "\t";
		for (int i = 0; i < this->getVertexCount(); i++) {
			cout.width(18);
			cout << "===================";
		}
		cout << endl;
		for (int i = 0; i < this->getVertexCount(); i++) {
			cout << "\t" << this->vertexList->Get(i)->getName() << "|";
			for (int j = 0; j < this->getVertexCount(); j++) {
				cout.width(18);
				cout << mtrx[i][j];
			}
			cout << endl;
		}
	}


	ListSequence<Edge<Name, Weight>*>* getEdges() {
		return this->edgeList;
	}
	ListSequence<Vertex<Name>*>* getVetex() {
		return this->vertexList;
	}
	
	int getEdgeCount() {
		return this->edgeList->GetSize();
	}
	int getVertexCount() {
		return this->vertexList->GetSize();
	}

private:

	const int INF = 9999;
	ListSequence<Vertex<Name>*>* vertexList;
	ListSequence<Edge<Name, Weight>*>* edgeList;

};