class Solution {
public:
bool isValid(int i, int j, int n, int m, vector<string> &matrix) {
        return !(i < 0 || j < 0 || i >= n || j >= m || matrix[i][j] == '#');
    }
    int minMoves(vector<string>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<char, vector<pair<int , int>>> mp;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(matrix[i][j]>='A' && matrix[i][j]<='Z'){
                    mp[matrix[i][j]].push_back({i,j});
                }
            }
        }
        if(matrix[n-1][m-1]=='#') return -1;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        using T = tuple<int,int,int>; 
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0, 0});
        unordered_set<char> used;
        int dx[4] = {0,0,-1,1};
        int dy[4]={-1,1,0,0};
        while(!pq.empty()){
            auto [d , x , y] = pq.top();
            pq.pop();
            if(x==n-1 && y==m-1 ) return d;
            if(isupper(matrix[x][y]) && !used.count(matrix[x][y])){
                used.insert(matrix[x][y]);
                for(auto [nx , ny] : mp[matrix[x][y]]){
                    if(d<dist[nx][ny]){
                        dist[nx][ny] = d;
                        pq.push({d , nx , ny});
                    }
                }
            }
            for(int k =0;k<4;k++){
                int nx = x+dx[k] , ny = y+dy[k];
                if(isValid(nx , ny , n , m , matrix) && d+1<dist[nx][ny]){
                    dist[nx][ny]=d+1;
                    pq.push({d+1,nx , ny});

                }
            }
        }
        return -1;


        
        
    }
};