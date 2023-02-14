#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
    struct node{
     struct node* prev;
     int data;
     struct node *next;
    };
    
void targetSum(struct node* head,int x){
    struct node* ptr, *ptr2;
    ptr = head;
    
    
    ptr2=head;
    while(ptr2->next!=NULL)
        ptr2=ptr2->next;
        
    
    while(ptr!=ptr2 && ptr2->next!=ptr){
            

       if(ptr->data+ptr2->data==x){
        ptr2=ptr2->prev;
       ptr=ptr->next;
       
       }else{
           if(ptr->data+ptr2->data<x){
               ptr=ptr->next;
           }else{
               ptr2=ptr2->prev;
           }
           
       }
       
    }
    
}
 
     struct node *addToEmpty (struct node *head, int data){
      struct node *temp = (struct node *) malloc (sizeof (struct node));
      temp->prev = NULL;
      temp->data = data;
      temp->next = NULL;
      head = temp;
       return head;
      }
    
    
     struct node *addToEnd (struct node *head, int data){
      struct node *temp = malloc (sizeof (struct node));
      struct node *tp;
      temp->prev = NULL;
      temp->data = data;
      temp->next = NULL;
      tp=head;
      while(tp->next!=NULL)
      tp=tp->next;
      tp->next=temp;
      temp->prev=tp;

     return head;
         }
struct node* createList(struct node* head){
    int n,data,i;
    int skip;
    scanf("%d",&n);
    scanf("%d",&data);
    head=addToEmpty(head,data);
    for(i=0;i<n-1;i++){
        scanf("%d",&data);
       head=addToEnd(head,data);
    }

    return head;
}
 int main () 
{
    int target;
    scanf("%d",&target);
   struct node *head = NULL;
    struct node *ptr;
    
   head=createList(head);
   ptr = head;
   targetSum(head,target);
  return 0;
}
