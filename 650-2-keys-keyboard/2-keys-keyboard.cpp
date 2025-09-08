class Solution {
public:
    int helper(int n, int screenVisible, int buffer, int flag) {
        if (screenVisible == n) return 0;
        if (screenVisible > n) return 1e9;

        if (screenVisible == n) {
            return 0;
        }

        int copy = 1e9, paste = 1e9;
        if (!flag) {
            copy = 1 + helper(n, screenVisible, screenVisible, 1);
        }
        if (buffer > 0) {
            paste = 1 + helper(n, screenVisible + buffer, buffer, 0);
        }
        return min(copy, paste);

        return min(copy, paste);
    }
    int minSteps(int n) {
        if (n == 1)
            return 0;
        if (n >= 2 && n <= 5)
            return n;

        return helper(n, 1, 0, 0);
    }
};