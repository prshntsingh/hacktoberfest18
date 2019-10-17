// Finding longest Arithmetic Progression in an integer array ,and return its length.
#include<bits/stdc++.h>
using namespace std;

int findLength(vector<int> &v)
{
    int n=v.size();
    if(n<3)
      return n;
    vector<vector<int> >dp(n,vector<int>(n,-1));
    map<int,int> pos;
    for (int i = 0; i < n; i++){
		    for (int j = i + 1; j < n; j++){
    			dp[i][j] = 2;
    			int dif = v[j] - v[i
    			int need = 2 * v[i] - v[j];
    			if (pos.count(need) == 0) continue;
    			dp[i][j] = max(dp[i][j], dp[pos[need]][i] + 1);
		      }
		    pos[v[i]] = i;
    }
  	int ans = 2;
  	for (int i = 0; i < n; i++) {
  		for (int j = i + 1; j < n; j++) {
  			ans = max(ans, dp[i][j]);
  		}
  	}
  	return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    cout<<"Length of longest AP: "<<findLength(v);
    return 0;
}
