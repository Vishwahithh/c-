#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node *next;
};
class sll
{
  node *head;
public:
  sll(){head=NULL;}
  ~sll(){}
  void insertBegin(int x);
  void insertEnd(int x);
  void insertMid(int x,int pos);
  int removeBegin();
  int removeEnd();
  int removeMid(int pos);
  void display();
  void reverse();
};
void sll::insertBegin(int x)
{
  node *temp=new node;
  temp->data=x;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp;
  }
  else
  {
    temp->next=head;
    head=temp;
  }
}
void sll::insertEnd(int x)
{
  node *temp=new node;
  temp->next=NULL;
  temp->data=x;
  if(head==NULL)
  {
    head=temp;
  }
  else
  {
  node *p;
  p=head;
  while(p->next!=NULL)
  {
    p=p->next;
  }
  p->next=temp;
}
}
void sll::insertMid(int x,int pos)
{
  node *temp=new node;
  temp->data=x;
  temp->next=NULL;
  int i=1;
  node *p;
  if(head==NULL)
  {
    head=temp;
  }
  else if(head->next==NULL)
  {
    cout<<"there is only one element in the list\n";
  }
  else
  {
    p=head;
    while(i<pos)
    {
      p=p->next;
      i++;
    }
    temp->next=p->next;
    p->next=temp;
  }
}
int sll::removeBegin()
{
  int x;
  if(head==NULL)
  {
    cout<<"no elements in the list\n";
  }
  else
  {
    node *p=head;
    x=head->data;
    head=head->next;
    p->next=NULL;
    delete p;
    return x;
  }
}
int sll::removeEnd()
{
  int x;
  if(head==NULL)
  {
    cout<<"no elements to remove\n";
  }
  else
  {
    node *p=head;
    node *temp;
    while(p->next->next!=NULL)
    {
      p=p->next;
    }
    temp=p->next;
    x=temp->data;
    p->next=NULL;
    delete temp;
    return x;
  }
}
int sll::removeMid(int pos)
{
  int x;
  node *p;
  if(head==NULL)
  {
    cout<<"no elements to remove\n";
  }
  else if(head->next==NULL)
  {
    p=head;
    x=head->data;
    head=NULL;
    delete p;
    return x;
  }
  else
  {
    p=head;
    int i=1;
    while(i<pos)
    {
      p=p->next;
      i++;
    }
    node *temp;
    temp=p->next;
    p->next=temp->next;
    x=temp->data;
    temp->next=NULL;
    delete temp;
    return x;
  }
}
void sll::display()
{
  node *p=head;
  while(p->next!=NULL)
  {
    cout<<p->data<<"\t";
    p=p->next;
  }
  cout<<p->data;
}
int main()
{
  sll s;
  s.insertBegin(5);
  s.insertEnd(10);
  s.insertMid(45,2);
  s.display();
  s.removeBegin();
  s.display();
}
