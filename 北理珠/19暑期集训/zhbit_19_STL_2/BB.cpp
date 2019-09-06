#include<iostream>
using namespace std;
int s[100];
int n;
int main()
{

    while(cin>>n&&n)

    {

        int k=1;
        int l=n;
        for(int i=1; i<=n; i++)s[i]=i;
        if(n==1)
        cout<<"Discarded cards:"<<endl<<"Remaining card: 1"<<endl;
        else
        {
            cout<<"Discarded cards: ";
            while(k<l)
            {
                cout<<s[k];
                k++;
                if(k<l)
                cout<<", ";
                if(k==l)
                cout<<endl<<"Remaining card: "<<s[k]<<endl;
                s[++l]=s[k];
                k++;
            }
        }
    }
return 0;
}
