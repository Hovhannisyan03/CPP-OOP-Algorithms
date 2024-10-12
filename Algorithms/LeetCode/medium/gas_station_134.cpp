class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int size = gas.size();
        int totalGas = 0;
        int totalCost = 0;
        int bag = 0;
        int start = 0;
        for(int i = 0; i < size; ++i)
        {
            totalGas += gas[i];
            totalCost += cost[i];
            bag += gas[i] - cost[i]; // go next station
            if(bag < 0) 
            {
                start = i + 1; // new station
                bag = 0;
            }
        }

        if(totalGas < totalCost)
        {
            return -1;
        }
        return start;
    }
};
