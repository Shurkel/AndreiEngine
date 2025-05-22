#include <graphics.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include "andreiengine_utils.cpp"
using namespace std;


Point3d arr[100];
void createCoolShape(int sizez) {
    double radius = 5.0;
    double height = 10.0;
    double angleIncrement = 3 * PI / sizez;

    for (int i = 0; i < sizez; i++) {
        double angle = i * angleIncrement;
        arr[i].x = radius * cos(angle);
        arr[i].y = height * sin(5 * angle);
        arr[i].z = height * sin(5.5 * angle);
    }
}

int main()
{

    Camera cam1;
    Cube cub1;

    ifstream f("../presets/preset1.in");
    ifstream c("../presets/cube1.in");

    f>>cam1.position.x>>cam1.position.y>>cam1.position.z;
    f>>cam1.angle.x>>cam1.angle.y>>cam1.angle.z;
    f>>cam1.fov;
    f>>cam1.speed;

    f>>screen.height>>screen.width;

    recursivesEinlesen(cub1, 0, c);

    printCamData(cam1);
    printCubeData(cub1);

    initwindow(screen.height, screen.width);


    getch();
    int page = 0;
     while (!GetAsyncKeyState(VK_ESCAPE))
    {
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();

        drawCube(cub1, cam1);
        //createCoolShape(100);
        for (int i = 0; i < 100; i++) {
            line(screen.width / 2 + transformPoint(arr[i], cam1).x, screen.height / 2 + transformPoint(arr[i], cam1).y, screen.width / 2 + transformPoint(arr[(i + 1) % 100], cam1).x, screen.height / 2 + transformPoint(arr[(i + 1) % 100], cam1).y);
            drawPoint(transformPoint(arr[i], cam1));
        }
        cam1.moveCamera();

        

        page = 1 - page;
    }
    getch();
    return 0;
}

