class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        // cout<<encodedText<<endl;
        // return "";
        int col = n / rows;
        vector<vector<char>> pattern(rows, vector<char>(col));
        int currow = -1;
        for (int itr = 0; itr < n; itr++) {
            if (itr % col == 0)
                currow++;
            pattern[currow][itr % col] = encodedText[itr];
        }
        string ans = "";
        // for(int i =0;i<rows;i++){
        //     for(int j=0;j<col;j++){
        //         cout<<pattern[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for (int c = 0; c < col; c++) {
            int i = 0;
            int j = c;

            while (i < rows && j < col) {
                ans += pattern[i][j];
                i++;
                j++;
            }
        }
        while(!ans.empty() && ans.back() == ' ') {
    ans.pop_back();
}

        return ans;
    }
};