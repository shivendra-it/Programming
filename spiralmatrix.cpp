#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	// DO STUFF HERE AND POPULATE result
	
	int row = A.size();
	int col = A[0].size();
	
	int up=0,down=row,left=0,right=col;
    
    while(up<down && left<right){
        
        for(int i = left; i<right; i++){
            result.push_back(A[up][i]);
        }
        up++;
        
        for(int i = up; i<down; i++){
            result.push_back(A[i][right-1]);
        }
        right--;
        
        if(left<right && up<down){
            
            for(int i = right-1; i>=left; i--){
            result.push_back(A[down-1][i]);
            }
                down--;
       
        
        if(up<down){
            
            for(int i = down-1; i>=up; i--){
            result.push_back(A[i][left]);
            }
                left++;
        }
        }
    }


	return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}


int main(){


vector<vector<int> > A(3);
A[0].push_back(1);
A[0].push_back(2);
A[0].push_back(3);
A[0].push_back(4);
A[1].push_back(5);
A[1].push_back(6);
A[1].push_back(7);
A[1].push_back(8);
A[2].push_back(9);
A[2].push_back(10);
A[2].push_back(11);
A[2].push_back(12);


vector<int> s = spiralOrder(A);
for(int i=0;i<s.size();i++){
	cout<<s[i]<<" ";
}
    return 0;
}