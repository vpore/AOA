#include<bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> w;
int n, M;

void Knapsack(){

}

int main(){
    int val, i, j, temp;
    cout<<"Enter maximum weight"<<endl;
    cin>>M;
    cout<<"Enter number of objects"<<endl;
    cin>>n;
    cout<<"Enter profits of each object"<<endl;
    for(i=0; i<n; i++){
        cin>>val;
        p.push_back(val);
    }
    for(i=0; i<n; i++){
        cin>>val;
        w.push_back(val);
    }
    

    Knapsack();
    return 0;
}