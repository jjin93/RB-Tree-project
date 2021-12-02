/* 논리연산자 : 참과 참, 거짓과 거짓, 참과 거짓 등 논리 연산을 할때 사용하는 논리연산자를 배우자.
            논리곱 연산, 논리합 연산이 존재하고, 기호로는 논리곱은 &&, 논리합은 ||을 의미한다.예제를 보자 */

#include <stdio.h>

int main()
{
  int number = 5;

  printf("AND(논리곱) : number 는 3보다 크다. 그리고 10 보다 작다. : %d\n", 3 < number && number < 10); // 둘 다 참이므로 참(1)을 출력
  printf("AND(논리곱) : number 는 3보다 크다. 그리고 10 보다 크다. : %d\n", 3 < number && 10 < number); // 둘 중 하나만 참이므로 거짓(0)을 출력
  
  printf("OR(논리합) : number 는 5 이거나 4이다. : %d\n", number == 5 || number == 4); // 둘 중 하나라도 참이므로 참(1)을 출력
  printf("OR(논리합) : number 는 6 이거나 7이다. : %d\n", number == 6 || number == 7); // 둘 다 거짓이므로 거짓(0)을 출력
  
  return 0;
}            