#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void findPath(vector<vector<int> >& grid, vector<vector<int> >& dp, vector<vector<int> >& path, int n, int m) {
    dp[0][0] = grid[0][0];

    // Initialize first row
    for(int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    // Initialize first column
    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    // Fill dp table and track path
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(dp[i-1][j] < dp[i][j-1]) {
                dp[i][j] = dp[i-1][j] + grid[i][j];
                path[i][j] = 1; // came from up
            } else {
                dp[i][j] = dp[i][j-1] + grid[i][j];
                path[i][j] = 0; // came from left
            }
        }
    }
}

void printPath(vector<vector<int> >& grid, vector<vector<int> >& path, int n, int m) {
    vector<int> result;
    int i = n-1, j = m-1;

    while(i >= 0 && j >= 0) {
        result.push_back(grid[i][j]);
        if(i == 0 && j == 0) break;

        if(i == 0) j--;
        else if(j == 0) i--;
        else {
            if(path[i][j] == 1) i--;
            else j--;
        }
    }

    for(int i = result.size()-1; i >= 0; i--) {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > grid(n, vector<int>(m));
    vector<vector<int> > dp(n, vector<int>(m));
    vector<vector<int> > path(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    findPath(grid, dp, path, n, m);

    cout << dp[n-1][m-1] << endl;
    printPath(grid, path, n, m);

    return 0;
}
