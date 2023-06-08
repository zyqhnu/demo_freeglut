//#include <iostream>
//#include <D:/freeglut-MSVC-3.0.0-2.mp/freeglut/include/GL/freeglut.h>//freeGLUT窗口库
//
///**
// * 渲染回调函数
// */
//void RenderScenceCB()
//{
//    // 清空颜色缓存
//    glClear(GL_COLOR_BUFFER_BIT);
//    // 交换前后缓存
//    glutSwapBuffers();
//}
//
///**
// * 主函数
// */
//int main(int argc, char ** argv)
//{
//
//    // 初始化GLUT
//    glutInit(&argc, argv);
//
//    // 显示模式：双缓冲、RGBA
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//
//    // 窗口设置
//    glutInitWindowSize(480, 320);      // 窗口尺寸
//    glutInitWindowPosition(100, 100);  // 窗口位置
//    glutCreateWindow("Tutorial 01");   // 窗口标题
//
//    // 开始渲染
//    glutDisplayFunc(RenderScenceCB);
//
//    // 缓存清空后的颜色值
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//    // 通知开始GLUT的内部循环
//    glutMainLoop();
//
//    return 0;
//}


#include <stdlib.h>
#include <GL/glut.h>
#include "Callbacks.h"

/* Keyboard callback function */
void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
    /* Exit on escape key press */
    case '\x1B':
    {
      exit(EXIT_SUCCESS);
      break;
    }
  }
}

/* Display callback function */
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);

  /* Display a red square */
  glColor3f(1.0f, 0.0f, 0.0f);

  glBegin(GL_POLYGON);
    glVertex2f(-0.7f, -0.5f);
    glVertex2f( 0.5f, -0.5f);
    glVertex2f( 0.5f,  0.5f);
    glVertex2f(-0.5f,  0.5f);
  glEnd();

  glFlush();
}
