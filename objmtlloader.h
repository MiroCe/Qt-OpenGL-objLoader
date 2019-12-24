#ifndef OBJMTLLOADER_H
#define OBJMTLLOADER_H

#include <vector>
#include <QWidget>
#include <QtOpenGL/QtOpenGL>
#include <QtGui>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

struct Point{
    Point(float x, float y, float z){
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
    }
    std::vector<float> v;
};

struct Texture
{
    Texture(float x, float y){
        vt.push_back(x);
        vt.push_back(y);
    }
    std::vector<float> vt;
};

struct Normal
{
    Normal(float x, float y, float z){
        vn.push_back(x);
        vn.push_back(y);
        vn.push_back(z);
    }
    std::vector<float> vn;
};

struct Face
{
    Face(std::vector<int> i1,std::vector<int> i2,std::vector<int> i3,std::vector<int> i4, int id){
        f.push_back(i1);
        f.push_back(i2);
        f.push_back(i3);
        f.push_back(i4);
        MaterialID = id;
    }
    std::vector<std::vector<int>> f;
    int MaterialID;
};

struct Material
{
    Material(int id){
        MaterialID = id;
    }
    float Ns;
    float Tr = 1.0f;
    std::vector<float> Ka;
    std::vector<float> Kd;
    std::vector<float> Ks;
    int illum;

    GLuint map_Kd=0;
    GLuint map_Ka=0;
    GLuint map_Ks=0;
    GLuint map_Bump=0;

    char name[20];
    int MaterialID;
};


class objmtlloader
{
public:
    objmtlloader();

    int Load(char* filename,int loadtype); // 1: x/x/x , 0: x/x
    int LoadMTL(char* filename);
    GLuint LoadBMP(char* filename);
    void Draw(int f_type);  // 1: x/x/x , 0: x/x

private:
    std::vector<Point> V;
    std::vector<Texture> Vt;
    std::vector<Normal> Vn;
    std::vector<Face> F;
    std::vector<Material> M;
    char* filehead = "/Users/l/Documents/QT+CG/assignment3/src";    //model filepath
};

#endif // OBJMTLLOADER_H
