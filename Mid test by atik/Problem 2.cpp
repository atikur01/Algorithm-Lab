#include <bits/stdc++.h>
using namespace std;

class Result
{
public:
    double sum;
    double length;
    Result(double s,double l)
    {
        sum = s;
        length = l;
    }
};

bool compare(Result a, Result b)
{
    if (a.length < b.length) return true;
    return false;
}

int lenOfLongSubarr(int arr[],int n, int k)
{
    map<int, int> um;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum == k)
            maxLen = i + 1;

        if (um.find(sum) == um.end())
            um[sum] = i;

        if (um.find(sum - k) != um.end()) {

            if (maxLen < (i - um[sum - k]))
                maxLen = i - um[sum - k];
        }
    }

    return maxLen;
}

int max(int a, int b) { return (a > b) ? a : b; }

int max(int a, int b, int c) { return max(max(a, b), c); }

int maxCrossingSum(int arr[], int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return max(left_sum + right_sum, left_sum, right_sum);
}

int maxSubArraySum(int arr[], int l, int h)
{
    if (l == h)
        return arr[l];

    int m = (l + h) / 2;

    return max(maxSubArraySum(arr, l, m),
        maxSubArraySum(arr, m + 1, h),
        maxCrossingSum(arr, l, m, h));
}

int main()
{
    int arr[] = { 1, -2, -3, 6, 5, -1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n - 1);
    int k = max_sum;
    cout << "Maximum contiguous sum is " << max_sum << endl;
    int l1 = lenOfLongSubarr(arr, n, k);
    cout << "Length = "<< l1<<endl;

    int arr2[] = { -2, 3, 4, -1, 2, -3 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int max_sum2 = maxSubArraySum(arr2, 0, n2 - 1);
    int k2 = max_sum2;
    cout << "Maximum contiguous sum is " << max_sum2 << endl;
    int l2 = lenOfLongSubarr(arr2, n2, k2);
    cout << "Length = " << l2 << endl;

    int arr3[] = { 1, 2, -4, 2, -1, -3 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int max_sum3 = maxSubArraySum(arr3, 0, n3 - 1);
    int k3 = max_sum3;
    cout << "Maximum contiguous sum is " << max_sum3 << endl;
    int l3 = lenOfLongSubarr(arr3, n3, k3);
    cout << "Length = " << l3 << endl;

    cout << endl;

    vector<Result> res = {
        Result(max_sum,l1),
		Result(max_sum2, l2),
		Result(max_sum3, l3),

    };

    sort(res.begin(), res.end(),compare);

    cout << "Answer 1:" << endl;
    cout << "Maximum contiguous sum is " << res.front().sum << " Length: "<<res.front().length<< endl;

    vector<int> res2;
    int x1 = max_sum - (l1 * 1);
    int x2 = max_sum2 - (l2 * 1);
    int x3 = max_sum3 - (13 * 1);
    res2.push_back(x1);
    res2.push_back(x2);
    res2.push_back(x3);

    sort(res2.begin(), res2.end());

    cout << endl;
    cout << "Answer 2:" << endl;
    cout << "Maximum contiguous sum is " << res2.back() << endl;



    

    

    return 0;
}