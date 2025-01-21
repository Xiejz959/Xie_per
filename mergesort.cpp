#include<bits/stdc++.h>
using namespace std;
void mergesort(int a[],int begin,int end);
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) 
        cin>>a[i];
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
void mergesort(int a[],int begin,int end)
{
    //递归结束条件，左边界等于右边界，相当于一个子数组中仅含有一个数
    if(begin==end) 
        return;

    //先分割
    int mid=(begin+end)/2;//将原数组分成两个部分
    mergesort(a,begin,mid);
    mergesort(a,mid+1,end);
    
    /*
      先分割，割完后原先一个大数组变成两个小数组
      这两个小数组分别有序
      接下来合并即可
      下面的合并代码保证了返回上一级递归时两个子数组都是有序的
    */

    //合并
    int result[end-begin+1]={0};
    int begin1=begin,end1=mid;//第一个子数组的边界
    int begin2=mid+1,end2=end;//第二个子数组的边界
    int point=0;
    while(begin1<=end1&&begin2<=end2)//比较两个子数组，小的放到result数组的前面
    {
        //更新point的值，同时更新对应a数组较小值的下标，即更新begin1或begin2，保持另一个不变
        if(a[begin1]<a[begin2])
            result[point++]=a[begin1++];
        else
            result[point++]=a[begin2++];
    }
    //有可能两个子数组不一样长，需要把较长的后面多出来的数给加到result数组的后面
    while(begin1<=end1)
        result[point++]=a[begin1++];
    while(begin2<=end2)
        result[point++]=a[begin2++];
    //将最后结果复制到a中
    for(int i=begin,j=0;i<=end;i++,j++)//注意a的下标从begin开始而result则从0开始
        a[i]=result[j];
    return;
}