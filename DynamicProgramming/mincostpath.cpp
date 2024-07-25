#include <iostream>
using namespace std;

int minCostPath_DP(int **input, int m, int n){
    int **output = new int*[m];
    for(int i = 0; i<m; i++){
        output[i] = new int[n];
    }
    output[m-1][n-1] = input[m-1][n-1];
    // filling last column;
    for(int i = m-2; i>=0; i--){
        output[i][n-1] = output[i+1][n-1] + input[i][n-1];
    }
    // filling last row;
    for(int j = n-2; j>=0; j--){
        output[m-1][j] = output[m-1][j+1] + input[m-1][j];
    }
    // filling remaining;
    for(int i = m-2; i>=0; i--){
        for(int j = n-2; j>=0; j--){
            output[i][j] = input[i][j] + min(output[i+1][j+1], min(output[i+1][j], output[i][j+1]));
        }
    }
    return output[0][0];
}
int mincostpath_mem(int ** input, int m, int n, int i, int j, int ** output){
    if(i==m-1 && j==n-1){
        return input[i][j];
    }
    if(i>=m || j>=n){
        return INT_MAX;
    }
    if(output[i][j] != -1){
        return output[i][j];
    }
    
    int x = mincostpath_mem(input, m, n, i+1, j, output);
    int y = mincostpath_mem(input, m, n, i+1, j+1, output);
    int z = mincostpath_mem(input, m, n, i, j+1, output);

    int ans = min(x, min(y, z)) + input[i][j];
    
    output[i][j] = ans;
    
    return ans;
}

int minCostPath(int ** input, int m, int n){
    int ** output = new int*[m];
    for(int i = 0; i<m; i++){
        output[i] = new int[n];
        for(int j = 0; j<n; j++){
            output[i][j] = -1;
        }
    }
    return mincostpath_mem(input, m, n, 0, 0, output);
}

int mcphelper(int ** input, int m, int n, int i, int j){
    if(i==m-1 && j==n-1){
        return input[i][j];
    }
    if(i>=m || j>=n){
        return INT_MAX;
    }
    
    int x = mcphelper(input, m, n, i+1, j);
    int y = mcphelper(input, m, n, i+1, j+1);
    int z = mcphelper(input, m, n, i, j+1);

    int ans = min(x, min(y, z)) + input[i][j];

    return ans; 
}
int  mincostpath(int **arr, int m, int n){
    return mcphelper(arr, m, n, 0, 0);
}
int main(){
    int m, n;
    cin>>m>>n;
    int **input = new int*[m];
    for(int i=0; i<m; i++){
        input[i] = new int[n];
        for(int j=0; j<n; j++){
            cin>>input[i][j];
        }
    }

    cout<<mincostpath(input, m, n)<<endl;
    cout<<minCostPath(input, m, n)<<endl;
    cout<<minCostPath_DP(input, m, n)<<endl;
}