■ IP주소란?
■ 넷마스크란?
■ 넷마스크를 사용하는 IP의 서브넷은 무엇입니까?
■ 서브넷의 브로드캐스트 주소는 무엇입니까?
■ 넷마스크로 IP 주소를 표시하는 다양한 방법은 무엇입니까?
■ 공용 IP와 개인 IP의 차이점은 무엇입니까?

RFC1918 name	IP address range				Largest CIDR block (subnet mask)
24-bit block	10.0.0.0 – 10.255.255.255		10.0.0.0/8 (255.0.0.0)
20-bit block	172.16.0.0 – 172.31.255.255		172.16.0.0/12 (255.240.0.0)
16-bit block	192.168.0.0 – 192.168.255.255	192.168.0.0/16 (255.255.0.0)

■ IP주소란?
■ TCP란?
■ UDP란?
■ 네트워크 계층은 무엇입니까?
■ OSI 모델은 무엇입니까?
■ DHCP 서버와 DHCP 프로토콜이란?
■ DNS 서버와 DNS 프로토콜이란?
■ IP 주소를 사용하여 2개의 기기를 통신하는 규칙은 무엇입니까?
■ IP로 라우팅 작동 방식
■ 라우팅의 기본 게이트웨이는 무엇입니까?
■ IP 관점에서 포트란 무엇이며 다른 장치에 연결할 때 사용되는 포트

◦ What is an IP address
◦ What is a Netmask
◦ What is the subnet of an IP with Netmask
◦ What is the broadcast address of a subnet
◦ What are the different ways to represent an ip address with the Netmask
◦ What are the differences between public and private IPs
◦ What is a class of IP addresses
◦ What is TCP
◦ What is UDP
◦ What are the network layers
◦ What is the OSI model
◦ What is a DHCP server and the DHCP protocol
◦ What is a DNS server and the DNS protocol
◦ What are the rules to make 2 devices communicate using IP addresses
◦ How does routing work with IP
◦ What is a default gateway for routing
◦ What is a port from an IP point of view and what is it used for when connecting to another device


# What is an IP address

### IP : Internet Protocol

- 어떤 컴퓨터의 위치를 특정해주는 '컴퓨터의 주소'

    **Protocol** : 컴퓨터나 네트워크 장비가 서로 통신하기 위해 미리 정해놓은 약속, 규약

### IPv4 와 IPv6

- **IPv4**
    - 기존의 IPv4의 경우 12자리의 10진수 숫자 배열로 IP주소를 만듬
    - 123.456.789.137 의 형태
    - 43억개에 달하는 경우의 수가 만들어짐
    - 점으로 구분된 숫자들은 **옥텟(Octet)** 이라고 부름
    - 8비트의 2진수의 10진수 표기법임
    - 255.255.255.255 = 11111111.11111111.11111111.11111111
- **IPv6**
    - 이를 해결하기 위해 등장한 것이 IPv6
    - 21DA:00D3:0000:2F3B:02AA:00FF:FE28:9C5A 의 형태
    - 2^128 (43억 x 43억 x 43억 x 43억)

### 사설IP 와 공인IP

- 위의 IPv6처럼 IPv4의 수가 적어짐에 따라 해결하기위해 등장한 방법 중 하나
- 공인IP의 경우 절대경로
- 사설IP의 경우 상대경로
- 와이파이로 따지자면
- 공인IP는 라우터의 주소이고 사설IP는 그 라우터에 연결된 각 기기의 주소
- 라우터는 전세계적으로 하나만 존재하는 주소를 가지게 되지만 그 안에 연결된 각 기기들은 다른 네트워크의 기기와 같은 IP주소를 가지게 됨
- 같은 IP주소를 가지게 되더라도 라우터 안에서만 이용하므로 문제가 되지 않음
- 보통 집 컴퓨터의 IP주소가 192.168.0.~ 으로 시작되는 이유가 이것 때문

### Network ID 와 Host ID

- 하나의 IP주소에는 Network ID 와 Host ID 가 존재
- Network ID
    - 인터넷 상의 모든 Host들을 전부 관리하기 힘들기에 한 Network 범위를 지정해 관리하기 쉽게 만들어 낸 것
- Host ID
    - 호스트들을 개별적으로 관리하기 위해 사용하게 된 것
- 택배를 배달할 아파트의 주소 → Network ID
택배를 집앞에 놔둘지 혹은 관리실에 맡길지 처럼 최종적인 위치를 나타내주는 것 → Host ID
- 192.168.0.3 & 192.168.0.4 라는 IP가 있을 때
192.168.0 은 Network 영역
3 과 4 는 Host 영역
192.168.0 이라는 네트워크 영역에 서로 통신이 가능한 3과 4가 존재한다 라고 보면됨

### IP 클래스

- A, B, C, D, E Class로 나누어 Network ID와 Host ID를 구분
- A 클래스
- B 클래스
- C 클래스
- D 클래스와 E 클래스 실제 Network에서 사용되는 클래스는 A, B, C이고 
D 클래스는 Multicats(멀티캐스트), E 클래스는 미래에 사용하기 위해 남겨둔 것으로 예약되어 있는데 실제로 사용되는 경우는 거의 없음

### 클래스의 구분

- 각 Class는 첫번째 옥텟으로 구분
- 각 클래스 별 범위
- 클래스 범위 공식

---

# What is a Netmask

- 네트워크의 주소 부분의 비트를 1로 치환한 것
- IP 주소와 넷마스크를 AND 연산하면 네트워크 주소를 얻을 수 있음
- **우리가 사용중인 IP주소를 보면 그 IP주소로부터 네트워크 주소를 알아낼 수 있음**
- 이 때 사용하는 것이 넷마스크

> 134.45.72.2 라는 IP가 있을 때
첫 옥텟의 숫자를 보고 B클래스임을 알 수 있음
bit operation을 통해 
134.45.72.2 → 10000110.00101101.01111000.00000010
&                → 11111111.11111111.00000000.00000000
                   = 10000110.00101101.00000000.00000000
                   ⇒     134     .      45      .       0       .       0

- 인간은 그냥 딱 보면 두번째 옥텟 까지의 숫자를 보고 말겠지만
- 컴퓨터의 경우 그게 아니기 때문에 비트연산을 사용해 구하게 됨

# What is the subnet of an IP with Netmask

### 서브넷팅(subneting)

- 자신의 네트워크 주소를 더 작은 서브네트워크 주소로 나누는 것
- 서브네트워크는 2의 배수로 나눌 수 있음
- B클래스를 받은 네트워크가 있다면 2^14 만큼 사용할 수 있음
이 때 하나의 네트워크를 나누지 않고 그대로 사용하게 되면 데이터끼리 충돌하는 경우가 발생하게 됨
- 하나의 큰 네트워크는 중규모로 또 다른 네트워크로 나뉠 수 있고 그 중규모 네트워크는 다시 소규모 네트워크로 나뉠 수 있음

# What is the broadcast address of a subnet

### Broadcast

- 같은 네트워크 상의 모든 PC에 데이터를 주는 방식
- 주로 MAC주소는 모르고 IP주소만 알고있을 때 PC의 MAC주소를 알기 위해 
→ "이 네트워크 안에 이런 IP주소 가진 PC는 응답해주세요" 같은 느낌
- 또는 서버가 다수의 클라이언트에 서비스 하기위해서 사용되기도 함

### Unicast , Multicast

- 브로드캐스트와 함께하는 개념
- Unicast → 1:1로 데이터를 전달하는 통신 방식
- Multicast → 다수가 있는 네트워크에서 그 중 일부하고만 통신할 때 사용
    - 200명 중 150명과 데이터를 주고받을 경우
    - 브로드캐스트로 한번에 할 수도 있지만 데이터가 필요없는 50명에게는 불필요한 데이터를 주기 때문에 사용

### Broadcast Address

- 위에서 마스크를 통해 Network ID를 구하는 방법을 했었음

> 134.45.72.2 라는 IP가 있을 때
첫 옥텟의 숫자를 보고 B클래스임을 알 수 있음
bit operation을 통해 
134.45.72.2 → 10000110.00101101.01111000.00000010
&                → 11111111.11111111.00000000.00000000
                   = 10000110.00101101.00000000.00000000
                   ⇒     134     .      45      .       0       .       0

- 이 때 브로드캐스트 주소의 경우엔
- 뒤가 255로 됨
- 134.45.255.255
- 얻어진 네트워크 주소에서 서브넷마스크의 0으로된 비트를 모두 1로 바꾸어주면 브로드캐스트 주소를 얻을 수 있음

# What are the different ways to represent an ip address with the Netmask

### CIDR 표기법 (Classless Inter-Domain Routing)

- **클래스로만 구분된 네트워크의 한계를 극복하기 위한 수단**
    - 기존의 클래스만을 이용해서 네트워크를 이용하게되면 서브넷 마스크는 8자리 단위로만 끊기게 되어 낭비가 심하게됨
    - 네트워크를 조금 더 세부적인 단위로 쪼개 사용하기 위해 나온 방법
- 표기법

> 192.168.0.1(주소)
255.255.255.0(서브넷마스크)
위의 주소를 CIDR로 표기한게되면
192.168.0.1/24 이런식으로 표현됨
뒤의 24는 Network ID의 유효 범위

> 158.167.18.156/15 이런 주소가 있다면
10011110.10100111.00010010.10011100 (158.167.18.156)
11111111.11111110.00000000.00000000 (15)
위처럼 까만 부분은 Network ID의 범위가 되고
빨간 부분은 Host ID의 범위가 됨

호스트영역이 모두 0일 경우에는 네트워크 자체의 주소

호스트영역이 모두 1일 경우에는 브로드캐스트 주소가 됨

# What are the differences between public and private IPs

위의 IP와 함께 설명됨

# What is a class of IP addresses

위의 IP부분에서 함께 설명됨

# What is TCP & What is UDP

## TCP(Transmission Control Protocol)

- 인터넷 상에서 데이터를 메시지 형태로 보내기위해 IP와 함께 사용하는 프로토콜
- 보통 TCP/IP 로 쓰임
    - IP는 패킷 전달여부를 보증하지 않고 패킷을 보낸 순서와 받는 순서를 관리하지 않음
    그런 IP의 단점을 보완하기 위해서 TCP는 IP와 함께 쓰임
    - IP가 패킷의 전달을 담당한다면 TCP는 패킷들이 제대로 도착은 했는지 순서는 알맞게 되어있는지 검사하는 역할
- 가상 회선 연결방식, 연결형 서비스 제공
- 보안적으로 높은 신뢰성을 지님
- 연결의 설정(3-way handshaking)과 해제(4-way handshaking)
    - [3-way handshaking 와 4-way handshaking](https://mindnet.tistory.com/entry/%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC-%EC%89%BD%EA%B2%8C-%EC%9D%B4%ED%95%B4%ED%95%98%EA%B8%B0-22%ED%8E%B8-TCP-3-WayHandshake-4-WayHandshake)
    3-way handshaking은 TCP의 연결을 초기화 할 때
    4-way handshaking은 TCP의 세션을 종료하기 위해 수행되는 절차
- 데이터의 흐름 제어 및 혼잡 제어
    - 수신자 버퍼가 오버플로우 나는 상황을 방지하고 네트워크 내에 패킷이 과도하게 증가하는것을 방지
- 전이중(Full-Duplex), 점대점(Point to Point) 방식
    - Full-Duplex : 전이중 통신 이라고도 하며 두 대의 단말기가 데이터를 송수신하기 위해 각각 독립된 회선을 사용하는 방식, 데이터가 동시에 양쪽으로 전송되는 방식으로 쉽게 생각해 2차선다리라고 생각하면 됨
    - Point to Point : 통신 시 양 노드 또는 네트워크가 1 대 1 형식으로 연결된 구조

## UDP(User Datagram Protocol)

- 데이터를 데이터그램 단위로 처리하는 프로토콜
- 서로 정보를 주고 받을 때 어떠한 신호절차를 거치지 않고 보내는 쪽에서 일방적으로 데이터를 전달하는 방식
- 보내는 쪽에서 받는쪽이 데이터를 받았는지 확인하지 않음
- 비연결형 서비스이기에 연결을 설정하고 해제하는 과정이 존재하지 않음
- 패킷에 순서를 부여하여 재조립하거나 흐름을 제어하는 기능같은 것이 없어 TCP보다 속도가 빠르고 네트워크 부하가 적음
- 대신 신뢰성있는 데이터 전송을 보장할 수 없음
- 신뢰성보다는 연속성이 중요한 서비스로 주로 실시간 서비스에 이용됨
- 흐름제어가 없어 패킷의 확인이 불가능

[TCP와 UDP](https://www.notion.so/699d6a0d0c7e4c5b9b131815664b9609)

# What are the network layers & What is the OSI model

## OSI model || OSI 7 계층

- 네트워크 통신이 일어나는 과정을 7단계로 나눈 것
    - 데이터의 흐름을 알기 위해 → 계층별 기능을 통해 전반적인 흐름 이해가 쉬워짐
    - 문제해결이 쉬워짐 → 계층별로 구분을 해둬 어느 부분에서 문제가 생겼는지 파악이 가능
    - 표준화 → 네트워크의 초창기 각 장비회사에선 서로 다른 프로토콜을 이용했는데 OSI model을 통해 서로 같은 프로토콜을 사용하게 되고 타 회사간 장비의 통신이 가능해짐
- OSI 7 Layer Model
    1. Physical Layer
    2. DataLink Layer
    3. Network Layer
    4. Transport Layer
    5. Session Layer
    6. Presentation Layer
    7. Application Layer

### 7. Application Layer

- 응용계층
- 데이터 생성을 목적으로 사용자에게 인터페이스와 네트워크 서비스 제공
- **사용자와 직접적으로 맞닿아있는 계층**
- 사용자가 하고자하는 네트워크 종류에 따라 일련의 기능을 제공
- 대표적으로 DNS, DHCP, HTTP, FTP, SSH, Telnet 등이 있음

### 6. Presentation Layer

- 표현계층
- 7계층에서 만들어진 데이터를 컴퓨터가 인식할 수 있도록 데이터 표현 방식을 알려줌
- 해당 데이터가 .txt 인지 .jpg인지 처럼 데이터 확장자를 포함해 어떤 방식으로 표현되는지 알려주는 계층
- 이를통한 **암호화와 압축화** 를 지원

### 5. Session Layer

- 세션 계층
- **데이터가 통신하기위한 논리적인 연결을 담당**
- 양 끝단의 응용프로세스가 통신을 관리하기 위한 방법을 제공
- 전이중방식(Full-Duplex), 반이중방식(Half-Duplex), 동시 송수신 방식(Duplex)의 통신과 함께 체크포인팅, 유휴, 종료, 다시 시작과정 등을 수행
- **TCP/IP 세션을 만들고 없애는 계층**

### 4. Transport Layer

- 전송계층
- **통신을 활성화하기 위한 계층**
- 데이터 전송 방식을 결정하고, 서비스의 포트번호를 구별할 수 있음
- 이 계층에 속한 대표적인 프로토콜이 TCP와 UDP

### 3. Network Layer

- 네트워크 계층
- 논리적 주소를 기반으로 출발지에서 목적지까지 가는 데이터 경로를 결정
- 데이터를 목적지까지 가장 안전하고 빠르게 전달하는 기능 → 라우팅 or Routing Protocol
- 논리적 주소 → IP가 대표적

### 2. DataLink Layer

- 데이터링크 계층
- **물리적 주소를 기반으로 정보의 전달을 수행할 수 있도록 도와주는 역할을 함**
- 물리적 주소란 MAC주소를 말하며 LAN카드에 부여받은 고유 주소
- Physical Layer 를 통해 송수신되는 정보의 오류와 흐름을 관리함
- point to point 방식을 이용
- 물리계층에서 발생할 수 있는 오류를 찾아내고, 수정하는 데에 필요한 기능적, 절차적 수단을 제공

### 1. Physical Layer

- 물리계층
- 전기적, 기계적, 기능적 특성을 이용해 통신케이블로 데이터를 전송하게 됨
- 통신단위는 비트로 0과 1을 이용
- 이 계층은 단순히 데이터의 전달만 담당할 뿐 데이터가 무엇이고, 어떤 에러가 있는지 등은 전혀 신경쓰지 않음
- 대표적인 장비로는 통신케이블, 허브 등이 있음

# What is a DHCP server and the DHCP protocol

## DHCP(Dynamic Host Configuration Protocol)

- TCP/IP 프로토콜에서는 각 컴퓨터들이 고유 IP를 가져야만 인터넷에 접속할 수 있음
- 네트워크 관리자는 ISP(Internet Service Provider)로 부터 주소를 할당받음

    ISP(Internet Service Provider) : 인터넷 서비스 제공자, KT, LG유플러스, SK브로드밴드 처럼 인터넷 서비스를 제공해주는 업체

- 네트워크 관리자는 할당받은 IP주소 블록 내에서 각 컴퓨트, 호스트에 IP주소를 할당하고 관리함
- 이 과정을 자동으로 관리할 수 있게 해주는 것이 DHCP
- **IP의 동적인 할당을 자동으로 관리해줌 → 이를 IP의 임대 라고 함**

### DHCP의 구성

- DHCP 서버
    - 클라이언트에게 IP할당 요청이 들어오면 IP를 부여해주고 할당 가능한 IP의 관리를 맡음
- DHCP 클라이언트
    - 시스템 시작 시 DHCP서버에 자신의 시스템을 위한 IP주소를 요청하고 그를 통해 TCP/IP 설정을 초기화함

### DHCP의 3가지 기능

- DHCP는 IP 임대, 갱신 반환 의 기능을 가짐
- 임대
    - 클라이언트에게 특정 기간동안 IP를 빌려주는 것
    - DHCP의 IP 할당 순서
    1. DHCP Discover
        - 호스트가 DHCP서버를 찾기위한 단계
        - 호스트는 자신이 접속할 DHCP 서버의 주소를 알지 못하기 때문에 서브넷 상의 모든 노드에 브로드캐스팅을 해 DHCP서버를 찾음
    2. DHCP Offer
        - DHCP 서버에서 클라이언트에게 서버 제공 메시지를 보냄
        - 서버 제공 메시지에는 클라이언트의 IP주소, 도메인 이름, IP주소 임대기간(유효 시간) 등이 포함됨
        - 이 과정 또한 송신 호스트를 모르기에 서브넷 상의 모든 노드로 브로드캐스팅함
    3. DHCP Request
        - DHCP 서버 발견 후 호스트에게 최적의 서버를 선택 후 그 서버로 DHCP 요청 메시지를 보냄
    4. DHCP Ack
        - 서버는 DHCP 요청 메시지에 확정의 의미로 ACK메시지를 보냄

### DHCP의 장단점

- 장점
    - PC 수가 많거나 PC자체의 변동 사항이 많을 경우 IP설정이 자동으로 되기 때문에 효율적이도 IP의 할당이 자동이기 때문에 IP충돌을 막을 수 있음
- 단점
    - DHCP 서버에 의존하기 때문에 서버가 다운되면 IP할당이 제대로 이루어지지 않음

# What is a DNS server and the DNS protocol

## DNS(Domain Name System)

- 우리가 사용하는 사이트들을 IP주소로 쳐야한다면 기억하기가 어려울 것임
- 그런 IP주소를 우리가 알아보기 쉽게 [www.google.com](http://www.google.com) 처럼 도메인으로 바꿔주는 시스템
- 주소창에 도메인을 입력하면 서버에서는 그 도메인에 맞는 IP를 찾아주는 방식

# What are the rules to make 2 devices communicate using IP addresses

- OSI 모델 TCP/IP

# How does routing work with IP

1계층과 3계층

# What is a default gateway for routing

- 내부 네트워크에서는 라우터 없이도 통신이 가능
- 통신 시 목적지를 찾기위해 내부 네트워크를 먼저 찾는데 이게 없을 경우 디폴트 게이트웨이를 통해 외부 네트워크에서 목적지를 찾음
- **다른 네트워크로 통하는 액세스 포인트**
- 기본적으로는 가능한 호스트 중 가장 첫번째

# What is a port from an IP point of view and what is it used for when connecting to another device

## Port

- 운영 체제 통신의 종단점.
- 외부의 다른 장비와 접속하기 위한 플러그와 같은 느낌
- 포트는 기본적으로 0~65535번으로 구성되어있음
- IP주소와 Port를 이용해 특정 컴퓨터의 프로그램에 접근할 수 있음

# 참고

[오십보백보 소현님 포스팅](https://stitchcoding.tistory.com/4)

[network mask](https://kwongyo.tistory.com/16)

[subnet mask](https://kwongyo.tistory.com/19?category=880253)

[broadcast](https://kwongyo.tistory.com/18?category=880253)

[tcp](https://brunch.co.kr/@wangho/6)
