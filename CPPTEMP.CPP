#include <iostream>
using namespace std;


void solve() {
  int n;
  cin >> n;
  vector<long long> vi(n);
  for(auto &x : vi) cin >> x;
  long long ans = 0;
  ans += vi[0]-1;
  for(int i = 1 ; i < n ; i++) {
    if(vi[i] > vi[i-1]) {
      ans += vi[i] - vi[i-1];
    }
  }
  cout<<ans<<"\n";
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}