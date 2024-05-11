#include<bits/stdc++.h> 
using namespace std; 
int N; 
stack<vector<vector<int>>> st;
int nsol = 0;

bool isSafe(vector<vector<int>>& board,int row ,int col) 
{ 
     for(int j =0;j < col; j++)
     {
        if(board[row][j] == 1)
        return false;
     }

     for(int i = row,j = col; i>=0 && j>= 0; i--,j-- )
     {
        if(board[i][j] == 1)
        return false;
     }
     for(int i = row,j = col; i < N && j>= 0; i++,j-- )
     {
        if(board[i][j] == 1)
        return false;
     }
     return true;
} 

bool solve(vector<vector<int>>& board ,int col ) 
{	 
	if(col>=N){ 
		st.push(board);
        nsol++;
		return false; 
	} 

	for(int i = 0;i<N;i++) 
	{ 
		if(isSafe(board,i,col) == true) 
		{ 
			// rows[i] = true; 
			// left_digonals[i+col] = true; 
			// Right_digonals[col-i+N-1] = true; 
			board[i][col] = 1; 
				
			
			if(solve(board,col+1))
            {
                return true;
            }
			
			// rows[i] = false; 
			// left_digonals[i+col] = false; 
			// Right_digonals[col-i+N-1] = false; 
			board[i][col] = 0;

		} 
	} 
	return false; 
} 


int main() 
{ 
	cout<<"Enter the no of rows for the square Board : "; 
	cin>>N; 

	vector<vector<int>>board(N,vector<int>(N,0)); 
	// vector<bool>rows(N,false);		 
				
	// vector<bool>left_digonals(2*N-1,false); 
	// vector<bool>Right_digonals(2*N-1,false); 

	bool ans = solve(board , 0); 

    if(st.size())
    {
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
			cout << endl<<endl<<endl<<endl;
            
        }
        cout<<"nsol: "<<nsol;
    }
	else
		cout<<"Solution Does not Exist\n"; 
}  
