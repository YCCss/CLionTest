//
// Created by Ycq on 2022/6/7.
//

#ifndef CLIONTEST_LEARN_EASYX_H
#define CLIONTEST_LEARN_EASYX_H

#include <graphics.h>
#include <conio.h>
#include <ctime>

#define MAXSTAR 200	// ��������

//���ǵĽṹ��
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

    // ��ʼ������
    void InitStar(int i)
    {
        star[i].x = 0;
        star[i].y = rand() % 480;
        star[i].step = (rand() % 5000) / 1000.0 + 1;
        star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// �ٶ�Խ�죬��ɫԽ��
        star[i].color = RGB(star[i].color, star[i].color, star[i].color);
    }

    // �ƶ�����
    void MoveStar(int i)
    {
        // ����ԭ��������
        putpixel((int)star[i].x, star[i].y, 0);

        // ������λ��
        star[i].x += star[i].step;
        if (star[i].x > 640)	InitStar(i);

        // ��������
        putpixel((int)star[i].x, star[i].y, star[i].color);
    }

public:
    //����
    void ex1(void)
    {
        initgraph(640, 480);	// ������ͼ���ڣ���СΪ 640x480 ����
        setlinecolor(RGB(255, 0, 255)); //������������ɫ
        circle(200, 200, 100);	// ��Բ��Բ��(200, 200)���뾶 100
        //���
        setfillcolor(RGB(0, 0, 255));
        fillcircle(300, 200, 100);

        //����
        settextcolor(RED); //��������ɫ
        settextstyle(30,20,"����"); //�����ִ�С������
        outtextxy(300, 300, "���");

        _getch();				// �����������
        closegraph();			// �رջ�ͼ����
    }

    //����ַ�
    void ex2(void)
    {
        // �����������
        srand((unsigned) time(NULL));

        // ��ʼ��ͼ��ģʽ
        initgraph(640, 480);

        int  x, y;
        char c;

        settextstyle(16, 8, _T("Courier"));	// ��������

        // ������ɫ
        settextcolor(GREEN);
        setlinecolor(RED);

        for (int i = 0; i <= 479; i++)
        {
            // �����λ����ʾ���������ĸ
            for (int j = 0; j < 3; j++)
            {
                x = (rand() % 80) * 8;
                y = (rand() % 20) * 24;
                c = (rand() % 26) + 65;
                outtextxy(x, y, c);
            }

            // ���߲���һ��������
            line(0, i, 639, i);

            Sleep(10);					// ��ʱ
            if (i >= 479)	i = -1;
            if (_kbhit())	break;		// ��������˳�
        }
        // �ر�ͼ��ģʽ
        closegraph();
    }

    //����
    void ex3(void)
    {
        srand((unsigned)time(NULL));	// �������
        initgraph(640, 480);			// ������ͼ����

        // ��ʼ����������
        for(int i = 0; i < MAXSTAR; i++)
        {
            InitStar(i);
            star[i].x = rand() % 640;
        }

        // �����ǿգ���������˳�
        while(!_kbhit())
        {
            for(int i = 0; i < MAXSTAR; i++)
                MoveStar(i);
            Sleep(20);
        }

        closegraph();					// �رջ�ͼ����
    }

    //�������ƶ��켣�ϻ���㣬�������С���飬�� Ctrl + ������󷽿飬��ESC���˳�����
    void ex4(void)
    {
        // ��ʼ��ͼ�δ���
        initgraph(640, 480);

        ExMessage m;		// ������Ϣ����

        while(true)
        {
            // ��ȡһ�����򰴼���Ϣ
            m = getmessage(EM_MOUSE | EM_KEY);

            switch(m.message)
            {
                case WM_MOUSEMOVE:
                    // ����ƶ���ʱ�򻭺�ɫ��С��
                    putpixel(m.x, m.y, RED);
                    break;

                case WM_LBUTTONDOWN:
                    // ����������ͬʱ������ Ctrl ��
                    if (m.ctrl)
                        // ��һ���󷽿�
                        rectangle(m.x - 10, m.y - 10, m.x + 10, m.y + 10);
                    else
                        // ��һ��С����
                        rectangle(m.x - 5, m.y - 5, m.x + 5, m.y + 5);
                    break;

                case WM_KEYDOWN:
                    if (m.vkcode == VK_ESCAPE)
                        closegraph();
                        return ;	// �� ESC ���˳�����
            }
        }

        // �ر�ͼ�δ���
        closegraph();
    }

    //�ʺ�
    void ex5(void)
    {
        // ������ͼ����
        initgraph(640, 480);

        // ����������(ͨ������������)
        float H = 190;		// ɫ��
        float S = 1;		// ���Ͷ�
        float L = 0.7f;		// ����
        for(int y = 0; y < 480; y++)
        {
            L += 0.0005f;
            setlinecolor( HSLtoRGB(H, S, L) );
            line(0, y, 639, y);
        }

        // ���ʺ�(ͨ��ɫ��������)
        H = 0;
        S = 1;
        L = 0.5f;
        setlinestyle(PS_SOLID, 2);		// �����߿�Ϊ 2
        for(int r = 400; r > 344; r--)
        {
            H += 5;
            setlinecolor( HSLtoRGB(H, S, L) );
            circle(500, 480, r);
        }

        // ��������˳�
        _getch();
        closegraph();
    }
};


#endif //CLIONTEST_LEARN_EASYX_H