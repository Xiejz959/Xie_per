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
    int max_value[n+1][total_weight+1]={0};//先只考虑前面i件物品且背包剩余容量为j
    //dp start
    for(int i=0;i<=n;i++)//遍历前i个物品
    {
        for(int j=0;j<=total_weight;j++)//遍历背包剩余容量为j
        {
            if(i==0 || j==0)//边界条件，前i个物品为0或者背包容量为0，最大价值为0
                max_value[i][j]=0;
            else
            {
                if(goods[i].weight<=j)//能放的进，比较放和不放的总最大价值
                    max_value[i][j]=max(max_value[i-1][j],max_value[i-1][j-goods[i].weight]+goods[i].value);
                else//放不进，只能不放,和没有的时候一样
                    max_value[i][j]=max_value[i-1][j]; 
            }
        }
    }
    /* 测试代码
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=total_weight;j++)
        {
            cout<<max_value[i][j]<<" ";
        }
        cout<<endl;
    } 
    */
    cout<<max_value[n][total_weight]<<endl;//右下角的值即为最大价值
    return 0;
}