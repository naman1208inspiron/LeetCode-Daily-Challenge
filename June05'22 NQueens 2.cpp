class Solution {
public:
    int totalNQueens(int n) {
        string s(n, '.');
        vector<string> board(n, s);
        int ans=0; 
        solve(board, ans, 0, n);
        return ans;
    }
    void solve(vector<string> &board, int &ans, int row, int n){
        if(row== n){
            ans++; 
            return;
        }
        
        for(int col=0; col<n; col++){
            if(isSafe(board, row, col, n)){
                board[row][col]= 'Q';
                solve(board, ans, row+1, n);
                board[row][col]= '.';
            }
        }
    }
    bool isSafe(vector<string> &board, int row, int col, int n){
        for(int i=row; i>=0; i--){
            if(board[i][col]=='Q') return false;
        }
        for(int i=row, j=col; i>=0 && j<n; i--, j++){
            if(board[i][j]=='Q') return false;
        }
        for(int i=row, j=col; i>=0 && j>=0; i--, j--){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
};
