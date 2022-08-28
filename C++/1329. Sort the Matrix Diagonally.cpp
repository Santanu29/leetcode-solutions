// We are traversing diagonal by diagonal and taking all the elements, sorting them and then placing them back into the matrix. As the numbers are in the range 1 <= mat[i][j] <= 100, so we can use counting sort to optimise the time.

class Solution {
    void sortDiagonal(vector<vector<int>>& mat, int row, int col, int m, int n)
    {
        int r = row, c = col;
        vector<int> arr(101,0);
        
        while(c<n && r<m)
        {
            arr[mat[r][c]]++;
            r++;
            c++;
        }
        
        r=row; c=col;
        for(int i=1;i<101;i++)
        {
            if(arr[i]>0)
            {                
                while(arr[i]--)
                {
                    mat[r][c] = i;
                    r++;
                    c++;
                }
            }
        }
    }
    
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        for(int col=0;col<n;col++)
        {
            sortDiagonal(mat, 0, col, m, n);
        }
        
        for(int row=1;row<m;row++)
        {
            sortDiagonal(mat, row, 0, m, n);
        }
        return mat;
    }
};
