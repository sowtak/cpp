#include <iostream>
#include <iomanip>
#include <bitset>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstring>
#define ll long long
#define rep(idx,b,e) for(int idx=(b);idx<e;idx++)
#define rrep(idx,b,e) for(int idx=b;idx>e;idx--)
template <typename T> inline bool chmin(T &a, T &b) {if (a>b){a=b; return true;} else return false;}
template <typename T> inline bool chmax(T &a, T &b) {if (a<b){a=b; return true;} else return false;}
using namespace std;

const int MAX = 1000000007;
const int MAX2 = 998244353;

ll N,T[100000];
int add(int n) {
  ll tmp = n;
  int cnt =0;
  
  while(tmp>1) {
    if(tmp%2==0){
      tmp/=2;
      cnt+=1;
    } else {
      break;
    }
  }
  return cnt;
}

ll calc(int t,int pre) {

  ll curr=1<<t;
  bitset<41>curr_b = curr;
  int cnt = 0;
  if (curr_b.count() == 1) {
    while(pre>=curr) {
      cnt=add(curr);
      curr=(curr<<1)+(1<<cnt);
    }
  } else {
    while(pre>=curr) {
      cnt=add(curr);
      int a = (curr<<1)+(1<<cnt);
      int b = (curr<<1)^curr;
      curr=min(a,b);
    }
  }
  cout<<curr<<endl;
  return curr;
}

int main() {
 cin>>N;
 ll pre=0;
 rep(i,0,N)
   cin>>T[i];
 rep(i,0,N) 
   pre=calc(T[i],pre);
 
 cout<<pre<<endl;
 
}
