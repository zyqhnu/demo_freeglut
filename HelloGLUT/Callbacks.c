//#include <iostream>
//#include <D:/freeglut-MSVC-3.0.0-2.mp/freeglut/include/GL/freeglut.h>//freeGLUT���ڿ�
//
///**
// * ��Ⱦ�ص�����
// */
//void RenderScenceCB()
//{
//    // �����ɫ����
//    glClear(GL_COLOR_BUFFER_BIT);
//    // ����ǰ�󻺴�
//    glutSwapBuffers();
//}
//
///**
// * ������
// */
//int main(int argc, char ** argv)
//{
//
//    // ��ʼ��GLUT
//    glutInit(&argc, argv);
//
//    // ��ʾģʽ��˫���塢RGBA
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//
//    // ��������
//    glutInitWindowSize(480, 320);      // ���ڳߴ�
//    glutInitWindowPosition(100, 100);  // ����λ��
//    glutCreateWindow("Tutorial 01");   // ���ڱ���
//
//    // ��ʼ��Ⱦ
//    glutDisplayFunc(RenderScenceCB);
//
//    // ������պ����ɫֵ
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//
//    // ֪ͨ��ʼGLUT���ڲ�ѭ��
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
