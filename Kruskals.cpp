//This ONE!!
//Mine

#include <bits/stdc++.h>
using namespace std;
// DSU data structure
// path compression + rank by union

class DSU {
	int* parent;
	int* rank;
    int n;
public:
	DSU(int n)
	{
		parent = new int[n];
		rank = new int[n];
        this->n=n;
		for (int i = 0; i < n; i++){
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	// Find function
	int find(int i)
	{
		if (parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}
	// union function
	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);

		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}

    void print(){
        cout<<"Parent Array [] : ";
        for(int i=0; i<n; i++){
            cout<<parent[i]<<"\t";
        }
        cout<<"\nRank Array [] : ";
        for(int i=0; i<n; i++){
            cout<<rank[i]<<"\t";
        }
    }
};

class Graph {
	vector<vector<int> > edgelist;
	int V;

public:
	Graph(int V) { this->V = V; }

	void addEdge(int x, int y, int w)
	{
		edgelist.push_back({ w, x, y });
	}

	void kruskals_mst()
	{
        int w, x, y;

        cout<<"\nEdge Table before sorting\n";
        for(auto edge : edgelist){
            w = edge[0];
			x = edge[1];
			y = edge[2];
            cout<<x<<" --> "<<y<<" : "<<w<<endl;
        }

		// 1. Sort all edges
		sort(edgelist.begin(), edgelist.end());

        cout<<"\nEdge Table after sorting\n";
        for(auto edge : edgelist){
            w = edge[0];
			x = edge[1];
			y = edge[2];
            cout<<x<<" --> "<<y<<" : "<<w<<endl;
        }

		// Initialize the DSU
		DSU s(V);
		int ans = 0;
		cout << "\nFollowing are the edges in the "
				"constructed MST"
			<< endl;
		for (auto edge : edgelist) {
			w = edge[0];
			x = edge[1];
			y = edge[2];

			// take that edge in MST if it does form a cycle
			if (s.find(x) != s.find(y)) {
				s.unite(x, y);
				ans += w;
				cout << x << " -- " << y << " == " << w
					<< endl;
			}
		}
        s.print();
		cout << "\nMinimum Cost Spanning Tree: " << ans;
	}
};

int main()
{
    cout<<"Enter no. of vertices & edges : ";
	int n, m, x, y, w;
	cin >> n >> m;
    cout<<"Enter 'u'  'v'  'weight' :\n";
	Graph g(n);
	for (int i = 0; i < m; i++)
	{
        cin >> x >> y >> w;
        g.addEdge(x, y, w);
	}

    cout<<"\nGraph is...\n\n";

	g.kruskals_mst();
	return 0;
}