#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node *next;
};
class csll
{
  node *head;
public:
  csll(){head=NULL;}
  ~csll(){}
  void insertBegin(int x);
  void insertEnd(int x);
  int removeBegin();
  int removeEnd();
  void display();
};
void csll::insertBegin(int x)
{
  node *temp=new node;
  temp->data=x;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp;
    temp->next=head;
  }
  else
  {
    temp->next=head;
    head->next=temp;
    head=temp;
  }
}
void csll::insertEnd(int x)
{
  node *temp=new node;
  temp->data=x;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp;
    temp->next=head;
  }
  else
  {
    node *p;
    p=head;
    while (p->next!=NULL) {
      p=p->next;
    }
    temp->next=head;
    p->next=temp;
  }
}
int csll::removeBegin()
{
  node *p;
  int x;
  if(head==NULL)
  {
    std::cout << "no elements to remove" << '\n';
  }
  else if (head->next==head)
  {
    p=head;
    head=NULL;
    x=p->data;
    delete p;
    return x;
  }
  else
  {
    p=head;
    while (p->next!=head) {
      p=p->next;
    }
    node *temp=head;
    x=temp->data;
    p->next=head->next;
    head=head->next;
    //temp->next=NULL
    delete temp;
    return x;
  }
}
int csll::removeEnd()
{
  int x;
  if(head==NULL)
  {
    std::cout << "no elements to remove" << '\n';
  }
  else if (head->next==head)
  {
    node *p=head;
    head=NULL;
    x=p->data;
    delete p;
    return x;
  }
  else
  {
    node *p=head;
    while(p->next->next!=head)
    {
      p=p->next;
    }
    node *temp;
    temp=p->next;
    x=temp->data;
    p->next=head;
    temp->next=NULL;
    delete temp;
    return x;
  }
}
void csll::display()
{
  node *p=head;
  while (p->next!=head) {
    cout<<p->data<<"\t";
    p=p->next;
  }
  cout<<p->data<<"\n";
}
int main() {
  csll c;
  c.insertBegin(4);
  c.insertEnd(5);
  c.insertBegin(65);
  c.display();
  c.insertBegin(45);
  c.insertEnd(99);
  c.display();
  c.removeEnd();
  c.removeBegin();
  c.display();
  return 0;
}
