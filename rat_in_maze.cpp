#include<bits/stdc++.h>
using namespace std ;
int x =0 ;
bool solve(char arr[1005][1005],int n,int m,int i,int j,int a[1005][1005]){
    // base case if we reach the end of the maze 
    if(i==n&&j==m){
        a[i][j]=1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){                           

                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        x++;

        cout<<endl;
        return true ;
    }

    // assuming that they can go 
    if(i>n||j>m){
        return false;
    }
    if(arr[i][j]=='X'){
        return false;
    }
    // assuming that current position is right 
    a[i][j]=1;
    bool canright=solve(arr,n,m,i,j+1,a);
    // bool candown=solve(arr,n,m,i+1,j,a);
    
    if(canright){
        return true ;
    }
    if(!canright){
        bool candown=solve(arr,n,m,i+1,j,a);
        if(candown){
            return true ;
        }
        
    }
    // else if(candown){
    //     return true;
    // }
    a[i][j]=0;
    
        
        return false;
    
}



int main(){

    int n;
    int m;
    cin>>n;
    cin>>m;
    char arr[1005][1005];
    int ans[1005][1005]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    bool final =solve(arr,n-1,m-1,0,0,ans);
    if(!final){
        cout<<-1<<endl;
    }
    // cout<<x<<endl;
    
    

}