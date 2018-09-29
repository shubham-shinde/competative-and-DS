#include<stdio.h>

void trypointer(int** x) {
  printf("%d\n",**x);
  printf("%d\n",*x);
  printf("%d\n",x);
}

 int main() {
   int i,*p;
   char z,*y;
   i=10;
   p=&i;
   z='y';
   y=&z;
   trypointer(&p);
   return 0;
 }
