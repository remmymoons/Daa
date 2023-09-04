#include <bits/stdc++.h>
using namespace std;

class SubsetSum{
    private:
        int count,x[10],w[10],d;

    public:
        SubsetSum(){
            count=0;
        }    

    void subset(int cs, int k, int r){
        x[k]=1;
        if (cs+w[k]==d){
            cout<<"Subset solution ="<< ++count<<endl;
            cout<<"Subset: ";
            for(int i=0;i<=k;i++){
                if(x[i]==1)
                    cout<< w[i]<<" ";
            }
            cout<<endl;
        }
        else if (cs+ w[k]+w[k+1]<=d)
            subset(cs+w[k],k+1,r-w[k]);
        if((cs+r-w[k] >=d) && (cs+w[k] <= d)){
            x[k]=0;
            subset(cs,k+1,r-w[k]);
        }    
    }   

    void solve(){
        int sum=0,n;

        cout<<"Enter number of elements: ";
        cin>>n;
        cout<<"Enter ele: ";
        for(int i=0;i<n;i++){
            cin>> w[i];
        }
        cout<<"enter req sum: ";
        cin>> d;

        for(int i=0;i<n;i++){
            sum+=w[i];
        }

        if(sum<d){
            cout<<"No solution"<<endl;
            return;
        }
        cout<<"The sol is"<<endl;
        subset(0,0,sum);
    }    
};

int main() {
    SubsetSum subsetSum;
    subsetSum.solve();
    return 0;
}
