class Solution {
public:
    bool isHappy(int n) 
    {
        int slow = getNext(n);
        int fast = getNext(getNext(n));
        while(slow != 1 && slow != fast)
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return slow == 1;
    }

private:
    int getNext(int num)
    {   
        int sumOfSquares = 0;
        while(num)
        {
            int square = num % 10;
            sumOfSquares += square * square;
            num /= 10;
        }

        return sumOfSquares;
    }
};