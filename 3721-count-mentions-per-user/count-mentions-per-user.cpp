class Solution {
public:
    vector<int> countMentions(int nu, vector<vector<string>>& events) {
        vector<int> mentions(nu, 0);
        sort(events.begin(), events.end(),
             [](const vector<string>& a, const vector<string>& b) {
                 int ta = stoi(a[1]), tb = stoi(b[1]);
                 if (ta == tb)
                     return a[0][0] > b[0][0];
                 return ta < tb;
             });
        unordered_map<int, int> offline;
        for (int i = 0; i < events.size(); i++) {
            vector<string> curr = events[i];
            if (curr[0] == "MESSAGE") {
                int currTs = stoi(curr[1]);
                for (auto it = offline.begin(); it != offline.end();) {
                    if (it->second <= currTs)
                        it = offline.erase(it);
                    else
                        ++it;
                }
                if (curr[2] == "ALL") {
                    for (int user = 0; user < nu; user++) {
                        mentions[user]++;
                    }
                } else if (curr[2] == "HERE") {
                    for (int user = 0; user < nu; user++) {
                        if (offline.find(user) == offline.end()) {
                            mentions[user]++;
                        }
                    }
                } else {
                    string ids = curr[2];
                    int n = ids.size();
                    for (int i = 0; i < n; i++) {
                        if (ids[i] == 'i' && i + 1 < n && ids[i + 1] == 'd') {
                            i += 2;
                            int num = 0;
                            while (i < n && isdigit(ids[i])) {
                                num = num * 10 + (ids[i] - '0');
                                i++;
                            }
                            if (num < nu)
                                mentions[num]++;
                        }
                    }
                }
            } else {
                int timeStaoffline = stoi(curr[1]);
                offline[stoi(curr[2])] = timeStaoffline + 60;
            }
        }
        return mentions;
    }
};
