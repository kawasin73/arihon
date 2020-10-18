#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

int N, Q;
vector<int> a;
vector<ll> x;

ll calc(ll max) {
  ll result = 0;
  int left = 0;
  int right = 0;
  ll sum = 0;
  while (left < N) {
    for (; right < N && sum + a[right] <= max; right++) {
      sum += a[right];
    }
    result += right - left;

    if (right == left) {
      sum += a[right];
      right++;
    }

    sum -= a[left];
    left++;
  }
  return result;
}

int main() {
  cin >> N >> Q;
  a.resize(N);
  x.resize(Q);
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < Q; i++) cin >> x[i];

  for (int i = 0; i < Q; i++) {
    cout << calc(x[i]) << endl;
  }
}
