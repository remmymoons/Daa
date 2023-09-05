#include <iostream>
#include <climits>

class Dijkstra {
private:
    int c[10][10];
    int n, src;

public:
    Dijkstra() {
        n = src = 0;
    }

    void input() {
        std::cout << "\nEnter the number of vertices: ";
        std::cin >> n;
        std::cout << "\nEnter the cost matrix:\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                std::cin >> c[i][j];
            }
        }
        std::cout << "\nEnter the source node: ";
        std::cin >> src;
    }

    void dijkstras() {
        int vis[10], dist[10], u, count, min;
        for (int j = 1; j <= n; j++) {
            dist[j] = c[src][j];
        }
        for (int j = 1; j <= n; j++) {
            vis[j] = 0;
        }
        dist[src] = 0;
        vis[src] = 1;
        count = 1;
        while (count != n) {
            min = INT_MAX;
            for (int j = 1; j <= n; j++) {
                if (dist[j] < min && vis[j] != 1) {
                    min = dist[j];
                    u = j;
                }
            }
            vis[u] = 1;
            count++;
            for (int j = 1; j <= n; j++) {
                if (min + c[u][j] < dist[j] && vis[j] != 1) {
                    dist[j] = min + c[u][j];
                }
            }
        }
        std::cout << "\nThe shortest distance is:\n";
        for (int j = 1; j <= n; j++) {
            std::cout << src << "----->" << j << "=" << dist[j] << std::endl;
        }
    }

    void solve() {
        input();
        dijkstras();
    }
};

int main() {
    Dijkstra dijkstra;
    dijkstra.solve();
    return 0;
}
