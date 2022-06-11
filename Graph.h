#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class Graph{
    public:
        int adjacencyMatrix[101][101]={{0}};
        int incidenceMatrix[101][1001]={{0}};
        int vertices,edges;
        bool directed;
        void getGraph();
        bool isDirected();
        bool isSimple();
        bool isComplete();
        bool isCyclic();
        void display();
        Graph unionGraph(Graph & g);
        void getAndShowIncidenceMatrix();
        void showIncidenceMatrix();
        int degreeOfGraph();
        void inDegreeOutDegree();
};
void Graph::getGraph(){
    // first line of graph.txt contains three numbers denoting the number of vertices , edges and is graph is directed or not and successive lines contain those vertices where there is an edge.
    ifstream file;
    file.open("graph.txt");
    file >> vertices >> edges >> directed;
    for(int i=0 ; i < edges ; i++){
        int v1,v2;
        file >> v1 >> v2;
        if(directed){
            adjacencyMatrix[v1][v2]++;
        }
        else{
            adjacencyMatrix[v1][v2]++;
            adjacencyMatrix[v2][v1]++;
        }
    }
}
bool Graph::isDirected(){
    for(int i=1 ; i<=vertices ; i++){
        for(int j=0 ; j<=vertices ; j++){
            if(adjacencyMatrix[i][j] && adjacencyMatrix[j][i]==0){
                return true;
            }
        }
    }
    return false;
}
bool Graph::isSimple(){
    for(int i=1 ; i<=vertices ; i++){
        for(int j=0 ; j<=vertices ;j++){
            if(adjacencyMatrix[i][i]==1 || adjacencyMatrix[i][j]>1){
                return false;
            }
        }
    }
    return true;
}
bool Graph::isComplete(){
    for(int i=1 ; i<=vertices ; i++){
        for(int j=1 ; j<=vertices , j!=i ; j++){
            if(adjacencyMatrix[i][j]==0){
                return false;
            }
        }
    }
    return true;
}
Graph Graph::unionGraph(Graph & g){
    Graph newGraph;
    vertices > g.vertices ? newGraph.vertices=vertices : newGraph.vertices=g.vertices;
    for(int i=1 ;  i<=newGraph.vertices ; i++){
        for(int j=1 ; j<=newGraph.vertices ; j++){
            newGraph.adjacencyMatrix[i][j] = max(adjacencyMatrix[i][j],g.adjacencyMatrix[i][j]);
        }
    }
    return newGraph;
}
void Graph::display(){
    for(int i=1 ; i<=vertices ; i++){
        for(int j=1 ; j<=vertices ; j++){
            cout<<setw(5)<<left;
            cout<<adjacencyMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Graph::getAndShowIncidenceMatrix(){
    int currEdge=1;
    if(directed){
        for(int i=1 ; i<=vertices ; i++){
            for(int j=1 ; j<=vertices ; j++){
                if(adjacencyMatrix[i][j]){
                    incidenceMatrix[i][currEdge] = -1;
                    incidenceMatrix[j][currEdge] = 1;
                    currEdge++;
                }
            }
        }
    }
    else{
        for(int i=1 ; i<=vertices ; i++){
            for(int j=i ; j<=vertices ; j++){
                if(adjacencyMatrix[i][j]){
                    incidenceMatrix[i][currEdge]=1;
                    incidenceMatrix[j][currEdge]=1;
                    currEdge++;
                }
            }
        }
    }
    for(int i=1 ; i<=vertices ; i++){
        for(int j=1 ; j<=edges ; j++){
            cout<<setw(5)<<left;
            cout<<incidenceMatrix[i][j];
        }
        cout<<endl;
    }
}
int Graph::degreeOfGraph(){
    int deg=0;
    for(int i=1 ; i<=vertices ; i++){
        for(int j=1 ; j<=edges ; j++){
            if(incidenceMatrix[i][j]) deg++;
        }
    }
    return deg;
}
void Graph::inDegreeOutDegree(){
    for(int i=1 ; i<=vertices ; i++){
        int in=0 , out=0;
        for(int j=1 ; j<=edges ; j++){
            if(incidenceMatrix[i][j]==-1) out++;
            else if(incidenceMatrix[i][j]==1) in++;
        }
        cout<<"In-degree of vertex "<<i<<" is :"<<in<<endl;
        cout<<"Out-degree of vertex "<<i<<" is :"<<out<<endl;
    }
}
