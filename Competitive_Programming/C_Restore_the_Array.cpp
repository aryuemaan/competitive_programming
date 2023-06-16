#include <bits/stdc++.h>
using namespace std;


 

 
int main(){
    int t,n,x1,y1,x2,y2;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      n--;
      vector<int> A(n),B(n+1);
      for(int i =0;i<n;i++){
        cin>>A[i];
      }
      
      bool done = false;
      B[0] = A[0];
      B[n] = A[n-1];
      for(int i = 0;i<n-1;i++){
        B[i+1] = min(A[i],A[i+1]);
      }
      for(int i = 0;i<n+1;i++){
        cout<<B[i]<<" ";
      }
      cout<<"\n";

    }
    return 0;
 
}