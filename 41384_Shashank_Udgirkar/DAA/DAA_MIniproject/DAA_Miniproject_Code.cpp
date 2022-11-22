#include <bits/stdc++.h>
using namespace std;

#define d 256

void RabinKarpSearch(string pat, string txt, int q)
{
    int M = pat.size();
    int N = txt.size();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i=0; i<M-1; i++)
        h = (h * d) % q;

    for (i=0; i<M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i=0; i<=N-M; i++) {
        if (p == t) {
            for (j=0; j<M; j++) {
                if (txt[i+j] != pat[j]) {
                    break;
                }
            }
 
            if (j == M){
                cout<<"\nPattern found at index "<<i<<endl;
                return;
            }
        }

        if (i < N-M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            if (t < 0)
                t = (t + q);
        }
    }

    cout<<"\nPattern not found"<<endl;
}

void NaiveSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();

    for (int i=0; i<=N-M; i++) {
        int j;

        for (j=0; j<M; j++)
            if (txt[i+j] != pat[j])
                break;
 
        if (j == M){
            cout<<"\nPattern found at index "<<i<<endl;
            return;
        }
    }

    cout<<"\nPattern not found"<<endl;
}

int main()
{
    string txt;
    string pat;
    cout<<"\nEnter text: \n";
    getline(cin, txt);
    cout<<"Enter pattern: \n";
    getline(cin, pat);

    while(true){
        cout<<"\n*MENU*\n"<<endl;
        cout<<"1. Naive String Matching"<<endl;
        cout<<"2. Rabin Karp String Matching"<<endl;
        cout<<"3. Exit"<<endl;

        int c;
        cout<<"\nEnter choice: ";
        cin>>c;

        if(c == 1){
            NaiveSearch(pat, txt);
        }
        else if(c == 2){
            int q = INT_MAX;
            RabinKarpSearch(pat, txt, q);
        }
        else if(c == 3){
            break;
        }
        else{
            cout<<"\nEnter valid choice."<<endl;
        }
    }
    
    return 0;
}