//to find second largest and smallest element
#include<iostream>
using namespace std;
int slargest(vector<int> vec,int n ){
    //we can also use imt max and min if any -ve value exists
    int largest=vec[0];
    int slargest=-1;
    for(int i=1;i<n;i++){
        if(vec[i]>largest){
            slargest=largest;
            largest=vec[i];
        }
        else if(vec[i]>slargest && vec[i]!=largest) slargest=vec[i];
    }
    return slargest;
}
int ssmallest(vector<int> vec, int n){
    int smallest=vec[0];
    int ssmallest=INT_MAX;
    for(int i=0;i<n;i++){
        if(vec[i]<smallest){
            ssmallest=smallest;
            smallest=vec[i];
        }
        else if(vec[i]<ssmallest && vec[i] !=smallest) ssmallest=vec[i];
    }
    return ssmallest;
}
int main(){
    vector <int> vec={1,2,4,5,7,7,6};
    int n=vec.size();
    cout<<slargest(vec,n)<<endl;
    cout<<ssmallest(vec,n);

    return 0;
}