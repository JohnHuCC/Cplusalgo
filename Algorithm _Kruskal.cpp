#include <iostream>
#include <vector>
#include <list>
#include <iomanip>     
#include <algorithm> 

using namespace std;
struct Edge{
    int from, to, weight;
    Edge(){};
    Edge(int u, int v, int w):from(u), to(v), weight(w){};
};

class MST{
private:
    int num_vertex;
    vector<vector<int>> AdjMatrix;
public:
    MST():num_vertex(0){};
    MST(int n):num_vertex(n){
        AdjMatrix.resize(num_vertex);
        for (int i = 0; i < num_vertex; i++) {
            AdjMatrix[i].resize(num_vertex);
        }
    }
    void AddEdge(int from, int to, int weight);

    void KruskalAlgorithm();
    void GetSortedEdge(vector<struct Edge> &vec);
    friend int PathCompression(int *subset, int i);
    friend void MergeToSet(int *subset, int x, int y);
};
int PathCompression(int *subset, int i){      // 遞迴做path compression

    int root; 
    for (root = i; subset[root] >= 0; root = subset[root]);

    while (i != root) {
        int parent = subset[i];
        subset[i] = root;
        i = parent;
    }

    return root;
}
void MergeToSet(int *subset, int x, int y){

    int x_root = PathCompression(subset, x),
        y_root = PathCompression(subset, y);

    // 越負表示set越多element
    if (subset[x_root] <= subset[y_root]) {        // x比較多element或是一樣多的時候, 以x作為root
        subset[x_root] += subset[y_root];
        subset[y_root] = x_root;
    }
    else {    //  if (subset[x_root] > subset[y_root]), 表示y比較多element
        subset[y_root] += subset[x_root];
        subset[x_root] = y_root;
    }
}
bool WeightComp(struct Edge e1, struct Edge e2){
    return (e1.weight < e2.weight);
}
void MST::GetSortedEdge(std::vector<struct Edge> &edgearray){

    for (int i = 0; i < num_vertex-1; i++) {
        for (int j = i+1; j < num_vertex; j++) {
            if (AdjMatrix[i][j] != 0) {
                edgearray.push_back(Edge(i,j,AdjMatrix[i][j]));
            }
        }
    }
    sort(edgearray.begin(), edgearray.end(), WeightComp);
}
void MST::KruskalAlgorithm(){

    struct Edge *edgesetMST = new struct Edge[num_vertex-1];
    int edgesetcount = 0;

    int subset[num_vertex];
    for (int i = 0; i < num_vertex; i++) {
        subset[i] = -1;
    }

    vector<struct Edge> increaseWeight;
    GetSortedEdge(increaseWeight);              // sort完的edge的vec

    for (int i = 0; i < increaseWeight.size(); i++) {
        if (PathCompression(subset, increaseWeight[i].from) != PathCompression(subset, increaseWeight[i].to)) {
            edgesetMST[edgesetcount++] = increaseWeight[i];
            MergeToSet(subset, increaseWeight[i].from, increaseWeight[i].to);
        }
    }
    cout << setw(3) << "v_b" << " - " << setw(3) << "v_a"<< " : weight\n";
    for (int i = 0; i < num_vertex-1; i++) {
        cout << setw(3) << edgesetMST[i].from << " - " << setw(3) << edgesetMST[i].to 
                  << " : " << setw(4) << edgesetMST[i].weight << "\n";
    }
}
void MST::AddEdge(int from, int to, int weight){
    AdjMatrix[from][to] = weight;
}

int main(){

    MST Graph_MST(5);
    Graph_MST.AddEdge(0, 1, 3);
	Graph_MST.AddEdge(0, 4, 1);
    Graph_MST.AddEdge(1, 0, 3);
    Graph_MST.AddEdge(1, 4, 4);
    Graph_MST.AddEdge(1, 2, 5);
    Graph_MST.AddEdge(2, 1, 5);
    Graph_MST.AddEdge(2, 4, 6);
    Graph_MST.AddEdge(2, 3, 2);
    Graph_MST.AddEdge(3, 2, 2);
    Graph_MST.AddEdge(3, 4, 7);
    Graph_MST.AddEdge(4, 0, 1);
    Graph_MST.AddEdge(4, 1, 4);
    Graph_MST.AddEdge(4, 2, 6);
    Graph_MST.AddEdge(4, 3, 7);

    cout << "Minimum Spanning Tree(Kruskal's Algorithm):\n";
    Graph_MST.KruskalAlgorithm();

    return 0;
}
