//开链表并正反双向输出(双向链表 double linked list)
#include<bits/stdc++.h>
#define N 50
using namespace std;
/*
    链节用结构体表示，prev连上一个结点的地址，
    next连下一个结点的地址，value存值。
*/
struct node
{
    node *prev;
    int value;
    node *next;
};
ifstream fin("in.txt");//文件输入
int main()
{
    node *head;//定义头结点
    head=new node;//申请空间,不用管head的prev指针
    head->value=0;//值存0
    head->next=NULL;//当做尾节点，因此指向NULL
    node *point_doer;//操作用结点
    point_doer=head;//先同步到head
    for(int i=0;i<N;i++)
    {
        int temp=0;
        fin>>temp;
        node *newpoint;//新链节的定义
        newpoint=new node;//申请空间
        newpoint->prev=point_doer;//新定义的结点连到前一个结点
        newpoint->value=temp;//存值
        newpoint->next=NULL;//连到NULL,当做尾节点
        point_doer->next=newpoint;//把上一个结点连到这一个结点，同时表明上一节点并非尾节点
        point_doer=newpoint;//同步
    }
    fin.close();//关闭输入
    /*
        ========逆向输出==========
        因为此时pointdoer已经在末尾,这里偷个懒
    */
    std::cout<<"逆向"<<endl;
    for(int i=0;i<N;i++)
    {
        std::cout<<point_doer->value<<" ";//输出值
        point_doer=point_doer->prev;//讲链节往前推一个
    }
    std::cout<<endl;
    /*
        ========正向输出========
    */
    point_doer=head;
    std::cout<<"正向"<<endl;
    for(int i=0;i<N;i++)
    {
        point_doer=point_doer->next;//结点往后走一个
        std::cout<<point_doer->value<<" ";
    }
    std::cout<<endl;
    // 释放链表内存
    while (head->next != NULL) 
    {
        node *temp = head->next;//连到头结点的下一个链节，方便释放内存
        head->next = head->next->next;//往后走
        delete temp;//释放空间
    }
    return 0;
}