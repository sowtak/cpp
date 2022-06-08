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

const int MOD = 1000000007;
const int MOD2 = 998244353;
const int MAX = 2147483647;

int Q;
int q, x, c, n;
int main() {
  cin>>Q;
  multiset<int>ms;
  rep(i,0,Q) {
    cin>>q;
    switch(q) {
      case 1:
        cin>>x;
        ms.insert(x);
        break;
      case 2:
        cin>>x>>c; 
        n=min(c, (int)ms.count(x));
        rep(i,0,n)ms.erase(x);
        break;
      case 3:
        cout<<(*ms.rbegin() - *ms.begin())<<endl;
        break;
    }
  }
}
