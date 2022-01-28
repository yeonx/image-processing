#define _CRT_SECURE_NO_WARNINGS // 경고무시
#include <windows.h> // 윈도우 응용 프로그램 헤더파일 포함
#include <stdio.h> //stdio헤더파일 포함
#include <stdlib.h> // stdlib헤더파일 포함
#include <math.h> // math헤더파일 포함
/*
float cubic(int v1, int v2, int v3, int v4, float d, float a) {
	float result = ((-v1 + (3 * v2) - (3 * v3) + v4) * pow(d, 3)) + (((2 * v1) - (5 * v2) + (4 * v3) - v4) * pow(d, 2)) + (v3 - v1) * d + (2 * v2);
	result /= 2;
	if (result >= 255)
		result = 255;
	return result;
}*/
int smallnum(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8) { //8개의 수 중에서 가장 작은 값의 인덱스를 반환해 주는 함수
	int num[8], index[8], i, j, tmp; // 8가지 수와 인덱스를 작은 순서로 담을 배열 선언, 반복문을 위한 i,j선언 임시로 값을 저장할 tmp 선언
	num[0] = n1;num[1] = n2;num[2] = n3;num[3] = n4; //8가지 수를 배열에 저장
	num[4] = n5;num[5] = n6;num[6] = n7;num[7] = n8; //8가지 수를 배열에 저장
	for (i = 0;i < 8;i++) //8번 반복
		index[i] = i; //인덱스에 담아줌
	for (i = 0;i < 7;i++) { //이중 반복문으로
		for (j = i + 1;j < 8;j++) { //작은 순으로 담기
			if (num[i] > num[j]) { // 앞에 있는 수가 더 크다면
				tmp = num[i];num[i] = num[j];num[j] = tmp; //바꿔줌
				tmp = index[i];index[i] = index[j];index[j] = tmp; //인덱스의 순도 바꿔줌
			}//괄호닫기
		}//괄호닫기
	}//괄호닫기
	return index[0]; //가장 작은 값의 인덱스 반환
}//괄호닫기
int main() {//메인함수 선언
	BITMAPFILEHEADER bmpFile; //BITMAPFILEHEADER 선언
	BITMAPINFOHEADER bmpInfo; //BITMAPINFOHEADER 선언
	FILE *inputFile = NULL; // 열 파일을 넣어줄 FILE형식 선언
	inputFile = fopen("AICenterY_128X128.bmp", "rb");// inputFile에 128*128bmp 읽음용으로 열기
	fread(&bmpFile, sizeof(BITMAPFILEHEADER), 1, inputFile);// inputFile에 연결된 파일로부터 BITMAPFILEHEADER 1개를 읽어 bmpFile변수에 저장
	fread(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, inputFile);// inputFile에 연결된 파일로부터 BITMAPINFOHEADER 1개를 읽어 bmpFile변수에 저장
	int width = bmpInfo.biWidth; // width에 bmpInfo에 담긴 biWidth값을
	int height = bmpInfo.biHeight;// height에 bmpInfo에 담긴 biHeight값을
	int size = bmpInfo.biSizeImage; // size에 bmpInfo에 담긴 biSizeImage값을
	int bitCnt = bmpInfo.biBitCount;// bitCnt에 bmpInfo에 담긴 biBitCount값을 
	int stride = (((bitCnt / 8)*width) + 3) / 4 * 4;// stride에 RGB를 다 담을 수 있는 값을 넣어줌
	unsigned char *inputImg = NULL, *Y1 = NULL; //128*128영상을 저장할 inputImg와 Y1선언
	inputImg = (unsigned char *)calloc(size, sizeof(unsigned char));// bmpInfo에 담긴  size값을 할당
	Y1 = (unsigned char *)calloc(width*height, sizeof(unsigned char));// bmpInfo에 담긴  width*height값을 할당
	fread(inputImg, sizeof(unsigned char), size, inputFile); // inputFile에서 inputImg읽음

	int width2 = bmpInfo.biWidth * 4; // width2에 bmpInfo에 담긴 biWidth값의 4배
	int height2 = bmpInfo.biHeight * 4;// height2에 bmpInfo에 담긴 biHeight값을
	int stride2 = (((bitCnt / 8)*width2) + 3) / 4 * 4; //stride2에 
	int size2 = stride2 * height2;// size2에  stride2 * height2
	unsigned char *outputImg = NULL, *Y2 = NULL; //512영상을 출력할 변수 선언
	outputImg = (unsigned char *)calloc(size2, sizeof(unsigned char)); //size2만큼 할당
	Y2 = (unsigned char *)calloc(width2*height2, sizeof(unsigned char)); //width2*height2만큼 할당
	int j, i; //반복문을 위한 j,i선언

	for (j = 0;j < height;j++) { //128크기의 높이만큼 
		for (i = 0;i < width;i++) { //128크기의 너비만큼 
			Y1[j*width + i] = inputImg[j*stride + 3 * i]; //Y정보담은 배열에 담기
		}//괄호닫기
	}//괄호닫기
	//////////////////////------------개발 히스토리 1번-----------------/////////////////////
	for (j = 0;j < height2;j++) { //512크기의 높이 만큼
		for (i = 0;i < width2;i++) { //512크기의 높이 만큼
			Y2[j*width2 + i] = Y1[(j / 4)*width + (i / 4)]; // Y정보를 담은 배열을 4씩 담기 128 -> 512
		}//괄호닫기
	}//괄호닫기
	/*
	for (j = 0;j < height2;j += 2) {
		for (i = 1;i < width2;i += 2)
			Y2[j*width2 + i] = (Y2[j*width2 + i-1]+ Y2[j*width2 + i+1]) / 2;
	}
	for (j = 0;j < height2;j += 2) {
		for (i = 1;i < width2;i += 2)
			Y2[j*width2 + i] = (Y2[(j+1)*width2 + i] + Y2[(j-1)*width2 + i]) / 2;
	}
	for (j = 1;j < height2;j += 2) {
		for (i = 1;i < width2;i += 2)
			Y2[j*width2 + i] = (Y2[(j + 1)*width2 + i] + Y2[(j - 1)*width2 + i]+ Y2[j*width2 + i - 1] + Y2[j*width2 + i + 1]) / 4;
	}*/
	unsigned char *Horizontal = NULL, *Vertic = NULL, *Edge = NULL; //수평,수직,경계 부분의 배열 선언
	Horizontal = (unsigned char *)calloc(height2*width2, sizeof(unsigned char)); //height2*width2 크기 만큼 할당
	Vertic = (unsigned char *)calloc(height2*width2, sizeof(unsigned char)); //height2*width2 크기 만큼 할당
	Edge = (unsigned char *)calloc(height2*width2, sizeof(unsigned char)); //height2*width2 크기 만큼 할당

	for (int j = 0;j < height2;j++) {//512 높이 만큼 반복
		for (int i = 0;i < width2;i++) {//512높이 만큼 반복
			Horizontal[j*width2 + i] = 0;//수평 0으로 초기화
			Vertic[j*width2 + i] = 0;//수직 0으로 초기화
		}//괄호닫기
	}//괄호닫기

	for (int j = 1;j < height2 - 1;j++) {//끝을 뺀 높이만큼 반복
		for (int i = 1;i < width2 - 1;i++) { //끝을 뺀 너비만큼 반복
			if ((Y2[(j - 1)*width2 + i] - Y2[(j + 1)*width2 + i])*(Y2[(j - 1)*width2 + i] - Y2[(j + 1)*width2 + i]) >= 900) //윗쪽과 아랫쪽의 경계가 30이상이면
				Horizontal[j*width2 + i] = 255;//윤곽 부분은 255로 
		}//괄호닫기
	}//괄호닫기

	for (int j = 1;j < height2 - 1;j++) {//끝을 뺀 높이만큼 반복
		for (int i = 1;i < width2 - 1;i++) { //끝을 뺀 너비만큼 반복
			if ((Y2[j*width2 + i - 1] - Y2[j*width2 + i + 1])*(Y2[j*width2 + i - 1] - Y2[j*width2 + i + 1]) >= 900) //왼쪽과 오른쪽의 경계가 30이상이면
				Vertic[j*width2 + i] = 255;//윤곽 부분은 255로 
		}//괄호닫기
	}//괄호닫기

	for (int j = 0;j < height2;j++) {//512높이만큼 반복
		for (int i = 0;i < width2;i++) {//512너비만큼 반복
			if (Horizontal[j*width2 + i] == 255 || Vertic[j*width2 + i] == 255)//두 부분의 윤곽이 존재할 경우
				Edge[j*width2 + i] = 255;//합한 경계에 255
			else //아니면
				Edge[j*width2 + i] = 0;//0을 저장
		}//괄호닫기
	}//괄호닫기
	/*
	for (j = 0;j < height2;j++) {
		for (i = 0;i < width2;i++) {
			if ((i % 4 == 0) && (j % 4 == 0))
				continue;
			if (Vertic[j*width2 + i] != 0) {
				if ((Horizontal[j*width2 + i + 1] == 255) && (Horizontal[j*width2 + i - 1] == 255)) {
					if (Vertic[(j + 1)*width2 + i] == 0)
						Y2[j*width2 + i] = (Y2[(j + 1)*width2 + i + 1] + Y2[(j + 1)*width2 + i - 1]) / 2;
					else
						Y2[j*width2 + i] = (Y2[(j - 1)*width2 + i + 1] + Y2[(j - 1)*width2 + i - 1]) / 2;
				}

			}
		}
	}

	for (j = 1;j < height2 - 1;j++) {
		for (i = 0;i < width2;i++) {
			if ((i % 4 == 0) && (j % 4 == 0))
				continue;
			if (Horizontal[j*width2 + i] == 255) {
				if ((Horizontal[j*width2 + i + 1] == 255) && (Horizontal[j*width2 + i - 1] == 255)) {
					if (Horizontal[(j + 1)*width2 + i] == 0)
						Y2[j*width2 + i] = (Y2[(j + 1)*width2 + i - 1] + Y2[(j + 1)*width2 + i + 1]) / 2;
					else
						Y2[j*width2 + i] = (Y2[(j - 1)*width2 + i + 1] + Y2[(j - 1)*width2 + i - 1]) / 2;
				}

			}
			if (Vertic[j*width2 + i] == 255) {
				if ((Vertic[(j + 1)*width2 + i] == 255) && (Vertic[(j - 1)*width2 + i] == 255)) {
					if (Vertic[j*width2 + (i + 1)] == 0)
						Y2[j*width2 + i] = (Y2[(j + 1)*width2 + i + 1] + Y2[(j - 1)*width2 + i + 1]) / 2;
					else
						Y2[j*width2 + i] = (Y2[(j + 1)*width2 + i - 1] + Y2[(j - 1)*width2 + i - 1]) / 2;
				}
			}
		}
	}
	int n1, n2, n3, n4, count = 0;
	for (j = 1;j < height2 - 1;j++) {
		for (i = 1;i < width2 - 1;i++) {
			n1 = 0;n2 = 0;n3 = 0;n4 = 0;
			if ((i % 4 == 0) && (j % 4 == 0))
				continue;
			else if (Horizontal[j*width2 + i] == 255) {
				if (Horizontal[(j + 1)*width2 + i] != 255)
					Y2[j*width2 + i] = (Y2[(j + 1)*width2 + i + 1] + Y2[(j + 1)*width2 + i - 1]) / 2;
				else
					Y2[j*width2 + i] = (Y2[(j - 1)*width2 + i + 1] + Y2[(j - 1)*width2 + i - 1]) / 2;
			}
			else if (Vertic[j*width2 + i] == 255) {
				if (Vertic[(j)*width2 + i + 1] != 255)
					Y2[j*width2 + i] = (Y2[(j + 1)*width2 + i + 1] + Y2[(j - 1)*width2 + i + 1]) / 2;
				else
					Y2[j*width2 + i] = (Y2[(j + 1)*width2 + i - 1] + Y2[(j - 1)*width2 + i - 1]) / 2;
			}
		}
	}
	*/
	//////////////////////------------ 개발 히스토리 2번-----------------/////////////////////
	/*
	//-----------4개의 꼭짓점 처리-------------//
	j = 0;i = width2 - 1;
	Y2[j*width2 + i]=
		(Y2[j*width2 + i] * 4 + Y2[j*width2 + i - 1] * 2 + Y2[(j + 1)*width2 + i] * 2 + Y2[(j + 1)*width2 + i - 1]) / 9; // 4:2:2:1 의 비율
	j = height2 - 1;i = 0;
	Y2[j*width2 + i] =
		(Y2[j*width2 + i] * 4 + Y2[j*width2 + i + 1] * 2 + Y2[(j - 1)*width2 + i] * 2 + Y2[(j - 1)*width2 + i + 1]) / 9; // 4:2:2:1 의 비율
	j = height2 - 1;i = width2 - 1;
	Y2[j*width2 + i] =
		(Y2[j*width2 + i] * 4 + Y2[j*width2 + i - 1] * 2 + Y2[(j - 1)*width2 + i] * 2 + Y2[(j - 1)*width2 + i - 1]) / 9; // 3:2:2:1 의 비율

	//-----------4개의 모서리 처리-------------//
	j = 0;
	for (int i = 1;i < width2 - 1;i++) {
		if (i % 4 == 0)
			continue;
		Y2[j*width2 + i] =
			(Y2[j*width2 + (i - 1)] * 2 + Y2[j*width2 + i] * 3 + Y2[j*width2 + (i + 1)] * 2 +
				Y2[(j + 1)*width2 + (i - 1)] + Y2[(j + 1)*width2 + i] * 2 + Y2[(j + 1)*width2 + (i + 1)]) / 11;
	}
	j = height2 - 1;
	for (int i = 1;i < width2 - 1;i++) {
		if ((i % 4 == 0) && (j % 4 == 0))
			continue;
		Y2[j*width2 + i] = (Y2[(j - 1)*width2 + (i - 1)] * 2 + Y2[(j - 1)*width2 + i] + Y2[(j - 1)*width2 + (i + 1)] * 2 +
			Y2[j*width2 + (i - 1)] + Y2[j*width2 + i] * 2 + Y2[j*width2 + (i + 1)]) / 9;
	}
	i = 0;
	for (j = 1;j < height2 - 1;j++) {
		if (j % 4 == 0)
			continue;
		Y2[j*width2 + i] =
			(Y2[(j - 1)*width2] * 2 + Y2[(j - 1)*width2 + i] + Y2[j*width2] * 4 +
				Y2[j*width2 + i] * 2 + Y2[(j + 1)*width2] * 2 + Y2[(j + 1)*width2 + i]) / 12;
	}
	i = width2 - 1;
	for (j = 1;j < height2 - 1;j++) {
		Y2[j*width2 + i] =
			(Y2[(j - 1)*width2 + (i - 1)] + Y2[(j - 1)*width2 + i] * 2 + Y2[j*width2 + (i - 1)] * 2 +
				Y2[j*width2 + i] * 4 + Y2[(j + 1)*width2 + (i - 1)] + Y2[(j + 1)*width2 + i] * 2) / 12;
	}

	//----모서리도 꼭짓점도 아닌 부분-------//
	for (j = 1;j < height2 - 1;j++) {
		for (i = 1;i < width2 - 1;i++) {
			if ((i % 4 == 0) && (j % 4 == 0))
				continue;
			Y2[j*width2 + i] =
				(Y2[(j - 1)*width2 + (i - 1)] * 1 / 16 + Y2[(j - 1)*width2 + i] * 1 / 8 + Y2[(j - 1)*width2 + (i + 1)] * 1 / 16 +
					Y2[j*width2 + (i - 1)] * 1 / 8 + Y2[j*width2 + i] * 1 / 4 + Y2[j*width2 + (i + 1)] * 1 / 8 +
					Y2[(j + 1)*width2 + (i - 1)] * 1 / 16 + Y2[(j + 1)*width2 + i] * 1 / 8 + Y2[(j + 1)*width2 + (i + 1)] * 1 / 16);
		}
	}
	*/
	//////////////////////------------개발 히스토리 3번-----------------/////////////////////
	for (j = 0;j < height2;j += 4) {//높이는 아는 값
		for (i = 2;i < width2;i += 4) //너비 부분은 아는 값의 중간 값
			Y2[j*width2 + i] = (Y2[(j)*width2 + i - 2] + Y2[(j)*width2 + i + 2]) / 2; // 양 옆의 아는 값의 평균
	}//괄호닫기
	for (j = 0;j < height2;j += 4) { //높이는 아는 값
		for (i = 1;i < width2;i += 2) // 아는 값에 인접한 값
			Y2[j*width2 + i] = (Y2[(j)*width2 + i - 1] + Y2[(j)*width2 + i + 1]) / 2; //실제로 비율은 아는 0.75,0.25
	}//괄호닫기
	for (j = 2;j < height2;j += 4) { //높이 부분은 아는 값의 중간 값
		for (i = 0;i < width2;i += 4) //너비 부분은 아는 값
			Y2[j*width2 + i] = (Y2[(j - 2)*width2 + i] + Y2[(j + 2)*width2 + i]) / 2; //양 옆의 아는 값의 평균
	}//괄호닫기
	for (j = 1;j < height2;j += 2) {// 아는 값에 인접한 값
		for (i = 0;i < width2;i += 4)//너비는 아는 값
			Y2[j*width2 + i] = (Y2[(j - 1)*width2 + i] + Y2[(j + 1)*width2 + i]) / 2;//실제로 비율은 아는 0.75,0.25
	}//괄호닫기
	for (j = 2;j < height2;j += 4) {// 4값의 중간
		for (i = 2;i < width2;i += 4) //아는 4값의 중간
			Y2[j*width2 + i] = (Y2[(j - 2)*width2 + i - 2] + Y2[(j + 2)*width2 + i - 2] + Y2[(j - 2)*width2 + i + 2] + Y2[(j + 2)*width2 + i + 2]) / 4; //아는 4값의 평균
	}//괄호닫기
	for (j = 1;j < height2;j += 2) { //홀수번째 값
		for (i = 2;i < width2;i += 4) //아는 값의 중간
			Y2[j*width2 + i] = (Y2[(j - 1)*width2 + i] + Y2[(j + 1)*width2 + i]) / 2; //위아래 값의 평균
	}//괄호닫기
	for (j = 2;j < height2;j += 4) {//아는 값의 중간
		for (i = 1;i < width2;i += 2)//홀수번째
			Y2[j*width2 + i] = (Y2[(j)*width2 + i - 1] + Y2[(j)*width2 + i + 1]) / 2; //양 옆 값의 평균
	}//괄호닫기
	for (j = 1;j < height2;j += 2) { //나머지값
		for (i = 1;i < width2;i += 2) { //나머지 값
			Y2[j*width2 + i] = (Y2[(j - 1)*width2 + i - 1] + Y2[(j - 1)*width2 + i + 1] + Y2[(j - 1)*width2 + i] + Y2[(j)*width2 + i + 1] + //주변값의 평균
				Y2[(j)*width2 + i - 1] + Y2[(j + 1)*width2 + i + 1] + Y2[(j + 1)*width2 + i - 1] + Y2[(j + 1)*width2 + i]) / 8;// 주변값의 평균
		}//괄호닫기
	}//괄호닫기
	/*
	///////////////////////-------bicubic----------///////////////////////
	int v1, v2, v3, v4;
	float d, a;
	for (j = 5;j < height2-8;j++) {
		for (i = 0;i < width2;i+=4) {
			if (j % 4 == 0)
				continue;
			v1 = Y2[(j - 4) / 4 * 4 * width2 + i];
			v2 = Y2[(j) / 4 * 4 * width2 + i];
			v3 = Y2[(j + 4) / 4 * 4 * width2 + i];
			v4 = Y2[(j + 8) / 4 * 4 * width2 + i];
			d = (float)(j - (j) / 4 * 4)/4;
			Y2[j*width2+i] = cubic(v1, v2, v3, v4, d, 2);
		}
	}
	for (j = 0;j < height2;j++) {
		for (i = 5;i < width2-8;i ++) {
			if (i % 4 == 0 && j%4==0)
				continue;
			v1 = Y2[j * width2 + (i - 4) / 4 * 4];
			v2 = Y2[j* width2 + (i) / 4 * 4];
			v3 = Y2[j* width2 + (i + 4) / 4 * 4];
			v4 = Y2[j* width2 + (i + 8) / 4 * 4];
			d = (float)(i - (i) / 4 * 4) / 4;
			Y2[j*width2 + i] =cubic(v1, v2, v3, v4, d, 2);
		}
	}
	*/
	//////////////////////------------개발 히스토리 4번-----------------/////////////////////
	for (j = height2 - 3;j < height2;j += 1) { //영상의 윗부분에 대해
		for (i = 0;i < width2;i++) //반복해서
			Y2[j*width2 + i] = Y2[(j - 1)*width2 + i]; //아는값 중 가까운 값으로 대체
	}//괄호닫기
	for (j = 0;j < height2;j += 1) { //영상의 오른쪽 부분에 대해
		for (i = width2 - 3;i < width2;i++) //반복해서 
			Y2[j*width2 + i] = Y2[j*width2 + i - 1]; //아는 값 중 가까운 값으로 대체
	}//괄호닫기
	//////////////////////------------개발 히스토리 5번-----------------/////////////////////

	int n1, n2, n3, n4, n5, n6, n7, n8, smalln, jj, ii; //작은 차이를 뽑아내기 위한 변수들과 반복문을 위한 변수 선언
	for (j = 4;j < height2 - 4;j += 4) { // 아는 값에서 끝부분 빼고 반복
		for (i = 4;i < width2 - 4;i += 4) { // 아는 값에서 끝부분 빼고 반복
			if (Edge[j*width2 + i] == 255) { //윤곽 부분인 경우
				n1 = (Y2[j*width2 + i] - Y2[(j - 4)*width2 + i - 4])*(Y2[j*width2 + i] - Y2[(j - 4)*width2 + i - 4]); //높이기준-4 너비기준 -4
				n2 = (Y2[j*width2 + i] - Y2[(j - 4)*width2 + i + 4])*(Y2[j*width2 + i] - Y2[(j - 4)*width2 + i + 4]); //높이기준-4 너비기준 +4
				n3 = (Y2[j*width2 + i] - Y2[(j + 4)*width2 + i - 4])*(Y2[j*width2 + i] - Y2[(j + 4)*width2 + i - 4]); //높이기준+4 너비기준 -4
				n4 = (Y2[j*width2 + i] - Y2[(j + 4)*width2 + i + 4])*(Y2[j*width2 + i] - Y2[(j + 4)*width2 + i + 4]); //높이기준+4 너비기준 +4
				n5 = (Y2[j*width2 + i] - Y2[(j - 4)*width2 + i])*(Y2[j*width2 + i] - Y2[(j - 4)*width2 + i]); //높이기준-4 
				n6 = (Y2[j*width2 + i] - Y2[(j + 4)*width2 + i])*(Y2[j*width2 + i] - Y2[(j + 4)*width2 + i]); //높이기준+4 
				n7 = (Y2[j*width2 + i] - Y2[(j)*width2 + i - 4])*(Y2[j*width2 + i] - Y2[(j)*width2 + i - 4]); //너비기준 -4
				n8 = (Y2[j*width2 + i] - Y2[(j)*width2 + i + 4])*(Y2[j*width2 + i] - Y2[(j)*width2 + i + 4]); //너비기준 +4
				smalln = smallnum(n1, n2, n3, n4, n5, n6, n7, n8) + 1; //차이가 가장 작은 값을 함수로 찾아냄
				if ((smalln == 1) && (Edge[(j - 4)*width2 + i - 4] == 255) && (Y2[j*width2 + i] == Y2[(j - 4)*width2 + i - 4])) {//높이기준-4 너비기준 -4 과 차이가 가장 작을 때
					for (jj = j - 3, ii = i - 3;jj < j;jj++, ii++) // 그 사이의 값에 대해
						Y2[jj*width2 + ii] = (Y2[(j - 4)*width2 + i - 4] + Y2[jj*width2 + ii]) / 2; // 그 값에 있던 것과 Y2[(j - 4)*width2 + i - 4] 평균
				}//괄호닫기
				else if ((smalln == 2) && (Edge[(j - 4)*width2 + i + 4] == 255) && (Y2[(j - 4)*width2 + i + 4] == Y2[j*width2 + i])) {//높이기준-4 너비기준 +4 과 차이가 가장 작을 때
					for (jj = j - 3, ii = i + 3;jj < j;jj++, ii--)// 그 사이의 값에 대해
						Y2[jj*width2 + ii] = (Y2[(j - 4)*width2 + i + 4] + Y2[jj*width2 + ii]) / 2;// 그 값에 있던 것과 Y2[(j - 4)*width2 + i + 4] 평균
				}//괄호닫기
				else if ((smalln == 3) && (Edge[(j + 4)*width2 + i - 4] == 255) && (Y2[(j + 4)*width2 + i - 4] == Y2[j*width2 + i])) {//높이기준+4 너비기준 -4 과 차이가 가장 작을 때
					for (jj = j + 3, ii = i - 3;jj > j;jj--, ii++) // 그 사이의 값에 대해
						Y2[jj*width2 + ii] = (Y2[(j + 4)*width2 + i - 4] + Y2[jj*width2 + ii]) / 2;// 그 값에 있던 것과 Y2[(j + 4)*width2 + i - 4] 평균
				}//괄호닫기
				else if ((smalln == 4) && (Edge[(j + 4)*width2 + i + 4] == 255) && (Y2[(j + 4)*width2 + i + 4] == Y2[j*width2 + i])) {//높이기준+4 너비기준 +4 과 차이가 가장 작을 때
					for (jj = j + 3, ii = i + 3;jj > j;jj--, ii--)// 그 사이의 값에 대해
						Y2[jj*width2 + ii] = (Y2[(j + 4)*width2 + i + 4] + Y2[jj*width2 + ii]) / 2;// 그 값에 있던 것과 Y2[(j + 4)*width2 + i + 4] 평균
				}//괄호닫기
				else if ((smalln == 5) && (Edge[(j - 4)*width2 + i] == 255) && (Y2[(j - 4)*width2 + i] == Y2[j*width2 + i])) {//높이기준-4과 차이가 가장 작을 때
					for (jj = j - 3;jj < j;jj++) // 그 사이의 값에 대해
						Y2[jj*width2 + i] = (Y2[(j - 4)*width2 + i] + Y2[jj*width2 + i]) / 2;// 그 값에 있던 것과 Y2[(j - 4)*width2 + i] 평균
				}//괄호닫기
				else if ((smalln == 6) && (Edge[(j + 4)*width2 + i] == 255) && (Y2[(j + 4)*width2 + i] == Y2[j*width2 + i])) {//높이기준+4과 차이가 가장 작을 때
					for (jj = j + 3;jj > j;jj--)// 그 사이의 값에 대해
						Y2[jj*width2 + i] = (Y2[(j + 4)*width2 + i] + Y2[jj*width2 + i]) / 2;// 그 값에 있던 것과 Y2[(j - 4)*width2 + i] 평균
				}//괄호닫기
				else if ((smalln == 7) && (Edge[(j)*width2 + i - 4] == 255) && (Y2[(j)*width2 + i - 4] == Y2[j*width2 + i])) {//너비기준 -4 과 차이가 가장 작을 때
					for (ii = i - 3;ii < i;ii++)// 그 사이의 값에 대해
						Y2[j*width2 + ii] = (Y2[(j)*width2 + i - 4] + Y2[j*width2 + ii]) / 2;// 그 값에 있던 것과 Y2[(j)*width2 + i - 4] 평균
				}//괄호닫기
				else if ((smalln == 8) && (Edge[(j)*width2 + i + 4] == 255) && (Y2[(j)*width2 + i + 4] == Y2[j*width2 + i])) {//너비기준 +4 과 차이가 가장 작을 때
					for (ii = i + 3;ii > i;ii--)// 그 사이의 값에 대해
						Y2[j*width2 + ii] = (Y2[(j)*width2 + i + 4] + Y2[j*width2 + i]) / 2;// 그 값에 있던 것과 Y2[(j)*width2 + i + 4] 평균
				}//괄호닫기
			}//괄호닫기
		}//괄호닫기
	}//괄호닫기


	///////////////////////////////////////////////////////////////////
	for (j = 0;j < height2;j++) { // 512 높이만큼 반복
		for (i = 0;i < width2;i++) { //512 너비만큼 반복
			outputImg[j*stride2 + 3 * i] = Y2[j*width2 + i]; //3가지 RGB에 Y 넣어주기
			outputImg[j*stride2 + 3 * i + 1] = Y2[j*width2 + i]; //3가지 RGB에 Y 넣어주기
			outputImg[j*stride2 + 3 * i + 2] = Y2[j*width2 + i]; //3가지 RGB에 Y 넣어주기
		}//괄호닫기
	}//괄호닫기


	FILE *outputFile = fopen("19011824_이연희.bmp", "wb"); //19011824_이연희 로 bmp파일을 열 것
	bmpInfo.biWidth = width2; //bmpInfo의 biwidth 값 512기준으로 맞춰주기
	bmpInfo.biHeight = height2; //bmpInfo의 biHeight 값 512기준으로 맞춰주기
	bmpInfo.biSizeImage = size2; //bmpInfo의 biSizeImage 값 512기준으로 맞춰주기
	bmpFile.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + size2; //bmpInfo의 bfSize 값 512기준으로 맞춰주기
	fwrite(&bmpFile, sizeof(BITMAPFILEHEADER), 1, outputFile);// bmgFile 변수에 저장된 BITMAPFILEHEADER 1개를 outputFile에 연결된 파일에 저장
	fwrite(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, outputFile);// bmgInfo 변수에 저장된 BITMAPINFOHEADER 1개를 outputFile에 연결된 파일에 저장
	fwrite(outputImg, sizeof(unsigned char), size2, outputFile);// outputImg 변수에 저장된 unsigned char를  size2개 outputFile에 연결된 파일에 저장
	free(inputImg);//input이미지에 할당 해제
	free(outputImg);//output이미지에 할당 해제
	fclose(inputFile);//input파일 닫아주기
	fclose(outputFile);//output파일 닫아주기
	return 0;//메인함수종료
}//괄호닫기