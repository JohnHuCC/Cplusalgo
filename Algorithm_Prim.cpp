#include <iostream>
#include <vector>
#include <iomanip>     
/*
ancestor[]�GMST���A�U��vertex������������Y�C
key[]�G��edge������Akey[]�O��edge��weight�A
���O�|�Nweight�u�Ȧs�bvertex�W�v�A��ܡu��F��vertex�������v�A
�t��k�n�D��X����H�̤�weight�`�M��F��vertex��edge�A��edge�W�����vertex�Y�Φ�������Y�O���iancestor[]�C
visited[]�G�ХX����vertex�w�g�bMST�̭��A�OMST��vertex�аO��1�A��l��0�C
*/ 

using namespace std;
const int Max_Weight = 1000;    // initialize key[]

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
    void PrimAlgorithm(int Start = 0);        // ���w�_�IStar�@��MST��root,default��0 
    friend int MinKeyExtract(int *key, bool *visited, int size);
};

int MinKeyExtract(int *key, bool *visited, int size){

    int min = Max_Weight, min_idx = 0;
    for (int i = 0; i < size; i++) {
        if (visited[i]==false && key[i]<min) {
            min = key[i];
            min_idx = i;
        }
    }
    return min_idx;
}
void MST::PrimAlgorithm(int Start){

    int key[num_vertex], predecessor[num_vertex];
    bool visited[num_vertex];

    for (int i = 0; i < num_vertex; i++) {
        key[i] = Max_Weight;
        predecessor[i] = -1;
        visited[i] = false;     // false���vertex���Qvisited
    }

    key[Start] = 0;
    for (int i = 0; i < num_vertex; i++) {
        int u = MinKeyExtract(key, visited, num_vertex);
        visited[u] = true;
        for (int i = 0; i < num_vertex; i++) {
            if ( visited[i]==false && AdjMatrix[u][i]!=0 && AdjMatrix[u][i]<key[i]) {
                predecessor[i] = u;
                key[i] = AdjMatrix[u][i];
            }
        }
    }
    cout << setw(3) << "v_b" << " - " << setw(3) << "v_a"<< " : weight\n";
    int i = (Start+1)%num_vertex;  
    while (i != Start) {
        cout << setw(3) << predecessor[i] << " - " << setw(3) << i
                  << " : " << setw(4) << AdjMatrix[predecessor[i]][i] <<"\n";
        i = (++i)%num_vertex;    
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

    cout << "Minimum Spanning Tree(Prim's Algorithm:\n";
    Graph_MST.PrimAlgorithm(0);

    return 0;
}
