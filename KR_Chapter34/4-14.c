/* E-4-14. define a macro swap(t,x,y) that interchanges two */
/* arguments of type t */

#include <stdio.h>
#include <math.h>
#define swap(t,x,y) t temp; temp = x; x = y; y = temp;

int main(){
	double a, b;
	a = 2.0;
	b = 3.0;
	printf("%f\n", pow(a, b));
	swap(double, a, b);
	printf("%f\n", pow(a, b));
}
