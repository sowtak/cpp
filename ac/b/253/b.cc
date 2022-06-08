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

int H, W;
bool assigned;
string S[100];
int main() {
  int x1=0,y1=0,x2=0,y2=0;
  cin>>H>>W;
  rep(i,0,H)cin>>S[i];

  rep(i,0,H)rep(j,0,W) {
    if(S[i][j]=='o' && !assigned) {
      y1=i, x1=j;
      assigned = true;
    } else if (S[i][j]=='o' && assigned) {
      y2=i, x2=j;
    }
  }
  int ans = (max(y1,y2)-min(y1,y2) + max(x1, x2)-min(x1, x2));
  cout<<ans<<endl;
}
