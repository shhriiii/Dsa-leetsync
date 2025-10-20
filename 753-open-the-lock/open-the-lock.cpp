#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1; 
        if (target == "0000") return 0;


        queue<pair<int, string>> pq;
        pq.push({0, "0000"});

        set<string> vis;
        vis.insert("0000");

        while (!pq.empty()) {
            auto [step, curr] = pq.front();
            pq.pop();

            if (curr == target)
                return step;
            for (int i = 0; i < 4; i++) {
                char ch = curr[i];
                string temp = curr;
                temp[i] = (ch == '9') ? '0' : ch + 1;
                if (!dead.count(temp) && !vis.count(temp)) {
                    vis.insert(temp);
                    pq.push({step + 1, temp});
                }

                temp[i] = (ch == '0') ? '9' : ch - 1;
                if (!dead.count(temp) && !vis.count(temp)) {
                    vis.insert(temp);
                    pq.push({step + 1, temp});
                }
            }
        }

        return -1; 
    }
};
