#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)//第一个数默认是已经排序了的，所以不用管，从第二个数开始
    {
        int temp=a[i];//现在取第i个数为temp去作比较
        for(int j=i-1;j>=0;j--)
        {
            if(temp<a[j])
            {
                a[j+1]=a[j];//原来j位置上的数往后移一个
                a[j]=temp;//temp放到j上，相当于把temp插入到了原a[j]之前
            }
            else//有序的数列就是从小到大，这时已经比最后一个数还大了，不用继续比
                break;
        }
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}