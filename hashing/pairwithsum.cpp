#include <unordered_set>

/*
Given an array of integers, find a pair that makes a sum , equal to given sum.
*/

// Complexity O(n2)
void PairWithSumNaive(int a[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (sum == a[i] + a[j])
            {
                std::cout << "Pair is" << a[i] << "," << sum - a[i] << std::endl;
            }
        }
    }
}

// Complexity O(n)
void PairWithSUm(int a[], int n, int sum)
{
    std::unordered_set<int> set;

    for (int i = 0; i < n; i++)
    {
        if (map.find(sum - a[i]) != set.end())
        {
            std::cout << "Pair is" << a[i] << "," << sum - a[i] << std::endl;
        }
        else
        {
            set.insert(a[i]);
        }
    }
}