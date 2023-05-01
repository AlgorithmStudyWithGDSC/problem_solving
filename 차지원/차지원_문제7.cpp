#include <iostream>
#include <vector>

using namespace std;

const int UP = 0;
const int DOWN = 1;
const int STRAIGHT = 2;
const int MIN_SCORE = INT32_MIN;
const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}};

int solution(vector<vector<vector<int>>>& board, vector<vector<int>>& scores, int n, int m) {
    for (int x = n - 1; x > -1; x--) {
        for (int y = 0; y < m; y++) {
            for (int i : { STRAIGHT, UP}) {
                int nx = x + DIRECTIONS[i].first;
                int ny = y + DIRECTIONS[i].second;

                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    board[nx][ny][UP] = max(board[nx][ny][UP], board[x][y][UP] + scores[nx][ny]);
                }
            }
            
        }
        
        for (int y = m - 1; y > -1; y--) {
            for (int i : { STRAIGHT, DOWN}) {
                int nx = x + DIRECTIONS[i].first;
                int ny = y + DIRECTIONS[i].second;

                if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                    board[x][y][DOWN] = max(board[x][y][DOWN], board[nx][ny][DOWN] + scores[x][y]);
                }
            }
        }
    }

    int maxSum = MIN_SCORE;
    for (auto& row : board) {
        for (auto& cell : row) {
            maxSum = max(maxSum, cell[0] + cell[1]);
        }
    }

    return maxSum;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> scores(n, vector<int>(m));
    vector<vector<vector<int>>> board(n, vector<vector<int>>(m, vector<int>(2)));

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> scores[row][col];
            board[row][col][UP] = MIN_SCORE;
            board[row][col][DOWN] = MIN_SCORE;
        }
    }

    board[n - 1][0][UP] = scores[n - 1][0];
    board[n - 1][m - 1][DOWN] = scores[n - 1][m - 1];

    cout << solution(board, scores, n, m);
    return 0;
}