#include <bits/stdc++.h>
//0-1 Knapsack using Dp and Recursion
using namespace std;
//Approach 1:Using Recursion
int knapsack(vector<int> &wt,vector<int> &val,int w,int n){
    //Base Condition
    if(n==0 || w==0){
        return 0;
    }
    if(wt[n-1]<=w){
        return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    else if(wt[n-1]>w){
        return knapsack(wt,val,w,n-1);
    }
}
//Approach 2:Memoization(DP)
int knapsack_with_memoization(vector<int> &wt,vector<int> &val,int w,int n,vector<vector<int>> &dp){
    //Base Condition
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if(wt[n-1]<=w){
        return dp[n][w]=max(val[n-1]+knapsack_with_memoization(wt,val,w-wt[n-1],n-1,dp),knapsack_with_memoization(wt,val,w,n-1,dp));
    }
    else if(wt[n-1]>w){
        return dp[n][w]=knapsack_with_memoization(wt,val,w,n-1,dp);
    }
}
//Approach 3:Tabulation(DP)
int knapsack_with_tabulation(vector<int> &wt,vector<int> &val,int w,int n,vector<vector<int>> &dp){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
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
    cout<<"Enter size of an array"<<'\n';
    cin>>n;
    cout<<"Enter capacity of a knapsack"<<'\n';
    cin>>w;

    cout<<"Enter elements of weight array"<<'\n';
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        wt.push_back(e);
    }
    cout<<"Enter elements of value array"<<'\n';
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        val.push_back(e);
    }
    cout<<"***********MENU***********"<<'\n';
    cout<<"1.Using Recursion"<<'\n';
    cout<<"2.Using Memoization"<<'\n';
    cout<<"3.Using Tabulation"<<'\n';
    int c;
    while(1){
        cout<<"Enter Choice"<<'\n';
        cin>>c;
        switch(c){
            case 1:{
                cout<<"Final Output is : ";
                cout<<knapsack(wt,val,w,n)<<'\n';
                break;
            }
            case 2:{
                cout<<"Final Output is : ";
                vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
                cout<<knapsack_with_memoization(wt,val,w,n,dp)<<'\n';
                break;
            }
            case 3:{
                cout<<"Final Output is : ";
                vector<vector<int>>dp(n+1,vector<int>(w+1,0));
                cout<<knapsack_with_tabulation(wt,val,w,n,dp)<<'\n';
                break;
            }
        }
        char c1;
        cout<<"\nDo you want to continue(Y/N)"<<'\n';
        cin>>c1;
        if(c1=='Y'){
            continue;
        }
        else{
            cout<<"Thank-You"<<'\n';
            break;
        }
    }
    return 0;
}
