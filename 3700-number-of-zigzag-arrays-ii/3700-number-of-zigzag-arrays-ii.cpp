class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int sz = A.size();
        Matrix C(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; ++i) {
            for (int k = 0; k < sz; ++k) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < sz; ++j) {
                    if (B[k][j] == 0) continue;

                    C[i][j] =
                        (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int sz = base.size();

        Matrix res(sz, vector<long long>(sz, 0));

        for (int i = 0; i < sz; ++i)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        // up[u] -> down[v] if u > v
        for (int u = 0; u < m; ++u) {
            for (int v = 0; v < u; ++v) {
                T[m + v][u] = 1;
            }
        }

        // down[u] -> up[v] if u < v
        for (int u = 0; u < m; ++u) {
            for (int v = u + 1; v < m; ++v) {
                T[v][m + u] = 1;
            }
        }

        vector<long long> dp(S, 0);

        // length = 2
        for (int a = 0; a < m; ++a) {
            for (int b = 0; b < m; ++b) {
                if (a == b) continue;

                if (a < b)
                    dp[b] = (dp[b] + 1) % MOD;      // up[b]
                else
                    dp[m + b] = (dp[m + b] + 1) % MOD; // down[b]
            }
        }

        Matrix P = power(T, n - 2);

        vector<long long> ans(S, 0);

        for (int i = 0; i < S; ++i) {
            if (dp[i] == 0) continue;

            for (int j = 0; j < S; ++j) {
                ans[j] =
                    (ans[j] + P[j][i] * dp[i]) % MOD;
            }
        }

        long long res = 0;

        for (int i = 0; i < S; ++i)
            res = (res + ans[i]) % MOD;

        return (int)res;
    }
};