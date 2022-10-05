#include <bits/stdc++.h>
using namespace std;


/*You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.*/


int  CoinChange(int n,vector<int> &coins,int amount,vector<vector<int>> &dp)
{
  	if(n==0)
  	{
    	if(amount%coins[0]!=0) return 1e9;
    	return amount/coins[0];
  	}

  	//If it has already calculated
  	if(dp[n][amount]!=-1) return dp[n][amount];

  	int pick=INT_MAX;

  	if(coins[n]<=amount) pick=1+CoinChange(n,coins,amount-coins[n],dp);

  	int notpick=CoinChange(n-1,coins,amount,dp);
  	
  	return dp[n][amount]=min(pick,notpick);
}


int main()
{
	int n,amount;
	cin>>n>>amount;
	vector<int> coins(n,0);
	for(int i=0;i<n;i++)
	{
		cin>>coins[i];
	}

	vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
	int ans=CoinChange(n,coins,amount,dp);
	//If you can't make up amount using given coins
	if(ans==1e9)
	{
		cout<<-1<<"\n";
	}
	else
	{
		cout<<ans<<"\n";
	}
}