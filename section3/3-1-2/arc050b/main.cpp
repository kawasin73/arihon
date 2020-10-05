#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;


int main() {
  ll r, b, x, y;
  cin >> r >> b >> x >> y;
  
  ll lower = 0;
  ll upper = min(r, b) + 1;

  while (upper - lower > 1) {
    ll mid = (upper + lower) / 2;
    ll groupA = (r - mid) / (x - 1);
    ll groupB = (b - mid) / (y - 1);
    if (groupA + groupB < mid) {
      upper = mid;
    } else {
      lower = mid;
    }
  }
  
  cout << lower << endl;
}
