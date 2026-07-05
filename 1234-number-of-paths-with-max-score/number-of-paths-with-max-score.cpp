class Solution {
public:
    int mod = 1e9 + 7;

    vector<vector<int>> dp;
    vector<vector<int>> ways;
    vector<vector<int>> vis;

    // Maximum score from (i,j) to E
    int helper(vector<string>& board, int i, int j) {

        if (i < 0 || j < 0 || board[i][j] == 'X')
            return INT_MIN;

        if (i == 0 && j == 0)
            return 0;

        if (vis[i][j])
            return dp[i][j];

        vis[i][j] = 1;

        int left = helper(board, i, j - 1);
        int up = helper(board, i - 1, j);
        int diagonal = helper(board, i - 1, j - 1);

        int best = max({left, up, diagonal});

        if (best == INT_MIN)
            return dp[i][j] = INT_MIN;

        int val = 0;
        if (board[i][j] >= '1' && board[i][j] <= '9')
            val = board[i][j] - '0';

        return dp[i][j] = best + val;
    }

    // Number of paths giving maximum score
    int helper2(vector<string>& board, int i, int j) {

        if (i < 0 || j < 0 || board[i][j] == 'X')
            return 0;

        if (i == 0 && j == 0)
            return 1;

        if (ways[i][j] != -1)
            return ways[i][j];

        long long ans = 0;

        int val = 0;
        if (board[i][j] >= '1' && board[i][j] <= '9')
            val = board[i][j] - '0';

        // Left
        if (j - 1 >= 0 &&
            dp[i][j - 1] != INT_MIN &&
            dp[i][j] == dp[i][j - 1] + val)
            ans += helper2(board, i, j - 1);

        // Up
        if (i - 1 >= 0 &&
            dp[i - 1][j] != INT_MIN &&
            dp[i][j] == dp[i - 1][j] + val)
            ans += helper2(board, i - 1, j);

        // Diagonal
        if (i - 1 >= 0 &&
            j - 1 >= 0 &&
            dp[i - 1][j - 1] != INT_MIN &&
            dp[i][j] == dp[i - 1][j - 1] + val)
            ans += helper2(board, i - 1, j - 1);

        return ways[i][j] = ans % mod;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();
        int m = board[0].size();

        dp.assign(n, vector<int>(m, 0));
        vis.assign(n, vector<int>(m, 0));

        int score = helper(board, n - 1, m - 1);

        if (score == INT_MIN)
            return {0, 0};

        ways.assign(n, vector<int>(m, -1));

        int cnt = helper2(board, n - 1, m - 1);

        return {score, cnt};
    }
};