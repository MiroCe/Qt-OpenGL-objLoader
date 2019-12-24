#include "widget.h"

static const float vertex_list[][3] =
{
    {-1.0f, 1.0f, 0.0f},
    {1.0f, 1.0f, 0.0f},
    {-1.0f, -1.0f, 0.0f},
    {1.0f, -1.0f, 0.0f},
    {-1.0f, 1.0f, 1.0f},
    {1.0f, 1.0f, 1.0f},
    {-1.0f, -1.0f, 1.0f},
    {1.0f, -1.0f, 1.0f}
};

static const GLint index_list[][2] =
{
    {0, 1},{2, 3},{4, 5},{6, 7},
    {0, 2},{1, 3},{4, 6},{5, 7},
    {0, 4},{1, 5},{7, 3},{2, 6}
};

void DrawCube(void)
{
    int i,j;
    glBegin(GL_POLYGON);
    for(i=0; i<12; ++i) // 12条线段
        for(j=0; j<2; ++j) // 每条线段2个顶点
            glVertex3fv(vertex_list[index_list[i][j]]);
    glEnd();
}

void Draw_rod(GLfloat x,GLfloat y,GLfloat z){
    // fishing rod
    glPushMatrix();
    glTranslatef(2.0f, -5.0f, -1.5f);
    glRotatef(-30.0f,1,0,0);
    glScalef(x,y,z); //10.0f, 0.01f, 0.01f
    glColor3f(0.30f, 0.130f, 0.13f);
    DrawCube();
    glPopMatrix();
}

void Draw_line(GLfloat x,GLfloat y,GLfloat z){
    // fishing thread
    glPushMatrix();

    glTranslatef(2.0f, 10.0f, 24.48f);
    glScalef(x,y,z); //10.0f, 0.01f, 0.01f
    glRotatef(90.0f,1,0,0);
    glColor3f(0.50f, 0.9f, 0.9f);
    DrawCube();

    glPopMatrix();
}

void Draw_hook(GLfloat x,GLfloat y,GLfloat z){
    // fishing hook
    glPushMatrix();
    glTranslatef(2.0f, -40.0f, 24.48f);
    glScalef(x,y,z); //10.0f, 0.01f, 0.01f
    glColor3f(0.85f, 0.64f, 0.12f);
    DrawCube();
    glPopMatrix();
}




MyGLWidget::MyGLWidget(QWidget *parent)
    :QGLWidget(parent)
{
}


MyGLWidget::~MyGLWidget()
{
}



void MyGLWidget::initializeGL()
{
    glViewport(0, 0, width(), height());
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glDisable(GL_DEPTH_TEST);

    if(Boat.Load("/boat.obj", 1)==0){
        printf("load boat successfully");
    }
    else{
        printf("load boat fail");
        flag = 0;
    }

    if(Workerman.Load("/workermanOBJ.obj",1)==0){
        printf("load man successfully");
    }
    else{
        printf("load man fail");
        flag = 0;
    }

    if(Fish1.Load("/Golden_Fish_OBJ.obj", 1)==0){
        printf("load fish successfully");
    }
    else{
        printf("load fish fail");
        flag = 0;
    }

}




void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 100.0f, 0.0f, 100.0f, -100.0f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glTranslatef(50.0f, 50.0f, 0.0f);

    // overlook
    glTranslatef(50.0f, 75.0f, 0.0f);
    glRotatef(20, 1, 0, 0);
    glRotatef(-70.0f, 0, 1, 0);

    // draw
    if (flag == 1){

        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
        glTranslatef(0.0f,-16.0f,0.0f);
        glScalef(1.0f,1.0f,0.5f);
        Boat.Draw(1);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);

        glPushMatrix();
        glTranslatef(0.0f,0.0f,-3.0f);
        Workerman.Draw(1);
        glPopMatrix();

        Draw_rod(0.1f, 0.1f, 30.0f);
        Draw_line(0.05f, 50.0f, 0.05f);
        Draw_hook(0.2f,0.3f,0.2f);

        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
        glTranslatef(-50.0f,-70.0f,0.0f);
        glRotatef(60.0f,0,1,0);
        glScalef(0.01f,0.01f,0.01f);
        Fish1.Draw(1);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0f,-60.0f,0.0f);
        glRotatef(60.0f,0,1,0);
        glScalef(0.01f,0.01f,0.01f);
        Fish1.Draw(2);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(60.0f,-20.0f,0.0f);
        glRotatef(60.0f,0,1,0);
        glScalef(0.01f,0.01f,0.01f);
        Fish1.Draw(3);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);

    }

}



void MyGLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
    update();
}

