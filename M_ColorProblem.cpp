bool isSafe(int ind, bool graph[101][101], int color[], int m, int n)
    {
        for(int i = 0; i < n; i++)
        {
            if(i != ind && graph[ind][i] == 1 && color[i] == m)
                return false;
        }
        return true;
    }
    bool solve(int ind, bool graph[101][101], int m, int n, int color[])
    {
        if(ind == n)
            return true;
        for(int i = 1; i <= m; i++)
        {
            if(isSafe(ind ,graph, color, i, n))
            {
                color[ind] = i;
                if(solve(ind + 1, graph, m, n, color))
                    return true;
                color[ind] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n + 1] = {0};
        bool what = solve(0, graph, m, n, color);
        return what;
    }
