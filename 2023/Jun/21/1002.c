#include <stdio.h>
#include <math.h>

int main() {
	int T;
	double d;
	int res[10000];
	int rb, rs;
	
	scanf("%d", &T);
	
	int x1, y1, r1, x2, y2, r2;
	
	for (int i = 0; i < T; i++){
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
		if(r1 >= r2) {
			rb = r1;
			rs = r2;
		} else {
			rb = r2;
			rs = r1;
		}
		
		if(x1 == x2 && y1 == y2 && rb == rs) {
            if(rb == 0) res[i] = 1;
			else res[i] = -1;
		} else if(rb + rs > d && rb - rs < d) {
			res[i] = 2;
		} else if(rb + rs < d || rb - rs > d) {
			res[i] = 0;
		} else if(rb + rs == d || rb - rs == d) {
			res[i] = 1;
		}
	}
	
	for (int i = 0; i < T; i++) {
		printf("%d\n", res[i]);
	}
}