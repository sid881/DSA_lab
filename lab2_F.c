#include<stdio.h>
#include<stdlib.h>
int binary_search(int a[],int N,int l,int target){
   int result=-1;
   int r=N;
   while(l<=r){
       int mid=l+(r-l)/2;
       if(a[mid]==target){
           l=mid+1;
           result=mid;
       }else if(a[mid]<target){
           l=mid+1;
       }else{
           r=mid-1;
       }
   }
   return result+1;
}
 int unique_elements(int a[],int N){
     int count=0;
     int i=0;
     while(i<N){
         i=binary_search(a,N,i,a[i]);
         count++;
     }
     return count;
 } 
 
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",unique_elements(a,n));
    return 0;
}