#include <graphics.h>
#include <conio.h>
#include <vector>

//基本成功

const int WIDTH = 640;  // 游戏界面宽度
const int HEIGHT = 480; // 游戏界面高度
const int GRID_SIZE = 20; // 方格大小

struct Point {
  int x;
  int y;
};

int main()
{
  initgraph(WIDTH, HEIGHT);

  std::vector<Point> snake; // 贪吃蛇的身体
  snake.push_back({ WIDTH / 2, HEIGHT / 2 }); // 初始位置

  int foodX = 100;
  int foodY = 100;

  bool isGameOver = false;
  int direction = 0; // 0上 1下 2左 3右

  while (!isGameOver) {
    cleardevice(); /*清屏*/

    // 绘制贪吃蛇身体
    setfillcolor(GREEN);
    for (const auto& point : snake) {
      fillrectangle(point.x, point.y, point.x + GRID_SIZE, point.y + GRID_SIZE);
    }

    // 绘制食物
    setfillcolor(RED);
    fillcircle(foodX + GRID_SIZE / 2, foodY + GRID_SIZE / 2, GRID_SIZE / 2);

    if (_kbhit()) {
      int key = _getch();
      if (key == 'w' && direction != 1) {
        direction = 0;
      }
      else if (key == 's' && direction != 0) {
        direction = 1;
      }
      else if (key == 'a' && direction != 3) {
        direction = 2;
      }
      else if (key == 'd' && direction != 2) {
        direction = 3;
      }
    }

    Point newHead = snake[0];
    switch (direction) {
    case 0: // 上
      newHead.y -= GRID_SIZE;
      break;
    case 1: // 下
      newHead.y += GRID_SIZE;
      break;
    case 2: // 左
      newHead.x -= GRID_SIZE;
      break;
    case 3: // 右
      newHead.x += GRID_SIZE;
      break;
    }

    // 判断是否吃到食物
    if (newHead.x == foodX && newHead.y == foodY) {
      // 食物被吃掉，生成新的食物
      foodX = rand() % (WIDTH / GRID_SIZE - 1) * GRID_SIZE;
      foodY = rand() % (HEIGHT / GRID_SIZE - 1) * GRID_SIZE;
    }
    else {
      // 移除蛇尾，使贪吃蛇移动
      snake.pop_back();
    }

    // 判断是否碰到边界或自身
    if (newHead.x < 0 || newHead.x >= WIDTH || newHead.y < 0 || newHead.y >= HEIGHT) {
      isGameOver = true;
    }
    for (const auto& point : snake) {
      if (newHead.x == point.x && newHead.y == point.y) {
        isGameOver = true;
        break;
      }
    }

    // 将新的头部插入到蛇身体的最前面
    snake.insert(snake.begin(), newHead);

    Sleep(100);
  }

  closegraph();

  return 0;
}
