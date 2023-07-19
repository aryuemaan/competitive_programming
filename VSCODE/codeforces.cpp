#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void chainSMOKERop() {


//JAI SHREE RAM

  int N,M; cin>>N>>M;

  int ans = 0;

  vector<vector<int>> stacks(M,vector<int>(N));

  for(int i = 0;i<N;i++){
    for(int j = 0;j<M;j++){
      cin>>stacks[j][i];
    }
  }

  for(vector<int> & stack : stacks){
    sort(stack.begin(),stack.end());
  }

  for(vector<int> stack : stacks){
    int prefix = 0;
    int total = 0;
    for(int num : stack){
      ans+=(num*total) - prefix;
      total++;
      prefix+=num;
    }
  }

  cout<<ans<<endl;

return 0;



}

