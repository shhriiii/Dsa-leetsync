class Solution {
public:
    vector<vector<int>> t;

    int solve(int currCountA, int pasteCountA, int n) {
        if (currCountA == n) return 0;
        if (currCountA > n) return 1000;

        if (t[currCountA][pasteCountA] != -1) {
            return t[currCountA][pasteCountA];
        }

        int copyPaste = 2 + solve(currCountA + currCountA, currCountA, n);
        int paste = 1e9;
        if (pasteCountA > 0) {
            paste = 1 + solve(currCountA + pasteCountA, pasteCountA, n);
        }

        return t[currCountA][pasteCountA] = min(copyPaste, paste);
    }

    int minSteps(int n) {
        if (n == 1) return 0;
        t.assign(n + 1, vector<int>(n + 1, -1));
        return 1 + solve(1, 1, n);
    }
};
