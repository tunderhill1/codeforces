#include <stdio.h>
#include <stdlib.h> 

int main()
{
    char input_str[3];
    scanf("%s", input_str);
    int input_int = atoi(input_str);
    
    if (input_int % 2 == 0 && input_int > 2) {
      printf("YES");
    } else {
      printf("NO");
    }
    return 0;
}