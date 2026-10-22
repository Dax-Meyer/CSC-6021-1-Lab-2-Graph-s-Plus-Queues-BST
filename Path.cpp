// PathUtils.tpp
#include <iostream>
#include "Path.h"
using namespace std;

template <typename T>
void print_path(const vector<T>& path) {
    if (!path.empty()) {
        cout << "\n=== Shortest Path Found ===" << endl;
        cout << "Route: ";
        for (int i = 0; i < (int)path.size(); i++) {
            cout << path[i];
            if (i < (int)path.size() - 1) cout << " → ";
        }
        cout << endl;
        cout << "Total hops: " << path.size() - 1 << endl;
    }
}
