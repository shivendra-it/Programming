#include<bits/stdc++.h>
using namespace std;



int main(){

    map <string,int> m;
    
     m["063"] = 0;  m["010"] = 1;  m["093"] = 2;  m["079"] = 3;  m["106"] = 4;
     m["103"] = 5;  m["119"] = 6;  m["011"] = 7;  m["127"] = 8;  m["107"] = 9;

     map <int,string> m1;
    
     m1[0] ="063";  m1[1] ="010";  m1[2] = "093";  m1[3] = "079";  m1[4] = "106";
     m1[5] = "103";  m1[6] = "119";  m1[7] = "011";  m1[8] = "127";  m1[9] = "107";

    while (1)
    {
        string s;
        cin>>s;

        if(s=="BYE"){
            return 0;
        }
        size_t pos = s.find('+');
        int convertdata = static_cast<int>(pos);
        int len = s.length();

        string s1 =s.substr(0,pos);
        string s2 =s.substr(pos+1,len-pos-2);


        int len1 = s1.length();
        int len2 = s2.length();

        int n1 = len1/3;
        int n2 = len2/3;
        int i =0;
        int sum =0;
        while(n1--){
            string s3 =s1.substr(i,3);
            i+=3;
            sum += pow(10,n1) * m[s3];
        }
     

        int j =0;
        int sum2 =0;
        while(n2--){
            string s4 =s2.substr(j,3);
            j+=3;
            sum += pow(10,n2) * m[s4];
        }


        
        int sum1 = sum+sum2;
        string out = "";
        while(sum1){
            int k = sum1 % 10;
            out =  m1[k] + out; 
            sum1=sum1/10;
        }
        cout<<s+out<<endl;
    }

    return 0;
}