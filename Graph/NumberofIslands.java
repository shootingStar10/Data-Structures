class Solution {
    public static int numIslands (char[][] grid) {
            int count = 0;
            boolean[][] visited = new boolean[grid.length][grid[0].length];

            for(int i = 0; i < grid.length; i++) {
                    for (int j = 0; j < grid[0].length; j++) {
                            visited[i][j] = false;
                    }
            }

            for(int i = 0; i < grid.length; i++) {
                    for (int j = 0; j < grid[0].length; j++) {
                            if(!visited[i][j] && grid[i][j] == '1') {
                                    numIslandsUtils (grid, visited, i , j);
                                    count++;
                            }
                    }
            }

            return count;
    }

    public static void numIslandsUtils (char[][] grid, boolean[][] visited, int row, int column) {
            visited[row][column] = true;

            if(row+1 >= 0 && row+1 < grid.length && column >= 0 && column < grid[0].length && !visited[row+1][column] && grid[row+1][column] == '1')
                    numIslandsUtils (grid, visited, row+1, column);

            if(row-1 >= 0 && row-1 < grid.length && column >= 0 && column < grid[0].length && !visited[row-1][column] && grid[row-1][column] == '1')
                    numIslandsUtils (grid, visited, row-1, column);

            if(row >= 0 && row < grid.length && column+1 >= 0 && column+1 < grid[0].length && !visited[row][column+1] && grid[row][column+1] == '1')
                    numIslandsUtils (grid, visited, row, column+1);

            if(row >= 0 && row < grid.length && column-1 >= 0 && column-1 < grid[0].length && !visited[row][column-1] && grid[row][column-1] == '1')
                    numIslandsUtils (grid, visited, row, column-1);
    }
}