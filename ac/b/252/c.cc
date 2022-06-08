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

int N, nums[10];
char ss[100][10];
int main() {
  cin>>N;
  rep(i,0,N)rep(j,0,10)cin>>ss[i][j];


  vector<int>dup(10);
  rep(num,0,10) {
    rep(i,0,N) {
      rep(j,0,10) {
        //cout<<ss[i][j] << ' ' << num << endl;
        if(ss[i][j]==num+'0'){
          dup.push_back(j);
          sort(dup.begin(), dup.end());
          if(binary_search(dup.begin(), dup.end(), j))nums[num]+=10;
          break;
        }
      }
    }
    nums[num]+=*max_element(dup.begin(), dup.end());
    dup.clear();
  }
  rep(i,0,10)cout<<nums[i]<<' ';
  cout<<'\n';
  cout<<*min_element(nums, nums+10)<<endl;

}
