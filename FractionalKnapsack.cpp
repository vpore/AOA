#include<bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> w;
int n, M;

void printSoln(vector<double> x){
    int sum=0;
    for(auto i=x.begin(); i!=x.end(); i++){
        cout<<fixed<<setprecision(2)<<*i<<endl;
    }
    for(int i=0; i<n; i++){
        sum+=(x[i])*(p[i]);
    }
    cout<<"Maximum profit: "<<sum<<endl;
}

void Knapsack(){
    vector<double> x(n, 0);
    int i;
    int remCapacity = M;
    for(i=0; i<n; i++){
        if(w[i]>remCapacity)
            break;
        x[i] = 1;
        remCapacity-=w[i];
    }
    if(i<=n){
        x[i] = double(double(remCapacity)/w[i]);
    }
    printSoln(x);
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
    cout<<"Enter weights of each object"<<endl;
    for(i=0; i<n; i++){
        cin>>val;
        w.push_back(val);
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(p[i]/w[i] > p[j]/w[j]){
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
                temp=w[j];
                w[j]=w[i];
                w[i]=temp;
            }
        }
    }

    Knapsack();
    return 0;
}