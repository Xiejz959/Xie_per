#include<bits/stdc++.h>
using namespace std;
void quicksort(int a[],int head,int tail);
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
void quicksort(int a[],int head,int tail)//快速排序，下例是正序
{
    int key=a[tail];//key是一个参考值，随机的
    /*  正序排序中比key小的放左边，反之放右边
        第一个key选头或尾，选头时tail先动，选尾时head先动
        指针head，tail相等时更新key，就是head所指的值
    */
   if(head>=tail)//递归结束
        return;
   int left=head,right=tail;//left，right限定递归范围，head，tail用于每一次的操作
    while(head!=tail)
    {
        while(a[head]<=key&&head<tail)//找到key左侧比key大的值
            head++;
        while(a[tail]>=key&&head<tail)//找到key右侧比key小的值
            tail--;
        if(head<tail)//这个条件是因为head，tail相等时不需要交换
        //上面两个循环限定了head要小于tail，所以head大于tail情况不存在，就是结束递归
        {
            int tmp=a[head];
            a[head]=a[tail];
            a[tail]=tmp;
        }
    }
    swap(a[head],a[right]);//head，tail相等时更新key,确保key值在中间
    quicksort(a,left,head-1);
    quicksort(a,head+1,right);
}