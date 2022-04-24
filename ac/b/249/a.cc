#include <iostream>
#include <iomanip>
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

int f(int sec, int speed, int stop, int x) {
  int dist = 0;
  while(x>0) {
    if (x-sec<0) {
      rep(i,0,sec) {
        if (x-i<0) {
          dist += (i-1)*speed;
          break;
        } else if (x-i==0) {
          dist += (i)*speed;
          break;
        }
      }
    } else {
      dist += speed * sec;
      x -= sec;
    }
    x-=stop;
  }

  return  dist;
}

int main() {
  int t_sec, t_speed, t_stop, a_sec, a_speed, a_stop, x;
  cin>>t_sec>>t_speed>>t_stop>>a_sec>>a_speed>>a_stop>>x;
  
  int t_dist = f(t_sec, t_speed, t_stop, x);
  int a_dist = f(a_sec, a_speed, a_stop, x);

  cout<<((t_dist>a_dist) ? "Takahashi" : (t_dist == a_dist) ? "Even" : "Aoki") <<endl;
}

