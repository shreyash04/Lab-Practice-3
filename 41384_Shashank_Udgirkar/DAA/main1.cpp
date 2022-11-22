
//Program to generate fibonacci numbers
#include <iostream>

using namespace std;

int fibonacci_recursive(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return fibonacci_recursive(n-1)+fibonacci_recursive(n-2);
}

int fibonacci_iterative(int n){
    int a,b,c;
    a=0;
    b=1;
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    for(int i=2;i<n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}

int main()
{
    cout<<"*********MENU**********"<<'\n';
    cout<<"1.Recursive"<<'\n';
    cout<<"2.Non Recursive"<<'\n';
    int a;

    while(1){
        cout<<"Enter Choice"<<'\n';
        cin>>a;
        switch(a){
            case 1:{
                int n;
                cout<<"Enter number"<<'\n';
                cin>>n;
                cout<<"Output is : ";
                cout<<fibonacci_recursive(n)<<'\n';
                break;
            }
            case 2:{
                int n;
                cout<<"Enter number"<<'\n';
                cin>>n;
                cout<<"Output is : ";
                cout<<fibonacci_iterative(n)<<'\n';
                break;
            }
            default:{
                cout<<"Enter Valid Choice"<<'\n';
                break;
            }
        }
        char c;
        cout<<"\nDo you want to continue(Y/N)"<<'\n';
        cin>>c;
        if(c=='N'){
            cout<<"Thank-You"<<'\n';
            break;
        }
        else{
            continue;
        }

    }
    return 0;
}
