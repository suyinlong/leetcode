class SnakeGame {
private:
    int w, h;
    vector<pair<int, int>> f;
    deque<pair<int, int>> q;
    set<pair<int, int>> snake;
    int count;
    bool end;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        w = width;
        h = height;
        f = food;
        count = 0;
        end = false;

        q.push_back(make_pair(0, 0));
        snake.insert(make_pair(0, 0));
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if (end) return -1;

        int x = q.back().first, y = q.back().second;
        pair<int, int> tail = q.front();
        q.pop_front();
        snake.erase(tail);

        if (direction == "U") x--;
        else if (direction == "L") y--;
        else if (direction == "R") y++;
        else if (direction == "D") x++;

        if (x < 0 || x >= h || y < 0 || y >= w || snake.count(make_pair(x, y))) {
            end = true;
            return -1;
        }

        snake.insert(make_pair(x, y));
        q.push_back(make_pair(x, y));

        if (count >= f.size())
            return f.size();

        if (x == f[count].first && y == f[count].second) {
            count++;
            q.push_front(tail);
            snake.insert(tail);
        }
        return count;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */