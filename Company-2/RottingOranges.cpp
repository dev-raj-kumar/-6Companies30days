class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n,m,i,j;
        n=grid.size();
        m = grid[0].size();
        int fr=0;
        queue<pair<int,int>>q;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fr++;
                }
            }
        }
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        int tt=0;
        while(!q.empty() && fr>0){
            tt++;
            int x = q.size();
            for(i=1;i<=x;i++){
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                for(j=0;j<4;j++){
                    int aa = a+dx[j];
                    int bb = b+dy[j];
                    if(aa>=0 && aa<n && bb>=0 && bb<m && grid[aa][bb]==1){
                        fr--;
                        grid[aa][bb]=2;
                        q.push({aa,bb});
                    }
                }
            }
        }
        if(fr > 0){
            return -1;
        }
        else
            return tt;
    }
};
