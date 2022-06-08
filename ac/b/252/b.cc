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

int N,K;
int A[110], B[110];
int main() {
  cin>>N>>K;
  int mx=0, x=0, pre=0;
  rep(i,0,N){
    cin>>x;
    if(x>pre)mx=x;
    pre=x;
    A[i]=x;
  }


  rep(i,0,K) {
    cin>>x;
    if(A[x-1]==mx) {
      cout<<"Yes"<<endl;
      return 0;
    }
  }

  cout<<"No"<<endl;
}
