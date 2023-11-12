#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <cstdio>

//每走一步蛇的长度都会增加，需要检查

#define MAX_BODY_LENGTH 100    // 贪吃蛇最大长度
#define CELL_SIZE        20    // 每个格子的大小
#define BOARD_WIDTH      25    // 游戏界面宽度（格子数）
#define BOARD_HEIGHT     25    // 游戏界面高度（格子数）

// 贪吃蛇的方向枚举类型
enum Direction {
  UP, DOWN, LEFT, RIGHT
};

// 定义贪吃蛇的结构体
struct Snake {
  int x[MAX_BODY_LENGTH];    // 每个身体节的横坐标
  int y[MAX_BODY_LENGTH];    // 每个身体节的纵坐标
  int length;                // 身体长度
  Direction dir;             // 移动方向
};

// 定义游戏界面的结构体
struct Board {
  int width;          // 界面宽度（格子数）
  int height;         // 界面高度（格子数）
  int score;          // 得分
  bool is_over;       // 是否结束
  Snake snake;        // 贪吃蛇
  int food_x;         // 食物横坐标
  int food_y;         // 食物纵坐标
};

// 初始化游戏界面
void init_board(Board& board) {
  board.width = BOARD_WIDTH;
  board.height = BOARD_HEIGHT;
  board.score = 0;
  board.is_over = false;

  // 初始化贪吃蛇
  board.snake.length = 3;
  board.snake.x[0] = 2;
  board.snake.y[0] = 2;
  board.snake.x[1] = 1;
  board.snake.y[1] = 2;
  board.snake.x[2] = 0;
  board.snake.y[2] = 2;
  board.snake.dir = RIGHT;

  // 随机生成食物位置
  srand((unsigned)time(NULL));
  board.food_x = rand() % BOARD_WIDTH;
  board.food_y = rand() % BOARD_HEIGHT;
}

// 绘制游戏界面
void draw_board(const Board& board) {
  // 绘制网格
  setlinecolor(RGB(192, 192, 192));   // 设置灰色
  for (int i = 0; i <= board.width; i++) {
    line(i * CELL_SIZE, 0, i * CELL_SIZE, board.height * CELL_SIZE);
  }
  for (int i = 0; i <= board.height; i++) {
    line(0, i * CELL_SIZE, board.width * CELL_SIZE, i * CELL_SIZE);
  }

  // 绘制贪吃蛇
  setfillcolor(RGB(0, 255, 0));     // 设置绿色
  for (int i = 0; i < board.snake.length; i++) {
    fillrectangle(board.snake.x[i] * CELL_SIZE, board.snake.y[i] * CELL_SIZE,
                  (board.snake.x[i] + 1) * CELL_SIZE, (board.snake.y[i] + 1) * CELL_SIZE);
  }

  // 绘制食物
  if (!board.is_over) {
    setfillcolor(RGB(255, 0, 0));     // 设置红色
    fillcircle((board.food_x + 0.5) * CELL_SIZE, (board.food_y + 0.5) * CELL_SIZE, CELL_SIZE / 2 - 2);
  }

  // 绘制得分
  settextstyle(20, 0, "Consolas");
  char score_str[32];
  sprintf(score_str, "Score: %d", board.score);
  outtextxy(10, BOARD_HEIGHT * CELL_SIZE - 30, score_str);

  // 绘制游戏结束提示
  if (board.is_over) {
    settextstyle(60, 0, "Consolas");
    setbkmode(TRANSPARENT);
    outtextxy((BOARD_WIDTH * CELL_SIZE - 350) / 2, BOARD_HEIGHT * CELL_SIZE / 2 - 30, "Game Over!");
  }
}

// 处理键盘输入
void handle_input(Board& board) {
  if (_kbhit()) {
    int ch = _getch();
    switch (ch) {
    case 'W':
    case 'w':
      if (board.snake.dir != DOWN) {
        board.snake.dir = UP;
      }
      break;
    case 'S':
    case 's':
      if (board.snake.dir != UP) {
        board.snake.dir = DOWN;
      }
      break;
    case 'A':
    case 'a':
      if (board.snake.dir != RIGHT) {
        board.snake.dir = LEFT;
      }
      break;
    case 'D':
    case 'd':
      if (board.snake.dir != LEFT) {
        board.snake.dir = RIGHT;
      }
      break;
    }
  }
}

// 移动贪吃蛇
void move_snake(Board& board) {
  // 计算贪吃蛇头部下一步的位置
  int next_x = board.snake.x[0];
  int next_y = board.snake.y[0];
  switch (board.snake.dir) {
  case UP:
    next_y--;
    break;
  case DOWN:
    next_y++;
    break;
  case LEFT:
    next_x--;
    break;
  case RIGHT:
    next_x++;
    break;
  }

  // 检测是否撞墙或撞到自己
  if (next_x < 0 || next_x >= board.width || next_y < 0 || next_y >= board.height) {
    board.is_over = true;
    return;
  }
  for (int i = 1; i < board.snake.length; i++) {
    if (next_x == board.snake.x[i] && next_y == board.snake.y[i]) {
      board.is_over = true;
      return;
    }
  }

  // 检测是否吃到食物
  bool ate_food = false;
  if (board.food_x == next_x && board.food_y == next_y) {
    board.score++;
    ate_food = true;
    board.food_x = rand() % BOARD_WIDTH;
    board.food_y = rand() % BOARD_HEIGHT;
  }

  // 移动身体
  for (int i = board.snake.length - 1; i > 0; i--) {
    board.snake.x[i] = board.snake.x[i - 1];
    board.snake.y[i] = board.snake.y[i - 1];
  }

  // 如果吃到食物，则增加身体长度
  if (ate_food && board.snake.length < MAX_BODY_LENGTH) {
    board.snake.length++;
  }

  // 移动头部
  board.snake.x[0] = next_x;
  board.snake.y[0] = next_y;
}


int main() {
  initgraph(CELL_SIZE * BOARD_WIDTH, CELL_SIZE * BOARD_HEIGHT);
  Board board;
  init_board(board);

  while (!board.is_over) {
    cleardevice();
    draw_board(board);
    handle_input(board);
    move_snake(board);
    Sleep(100);
  }

  draw_board(board);
  _getch();
  closegraph();
  return 0;
}
