#include <iostream>
using namespace std;

int knapsack_1(int *weights, int * values, int n, int maxweight, int** output){
    if(n < 0 ){
        return 0;
    }

    if(output[maxweight][n] != -1){
        return output[maxweight][n];
    }
    if(weights[n] > maxweight){
        output[maxweight][n] = knapsack_1(weights, values, n-1, maxweight, output);
        return output[maxweight][n];
    }
    int x = knapsack_1(weights, values, n-1, maxweight - weights[n], output) + values[n];
    int y = knapsack_1(weights, values, n-1, maxweight, output);

    output[maxweight][n] = max(x, y);

    return output[maxweight][n];
}
int knapsack_mem(int *weights, int * values, int n, int maxweight){
    int ** output = new int*[maxweight+1];
    for(int i = 0; i<=maxweight; i++){
        output[i] = new int[n];
        for(int j = 0; j<n; j++){
            output[i][j] = -1;
        }
    }
    return knapsack_1(weights, values, n-1, maxweight, output);
}
int knapsack(int * weights, int * values, int n, int maxweight){
    if(n==0 || maxweight == 0){
        return 0;
    }

    if(weights[0] > maxweight){
        return knapsack(weights + 1, values + 1, n-1, maxweight);
    }
    int x = knapsack(weights + 1, values + 1, n-1, maxweight - weights[0]) + values[0];
    int y = knapsack(weights + 1, values + 1, n-1, maxweight);

    return max(x, y);
}
int main(){
    int n;
    int weights[] = {5, 1, 8, 9, 2};
    int values[] = {4, 10, 2, 3, 1};
    int w = 15;

    cout<<knapsack(weights, values, 5, w)<<endl;
    cout<<knapsack_mem(weights, values, 5, w)<<endl;
}