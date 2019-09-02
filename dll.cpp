#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node *next,*prev;
};
class dll
{
  node *head;
public:
  dll(){head=NULL;}
  ~dll(){}
  void insertEnd(int x);
  void insertMid(int x,int pos);
  void insertBegin(int x);
  int removeEnd();
  int removeMid(int pos);
  int removeBegin();
  void display();
};
void dll::insertBegin(int x)
{
  node *temp=new node;
  temp->data=x;
  temp->next=temp->prev=NULL;
  if(head==NULL)
  {
    head=temp;
  }
  else
  {
    temp->next=head;
    head->prev=temp;
    head=temp;
  }
}
void dll::insertEnd(int x)
{
  node *temp=new node;
  temp->data=x;
  temp->next=temp->prev=NULL;
  if(head==NULL)
  {
    head=temp;
  }
  else
  {
    node *p=head;
    while(p->next!=NULL)
    {
      p=p->next;
    }
    temp->prev=p;
    p->next=temp;
  }
}
void dll::insertMid(int x,int pos)
{
  node *temp=new node;
  int i=1;
  temp->data=x;
  temp->next=temp->prev=NULL;
  if(head==NULL)
  {
    head=temp;
  }
  else
  {
    node *p=head;
    while(i<pos)
    {
      p=p->next;
      i++;
    }
    temp->prev=p;
    temp->next=p->next;
    p->next->prev=temp;
    p->next=temp;
  }
}
int dll::removeBegin()
{
  node *p;
  int x;
  if(head==NULL)
  {
    std::cout << "no elements to remove\n" << '\n';
  }
  else
  {
    p=head;
    x=head->data;
    head->next->prev=NULL;
    head=head->next;
    p->next=NULL;
    delete p;
    return x;
  }
}
int dll::removeEnd()
{
  node *p;
  int x;
  if(head==NULL)
  {
    std::cout << "no elements to remove\n" << '\n';
  }
  else
  {
    p=head;
    node *temp;
    while(p->next->next!=NULL)
    {
      p=p->next;
    }
    temp=p->next;
    x=temp->data;
    p->next->prev=NULL;
    p->next=NULL;
    delete temp;
    return x;
  }
}
int dll::removeMid(int pos)
{
  node *p;
  int x,i=1;
  if(head==NULL)
  {
    std::cout << "no elements to remove\n" << '\n';
  }
  else
  {
    p=head;
    while(i<pos)
    {
      p=p->next;
      i++;
    }
    node *temp;
    temp=p->next;
    x=temp->data;
    p->next=p->next->next;
    temp->next->prev=temp->prev;
    temp->next=temp->prev=NULL;
    delete temp;
    return x;
  }
}
void dll::display()
{
  node *p=head;
  while(p->next!=NULL)
  {
    cout<<p->data<<"/t";
    p=p->next;
  }
  cout<<p->data<<"/n";
}
int main()
{
  dll s;
  s.insertBegin(5);
  s.insertEnd(10);
  s.insertMid(45,2);
  s.display();
  s.removeBegin();
  s.display();
}
