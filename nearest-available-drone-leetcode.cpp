class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) 
    {
        int tx = target[0];
        int ty = target[1];

        int min_dist = INT_MAX;
        int best_index = -1;

        for(int i = 0 ; i < drones.size() ; i++)
            {
                int x = drones[i][0];
                int y = drones[i][1];
                int r = drones[i][2];

                //calculating manhattan distance 
                int man_dist = abs(x-tx) + abs(y-ty);

                if(man_dist <= r)
                {

                if(man_dist < min_dist)
                    {
                     min_dist = man_dist;
                     best_index = i;
                    }
                  }  
            }

        return best_index;
    }
};
