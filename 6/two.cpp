#include<iostream>
#include<cstring>
using namespace std;

template<class T>
void search(T a[],int n,T key){
    int i,j;
    for(int i=0;i<n;i++){
        if(a[i]==key){
            cout<<i+1<<endl;
            j=1;
        }
    }
    if(j == 0){
        cout<<0<<endl;
    }
}

int main(){
    int t,i,j,n;
    char a;
    cin>>t;
    while(t--)
    {
        cin>>a>>n;
        switch (a) {
            case 'I':{
                int b[n],c;
                for(i=0;i<n;i++){
                    cin>>b[i];
                }
                cin>>c;
                search(b,n,c);
                break;
            }
            case 'S': {
                string b[n],c;

                for(i=0; i<n; i++)
                    cin>>b[i];
                cin>>c;
                Search(b,n,c);
                break;
            }
        }
    }
}