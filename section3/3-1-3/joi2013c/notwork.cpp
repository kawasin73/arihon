#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

int n;
vector<int> a;

bool check(ll k) {
  // x >= k, y >= x -> z >= x
  ll x = 0, y = 0, z = 0;
  int xi, yi, zi = 0;
  for (xi = 0; x < k && xi < n; xi++) {
    x += a[xi];
  }
  for (yi = xi; y < x && yi < n; yi++) {
    y += a[yi];
  }
  for (zi = yi; zi < n; zi++) {
    z += a[zi];
  }
  zi = 0;
  if (x < k) {
    return false;
  }
  
  while (zi < n) {
    if (y >= x && z >= x) {
      return true;
    }
    
    // move x - y 1 block
    if (xi >= n) xi = 0;
    y -= a[xi];
    x += a[xi];
    xi++;

    // shrink x by moving z - x
    while (x - a[zi] >= k) {
      x -= a[zi];
      z += a[zi];
      zi++;
      if (zi >= n) break;
    }
    
    // update y - z
    for (; y < x && z - a[yi] >= 0; yi++) {
      if (yi >= n) yi = 0;
      z -= a[yi];
      y += a[yi];
    }
  }
  return y >= x && z >= x;
}

int main() {
  cin >> n;
  a.resize(n);
  
  ll total = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    total += a[i];
  }
  
  
  ll lower = 0;
  ll upper = total / 3 + 1;
  
  while(upper - lower > 1) {
    ll mid = (upper + lower) / 2;
    if (check(mid)) {
      lower = mid;
      //cout << "ok:" << mid << endl;
    } else {
      upper = mid;
      //cout << "ng:" << mid << endl;
    }
  }
  
  cout << lower << endl;
}
