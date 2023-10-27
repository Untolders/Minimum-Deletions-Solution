**********************************************************************************************  Question  ***********************************************************************************************

Given a string of S as input. Your task is to write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome.
Note: The order of characters in the string should be maintained.

Example 1:

Input: 
S = "aebcbda"
Output: 
2
Explanation: 
Remove characters 'e' and 'd'.
Example 2:

Input: 
S = "geeksforgeeks"
Output: 
8
Explanation: 
One of the possible result string can be "eefee", so answer is 13 - 5 = 8.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function minimumNumberOfDeletions() which takes the string S as inputs and returns the minimum number of deletions required to convert S into a pallindrome.

Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(|S|2)

Constraints:
1 ≤ |S| ≤ 103






************************************************************************************************  Solution  *********************************************************************************************

  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int lcs(string &a,string &b,int m,int n,vector<vector<int>> &dp){
        if(!m or !n) return 0;
        if(dp[m][n]!= -1) return dp[m][n]; 
        if(a[m-1] == b[n-1]) return dp[m][n]=1+lcs(a,b,m-1,n-1,dp);
        return dp[m][n]=max(lcs(a,b,m-1,n,dp),lcs(a,b,m,n-1,dp));
    }
    int minimumNumberOfDeletions(string S) { 
        string a = S;
        int n = a.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        reverse(S.begin(),S.end());
        return n-lcs(a,S,n,n,dp);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends
