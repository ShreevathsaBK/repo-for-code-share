#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long dp[501][125251];

long long twoSets(vector<int>& arr, int i, int sum){
	if(sum == 0)
		return 1;

	if(sum < 0 || i < 0)
		return 0;

	if(dp[i][sum] != -1)
		return dp[i][sum];

	long long pick = twoSets(arr, i - 1, sum - arr[i]);
	long long no_pick = twoSets(arr, i - 1, sum);

	return dp[i][sum] = (pick + no_pick) % MOD;
}

void solve(){
	int n;
	cin >> n;

	vector<int> arr;

	for(int i=1; i<=n; ++i){
		arr.push_back(i);
	}


	int sum = (n*(n+1))/2;
	if(sum & 1){
		cout << 0;
	}
	else{
		memset(dp, -1, sizeof(dp));
		long long ans = twoSets(arr, n-1, sum/2);
		cout << ans/2;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	solve();
	return 0;
}