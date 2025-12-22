#define ll long long
class Solution {
public:
    long long lastInteger(long long n) {
        ll l = 1, r = n;

        bool left = true;
        bool right = false;
        int step = 0;

        while (n > 1) {
            if ((n) % 2 == 0) {
                if (left) {
                    r = r - pow(2, step);
                    left = false;
                    right = true;
                } else {
                    l = l + pow(2, step);
                    right = false;
                    left = true;
                }

            }
            //  n odd hai
            else {
                if (left) {
                    left = false;
                    right = true;

                }
                //  r to l
                else {

                    right = false;
                    left = true;
                }
            }
            n = (n + 1) / 2;
            step++;
        }
        return l;
    }
};