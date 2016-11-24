#ifndef DEFINE_H
#define DEFINE_H
#include <cassert>

namespace Tetris
{

enum class BoxColor
{
    None = 0,
    Square = 1,//正方形
    Four,//四点,条形
    Seven,//7形状
    SevenReverse,//反7
    Z,//Z形
    ZReverse,//反Z
    Convex,//凸形
    RegularNum = Convex,
    Cross, //十字
//    One,//一点,用于吃掉遇到的第一个value
    //Two,//两点
    Three,//三点
    Five,//五点
    BoxNum = Five,
//    Bomb_one,//一个点炸弹
};

enum class ClockDirection
{
    ClockWise,
    AntiClock,
};

}
#endif//DEFINE_H
