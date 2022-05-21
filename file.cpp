#include<bits/stdc++.h>
#define ios     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
map<char, vector<string>>m;
int cnt=0;
void check(vector<string> & path, string &str, string  mystr, int index){
  // Base Case ....
   if(mystr.size()>str.size()){
    // cout<<mystr<<endl;
     return ;
   }
   if(str==mystr){

        cnt++;
        return;
    
    }

   


   for(auto  x : m){

        for(int i=index; i<mystr.size();i++){

            if(mystr[i]==x.first){
                
                for(auto  y : x.second){
                // cout<<y<<endl;
                string str1= mystr.substr(0, i);
                string str2= mystr.substr(i+1);
                path.push_back(y);
                string str3=str1;
                str3+=y;
                str3+=str2;
                check(path,str, str3, i);
                path.pop_back();
                
                }
            }
        }
   }






}
void  RandomYeidGenerator(int count, vector<char> & arr , string str, int k){


    if(count==k){
         vector<string> path;
         string start="S";

         // cout<<str<<endl;
         check(path,str, start,0);
          if(cnt>=2){
            cout<<str<<endl;
         }
         cnt=0;
         return;
    }

   for(int i=0; i<arr.size();i++){

      RandomYeidGenerator(count+1, arr, str+arr[i],k);
   }

     
}
void solve(){


    
    m['S'].push_back("S+S");
    m['S'].push_back("S*S");
    m['S'].push_back("a");
    m['S'].push_back("b");
    vector<char> arr;
    arr.push_back('a');
    arr.push_back('b');
    arr.push_back('+');
    arr.push_back('*');
    string mystr;
    RandomYeidGenerator(0, arr,  mystr,5);
}
signed main(){
    ios
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
        
    int test=1;
    //cin>>test; 
    while(test--){
        solve();
    }    
    return 0;
}