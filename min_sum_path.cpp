// Given a m x n grid filled with non-negative numbers,
// find a path from top left to bottom right which
// minimizes the sum of all numbers along its path.

#include<bits/stdc++.h>
using namespace std;

int minSumPath(vector<vector<int> > &grid) {
      if (grid.size() == 0) return 0;
      int m = grid.size(), n = grid[0].size();
      int minPath[m + 1][n + 1];
      for (int i = 0; i < m; i++) {
        minPath[i][0] = grid[i][0];
        if (i > 0) minPath[i][0] += minPath[i - 1][0];
        for (int j = 1; j < n; j++) {
          minPath[i][j] = grid[i][j] + minPath[i][j-1];
          if (i > 0) minPath[i][j] = min(minPath[i][j], grid[i][j] + minPath[i-1][j]);
        }
      }
      return minPath[m-1][n-1];
}

int main()
{
      int m,n;
      cin>>m>>n;
      vector<vector<int> > v(m,vector<int> (m,-1));
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          cin>>v[i][j];
        }
      }
      cout<<"Length of the minimum path is: "<<minSumPath(v);
}
