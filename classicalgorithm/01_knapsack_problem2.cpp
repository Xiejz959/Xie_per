#include<bits/stdc++.h>
using namespace std;
int main()
{
    int total_weight=0,n=0;
    cin>>total_weight>>n;
    struct stuff//结构体便于储存物品的价值和重量
    {
        int value;
        int weight;
    };
    stuff goods[n+1];//开n+1个，便于前i个物品和下标i对齐
    //goods[0]没有意义，只是为了对齐
    goods[0].value=0;
    goods[0].weight=0;
    for(int i=1;i<=n;i++)
    {
        cin>>goods[i].weight>>goods[i].value;
    }
    int max_value[total_weight+1]={0};
    //dp start
    for(int i=1;i<=n;i++)//遍历前i个物品
    {
        for(int j=total_weight;j>=goods[i].weight;j--)//遍历背包剩余容量为j
        {
            max_value[j]=max(max_value[j],max_value[j-goods[i].weight]+goods[i].value);
        }
    }
    // for(int i=0;i<=total_weight;i++)
    // {
    //     cout<<max_value[i]<<" ";
    // }
    cout<<max_value[total_weight]<<endl;
    return 0;
}