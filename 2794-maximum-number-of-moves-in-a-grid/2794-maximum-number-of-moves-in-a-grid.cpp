class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
        
        // DFS function to calculate the maximum moves from a given cell
        auto dfs = [&](int row, int col, auto& dfs_ref) -> int {
            if (dp[row][col] != -1) return dp[row][col];
            
            int max_moves = 0;
            std::vector<std::pair<int, int>> directions = {{-1, 1}, {0, 1}, {1, 1}};
            
            for (auto [dr, dc] : directions) {
                int new_row = row + dr;
                int new_col = col + dc;
                if (new_row >= 0 && new_row < m && new_col < n && grid[new_row][new_col] > grid[row][col]) {
                    max_moves = std::max(max_moves, 1 + dfs_ref(new_row, new_col, dfs_ref));
                }
            }
            
            return dp[row][col] = max_moves;
        };
        
        // Calculate the maximum moves starting from any cell in the first column
        int result = 0;
        for (int i = 0; i < m; ++i) {
            result = std::max(result, dfs(i, 0, dfs));
        }
        
        return result;
    }
};