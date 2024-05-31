class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        bool arr[58];
        int count = 0;
        size_t size_jew = 0;
        size_t size_sto = 0;
        for(char ch : jewels)
        {
            arr[ch - 'A'] = 1;
        }

        for(char ch : stones)
        {
            if(arr[ch - 'A'])
            {
                ++count;
            }
        }
        return count;
    }
};