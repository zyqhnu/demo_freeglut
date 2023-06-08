//#include <iostream>
//#include <GL/glut.h>
//#include <GL/freeglut.h>//freeGLUT���ڿ�
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
//    glClearColor(1.0f, 0.5f, 0.0f, 0.0f);
//
//    // ֪ͨ��ʼGLUT���ڲ�ѭ��
//    glutMainLoop();
//
//    return 0;
//}


#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include <glm/>


void processInput(GLFWwindow* window);


//ģ�Ͷ�������
float vertices[] = {
    0.5f, 0.5f, 0.0f,   /* Postion ���Ͻ�  Color*/  1.0f, 0.0f, 0.0f,
    0.5f, -0.5f, 0.0f,  /* ���½� */			    0.0f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.0f, /* ���½� */			    0.0f, 0.0f, 1.0f,
    -0.5f, 0.5f, 0.0f,  /* ���Ͻ�*/					1.0f, 0.0f, 1.0f,
};


unsigned int indices[] = { // ע��������0��ʼ! 
    0, 1, 3, // ��һ��������
    1, 2, 3  // �ڶ���������
};

const char* vertexShaderSource =
"#version 330 core                                \n		"
"layout(location = 0) in vec3 aPos;              \n			"
"layout(location = 1) in vec3 aColor;              \n			"
"out vec4 vertexColor;                                      \n"
"void main(){\n												"
"		gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n	"
"		vertexColor = vec4(aColor.x,aColor.y,aColor.z,1.0);}\n					";

const char* fragmentShaderSource =
"#version 330 core                             \n	"
"in vec4 vertexColor; \n"
"out vec4 FragColor;                           \n	"
"void main(){\n										"
"		FragColor = vertexColor;}\n";

int main(int argc, char* argv[])
{


    glfwInit();
    //����opengl�汾3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//����glfw��Ҫ�汾3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//����glfw��Ҫ�汾3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//����glfwʹ��core-profile

    GLFWwindow* window = glfwCreateWindow(800, 600, "Test window", NULL, NULL);

    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();//���ٴ��ڣ��ͷ���Դ
        //return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);//ָ���߳�

    glewExperimental = true;

    if (glewInit() != GLEW_OK)//��ʼglew����
    {
        std::cout << "glew init failed." << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }
    //�����ӿ��ӽ�
    glViewport(0, 0, 800, 600);
    /*
    //����ģʽ Wireframe Mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //�޳�����α���
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_FRONT);//GL_BACK:�޳����� ��GL_FRONT:�޳�����
    */
    //VAO ��Vertex Arrays
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    //VBO
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //EBO
    unsigned int EBO;
    glGenBuffers(1, &EBO);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    //����
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    //link ����
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    while (!glfwWindowShouldClose(window)) {
        //1.input
        //--------
        processInput(window);

        //2.render
        //--------
        //����Ҫ������ɫ��r 0-1.0��g 0-1.0��b 0-1.0����͸����0-1.0��
        glClearColor(0.2f, 0.3f, 0.3f, 0.1f);
        //���colorbuff�Ļ�����
        glClear(GL_COLOR_BUFFER_BIT);
        //--------

        //Draw Triangle
        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        glUseProgram(shaderProgram);
        //glDrawArrays(GL_TRIANGLES, 0, 6);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        //3.swap buffers and Poll IO events
        //-------
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();
    //std::cin.get();
    return 0;
}
//Esc������Ӧ����
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }


}


//#include <GLFW/glfw3.h>
//
//int main(void)
//{
//    GLFWwindow* window;
//
//    /* Initialize the library */
//    if (!glfwInit())
//        return -1;
//
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//    if (!window) {
//        glfwTerminate();
//        return -1;
//    }
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window)) {
//        /* Render here */
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        glBegin(GL_TRIANGLES);
//        glVertex2d(0.5f, 0.5f);
//        glVertex2d(-0.5f, -0.5f);
//        glVertex2d(0.5f, -0.5f);
//
//        glEnd();
//
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//
//        /* Poll for and process events */
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
//}