class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        unordered_map<char , int> mp;
         mp['b']=0;
        mp['a']=0;
        mp['l']=0;
        mp['o']=0;
        mp['n']=0;
        for(int i =0;i<n;i++){
            mp[text[i]]++;

        }
        int mnm = INT_MAX;
       
        for(auto it : mp){
            char c = it.first;
            int freq=it.second;
            if(c=='b' || c=='a' || c=='l' ||  c=='o' ||  c=='n' ){
                if( c=='l' ||  c=='o' ){
                    mnm = min(freq/2,mnm);
                    

                }
                else{
                    mnm = min(freq , mnm);

                }
                cout<<mnm<<endl;
            }

        }
        return mnm;

        
    }
};