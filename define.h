#ifndef DEFINE_H
#define DEFINE_H
#include <cassert>

namespace Tetris
{

namespace BoxColor
{
enum Color
{
    None = 0,
    Square = 1,//������
    Four,//�ĵ�,����
    Seven,//7��״
    SevenReverse,//��7
    Z,//Z��
    ZReverse,//��Z
    Convex,//͹��
    RegularNum = Convex,
    Cross, //ʮ��
    One,//һ��,���ڳԵ������ĵ�һ��value
    //Two,//����
    Three,//����
    Five,//���
    BoxNum = Five,
    Bomb_one,//һ����ը��
};
}

namespace ClockDirection
{
enum Direction
{
    ClockWise,
    AntiClock,
};
}
}
#endif//DEFINE_H
