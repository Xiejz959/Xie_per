#include<bits/stdc++.h>
using namespace std;
int n=0;
//一下变量标记每行每列每条对角线是否存在皇后
bool column[100]={false},leftincline[100]={false},rightincline[100]={false};
int ans[20]={0};
int amount=0;
void output();
void queen(int p);
int main()
{
    
    cin>>n;
    queen(0);//从0开始，实际上是从第一行开始DFS
    cout<<amount<<endl;
    return 0;
}
void output()
{
    if(amount<=2)//保证只输出前三个正解
    {
        for(int j=0;j<n;j++)
        {
            cout<<ans[j]<<' ';
        }
        cout<<endl;//输出后不用重置ans，回溯时会自动覆盖
        //若重置，会打乱回溯的过程，结果会错
    }
    amount++;//计数
}
void queen(int p)
{
    if(p>=n)//全部搜完，输出
    {
        output();
        return;
    }
    else
    {
        for(int i=0;i<n;i++)//搜索第p行第i个
        {
            if(column[i]==0 && leftincline[p+i]==0 && rightincline[p-i+n]==0)
            {
                //occupied by queen
                column[i]=1;
                leftincline[p+i]=1;
                rightincline[p-i+n]=1;
                ans[p]=i+1;

                //find the queen position of next row
                queen(p+1);

                //come back
                column[i]=0;
                leftincline[p+i]=0;
                rightincline[p-i+n]=0;
            }
        }
    }
}