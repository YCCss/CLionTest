//
// Created by Ycq on 2022/6/7.
//

#ifndef CLIONTEST_LEARN_EASYX_H
#define CLIONTEST_LEARN_EASYX_H

#include <graphics.h>
#include <conio.h>
#include <ctime>

#define MAXSTAR 200	// 星星总数

//星星的结构体
struct STAR
{
    double	x;
    int		y;
    double	step;
    int		color;
};


class LearnEasyx {

private:
    STAR star[MAXSTAR];

    // 初始化星星
    void InitStar(int i)
    {
        star[i].x = 0;
        star[i].y = rand() % 480;
        star[i].step = (rand() % 5000) / 1000.0 + 1;
        star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// 速度越快，颜色越亮
        star[i].color = RGB(star[i].color, star[i].color, star[i].color);
    }

    // 移动星星
    void MoveStar(int i)
    {
        // 擦掉原来的星星
        putpixel((int)star[i].x, star[i].y, 0);

        // 计算新位置
        star[i].x += star[i].step;
        if (star[i].x > 640)	InitStar(i);

        // 画新星星
        putpixel((int)star[i].x, star[i].y, star[i].color);
    }

public:
    //测试
    void ex1(void)
    {
        initgraph(640, 480);	// 创建绘图窗口，大小为 640x480 像素
        setlinecolor(RGB(255, 0, 255)); //设置线条的颜色
        circle(200, 200, 100);	// 画圆，圆心(200, 200)，半径 100
        //填充
        setfillcolor(RGB(0, 0, 255));
        fillcircle(300, 200, 100);

        //文字
        settextcolor(RED); //设置字颜色
        settextstyle(30,20,"宋体"); //设置字大小和字体
        outtextxy(300, 300, "你好");

        _getch();				// 按任意键继续
        closegraph();			// 关闭绘图窗口
    }

    //随机字符
    void ex2(void)
    {
        // 设置随机种子
        srand((unsigned) time(NULL));

        // 初始化图形模式
        initgraph(640, 480);

        int  x, y;
        char c;

        settextstyle(16, 8, _T("Courier"));	// 设置字体

        // 设置颜色
        settextcolor(GREEN);
        setlinecolor(RED);

        for (int i = 0; i <= 479; i++)
        {
            // 在随机位置显示三个随机字母
            for (int j = 0; j < 3; j++)
            {
                x = (rand() % 80) * 8;
                y = (rand() % 20) * 24;
                c = (rand() % 26) + 65;
                outtextxy(x, y, c);
            }

            // 画线擦掉一个像素行
            line(0, i, 639, i);

            Sleep(10);					// 延时
            if (i >= 479)	i = -1;
            if (_kbhit())	break;		// 按任意键退出
        }
        // 关闭图形模式
        closegraph();
    }

    //星星
    void ex3(void)
    {
        srand((unsigned)time(NULL));	// 随机种子
        initgraph(640, 480);			// 创建绘图窗口

        // 初始化所有星星
        for(int i = 0; i < MAXSTAR; i++)
        {
            InitStar(i);
            star[i].x = rand() % 640;
        }

        // 绘制星空，按任意键退出
        while(!_kbhit())
        {
            for(int i = 0; i < MAXSTAR; i++)
                MoveStar(i);
            Sleep(20);
        }

        closegraph();					// 关闭绘图窗口
    }

    //在鼠标的移动轨迹上画红点，按左键画小方块，按 Ctrl + 左键画大方块，按ESC键退出程序
    void ex4(void)
    {
        // 初始化图形窗口
        initgraph(640, 480);

        ExMessage m;		// 定义消息变量

        while(true)
        {
            // 获取一条鼠标或按键消息
            m = getmessage(EM_MOUSE | EM_KEY);

            switch(m.message)
            {
                case WM_MOUSEMOVE:
                    // 鼠标移动的时候画红色的小点
                    putpixel(m.x, m.y, RED);
                    break;

                case WM_LBUTTONDOWN:
                    // 如果点左键的同时按下了 Ctrl 键
                    if (m.ctrl)
                        // 画一个大方块
                        rectangle(m.x - 10, m.y - 10, m.x + 10, m.y + 10);
                    else
                        // 画一个小方块
                        rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
                    break;

                case WM_KEYDOWN:
                    if (m.vkcode == VK_ESCAPE)
                        closegraph();
                        return ;	// 按 ESC 键退出程序
            }
        }

        // 关闭图形窗口
        closegraph();
    }

    //彩虹
    void ex5(void)
    {
        // 创建绘图窗口
        initgraph(640, 480);

        // 画渐变的天空(通过亮度逐渐增加)
        float H = 190;		// 色相
        float S = 1;		// 饱和度
        float L = 0.7f;		// 亮度
        for(int y = 0; y < 480; y++)
        {
            L += 0.0005f;
            setlinecolor( HSLtoRGB(H, S, L) );
            line(0, y, 639, y);
        }

        // 画彩虹(通过色相逐渐增加)
        H = 0;
        S = 1;
        L = 0.5f;
        setlinestyle(PS_SOLID, 2);		// 设置线宽为 2
        for(int r = 400; r > 344; r--)
        {
            H += 5;
            setlinecolor( HSLtoRGB(H, S, L) );
            circle(500, 480, r);
        }

        // 按任意键退出
        _getch();
        closegraph();
    }
};


#endif //CLIONTEST_LEARN_EASYX_H
