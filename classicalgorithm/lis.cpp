#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*
    动态规划：不断求解以i为结尾的最长递增子序列的长度
    */
    int n=0;
    cin>>n;
    vector<int> a;//用来存放输入的序列
    vector<int> ans;//用来存放最长递增子序列(所求解)
    vector<int> dp(n,1);//用来动态规划，放的是以i为结尾的最长递增子序列的长度
    vector<int> prev(n,-1);//存放最长子序列的前一个元素的下标
    //输入初始数组
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    
    for(int i=0;i<n;i++)//从第一个元素开始遍历原数组
    {
        for(int j=0;j<i;j++)//找符合条件的子序列，使a[i]>a[j],增长最大递增子序列
        {
            if(a[i]>a[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
                if(dp[i]==dp[j]+1)
                {
                    prev[i]=j;//找到前一个元素的下标，为了求解最长子序列
                }
            }
        }
    }
    //找到最长子序列的长度
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]>dp[max])
        {
            max=i;
        }
    }
    //从后往前解出最长递增子序列
    while(max!=-1)
    {
        ans.push_back(a[max]);
        max=prev[max];
    }
    reverse(ans.begin(),ans.end());//反转，因为是从后往前解的
    for(vector<int>::iterator it=ans.begin();it!=ans.end();it++)//用迭代器输出
    {
        cout<<*it<<" ";
    }
    return 0;
}