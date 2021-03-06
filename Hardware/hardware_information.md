## hardware
### 아두이노와 라즈베리파이의 차이점 

> 아두이노(Arduino)와 라즈베리파이(Raspberrypi)의 비교 분석
- 아두이노와 라즈베리파이 가장 큰 차이점은 OS(운영체제)이다.
- 아두이노는 OS의 구동없이 동작이 가능하며, 라즈베리파이는 OS가 있어야 동작이 가능하다. 즉 아두이노는 운영체제나 펌웨어가 없지만, 라즈베리파이는 운영체제 설치가 가능하다. 또한 아두이노는 외부 프로그램을 이용하여 순수하게 외부기기를 직접 "제어"하는 것에 특화되어 있다. 라즈베리파이는 설치되어있는 운영체제 내에서 직접 프로그래밍 하여 외부기기를 제어할 수 있다. 



> 아두이노는 C언어 기반으로 사용한다면, 라즈베리파이 C언어, JAVA, Python 등 다른 Software 기반 application도 확정 가능하다. 
> ##### - 고성능이며 크기가 작은 아두이노 우노 R3을 사용할 예정 

## arduino IOT fine dust project
> 미세먼지 정의가 대기 중에 떠다니거나 흩날려 내려오는 입자상 물질로 입자크기가 10마이크로미터 이하인 미세먼지(PM10), 2.5 마이크로미터 이한인 초 미세 먼지 (PM 2.5)라고 한다. 
### 미세먼지 측정 센서 (참조)
> - PMS7003 센서 
> 
> PM7003 미세먼지 센서는 Plantower사에서 제작, 판매하는 레이저 방식의 미세먼지 측정 센서이다.2.5(초미세먼지)를 안정적으로 측정할 수 있고, 크기도 작기 때문에 시중에서 판매되는 미세먼지 간이 측정기에 널리 사용되고 있음. 
> - ##### GP2Y1010AU0F 센서 (구매 예정)
> 
> 샤프의 GP2Y1010Au0F는 광학 감지 방식을 사용하는 미세먼지 센서이다,. 공기 중의 먼지와 입자로 공기 품질을 측정한다. 
> - PPD42NS 센서 
> 
> 이 센서는 광학감지방식을 사용하여 미세먼지 농도를 측정함, 저항 히터로 공기 자동 흡힙하여 측정 
> - ##### NOVA SDS011 센서 (구매 예정)
> 
> Nova fitness 사의 SDS011 센서는 레이저 산란의 원리를 사용해 공기 중 0.3~10 사이의 미세먼지 입자 농도를 측정할 수 있다. 디지털 출력과 내장 팬이 있어 안정적이고 신뢰할 수 있다. 
<br> 

# 실내 대기 측정 센서 

> - DHT22 센서
>  
> DHT22 온도 습도 센서는 AM2302 센서를 사용한다. 
> 
> - ##### MH-219B 센서 (구매 예정)
> 
> MH-219B 센서는 실내 공기질 모니터링에 많이 사용된다. (공기 청정기 효과를 높이기 위해 문과 창문을 꽉 닫으면 환기가 되지 않아, 미세먼지 농도는 감소해도 이산화탄소 농도가 올라간다. 공기청정기만 믿고 환기를 안시키면 오히려 이산화탄소가 인체에 나쁜 영향을 줄 수 있다. )

# 무선 전송 통신 시스템 구현 hardware (참조)
> - R.Box는 라즈베리파이 기반을 만들어진 다양한 센서로 구성되어 있는 IOT 허브로, 데비안 리눅스 기반으로 만들어진 Raspbian OS를 사용한다. 아두이노가 미세먼지센서에서 측정한 데이터를 wifi 를 통해 R.Box로 
> 

# 회로 설계 및 케이스 제작 (3D 프린터) 
> 케이스 제작을 어떻게 할건지 생각해 봐야함. 

---
참고자료(reference) 

![image](https://user-images.githubusercontent.com/63999666/148562803-8fb0b902-03e4-4b73-809e-6f1a9e0a70c8.png)

http://beesl.csbr.re.kr/wp-content/uploads/sites/3/2019/06/%EC%82%AC%EB%AC%BC%EC%9D%B8%ED%84%B0%EB%84%B7-%EA%B8%B0%EB%B0%98-%EC%8B%A4%EB%82%B4%ED%99%98%EA%B2%BD-%EC%B8%A1%EC%A0%95-%EC%84%BC%EC%84%9C-%EB%AA%A8%EB%93%88-%EA%B0%9C%EB%B0%9C.pdf
<br>
중앙대학교 논문 참조

![image](https://user-images.githubusercontent.com/63999666/148566417-8bb89ecd-05a1-402a-95aa-79ad3d892298.png)
https://scienceon.kisti.re.kr/commons/util/originalView.do?cn=CFKO201831342440545&oCn=NPAP12689473&dbt=CFKO&journal=NPRO00377597
<br> 
학술논문지 논문 참조 
