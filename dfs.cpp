//
// Created by Ruslan Sirazhetdinov on 03.03.2020.
//
#include <iostream>
#include <stack>
using namespace std;
int main() {
    // чтение исходных данных
    int n, v;
    cin >> n >> v;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    stack <int> plan; // план посещения в виде стека
    plan.push(--v);   // мы нумеруем с 0, а не с 1
    matrix[v][v] = 1; // отмечаем, что эта вершина уже заносилась в план
    int counter = 1;  // начальную уже сосчитали
    while (!plan.empty()) {
        v = plan.top(); // посещаем следующую по плану вершину
        plan.pop();       // удаляем ее из плана посещения
        for (int u = 0; u < n; u++) { // перебираем соседние с ней
            if (matrix[v][u] and !matrix[u][u]) { // если инцедентна и новая, то
                plan.push(u);     // добавляем ее в план
                matrix[u][u] = 1; // отмечаем, что уже не новая
                counter++;        // считаем, сколько было вершин
            }
        }
    }
    cout << counter << endl;
}