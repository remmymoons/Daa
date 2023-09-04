#include <bits/stdc++.h>
using namespace std;

class Horsepool{
    private:
        int table[128];
        char p[20],t[100];
        int n,m,flag;

    public:
        Horsepool(){
            memset(table,-1,sizeof(table));
            flag=0;
        }

    void input(){
        cout<<"enter text: ";
        cin.getline(t,sizeof(t));
        n=strlen(t);

        cout<<"enter pattern: ";
        cin.getline(p,sizeof(p));
        m=strlen(p);
    }    

    void compute(){
        for(int i=0;i<m-1;i++){
            table[p[i]] = m-1-i;
        }

        int i=m-1;
        while(i<n){
            int k=0;
            while (k<m && p[m-1-k]== t[i-k])
                k++;
            if(k==m){
                cout<<"posiiton of pattern is: "<<i-m+2<<endl;
                flag =1;
                break;
            }    
            else{
                i+= table[t[i]] !=-1 ? table[t[i]] : m;
            }
        }

        if (!flag)
            cout<<"Pattern not found";
    }
};

int main(){
    Horsepool obj;
    obj.input();
    obj.compute();
    return 0;
}
