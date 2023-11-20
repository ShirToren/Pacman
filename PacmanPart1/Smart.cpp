#include "Smart.h"

void Smart::moveInStrategy(const Board& b, GameCreature& creature, const Position& pacmanPos)
{
   
    smartMoving(b, creature, pacmanPos);
  
}
string Smart::pathMoves(const Board& b, const Position& src, const Position& dest)const {

    // Stores the moves of the directions of adjacent cells
    int dRow[] = { -1, 0, 0, 1 };
    int dCol[] = { 0, -1, 1, 0 };

    // Function to find the shortest path from the
    // source to destination in the given  matrix

    
        // Stores the distance for each
        // cell from the source cell
    
    int** d = new int* [b.getRows()];
    for (int i = 0; i < b.getRows(); i++)
    {
        d[i] = new int[b.getCols()];
        for (int j = 0; j < b.getCols(); j++)
        {
            d[i][j] = -1;
        }
    }

        // Distance of source cell is 0
        d[src.getX()][src.getY()] = 0;

        // Initialize a visited array

        bool** visited = new bool* [b.getRows()];
        for (int i = 0; i < b.getRows(); i++)
        {
            visited[i] = new bool[b.getCols()];
            for (int j = 0; j < b.getCols(); j++)
            {
                visited[i][j] = false;
            }
        }

   

        // Mark source cell as visited
        visited[src.getX()][src.getY()] = true;

        // Create a queue for BFS
        queue<Node> q;

        // Distance of source cell is 0
        Node s = { src, 0 };

        // Enqueue source cell
        q.push(s);

        // Keeps track of whether
        // destination is reached or not
        bool ok = false;

        // Iterate until queue is not empty
        while (!q.empty()) {

            // Deque front of the queue
            Node curr = q.front();
            Position pt = curr.pt;

            // If the destination cell is
            // reached, then find the path
            if (pt.getX() == dest.getX()
                && pt.getY() == dest.getY()) {

                int xx = pt.getX(), yy = pt.getY();
                int dist = curr.dist;

                // Assign the distance of
                // destination to the
                // distance matrix
                d[pt.getX()][pt.getY()] = dist;

                // Stores the smallest path
                string pathmoves = "";

                // Iterate until source is reached
                while (xx != src.getX()
                    || yy != src.getY()) {

                    // Append D
                    if (xx > 0 && d[xx - 1][yy] == dist - 1) {
                        pathmoves += 'D';
                        xx--;
                    }

                    // Append U
                    if (xx < (b.getRows() - 1)
                        && d[xx + 1][yy]
                        == dist - 1) {
                        pathmoves += 'U';
                        xx++;
                    }

                    // Append R
                    if (yy > 0 && d[xx][yy - 1] == dist - 1) {
                        pathmoves += 'R';
                        yy--;
                    }

                    // Append L
                    if (yy <(b.getCols() - 1)
                        && d[xx][yy + 1]
                        == dist - 1) {
                        pathmoves += 'L';
                        yy++;
                    }
                    dist--;
                }

                // Reverse the backtracked path
                reverse(pathmoves.begin(),
                    pathmoves.end());

                return pathmoves;
  
            }

            // Pop the start of queue
            q.pop();

            // Explore all adjacent directions
            for (int i = 0; i < 4; i++) {
                int row = pt.getX() + dRow[i];
                int col = pt.getY() + dCol[i];

                // If the current cell is valid
                // cell and can be traversed
                Position p(row, col);
                if (isValid(row, col) && (b.get(p) != '#' && !visited[row][col])) {

                    // Mark the adjacent cells as visited
                    visited[row][col] = true;

                    // Enqueue the adjacent cells
                    Node adjCell
                        = { { row, col }, curr.dist + 1 };
                    q.push(adjCell);

                    // Update the distance
                    // of the adjacent cells
                    d[row][col] = curr.dist + 1;
                }
            }
        }

    // If the destination is not reachable
    return "NONE";
}
void Smart::smartMoving(const Board& b, GameCreature& creature, const Position& pacmanPos)
{
    string shortestPath = pathMoves(b, creature.getPos(), pacmanPos);
    switch (shortestPath[0])
    {
    case 'D':
        creature.setDirection(Direction::DOWN);
        break;
    case 'U':
        creature.setDirection(Direction::UP);
        break;
    case 'L':
        creature.setDirection(Direction::LEFT);
        break;
    case 'R':
        creature.setDirection(Direction::RIGHT);
        break;
    }
    creature.goToCreature();
    cout << b.get(creature.getPos());
    creature.move(b);
    creature.printCreatureMove();

}







