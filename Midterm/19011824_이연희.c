#define _CRT_SECURE_NO_WARNINGS // �����
#include <windows.h> // ������ ���� ���α׷� ������� ����
#include <stdio.h> //stdio������� ����
#include <stdlib.h> // stdlib������� ����
#include <math.h> // math������� ����
/*
float cubic(int v1, int v2, int v3, int v4, float d, float a) {
	float result = ((-v1 + (3 * v2) - (3 * v3) + v4) * pow(d, 3)) + (((2 * v1) - (5 * v2) + (4 * v3) - v4) * pow(d, 2)) + (v3 - v1) * d + (2 * v2);
	result /= 2;
	if (result >= 255)
		result = 255;
	return result;
}*/
int smallnum(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8) { //8���� �� �߿��� ���� ���� ���� �ε����� ��ȯ�� �ִ� �Լ�
	int num[8], index[8], i, j, tmp; // 8���� ���� �ε����� ���� ������ ���� �迭 ����, �ݺ����� ���� i,j���� �ӽ÷� ���� ������ tmp ����
	num[0] = n1;num[1] = n2;num[2] = n3;num[3] = n4; //8���� ���� �迭�� ����
	num[4] = n5;num[5] = n6;num[6] = n7;num[7] = n8; //8���� ���� �迭�� ����
	for (i = 0;i < 8;i++) //8�� �ݺ�
		index[i] = i; //�ε����� �����
	for (i = 0;i < 7;i++) { //���� �ݺ�������
		for (j = i + 1;j < 8;j++) { //���� ������ ���
			if (num[i] > num[j]) { // �տ� �ִ� ���� �� ũ�ٸ�
				tmp = num[i];num[i] = num[j];num[j] = tmp; //�ٲ���
				tmp = index[i];index[i] = index[j];index[j] = tmp; //�ε����� ���� �ٲ���
			}//��ȣ�ݱ�
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
	return index[0]; //���� ���� ���� �ε��� ��ȯ
}//��ȣ�ݱ�
int main() {//�����Լ� ����
	BITMAPFILEHEADER bmpFile; //BITMAPFILEHEADER ����
	BITMAPINFOHEADER bmpInfo; //BITMAPINFOHEADER ����
	FILE *inputFile = NULL; // �� ������ �־��� FILE���� ����
	inputFile = fopen("AICenterY_128X128.bmp", "rb");// inputFile�� 128*128bmp ���������� ����
	fread(&bmpFile, sizeof(BITMAPFILEHEADER), 1, inputFile);// inputFile�� ����� ���Ϸκ��� BITMAPFILEHEADER 1���� �о� bmpFile������ ����
	fread(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, inputFile);// inputFile�� ����� ���Ϸκ��� BITMAPINFOHEADER 1���� �о� bmpFile������ ����
	int width = bmpInfo.biWidth; // width�� bmpInfo�� ��� biWidth����
	int height = bmpInfo.biHeight;// height�� bmpInfo�� ��� biHeight����
	int size = bmpInfo.biSizeImage; // size�� bmpInfo�� ��� biSizeImage����
	int bitCnt = bmpInfo.biBitCount;// bitCnt�� bmpInfo�� ��� biBitCount���� 
	int stride = (((bitCnt / 8)*width) + 3) / 4 * 4;// stride�� RGB�� �� ���� �� �ִ� ���� �־���
	unsigned char *inputImg = NULL, *Y1 = NULL; //128*128������ ������ inputImg�� Y1����
	inputImg = (unsigned char *)calloc(size, sizeof(unsigned char));// bmpInfo�� ���  size���� �Ҵ�
	Y1 = (unsigned char *)calloc(width*height, sizeof(unsigned char));// bmpInfo�� ���  width*height���� �Ҵ�
	fread(inputImg, sizeof(unsigned char), size, inputFile); // inputFile���� inputImg����

	int width2 = bmpInfo.biWidth * 4; // width2�� bmpInfo�� ��� biWidth���� 4��
	int height2 = bmpInfo.biHeight * 4;// height2�� bmpInfo�� ��� biHeight����
	int stride2 = (((bitCnt / 8)*width2) + 3) / 4 * 4; //stride2�� 
	int size2 = stride2 * height2;// size2��  stride2 * height2
	unsigned char *outputImg = NULL, *Y2 = NULL; //512������ ����� ���� ����
	outputImg = (unsigned char *)calloc(size2, sizeof(unsigned char)); //size2��ŭ �Ҵ�
	Y2 = (unsigned char *)calloc(width2*height2, sizeof(unsigned char)); //width2*height2��ŭ �Ҵ�
	int j, i; //�ݺ����� ���� j,i����

	for (j = 0;j < height;j++) { //128ũ���� ���̸�ŭ 
		for (i = 0;i < width;i++) { //128ũ���� �ʺ�ŭ 
			Y1[j*width + i] = inputImg[j*stride + 3 * i]; //Y�������� �迭�� ���
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
	//////////////////////------------���� �����丮 1��-----------------/////////////////////
	for (j = 0;j < height2;j++) { //512ũ���� ���� ��ŭ
		for (i = 0;i < width2;i++) { //512ũ���� ���� ��ŭ
			Y2[j*width2 + i] = Y1[(j / 4)*width + (i / 4)]; // Y������ ���� �迭�� 4�� ��� 128 -> 512
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
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
	unsigned char *Horizontal = NULL, *Vertic = NULL, *Edge = NULL; //����,����,��� �κ��� �迭 ����
	Horizontal = (unsigned char *)calloc(height2*width2, sizeof(unsigned char)); //height2*width2 ũ�� ��ŭ �Ҵ�
	Vertic = (unsigned char *)calloc(height2*width2, sizeof(unsigned char)); //height2*width2 ũ�� ��ŭ �Ҵ�
	Edge = (unsigned char *)calloc(height2*width2, sizeof(unsigned char)); //height2*width2 ũ�� ��ŭ �Ҵ�

	for (int j = 0;j < height2;j++) {//512 ���� ��ŭ �ݺ�
		for (int i = 0;i < width2;i++) {//512���� ��ŭ �ݺ�
			Horizontal[j*width2 + i] = 0;//���� 0���� �ʱ�ȭ
			Vertic[j*width2 + i] = 0;//���� 0���� �ʱ�ȭ
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�

	for (int j = 1;j < height2 - 1;j++) {//���� �� ���̸�ŭ �ݺ�
		for (int i = 1;i < width2 - 1;i++) { //���� �� �ʺ�ŭ �ݺ�
			if ((Y2[(j - 1)*width2 + i] - Y2[(j + 1)*width2 + i])*(Y2[(j - 1)*width2 + i] - Y2[(j + 1)*width2 + i]) >= 900) //���ʰ� �Ʒ����� ��谡 30�̻��̸�
				Horizontal[j*width2 + i] = 255;//���� �κ��� 255�� 
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�

	for (int j = 1;j < height2 - 1;j++) {//���� �� ���̸�ŭ �ݺ�
		for (int i = 1;i < width2 - 1;i++) { //���� �� �ʺ�ŭ �ݺ�
			if ((Y2[j*width2 + i - 1] - Y2[j*width2 + i + 1])*(Y2[j*width2 + i - 1] - Y2[j*width2 + i + 1]) >= 900) //���ʰ� �������� ��谡 30�̻��̸�
				Vertic[j*width2 + i] = 255;//���� �κ��� 255�� 
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�

	for (int j = 0;j < height2;j++) {//512���̸�ŭ �ݺ�
		for (int i = 0;i < width2;i++) {//512�ʺ�ŭ �ݺ�
			if (Horizontal[j*width2 + i] == 255 || Vertic[j*width2 + i] == 255)//�� �κ��� ������ ������ ���
				Edge[j*width2 + i] = 255;//���� ��迡 255
			else //�ƴϸ�
				Edge[j*width2 + i] = 0;//0�� ����
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
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
	//////////////////////------------ ���� �����丮 2��-----------------/////////////////////
	/*
	//-----------4���� ������ ó��-------------//
	j = 0;i = width2 - 1;
	Y2[j*width2 + i]=
		(Y2[j*width2 + i] * 4 + Y2[j*width2 + i - 1] * 2 + Y2[(j + 1)*width2 + i] * 2 + Y2[(j + 1)*width2 + i - 1]) / 9; // 4:2:2:1 �� ����
	j = height2 - 1;i = 0;
	Y2[j*width2 + i] =
		(Y2[j*width2 + i] * 4 + Y2[j*width2 + i + 1] * 2 + Y2[(j - 1)*width2 + i] * 2 + Y2[(j - 1)*width2 + i + 1]) / 9; // 4:2:2:1 �� ����
	j = height2 - 1;i = width2 - 1;
	Y2[j*width2 + i] =
		(Y2[j*width2 + i] * 4 + Y2[j*width2 + i - 1] * 2 + Y2[(j - 1)*width2 + i] * 2 + Y2[(j - 1)*width2 + i - 1]) / 9; // 3:2:2:1 �� ����

	//-----------4���� �𼭸� ó��-------------//
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

	//----�𼭸��� �������� �ƴ� �κ�-------//
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
	//////////////////////------------���� �����丮 3��-----------------/////////////////////
	for (j = 0;j < height2;j += 4) {//���̴� �ƴ� ��
		for (i = 2;i < width2;i += 4) //�ʺ� �κ��� �ƴ� ���� �߰� ��
			Y2[j*width2 + i] = (Y2[(j)*width2 + i - 2] + Y2[(j)*width2 + i + 2]) / 2; // �� ���� �ƴ� ���� ���
	}//��ȣ�ݱ�
	for (j = 0;j < height2;j += 4) { //���̴� �ƴ� ��
		for (i = 1;i < width2;i += 2) // �ƴ� ���� ������ ��
			Y2[j*width2 + i] = (Y2[(j)*width2 + i - 1] + Y2[(j)*width2 + i + 1]) / 2; //������ ������ �ƴ� 0.75,0.25
	}//��ȣ�ݱ�
	for (j = 2;j < height2;j += 4) { //���� �κ��� �ƴ� ���� �߰� ��
		for (i = 0;i < width2;i += 4) //�ʺ� �κ��� �ƴ� ��
			Y2[j*width2 + i] = (Y2[(j - 2)*width2 + i] + Y2[(j + 2)*width2 + i]) / 2; //�� ���� �ƴ� ���� ���
	}//��ȣ�ݱ�
	for (j = 1;j < height2;j += 2) {// �ƴ� ���� ������ ��
		for (i = 0;i < width2;i += 4)//�ʺ�� �ƴ� ��
			Y2[j*width2 + i] = (Y2[(j - 1)*width2 + i] + Y2[(j + 1)*width2 + i]) / 2;//������ ������ �ƴ� 0.75,0.25
	}//��ȣ�ݱ�
	for (j = 2;j < height2;j += 4) {// 4���� �߰�
		for (i = 2;i < width2;i += 4) //�ƴ� 4���� �߰�
			Y2[j*width2 + i] = (Y2[(j - 2)*width2 + i - 2] + Y2[(j + 2)*width2 + i - 2] + Y2[(j - 2)*width2 + i + 2] + Y2[(j + 2)*width2 + i + 2]) / 4; //�ƴ� 4���� ���
	}//��ȣ�ݱ�
	for (j = 1;j < height2;j += 2) { //Ȧ����° ��
		for (i = 2;i < width2;i += 4) //�ƴ� ���� �߰�
			Y2[j*width2 + i] = (Y2[(j - 1)*width2 + i] + Y2[(j + 1)*width2 + i]) / 2; //���Ʒ� ���� ���
	}//��ȣ�ݱ�
	for (j = 2;j < height2;j += 4) {//�ƴ� ���� �߰�
		for (i = 1;i < width2;i += 2)//Ȧ����°
			Y2[j*width2 + i] = (Y2[(j)*width2 + i - 1] + Y2[(j)*width2 + i + 1]) / 2; //�� �� ���� ���
	}//��ȣ�ݱ�
	for (j = 1;j < height2;j += 2) { //��������
		for (i = 1;i < width2;i += 2) { //������ ��
			Y2[j*width2 + i] = (Y2[(j - 1)*width2 + i - 1] + Y2[(j - 1)*width2 + i + 1] + Y2[(j - 1)*width2 + i] + Y2[(j)*width2 + i + 1] + //�ֺ����� ���
				Y2[(j)*width2 + i - 1] + Y2[(j + 1)*width2 + i + 1] + Y2[(j + 1)*width2 + i - 1] + Y2[(j + 1)*width2 + i]) / 8;// �ֺ����� ���
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
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
	//////////////////////------------���� �����丮 4��-----------------/////////////////////
	for (j = height2 - 3;j < height2;j += 1) { //������ ���κп� ����
		for (i = 0;i < width2;i++) //�ݺ��ؼ�
			Y2[j*width2 + i] = Y2[(j - 1)*width2 + i]; //�ƴ°� �� ����� ������ ��ü
	}//��ȣ�ݱ�
	for (j = 0;j < height2;j += 1) { //������ ������ �κп� ����
		for (i = width2 - 3;i < width2;i++) //�ݺ��ؼ� 
			Y2[j*width2 + i] = Y2[j*width2 + i - 1]; //�ƴ� �� �� ����� ������ ��ü
	}//��ȣ�ݱ�
	//////////////////////------------���� �����丮 5��-----------------/////////////////////

	int n1, n2, n3, n4, n5, n6, n7, n8, smalln, jj, ii; //���� ���̸� �̾Ƴ��� ���� ������� �ݺ����� ���� ���� ����
	for (j = 4;j < height2 - 4;j += 4) { // �ƴ� ������ ���κ� ���� �ݺ�
		for (i = 4;i < width2 - 4;i += 4) { // �ƴ� ������ ���κ� ���� �ݺ�
			if (Edge[j*width2 + i] == 255) { //���� �κ��� ���
				n1 = (Y2[j*width2 + i] - Y2[(j - 4)*width2 + i - 4])*(Y2[j*width2 + i] - Y2[(j - 4)*width2 + i - 4]); //���̱���-4 �ʺ���� -4
				n2 = (Y2[j*width2 + i] - Y2[(j - 4)*width2 + i + 4])*(Y2[j*width2 + i] - Y2[(j - 4)*width2 + i + 4]); //���̱���-4 �ʺ���� +4
				n3 = (Y2[j*width2 + i] - Y2[(j + 4)*width2 + i - 4])*(Y2[j*width2 + i] - Y2[(j + 4)*width2 + i - 4]); //���̱���+4 �ʺ���� -4
				n4 = (Y2[j*width2 + i] - Y2[(j + 4)*width2 + i + 4])*(Y2[j*width2 + i] - Y2[(j + 4)*width2 + i + 4]); //���̱���+4 �ʺ���� +4
				n5 = (Y2[j*width2 + i] - Y2[(j - 4)*width2 + i])*(Y2[j*width2 + i] - Y2[(j - 4)*width2 + i]); //���̱���-4 
				n6 = (Y2[j*width2 + i] - Y2[(j + 4)*width2 + i])*(Y2[j*width2 + i] - Y2[(j + 4)*width2 + i]); //���̱���+4 
				n7 = (Y2[j*width2 + i] - Y2[(j)*width2 + i - 4])*(Y2[j*width2 + i] - Y2[(j)*width2 + i - 4]); //�ʺ���� -4
				n8 = (Y2[j*width2 + i] - Y2[(j)*width2 + i + 4])*(Y2[j*width2 + i] - Y2[(j)*width2 + i + 4]); //�ʺ���� +4
				smalln = smallnum(n1, n2, n3, n4, n5, n6, n7, n8) + 1; //���̰� ���� ���� ���� �Լ��� ã�Ƴ�
				if ((smalln == 1) && (Edge[(j - 4)*width2 + i - 4] == 255) && (Y2[j*width2 + i] == Y2[(j - 4)*width2 + i - 4])) {//���̱���-4 �ʺ���� -4 �� ���̰� ���� ���� ��
					for (jj = j - 3, ii = i - 3;jj < j;jj++, ii++) // �� ������ ���� ����
						Y2[jj*width2 + ii] = (Y2[(j - 4)*width2 + i - 4] + Y2[jj*width2 + ii]) / 2; // �� ���� �ִ� �Ͱ� Y2[(j - 4)*width2 + i - 4] ���
				}//��ȣ�ݱ�
				else if ((smalln == 2) && (Edge[(j - 4)*width2 + i + 4] == 255) && (Y2[(j - 4)*width2 + i + 4] == Y2[j*width2 + i])) {//���̱���-4 �ʺ���� +4 �� ���̰� ���� ���� ��
					for (jj = j - 3, ii = i + 3;jj < j;jj++, ii--)// �� ������ ���� ����
						Y2[jj*width2 + ii] = (Y2[(j - 4)*width2 + i + 4] + Y2[jj*width2 + ii]) / 2;// �� ���� �ִ� �Ͱ� Y2[(j - 4)*width2 + i + 4] ���
				}//��ȣ�ݱ�
				else if ((smalln == 3) && (Edge[(j + 4)*width2 + i - 4] == 255) && (Y2[(j + 4)*width2 + i - 4] == Y2[j*width2 + i])) {//���̱���+4 �ʺ���� -4 �� ���̰� ���� ���� ��
					for (jj = j + 3, ii = i - 3;jj > j;jj--, ii++) // �� ������ ���� ����
						Y2[jj*width2 + ii] = (Y2[(j + 4)*width2 + i - 4] + Y2[jj*width2 + ii]) / 2;// �� ���� �ִ� �Ͱ� Y2[(j + 4)*width2 + i - 4] ���
				}//��ȣ�ݱ�
				else if ((smalln == 4) && (Edge[(j + 4)*width2 + i + 4] == 255) && (Y2[(j + 4)*width2 + i + 4] == Y2[j*width2 + i])) {//���̱���+4 �ʺ���� +4 �� ���̰� ���� ���� ��
					for (jj = j + 3, ii = i + 3;jj > j;jj--, ii--)// �� ������ ���� ����
						Y2[jj*width2 + ii] = (Y2[(j + 4)*width2 + i + 4] + Y2[jj*width2 + ii]) / 2;// �� ���� �ִ� �Ͱ� Y2[(j + 4)*width2 + i + 4] ���
				}//��ȣ�ݱ�
				else if ((smalln == 5) && (Edge[(j - 4)*width2 + i] == 255) && (Y2[(j - 4)*width2 + i] == Y2[j*width2 + i])) {//���̱���-4�� ���̰� ���� ���� ��
					for (jj = j - 3;jj < j;jj++) // �� ������ ���� ����
						Y2[jj*width2 + i] = (Y2[(j - 4)*width2 + i] + Y2[jj*width2 + i]) / 2;// �� ���� �ִ� �Ͱ� Y2[(j - 4)*width2 + i] ���
				}//��ȣ�ݱ�
				else if ((smalln == 6) && (Edge[(j + 4)*width2 + i] == 255) && (Y2[(j + 4)*width2 + i] == Y2[j*width2 + i])) {//���̱���+4�� ���̰� ���� ���� ��
					for (jj = j + 3;jj > j;jj--)// �� ������ ���� ����
						Y2[jj*width2 + i] = (Y2[(j + 4)*width2 + i] + Y2[jj*width2 + i]) / 2;// �� ���� �ִ� �Ͱ� Y2[(j - 4)*width2 + i] ���
				}//��ȣ�ݱ�
				else if ((smalln == 7) && (Edge[(j)*width2 + i - 4] == 255) && (Y2[(j)*width2 + i - 4] == Y2[j*width2 + i])) {//�ʺ���� -4 �� ���̰� ���� ���� ��
					for (ii = i - 3;ii < i;ii++)// �� ������ ���� ����
						Y2[j*width2 + ii] = (Y2[(j)*width2 + i - 4] + Y2[j*width2 + ii]) / 2;// �� ���� �ִ� �Ͱ� Y2[(j)*width2 + i - 4] ���
				}//��ȣ�ݱ�
				else if ((smalln == 8) && (Edge[(j)*width2 + i + 4] == 255) && (Y2[(j)*width2 + i + 4] == Y2[j*width2 + i])) {//�ʺ���� +4 �� ���̰� ���� ���� ��
					for (ii = i + 3;ii > i;ii--)// �� ������ ���� ����
						Y2[j*width2 + ii] = (Y2[(j)*width2 + i + 4] + Y2[j*width2 + i]) / 2;// �� ���� �ִ� �Ͱ� Y2[(j)*width2 + i + 4] ���
				}//��ȣ�ݱ�
			}//��ȣ�ݱ�
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�


	///////////////////////////////////////////////////////////////////
	for (j = 0;j < height2;j++) { // 512 ���̸�ŭ �ݺ�
		for (i = 0;i < width2;i++) { //512 �ʺ�ŭ �ݺ�
			outputImg[j*stride2 + 3 * i] = Y2[j*width2 + i]; //3���� RGB�� Y �־��ֱ�
			outputImg[j*stride2 + 3 * i + 1] = Y2[j*width2 + i]; //3���� RGB�� Y �־��ֱ�
			outputImg[j*stride2 + 3 * i + 2] = Y2[j*width2 + i]; //3���� RGB�� Y �־��ֱ�
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�


	FILE *outputFile = fopen("19011824_�̿���.bmp", "wb"); //19011824_�̿��� �� bmp������ �� ��
	bmpInfo.biWidth = width2; //bmpInfo�� biwidth �� 512�������� �����ֱ�
	bmpInfo.biHeight = height2; //bmpInfo�� biHeight �� 512�������� �����ֱ�
	bmpInfo.biSizeImage = size2; //bmpInfo�� biSizeImage �� 512�������� �����ֱ�
	bmpFile.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + size2; //bmpInfo�� bfSize �� 512�������� �����ֱ�
	fwrite(&bmpFile, sizeof(BITMAPFILEHEADER), 1, outputFile);// bmgFile ������ ����� BITMAPFILEHEADER 1���� outputFile�� ����� ���Ͽ� ����
	fwrite(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, outputFile);// bmgInfo ������ ����� BITMAPINFOHEADER 1���� outputFile�� ����� ���Ͽ� ����
	fwrite(outputImg, sizeof(unsigned char), size2, outputFile);// outputImg ������ ����� unsigned char��  size2�� outputFile�� ����� ���Ͽ� ����
	free(inputImg);//input�̹����� �Ҵ� ����
	free(outputImg);//output�̹����� �Ҵ� ����
	fclose(inputFile);//input���� �ݾ��ֱ�
	fclose(outputFile);//output���� �ݾ��ֱ�
	return 0;//�����Լ�����
}//��ȣ�ݱ�