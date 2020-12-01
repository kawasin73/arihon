#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

const int MAX_N = 40;

int N;
ll W;
vector<ll> w, v;
vector<pair<ll, ll> > ps(1 << (MAX_N / 2));

int main() {
  cin >> N >> W;
  w.resize(N);
  v.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i] >> w[i];
  }

  int n2 = N / 2;
  for (int i = 0; i < 1 << n2; i++) {
    ll sw = 0, sv = 0;
    for (int j = 0; j < n2; j++) {
      if (i >> j & 1) {
        sw += w[j];
        sv += v[j];
      }
    }
    ps[i] = make_pair(sw, sv);
  }

  sort(ps.begin(), ps.begin() + (1 << n2));
  int m = 1;
  for (int i = 0; i < 1 << n2; i++) {
    if (ps[m-1].second < ps[i].second) {
      ps[m] = ps[i];
      m++;
    }
  }

  ll res = 0;
  for (int i = 0; i < 1 << (N - n2); i++) {
    ll sw = 0, sv = 0;
    for (int j = 0; j < N - n2; j++) {
      if (i >> j & 1) {
        sw += w[n2 + j];
        sv += v[n2 + j];
      }
    }
    if (sw <= W) {
      ll tv = (lower_bound(ps.begin(), ps.begin()+m, make_pair(W-sw, LLONG_MAX)) - 1)->second;
      res = max(res, sv + tv);
    }
  }

  cout << res << endl;
}
