#include "GLUT.h"

#include <Windows.h>
#include <math.h>
#include <stdio.h>

int xStart, yStart, xEnd, yEnd;

static void drawPoints();

long long int round(const float &a) 
{
  long long int result;

  if (a - floor(a) >= 0.5)
    result = floor(a) + 1;
  else
    result = floor(a);

  return result;
}

void draw_pixel(const int &x, const int &y, const float color[],
                const float &width)
{
  glPointSize(width);
  glBegin(GL_POINTS);
  glColor3f(color[0], color[1], color[2]);
  glVertex2d(x, y);
  glEnd();
}

void DDAalgorithm() 
{
  float color[3];

  color[0] = 1.0;
  color[1] = 0.0;
  color[2] = 0.0;

  float point_size = 10.0;
  int dx = xEnd - xStart;
  int dy = yEnd - yStart;
  int steps = dx;

  if (abs(dy) > abs(dx))
    steps = dy;

  // first point
  double x = 1.0 * xStart,
         y = 1.0 * yStart; // Convert to double

  const auto inc_x = (1.0 * dx) / steps;
  const auto inc_y = (1.0 * dy) / steps;

  draw_pixel(x, y, color, point_size);

  for (int i = 1; i <= steps; i++) 
  {
    x += inc_x;
    y += inc_y;

    draw_pixel(round(x), round(y), color, point_size);
  }
}

void Bresenham() 
{
  int dx, dy, i, e, incx, incy, inc1, inc2, x, y;

  float color[3], point_size = 10.0;

  color[0] = 0.0;
  color[1] = 0.0;
  color[2] = 0.0;

  dx = xEnd - xStart;
  dy = yEnd - yStart;

  if (dx < 0)
    dx = -dx;

  if (dy < 0)
    dy = -dy;

  incx = 1;

  if (xEnd < xStart)
    incx = -1;

  incy = 1;

  if (yEnd < yStart)
    incy = -1;

  x = xStart;
  y = yStart;

  if (dx > dy) 
  {
    draw_pixel(x, y, color, point_size);

    e = 2 * dy - dx;
    inc1 = 2 * (dy - dx);
    inc2 = 2 * dy;

    for (i = 0; i < dx; i++) 
    {

      if (e >= 0) 
      {
        y += incy;
        e += inc1;
      } 
      else
        e += inc2;

      x += incx;
      draw_pixel(x, y, color, point_size);
    }
  } 
  else 
  {
    draw_pixel(x, y, color, point_size);

    e = 2 * dx - dy;
    inc1 = 2 * (dx - dy);
    inc2 = 2 * dx;

    for (i = 0; i < dy; i++) 
    {
      if (e >= 0) 
      {
        x += incx;
        e += inc1;
      }
      else
        e += inc2;

      y += incy;
      draw_pixel(x, y, color, point_size);
    }
  }
}

void drawLine() 
{
  printf("Enter (xStart, yStart, xEnd, yEnd)\n");
  scanf_s("%d %d %d %d", &xStart, &yStart, &xEnd, &yEnd);

  DDAalgorithm();
  glFlush();

  printf("Enter (xStart, yStart, xEnd, yEnd)\n");
  scanf_s("%d %d %d %d", &xStart, &yStart, &xEnd, &yEnd);

  Bresenham();
  glFlush();

}

void myInit() {

  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-500, 500, -500, 500);
}

void main(int argc, char **argv) {
  // Initialization
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  // Window POsition
  glutInitWindowPosition(100, 100);
  // Window Size
  glutInitWindowSize(600, 600);
  glutCreateWindow("Drawing Points");
  myInit();
  // Draw Function
  // glutDisplayFunc(drawPoints);
  glutDisplayFunc(drawLine);
  glutMainLoop();
}

void drawPoints() {
  /*
   change to LINES or LINE_LOOP or LINE_STRIP
  */
  glPointSize(10.0);
  glBegin(GL_POINTS);
  // point1
  glColor3f(1.0, 0.0, 0.0);
  glVertex2d(0, 0);
  // point2
  glColor3f(0.0, 1.0, 0.0);
  glVertex2d(0, 200);
  // point3
  glColor3f(0.0, 0.0, 1.0);
  glVertex2d(100, 0);
  // point4
  glColor3f(1.0, 0.5, 0.0);
  glVertex2d(100, 200);
  glEnd();
  glFlush();
}