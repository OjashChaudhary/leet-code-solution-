class Solution {
public:
    int numberOfSets(int n, int k) {
        long long mod = 1000000007;
        long long ans = 1;

        for (int i = 1; i <= 2 * k; i++) {
            ans = ans * (n + k - i) % mod;

            long long a = i;
            long long b = mod - 2;
            long long power = 1;

            while (b > 0) {
                if (b % 2 == 1)
                    power = power * a % mod;

                a = a * a % mod;
                b /= 2;
            }

            ans = ans * power % mod;
        }

        return ans;
    }
};