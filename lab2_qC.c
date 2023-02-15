#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev,*next;
    int data;
};
int targetSum(struct node* head,int target){
    struct node* ptr, *ptr2;
    int count=0;
    ptr = head;
    ptr2=head;
    while(ptr2->next!=NULL)
        ptr2=ptr2->next;
    while(ptr!=ptr2 && ptr2->next!=ptr){
       if(ptr->data+ptr2->data==target){
       count=1;
       break;
       }else{
           if(ptr->data+ptr2->data<target){
               ptr=ptr->next;
           }else{
               ptr2=ptr2->prev;
           }
       }
       
    }
    return count;
}
struct node*createlist(struct node* head){
  int n,data;
  scanf("%d",&n);
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
    int target;
    struct node*head,*ptr;
    scanf("%d",&target);
    head=createlist(head);
    ptr=head;
    printf("%d",targetSum(head,target));
    
}
