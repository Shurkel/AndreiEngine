#include "../include\andreiengine_utils.h"
#include <graphics.h>
#include <math.h>
#include <iostream>
Screen screen;
void Camera::moveCamera()
{
    if (GetAsyncKeyState(0x57)) position.x += speed; // move forward
    if (GetAsyncKeyState(0x53)) position.x -= speed; // move backward
    if (GetAsyncKeyState(0x41)) position.y -= speed; // move left
    if (GetAsyncKeyState(0x44)) position.y += speed; // move right
    if (GetAsyncKeyState(0x45)) position.z += speed; // move up
    if (GetAsyncKeyState(0x51)) position.z -= speed; // move down
}


float degToRad(float deg) {
    return deg * PI / 180;
}

float radToDeg(float rad) {
    return rad * 180 / PI;
}

Point3d distance3d(Point3d point1, Camera point2) {
    Point3d result;
    result.x = point1.x - point2.position.x;
    result.y = point1.y - point2.position.y;
    result.z = point1.z - point2.position.z;
    return result;
}

Point2d transformPoint(Point3d point, Camera camera)
{
    Point2d result;

    float dinstancex = distance3d(point, camera).x;
    float par, parPoint, parRat;
    if(dinstancex>=0)
    {
        par = dinstancex / (1 / tan(degToRad(camera.fov / 2)));
        //distance between fov and camera axis
        parPoint = distance3d(point, camera).y;
        //distance between point and camera axis
        parRat = parPoint / par;
        //ratio

        float parPointY = distance3d(point, camera).z;
        float parRatY = parPointY / par;

        result.x = parRat * screen.height / 2;
        result.y = -parRatY * screen.width / 2;
    }
    return result;
}

void drawPoint(Point2d point)
{
    circle(point.x + screen.width / 2, point.y + screen.height / 2, 5);
}

void drawCube(Cube cube, Camera camera)
{
    line(transformPoint(cube.corner[0], camera).x + screen.width / 2, transformPoint(cube.corner[0], camera).y + screen.height / 2, transformPoint(cube.corner[1], camera).x + screen.width / 2, transformPoint(cube.corner[1], camera).y + screen.height / 2);
    line(transformPoint(cube.corner[1], camera).x + screen.width / 2, transformPoint(cube.corner[1], camera).y + screen.height / 2, transformPoint(cube.corner[2], camera).x + screen.width / 2, transformPoint(cube.corner[2], camera).y + screen.height / 2);
    line(transformPoint(cube.corner[2], camera).x + screen.width / 2, transformPoint(cube.corner[2], camera).y + screen.height / 2, transformPoint(cube.corner[3], camera).x + screen.width / 2, transformPoint(cube.corner[3], camera).y + screen.height / 2);
    line(transformPoint(cube.corner[3], camera).x + screen.width / 2, transformPoint(cube.corner[3], camera).y + screen.height / 2, transformPoint(cube.corner[0], camera).x + screen.width / 2, transformPoint(cube.corner[0], camera).y + screen.height / 2);
    line(transformPoint(cube.corner[4], camera).x + screen.width / 2, transformPoint(cube.corner[4], camera).y + screen.height / 2, transformPoint(cube.corner[5], camera).x + screen.width / 2, transformPoint(cube.corner[5], camera).y + screen.height / 2);
    line(transformPoint(cube.corner[5], camera).x + screen.width / 2, transformPoint(cube.corner[5], camera).y + screen.height / 2, transformPoint(cube.corner[6], camera).x + screen.width / 2, transformPoint(cube.corner[6], camera).y + screen.height / 2);
    line(transformPoint(cube.corner[6], camera).x + screen.width / 2, transformPoint(cube.corner[6], camera).y + screen.height / 2, transformPoint(cube.corner[7], camera).x + screen.width / 2, transformPoint(cube.corner[7], camera).y + screen.height / 2);
    line(transformPoint(cube.corner[7], camera).x + screen.width / 2, transformPoint(cube.corner[7], camera).y + screen.height / 2, transformPoint(cube.corner[4], camera).x + screen.width / 2, transformPoint(cube.corner[4], camera).y + screen.height / 2);
    line(transformPoint(cube.corner[0], camera).x + screen.width / 2, transformPoint(cube.corner[0], camera).y + screen.height / 2, transformPoint(cube.corner[4], camera).x + screen.width / 2, transformPoint(cube.corner[4], camera).y + screen.height / 2);
    line(transformPoint(cube.corner[1], camera).x + screen.width / 2, transformPoint(cube.corner[1], camera).y + screen.height / 2, transformPoint(cube.corner[5], camera).x + screen.width / 2, transformPoint(cube.corner[5], camera).y + screen.height / 2);
    line(transformPoint(cube.corner[2], camera).x + screen.width / 2, transformPoint(cube.corner[2], camera).y + screen.height / 2, transformPoint(cube.corner[6], camera).x + screen.width / 2, transformPoint(cube.corner[6], camera).y + screen.height / 2);
    line(transformPoint(cube.corner[3], camera).x + screen.width / 2, transformPoint(cube.corner[3], camera).y + screen.height / 2, transformPoint(cube.corner[7], camera).x + screen.width / 2, transformPoint(cube.corner[7], camera).y + screen.height / 2);

}

void recursivesEinlesen(Cube &cub, int i, std::ifstream &c)
{
    if(i < 8)
    {
        c>>cub.corner[i].x>>cub.corner[i].y>>cub.corner[i].z;
        recursivesEinlesen(cub, i+1, c);
    }
}

void printCamData(Camera cam)
{
    std::cout << "Camera position: " << cam.position.x << " " << cam.position.y << " " << cam.position.z << '\n';
    std::cout << "Camera angle: " << cam.angle.x << " " << cam.angle.y << " " << cam.angle.z << '\n';
    std::cout << "Camera fov: " << cam.fov << '\n';;
    std::cout << "Camera speed: " << cam.speed << '\n';
}

void printCubeData(Cube cub)
{
    for (int i = 0; i < 8; i++)
    {
        std::cout << "Corner " << i << ": " << cub.corner[i].x << " " << cub.corner[i].y << " " << cub.corner[i].z << '\n';
    }
}



