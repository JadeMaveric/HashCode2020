#include <iostream>
#include <stdlib.h>

#define DEBUG false

using std::cout;
using std::cin;
using std::endl;

int knapsack(int N, int W, int* v, int* w, int* k);

int main() {
    /* INPUTS AND DATASTRUCTURES */
    int N, W;           // Number of items, Max weight
    int* v, * w, * k;     // value array, weight array, knapsack matrix

    cout << "# of elements: ";
    cin >> N;

    cout << "Knapsack Cap: ";
    cin >> W;

    v = new int[N];
    w = new int[N];
    k = new int[(N + 1) * (W + 1)];

    for (int i = 1; i <= N; i++) {
        cout << "Item #" << i << "\n"
            << "Value: ";
        cin >> v[i];
        cout << "Weight: ";
        cin >> w[i];
        cout << "\n";
    }
    knapsack(N, W, v, w, k);  //calling knapsack function

    return 0;
}

int knapsack(int N, int W, int* v, int* w, int* k) {
    /* START OF KNAPSACK */
    // Intialise base case
    for (int i = 0; i <= W; i++) k[i] = 0;
    for (int i = 0; i <= N; i++) k[i * W] = 0;

    for (int item = 1; item <= N; item++) {
        for (int weight = 1; weight <= W; weight++) {
            int curr_item_value = (w[item] <= weight ? v[item] : 0)
                + (weight - w[item] > 0 ? k[(item - 1) * W + weight - w[item]] : 0);
            int prev_item_value = k[(item - 1) * W + weight];
            k[(item)*W + weight] = curr_item_value > prev_item_value ? curr_item_value : prev_item_value; // Choose best value (max)

            if (DEBUG) cout << k[(item)*W + weight] << "\t";
        }
        if (DEBUG) cout << endl;
    }
    cout << "MAX: " << k[N * W + W] << endl;  //printing final o/p
    return 0;
}

