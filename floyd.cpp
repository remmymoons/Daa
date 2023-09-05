#include <iostream>

class FloydWarshall {
private:
    int a[10][10];
    int n;

public:
    FloydWarshall() {
        n = 0;
    }

    void floyds() {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
        std::cout << "\nall pair shortest path matrix is:\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                std::cout << a[i][j] << "\t";
            }
            std::cout << "\n\n";
        }
    }

    int min(int x, int y) {
        if (x < y) {
            return x;
        } else {
            return y;
        }
    }

    void input() {
        std::cout << "\nEnter the number of vertices: ";
        std::cin >> n;
        std::cout << "\nEnter the cost matrix:\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                std::cin >> a[i][j];
            }
        }
    }

    void solve() {
        input();
        floyds();
    }
};

int main() {
    FloydWarshall floydWarshall;
    floydWarshall.solve();
    return 0;
}
