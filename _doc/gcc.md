[참조](https://eoriented.github.io/post/how-to-compile-using-gcc/)

| 옵션 | 의미 | 기타
|:-|:-:|:-:
| -o | 바이너리 형식의 출력 파일 이름을 지정하는데, 지정하지 않으면 a.out라는 기본 이름이 적용된다.
| -c | 소스 파일을 컴파일만 하고 링크를 수행하지 않으며, 오브젝트 파일을 생성한다.
| -C | ex)make all -C ./libft/ (libft 폴더 내에서 make all을 실행한다)
| -I | 헤더파일 경로. 옵션뒤에 경로를 붙여서 사용 |-I./lib(o) -I ./lib(x)
| -E | 전처리를 실행하고 컴파일을 중단하게 한다.|
| -L | 라이브러리 파일을 검색하는 디렉토리 목록을 추가한다.
| -l | 라이브러리 파일을 컴파일 시 링크한다.	| libMylib.a 를 사용시 -l*Mylib* 로 써야함.
| -g | 바이너리 파일에 표준 디버깅 정보를 포함시킨다.
| -ggdb | 바이너리 파일에 GNU 디버거인 gdb만이 이해할 수 있는 많은 디버깅 정보를 포함시킨다.
| -O | 컴파일 코드를 최적화시킨다.
| -ON | 최적화 N 단계를 지정한다.
| -DFOO=RAR | 명령라인에서 BAR의 값을 가지는 FOO라는 선행 처리기 매크로를 정의한다.
| -static | 정적 라이브러리에 링크한다.
| -ansi | 표준과 충돌하는 GNU 확장안을 취소하며, ANSI/ISO C 표준을 지원한다. 이 옵션은 ANSI 호환 코드를 보장하지 않는다.
| -traditional | 과서 스타일의 함수 정의 형식과 같이 전통적인 K&R(Kernighan and Ritchie) C 언어 형식을 지원한다.
| -MM | make 호환의 의존성 목록을 출력한다.
| -V | 컴파일의 각 단계에서 사용되는 명령어를 보여준다.
| __-fPIC__ | 동적 라이브러리 옵션
| __-shared__ | 오브젝트 파일을 .so 파일로 묶어 준다
