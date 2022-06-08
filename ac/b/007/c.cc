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

int R,C,sy,sx,gy,gx;
string s[51];
int dist[51][51];
bool used[51][51];
queue<pair<int, int>>q;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
void bfs(int sy,int sx) {
  q.push(make_pair(sy,sx));
  while(!q.empty()) {
    pair<int, int> pt = q.front();q.pop();
    int y=pt.first, x=pt.second;
    used[y][x]=true;
    rep(i,0,4) {
      int ny=y+dy[i], nx=x+dx[i];
      if(used[ny][nx] ||  s[ny][nx]=='#')continue;
      dist[ny][nx] = dist[y][x] + 1;
      used[ny][nx]=true;
      q.push(make_pair(ny,nx));
    }
  }
}
int main() {
  cin>>R>>C>>sy>>sx>>gy>>gx;
  sy--,sx--,gy--,gx--;
  rep(i,0,R)cin>>s[i];

  rep(i,0,R)rep(j,0,C)dist[i][j]=MAX;
  dist[sy][sx]=0;

  bfs(sy,sx);
  cout<<dist[gy][gx]<<endl;
}
