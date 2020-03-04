#include <iostream>
#include <fstream>
using namespace std;

int * splittoi(const string& str, int n) {
    int * arr = new int[n];
    string token;
    for (auto x : str) {
        if (x == ' ') {
            *arr = stoi(token);
            arr++;
            token = "";
        }
        else {
            token += x;
        }
    }
    *arr = stoi(token);
    arr -= n;
    return arr;
}

int main() {
    size_t N;

    ifstream in("/Users/irusland/Desktop/UrFU/C++/lab1/in.txt");
//    ifstream in("/Users/irusland/Desktop/UrFU/C++/lab1/6n3comp.txt");

    if (!in) {
        cout << "Cannot open input file" << std::endl;
        return 1;
    }

    string str;
    getline(in, str);
    N = stoi(str);

    int matrix[N][N];
    for (int i = 0; i < N; ++i) {
        std::getline(in, str);

        int * arr = splittoi(str, N);
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = arr[j + 1];
        }
    }
    in.close();

    int v = -1;
    for (int i = 0; i < N; ++i) {
        if (matrix[i][i] == 0) {
            v = i;
            break;
        }
    }
    stack<int> plan;
    int counter = 0;
    while (v != -1) {
        counter++;
        plan.push(v);
        matrix[v][v] = counter; // принадлежит counter компонете

        while (!plan.empty()) {
            v = plan.top();
            plan.pop();
            for (int u = 0; u < N; u++) {
                if (matrix[v][u] and matrix[u][u] == 0) {
                    plan.push(u);
                    matrix[u][u] = counter; // принадлежит counter компонете
                }
            }
        }
        v = -1;
        for (int i = 0; i < N; ++i) {
            if (matrix[i][i] == 0) {
                v = i;
                break;
            }
        }
    }

    // debug matrix
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < N; ++j) {
//            cout << matrix[i][j];
//        }
//        cout << endl;
//    }

    // колличество компонент
    cout << counter << endl;

    for (int k = 1; k <= counter; ++k) {
        for (int i = 0; i < N; ++i) {
            if (matrix[i][i] == k) {
                cout << i + 1; // вершина в компоненте k
            }
        }
        cout << 0 << endl;
    }

    return 0;
}
