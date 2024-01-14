#include <bits/stdc++.h>
using namespace std;
int knapSackRec(int w, int wt[], int val[], int index, int** dp){
	if (index < 0)
		return 0;
	if (dp[index][w] != -1)
		return dp[index][w];
	if (wt[index] > w) {
		dp[index][w] = knapSackRec(w, wt, val, index - 1, dp);
		return dp[index][w];
	}
	else {
        dp[index][w] = max(val[index]+ knapSackRec(w - wt[index], wt, val,index - 1, dp),knapSackRec(w, wt, val, index - 1, dp));
		return dp[index][w];
	}
}
int knapSack(int w, int wt[], int val[], int n){
	int** dp;
	dp = new int*[n];
	for (int i = 0; i < n; i++){
        dp[i] = new int[w + 1];
    }
	for (int i = 0; i < n; i++){
		for (int j = 0; j < w + 1; j++){
			dp[i][j] = -1;
        }
	    return knapSackRec(w, wt, val, n - 1, dp);
    }
}
int main(){
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,w;
	cin >> n >> w;
	int profit[n];
	int weight[n];
	for(int i=0; i<n; i++){
        cin >> weight[i];
	}
    for(int i=0; i<n; i++){
        cin >> profit[i];
	}
	cout << knapSack(w, weight, profit, n);
	return 0;
}