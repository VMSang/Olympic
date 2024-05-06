#include <bits/stdc++.h>
using namespace std;

int n,dem=1;
int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};
int a[20][20];
void Print(){
    cout<<"Phương án thứ "<<dem<<":\n";
    for(int i=2;i<n+2;i++){
        for(int j=2;j<n+2;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    dem++;
}
void Move(int x,int y,int k){
    for(int i=0;i<8;i++){
        int u=x+dx[i],v=y+dy[i];
        if(a[u][v]==0){
            a[u][v]=k+1;
            if (k==n*n -1)
                Print();
            else
                Move(u,v,k+1);
            a[u][v]=0;
        }
    }
}
int main()
{
    cout<<"n = ";
    cin>>n;
    memset(a,'1',sizeof(a));
    for(int i=2;i<n+2;i++)
        for(int j=2;j<n+2;j++)
            a[i][j]=0;
    Move(2,2,1);
    a[2][2] = 1;
    if (dem==1)
        cout<<"không có phương án nào";
    return 0;
}