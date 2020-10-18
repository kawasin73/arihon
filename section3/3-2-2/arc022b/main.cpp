#include <bits/stdc++.h>
using namespace std;
#define ALL(a)  (a).begin(),(a).end()
typedef int long long ll;

int N;
vector<int> A;
set<int> S;

int main() {
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  int result = 0;
  int right = 0;
  for (int left = 0; left < N; left++) {
    while (right < N && S.find(A[right]) == S.end()) {
      S.insert(A[right]);
      right++;
    }
    if (right - left > result) {
      result = right - left;
    }

    if (right == left) {
      continue;
    }
    S.erase(A[left]);
  }

  cout << result << endl;
}
