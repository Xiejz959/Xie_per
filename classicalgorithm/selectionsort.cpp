#include<bits/stdc++.h>
using namespace std;
int main()
{
    //选择排序
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    	cin>>a[i];
    for(int i=0;i<n;i++)//i is the position to store.
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;//找出未排序中的最小值
        }
        swap(a[i],a[min]);
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}