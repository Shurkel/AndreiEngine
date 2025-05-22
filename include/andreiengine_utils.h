#ifndef ANDREIENGINE_UTILS_H
#define ANDREIENGINE_UTILS_H
#define PI 3.14159265358979323846
#include <Windows.h>
#include <fstream>



struct Point3d {
    double x;
    double y;
    double z;
};

struct Point2d {
    double x;
    double y;
};

struct Cube {
    Point3d corner[8];
};

struct Camera {
    Point3d position;
    Point3d angle;
    float fov;
    float speed;

    void moveCamera();
};

struct Screen {
    int width;
    int height;
};


float degToRad(float deg);

float radToDeg(float rad);

Point3d distance3d(Point3d point1, Camera point2);

void roatateCamera(Camera& camera, int angle);

Point2d transformPoint(Point3d point, Camera camera);

void drawPoint(Point2d point);

void drawCube(Cube cube, Camera camera);

void recursivesEinlesen(Cube &cub, int i, std::ifstream &c);

void printCamData(Camera cam);

void printCubeData(Cube cub);

#endif
