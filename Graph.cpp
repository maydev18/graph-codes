#include <iostream>
#include "Graph.h"
using namespace std;
int main(){
    Graph g;
    g.getGraph();
    // Graph h;
    // h.getGraph();
    // g.isDirected()?cout<<"directed":cout<<"undirected";
    // cout<<endl;
    // g.isSimple()?cout<<"simple"<<endl:cout<<"not simple"<<endl;
    // g.isComplete()?cout<<"complete"<<endl:cout<<"not complete"<<endl;
    // g.isCyclic()?cout<<"cyclic"<<endl:cout<<"not cyclic"<<endl;
    // Graph un = h.unionGraph(g);
    // un.display();
    // g.display();
    g.getAndShowIncidenceMatrix();
    // cout<<g.degreeOfGraph();
    g.inDegreeOutDegree();
    return 0;
}