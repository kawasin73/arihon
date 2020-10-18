#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

int R, C;
vector<vector<int>> a(10, vector<int>(10000));

int calc(int key) {
  int count = 0;
  for (int j = 0; j < C; j++) {
    int count_0 = 0;
    for (int i = 0; i < R; i++) {
      if ((key >> i) & 1) {
        if (a[i][j] == 1) {
          count_0++;
        }
      } else {
        if (a[i][j] == 0) {
          count_0++;
        }
      }
    }
    count += max(count_0, R - count_0);
  }
  return count;
}

int main() {
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> a[i][j];
    }
  }
  
  int result = 0;
  for (int key = 0; key < 1 << R; key++) {
    int count = calc(key);
    if (count > result) {
      result = count;
    }
  }
  
  cout << result << endl;
}
