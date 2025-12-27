class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>> end;

        priority_queue<int, vector<int>, greater<int>> free;

        for (int i = 0; i < n; i++) free.push(i);

        vector<int> freq(n, 0);

        for (auto &meet : meetings) {
            long long start = meet[0];
            long long finish = meet[1];

            while (!end.empty() && end.top().first <= start) {
                free.push(end.top().second);
                end.pop();
            }

            if (!free.empty()) {
                int room = free.top(); free.pop();
                end.push({finish, room});
                freq[room]++;
            } else {
     
                auto [endTime, room] = end.top();
                end.pop();
                long long newEnd = endTime + (finish - start);
                end.push({newEnd, room});
                freq[room]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (freq[i] > freq[ans]) ans = i;
        }
        return ans;
    }
};
