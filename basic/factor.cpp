#include<iostream>
using namespace std;
int main (){
    int a;
    cin>>a;
    vector<int>vec;
    for(int i=1;i<= sqrt(a);i++){
        if(a%i==0){
            vec.push_back(i);
       
            if((a/i )!= i) vec.push_back(a/i);
    }
}
    sort(vec.begin(),vec.end());
    for(int i :vec)
        cout<<i<<" "<<endl;
    return 0;
}