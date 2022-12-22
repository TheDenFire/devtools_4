#include <stdio.h>
#include <math.h>

//task1
enum os{
    symbian = 1,
    embedded = 2,
    windows = 3,
    vxworks = 4,
    qnx = 5
} a;

//task2
struct rad {
    int x1,x0,y1,y0;
} q;
double radius(){
    return sqrt((q.x1-q.x0)*(q.x1-q.x0)+(q.y1-q.y0)*(q.y1-q.y0));
}

//task3
static union{
    struct{
        unsigned NumLock:1, CapsLock:1, ScrollLock:1;
    }t;
    int type;
}f;

int main() {
    //task1
    a = 1;
    switch(a)
    {
        case symbian:
            printf("Symbian\n");
            break;
        case embedded:
            printf("Embedded Linux\n");
            break;
        case windows:
            printf("Windiws CE\n");
            break;
        case vxworks:
            printf("VxWorks\n");
            break;
        case qnx:
            printf("QNX\n");
            break;
    }

    //task2
    q.x1 = 1;
    q.x0 = 2;
    q.y1 = 4;
    q.y0 = 5;
    printf("%lf\n", radius());

    //task3
    f.type = 101;
    printf("CapsLock: %u\nScrollLock: %u\nNumLock: %u",f.t.CapsLock, f.t.ScrollLock, f.t.NumLock );
    return 0;
}