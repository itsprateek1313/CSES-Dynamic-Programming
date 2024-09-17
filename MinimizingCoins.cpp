#include <iostream>
#include <vector>
#include <climits>

const int MOD = 1000000007;
using namespace std;
int minCoinsDP(int amount, const vector<int>& coins,vector<int>& dp) {
    // Base case: if sum is 0, no coins are needed
    if (amount == 0) return 0;
    
    // If the sum becomes negative return infinity indicating no solution
    if (amount < 0) return INT_MAX;

    if(dp[amount]!=-1) return dp[amount];
    
    int result = INT_MAX;
    
    // Try every coin and see which one gives the minimum number of coins
    for (int coin : coins) {
        int sub_result = minCoinsDP(amount - coin, coins,dp);
        
        // If sub_result is valid, update the result
        if (sub_result != INT_MAX) {
            result = min(result, sub_result + 1);
        }
    }
    dp[amount] = result;
    return dp[amount];
}

int main() {
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int dp_size = amount;
    vector<int> dp(dp_size+1,-1);
    int result = minCoinsDP(amount, coins,dp);

    if (result == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}
