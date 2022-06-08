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

int N,K,L, p,q,r,s;
vector<vector<int>>road, railway;


int main() {
  cin>>N>>K>>L;
  
  rep(i,0,K) {
    cin>>p>>q;p--,q--;
    road[p][q]=road[q][p]=1;
  }

  rep(i,0,L) {
    cin>>r>>s;r--,s--;
    road[r][s]=road[s][r]=1;
  }
}
