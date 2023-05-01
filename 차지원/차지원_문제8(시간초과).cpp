#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum class ItemType {
    EMPTY = 0,
    ITEM1 = 1,
    ITEM2 = 2,
    ITEM3 = 3,
    ITEM4 = 4,
    AIRCON = 9
};

enum class PrevType {
    LEFT = 0,
    RIGHT,
    DOWN,
    UP
};

const vector<vector<int>> DIRECTIONS = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
};

void go(int x, int y, int n, int m, queue<vector<int>>& q, int next, vector<vector<vector<bool>>>& visited, int& result) {
    int nx = x + DIRECTIONS[next][0];
    int ny = y + DIRECTIONS[next][1];
    if (0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny][next]) {
        q.push({nx, ny, next});

        if (visited[nx][ny][0] + visited[nx][ny][1] + visited[nx][ny][2] + visited[nx][ny][3] == 0) {
            result++;
        }

        visited[nx][ny][next] = true;
    }
}

int solution(vector<pair<int, int>>& aircons, vector<vector<int>>& board) {
    int result = 0;
    int n = board.size();
    int m = board[0].size();
    vector<vector<vector<bool>>> visited(board.size(), vector<vector<bool>>(board[0].size(), vector<bool>(4, false)));
    queue<vector<int>> q;

    for (auto aircon : aircons) {
        auto [x, y] = aircon;
        q.push({x, y, -1});
        for (int i = 0; i < 4; i++) {
            visited[x][y][i] = true;
        }
        result++;
    }

    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int prev = q.front()[2];
        q.pop();

        switch(static_cast<ItemType>(board[x][y])) {
            case ItemType::EMPTY: {
                go(x, y, n, m, q, prev, visited, result);
                break;
            }
            case ItemType::ITEM1: {
                if (static_cast<PrevType>(prev) == PrevType::DOWN || static_cast<PrevType>(prev) == PrevType::UP) {
                    go(x, y, n, m, q, prev, visited, result);
                }            
                break;
            }
            case ItemType::ITEM2: {
                if (static_cast<PrevType>(prev) == PrevType::LEFT|| static_cast<PrevType>(prev) == PrevType::RIGHT) {
                    go(x, y, n, m, q, prev, visited, result);
                }            
                break;
            }
            case ItemType::ITEM3: {
                int next = 3 - prev;
                go(x, y, n, m, q, next, visited, result);
                break;
            }
            case ItemType::ITEM4: {
                int next = (prev + 2) % 4;
                go(x, y, n, m, q, next, visited, result);
                break;
            }
            case ItemType::AIRCON: {
                for (int i = 0; i < 4; i++) {
                    go(x, y, n, m, q, i, visited, result);
                }
                break;
            }
            default: {
                throw ("item type error");
            }
        }
    }
    
    return result;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    vector<pair<int, int>> aircons;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (static_cast<ItemType>(board[i][j]) == ItemType::AIRCON) {
                aircons.push_back({i, j});
            }
        }
    }

    cout << solution(aircons, board);
    return 0;
}