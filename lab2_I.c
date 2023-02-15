#include<stdio.h>
#include<stdlib.h>
int step(int a[],int n,int target){
    int l,r;
    l=0;
    r=n-1;
    int count=0;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(a[mid]<target){
            l=mid+1;
            count=l;
        }else{
          r=mid-1; 
        }
    }
    return count;
    
}
int main(){
    int n,target;
    scanf("%d",&n);
    target=n*(n-1)/4;
    int a[n];
    int i=0;
    while(i<n){
        if(i==0){
            a[0]=n-1;
        }else{
            a[i]=n-i-1;
        }
        i++;
    }
   
    for(i=0;i<n;i++){
        if(i==0){
            a[i]=a[i];
        }else{
        a[i]+=a[i-1];
        }
    }
     printf("%d",step(a,n,target)+1);
    
    return 0;
}
