/*#include<bits/stdc++.h>
using namespace std;

void printLCS(vector<vector<int>> b, string X, int i, int j){
    if(i==0 || j==0)
        return;
    if(b[i][j] == 50){
        printLCS(b, X, i-1, j-1);
        cout<<X[i];
    }
    else if(b[i][j] == 20)
        printLCS(b, X, i-1, j);
    else
        printLCS(b, X, i, j-1);
}

void LCS(string X, string Y){
    int m=X.length();
    int n=Y.length();
    vector<vector<int>> c(m, vector<int> (n, 0));
    vector<vector<int>> b(m-1, vector<int> (n-1, 0));
    
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(X[i] == Y[j]){
                c[i][j] = c[i-1][j-1];
                b[i][j] = 50; //Diagonal
            }
            else if(c[i-1][j] >= c[i][j-1]){
                cout<<"Hii1"<<endl;
                c[i][j] = c[i-1][j];
                b[i][j] = 20; //Up
            }
            else{
                cout<<"Hii2"<<endl;
                c[i][j] = c[i][j-1];
                b[i][j] = 10; //Left
            }
        }
    }
    printLCS(b, X, m, n);
}

int main(){
    string X, Y;
    int i;
    cout<<"Enter X"<<endl;
    cin>>X;
    cout<<"Enter Y"<<endl;
    cin>>Y;
    
    for(i=X.length(); i>0; i--)
        X[i] = X[i-1];
    for(i=Y.length(); i>0; i--)
        Y[i] = Y[i-1];

    LCS(X, Y);
    return 0;
}*/


#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cout << "Enter first string" << endl;
    cin >> s1;
    cout << "Enter second string" << endl;
    cin >> s2;
    int dp[s1.length() + 1][s2.length() + 1];
    int n = s1.length(), m = s2.length();
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int index = dp[n][m];
    char lcs[index + 1]={};
    lcs[index] = '\0';
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        // If current character in X and Y are same, then
        // current character is part of LCS
        if (s1[i - 1] == s2[j - 1])
        {
            lcs[index - 1] = s1[i - 1]; // Put current character in result
            i--; j--; index--;     // reduce values of i, j and index
        }

        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "LCS is " << lcs << endl;

    return 0;
}