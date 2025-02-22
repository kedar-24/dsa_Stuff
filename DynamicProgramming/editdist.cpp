#include <iostream>
using namespace std;

void editDistance_DP(string s, string t){
    int m = s.size();
    int n = t.size();
    int ** output = new int*[m+1];
    for(int i = 0; i<=m; i++){
        output[i] = new int[n+1];
    }
    for(int i=0; i<=m; i++){
        output[i][0] = i;
    } 
    for(int j=1; j<=n; j++){
        output[0][j] = j;
    }
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s[m-i] == t[n-j]){
                output[i][j] = output[i-1][j-1];
            }else{
                int a = output[i-1][j];
                int b = output[i][j-1];
                int c = output[i-1][j-1];
                output[i][j] = min(a, min(b, c)) + 1;
            }
        }
    }

    return output[m][n];

}
int editDistance_mem(string s, string t, int ** output){
    int m = s.size();
    int n = t.size();
    if(s.size()==0 || t.size()==0){
        return max(s.size(), t.size());
    }

    if(output[m][n] != -1){
        return output[m][n];
    }
    int ans;
    if(s[0] == t[0]){
        ans = editDistance_mem(s.substr(1), t.substr(1), output);
    }else{
        int i = editDistance_mem(s.substr(1), t, output) + 1;
        int d = editDistance_mem(s, t.substr(1), output) + 1;
        int r = editDistance_mem(s.substr(1), t.substr(1), output) + 1;

        ans = min(i, min(d, r));
    }
    output[m][n] = ans;

    return ans;
}
int editDistance_1(string s, string t){
    int m = s.size();
    int n = t.size();
    int ** output = new int*[m+1];
    for(int i = 0; i<=m; i++){
        output[i] = new int[n+1];
        for(int j = 0; j<=n; j++){
            output[i][j] = -1;
        }
    }
    return editDistance_mem(s, t, output);
}

int editDistance(string s, string t){
    if(s.size()==0 || t.size()==0){
        return max(s.size(), t.size());
    }

    if(s[0] == t[0]){
        return editDistance(s.substr(1), t.substr(1));
    }else{
        int i = editDistance(s.substr(1), t) + 1;
        int d = editDistance(s, t.substr(1)) + 1;
        int r = editDistance(s.substr(1), t.substr(1)) + 1;

        return min(i, min(d, r));
    }
}
int main(){
    string s = "abcdefabcdefabcdefabcdefabcdefabcdefabcdefabcdef";
    string t = "afdiafdafdafd";

    cout<<editDistance_1(s,t)<<endl;
    //cout<<editDistance(s,t)<<endl;
}