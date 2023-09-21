#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long
#define pb push_back
#define loop(i, a, b) for(int i=a; i<b; i++)

void fill(vector<vector<bool>>& canPlace, int i, int j){
    for(int a=0; a<8; a++){
        canPlace[a][j] = 0;
        canPlace[i][a] = 0;
    }

    
}

void f(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& canPlace, int& ans){
    if(i<0 || i>=8 || j<0 || j>=8) return;
    if(i==7 && j==7) ans++;


}

int numOfWaysToPlace8Queens(vector<vector<char>>& board){
    vector<vector<bool>> canPlace(8, vector<bool>(8, 1));
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[i][j]=='*') canPlace[i][j] = 0;
        }
    }

    int ans = 0;
    f(0, 0, board, canPlace, ans);

    return ans;
}

int main(){
    vector<vector<char>> board(8, vector<char>(8, '.'));
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin>>board[i][j];
        }
    }

    cout<<numOfWaysToPlace8Queens(board)<<'\n';

    return 0;
}