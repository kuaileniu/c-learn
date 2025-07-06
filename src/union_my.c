#include <stdio.h>
#include <stdlib.h>

// 联合体共占用一个内存，
union MyDate
{
  int i;
  short s
};

union RGBA
{
  int color;

  char rgba[4]; // 4个字节，分别表示红、绿、蓝、透明度
};

void show_union()
{
  printf("MyDate: %d\n", sizeof(union MyDate));
  union MyDate md = {1};

  int hex_val = 0XABCD;
  hex_val = (hex_val & 0XFF00) | 0X00EE; // 保留高8位，替换低8位为EE
}