class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int di[4] = {-1, 1, 1, -1}, dj[4] = {1, 1, -1, -1};
        auto inb = [&](int i, int j){ return i>=0 && i<n && j>=0 && j<m; };

        vector<vector<vector<int>>> dp2(4, vector<vector<int>>(n, vector<int>(m,0)));
        vector<vector<vector<int>>> dp0(4, vector<vector<int>>(n, vector<int>(m,0)));

        for(int d=0; d<4; ++d){
            int si = di[d]==1 ? n-1 : 0, ei = di[d]==1 ? -1 : n, stepi = di[d]==1 ? -1 : 1;
            int sj = dj[d]==1 ? m-1 : 0, ej = dj[d]==1 ? -1 : m, stepj = dj[d]==1 ? -1 : 1;
            for(int i=si; i!=ei; i+=stepi){
                for(int j=sj; j!=ej; j+=stepj){
                    int ni=i+di[d], nj=j+dj[d];
                    if(grid[i][j]==2){
                        dp2[d][i][j]=1;
                        if(inb(ni,nj) && grid[ni][nj]==0) dp2[d][i][j]+=dp0[d][ni][nj];
                    } else dp2[d][i][j]=0;
                    if(grid[i][j]==0){
                        dp0[d][i][j]=1;
                        if(inb(ni,nj) && grid[ni][nj]==2) dp0[d][i][j]+=dp2[d][ni][nj];
                    } else dp0[d][i][j]=0;
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]!=1) continue;
                ans = max(ans, 1);
                for(int d=0; d<4; ++d){
                    int ni=i+di[d], nj=j+dj[d];
                    if(!inb(ni,nj) || grid[ni][nj]!=2) continue;
                    int L = dp2[d][ni][nj];
                    ans = max(ans, 1 + L);
                    int ti=ni, tj=nj, cw=(d+1)&3;
                    for(int t=1; t<=L; ++t){
                        int ui=ti+di[cw], uj=tj+dj[cw];
                        int add = 0;
                        if(inb(ui,uj)){
                            if(t&1) add = dp0[cw][ui][uj];
                            else add = dp2[cw][ui][uj];
                        }
                        ans = max(ans, 1 + t + add);
                        ti+=di[d]; tj+=dj[d];
                    }
                }
            }
        }
        return ans;
    
    }
};