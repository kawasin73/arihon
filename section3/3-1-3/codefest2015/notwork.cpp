#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

int n;
int m;
vector<int> x;

bool canCover(int k) {
  int covered = 0;
  for (int i = 0; i < m; i++) {
    //cout << "current :" << covered << endl;
    int left = (x[i] - 1 - covered);
    if (left <= 0) {
      covered = max(covered, x[i] + k);
      //cout << "covered" << endl;
    } else if (left > k) {
      //cout << "not ok" << endl;
      return false;
    } else {
      int right1 = (k - left) / 2;
      int right2 = k - left * 2;
      covered = x[i] + max(right1, right2);
    }
  }
  return covered >= n;
}

int main() {
  cin >> n >> m;
  x.resize(m);
  for (int i = 0; i < m; i++) cin >> x[i];
  
  int lower = 0;
  int upper = 2 * n;
  while(upper - lower > 1) {
    int mid = (lower + upper) / 2;
    if (canCover(mid)) {
      upper = mid;
      //cout << "ok" << mid << endl;
    } else {
      lower = mid;
      //cout << "ng" << mid << endl;
    }
  }
  
  cout << upper << endl;
}
