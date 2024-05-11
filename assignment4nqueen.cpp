#include<bits/stdc++.h> 
using namespace std; 
int N; 
stack<vector<vector<int>>> st;

bool isSafe(int row ,int col ,vector<bool>rows , vector<bool>left_digonals ,vector<bool>Right_digonals) 
{ 
    return !(rows[row] || left_digonals[row+col] || Right_digonals[col-row+N-1]) ;
} 

bool solve(vector<vector<int>>& board ,int col ,vector<bool>rows ,vector<bool>left_digonals ,vector<bool>Right_digonals) 
{	 
	if(col>=N){ 
		st.push(board);
		return true; 
	} 

	for(int i = 0;i<N;i++) 
	{ 
		if(isSafe(i,col,rows,left_digonals,Right_digonals) == true) 
		{ 
			rows[i] = true; 
			left_digonals[i+col] = true; 
			Right_digonals[col-i+N-1] = true; 
			board[i][col] = 1; 
				
			
			bool sol = solve(board,col+1,rows,left_digonals,Right_digonals);
			
			rows[i] = false; 
			left_digonals[i+col] = false; 
			Right_digonals[col-i+N-1] = false; 
			board[i][col] = 0;

			if(sol){ 
				// printSol(board);
				// cout << endl;
				st.push(board);
				return true; 
			} 
		} 
	} 
	return false; 
} 


int main() 
{ 
	cout<<"Enter the no of rows for the square Board : "; 
	cin>>N; 

	vector<vector<int>>board(N,vector<int>(N,0)); 
	vector<bool>rows(N,false);		 
				
	vector<bool>left_digonals(2*N-1,false); 
	vector<bool>Right_digonals(2*N-1,false); 

	bool ans = solve(board , 0, rows,left_digonals,Right_digonals); 

	if(ans == true){ 

		while(!st.empty())
		{
			vector<vector<int>> b1= st.top();
			st.pop();
			for(auto it:b1)
			{
				for(auto it1:it)
					cout << it1 << " ";
				cout << endl;
			}
			cout << endl;
		}
	} 
	else
		cout<<"Solution Does not Exist\n"; 
}  
