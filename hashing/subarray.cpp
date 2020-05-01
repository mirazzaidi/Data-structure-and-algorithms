#include <unordered_map>
#include <unordered_set>

/*
Given an array of integers, find a subarray whose sum is equal to given sum.
*/


bool subarrayWithZeroSum(int a[], int n)
{
    std::unordered_set<int> set;
    int prefix_sum = a[0];
    for (auto i = 1; i < n; i++)
    {
        prefix_sum += a[i];

        if (set.find(prefix_sum) != set.end())
            return true;
        else if (prefix_sum == 0)
            return true;
    }
    return prefix_sum == 0;
}

// 1 3 4 -2 -8 15 ; sum=5
// 1 4 8  6 -2 13
bool subarrayWithSum(int a[], int n, int sum)
{
    std::unordered_set<int> set;
    int prefix_sum = a[0];
    set.insert(prefix_sum);

    for (auto i = 1; i < n; i++)
    {
        prefix_sum += a[i];

        if (set.find(prefix_sum - sum) != set.end())
            return true;
        if (prefix_sum == sum)
            return true;
        set.insert(prefix_sum);
    }
    return prefix_sum == sum;
}
// 5, 8, -4,-4,3,2,-2,1
int LongestSubarrayWithSum(int a[], int n, int sum)
{
    std::unordered_map<int, int> map;
    int prefix_sum = a[0];
    map.insert(prefix_sum, 0);

    int maxLen = 0;

    for (auto i = 1; i < n; i++)
    {
        prefix_sum += a[i];

        if (map.find(prefix_sum - sum) != map.end())
        {
            auto it = map.find(prefix_sum - sum);
            auto len = i - it->second; //index
            maxLen = max(maxLen, len);
        }
        else if (prefix_sum == sum)
            maxLen = max(maxLen, i + 1);
        else
            map.insert(prefix_sum, i);
    }
    return maxLen;
}

int LongestSequenceOfEqZerosAndOnes(int a[], int n)
{
    int ps = 0;
    int maxLen = 0;
    std::unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        ps += a[i] == 0 ? -1 : 1;

        if (ps == 0)
            maxLen = max(maxLen, i + 1);
        else if (map.find(ps) != map.end())
            maxLen = i - map[ps];
        else
            map.insert(ps, i);
    }
    return maxLen;
}