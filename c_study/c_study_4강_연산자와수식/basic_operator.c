/* 덧셈,뺄셈,곱셈,나눗셈,나머지에 대해 알아보자.*/

/*정수 덧셈 : 더한 값을 저장하지않고 바로 출력할 수도 있고 더한 값을 변수에 저장할 수도 있다. 물론 정수와 실수의 덧셈은
            실수형 자료형에 저장해야 한다.*/
//덧셈, 뺄셈, 곱셈 다 방식 같다.            
#include <stdio.h>

int main()
{
    int a = 1;
    int b = 10;
    float c = 1.3f;
    float d = 10.5f;

    printf("a + b = %d\n",a+b);
    printf("a - b = %d\n",a-b);
    printf("c + d = %.3f\n",c+d);
    printf("c - d = %.3f\n",c-d);
    printf("a + d = %f\n",a+d);
    printf("a - d = %f\n",a-d);
    /* 나눗셈은 /기호를 사용하며 일반적으로 정수와 정수끼리 나눗셈을 하면 몫이 결과가 되며, 나머지 값은 버려진다. 그러나 실수 끼리
        나눗셈을 하면 정상적으로 나머지값까지 저장된다.*/
    printf("a / b = %d\n",a/b);
    printf("c / d = %.3f\n",c/d);
    printf("a / d = %f\n",a/d);    
    /* 나머지 연산은 % 기호를 사용하며, 나누고 남은 숫자이며, 정수와 정수끼리만 가능하다.*/
    printf("a %% b = %d\n",a%b);
    return 0;
}