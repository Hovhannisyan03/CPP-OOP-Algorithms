class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int start = 0;
        int end = arr.size() - 1;
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            if(arr[mid] > arr[mid + 1])
            {
                end = mid;
            }
            else 
            {
                start = mid + 1;//arr[mid] <= arr[mid + 1] -> peak must be to the right, because the array is still increasing
            }
        }
        return start;
    }
};
