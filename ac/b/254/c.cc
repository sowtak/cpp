#include <iostream>
#include <iomanip>
#include <bitset>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cmath>
#include <cstring>
#define ll long long
#define rep(idx,b,e) for(int idx=(b);idx<e;idx++)
#define rrep(idx,b,e) for(int idx=b;idx>e;idx--)
template <typename T> inline bool chmin(T &a, T &b) {if (a>b){a=b; return true;} else return false;}
template <typename T> inline bool chmax(T &a, T &b) {if (a<b){a=b; return true;} else return false;}
using namespace std;

const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAX = 2147483647;

int N,K;
int main() {
  array<int, 200000> a,b;
  cin>>N>>K;rep(i,0,N)cin>>a[i];
  
  if(is_sorted(a.begin(), a.end())) {
    cout<<"Yes"<<endl;
    return 0;
  } else {
    while(!is_sorted(a.begin(), a.end())) {
      b=a;
      rep(i,0,N-K) {
        if(a[i]>a[i+K]) 
          swap(a[i], a[i+K]);
      }
      if(b==a)
        break;
    }
  }

  rep(i,0,N)cout<<a[i]<<' ';
  cout<<endl;

  if(is_sorted(a.begin(), a.end())) {
    cout<<"Yes" <<endl;
  } else {
    cout<<"No"<<endl;
  }
}
