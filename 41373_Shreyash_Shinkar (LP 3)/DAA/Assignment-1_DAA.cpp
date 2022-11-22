//Program to generate fibonacci numbers
#include <iostream>

using namespace std;

int fibonacciRecursive(int n){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }

    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

int fibonacciIterative(int n){
    int a = 0, b = 1, c;
    
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    for(int i=2; i<n; i++){
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main()
{
    while(true){
        cout<<"\n*MENU*\n";
        cout<<"1. Recursive"<<endl;
        cout<<"2. Non-Recursive"<<endl;
        int a;
        cout<<"Enter Choice: ";
        cin>>a;
        switch(a){
            case 1:{
                int n;
                cout<<"Enter number: ";
                cin>>n;
                cout<<"Output is: ";
                cout<<fibonacciRecursive(n)<<endl;
                break;
            }
            case 2:{
                int n;
                cout<<"Enter number: ";
                cin>>n;
                cout<<"Output is: ";
                cout<<fibonacciIterative(n)<<endl;
                break;
            }
            default:{
                cout<<"Enter Valid Choice"<<endl;
                break;
            }
        }

        char c;
        cout<<"\nDo you want to continue(Y/N): ";
        cin>>c;
        if(c=='N' || c=='n'){
            cout<<"Thank You!";
            break;
        }
        else{
            continue;
        }

    }
    return 0;
}
