#include <graphics.h>
#include <conio.h>

//旋转的对象不对，他是随机选着下一个

// 游戏区域大小
const int WIDTH = 10;   // 宽度
const int HEIGHT = 20;  // 高度

// 方块类型及其形状定义
enum TetrominoType {
  I, J, L, O, S, T, Z
};

const int TETROMINO_SIZE = 32;  // 方块的大小（边长）

const int TetrominoShapes[][TETROMINO_SIZE][TETROMINO_SIZE] = {
    // I型方块
    {
        { 0, 0, 0, 0 },
        { 1, 1, 1, 1 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    },
    // J型方块
    {
        { 1, 0, 0, 0 },
        { 1, 1, 1, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    },
    // L型方块
    {
        { 0, 0, 1, 0 },
        { 1, 1, 1, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    },
    // O型方块
    {
        { 1, 1, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    },
    // S型方块
    {
        { 0, 1, 1, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    },
    // T型方块
    {
        { 0, 1, 0, 0 },
        { 1, 1, 1, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    },
    // Z型方块
    {
        { 1, 1, 0, 0 },
        { 0, 1, 1, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 }
    }
};

// 游戏区域数组
int gameArea[HEIGHT][WIDTH] = { 0 };

// 方块当前位置和类型
int curTetrominoX = WIDTH / 2 - 1;
int curTetrominoY = 0;
TetrominoType curTetrominoType;

// 绘制游戏区域
void drawGameArea() {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (gameArea[i][j] == 1) {
        setfillcolor(LIGHTBLUE);
        bar(j * TETROMINO_SIZE, i * TETROMINO_SIZE, (j + 1) * TETROMINO_SIZE, (i + 1) * TETROMINO_SIZE);
      }
      else {
        setfillcolor(BLACK);
        bar(j * TETROMINO_SIZE, i * TETROMINO_SIZE, (j + 1) * TETROMINO_SIZE, (i + 1) * TETROMINO_SIZE);
      }
    }
  }
}

// 绘制当前方块
void drawCurTetromino() {
  for (int i = 0; i < TETROMINO_SIZE; i++) {
    for (int j = 0; j < TETROMINO_SIZE; j++) {
      if (TetrominoShapes[curTetrominoType][i][j] == 1) {
        setfillcolor(YELLOW);
        bar((curTetrominoX + j) * TETROMINO_SIZE, (curTetrominoY + i) * TETROMINO_SIZE,
            (curTetrominoX + j + 1) * TETROMINO_SIZE, (curTetrominoY + i + 1) * TETROMINO_SIZE);
      }
    }
  }
}

// 判断方块是否可以移动到指定位置
bool canMoveTo(int newX, int newY, TetrominoType type) {
  for (int i = 0; i < TETROMINO_SIZE; i++) {
    for (int j = 0; j < TETROMINO_SIZE; j++) {
      if (TetrominoShapes[type][i][j] == 1) {
        int x = newX + j;
        int y = newY + i;
        if (x < 0 || x >= WIDTH || y >= HEIGHT || (y >= 0 && gameArea[y][x] == 1)) {
          return false;
        }
      }
    }
  }
  return true;
}

// 将当前方块固定在游戏区域中
void fixCurTetromino() {
  for (int i = 0; i < TETROMINO_SIZE; i++) {
    for (int j = 0; j < TETROMINO_SIZE; j++) {
      if (TetrominoShapes[curTetrominoType][i][j] == 1) {
        int x = curTetrominoX + j;
        int y = curTetrominoY + i;
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
          gameArea[y][x] = 1;
        }
      }
    }
  }
}

// 消除满行的方块
void clearFullLines() {
  int fullLineCount = 0;
  for (int i = HEIGHT - 1; i >= 0; i--) {
    bool isFullLine = true;
    for (int j = 0; j < WIDTH; j++) {
      if (gameArea[i][j] == 0) {
        isFullLine = false;
        break;
      }
    }
    if (isFullLine) {
      // 将上方的行依次下移一行
      for (int k = i; k > 0; k--) {
        for (int j = 0; j < WIDTH; j++) {
          gameArea[k][j] = gameArea[k - 1][j];
        }
      }
      // 清空顶部的一行
      for (int j = 0; j < WIDTH; j++) {
        gameArea[0][j] = 0;
      }
      fullLineCount++;
    }
  }
  if (fullLineCount > 0) {
    drawGameArea();
    Sleep(300);  // 延时一段时间，让玩家看到消除效果
  }
}

// 游戏主循环
void gameLoop() {
  while (true) {
    // 检测用户输入
    if (_kbhit()) {
      int keyCode = _getch();
      switch (keyCode) {
      case 'W':
      case 'w':
        // 顺时针旋转方块
      {
        TetrominoType nextType = static_cast<TetrominoType>((curTetrominoType + 1) % 7);
        if (canMoveTo(curTetrominoX, curTetrominoY, nextType)) {
          curTetrominoType = nextType;
        }
      }
        break;
      case 'A':
      case 'a':
        // 左移方块
        if (canMoveTo(curTetrominoX - 1, curTetrominoY, curTetrominoType)) {
          curTetrominoX--;
        }
        break;
      case 'D':
      case 'd':
        // 右移方块
        if (canMoveTo(curTetrominoX + 1, curTetrominoY, curTetrominoType)) {
          curTetrominoX++;
        }
        break;
      case 'S':
      case 's':
        // 快速下移方块
        if (canMoveTo(curTetrominoX, curTetrominoY + 1, curTetrominoType)) {
          curTetrominoY++;
        }
        else {
          fixCurTetromino();
          clearFullLines();
          // 创建新的方块
          curTetrominoX = WIDTH / 2 - 1;
          curTetrominoY = 0;
          curTetrominoType = static_cast<TetrominoType>(rand() % 7);
          if (!canMoveTo(curTetrominoX, curTetrominoY, curTetrominoType)) {
            // 新方块无法放置，游戏结束
            return;
          }
        }
        break;
      }
    }

    // 自动下移方块
    if (canMoveTo(curTetrominoX, curTetrominoY + 1, curTetrominoType)) {
      curTetrominoY++;
    }
    else {
      fixCurTetromino();
      clearFullLines();
      // 创建新的方块
      curTetrominoX = WIDTH / 2 - 1;
      curTetrominoY = 0;
      curTetrominoType = static_cast<TetrominoType>(rand() % 7);
      if (!canMoveTo(curTetrominoX, curTetrominoY, curTetrominoType)) {
        // 新方块无法放置，游戏结束
        return;
      }
    }

    drawGameArea();
    drawCurTetromino();
    Sleep(800);  // 延时一段时间，控制方块下落速度
  }
}

int main()
{
  initgraph(WIDTH * TETROMINO_SIZE, HEIGHT * TETROMINO_SIZE);
  gameLoop();
  closegraph();
  return 0;
}
