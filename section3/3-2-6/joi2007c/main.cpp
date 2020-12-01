#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

int N, M;
vector<int> P;
vector<int> PP;

int main() {
  cin >> N >> M;
  P.resize(N+1);
  P[0] = 0;
  for (int i = 0; i < N; i++) {
    cin >> P[i+1];
  }
  for (int i = 0; i < N+1; i++) {
    for (int j = 0; j < N+1; j++) {
      if (P[i] + P[j] <= M) {
        PP.push_back(P[i] + P[j]);
      }
    }
  }
  sort(ALL(PP));
  int result = 0;

  for (int i = 0; i < PP.size(); i++) {
    int p2 = *(upper_bound(ALL(PP), M-PP[i]) - 1);
    if (p2 + PP[i] > result) {
      result = p2 + PP[i];
    }
  }

  cout << result << endl;
}
