#include <iostream>

class BinomialCoefficient {
public:

    int bin(int n, int k) {
        int c[10][10]; 
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j == 0 || i == j)
                    c[i][j] = 1;
                else
                    c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            }
        }
        return c[n][k];
    }

    void calculate() {
        int n, k;
        std::cout << "Enter the value of n & k such that n > k: ";
        std::cin >> n >> k;
        std::cout << "C(" << n << "," << k << ") = " << bin(n, k) << std::endl;
    }
};

int main() {
    BinomialCoefficient bc;
    bc.calculate();
    return 0;
}
