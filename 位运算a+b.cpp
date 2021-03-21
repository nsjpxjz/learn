#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int num1,num2;
    scanf("%d%d",&num1,&num2);
    while(num2 != 0) {
         int temp = num1^num2;
         num2 = (num1&num2) << 1;
         num1 = temp;
    }
    printf("%d",num1);
    return 0;
}