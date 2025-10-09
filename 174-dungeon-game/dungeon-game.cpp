class Solution {
public:
 int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        // dp[i][j] = minimum health needed when entering cell (i, j)
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, INT_MAX));

        // Set boundary conditions to 1 to simplify the min() calculation in the loops.
        // This simulates a "safe" path beyond the grid boundaries.
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;

        // Iterate backwards from the princess's cell
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // Minimum health required for the next step (from either the room below or to the right)
                int min_health_for_next_step = std::min(dp[i + 1][j], dp[i][j + 1]);
                
                // Calculate the health needed *before* this room's effect is applied.
                int health_needed = min_health_for_next_step - dungeon[i][j];
                
                // The health upon entering must be at least 1. If health_needed is negative
                // (e.g., the room has a health potion), we still only need 1 health to enter.
                dp[i][j] = std::max(1, health_needed);
            }
        }

        // The answer is the minimum health needed at the starting cell (0, 0)
        return dp[0][0];
    }
};