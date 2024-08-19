/*
求最大连续子序列的和(kadane)
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    //num储存原始数字序列
    int num[n];
    memset(num,0,sizeof(num));
    for(int i=0;i<n;i++)
        cin>>num[i];
    //sumcurrent储存以前一个数字为结尾的子序列的和
    //sumall储存最终的最大值
    int sumcurrent=num[0],sumall=num[0];
    for(int i=1;i<n;i++)//从第二个元素开始
    {
        /*
        sumcurrent是以前一个数字为结尾的子序列的和，更新这个值的时候，比较一下是之前的数字和大
        还是加上当前数字后的值大。
        如果num[i]是正数，显然sumcurrent+num[i]大，
        如果num[i]是负数，如果负的不多，那加上去没事，负的多，就从当前数重新开始
        */
        sumcurrent=max(sumcurrent+num[i],num[i]);
        sumall=max(sumall,sumcurrent);
    }
    cout<<sumall<<endl;
    return 0;
}