//This ONE!!
//Mine

#include<bits/stdc++.h>
using namespace std;

vector<double> p;
vector<double> w;
vector<vector<double>> objList;
int n, M;

void printSoln(vector<double> x){
    int sum=0;
    cout<<"\nItems in Knapsack - \n"<<endl;
    cout<<"Object\tFraction"<<endl;
    for(int i=0; i<x.size(); i++){
        cout<<fixed<<setprecision(0)<<objList[i][3]<<"\t";
        cout<<fixed<<setprecision(2)<<x[i]<<endl;
    }
    for(int i=0; i<n; i++){
        sum+=(x[i])*(objList[i][1]);
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
        remCapacity-=objList[i][2];
    }
    if(i<=n){
        x[i] = double(double(remCapacity)/objList[i][2]);
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

    cout<<"\nObject\tProfit\tWeight\tProfit/Weight Ratio"<<endl;
    for(i=0; i<n; i++){
        cout<<i+1<<"\t"<<p[i]<<"\t"<<w[i]<<"\t"<<p[i]/w[i]<<endl;
        objList.push_back({double(p[i]/w[i]), p[i], w[i], double(i+1)});
    }

    sort(objList.rbegin(), objList.rend());

    // for(i=0; i<n; i++){
    //     for(j=0; j<n; j++){
    //         if(p[i]/w[i] > p[j]/w[j]){
    //             temp=p[j];
    //             p[j]=p[i];
    //             p[i]=temp;
    //             temp=w[j];
    //             w[j]=w[i];
    //             w[i]=temp;
    //         }
    //     }
    // }

    cout<<"\nAfter Sorting..."<<endl;
    cout<<"\nObject\tProfit\tWeight\tRatio"<<endl;
    for(i=0; i<n; i++){
        //cout<<i+1<<"\t"<<p[i]<<"\t"<<w[i]<<endl;
        cout<<objList[i][3]<<"\t"<<objList[i][1]<<"\t"<<objList[i][2]<<"\t"<<objList[i][0]<<endl;
    }

    Knapsack();
    return 0;
}