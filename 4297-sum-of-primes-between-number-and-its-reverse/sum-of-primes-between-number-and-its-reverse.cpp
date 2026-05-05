class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false; 
        if (n == 2)
            return true; 
        if (n % 2 == 0)
            return false; 

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int x = 0;
        int z = n;
        while (z > 0) {
            int ld = z % 10;
            x = x * 10 + ld;
            z /= 10;
        }
        int start = min(n, x);
        int end = max(n, x);
        int sum = 0;
        for (int i = start; i <= end; i++) {
            if (isPrime(i))
                sum += i;
        }
        return sum;
    }
};