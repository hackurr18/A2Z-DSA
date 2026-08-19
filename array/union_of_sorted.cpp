#include<iostream>
#include<set>
#include<vector>

using namespace std;
//brute O(n1logn +n2logn) + O(n1+n2)
vector<int> union_sorted_arr(vector <int>vec1,vector<int>vec2,int n1,int n2){
    set<int>st;
    for(int i=0;i<n1;i++){
        st.insert(vec1[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(vec2[i]);   
    }
    vector<int>temp;
    for(auto i:st){
        temp.push_back(i);

    }
    return temp;
}
//optimal o(n1+n2)
//1,2,7,7,8
//2,4,5,7,8,9
vector<int> union_sorted(vector <int>vec1,vector<int>vec2,int n1,int n2){
     vector<int>ls;
    int j=0 ,i=0;
    while(i<n1 && j<n2){
        if(vec1[i] <=vec2[j]){
            if(ls.size()==0 || ls.back()!= vec1[i]){
                ls.push_back(vec1[i]);
            }
            i++ ;
        }
        else{
            if(ls.size()==0 || ls.back()!= vec2[j]){
                ls.push_back(vec2[j]);
            }
            j++ ;

        }
    }
    while(j<n2){
        if(ls.size()==0 || ls.back()!= vec2[j]){
            ls.push_back(vec2[j]);
        }
        j++ ;

    }
    while(i<n1){
        if(ls.size()==0 || ls.back()!= vec1[i]){
            ls.push_back(vec1[i]);
        }
        i++ ;
    }
    
    return ls;
}
int main(){
    vector<int>vec1={1,2,7,7,8};
    vector<int>vec2={2,4,5,7,8,9};
    int n1=vec1.size();
    int n2=vec2.size();
  //  vector<int>temp= union_sorted_arr(vec1,vec2,n1,n2);
    vector<int>temp= union_sorted(vec1,vec2,n1,n2);
    for(auto i:temp){
        cout<<i<<" ";
    }
    return 0;
}