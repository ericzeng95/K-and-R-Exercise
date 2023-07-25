// structures exercise
#include <stdio.h>
#define min(a,b) ((a)<(b) ? (a): (b))
#define max(a,b) ((a)>(b) ? (a): (b))

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct point pt = {320, 200};

/* make a point from x and y components */
struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

int pintersect(struct point p, struct rect r) {
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

int main() {
    struct point pt = makepoint(100, 100);
    printf("%d, %d\n", pt.x, pt.y);

    double dist, sqrt(double);
    dist = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
    printf("Distance: %f\n", dist);

    struct rect screen;
    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(200, 200);

	// pointer example
	struct point origin, *pp;
	origin.x = 100;
	origin.y = 200;
	
	pp = &origin;
	printf("Origin is (%d, %d)\n", (*pp).x, (*pp).y);

	// alternative way of using pointer to struct accessing members
	printf("Origin with -> is (%d, %d)\n", pp->x, pp->y);

	
}
