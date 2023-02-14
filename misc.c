#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev,*next;
    int data;
};
void rotate(struct node* head,int s){
    struct node* temp,*ptr;
    temp=head;
    if(s==0){
        printf("no rotation");
    }else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        head->prev=temp;
        int i=1;
        while(i<=s){
            temp=temp->prev;
            head=head->prev;
            i++;
        }
        temp->next=NULL;
        head->prev=NULL;
        ptr=head;
        while(ptr!=NULL){
            printf("%d",ptr->data);
            ptr=ptr->next;
        }
    }
}
 struct node* addEnd(struct node* head,int data){
     struct node* tp;
     struct node* temp=malloc(sizeof(struct node));
     tp=head;
     temp->next=NULL;
     temp->data=data;
     temp->prev=NULL;
    while(tp->next!=NULL)
    tp=tp->next;
    temp->prev=tp;
    tp->next=temp;
     return head;
 }
 struct node* addToEmpty(struct node* head,int data){
     struct node* temp=malloc(sizeof(struct node));
     temp->next=NULL;
     temp->data=data;
     temp->prev=NULL;
     head=temp;
     return head;
 }

 struct node* createList(struct node* head){
    int n,i,data;
    scanf("%d",&n);
    scanf("%d",&data);
    head=addToEmpty(head,data);
    for(i=0;i<n-1;i++){
        scanf("%d",&data);
        head=addEnd(head,data);
    }
    printf("\nnow enter skip:");
    return head;
 }
 int main(){
     int skip;
     
     struct node*head,*ptr;
     ptr=head;
     head=createList(head);
     scanf("%d",&skip);
     rotate(head,skip);
     return 0;
 }
