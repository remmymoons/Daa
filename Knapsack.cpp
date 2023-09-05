#include <iostream>

class Knapsack {
private:
    int n, m;
    int p[10], w[10];
    int v[10][10];

public:
    Knapsack() {
        n = m = 0;
    }

    void knapsack() {
        int x[10];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    v[i][j] = 0;
                } else if (j - w[i] < 0) {
                    v[i][j] = v[i - 1][j];
                } else {
                    v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
                }
            }
        }
        std::cout << "\nthe output is:\n";
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                std::cout << v[i][j] << "\t";
            }
            std::cout << "\n\n";
        }
        std::cout << "\nthe optimal solution is " << v[n][m] << std::endl;
        std::cout << "the solution vector is:\n";
        for (int i = n; i >= 1; i--) {
            if (v[i][m] != v[i - 1][m]) {
                x[i] = 1;
                m -= w[i];
            } else {
                x[i] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            std::cout << x[i] << "\t";
        }
    }

    int max(int x, int y) {
        if (x > y) {
            return x;
        } else {
            return y;
        }
    }

    void input() {
        std::cout << "\nEnter the number of items: ";
        std::cin >> n;
        std::cout << "\nEnter the weight of each item:\n";
        for (int i = 1; i <= n; i++) {
            std::cin >> w[i];
        }
        std::cout << "\nEnter the profit of each item:\n";
        for (int i = 1; i <= n; i++) {
            std::cin >> p[i];
        }
        std::cout << "\nEnter the knapsack's capacity: ";
        std::cin >> m;
    }

    void solve() {
        input();
        knapsack();
    }
};

int main() {
    Knapsack knapsack;
    knapsack.solve();
    return 0;
}
