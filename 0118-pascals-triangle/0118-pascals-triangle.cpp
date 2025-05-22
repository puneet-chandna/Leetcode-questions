class Solution {
public:
    vector<int> ncr(int row){
        long long res= 1;
        vector<int> roww ;
        roww.push_back(1);
        for( int i=1 ; i < row; i++){
            res= res*(row-i);
            res= res/i;
            roww.push_back(res);
        }

        return roww;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        
        
        for(int i = 1; i<=numRows ;i++){
            pascal.push_back(ncr(i));
        }


        return pascal;
    }
};