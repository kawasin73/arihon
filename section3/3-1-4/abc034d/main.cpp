#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

int n, k;
vector<int> w, p;
vector<double> m;

bool check(double x) {
  for (int i = 0; i < n; i++) {
    double a = (double) p[i] * (double) w[i];
    double b = x * (double) w[i];
    m[i] = a - b;
  }
  sort(ALL(m));
  reverse(ALL(m));
  double total = 0;
  for (int i = 0; i < k; i++) {
    total += m[i];
  }
  return total >= 0;
}

int main() {
  cin >> n >> k;
  w.resize(n);
  p.resize(n);
  m.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> p[i];
  }
  
  double lower = 0;
  double upper = 100;
  for (int i = 0; i < 100; i++) {
    double mid = (lower + upper) / 2;
    if (check(mid)) {
      lower = mid;
    } else {
      upper = mid;
    }
  }
  
  cout << lower << endl;
}
