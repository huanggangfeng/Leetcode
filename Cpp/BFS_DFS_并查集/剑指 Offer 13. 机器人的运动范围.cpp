
// BFS:
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int ret = 0;
        bfs(m, n, k, ret);
        return ret;
    }

    void bfs(const int m, const int n, const int k, int &count) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            int i = pos.first;
            int j = pos.second;
            if (i < 0 || i >= m || j <0 || j >= n || visited[i][j])
                continue;

            if (getSum(i) + getSum(j) > k)
                continue;

            visited[i][j] = 1;
            count++;

            for (auto &e : directions) {
                i = pos.first + e[0];
                j = pos.second + e[1];
                if (i < 0 || i >= m || j <0 || j >= n || visited[i][j])
                    continue;
                q.push({i,j});
            }
        }
    }
   
    int getSum(int num)
    {
        if(num < 10)
            return num;
        int sum = 0;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

// DFS
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int ret = 0;
        dfs(visited, 0, 0, m, n, k, ret);
        return ret;
    }

    void dfs(vector<vector<int>> &visited, int i, int j,  const int m, int n, const int k, int &count) {
        if (i < 0 || i >= m || j < 0 || j >=n || visited[i][j])
            return;
        int sum = getSum(i) + getSum(j);
        if (sum <= k) {
            count++;
            visited[i][j] = 1;
        } else
            return;

        dfs(visited, i - 1, j, m, n, k, count);
        dfs(visited, i + 1, j, m, n, k, count);
        dfs(visited, i, j - 1, m, n, k, count);
        dfs(visited, i, j + 1, m, n, k, count);
    }

    int getSum(int num)
    {
        if(num < 10)
            return num;
        int sum = 0;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};