#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// 1. Recursive solution (without memoization)
int countWaysRecursive(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    int ways = 0;
    for (int i = 1; i <= 6; ++i) {
        ways = ways + countWaysRecursive(n - i);
    }
    return ways;
}

// 2. Top-down DP (Memoization)
int countWaysTopDown(int n, vector<int>& dp) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    if (dp[n] != -1) return dp[n];

    int ways = 0;
    for (int i = 1; i <= 6; ++i) {
        ways = (ways + countWaysTopDown(n - i, dp)) % MOD;
    }

    dp[n] = ways;  // Memoize the result
    return dp[n];
}

// 3. Bottom-up DP (Tabulation)
int countWaysBottomUp(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;  // There's one way to make sum 0

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    // 1. Recursive solution
    cout << "Recursive Solution: " << countWaysRecursive(n) << endl;

    // 2. Top-down DP
    vector<int> dp(n + 1, -1);
    cout << "Top-down DP Solution: " << countWaysTopDown(n, dp) << endl;

    // 3. Bottom-up DP
    cout << "Bottom-up DP Solution: " << countWaysBottomUp(n) << endl;

    return 0;
}
