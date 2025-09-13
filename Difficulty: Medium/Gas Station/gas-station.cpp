class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int totalgas=0;
        int totalcost=0;
        for(int i=0;i<gas.size();i++)
        {
            totalgas+=gas[i];
            totalcost+=cost[i];
        }
        if(totalgas<totalcost) return -1;
        
        int start=0,tank=0;
        for(int i=0;i<gas.size();i++)
        {
            tank+=gas[i]-cost[i];
            if(tank<0)
            {
                start=i+1;
                tank=0;
            }
        }
        return start;
    }
};