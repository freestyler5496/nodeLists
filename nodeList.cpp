#include <cstdlib>
#include <fstream>     // file operations
#include <iostream>
#include <ctime>
using namespace std;
class Node
{
    public:
    Node()
    {
    }
    Node(int it)
    {
        item = it;
    }

    Node(int it, Node *n)
    {
        item=it;
        next=n;
    }

    void display()
    {
        cout << item << endl;
    }

    int item;
    Node* next;
};
void recDisplay(Node *head)
{
    if(head == NULL)
        return;
    if(head != NULL)
    {
        head->display();
        recDisplay(head->next);
    }
}
void removeNegs(Node *&inHead){

    Node *outHead = new Node;

    if(inHead->item >= 0){
        outHead->item=inHead->item;
    }
    Node *inPtr=inHead->next;
    Node *outPtr = outHead;

    while(inPtr != NULL)
    {   if(inPtr->item >= 0)
        {
            outPtr->next = new Node;
            outPtr->next->item = inPtr->item;
            outPtr=outPtr->next;

        }
        inPtr=inPtr->next;
    }

    outPtr->next = NULL;
    while(inHead!=NULL)
    {
        Node *temp= inHead;
        inHead = inHead->next;
        delete temp;
    }

    inHead = outHead;
}
//void remNeg(Node *&head)         ///ERROR
//{
//    Node *prev=NULL;
//    Node *cur = head;
//    while(cur != NULL)
//    {
//        if(cur->item < 0)
//        {
//            if(prev==NULL)
//            {
//                head = head->next;
//            }
//            else{
//
//                prev->next=cur->next;
//
//            }
//            delete cur;
//        }
//        prev=cur;
//        cur = cur->next;
//    }
//
//
}


int main()
{
    Node *head = new Node(1);
    Node *cur = head;
    int flag = 0;
    for(int i=2; i<=10; i++)
    {
        if(flag==0)
        {
            cur->next=new Node(i);
            flag++;
        }
        else
        {
            cur->next=new Node(-i);
            flag--;
        }
        cur = cur->next;
    }
    cur->next=NULL;
    cur=NULL;
//    head->display();
//    recDisplay(head);
//    head->next->display();
//    head->next->next->display();
//    head->next->next->next->display();
//    head->next->next->next->next->display();
//    cout << (head->next->next->next->next->next == NULL);
    recDisplay(head);
    cout << endl;
    remNeg(head);
    recDisplay(head);


}
