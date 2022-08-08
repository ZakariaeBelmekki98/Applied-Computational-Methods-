#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	double x,y;

} Point;

typedef struct{
	double a,b,c;
} Line;

double distance_point_line(Line *line, Point *point);

int main(){
	Line line;
	line.a=1;
	line.b=1;
	line.c=3;

	Point point;
	point.x=1;
	point.y=1;

	printf("Distance : %f\n", distance_point_line(&line, &point));
	return 0;
}


double distance_point_line(Line *line, Point *point){
	return fabs(line->a * point->x + line->b * point->y - line->c) / sqrt(line->a * line->a + line->b * line->b);
}
