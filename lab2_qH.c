#include<stdio.h>
#include<stdlib.h>
long long squareroot(long long n){
    long long l,h;
    l=0;
    h=n;
    long long ans;
    while(l<h){
        long long mid=l+(h-l)/2;
        if(mid*mid==n){
            ans=mid;
            break;
        }else if(mid*mid<n){
            l=mid+1;
            ans=mid+1;
        }else{
            h=mid-1;
        }
    }
    return ans;
}
int main(){
    long long n;
    scanf("%lld",&n);
    printf("%lld",squareroot(n));
    return 0;
}