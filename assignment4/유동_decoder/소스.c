#define _CRT_SECURE_NO_WARNINGS //�����
#include <windows.h> //������ ���� ���α׷� ������� ����
#include <stdio.h> // stdio.h ������� ����
#include <string.h> // string.h������� ����
#include <stdlib.h> // stdlib.h ������� ����

int change8(char *s) { //6bit ���ڿ��� �������� �������� �ٲٴ� �Լ�
	int k = 0; //return �� �ʱ�ȭ
	if (s[7] == '1') //1�̸�
		k += 1; //+1
	if (s[6] == '1') //1�̸�
		k += 2; //+2
	if (s[5] == '1') //1�̸�
		k += 4; //+1
	if (s[4] == '1') //1�̸�
		k += 8; //+2
	if (s[3] == '1') //1�̸�
		k += 16; //+4
	if (s[2] == '1') //1�̸�
		k += 32; //+8
	if (s[1] == '1') //1�̸�
		k += 64; //+16
	if (s[0] == '1') //1�̸�
		k += 128; //+32
	return k; //�� ���� ��ȯ
} //��ȣ�ݱ�
int change(int k) {
	int i, num = 1;
	for (i = 1;i < k;i++) {
		num = num * 2;

	}
	return num;
}
int main() {//�����Լ� ����
	BITMAPFILEHEADER bmpFile;//BITMAPFILEHEADER ����
	BITMAPINFOHEADER bmpInfo;//BITMAPINFOHEADER ����
	FILE *inputFile = NULL;// �� ������ �־��� FILE���� ����
	FILE *fp = fopen("bitstream.txt", "r"); //txt������ �б���� open
	unsigned char *outputImg = NULL, *Y = NULL; //����̹����� Y���� ���� ���� ����
	inputFile = fopen("tmp.bmp", "rb"); //����̹����� ���� ������� 512*512 bmp����
	fread(&bmpFile, sizeof(BITMAPFILEHEADER), 1, inputFile); // inputFile�� ����� ���Ϸκ��� BITMAPFILEHEADER 1���� �о� bmpFile������ ����
	fread(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, inputFile);// inputFile�� ����� ���Ϸκ��� BITMAPINFOHEADER 1���� �о� bmpFile������ ����
	int width = bmpInfo.biWidth;// width�� bmpInfo�� ��� biWidth����
	int height = bmpInfo.biHeight;// height�� bmpInfo�� ��� biHeight����
	int size = bmpInfo.biSizeImage;// size�� bmpInfo�� ��� biSizeImage����
	int bitCnt = bmpInfo.biBitCount;// bitCnt�� bmpInfo�� ��� biBitCount���� 
	int stride = (((bitCnt / 8)*width) + 3) / 4 * 4;// stride�� RGB�� �� ���� �� �ִ� ���� �־���
	outputImg = (unsigned char *)calloc(size, sizeof(unsigned char)); //size��ŭ �Ҵ�
	Y = (unsigned char *)calloc(height*width, sizeof(unsigned char)); //width*height��ŭ �Ҵ�


	//---------�ʿ��� ���� ����------------//
	char s2[2] = { 0, }; // 6bit�� ���� ���ڿ� ����
	char s8[9] = { 0, };
	int i, j, num,k=0; // �ݺ����� ���� i,j����
	int d = 0;

	for (j = 0;j < height;j ++) { //���̿� �ʺ� �κ��� �� ��
		for (i = 0;i < width;i++) { //¦�� �κ� ���� ����Ǿ�������
			
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
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�

	//-----------------------------------------------------------------//


	for (j = 0;j < height;j++) {
		for (i = 0;i < width;i++) { 
			outputImg[j*stride + 3 * i] = Y[j*height + i];//3���� RGB�� Y �־��ֱ�
			outputImg[j*stride + 3 * i + 1] = Y[j*height + i];//3���� RGB�� Y �־��ֱ�
			outputImg[j*stride + 3 * i + 2] = Y[j*height + i];//3���� RGB�� Y �־��ֱ�
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�


	FILE *outFile = fopen("light.bmp", "wb"); //������ ���� bmp���Ϸ� �� ��
	fwrite(&bmpFile, sizeof(BITMAPFILEHEADER), 1, outFile); // bmgFile ������ ����� BITMAPFILEHEADER 1���� outputFile�� ����� ���Ͽ� ����
	fwrite(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, outFile); // bmgInfo ������ ����� BITMAPINFOHEADER 1���� outputFile�� ����� ���Ͽ� ����
	fwrite(outputImg, sizeof(unsigned char), size, outFile);// outputImg ������ ����� unsigned char��  size�� outputFile�� ����� ���Ͽ� ����
	free(outputImg); //�ƿ�ǲ�̹����� �Ҵ� ����
	fclose(outFile); //�ƿ�ǲ ���� �ݱ�
	fclose(inputFile); //��� �̹����� ���� input tmp �̹��� ���� �ݱ�
	fclose(fp);//txt���� �ݱ�

	return 0; //main�Լ� ����
}//��ȣ�ݱ�