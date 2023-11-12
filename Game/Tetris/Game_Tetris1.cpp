#include <conio.h>
#include <cstdio>
#include <graphics.h>

//基本成功版本, 每次只会清除一行满的方块

// 游戏区域大小
const int WIDTH = 10;   // 宽度
const int HEIGHT = 20;  // 高度
const int NUMBER_TETRIS = 7; //方块的种数
// 方块类型及其形状定义
enum TetrominoType {
  I, J, L, O, S, T, Z
};

const int TETROMINO_SIZE = 32;  // 方块的大小（边长）
const int MATRIX_SIZE = 4;   //每个形状的矩阵大小

const int TetrominoShapes[][MATRIX_SIZE][MATRIX_SIZE] = {
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
void drawCurTetromino(int currentTetromino[4][4], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (currentTetromino[i][j] == 1) {
        setfillcolor(YELLOW);
        bar((curTetrominoX + j) * TETROMINO_SIZE, (curTetrominoY + i) * TETROMINO_SIZE,
            (curTetrominoX + j + 1) * TETROMINO_SIZE, (curTetrominoY + i + 1) * TETROMINO_SIZE);
      }
    }
  }
}

// 判断方块是否可以移动到指定位置
bool canMoveTo(int newX, int newY, int currentTetromino[4][4], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (currentTetromino[i][j] == 1) {
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
void fixCurTetromino(int curTetromino[4][4], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (curTetromino[i][j] == 1) {
        int x = curTetrominoX + j;
        int y = curTetrominoY + i;
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
          gameArea[y][x] = 1;
        }
      }
    }
  }
}

// 消除满行的方块， 消除所有一行全是1的
int clearFullLines_all() {
  int temp[HEIGHT][WIDTH] = {0};
  int temp_col = HEIGHT- 1;
  int fullLineCount = 0;
  for (int i = HEIGHT - 1; i >= 0; i--) {
    bool isFullLine = true;
    for (int j = 0; j < WIDTH; j++) {
      if (gameArea[i][j] == 0) {
        for(int h = 0; h < WIDTH; h++)
        {//将不是全为1的行移到另一个矩阵
          temp[temp_col][h] = gameArea[i][h];
        }
        temp_col--;
        isFullLine = false;
        break;
      }
    }
    if (isFullLine) {
      fullLineCount++;
    }
  }
  if (fullLineCount > 0) {
    for (int i = 0; i < HEIGHT; i++)
    {
      for (int j = 0; j < WIDTH; j++)
      {
        gameArea[i][j] = temp[i][j];
      }
    }
    drawGameArea();
    Sleep(100);  // 延时一段时间，让玩家看到消除效果
    return fullLineCount;
  }
  return 0;
}


// 消除满行的方块,每次只能消除一行
bool clearFullLines() {
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
    return true;
  }
  return false;
}

// 函数：矩阵顺时针旋转
void rotateMatrix(int matrix[4][4], int n) {
  // 先进行矩阵转置
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }

  // 再按纵向中心线对称交换元素
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n / 2; j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[i][n - j - 1];
      matrix[i][n - j - 1] = temp;
    }
  }
}

// 函数：创建新矩阵旋转
void rotateWithNewMatrix(int src_matrix[4][4], int dst_matrix[4][4], int n) {
  // 旋转原矩阵并赋值给新矩阵
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dst_matrix[j][n - 1 - i] = src_matrix[i][j];
    }
  }
}

// 函数：二维矩阵复制
void copyMatrix(const int srcMatrix[4][4], int destMatrix[4][4], int n) {
  // 复制原矩阵到目标矩阵
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      destMatrix[i][j] = srcMatrix[i][j];
    }
  }
}

// 游戏主循环
void gameLoop() {

  int speed = 1000;
  int time_count = 0;
  int goal = 0;
  int flag = true;
  char str[64] = {0};
  int currentTetromino[MATRIX_SIZE][MATRIX_SIZE];
  // 创建新的方块
  curTetrominoX = WIDTH / 2 - 1;
  curTetrominoY = 0;
  curTetrominoType = static_cast<TetrominoType>(rand() % NUMBER_TETRIS);
  copyMatrix(TetrominoShapes[curTetrominoType], currentTetromino, MATRIX_SIZE);

  while (true) {
    if (goal && goal % 50 == 0 && flag)
    { //每满50分，加速
      speed -= 50; //值越小速度越快
      flag = false;
    }
    time_count += 100;
    // 检测用户输入
    if (_kbhit()) {
      int keyCode = _getch();
      switch (keyCode) {
      case 'P':
      case 'p':
        printf("Stop game!!\n");
        while(1)
        {
          if (_kbhit()) {
            int keyCode1 = _getch();
            if (keyCode1 == 'p' || keyCode1 == 'P')
            {
              printf("Start game!!\n");
              break;
            }
          }
        }
        break;
      case 'Q':
      case 'q':
        settextstyle(10, 10, _T("宋体"));
        sprintf(str, "Exit game ! \n input 's' start new ganme");
        outtextxy(0,320, (str));
        sprintf(str, "Exit game ! \n input 'q' exit ganme");
        outtextxy(0,320, (str));
        printf("Exit current game!!\n");
        return ;
        break;
      case 'W':
      case 'w':
        // 顺时针旋转方块
      {
        int tempTetromino[4][4];
        rotateWithNewMatrix(currentTetromino, tempTetromino, MATRIX_SIZE);
        if (canMoveTo(curTetrominoX, curTetrominoY, tempTetromino, MATRIX_SIZE)) {
          copyMatrix(tempTetromino, currentTetromino, MATRIX_SIZE);
        }
      }
        break;
      case 'A':
      case 'a':
        // 左移方块
        if (canMoveTo(curTetrominoX - 1, curTetrominoY, currentTetromino, MATRIX_SIZE)) {
          curTetrominoX--;
        }
        break;
      case 'D':
      case 'd':
        // 右移方块
        if (canMoveTo(curTetrominoX + 1, curTetrominoY, currentTetromino, MATRIX_SIZE)) {
          curTetrominoX++;
        }
        break;
      case 'S':
      case 's':
        // 快速下移方块
        if (canMoveTo(curTetrominoX, curTetrominoY + 1, currentTetromino, MATRIX_SIZE)) {
          curTetrominoY++;
        }
        else {
          fixCurTetromino(currentTetromino, MATRIX_SIZE);
          int _goal = clearFullLines_all();
          if(_goal)
          {
            goal += _goal * 10;
            flag = true;
          }

          // 创建新的方块
          curTetrominoX = WIDTH / 2 - 1;
          curTetrominoY = 0;
          curTetrominoType = static_cast<TetrominoType>(rand() % NUMBER_TETRIS);
          copyMatrix(TetrominoShapes[curTetrominoType], currentTetromino, MATRIX_SIZE);
          if (!canMoveTo(curTetrominoX, curTetrominoY, currentTetromino, MATRIX_SIZE)) {
            // 新方块无法放置，游戏结束
            settextstyle(10, 10, _T("宋体"));
            sprintf(str, "Game over! \n input 's' start new ganme");
            outtextxy(0,320, (str));
            printf("Game over!!\n");
            return;
            return;
          }
        }
        break;
      }
    }

    // 自动下移方块
    if (canMoveTo(curTetrominoX, curTetrominoY + 1, currentTetromino, MATRIX_SIZE)) {
      if (time_count >= speed)
      {
        curTetrominoY++;
        time_count = 0;
      }

    }
    else {
      fixCurTetromino(currentTetromino, MATRIX_SIZE);
      int _goal = clearFullLines_all();
      if(_goal)
      {
        goal += _goal * 10;
        flag = true;
      }

      // 创建新的方块
      curTetrominoX = WIDTH / 2 - 1;
      curTetrominoY = 0;
      curTetrominoType = static_cast<TetrominoType>(rand() % NUMBER_TETRIS);
      copyMatrix(TetrominoShapes[curTetrominoType], currentTetromino, MATRIX_SIZE);
      if (!canMoveTo(curTetrominoX, curTetrominoY, currentTetromino, MATRIX_SIZE)) {
        // 新方块无法放置，游戏结束
        settextstyle(10, 10, _T("宋体"));
        sprintf(str, "Game over! \n input 's' start new ganme");
        outtextxy(0,320, (str));
        printf("Game over!!\n");
        return;
      }
    }

    drawGameArea();
    drawCurTetromino(currentTetromino, MATRIX_SIZE);

    settextstyle(10, 10, _T("宋体"));
    sprintf(str, "goal: %02d \n speed: %04d", goal, speed);
    outtextxy(0,620, (str));

    Sleep(50);  // 延时一段时间，控制方块下落速度
  }
}

int main()
{
  initgraph(WIDTH * TETROMINO_SIZE, HEIGHT * TETROMINO_SIZE);
  char str[32];
  settextstyle(10, 10, _T("宋体"));
  sprintf(str, "s down/start; w rotate; a letf;");
  outtextxy(0,320, (str));
  sprintf(str, "d right; q exit; p pause/start");
  outtextxy(0,350, (str));
  while(true)
  {
    if (_kbhit()) {
      int keyCode = _getch();
      switch (keyCode) {
      case 's':
        printf("start game\n");
        printf("s down/start; w rotate; a letf; d right; q exit; p pause/start\n");
        for (int i = 0; i < HEIGHT; i++)
        {
          for (int j = 0; j < WIDTH; j++)
          {
            gameArea[i][j] = 0;
          }
        }
        cleardevice();
        gameLoop();
        break;
      case 'q':
        printf("Exit Gmae\n");
        return 0;
        break;
      default:
        printf("Please input s to start game!!\nPlease input q to exit game!!\n");
        break;
      }
    }
  }
  closegraph();
  return 0;
}
