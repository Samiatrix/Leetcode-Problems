class Solution {
public:
    int compareVersion(string version1, string version2) {
        string t = "";
        vector<string> a;
        for(int i=0;i<version1.size();i++){
            if(i == 0){
                t+=version1[i];
            }
            else if(version1[i] == '.'){
                a.push_back(t);
                t = "";
            }
            else{
                t+=version1[i];
            }
        }
        a.push_back(t);
        t="";
        vector<string> b;
        for(int i=0;i<version2.size();i++){
            if(i == 0){
                t+=version2[i];
            }
            else if(version2[i] == '.'){
                b.push_back(t);
                t = "";
            }
            else{
                t+=version2[i];
            }
        }
        b.push_back(t);
        
        for(int i=0;i<a.size();i++){
            a[i] = to_string(stoi(a[i]));
            // int n = a[i].size()-1;
            // while(n>=0 && a[i][n]=='0') n--;
            // a[i] = a[i].substr(0, n+1);
            
        }
        for(int i=0;i<b.size();i++){
            b[i] = to_string(stoi(b[i]));
            // int n = b[i].size()-1;
            // while(n>=0 && b[i][n]=='0') n--;
            // b[i] = b[i].substr(0, n+1);
        }
        // for(auto i:a)   cout<<i<<" ";
        // cout<<endl;
        // for(auto i:b)   cout<<i<<" ";
        
        if(a.size()<b.size()){
            int d = b.size()-a.size();
            for(int i=0;i<d;i++){
                a.push_back("0");
            }
        }
        else{
            // cout<<endl;
            // cout<<a.size()-b.size()<<endl;
            int d = a.size()-b.size();
            for(int i=0;i<d;i++){
                // cout<<"tes"<<endl;
                b.push_back("0");
            }
        }
        // for(auto i:a)   cout<<i<<" ";
        // cout<<endl;
        // for(auto i:b)   cout<<i<<" ";
        
        for(int i=0;i<a.size();i++){
            // cout<<a[i]<<" "<<b[i]<<endl;
            if(stoi(a[i])<stoi(b[i]))   return -1;
            else if(stoi(a[i])>stoi(b[i]))  return 1;
        }
        return 0;
    }
};