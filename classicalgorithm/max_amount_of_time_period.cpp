/*
给定多个时间段，求最多的不重复时间段段的数量
注意直接用end升序排列即可
*/
#include<bits/stdc++.h>
using namespace std;
struct date
{
    int begin;
    int end;
};
bool cmp(date a,date b)
{
    return a.end<b.end;
}
int main()
{
    int n;cin>>n;
    vector<date> a(n);
    for(int i=0;i<n;i++) cin>>a[i].begin>>a[i].end;
    sort(a.begin(),a.end(),cmp);
    //每一步的目标是尽早结束当前时间段，也就是end尽可能小
    //因此用end排序，由于begin小于end，这也保证了begin尽可能小
    //同时用end去排序，避免了begin小而对应end过大，使得单个时间段过长的问题（不重复时间段数量少）
    int ans=0,last=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i].begin>=last)
        {
            ans++;
            last=a[i].end;
        }
    }
    cout<<ans<<endl;
    return 0;
}