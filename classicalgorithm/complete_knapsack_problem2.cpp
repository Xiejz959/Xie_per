#include<bits/stdc++.h>
using namespace std;
int main()
{
    int totalweight=0,n=0;
    cin>>totalweight>>n;
    struct stuff
    {
        int weight;
        int value;
    };
    stuff goods[n+1];//n+1个保持下标i对应前i个
    goods[0].value=0,goods[0].weight=0;
    for(int i=1;i<=n;i++)
    {
        cin>>goods[i].weight>>goods[i].value;
    }
    int max_value[totalweight+1]={0};
    /*
    一维dp时，内循环正向，如果前次已经拿过，后面可以继续拿，等于重复拿一件物品，是完全背包
    如果内循环是逆向，保证了每件物品只拿一次，是01背包
    原因是状态更新方程后面的状态是用前面的状态更新的
    重不重复拿在于前面的max_value[j]是否在当前i的循环中更新过
    */
    for(int i=1;i<=n;i++)
    {
        for(int j=goods[i].weight;j<=totalweight;j++)
        {
            max_value[j]=max(max_value[j],max_value[j-goods[i].weight]+goods[i].value);
        }
    }
    // for(int i=0;i<=totalweight;i++)
    // {
    //     cout<<max_value[i]<<" ";
    // }
    cout<<max_value[totalweight];
    return 0;
}