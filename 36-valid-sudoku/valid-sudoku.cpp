class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
   
        for (int i = 0; i < 9; i++) {
            set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }


        for (int j = 0; j < 9; j++) {
            set<char> st;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                if (st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }


        for (int startRow = 0; startRow < 9; startRow += 3) {
            for (int startCol = 0; startCol < 9; startCol += 3) {
                set<char> st;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[startRow + i][startCol + j];
                        if (c == '.') continue;
                        if (st.count(c)) return false;
                        st.insert(c);
                    }
                }
            }
        }

        return true;
    }
};
