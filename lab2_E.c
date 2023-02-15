#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev,*next;
    int data;
};
struct node*rotate(struct node*head,int skip){
    struct node*temp;
    temp=head;
    int i=1;
    while(temp->next!=NULL){
    temp=temp->next;
    }
    temp->next=head;
    head->prev=temp;
    while(i<=skip){
        temp=temp->next;
        head=head->next;
        i++;
    }
    temp->next=NULL;
    head->prev=NULL;
    return head;
    
}
struct node*createlist(struct node* head,int n){
  int data;
  scanf("%d",&data);
  struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
  for(int i=0;i<n-1;i++){
      scanf("%d",&data);
      struct node* tp=malloc(sizeof(struct node));
    tp->data=data;
    tp->prev=temp;
    temp->next=tp;
    temp=temp->next;
  }
  return head;
}
int main(){
    int skip,n;
    struct node*head,*ptr;
    scanf("%d",&n);
    scanf("%d",&skip);
    head=createlist(head,n);
    head=rotate(head,skip);
    ptr=head;
   while(ptr!=NULL){
       printf("%d",ptr->data);
       ptr=ptr->next;
   }
   return 0; 
}