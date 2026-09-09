#include <vector>
using std::vector;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int m = grid.size();
	    int n = grid[0].size();
	    int numIslands{0};

        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == '1'){
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
            
        }

        return numIslands;
    }
private:
    // verifica os adjacentes (cima, baixo, esquerda, direita)
    void dfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
	    int n = grid[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;
        // troca o valor no grid para '0' evitando dupla contagem
        grid[i][j] = '0';
        dfs(grid, i,     j + 1); // direita
        dfs(grid, i + 1, j); // baixo
        dfs(grid, i,     j - 1); // esquerda
        dfs(grid, i - 1, j); // cima
    }
};