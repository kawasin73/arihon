#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

int n;
vector<int> h;
vector<int> s;
vector<ll> t;

bool check(ll x) {
  for (int i = 0; i < n; i++) {
    ll hi = h[i];
    ll si = s[i];
    if (x < hi) return false;
    t[i] = (x - hi) / si;
  }
  sort(ALL(t));
  for (ll i = 0; i < n; i++) {
    if (t[i] < i) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> n;
  h.resize(n);
  s.resize(n);
  t.resize(n);
  
  for (int i = 0; i < n; i++) {
    cin >> h[i] >> s[i];
  }
  
  ll lower = 0;
  ll upper = 1e+15;
  while (upper - lower > 1) {
    ll mid = (lower + upper) / 2;
    if (check(mid)) {
      upper = mid;
    } else {
      lower = mid;
    }
  }
  
  cout << upper << endl;
}
