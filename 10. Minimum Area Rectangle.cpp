// TC : O(N*2)
// MC : O(N)
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        // store all pair row wise 
        unordered_map<int,unordered_set<int>>mp;

        for(auto it : points){
            mp[it[0]].insert(it[1]);
        }

        // final ans
        int ans = INT_MAX;

        // size
        int n = points.size();
        
        /*
        A - - - B
        |       |
        D - - - C 
        */
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                // point A
                int _x1 = points[i][0];
                int _y1 = points[i][1];

                // point C
                int _x2 = points[j][0];
                int _y2 = points[j][1];

                // A and C are in Diagonal
                if(_x1 != _x2 and _y1 != _y2){
                    // chech D and B present or not
                    if(mp[_x1].count(_y2) && mp[_x2].count(_y1)){
                        ans = min(ans,abs(_x1-_x2)*abs(_y1-_y2));
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};