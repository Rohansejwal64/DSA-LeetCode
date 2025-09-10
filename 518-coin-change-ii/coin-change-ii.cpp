class Solution {
public:
int solve(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    if (amount == 0) return 1; // One valid way (by not taking any coins)

    if (index == 0) {
        // Only possible if amount is a multiple of coins[0]
        return (amount % coins[0] == 0) ? 1 : 0;
    }

    if (dp[index][amount] != -1) return dp[index][amount];

    // Not taking the current coin
    int notTake = solve(index - 1, amount, coins, dp);

    // Taking the current coin (if possible)
    int take = 0;
    if (coins[index] <= amount) {
        take = solve(index, amount - coins[index], coins, dp);
    }

    return dp[index][amount] = take + notTake;
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return solve(n - 1, amount, coins, dp);
}

};