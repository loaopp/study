This is an H1
=============

---

This is an H2
-------------

---

# This is a H1
## This is a H2
### This is a H3
#### This is a H4
##### This is a H5
###### This is a H6

---

> This is a first blockqute.
>	> This is a second blockqute.
>	>	> This is a third blockqute.

---

1. 첫번째
2. 두번째
3. 세번째

---

* 빨강
  * 녹색
    * 파랑

+ 빨강
  + 녹색
    + 파랑

- 빨강
  - 녹색
    - 파랑

---

* 1단계
  - 2단계
    + 3단계
      + 4단계

---

This is a normal paragraph:

    This is a code block.

end code block.

---

```
public class BootSpringBootApplication {
  public static void main(String[] args) {
    System.out.println("Hello, Honeymon");
  }
}
```

---

* * *

***

*****

- - -

---------------------------------------

### 참조링크
	[link keyword][id]

	[id]: URL "Optional Title here"
	// code
Link: [Google][googlelink]

[googlelink]: https://google.com "Go google"

### 외부링크
	사용문법: [Title](link)
적용예: [Google](https://google.com, "google link")

### 자동링크
	일반적인 URL 혹은 이메일주소인 경우 적절한 형식으로 링크를 형성한다.

* 외부링크: <http://www.naver.com/>
* 이메일링크: <address@example.com>

---

### 강조

*single asterisks*

_single underscores_

**double asterisks**

__double underscores__

~~cancelline~~

~~___TEST ABCMAN 123___~~

~~__TEST ABCMAN 123__~~

~~_TEST ABCMAN 123_~~

---

### 이미지
	![Alt text](/path/to/img.jpg)
	![Alt text](/path/to/img.jpg "Optional title")

사이즈 조절 기능은 없기 때문에 <img width="" height=""></img>를 이용한다.

	<img src="/path/to/img.jpg" width="450px" height="300px" title="px(픽셀) 크기 설정" alt="RubberDuck"></img><br/>
	<img src="/path/to/img.jpg" width="40%" height="30%" title="px(픽셀) 크기 설정" alt="RubberDuck"></img>

### 줄바꿈
3칸 이상 띄어쓰기( )를 하면 줄이 바뀐다.

	* 줄 바꿈을 하기 위해서는 문장 마지막에서 3칸이상을 띄어쓰기해야 한다.
	이렇게

	* 줄 바꿈을 하기 위해서는 문장 마지막에서 3칸이상을 띄어쓰기해야 한다.___\\ 띄어쓰기
	이렇게

