#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

ll countSmallerOrEqual(ll x, vector<int> a, vector<int> b) {
  ll totalCount = 0;
  for (int ai: a) {
    ll count = upper_bound(ALL(b), x / ai) - b.begin();
    totalCount += count;
  }
  return totalCount;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(ALL(a));
  sort(ALL(b));

  ll lower = 0;
  ll upper = 1e+18;
  while((upper - lower) > 1L) {
    ll v = (lower + upper) / 2;
    int count = countSmallerOrEqual(v, a, b);
    if (count < k) {
      lower = v;
    } else {
      upper = v;
    }
  }
  
  cout << upper << endl;
  return 0;
}
