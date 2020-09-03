/*Solution to maxpartition problem leetcode*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std ;
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        auto n = A.size();
        vector<long> maxSumAtPos(n,-1);
        maxSumAtPos[n-1] = A[n-1];
        GetMaxSumForRange(A,0,n-1,K,maxSumAtPos);

        return maxSumAtPos[0];
    }
    
    void GetMaxSumForRange(vector<int>& A, int s, int e, int K, vector<long> &mSumArr)
    {
        if(mSumArr[s] != -1)
            return ;

        long asum = 0 ;
        long maxSum = 0 ;
        auto maxSoFar = A[s];
        for(auto index = s ; index < (s+K) && index <= e ; ++index)
        {
            maxSoFar = A[index] > maxSoFar ? A[index] : maxSoFar;
            sum = (index - s + 1) * maxSoFar;
            if(index < e && mSumArr[index+1] == -1)
            {
               GetMaxSumForRange(A, index+1, e, K, mSumArr);
            }

           //if(maxSum < (sum + (index < e ? mSumArr[index+1] : 0)))
            auto tempSum = sum + (index < e ? mSumArr[index+1] : 0);
            maxSum = maxSum < tempSum ?  tempSum : maxSum;              

        }
        mSumArr[s] = maxSum;
    }

};

int main()
{
    //vector<int> A{1,15,7,9,2,5,10};
    vector<int> A{1,2,3};
    Solution sol1;
    cout << sol1.maxSumAfterPartitioning(A, 1) << endl;
    return 0 ;
}
