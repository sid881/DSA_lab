#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev,*next;
    int data;
};
struct node* insertSong(struct node*ptr,int data){
    struct node*temp,*temp2;
    struct node*tp=malloc(sizeof(struct node));
    temp=ptr;
    if(ptr->next!=NULL){
    temp2=ptr->next;
    }else{
        temp2=ptr;
    }
    //tp->prev=NULL;
    tp->data=data;
    //tp->next=NULL;
    tp->prev=temp;
    temp->next=tp;
    tp->next=temp2;
    temp2->prev=tp;
    return ptr;
}
struct node *printSong(struct node *ptr){
    struct node* temp;
    temp=ptr;
    printf("%d",temp->data);
    return ptr;
}
struct node *playPrev(struct node *ptr){
    struct node *temp;
    temp=ptr;
    if(temp->prev!=NULL){
        temp=temp->prev;
    }else{
        temp=temp;
    }
    ptr=temp;
    
    return ptr;
}
struct node *playNext(struct node *ptr){
    struct node *temp;
    temp=ptr;
    if(temp->next!=NULL){
    temp=temp->next;
    }else{
        temp=temp;
    }
    ptr=temp;
    return ptr;
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
    return head;
 }
 int main(){
     int n,data;
     struct node*head,*ptr,*ptr2;
     head=createList(head);
     ptr=head;
     while(1){
         printf("\n*now enter operations*");
    scanf("%d",&n);
        if(n==1){
            printf("\nplease insert song at end");
            scanf("%d",&data);
       head=addEnd(head,data);
        }
         else if(n==2){
            ptr=printSong(ptr);
        }else if(n==3){
            ptr=playPrev(ptr);
        }else if(n==4){
            ptr=playNext(ptr);
        }else if(n==5){
            printf("\nplease insert song at between:");
            scanf("%d",&data);
            ptr=insertSong(ptr,data);
            }
        else if(n==6){
           printf("\n*well done*");
            break;
        }
     }
     return 0;
 }