#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

int N, x;
vector<int> a;

int main() {
  cin >> N >> x;
  a.resize(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  
  ll count = 0;
  if (a[0] > x) {
    count += a[0] - x;
    a[0] = x;
  }
  for (int i = 0; i < N-1; i++) {
    if (a[i] + a[i+1] > x) {
      count += a[i] + a[i+1] - x;
      a[i+1] = x - a[i];
    }
  }
  cout << count;
}
