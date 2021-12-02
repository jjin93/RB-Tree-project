/* 비교 연산자 : 값과 값을 비교하는 연산자. 관계 연산자라고도 한다. 예제를 보며 파악하자.*/
/* C언어 에서는 참이면 1을 거짓이면 0을 반환한다. 또 값을 인식 할때는 0을 거짓으로, 0이외의 값을 참으로 판단한다.*/

#include <stdio.h>

int main()
{
	int number = 5;

	printf("number 는 5와 같습니까? %d\n", number == 5);  // 같으므로 1(참)
	printf("number 는 4와 같습니까? %d\n", number == 4);  // 같지 않으므로 0(거짓)

	printf("number 는 5와 다릅니까? %d\n", number != 5); // 같으므로 0(거짓)
	printf("number 는 4와 다릅니까? %d\n", number != 4); // 같지 않으므로 1(참)

	printf("number 가 4보다 큽니까? %d\n", 4 < number);    // 크므로 1(참)
	printf("number 가 5보다 큽니까? %d\n", 5 < number);    // 크지 않으므로 0(거짓)
	printf("number 가 10보다 큽니까? %d\n", 10 < number);   // 크지 않으므로 0(거짓)

	printf("number 가 10보다 작습니까? %d\n", number < 10); // 작으므로 1(참)
	printf("number 가 5보다 작습니까? %d\n", number < 5);   // 작지 않으므로 0(거짓)
	printf("number 가 4보다 작습니까? %d\n", number < 4);  // 작지 않으므로 0(거짓)

	printf("number 가 5보다 크거나 같습니까? %d\n", 5 <= number); // 크거나 같으므로 1(참)
	printf("number 가 5보다 작거나 같습니까? %d\n", number <= 5); // 작거나 같으므로 1(참)

	return 0;
}