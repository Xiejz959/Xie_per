//创建一个链表并输出（单链表 single linked list）
#include<bits/stdc++.h>
#define N 100
using namespace std;
ifstream fin("in.txt");//文本形式输出
struct node//创建一个链接
{
    int value;//存值
    node *next;//尾指针，指向下一个链节
};
int main()
{
    //int n;
    int temp;
    //cin>>n;
    node *head;//定义头结点
    head=new node;//为头结点申请一个内存空间
    node *point;//申请一个链节，用于操作链表
    point=head;//一开始指向head的地址，操作head，在循环中指向不同结点的地址，操作不同结点
    head->value=0;
    for(int i=0;i<N;i++)
    {
        fin>>temp;//文件流输入
        node *p=new node; //开新的结点
        p->value=temp;//传入新结点的值
        p->next=NULL;//假设新结点是最后一个，把next指向null，形成尾结点
        point->next=p;//point此时仍指向上一个结点，这步操作把上一个结点的next指向这一个链节
        point=p;//更新到当前链节
    }
    point=head;//指向头结点，便于扫整个链表
    while(point!=NULL)//节点仍然存在
    {
        point=point->next;//去下一个结点
        cout<<point->value<<" ";//输出该结点的值
        
    }
    cout<<endl;
    return 0;
}