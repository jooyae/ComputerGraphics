


## Computer Graphics 

*서울여자대학교 컴퓨터 그래픽스 전공 수업* 

Computer Graphics에는 캐드 , 캠, 가상현실, 애니메이션, 게임, 교육 훈련, 자연과학 가시화, 그래픽 사용자 인터페이스 등 응용분야가 많다. 그중에서도 (1) *Computer Aided Manufacturing* - Numerical Control Machine 개발 및 자동 생산에 따른 효율과 가공의 정밀도 향상 (2) *Virtual Walkthrough* - 레이 트레이싱에 의한 렌더링 (3) 애니메이션 및 게임 - 사용자와 프로그램 사이의 상호작용 설계 , 시간 최소화 (4) *CAI* - 학습 보조도구로서 컴퓨터에 내재하는 추론기능과 지식 데이터 베이스 (5) 과학분야 가시화 *SCI VIS* (Scientific Visualization) 과 *GUI* (그래픽 사용자 인터페이스) 에 대해서 이론과 실습을 한다. 

## Contents 

 1. 3D 도형 모델링과 시점 변환 
 2. 투상 변환과 뷰포트 변환
 3. 가시성 판단을 위한 벡터,후면 제거 
 4. 레스터 변환과 모델 변환 
 5. 그래픽 사용자 인터페이스 응용 
 6. 3D 애니메이션 개인 프로젝트 

## 3D Modeling 

간단한 원구부터 시작해서 3D Teapot Modeling과 시점 변환
<img src="https://user-images.githubusercontent.com/58849278/123018454-908ebd80-d409-11eb-9653-d77cf7e3c577.png">

 - 평행 투상 변환
 - 원근 투상 변환
 - x축으로 10도 회전 
 - x축으로 0.3 이동한 후 1.2배 확대, z축으로 180도 회전 

도형 설계 화면 

<img src="https://user-images.githubusercontent.com/58849278/123018295-40176000-d409-11eb-8ecf-44d099e9325e.png" width = 70%>

## 가시성 판단

후면과 은면 제거 

<img src="https://user-images.githubusercontent.com/58849278/123018944-7acdc800-d40a-11eb-9dad-415886785f1b.png" width = 40%>

후면제거 

<img src="https://user-images.githubusercontent.com/58849278/123019102-c6807180-d40a-11eb-9c5c-5e405867190a.png" width = 40%>

은면제거 

<img src="https://user-images.githubusercontent.com/58849278/123019145-e2841300-d40a-11eb-9cf6-370ea7b447ad.png" width = 40%>

후면과 은면 존재 

<img src="https://user-images.githubusercontent.com/58849278/123019230-0cd5d080-d40b-11eb-867d-74712954924b.png" width = 40%>

전면 제거 

<img src="https://user-images.githubusercontent.com/58849278/123019265-24ad5480-d40b-11eb-877f-cdfac20d8cd0.png" width = 40%>

이면 line처리 

<img src="https://user-images.githubusercontent.com/58849278/123019322-3bec4200-d40b-11eb-954b-c484798c9b61.png" width = 40%>

 - 모델링 What to Draw & 렌더링 How to Draw 
 - 모델링 : 장면 내부 물체를 정의하는 작업으로 선분의 끝점, 다각형의 정점 정의
 - 렌더링 : 정의될 물체를 그려내는 작업으로 조명, 관찰자 위치, 재질, 3차원 물체를 어떻게 2차원 화면으로 사상하는지 정의 
 :heavy_check_mark: 여기서는 화면 선명도를 위해 샤도우 마스크, 애퍼처 그릴 그리고 인터레이싱 = 주사선을 사용했다. 또 화소단위의 컬러링이 아닌 벡터 그래픽 장비로 화소 개념이 없고 전자빔의 폭으로 무한 해상도를 표현할 수 있다. 

## 레스터 변환 

 - 지엘의 래스터 변환 
	 - 은면제거와 동시 진행 
	 - 깊이와 색을 보간 
	 - 정규화 장치 좌표 -> 뷰포트 좌표 -> 화면 좌표 순 
	 - 최대의 연산속도와 최대의 정확성이 요구 
 - 브레스넘 알고리즘 
	 - 종점 알고리즘 
	 - 빠른 연산 속도 
	 - 부동소수 연산에서 발생하는 표류현상 없음 
	 

  

		     void MidpointLine(int x1, int y1, int x2, int y2){ int dx, dy, incrE, incrNE, D, x, y; dx = x2 - x1; dy = y2 - y1; D = 2*dy - dx; 결정변수 값을 초기화 incrE = 2*dy; 동쪽 화소 선택시 증가분 incrNE = 2*dy - 2*dx; 동북쪽 화소 선택시 증가분 x = x1; y = y1; 첫 화소 DrawPixel(x, y) 첫 화소 그리기 while (x < x2) { if (D <= 0) { 결정변수가 음수. 동쪽화소 선택 D += incrE; 결정변수 증가 x++; } 다음 화소는 동쪽 else{ 결정변수가 양수. 동북쪽 화소 선택 D += incrNE; 결정변수 증가 x++; y++; } 다음 화소는 동북쪽 DrawPixel (x, y); 화소 그리기 } }


## GUI - Graphic User Interface

 - 오토데스크 3ds 맥스 프로그램 사용  
 - 주전자 예시 
 
	 <img src="https://user-images.githubusercontent.com/58849278/123021334-dc903100-d40e-11eb-85b7-eed87f0b5c92.png" width = 60%>

## 3D 아기 공룡  

**Record**  
<img src="https://user-images.githubusercontent.com/58849278/123021810-bae37980-d40f-11eb-94b9-ee27aa57ee7c.gif">

 1. 3D 공룡 모델링 
 2. 마우스 클릭시 Jump 효과 추가 
 3. 3D 	배경에 바닥 표현 후 그림자 rotate 효과
 4. Plane으로 행성을 표현하고 싶었지만 너무 허접했다 .. 
 5. 3D teapot 
 6. 아기 공룡의 성장 




