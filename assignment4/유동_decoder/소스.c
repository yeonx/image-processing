#define _CRT_SECURE_NO_WARNINGS //경고무시
#include <windows.h> //원도우 응용 프로그램 헤더파일 포함
#include <stdio.h> // stdio.h 헤더파일 포함
#include <string.h> // string.h헤더파일 포함
#include <stdlib.h> // stdlib.h 헤더파일 포함

int change8(char *s) { //6bit 문자열의 이진수를 십진수로 바꾸는 함수
	int k = 0; //return 값 초기화
	if (s[7] == '1') //1이면
		k += 1; //+1
	if (s[6] == '1') //1이면
		k += 2; //+2
	if (s[5] == '1') //1이면
		k += 4; //+1
	if (s[4] == '1') //1이면
		k += 8; //+2
	if (s[3] == '1') //1이면
		k += 16; //+4
	if (s[2] == '1') //1이면
		k += 32; //+8
	if (s[1] == '1') //1이면
		k += 64; //+16
	if (s[0] == '1') //1이면
		k += 128; //+32
	return k; //총 값을 반환
} //괄호닫기
int change(int k) {
	int i, num = 1;
	for (i = 1;i < k;i++) {
		num = num * 2;

	}
	return num;
}
int main() {//메인함수 선언
	BITMAPFILEHEADER bmpFile;//BITMAPFILEHEADER 선언
	BITMAPINFOHEADER bmpInfo;//BITMAPINFOHEADER 선언
	FILE *inputFile = NULL;// 열 파일을 넣어줄 FILE형식 선언
	FILE *fp = fopen("bitstream.txt", "r"); //txt파일을 읽기모드로 open
	unsigned char *outputImg = NULL, *Y = NULL; //출력이미지와 Y값을 받을 것을 선언
	inputFile = fopen("tmp.bmp", "rb"); //출력이미지를 위한 흰바탕의 512*512 bmp파일
	fread(&bmpFile, sizeof(BITMAPFILEHEADER), 1, inputFile); // inputFile에 연결된 파일로부터 BITMAPFILEHEADER 1개를 읽어 bmpFile변수에 저장
	fread(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, inputFile);// inputFile에 연결된 파일로부터 BITMAPINFOHEADER 1개를 읽어 bmpFile변수에 저장
	int width = bmpInfo.biWidth;// width에 bmpInfo에 담긴 biWidth값을
	int height = bmpInfo.biHeight;// height에 bmpInfo에 담긴 biHeight값을
	int size = bmpInfo.biSizeImage;// size에 bmpInfo에 담긴 biSizeImage값을
	int bitCnt = bmpInfo.biBitCount;// bitCnt에 bmpInfo에 담긴 biBitCount값을 
	int stride = (((bitCnt / 8)*width) + 3) / 4 * 4;// stride에 RGB를 다 담을 수 있는 값을 넣어줌
	outputImg = (unsigned char *)calloc(size, sizeof(unsigned char)); //size만큼 할당
	Y = (unsigned char *)calloc(height*width, sizeof(unsigned char)); //width*height만큼 할당


	//---------필요한 변수 선언------------//
	char s2[2] = { 0, }; // 6bit씩 받을 문자열 선언
	char s8[9] = { 0, };
	int i, j, num,k=0; // 반복문을 위한 i,j선언
	int d = 0;

	for (j = 0;j < height;j ++) { //높이와 너비 부분이 둘 다
		for (i = 0;i < width;i++) { //짝수 부분 값만 저장되어있으니
			
			if (i == 0) {
				fread(s8, sizeof(char), 8, fp);
				Y[j*height + i] = change8(s8);
				memset(s8, 0, 9);
			}
			else {
				k = 0;
				d = 0;
				while (1) {
					memset(s2, 0, 2);
					fread(s2, sizeof(char), 1, fp);

					if (s2[0] == '0') {
						if (k == 0) {
							Y[j*height + i] = Y[j*height + i-1];
						}
						else {
							int n =k;
							if (n == 0) {
								n = 0;
							}
							else if (n == 1) {
								n = 1;
							}
							else if (n == 2) {
								n = -1;
							}
							else if (n == 3) {
								n = 2;
							}
							else if (n == 4) {
								n = -2;
							}
							else if (n == 5) {
								n = 3;
							}
							else if (n == 6) {
								n = -3;
							}
							else if (n == 7) {
								n = 4;
							}
							else if (n == 8) {
								n = -4;
							}
							else if (n == 9) {
								n = 5;
							}
							else if (n == 10) {
								n = -5;
							}
							else if (n == 11) {
								n = 6;
							}
							else if (n == 12) {
								n = -6;
							}
							else if (n == 13) {
								n = 7;
							}
							else if (n == 14) {
								n = -7;
							}
							else if (n == 15) {
								n = 8;
							}
							else if (n == 16) {
								n = -8;
							}
							else if (n == 17) {
								n = 9;
							}
							else if (n == 18) {
								n = -9;
							}
							else if (n == 19) {
								n = 10;
							}
							else if (n == 20) {
								n = -10;
							}
							else if (n == 21) {
								n = 11;
							}
							else if (n == 22) {
								n = -11;
							}
							else if (n == 23) {
								n = 12;
							}
							else if (n == 24) {
								n = -12;
							}
							else if (n == 25) {
								n = 13;
							}
							else if (n == 26) {
								n = -13;
							}
							else if (n == 27) {
								n = 14;
							}
							else if (n == 28) {
								n = -14;
							}
							else if (n == 29) {
								n = 15;
							}
							else if (n == 30) {
								n = -15;
							}
							else if (n == 31) {
								n = 16;
							}
							else if (n == 32) {
								n = -16;
							}
							Y[j*height + i] = Y[j*height + i - 1] + n* 15;
						}
						break;
					}
					else {
						k++;
						d = 1;
					}

				}
			}
		}//괄호닫기
	}//괄호닫기

	//-----------------------------------------------------------------//


	for (j = 0;j < height;j++) {
		for (i = 0;i < width;i++) { 
			outputImg[j*stride + 3 * i] = Y[j*height + i];//3가지 RGB에 Y 넣어주기
			outputImg[j*stride + 3 * i + 1] = Y[j*height + i];//3가지 RGB에 Y 넣어주기
			outputImg[j*stride + 3 * i + 2] = Y[j*height + i];//3가지 RGB에 Y 넣어주기
		}//괄호닫기
	}//괄호닫기


	FILE *outFile = fopen("light.bmp", "wb"); //복원한 영상 bmp파일로 열 것
	fwrite(&bmpFile, sizeof(BITMAPFILEHEADER), 1, outFile); // bmgFile 변수에 저장된 BITMAPFILEHEADER 1개를 outputFile에 연결된 파일에 저장
	fwrite(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, outFile); // bmgInfo 변수에 저장된 BITMAPINFOHEADER 1개를 outputFile에 연결된 파일에 저장
	fwrite(outputImg, sizeof(unsigned char), size, outFile);// outputImg 변수에 저장된 unsigned char를  size개 outputFile에 연결된 파일에 저장
	free(outputImg); //아웃풋이미지에 할당 해제
	fclose(outFile); //아웃풋 파일 닫기
	fclose(inputFile); //출력 이미지를 위한 input tmp 이미지 파일 닫기
	fclose(fp);//txt파일 닫기

	return 0; //main함수 종료
}//괄호닫기