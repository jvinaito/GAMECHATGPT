#include <graphics.h>
#include <conio.h>

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TC\\BGI");
  int x1 = 100, y1 = 100;
  int x2 = 200, y2 = 100;
  int x3 = 200, y3 = 200;
  int x4 = 100, y4 = 200;
  int x5 = 150, y5 = 50;
  int x6 = 250, y6 = 50;
  int x7 = 250, y7 = 150;
  int x8 = 150, y8 = 150;
  //hinh vuong dau tien
  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x4, y4);
  line(x4, y4, x1, y1);
  //mat sau
  line(x5, y5, x6, y6);
  line(x6, y6, x7, y7);
  line(x7, y7, x8, y8);
  line(x8, y8, x5, y5);
  //noi dinh
  line(x1, y1, x5, y5);
  line(x2, y2, x6, y6);
  line(x3, y3, x7, y7);
  line(x4, y4, x8, y8);
 setfillstyle(SOLID_FILL, GREEN); // Ð?t ki?u tô d?c và màu xanh
floodfill(0, 0, WHITE); 
  getch();
  closegraph();
  return 0;
  
}

