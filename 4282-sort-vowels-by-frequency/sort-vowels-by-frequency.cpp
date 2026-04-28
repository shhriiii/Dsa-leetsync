class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();

        map<char, int> freq;
        map<char, int> firstPos;

        // count frequency + first occurrence
        for (int i = 0; i < n; i++) {
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
                freq[s[i]]++;

                if (firstPos.find(s[i]) == firstPos.end()) {
                    firstPos[s[i]] = i;
                }
            }
        }

        vector<pair<int, char>> vec;

        for (auto [ch, f] : freq) {
            vec.push_back({f, ch});
        }


        sort(vec.begin(), vec.end(), [&](auto &a, auto &b) {
            if (a.first != b.first)
                return a.first > b.first; // higher freq first

            return firstPos[a.second] < firstPos[b.second];

        });

        int j = 0;

        for (int i = 0; i < n; i++) {
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
                s[i] = vec[j].second;
                vec[j].first--;

                if (vec[j].first == 0)
                    j++;
            }
        }

        return s;
    }
};