#include<bits/stdc++.h>
using namespace std;

int s;
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

void printMST(vector<int> parent, vector<int> key, vector<vector<int>> graph, int V){
    cout<<"\nFinal Values...";
    cout<<"\nKEY arrray : \t";
    for(auto it : key){
        cout<<it<<"\t";
    }
    cout<<"\nPI arrray : \t";
    for(auto it : parent){
        cout<<it<<"\t";
    }
    int sum=0;
    cout<<"\n\nEdge\tWeight\n";
    for(int i=0; i<V; i++){
        if(i==s){continue;}
        sum += graph[i][parent[i]];
        cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<endl;
    }
    cout<<"Minimum - "<<sum;
}

void primsMST(vector<vector<int>> graph, int V){
    
    vector<int> parent(V, -1);
    vector<int> key(V, INT16_MAX);
    vector<bool> Q(V, false);

    cout<<"\nKEY array :\t";
    for(auto it : key){
        cout<<it<<"\t";
    }

    cout<<"\nPI array :\t";
    for(auto it : parent){
        cout<<it<<"\t";
    }

    cout<<"\n\nEnter starting vertex :";
    cin>>s;

    key.at(s) = 0;
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
    
    printMST(parent, key, graph, V);
}

int main(){
    int V, wt, i, j;
    vector<vector<int>> graph;
    cout<<"Enter number of Vertices :";
    cin>>V;
    cout<<"Enter WEIGHTS of each edge :"<<endl;
    for(i=0; i<V; i++){
        vector<int> row;
        for(j=0; j<V; j++){
            cin>>wt;
            row.push_back(wt);
        }
        graph.push_back(row);
    }

    cout<<"\nGraph is...\n";
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            cout<<graph[i][j]<<"\t";
        }
        cout<<"\n";
    }

    primsMST(graph, V);
    
    return 0;
}