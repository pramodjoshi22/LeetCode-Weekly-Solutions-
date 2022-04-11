//2233. Maximum Product After K Increments

class Solution
{
public:
    int maximumProduct(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (n == 1)
            return arr[0] + k;

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
            pq.push(arr[i]);

        while (k > 0)
        {
            int temp = pq.top();
            pq.pop();
            if (pq.top() - temp + 1 <= k)
                k -= (pq.top() - temp + 1), temp = pq.top() + 1;
            else
                temp += k, k = 0;
            pq.push(temp);
        }

        int mod = 7 + 1e9;
        long long ans = 1;

        while (!pq.empty())
            ans = (ans * pq.top()) % mod, pq.pop();

        return ans;
    }
};