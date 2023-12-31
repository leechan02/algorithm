#include <iostream>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, M;
  std::cin >> N >> M;

  int arr[N + 1][N + 1];
  int S[N + 1][N + 1];
  for (int i = 1; i <= N; ++i) {
    S[i][0] = 0;
    for (int j = 1; j <= N; ++j) {
      std::cin >> arr[i][j];
      S[i][j] = S[i][j - 1] + S[i - 1][j] - S[i - 1][j - 1] + arr[i][j];
    }
  }

  int X1, Y1, X2, Y2;
  for (int k = 0; k < M; ++k) {
    std::cin >> X1 >> Y1 >> X2 >> Y2;
    std::cout << S[X2][Y2] - S[X1 - 1][Y2] - S[X2][Y1 - 1] + S[X1 - 1][Y1 - 1]
              << '\n';
  }
  return (0);
}