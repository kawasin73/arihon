#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

// https://atcoder.jp/contests/abc018/submissions/17283028

int N, M, P, Q, R;
vector<int> x, y, z;

int calc(int key) {
  vector<int> points(M);
  for (int i = 0; i < R; i++) {
    if (key >> x[i] & 1) {
      points[y[i]] += z[i];
    }
  }
  sort(ALL(points));
  reverse(ALL(points));
  int point = 0;
  for (int i = 0; i < Q; i++) {
    point += points[i];
  }
  return point;
}

int main() {
  cin >> N >> M >> P >> Q >> R;
  x.resize(R);
  y.resize(R);
  z.resize(R);
  for (int i = 0; i < R; i++) {
    cin >> x[i] >> y[i] >> z[i];
    x[i]--;
    y[i]--;
  }

  int result = 0;
  for (int key = 0; key < 1 << N; key++) {
    int count = 0;
    for (int i = 0; i < N; i++) {
      if (key >> i & 1) count++;
    }
    if (count != P) continue;
    
 	int point = calc(key);
    if (point > result) result = point;
  }
  
  cout << result << endl;
}
