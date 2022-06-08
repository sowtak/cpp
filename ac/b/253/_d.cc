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

int N,A,B,i;
ll sum;
int main() {
  cin>>N>>A>>B;
  vector<bool>used(N+1, false);
  sum=(N-1)*(N/2L);
  cout<<sum<<endl;
  for(i=3;i<=N/3;i+=3){
    if(used[i])continue;
    sum-=i;used[i]=true;
  }
  for(i=15;i<=N/15;i+=15) {
    if(used[i])continue;
    sum-=i;used[i]=true;
  }
  for(i=5;i<=N/5;i+=5) {
    if(used[i])continue;
    sum-=i;used[i]=true;
  }
  cout<<sum<<endl;
}
