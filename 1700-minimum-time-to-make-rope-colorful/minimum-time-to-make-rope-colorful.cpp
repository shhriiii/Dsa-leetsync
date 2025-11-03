class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();

        int i = 1;
        bool isSame = false;
        int total = 0;

        while (i < n) {
            if (colors[i] != colors[i - 1]) {
                isSame = false;

            } else {
                int maxTime = INT_MIN;
                isSame = true;
                int sum = neededTime[i - 1];
                while (isSame && i < n) {
                    if (colors[i] != colors[i - 1]) {
                        isSame = false;
                        int rem = sum - maxTime;
                        total += rem;
                        cout << "currSum till i " << i << " " << sum
                             << "  remove" << rem << endl;
                    } else {
                        maxTime =
                            max({maxTime, neededTime[i - 1], neededTime[i]});
                        sum += neededTime[i];
                        i++;
                    }
                }
                if (i == n && isSame == true) {
                    int rem = sum - maxTime;
                    total += rem;
                }
            }
            i++;
        }
        return total;
    }
};

// int total
// a b a a a a c
//             i
//  bool isSame = true;
// min = maxTime(time (i,i-1))
//  total +=minm;

// a b a a a a c
//     2 1 3 4 = 10;
//     2 2 3 4  = 4
// 10 -  4 = 6;
