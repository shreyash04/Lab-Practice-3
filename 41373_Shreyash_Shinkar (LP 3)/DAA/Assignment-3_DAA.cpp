//0-1 Knapsack using Dp and Recursion
#include <bits/stdc++.h>
using namespace std;

//Approach 1:Using Recursion
int knapsackRecusrsion(vector<int> &wt, vector<int> &val, int w, int n){
    //Base Condition
    if(n==0 || w==0){
        return 0;
    }
    if(wt[n-1] <= w){
        return max(val[n-1] + knapsackRecusrsion(wt, val, w-wt[n-1], n-1), knapsackRecusrsion(wt,val,w,n-1));
    }
    else if(wt[n-1] > w){
        return knapsackRecusrsion(wt, val, w, n-1);
    }
}
//Approach 2:Memoization(DP)
int knapsackMemoization(vector<int> &wt, vector<int> &val, int w, int n, vector<vector<int>> &dp){
    //Base Condition
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w] != -1){
        return dp[n][w];
    }
    if(wt[n-1] <= w){
        return dp[n][w] = max(val[n-1] + knapsackMemoization(wt, val, w-wt[n-1], n-1, dp), 
                            knapsackMemoization(wt, val, w, n-1, dp));
    }
    else if(wt[n-1] > w){
        return dp[n][w] = knapsackMemoization(wt, val, w, n-1, dp);
    }
}
//Approach 3:Tabulation(DP)
int knapsackTabulation(vector<int> &wt, vector<int> &val, int w, int n, vector<vector<int>> &dp){
    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main()
{
    vector<int> wt;
    vector<int> val;
    int w;
    int n;
    cout<<"Enter size of an array: ";
    cin>>n;
    cout<<"Enter capacity of a knapsack: ";
    cin>>w;

    cout<<"Enter elements of weight array:"<<endl;
    for(int i=0; i<n; i++){
        int e;
        cin>>e;
        wt.push_back(e);
    }

    cout<<"Enter elements of value array:"<<endl;
    for(int i=0; i<n; i++){
        int e;
        cin>>e;
        val.push_back(e);
    }

    while(true){
        cout<<"\n*MENU*\n";
        cout<<"1. Using Recursion"<<endl;
        cout<<"2. Using Memoization"<<endl;
        cout<<"3. Using Tabulation"<<endl;
    
        cout<<"Enter Choice: ";
        int c;
        cin>>c;
        switch(c){
            case 1:{
                cout<<"Final Output is: ";
                cout<<knapsackRecusrsion(wt, val, w, n)<<endl;
                break;
            }
            case 2:{
                cout<<"Final Output is: ";
                vector<vector<int>>dp(n+1, vector<int>(w+1, -1));
                cout<<knapsackMemoization(wt, val, w, n, dp)<<endl;
                break;
            }
            case 3:{
                cout<<"Final Output is: ";
                vector<vector<int>>dp(n+1, vector<int>(w+1, 0));
                cout<<knapsackTabulation(wt, val, w, n, dp)<<endl;
                break;
            }
        }
        char c1;
        cout<<"\nDo you want to continue(Y/N): ";
        cin>>c1;
        if(c1=='Y' || c1=='y'){
            continue;
        }
        else{
            cout<<"Thank You!";
            break;
        }
    }
    return 0;
}
