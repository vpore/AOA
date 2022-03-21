#include<bits/stdc++.h>
using namespace std;

int minKey(vector<int> key, vector<bool> Q, int V){
    int min=INT16_MAX, minIndex;
    for(int i=0; i<V; i++){
        if(Q[i]==false && min>key[i]){
            min=key[i];
            minIndex=i;
        }
    }
    return minIndex;
}

void printMST(vector<int> parent, vector<vector<int>> graph, int V){
    int sum=0;
    cout<<"\nEdge\tWeight\n";
    for(int i=1; i<V; i++){
        sum += graph[i][parent[i]];
        cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<endl;
    }
    cout<<"Minimum - "<<sum;
}

void primsMST(vector<vector<int>> graph, int V){
    // for(int i=0; i<V; i++){
    //     for(int j=0; j<V; j++){
    //         cout<<graph[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    vector<int> parent(V, -1);
    vector<int> key(V, INT16_MAX);
    vector<bool> Q(V, false);

    // for(int i=0; i<V; i++){
    //     key.push_back(INT16_MAX);
    //     Q.push_back(false);
    // }

    // for(int j=0; j<V; j++){
    //     cout<<key[j]<<"\t"<<Q[j]<<endl;
    // }

    key.at(0) = 0;
    parent.push_back(-1);
    for(int count=0; count<V-1; count++){
        int u = minKey(key, Q, V);
        Q.at(u) = true;
        for(int v=0; v<V; v++){
            if(graph[u][v] && Q[v]==false && graph[u][v]<key[v]){
                key[v] = graph[u][v];
                parent.at(v) = u;
            }
        }        
    }
    
    printMST(parent, graph, V);
}

int main(){
    int V, wt;
    vector<vector<int>> graph;
    cout<<"Enter number of Vertices"<<endl;
    cin>>V;
    cout<<"Enter WEIGHTS of each edge"<<endl;
    for(int i=0; i<V; i++){
        vector<int> row;
        for(int j=0; j<V; j++){
            cout<<"Enter weight of "<<i<<" - "<<j<<" edge  : ";
            cin>>wt;
            row.push_back(wt);
        }
        graph.push_back(row);
    }

    // for(int i=0; i<V; i++){
    //     for(int j=0; j<V; j++){
    //         cout<<graph[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }

    primsMST(graph, V);
    
    return 0;
}