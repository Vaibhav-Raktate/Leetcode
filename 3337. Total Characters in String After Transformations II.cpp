#include <vector>
#include <string>
using namespace std;

class Solution {
    typedef vector<vector<int>> Matrix;
    const int M = 1e9 + 7;

    Matrix matrixMultiplication(Matrix &A, Matrix &B) {
        Matrix C(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    C[i][j] = (C[i][j] + (1LL * A[i][k] * B[k][j]) % M) % M;
                }
            }
        }
        return C;
    }

    Matrix matrixExponentiation(Matrix &base, int exponent) {
        if (exponent == 0) {
            Matrix I(26, vector<int>(26, 0));
            for (int i = 0; i < 26; i++) {
                I[i][i] = 1;
            }
            return I;
        }
        Matrix half = matrixExponentiation(base, exponent / 2);
        Matrix result = matrixMultiplication(half, half);

        if (exponent % 2 == 1) {
            result = matrixMultiplication(result, base);
        }
        return result;
    }

public:
    int lengthAfterTransformations(string s, int t, vector<int> nums) {
        vector<int> freq(26, 0);
        for (char &ch : s) {
            freq[ch - 'a']++;
        }

        Matrix T(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int add = 1; add <= nums[i]; add++) {
                T[(i + add) % 26][i]++;
            }
        }

        Matrix result = matrixExponentiation(T, t);

        vector<int> updated_freq(26, 0);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                updated_freq[i] = (updated_freq[i] + (1LL * result[i][j] * freq[j]) % M) % M;
            }
        }

        int resultlength = 0;
        for (int i = 0; i < 26; i++) {
            resultlength = (resultlength + updated_freq[i]) % M;
        }

        return resultlength;
    }
};
