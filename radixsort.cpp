#include<bits/stdc++.h>
using namespace std;
void radixsort(int a[],int n);
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) 
        cin>>a[i];
    radixsort(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
void radixsort(int a[],int n)
{
    int max=0;//因为是正数，所以最长的数就是最大的数
    for(int i=0;i<n;i++)
        if(a[i]>max) max=a[i];
    int len=0;//存最大数的位数
    while(max>0)
    {
        len++;
        max/=10;
    }

    int bucket[n][10]={0};//开一个桶，用于存所需位相同的数
    
    for(int i=0;i<len;i++)//遍历位数
    {
        int count[10]={0};//记录每个桶中的数的个数
        for(int j=0;j<n;j++)
        {
            int num=(a[j]/(int)pow(10,i))%10;//取出第i位
            //第i位放在第i个桶中，
            bucket[count[num]++][num]=a[j];
        }
        int k=0;
        for(int j=0;j<10;j++)//按排好的顺序放回原数组
        {
            for(int l=0;l<count[j];l++)
            {
                a[k++]=bucket[l][j];
            }
        }
        /*
        基数排序排完一位后排下一位，原数组中的数按照当前位已经排好
        下一次排序时，不管这一位顺序如何，每个桶中上一位的顺序总是有序的
        */
    }
    return;
}