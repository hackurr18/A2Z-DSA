#include<iostream>
#include<string>

using namespace std;
/*int main(){

    int arr[5]={1,2,5,2,1};
    
    int hash[6]={0,0,0,0,0,0};
    
    //precomputation
    for(int i=0;i<5;i++){
        hash[arr[i]] +=1 ;
    }
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;

        cout<<hash[number]<< endl;
    }
    return 0;
} */
int hashing(string s){
    //precom
    //kapil
    int hash[26]={0};
    for(int i=0 ;i<sizeof(s);i++){
        int k=s[i] - 'a';
        hash[k] +=1;
    }
    for(auto i:hash){
        cout<<i<<' ';
    }
    int q;
    cout<<"enter count of num";
    cin>>q;
    
    while(q--){
        char target;
        cout<<"enter char"<<endl;
        
        cin>>target;
        int p=target - 'a' ;
        cout<<hash[p]<<endl;
    }
        
    
    return 0;
}
int main(){
    string s;
    cout<<"enter string";
    cin>>s;
    hashing(s);

    return 0;
}
