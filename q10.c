#include<stdio.h>
 int is_possible(int a[],int k,int n,int x){
     int cnt=0;
     for(int i=0;i<n;i++){
         cnt +=a[i]/x;
         }
         return cnt>=k;
 }
 int main(){
     int n,k;
     int ans=0;
     scanf("%d",&n);
     scanf("%d",&k);
     int a[n];
     for(int i=0;i<n;i++){
         scanf("%d",&a[i]);
     }
     int left=0;
     int right=n-1;
     while(left<=right){
         int mid=(left+right)/2;
         if(is_possible(a,k,n,mid)){
             left=mid+1;
             ans=mid;
         }else{
             right=mid-1;
         }
     }
     printf("%d",ans);
     return 0;
 }
