#define _CRT_SECURE_NO_WARNINGS // 경고무시
#include <windows.h> // 윈도우 응용 프로그램 헤더파일 포함
#include <stdio.h> //stdio헤더파일 포함
#include <stdlib.h> // stdlib헤더파일 포함
int med(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9) { // 중간값을 구하기 위한 함수
	int n[9] = { 0 }, i, j, tmp;  // 9개 배열과, 반복문을 위한 i,j 선언 그리고 정렬을 위한 tmp선언
	n[0] = n1; n[1] = n2; n[2] = n3;n[3] = n4; n[4] = n5; n[5] = n6;n[6] = n7; n[7] = n8; n[8] = n9; // 입력받은 값 배열에 넣기
	for (i = 0;i < 9;i++) { // 정렬을 해주기 위한 반복문 오름차순
		for (j = 0;j < 8;j++) { // 정렬을 해주기 위한 이중 반복문
			if (n[j] > n[j + 1]) { // 앞에 있는 것이 더 크면
				tmp = n[j]; // tmp에 j번째 를 넣고
				n[j] = n[j + 1]; // j번째에 j+1번째를 넣고
				n[j + 1] = tmp; // j+1번째에 tmp를 넣어줌 (교환 완료)
			}//if문 괄호닫기
		}//for문 괄호닫기
	}//이중 for문 괄호닫기
	return n[4]; //중간값 반환
}//괄호닫기
int med_vertex(int n1, int n2, int n3, int n4) { // 꼭지점 부분의 중간값을 구하기 위한 함수
	int n[4] = { 0 }, i, j, tmp; // 4개의 배열과, 반복문을 위한 i,j 선언 그리고 정렬을 위한 tmp선언
	n[0] = n1;n[1] = n2;n[2] = n3;n[3] = n4; // 입력받은 값 배열에 넣기
	for (i = 0;i < 4;i++) { //정렬을 해주기 위한 반복문
		for (j = 0;j < 3;j++) { //정렬을 해주기 위한 반복문
			if (n[j] > n[j + 1]) { //앞에 있는 것이 더 크면 바꿔줌
				tmp = n[j]; //tmp에 j번째 넣고
				n[j] = n[j + 1]; //j번째에 j+1번째 넣고 
				n[j + 1] = tmp; //j+1번째에 
			}//괄호닫기
		}//괄호닫기
	}//괄호닫기
	if (n[0] == 0)//맨 앞의 값이 0일 때 그것을 제외한 3가지로 중간값을 해줌
		return n[2]; //배열의 3번째가 중간값임
	else // 맨 뒤의 값이 255이면 그것을 제외한 3가지로 중간값을 계산
		return n[1]; // 배열으리 2번째가 중간값임
}//괄호닫기
int med_edge(int n1, int n2, int n3, int n4, int n5, int n6) { // 모서리 부분의 중간값을 구하기 위한 함수
	int n[6] = { 0 }, i, j, tmp; // 6개의 배열과 반복문을 위한 i,j 선언 그리고 정렬을 위한 tmp 정렬
	n[0] = n1;n[1] = n2;n[2] = n3; n[3] = n4;n[4] = n5;n[5] = n6; // 입력받은 값 배열에 넣기
	for (i = 0;i < 6;i++) { //정렬을 해주기 위한 반복문
		for (j = 0;j < 5;j++) { //정렬을 해주기 위한 반복문
			if (n[j] > n[j + 1]) { // 앞의 값이 더 크면 교환
				tmp = n[j]; // tmp에 j번째를 넣고
				n[j] = n[j + 1]; // j번째엔 j+1값을
				n[j + 1] = tmp; // 다시 j+1번째엔 tmp에 있는 값을 넣어줌
			}//괄호닫기
		}//괄호닫기
	}//괄호닫기
	if (n[0] == 0) // 배열의 첫번째가 0이면 그 값을 빼고 중간값 계산
		return n[3]; // 4번째가 중간값임
	else // 마지막 값이 255면 그 값을 빼고 중간값 계산
		return n[2]; // 3번째가 중간값임
}//괄호닫기
int main() { //메인함수 
	BITMAPFILEHEADER bmpFile; //BITMAPFILEHEADER 선언
	BITMAPINFOHEADER bmpInfo; //BITMAPINFOHEADER 선언
	FILE *inputFile = NULL; // 열 파일을 넣어줄 FILE형식 선언
	inputFile = fopen("free.bmp", "rb"); // inputFile에 노이즈가 있는 bmp 읽음용으로 열기
	fread(&bmpFile, sizeof(BITMAPFILEHEADER), 1, inputFile); // inputFile에 연결된 파일로부터 BITMAPFILEHEADER 1개를 읽어 bmpFile변수에 저장
	fread(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, inputFile); // inputFile에 연결된 파일로부터 BITMAPINFOHEADER 1개를 읽어 bmpInfo변수에 저장
	int width = bmpInfo.biWidth; // width에 bmpInfo에 담긴 biWidth값을
	int height = bmpInfo.biHeight; // height에 bmpInfo에 담긴 biHeight값을
	int size = bmpInfo.biSizeImage; // size에 bmpInfo에 담긴 biSizeImage값을
	int bitCnt = bmpInfo.biBitCount; // bitCnt에 bmpInfo에 담긴 biBitCount값을 
	
	int stride = (((bitCnt / 8)*width) + 3) / 4 * 4; // stride에 RGB를 다 담을 수 있는 값을 넣어줌
	printf("W: %d(%d)\nH: %d\nS: %d\nD: %d\n", width, stride, height, size, bitCnt);

	unsigned char *inputImg = NULL, *outputImg = NULL; // 받은 bmp파일을 넣는 변수와 output을 위한 변수 선언
	inputImg = (unsigned char *)calloc(size, sizeof(unsigned char)); // bmpInfo에 담긴  size값을 할당
	outputImg = (unsigned char *)calloc(size, sizeof(unsigned char)); // bmpInfo에 담긴  size값을 할당
	unsigned char tmp;// 임시로 값을 넣어 줄 것임
	fread(inputImg, sizeof(unsigned char), size, inputFile); // inputFile에 연결된 파일로부터 unsigned char를 size개를 읽어 inputImg변수에 저장


	int i, j;// 앞으로 for문에 대해 이 변수들을 쓸 거라 선언해주기

	//---------모서리와 꼭지점을 하나하나 처리-----------------//

	for (j = 1;j < height - 1;j++) { // 모서리와 꼭짓점을 제외한 부분을 처리하기 위해
		for (i = 1;i < width - 1;i++) { // 앞이랑 뒤 1 씩을 빼준 나머지 값을 처리
			if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) { // 노이즈가 있는 이미지에 대해 극단적인 검정, 흰 점이 찍혀 있을 경우 (salt-and-pepper)
				inputImg[j*stride + 3 * i] = med(inputImg[(j - 1)*stride + 3 * (i - 1)], inputImg[(j - 1)*stride + 3 * i], inputImg[(j - 1)*stride + 3 * (i + 1)], // 9가지에 를 med함수를 호출해 
					inputImg[j*stride + 3 * (i - 1)], inputImg[j*stride + 3 * i], inputImg[j*stride + 3 * (i + 1)], // 중간값으로 극단적인 점을
					inputImg[(j + 1)*stride + 3 * (i - 1)], inputImg[(j + 1)*stride + 3 * i], inputImg[(j + 1)*stride + 3 * (i + 1)]); // 처리해 주기
				outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리 (RGB 3가지에 다 넣어주기)
				outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i+1]; //output이미지에 중간값을 넣어준 것으로 처리
				outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i+2]; //output이미지에 중간값을 넣어준 것으로 처리
			}//괄호닫기
		}//괄호닫기
	}//괄호닫기

	//-----------4개의 꼭짓점 처리-------------//

	j = 0;i = 0; // height=0, width=0 부분 꼭지점
	if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) { //이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
		inputImg[j*stride + 3 * i] = med_vertex(inputImg[j*stride + 3 * i], inputImg[j*stride + 3 * (i + 1)], // med_vertex는 꼭지점을 위해 만든 미디언 필터링
			inputImg[(j + 1)*stride + 3 * i], inputImg[(j + 1)*stride + 3 * (i + 1)]); // 해당 위치와 주변까지 필터링해줌
		outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리 (RGB 3가지에 다 넣어주기)
		outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i + 1]; //output이미지에 중간값을 넣어준 것으로 처리
		outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i + 2]; //output이미지에 중간값을 넣어준 것으로 처리
	} //괄호닫기
	else { // 극단적인 점이 없을 때
		tmp = //Gaussian  filter를 응용해 주변으로 갈 수록 가중치를 적게 둘 것임
			(inputImg[j*stride + 3 * i] *4 + inputImg[j*stride + 3 * (i+1)]*2 + inputImg[(j + 1)*stride + 3 * i]*2 + inputImg[(j + 1)*stride + 3 * (i + 1)])/9; // 4:2:2:1 의 비율
		outputImg[j*stride + 3 * i] = tmp; //output이미지에 tmp의 결과를 넣어줌 (RGB 3가지에 다 넣어주기)
		outputImg[j*stride + 3 * i + 1] = tmp; //output이미지에 tmp의 결과를 넣어줌
		outputImg[j*stride + 3 * i + 2] = tmp; //output이미지에 tmp의 결과를 넣어줌
	}//괄호닫기
	j = 0;i = width - 1; // height=0, width 부분 꼭지점
	if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) { //이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
		inputImg[j*stride + 3 * i] = med_vertex(inputImg[j*stride + 3 * i], inputImg[j*stride + 3 * (i - 1)], // med_vertex는 꼭지점을 위해 만든 미디언 필터링
			inputImg[(j + 1)*stride + 3 * i], inputImg[(j + 1)*stride + 3 * (i - 1)]); // 해당 위치와 주변까지 필터링해줌
		outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리 (RGB 3가지에 다 넣어주기)
		outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i + 1]; //output이미지에 중간값을 넣어준 것으로 처리
		outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i + 2]; //output이미지에 중간값을 넣어준 것으로 처리
	} //괄호닫기
	else { // 극단적인 점이 없을 때
		tmp = //Gaussian tmp를 응용해 주변으로 갈 수록 가중치를 적게 둘 것임
			(inputImg[j*stride + 3 * i] * 4 + inputImg[j*stride + 3 * (i - 1)] *2 + inputImg[(j + 1)*stride + 3 * i]*2 + inputImg[(j + 1)*stride + 3 * (i - 1)] )/9; // 4:2:2:1 의 비율
		outputImg[j*stride + 3 * i] = tmp; //output이미지에 tmp의 결과를 넣어줌 (RGB 3가지에 다 넣어주기)
		outputImg[j*stride + 3 * i + 1] = tmp; //output이미지에 tmp의 결과를 넣어줌
		outputImg[j*stride + 3 * i + 2] = tmp; //output이미지에 tmp의 결과를 넣어줌
	}//괄호닫기
	j = height - 1;i = 0; // height 끝부분, width=0 부분 꼭지점
	if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) { //이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
		inputImg[j*stride + 3 * i] = med_vertex(inputImg[j*stride + 3 * i], inputImg[j*stride + 3 * (i + 1)], // med_vertex는 꼭지점을 위해 만든 미디언 필터링
			inputImg[(j - 1)*stride + 3 * i], inputImg[(j - 1)*stride + 3 * (i + 1)]); // 해당 위치와 주변까지 필터링해줌
		outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리 (RGB 3가지에 다 넣어주기)
		outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i + 1]; //output이미지에 중간값을 넣어준 것으로 처리
		outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i + 2]; //output이미지에 중간값을 넣어준 것으로 처리
	} //괄호닫기
	else { // 극단적인 점이 없을 때
		tmp = //Gaussian  filter를 응용해 주변으로 갈 수록 가중치를 적게 둘 것임
			(inputImg[j*stride + 3 * i] * 4 + inputImg[j*stride + 3 * (i + 1)] *2 + inputImg[(j - 1)*stride + 3 * i] *2 + inputImg[(j - 1)*stride + 3 * (i + 1)]) / 9; // 4:2:2:1 의 비율
		outputImg[j*stride + 3 * i] = tmp; //output이미지에 tmp의 결과를 넣어줌 (RGB 3가지에 다 넣어주기)
		outputImg[j*stride + 3 * i + 1] = tmp; //output이미지에 tmp의 결과를 넣어줌
		outputImg[j*stride + 3 * i + 2] = tmp; //output이미지에 tmp의 결과를 넣어줌
	}//괄호닫기
	j = height - 1;i = width - 1; // height와 width끝부분 꼭지점
	if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) { //이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
		inputImg[j*stride + 3 * i] = med_vertex(inputImg[j*stride + 3 * i], inputImg[j*stride + 3 * (i - 1)], // med_vertex는 꼭지점을 위해 만든 미디언 필터링
			inputImg[(j - 1)*stride + 3 * i], inputImg[(j - 1)*stride + 3 * (i - 1)]); // 해당 위치와 주변까지 필터링해줌
		outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리 (RGB 3가지에 다 넣어주기)
		outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i + 1]; //output이미지에 중간값을 넣어준 것으로 처리
		outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i + 2]; //output이미지에 중간값을 넣어준 것으로 처리
	} //괄호닫기
	else { // 극단적인 점이 없을 때
		tmp = //Gaussian  filter를 응용해 주변으로 갈 수록 가중치를 적게 둘 것임
			(inputImg[j*stride + 3 * i] * 4 + inputImg[j*stride + 3 * (i - 1)]*2 + inputImg[(j - 1)*stride + 3 * i] *2 + inputImg[(j - 1)*stride + 3 * (i - 1)])/9; // 3:2:2:1 의 비율
		outputImg[j*stride + 3 * i] = tmp; //output이미지에 tmp의 결과를 넣어줌 (RGB 3가지에 다 넣어주기)
		outputImg[j*stride + 3 * i + 1] = tmp; //output이미지에 tmp의 결과를 넣어줌
		outputImg[j*stride + 3 * i + 2] = tmp; //output이미지에 tmp의 결과를 넣어줌
	}//괄호닫기

	//-----------4개의 모서리 처리-------------//
	j = 0; //heigh=0인 모서리 처리
	for (int i = 1;i < width - 1;i++) {// 끝이 아닌 부분의 폭
		if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) { //이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
			inputImg[j*stride + 3 * i] = med_edge(inputImg[j*stride + 3 * (i - 1)] , inputImg[j*stride + 3 * i] ,inputImg[j*stride + 3 * (i + 1)] , // med_edge함수는 모서리 부분의 중간값을 찾아주는 함수
				inputImg[(j + 1)*stride + 3 * (i - 1)] , inputImg[(j + 1)*stride + 3 * i] , inputImg[(j + 1)*stride + 3 * (i + 1)]); // 자신을 포함한 6가지를 모두 넣어줌
			outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리 (RGB 3가지에 다 넣어주기)
			outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리
			outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리
		}//괄호닫기
		else { // 극단적인 점이 없을 때
			tmp = // Gaussian  filter를 응용해 주변으로 갈 수록 가중치를 적게 둘 것임
				(inputImg[j*stride + 3 * (i - 1)] * 2 + inputImg[j*stride + 3 * i] * 4 + inputImg[j*stride + 3 * (i + 1)] * 2 + // 6개의 비율은 4:2:2:2:1:1 곱해주고
				inputImg[(j + 1)*stride + 3 * (i - 1)] + inputImg[(j + 1)*stride + 3 * i] * 2 + inputImg[(j + 1)*stride + 3 * (i + 1)]) / 12; // 12로 나눠줌
			outputImg[j*stride + 3 * i] = tmp; //output이미지에 tmp의 결과를 넣어줌 (RGB 3가지에 다 넣어주기)
			outputImg[j*stride + 3 * i + 1] = tmp; //output이미지에 tmp의 결과를 넣어줌
			outputImg[j*stride + 3 * i + 2] = tmp; //output이미지에 tmp의 결과를 넣어줌
		}//괄호닫기
	}//괄호닫기
	j = height-1; // height의 끝부분 중 0이 아닌 모서리 처리
	for (int i = 1;i < width - 1;i++) { //끝이 아닌 부분의 폭
		if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) {//이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
			inputImg[j*stride + 3 * i] = med_edge(inputImg[(j - 1)*stride + 3 * (i - 1)], inputImg[(j-1)*stride + 3 * i], inputImg[(j - 1)*stride + 3 * (i + 1)], // med_edge함수는 모서리 부분의 중간값을 찾아주는 함수
				inputImg[j*stride + 3 * (i - 1)], inputImg[j*stride + 3 * i], inputImg[j*stride + 3 * (i + 1)]); // 자신을 포함한 6가지를 모두 넣어줌
			outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리 (RGB 3가지에 다 넣어주기)
			outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리
			outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리
		}//괄호닫기
		else { // 극단적인 점이 없을 때
			tmp = (inputImg[(j - 1)*stride + 3 * (i - 1)] + inputImg[(j - 1)*stride + 3 * i] * 2 + inputImg[(j - 1)*stride + 3 * (i + 1)] + // 6개의 비율은 4:2:2:2:1:1 곱해주고
				inputImg[j*stride + 3 * (i - 1)] * 2 + inputImg[j*stride + 3 * i] * 4 + inputImg[j*stride + 3 * (i + 1)] * 2) / 12; //12로 나눠줌
			outputImg[j*stride + 3 * i] = tmp; //output이미지에 tmp의 결과를 넣어줌 (RGB 3가지에 다 넣어주기)
			outputImg[j*stride + 3 * i + 1] = tmp; //output이미지에 tmp의 결과를 넣어줌
			outputImg[j*stride + 3 * i + 2] = tmp; //output이미지에 tmp의 결과를 넣어줌
		}//괄호닫기
	}//괄호닫기
	i = 0; // 폭에서 width=0인 부분의 처리
	for (j = 1;j < height - 1;j++) { // 끝부분이 아닌 높이 부분
		if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) {//이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
			inputImg[j*stride +3* i] = med_edge(inputImg[(j-1)*stride + 3 * i], inputImg[(j-1)*stride + 3 * (i+1)], inputImg[j*stride + 3 * i ], // med_edge함수는 모서리 부분의 중간값을 찾아주는 함수
				inputImg[j*stride + 3 * (i + 1)], inputImg[(j + 1)*stride + 3 * i], inputImg[(j + 1)*stride + 3 * (i + 1)]); // 자신을 포함한 6가지를 모두 넣어줌
			outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리 (RGB 3가지에 다 넣어주기)
			outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리
			outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리
		}//괄호닫기
		else { // 극단적인 점이 없을 때
			tmp = // Gaussian  filter를 응용해 주변으로 갈 수록 가중치를 적게 둘 것임
				(inputImg[(j - 1)*stride] * 2 + inputImg[(j - 1)*stride + 3] + inputImg[j*stride] * 4 + // 6개의 비율은 4:2:2:2:1:1 곱해주고
					inputImg[j*stride + 3] * 2 + inputImg[(j + 1)*stride] * 2 + inputImg[(j + 1)*stride + 3]) / 12; //12로 나눠줌
			outputImg[j*stride + 3 * i] = tmp; //output이미지에 tmp의 결과를 넣어줌 (RGB 3가지에 다 넣어주기)
			outputImg[j*stride + 3 * i + 1] = tmp; //output이미지에 tmp의 결과를 넣어줌
			outputImg[j*stride + 3 * i + 2] = tmp; //output이미지에 tmp의 결과를 넣어줌
		}//괄호닫기
	}//괄호닫기
	i = width-1; //폭에서 width가 0이 아닌 반대쪽 끝 부분의 처리
	for (j = 1;j < height - 1;j++) { // 끝부분이 아닌 높이 부분
		if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) {//이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
			inputImg[j*stride + 3 * i] = med_edge(inputImg[(j-1)*stride + 3 * (i - 1)], inputImg[(j-1)*stride + 3 * i], inputImg[j*stride + 3 * (i - 1)], // med_edge함수는 모서리 부분의 중간값을 찾아주는 함수
				inputImg[j*stride + 3 * i], inputImg[(j + 1)*stride + 3 * (i-1)], inputImg[(j + 1)*stride + 3 * i]); // 자신을 포함한 6가지를 모두 넣어줌
			outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리 (RGB 3가지에 다 넣어주기)
			outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리
			outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i]; //output이미지에 중간값을 넣어준 것으로 처리
		}//괄호닫기
		else { // 극단적인 점이 없을 때
			tmp = // Gaussian  filter를 응용해 주변으로 갈 수록 가중치를 적게 둘 것임
				(inputImg[(j - 1)*stride + 3 * (i - 1)] + inputImg[(j - 1)*stride + 3 * i] * 2 + inputImg[j*stride + 3 * (i - 1)] * 2 + // 6개의 비율은 4:2:2:2:1:1 곱해주고
					inputImg[j*stride + 3 * i] * 4 + inputImg[(j + 1)*stride + 3 * (i - 1)] + inputImg[(j + 1)*stride + 3 * i] * 2) / 12; // 12로 나눠줌
			outputImg[j*stride + 3 * i] = tmp; //output이미지에 tmp의 결과를 넣어줌 (RGB 3가지에 다 넣어주기)
			outputImg[j*stride + 3 * i + 1] = tmp; //output이미지에 tmp의 결과를 넣어줌
			outputImg[j*stride + 3 * i + 2] = tmp; //output이미지에 tmp의 결과를 넣어줌
		}//괄호닫기
	}//괄호닫기
	
	//----모서리도 꼭짓점도 아닌 부분-------//
	for (j = 1;j < height - 1;j++) { // 모서리도 아니고 꼭지점도 아닌 부분의 높이 부분 처리
		for (i = 1;i < width - 1;i++) { //모서리도 아니고 꼭지점도 아닌 부분의 폭 부분 처리
			if (inputImg[j*stride + 3 * i + 0] != 0 && inputImg[j*stride + 3 * i + 0] != 255) { //salt-and-pepper 의 경우가 아닌 경우
				tmp =// Gaussian filter를 사용해줌
					(inputImg[(j - 1)*stride + 3 * (i - 1)] * 1 / 16 + inputImg[(j - 1)*stride + 3 * i] * 1 / 8 + inputImg[(j - 1)*stride + 3 * (i + 1)] * 1 / 16 + //9가지의 비율은
					inputImg[j*stride + 3 * (i - 1)] * 1 / 8 + inputImg[j*stride + 3 * i] * 1 / 4 + inputImg[j*stride + 3 * (i + 1)] * 1 / 8 + // 4:2:2:2:2:1:1:1:1
					inputImg[(j + 1)*stride + 3 * (i - 1)] * 1 / 16 + inputImg[(j + 1)*stride + 3 * i] * 1 / 8 + inputImg[(j + 1)*stride + 3 * (i + 1)] * 1 / 16); //16으로 각각 나눠줌
				outputImg[j*stride + 3 * i] = tmp; //output이미지에 tmp의 결과를 넣어줌 (RGB 3가지에 다 넣어주기)
				outputImg[j*stride + 3 * i + 1] = tmp; //output이미지에 tmp의 결과를 넣어줌
				outputImg[j*stride + 3 * i + 2] = tmp; //output이미지에 tmp의 결과를 넣어줌
			}//괄호닫기
			
		}//괄호닫기
	}//괄호닫기
	//----------패딩을 씌운 ver-----------//
	/*
	unsigned char *filter=NULL;//패딩을 포함한 것을 만들 것임
	filter = (unsigned char *)calloc((height + 2)*(width + 2), sizeof(unsigned char)); //높이와 넓이가 +2만큼 더 큰 패딩을 포함한 것을 할당
	for (j = 0;j < height + 2;j++) { // 패딩을 포함해서 filter에 넣어주어야함
		for (i = 0;i < width + 2;i++) { // 이미지의 넓이와 폭에 +2만큼의 
			if (j == 0) { //height가 0인 경우
				if (i == 0) { // 그 중에서도 폭이 0인 경우
					if (inputImg[(j + 1)*stride + 3 * (i + 1)] == 0 || inputImg[(j + 1)*stride + 3 * (i + 1)] == 255) //이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
						filter[j*width + i] = inputImg[(j + 2)*stride + 3 * (i + 2)]; //다른 주변의 값을 filter에 넣어줌
					else //이미지에 극단적인 검정이나 흰 점이 찍혀 있지 않을 경우
						filter[j*width + i] = inputImg[(j + 1)*stride + 3 * (i + 1)]; // 그 값을 filter에 넣어줌
				}//괄호닫기
				else if (i == width - 1) //그 중에서 폭이 맨 끝인 경우
					if (inputImg[(j + 1)*stride + 3 * (i - 1)] == 0 || inputImg[(j + 1)*stride + 3 * (i - 1)] == 255) //이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
						filter[j*width + i] = inputImg[(j + 2)*stride + 3 * (i - 2)]; //다른 주변의 값을 filter에 넣어줌
					else //이미지에 극단적인 검정이나 흰 점이 찍혀 있지 않을 경우
						filter[j*width + i] = inputImg[(j + 1)*stride + 3 * (i - 1)]; // 그 값을 filter에 넣어줌

				else { // 나머지 모서리 부분일 때
					if (inputImg[(j + 1)*stride + 3 * i] == 0 || inputImg[(j + 1)*stride + 3 * i] == 255) //이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
						filter[j*width + i] = inputImg[(j + 2)*stride + 3 * i]; //다른 주변의 값을 filter에 넣어줌
					else //이미지에 극단적인 검정이나 흰 점이 찍혀 있지 않을 경우
						filter[j*width + i] = inputImg[(j + 1)*stride + 3 * i]; // 그 값을 filter에 넣어줌
				}//괄호닫기
			}//괄호닫기
			else if (j == height - 1) { // 높이가 0의 반대편 끝인 경우
				if (i == 0) { // 그중에서 폭이 0
					if (inputImg[(j - 1)*stride + 3 * (i + 1)] == 0 || inputImg[(j - 1)*stride + 3 * (i + 1)] == 255)  //이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
						filter[j*width + i] = inputImg[(j - 2)*stride + 3 * (i + 2)]; //다른 주변의 값을 filter에 넣어줌
					else //이미지에 극단적인 검정이나 흰 점이 찍혀 있지 않을 경우
						filter[j*width + i] = inputImg[(j - 1)*stride + 3 * (i + 1)]; // 그 값을 filter에 넣어줌
				}//괄호닫기

				else if (i == width - 1) { // 그 중에서 폭이 0의 반대편 끝
					if (inputImg[(j - 1)*stride + 3 * (i - 1)] == 0 || inputImg[(j - 1)*stride + 3 * (i - 1)] == 255) //이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
						filter[j*width + i] = inputImg[(j - 2)*stride + 3 * (i - 2)]; //다른 주변의 값을 filter에 넣어줌

					else //이미지에 극단적인 검정이나 흰 점이 찍혀 있지 않을 경우
						filter[j*width + i] = inputImg[(j - 1)*stride + 3 * (i - 1)]; // 그 값을 filter에 넣어줌
				}//괄호닫기

				else { //나머지 모서리 부분일 때
					if (inputImg[(j - 1)*stride + 3 * i] == 0 || inputImg[(j - 1)*stride + 3 * i] == 255) //이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
						filter[j*width + i] = inputImg[(j - 2)*stride + 3 * i]; //다른 주변의 값을 filter에 넣어줌
					else //이미지에 극단적인 검정이나 흰 점이 찍혀 있지 않을 경우 
						filter[j*width + i] = inputImg[(j - 1)*stride + 3 * i]; // 그 값을 filter에 넣어줌
				}//괄호닫기
			}//괄호닫기
			else if (i == 0) { //폭이 0일 경우
				if (inputImg[j*stride + 3 * (i + 1)] == 0 || inputImg[j*stride + 3 * (i + 1)] == 255) //이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
					filter[j*width + i] = inputImg[j*stride + 3 * (i + 2)]; //다른 주변의 값을 filter에 넣어줌
				else //이미지에 극단적인 검정이나 흰 점이 찍혀 있지 않을 경우
					filter[j*width + i] = inputImg[j*stride + 3 * (i + 1)]; // 그 값을 filter에 넣어줌
			}//괄호닫기

			else if (i == width - 1) { //폭이 0이 아닌 반대편 부분 끝인 경우
				if (inputImg[j*stride + 3 * (i - 1)] == 0 || inputImg[j*stride + 3 * (i - 1)] == 255) //이미지에 극단적인 검정이나 흰 점이 찍혀 있을 때 (salt-and-pepper)
					filter[j*width + i] = inputImg[j*stride + 3 * (i - 2)]; //다른 주변의 값을 filter에 넣어줌
				else //이미지에 극단적인 검정이나 흰 점이 찍혀 있지 않을 경우
					filter[j*width + i] = inputImg[j*stride + 3 * (i - 1)]; // 그 값을 filter에 넣어줌
			}//괄호닫기
			else { // 패딩 부분이 아닌 쪽은
				filter[j*width + i] = inputImg[(j - 1)*stride + 3 * (i - 1)]; // input이미지 부분을 그대로 넣어줌
			}//괄호닫기
		}//괄호닫기
	}//괄호닫기
	for (j = 1;j < height + 1;j++) { //패딩 안쪽 부분에 대해
		for (i = 1;i < width + 1;i++) { // 높이와 넓이 (이미지 부분에 맞춘)
			if (filter[j*width + i] == 0 || filter[j*width + i] == 255) { // 노이즈가 있는 이미지에 대해 극단적인 검정, 흰 점이 찍혀 있을 경우 (salt-and-pepper)
				filter[j*width + i] = med(filter[(j - 1)*width + (i - 1)], filter[(j - 1)*width + i], filter[(j - 1)*width + (i + 1)], // 9가지에 를 med함수를 호출해 
					filter[j*width + (i - 1)], filter[j*width + i], filter[j*width + (i + 1)], // 중간값으로 극단적인 점을
					filter[(j + 1)*width + (i - 1)], filter[(j + 1)*width + i], filter[(j + 1)*width + (i + 1)]); // 처리해 주기
			}//괄호닫기
			else {
				filter[j*width + i] =// Gaussian filter를 사용해줌
					(filter[(j - 1)*width + (i - 1)] * 1 / 16 + filter[(j - 1)*width + i] * 1 / 8 + filter[(j - 1)*width + (i + 1)] * 1 / 16 + //9가지의 비율은
						filter[j*width + (i - 1)] * 1 / 8 + filter[j*width + i] * 1 / 4 + filter[j*width + (i + 1)] * 1 / 8 + // 4:2:2:2:2:1:1:1:1
						filter[(j + 1)*width + (i - 1)] * 1 / 16 + filter[(j + 1)*width + i] * 1 / 8 + filter[(j + 1)*width + (i + 1)] * 1 / 16); //16으로 각각 나눠줌
			}//괄호닫기
		}//괄호닫기
	}//괄호닫기
	for (j = 0;j < height;j++) { // 이미지 크기 만큼의 높이에 대해
		for (i = 0;i < width;i++) { // 폭만큼의 넓이에 대해
			outputImg[j*stride + 3 * i] = filter[(j + 1)*width + (i + 1)]; //B
			outputImg[j*stride + 3 * i + 1] = filter[(j + 1)*width + (i + 1)]; //G
			outputImg[j*stride + 3 * i + 2] = filter[(j + 1)*width + (i + 1)]; //R
		}//괄호닫기
	}//괄호닫기
	*/
	FILE *outputFile = fopen("19011824_이연희.bmp", "wb"); //19011824_이연희 로 bmp파일을 열 것
	fwrite(&bmpFile, sizeof(BITMAPFILEHEADER), 1, outputFile); // bmgFile 변수에 저장된 BITMAPFILEHEADER 1개를 outputFile에 연결된 파일에 저장
	fwrite(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, outputFile); // bmgInfo 변수에 저장된 BITMAPINFOHEADER 1개를 outputFile에 연결된 파일에 저장
	fwrite(outputImg, sizeof(unsigned char), size, outputFile); // outputImg 변수에 저장된 unsigned char를  size개 outputFile에 연결된 파일에 저장
	free(outputImg); //output이미지에 할당 해제
	free(inputImg); //input이미지에 할당 해제
	//free(filter); //filter 할당 해제
	fclose(inputFile); //input파일 닫아주기
	fclose(outputFile); //output파일 닫아주기
	return 0; //main함수 종료
}//괄호닫기