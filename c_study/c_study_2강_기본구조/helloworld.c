/*이게 주석*/
//이렇게도 된다.
//앞으로 주석은 코드 위에 설명하겠다.
// C언어의 기본 구조
/*무엇을 하든 이 구조를 작성하고 시작한다*/

// #은 전 처리기. 컴파일 하기전에 미리 처리해라는 명령어. 전처리기는 세미콜론을 붙이지 않는다.
/* stdio.h 는 헤더파일이고 헤더파일은 'h'확장자를 가지는 파일을 헤더파일 이라고 부른다.
    헤더 파일은 이미 만들어져 있는 함수가 어떤게 있는지 정리한 목차 라고 생각하면 된다.
    컴퓨터는 헤더파일을 보면서 이 함수가 존재하는지 판단하고 기능을 가져올 수 있다. 그 중에서
    stdio.h(STandDard Input Output)는 표준 입출력 헤더파일이라고 하며, stdio.h 를 추가하면
    입출력, 반복문, 조건문 등을 사용 할 수 있도록 해준다.*/
#include <stdio.h>

// C언어의 가장 기본적인 함수. 실행버튼을 누르면 main함수 안에 있는 코드가 제일 먼저 실행된다.
int main()
{
    printf("Hello, World!");
    // 함수가 종료되었을 때 함수 내의 변수 혹은 어떤 값을 돌려주는 역할.
    // int main()을 썼다면 return 0; 을 매번 쓰도록 권장한다.
    // ; 세미콜론은 마침을 의미. 잊지 말고 코드 끝에는 세미콜론을 붙이자.
    return 0;
}

/* 지금 컴파일 아는 단계는 gcc -o hello helloworld.c
    그 다음 실행하는 것이 해당 폴더라면, ./hello  */