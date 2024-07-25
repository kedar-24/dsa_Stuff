#include <iostream>
using namespace std;

int lcshelper(string s, string t){
    int m = s.size();
    int n = t.size();
    int ** output = new int*[m+1];
    for(int i = 0; i<=m; i++){
        output[i] = new int[n+1];
    }
    for(int i = 0; i<=n; i++){
        output[i][0] = 0;
    }
    for(int j = 1; j<=m; j++){
        output[0][j] = 0;
    }
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s[m-i] == t[n-j]){
                output[i][j] = 1 + output[i-1][j-1];
            }else{
                int a = output[i][j-1];
                int b = output[i-1][j];
                int c = output[i-1][j-1];

                output[i][j] = max(a, max(b, c));
            }
        }
    }
    return output[m][n];
}

int lcs_mem(string s, string t, int **output){
    int m = s.size();
    int n = t.size();
    int ans;
    if(s.size()==0 || t.size()==0){
        return 0;
    }
    if(output[m][n] != -1){
        return output[m][n];
    }
    if(s[0]==t[0]){
        ans = 1 + lcs_mem(s.substr(1), t.substr(1), output);
    }else{    
        int a = lcs_mem(s.substr(1), t, output);
        int b = lcs_mem(s, t.substr(1), output);
        int c = lcs_mem(s.substr(1), t.substr(1), output);

        ans = max(a, max(b, c));
    }
    output[m][n] = ans;
    return ans;
}

int LCS_1(string s, string t){
    int m = s.size();
    int n = t.size();
    int** output = new int*[m+1];
    for(int i=0; i<=m; i++){
        output[i] = new int[n+1];
        for(int j = 0; j<=n; j++){
            output[i][j] = -1;
        }
    }
    return lcs_mem(s, t, output);
}
int LCS(string s, string t){
    if(s.size()==0 || t.size()==0){
        return 0;
    }
    if(s[0]==t[0]){
        return 1 + LCS(s.substr(1), t.substr(1));
    }else{
        int a = LCS(s.substr(1), t);
        int b = LCS(s, t.substr(1));
        int c = LCS(s.substr(1), t.substr(1));

        return max(a, max(b, c));
    }
}
int main(){
    string s, t;
    cin>>s;
    cin>>t;
    cout<<LCS(s, t)<<endl;
    cout<<LCS_1(s, t)<<endl;
    cout<<lcshelper(s, t)<<endl;
}