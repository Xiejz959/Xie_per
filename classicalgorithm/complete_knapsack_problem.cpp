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
    int max_value[n+1][totalweight+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=totalweight;j++)
        {
            if(i==0 || j==0)
                max_value[i][j]=0;
            else
            {
                if(goods[i].weight<=j)
                {
                    for(int k=0;k*goods[i].weight<=j;k++)//保证尽可能利用背包最大容量
                    {
                        max_value[i][j]=max(max_value[i-1][j],max_value[i-1][j-k*goods[i].weight]+goods[i].value*k);
                    }
                }
                else
                {
                    max_value[i][j]=max_value[i-1][j];
                }
            }
        }
    }
    /*测试
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=totalweight;j++)
        {
            cout<<max_value[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    cout<<max_value[n][totalweight];
    return 0;
}