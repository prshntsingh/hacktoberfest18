// Given 2 sorted arrays, finding the median of the array formed by merging both arrays

#include<bits/stdc++.h>
using namespace std;

double findMedian(vector<int> &X,vector<int> &Y)
{
    int x=X.size();
    int y=Y.size();
    if(x>y)
        return findMedian(Y,X);
    int l=0,h=x;
    while(l<=h){
        int partX=l+(h-l)/2;
        int partY=(x+y+1)/2-partX;

        int maxlX=(partX==0)?INT_MIN:X[partX-1];
        int minrX=(partX==x)?INT_MAX:X[partX];

        int maxlY=(partY==0)?INT_MIN:Y[partY-1];
        int minrY=(partY==y)?INT_MAX:Y[partY];

        if(maxlX<=minrY && maxlY<=minrX){
            if((x+y)%2==0)
                return (double)(max(maxlX,maxlY)+min(minrX,minrY))/2;
            else
                return (double)(max(maxlX,maxlY));
        }
        else if(maxlX>minrY)
            h=partX-1;
        else
            l=partX+1;
    }
}

int main()
{
    int m,n//size of both the arrays
    cin>>m>>n;
    int num;
    vector<int> a,b;
    for(int i=0;i<m;i++){
      cin>>num;
      a.push_back(num);
    }
    for(int i=0;i<n;i++){
      cin>>num;
      b.push_back(num);
    }
    cout<<"Median is: "<<findMedian(a,b);
    return 0;
}
