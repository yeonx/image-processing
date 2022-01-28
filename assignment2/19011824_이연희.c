#define _CRT_SECURE_NO_WARNINGS // �����
#include <windows.h> // ������ ���� ���α׷� ������� ����
#include <stdio.h> //stdio������� ����
#include <stdlib.h> // stdlib������� ����
int med(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9) { // �߰����� ���ϱ� ���� �Լ�
	int n[9] = { 0 }, i, j, tmp;  // 9�� �迭��, �ݺ����� ���� i,j ���� �׸��� ������ ���� tmp����
	n[0] = n1; n[1] = n2; n[2] = n3;n[3] = n4; n[4] = n5; n[5] = n6;n[6] = n7; n[7] = n8; n[8] = n9; // �Է¹��� �� �迭�� �ֱ�
	for (i = 0;i < 9;i++) { // ������ ���ֱ� ���� �ݺ��� ��������
		for (j = 0;j < 8;j++) { // ������ ���ֱ� ���� ���� �ݺ���
			if (n[j] > n[j + 1]) { // �տ� �ִ� ���� �� ũ��
				tmp = n[j]; // tmp�� j��° �� �ְ�
				n[j] = n[j + 1]; // j��°�� j+1��°�� �ְ�
				n[j + 1] = tmp; // j+1��°�� tmp�� �־��� (��ȯ �Ϸ�)
			}//if�� ��ȣ�ݱ�
		}//for�� ��ȣ�ݱ�
	}//���� for�� ��ȣ�ݱ�
	return n[4]; //�߰��� ��ȯ
}//��ȣ�ݱ�
int med_vertex(int n1, int n2, int n3, int n4) { // ������ �κ��� �߰����� ���ϱ� ���� �Լ�
	int n[4] = { 0 }, i, j, tmp; // 4���� �迭��, �ݺ����� ���� i,j ���� �׸��� ������ ���� tmp����
	n[0] = n1;n[1] = n2;n[2] = n3;n[3] = n4; // �Է¹��� �� �迭�� �ֱ�
	for (i = 0;i < 4;i++) { //������ ���ֱ� ���� �ݺ���
		for (j = 0;j < 3;j++) { //������ ���ֱ� ���� �ݺ���
			if (n[j] > n[j + 1]) { //�տ� �ִ� ���� �� ũ�� �ٲ���
				tmp = n[j]; //tmp�� j��° �ְ�
				n[j] = n[j + 1]; //j��°�� j+1��° �ְ� 
				n[j + 1] = tmp; //j+1��°�� 
			}//��ȣ�ݱ�
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
	if (n[0] == 0)//�� ���� ���� 0�� �� �װ��� ������ 3������ �߰����� ����
		return n[2]; //�迭�� 3��°�� �߰�����
	else // �� ���� ���� 255�̸� �װ��� ������ 3������ �߰����� ���
		return n[1]; // �迭���� 2��°�� �߰�����
}//��ȣ�ݱ�
int med_edge(int n1, int n2, int n3, int n4, int n5, int n6) { // �𼭸� �κ��� �߰����� ���ϱ� ���� �Լ�
	int n[6] = { 0 }, i, j, tmp; // 6���� �迭�� �ݺ����� ���� i,j ���� �׸��� ������ ���� tmp ����
	n[0] = n1;n[1] = n2;n[2] = n3; n[3] = n4;n[4] = n5;n[5] = n6; // �Է¹��� �� �迭�� �ֱ�
	for (i = 0;i < 6;i++) { //������ ���ֱ� ���� �ݺ���
		for (j = 0;j < 5;j++) { //������ ���ֱ� ���� �ݺ���
			if (n[j] > n[j + 1]) { // ���� ���� �� ũ�� ��ȯ
				tmp = n[j]; // tmp�� j��°�� �ְ�
				n[j] = n[j + 1]; // j��°�� j+1����
				n[j + 1] = tmp; // �ٽ� j+1��°�� tmp�� �ִ� ���� �־���
			}//��ȣ�ݱ�
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
	if (n[0] == 0) // �迭�� ù��°�� 0�̸� �� ���� ���� �߰��� ���
		return n[3]; // 4��°�� �߰�����
	else // ������ ���� 255�� �� ���� ���� �߰��� ���
		return n[2]; // 3��°�� �߰�����
}//��ȣ�ݱ�
int main() { //�����Լ� 
	BITMAPFILEHEADER bmpFile; //BITMAPFILEHEADER ����
	BITMAPINFOHEADER bmpInfo; //BITMAPINFOHEADER ����
	FILE *inputFile = NULL; // �� ������ �־��� FILE���� ����
	inputFile = fopen("free.bmp", "rb"); // inputFile�� ����� �ִ� bmp ���������� ����
	fread(&bmpFile, sizeof(BITMAPFILEHEADER), 1, inputFile); // inputFile�� ����� ���Ϸκ��� BITMAPFILEHEADER 1���� �о� bmpFile������ ����
	fread(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, inputFile); // inputFile�� ����� ���Ϸκ��� BITMAPINFOHEADER 1���� �о� bmpInfo������ ����
	int width = bmpInfo.biWidth; // width�� bmpInfo�� ��� biWidth����
	int height = bmpInfo.biHeight; // height�� bmpInfo�� ��� biHeight����
	int size = bmpInfo.biSizeImage; // size�� bmpInfo�� ��� biSizeImage����
	int bitCnt = bmpInfo.biBitCount; // bitCnt�� bmpInfo�� ��� biBitCount���� 
	
	int stride = (((bitCnt / 8)*width) + 3) / 4 * 4; // stride�� RGB�� �� ���� �� �ִ� ���� �־���
	printf("W: %d(%d)\nH: %d\nS: %d\nD: %d\n", width, stride, height, size, bitCnt);

	unsigned char *inputImg = NULL, *outputImg = NULL; // ���� bmp������ �ִ� ������ output�� ���� ���� ����
	inputImg = (unsigned char *)calloc(size, sizeof(unsigned char)); // bmpInfo�� ���  size���� �Ҵ�
	outputImg = (unsigned char *)calloc(size, sizeof(unsigned char)); // bmpInfo�� ���  size���� �Ҵ�
	unsigned char tmp;// �ӽ÷� ���� �־� �� ����
	fread(inputImg, sizeof(unsigned char), size, inputFile); // inputFile�� ����� ���Ϸκ��� unsigned char�� size���� �о� inputImg������ ����


	int i, j;// ������ for���� ���� �� �������� �� �Ŷ� �������ֱ�

	//---------�𼭸��� �������� �ϳ��ϳ� ó��-----------------//

	for (j = 1;j < height - 1;j++) { // �𼭸��� �������� ������ �κ��� ó���ϱ� ����
		for (i = 1;i < width - 1;i++) { // ���̶� �� 1 ���� ���� ������ ���� ó��
			if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) { // ����� �ִ� �̹����� ���� �ش����� ����, �� ���� ���� ���� ��� (salt-and-pepper)
				inputImg[j*stride + 3 * i] = med(inputImg[(j - 1)*stride + 3 * (i - 1)], inputImg[(j - 1)*stride + 3 * i], inputImg[(j - 1)*stride + 3 * (i + 1)], // 9������ �� med�Լ��� ȣ���� 
					inputImg[j*stride + 3 * (i - 1)], inputImg[j*stride + 3 * i], inputImg[j*stride + 3 * (i + 1)], // �߰������� �ش����� ����
					inputImg[(j + 1)*stride + 3 * (i - 1)], inputImg[(j + 1)*stride + 3 * i], inputImg[(j + 1)*stride + 3 * (i + 1)]); // ó���� �ֱ�
				outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó�� (RGB 3������ �� �־��ֱ�)
				outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i+1]; //output�̹����� �߰����� �־��� ������ ó��
				outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i+2]; //output�̹����� �߰����� �־��� ������ ó��
			}//��ȣ�ݱ�
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�

	//-----------4���� ������ ó��-------------//

	j = 0;i = 0; // height=0, width=0 �κ� ������
	if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) { //�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
		inputImg[j*stride + 3 * i] = med_vertex(inputImg[j*stride + 3 * i], inputImg[j*stride + 3 * (i + 1)], // med_vertex�� �������� ���� ���� �̵�� ���͸�
			inputImg[(j + 1)*stride + 3 * i], inputImg[(j + 1)*stride + 3 * (i + 1)]); // �ش� ��ġ�� �ֺ����� ���͸�����
		outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó�� (RGB 3������ �� �־��ֱ�)
		outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i + 1]; //output�̹����� �߰����� �־��� ������ ó��
		outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i + 2]; //output�̹����� �߰����� �־��� ������ ó��
	} //��ȣ�ݱ�
	else { // �ش����� ���� ���� ��
		tmp = //Gaussian  filter�� ������ �ֺ����� �� ���� ����ġ�� ���� �� ����
			(inputImg[j*stride + 3 * i] *4 + inputImg[j*stride + 3 * (i+1)]*2 + inputImg[(j + 1)*stride + 3 * i]*2 + inputImg[(j + 1)*stride + 3 * (i + 1)])/9; // 4:2:2:1 �� ����
		outputImg[j*stride + 3 * i] = tmp; //output�̹����� tmp�� ����� �־��� (RGB 3������ �� �־��ֱ�)
		outputImg[j*stride + 3 * i + 1] = tmp; //output�̹����� tmp�� ����� �־���
		outputImg[j*stride + 3 * i + 2] = tmp; //output�̹����� tmp�� ����� �־���
	}//��ȣ�ݱ�
	j = 0;i = width - 1; // height=0, width �κ� ������
	if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) { //�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
		inputImg[j*stride + 3 * i] = med_vertex(inputImg[j*stride + 3 * i], inputImg[j*stride + 3 * (i - 1)], // med_vertex�� �������� ���� ���� �̵�� ���͸�
			inputImg[(j + 1)*stride + 3 * i], inputImg[(j + 1)*stride + 3 * (i - 1)]); // �ش� ��ġ�� �ֺ����� ���͸�����
		outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó�� (RGB 3������ �� �־��ֱ�)
		outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i + 1]; //output�̹����� �߰����� �־��� ������ ó��
		outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i + 2]; //output�̹����� �߰����� �־��� ������ ó��
	} //��ȣ�ݱ�
	else { // �ش����� ���� ���� ��
		tmp = //Gaussian tmp�� ������ �ֺ����� �� ���� ����ġ�� ���� �� ����
			(inputImg[j*stride + 3 * i] * 4 + inputImg[j*stride + 3 * (i - 1)] *2 + inputImg[(j + 1)*stride + 3 * i]*2 + inputImg[(j + 1)*stride + 3 * (i - 1)] )/9; // 4:2:2:1 �� ����
		outputImg[j*stride + 3 * i] = tmp; //output�̹����� tmp�� ����� �־��� (RGB 3������ �� �־��ֱ�)
		outputImg[j*stride + 3 * i + 1] = tmp; //output�̹����� tmp�� ����� �־���
		outputImg[j*stride + 3 * i + 2] = tmp; //output�̹����� tmp�� ����� �־���
	}//��ȣ�ݱ�
	j = height - 1;i = 0; // height ���κ�, width=0 �κ� ������
	if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) { //�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
		inputImg[j*stride + 3 * i] = med_vertex(inputImg[j*stride + 3 * i], inputImg[j*stride + 3 * (i + 1)], // med_vertex�� �������� ���� ���� �̵�� ���͸�
			inputImg[(j - 1)*stride + 3 * i], inputImg[(j - 1)*stride + 3 * (i + 1)]); // �ش� ��ġ�� �ֺ����� ���͸�����
		outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó�� (RGB 3������ �� �־��ֱ�)
		outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i + 1]; //output�̹����� �߰����� �־��� ������ ó��
		outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i + 2]; //output�̹����� �߰����� �־��� ������ ó��
	} //��ȣ�ݱ�
	else { // �ش����� ���� ���� ��
		tmp = //Gaussian  filter�� ������ �ֺ����� �� ���� ����ġ�� ���� �� ����
			(inputImg[j*stride + 3 * i] * 4 + inputImg[j*stride + 3 * (i + 1)] *2 + inputImg[(j - 1)*stride + 3 * i] *2 + inputImg[(j - 1)*stride + 3 * (i + 1)]) / 9; // 4:2:2:1 �� ����
		outputImg[j*stride + 3 * i] = tmp; //output�̹����� tmp�� ����� �־��� (RGB 3������ �� �־��ֱ�)
		outputImg[j*stride + 3 * i + 1] = tmp; //output�̹����� tmp�� ����� �־���
		outputImg[j*stride + 3 * i + 2] = tmp; //output�̹����� tmp�� ����� �־���
	}//��ȣ�ݱ�
	j = height - 1;i = width - 1; // height�� width���κ� ������
	if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) { //�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
		inputImg[j*stride + 3 * i] = med_vertex(inputImg[j*stride + 3 * i], inputImg[j*stride + 3 * (i - 1)], // med_vertex�� �������� ���� ���� �̵�� ���͸�
			inputImg[(j - 1)*stride + 3 * i], inputImg[(j - 1)*stride + 3 * (i - 1)]); // �ش� ��ġ�� �ֺ����� ���͸�����
		outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó�� (RGB 3������ �� �־��ֱ�)
		outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i + 1]; //output�̹����� �߰����� �־��� ������ ó��
		outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i + 2]; //output�̹����� �߰����� �־��� ������ ó��
	} //��ȣ�ݱ�
	else { // �ش����� ���� ���� ��
		tmp = //Gaussian  filter�� ������ �ֺ����� �� ���� ����ġ�� ���� �� ����
			(inputImg[j*stride + 3 * i] * 4 + inputImg[j*stride + 3 * (i - 1)]*2 + inputImg[(j - 1)*stride + 3 * i] *2 + inputImg[(j - 1)*stride + 3 * (i - 1)])/9; // 3:2:2:1 �� ����
		outputImg[j*stride + 3 * i] = tmp; //output�̹����� tmp�� ����� �־��� (RGB 3������ �� �־��ֱ�)
		outputImg[j*stride + 3 * i + 1] = tmp; //output�̹����� tmp�� ����� �־���
		outputImg[j*stride + 3 * i + 2] = tmp; //output�̹����� tmp�� ����� �־���
	}//��ȣ�ݱ�

	//-----------4���� �𼭸� ó��-------------//
	j = 0; //heigh=0�� �𼭸� ó��
	for (int i = 1;i < width - 1;i++) {// ���� �ƴ� �κ��� ��
		if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) { //�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
			inputImg[j*stride + 3 * i] = med_edge(inputImg[j*stride + 3 * (i - 1)] , inputImg[j*stride + 3 * i] ,inputImg[j*stride + 3 * (i + 1)] , // med_edge�Լ��� �𼭸� �κ��� �߰����� ã���ִ� �Լ�
				inputImg[(j + 1)*stride + 3 * (i - 1)] , inputImg[(j + 1)*stride + 3 * i] , inputImg[(j + 1)*stride + 3 * (i + 1)]); // �ڽ��� ������ 6������ ��� �־���
			outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó�� (RGB 3������ �� �־��ֱ�)
			outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó��
			outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó��
		}//��ȣ�ݱ�
		else { // �ش����� ���� ���� ��
			tmp = // Gaussian  filter�� ������ �ֺ����� �� ���� ����ġ�� ���� �� ����
				(inputImg[j*stride + 3 * (i - 1)] * 2 + inputImg[j*stride + 3 * i] * 4 + inputImg[j*stride + 3 * (i + 1)] * 2 + // 6���� ������ 4:2:2:2:1:1 �����ְ�
				inputImg[(j + 1)*stride + 3 * (i - 1)] + inputImg[(j + 1)*stride + 3 * i] * 2 + inputImg[(j + 1)*stride + 3 * (i + 1)]) / 12; // 12�� ������
			outputImg[j*stride + 3 * i] = tmp; //output�̹����� tmp�� ����� �־��� (RGB 3������ �� �־��ֱ�)
			outputImg[j*stride + 3 * i + 1] = tmp; //output�̹����� tmp�� ����� �־���
			outputImg[j*stride + 3 * i + 2] = tmp; //output�̹����� tmp�� ����� �־���
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
	j = height-1; // height�� ���κ� �� 0�� �ƴ� �𼭸� ó��
	for (int i = 1;i < width - 1;i++) { //���� �ƴ� �κ��� ��
		if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) {//�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
			inputImg[j*stride + 3 * i] = med_edge(inputImg[(j - 1)*stride + 3 * (i - 1)], inputImg[(j-1)*stride + 3 * i], inputImg[(j - 1)*stride + 3 * (i + 1)], // med_edge�Լ��� �𼭸� �κ��� �߰����� ã���ִ� �Լ�
				inputImg[j*stride + 3 * (i - 1)], inputImg[j*stride + 3 * i], inputImg[j*stride + 3 * (i + 1)]); // �ڽ��� ������ 6������ ��� �־���
			outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó�� (RGB 3������ �� �־��ֱ�)
			outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó��
			outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó��
		}//��ȣ�ݱ�
		else { // �ش����� ���� ���� ��
			tmp = (inputImg[(j - 1)*stride + 3 * (i - 1)] + inputImg[(j - 1)*stride + 3 * i] * 2 + inputImg[(j - 1)*stride + 3 * (i + 1)] + // 6���� ������ 4:2:2:2:1:1 �����ְ�
				inputImg[j*stride + 3 * (i - 1)] * 2 + inputImg[j*stride + 3 * i] * 4 + inputImg[j*stride + 3 * (i + 1)] * 2) / 12; //12�� ������
			outputImg[j*stride + 3 * i] = tmp; //output�̹����� tmp�� ����� �־��� (RGB 3������ �� �־��ֱ�)
			outputImg[j*stride + 3 * i + 1] = tmp; //output�̹����� tmp�� ����� �־���
			outputImg[j*stride + 3 * i + 2] = tmp; //output�̹����� tmp�� ����� �־���
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
	i = 0; // ������ width=0�� �κ��� ó��
	for (j = 1;j < height - 1;j++) { // ���κ��� �ƴ� ���� �κ�
		if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) {//�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
			inputImg[j*stride +3* i] = med_edge(inputImg[(j-1)*stride + 3 * i], inputImg[(j-1)*stride + 3 * (i+1)], inputImg[j*stride + 3 * i ], // med_edge�Լ��� �𼭸� �κ��� �߰����� ã���ִ� �Լ�
				inputImg[j*stride + 3 * (i + 1)], inputImg[(j + 1)*stride + 3 * i], inputImg[(j + 1)*stride + 3 * (i + 1)]); // �ڽ��� ������ 6������ ��� �־���
			outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó�� (RGB 3������ �� �־��ֱ�)
			outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó��
			outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó��
		}//��ȣ�ݱ�
		else { // �ش����� ���� ���� ��
			tmp = // Gaussian  filter�� ������ �ֺ����� �� ���� ����ġ�� ���� �� ����
				(inputImg[(j - 1)*stride] * 2 + inputImg[(j - 1)*stride + 3] + inputImg[j*stride] * 4 + // 6���� ������ 4:2:2:2:1:1 �����ְ�
					inputImg[j*stride + 3] * 2 + inputImg[(j + 1)*stride] * 2 + inputImg[(j + 1)*stride + 3]) / 12; //12�� ������
			outputImg[j*stride + 3 * i] = tmp; //output�̹����� tmp�� ����� �־��� (RGB 3������ �� �־��ֱ�)
			outputImg[j*stride + 3 * i + 1] = tmp; //output�̹����� tmp�� ����� �־���
			outputImg[j*stride + 3 * i + 2] = tmp; //output�̹����� tmp�� ����� �־���
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
	i = width-1; //������ width�� 0�� �ƴ� �ݴ��� �� �κ��� ó��
	for (j = 1;j < height - 1;j++) { // ���κ��� �ƴ� ���� �κ�
		if (inputImg[j*stride + 3 * i] == 0 || inputImg[j*stride + 3 * i] == 255) {//�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
			inputImg[j*stride + 3 * i] = med_edge(inputImg[(j-1)*stride + 3 * (i - 1)], inputImg[(j-1)*stride + 3 * i], inputImg[j*stride + 3 * (i - 1)], // med_edge�Լ��� �𼭸� �κ��� �߰����� ã���ִ� �Լ�
				inputImg[j*stride + 3 * i], inputImg[(j + 1)*stride + 3 * (i-1)], inputImg[(j + 1)*stride + 3 * i]); // �ڽ��� ������ 6������ ��� �־���
			outputImg[j*stride + 3 * i] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó�� (RGB 3������ �� �־��ֱ�)
			outputImg[j*stride + 3 * i + 1] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó��
			outputImg[j*stride + 3 * i + 2] = inputImg[j*stride + 3 * i]; //output�̹����� �߰����� �־��� ������ ó��
		}//��ȣ�ݱ�
		else { // �ش����� ���� ���� ��
			tmp = // Gaussian  filter�� ������ �ֺ����� �� ���� ����ġ�� ���� �� ����
				(inputImg[(j - 1)*stride + 3 * (i - 1)] + inputImg[(j - 1)*stride + 3 * i] * 2 + inputImg[j*stride + 3 * (i - 1)] * 2 + // 6���� ������ 4:2:2:2:1:1 �����ְ�
					inputImg[j*stride + 3 * i] * 4 + inputImg[(j + 1)*stride + 3 * (i - 1)] + inputImg[(j + 1)*stride + 3 * i] * 2) / 12; // 12�� ������
			outputImg[j*stride + 3 * i] = tmp; //output�̹����� tmp�� ����� �־��� (RGB 3������ �� �־��ֱ�)
			outputImg[j*stride + 3 * i + 1] = tmp; //output�̹����� tmp�� ����� �־���
			outputImg[j*stride + 3 * i + 2] = tmp; //output�̹����� tmp�� ����� �־���
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
	
	//----�𼭸��� �������� �ƴ� �κ�-------//
	for (j = 1;j < height - 1;j++) { // �𼭸��� �ƴϰ� �������� �ƴ� �κ��� ���� �κ� ó��
		for (i = 1;i < width - 1;i++) { //�𼭸��� �ƴϰ� �������� �ƴ� �κ��� �� �κ� ó��
			if (inputImg[j*stride + 3 * i + 0] != 0 && inputImg[j*stride + 3 * i + 0] != 255) { //salt-and-pepper �� ��찡 �ƴ� ���
				tmp =// Gaussian filter�� �������
					(inputImg[(j - 1)*stride + 3 * (i - 1)] * 1 / 16 + inputImg[(j - 1)*stride + 3 * i] * 1 / 8 + inputImg[(j - 1)*stride + 3 * (i + 1)] * 1 / 16 + //9������ ������
					inputImg[j*stride + 3 * (i - 1)] * 1 / 8 + inputImg[j*stride + 3 * i] * 1 / 4 + inputImg[j*stride + 3 * (i + 1)] * 1 / 8 + // 4:2:2:2:2:1:1:1:1
					inputImg[(j + 1)*stride + 3 * (i - 1)] * 1 / 16 + inputImg[(j + 1)*stride + 3 * i] * 1 / 8 + inputImg[(j + 1)*stride + 3 * (i + 1)] * 1 / 16); //16���� ���� ������
				outputImg[j*stride + 3 * i] = tmp; //output�̹����� tmp�� ����� �־��� (RGB 3������ �� �־��ֱ�)
				outputImg[j*stride + 3 * i + 1] = tmp; //output�̹����� tmp�� ����� �־���
				outputImg[j*stride + 3 * i + 2] = tmp; //output�̹����� tmp�� ����� �־���
			}//��ȣ�ݱ�
			
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
	//----------�е��� ���� ver-----------//
	/*
	unsigned char *filter=NULL;//�е��� ������ ���� ���� ����
	filter = (unsigned char *)calloc((height + 2)*(width + 2), sizeof(unsigned char)); //���̿� ���̰� +2��ŭ �� ū �е��� ������ ���� �Ҵ�
	for (j = 0;j < height + 2;j++) { // �е��� �����ؼ� filter�� �־��־����
		for (i = 0;i < width + 2;i++) { // �̹����� ���̿� ���� +2��ŭ�� 
			if (j == 0) { //height�� 0�� ���
				if (i == 0) { // �� �߿����� ���� 0�� ���
					if (inputImg[(j + 1)*stride + 3 * (i + 1)] == 0 || inputImg[(j + 1)*stride + 3 * (i + 1)] == 255) //�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
						filter[j*width + i] = inputImg[(j + 2)*stride + 3 * (i + 2)]; //�ٸ� �ֺ��� ���� filter�� �־���
					else //�̹����� �ش����� �����̳� �� ���� ���� ���� ���� ���
						filter[j*width + i] = inputImg[(j + 1)*stride + 3 * (i + 1)]; // �� ���� filter�� �־���
				}//��ȣ�ݱ�
				else if (i == width - 1) //�� �߿��� ���� �� ���� ���
					if (inputImg[(j + 1)*stride + 3 * (i - 1)] == 0 || inputImg[(j + 1)*stride + 3 * (i - 1)] == 255) //�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
						filter[j*width + i] = inputImg[(j + 2)*stride + 3 * (i - 2)]; //�ٸ� �ֺ��� ���� filter�� �־���
					else //�̹����� �ش����� �����̳� �� ���� ���� ���� ���� ���
						filter[j*width + i] = inputImg[(j + 1)*stride + 3 * (i - 1)]; // �� ���� filter�� �־���

				else { // ������ �𼭸� �κ��� ��
					if (inputImg[(j + 1)*stride + 3 * i] == 0 || inputImg[(j + 1)*stride + 3 * i] == 255) //�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
						filter[j*width + i] = inputImg[(j + 2)*stride + 3 * i]; //�ٸ� �ֺ��� ���� filter�� �־���
					else //�̹����� �ش����� �����̳� �� ���� ���� ���� ���� ���
						filter[j*width + i] = inputImg[(j + 1)*stride + 3 * i]; // �� ���� filter�� �־���
				}//��ȣ�ݱ�
			}//��ȣ�ݱ�
			else if (j == height - 1) { // ���̰� 0�� �ݴ��� ���� ���
				if (i == 0) { // ���߿��� ���� 0
					if (inputImg[(j - 1)*stride + 3 * (i + 1)] == 0 || inputImg[(j - 1)*stride + 3 * (i + 1)] == 255)  //�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
						filter[j*width + i] = inputImg[(j - 2)*stride + 3 * (i + 2)]; //�ٸ� �ֺ��� ���� filter�� �־���
					else //�̹����� �ش����� �����̳� �� ���� ���� ���� ���� ���
						filter[j*width + i] = inputImg[(j - 1)*stride + 3 * (i + 1)]; // �� ���� filter�� �־���
				}//��ȣ�ݱ�

				else if (i == width - 1) { // �� �߿��� ���� 0�� �ݴ��� ��
					if (inputImg[(j - 1)*stride + 3 * (i - 1)] == 0 || inputImg[(j - 1)*stride + 3 * (i - 1)] == 255) //�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
						filter[j*width + i] = inputImg[(j - 2)*stride + 3 * (i - 2)]; //�ٸ� �ֺ��� ���� filter�� �־���

					else //�̹����� �ش����� �����̳� �� ���� ���� ���� ���� ���
						filter[j*width + i] = inputImg[(j - 1)*stride + 3 * (i - 1)]; // �� ���� filter�� �־���
				}//��ȣ�ݱ�

				else { //������ �𼭸� �κ��� ��
					if (inputImg[(j - 1)*stride + 3 * i] == 0 || inputImg[(j - 1)*stride + 3 * i] == 255) //�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
						filter[j*width + i] = inputImg[(j - 2)*stride + 3 * i]; //�ٸ� �ֺ��� ���� filter�� �־���
					else //�̹����� �ش����� �����̳� �� ���� ���� ���� ���� ��� 
						filter[j*width + i] = inputImg[(j - 1)*stride + 3 * i]; // �� ���� filter�� �־���
				}//��ȣ�ݱ�
			}//��ȣ�ݱ�
			else if (i == 0) { //���� 0�� ���
				if (inputImg[j*stride + 3 * (i + 1)] == 0 || inputImg[j*stride + 3 * (i + 1)] == 255) //�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
					filter[j*width + i] = inputImg[j*stride + 3 * (i + 2)]; //�ٸ� �ֺ��� ���� filter�� �־���
				else //�̹����� �ش����� �����̳� �� ���� ���� ���� ���� ���
					filter[j*width + i] = inputImg[j*stride + 3 * (i + 1)]; // �� ���� filter�� �־���
			}//��ȣ�ݱ�

			else if (i == width - 1) { //���� 0�� �ƴ� �ݴ��� �κ� ���� ���
				if (inputImg[j*stride + 3 * (i - 1)] == 0 || inputImg[j*stride + 3 * (i - 1)] == 255) //�̹����� �ش����� �����̳� �� ���� ���� ���� �� (salt-and-pepper)
					filter[j*width + i] = inputImg[j*stride + 3 * (i - 2)]; //�ٸ� �ֺ��� ���� filter�� �־���
				else //�̹����� �ش����� �����̳� �� ���� ���� ���� ���� ���
					filter[j*width + i] = inputImg[j*stride + 3 * (i - 1)]; // �� ���� filter�� �־���
			}//��ȣ�ݱ�
			else { // �е� �κ��� �ƴ� ����
				filter[j*width + i] = inputImg[(j - 1)*stride + 3 * (i - 1)]; // input�̹��� �κ��� �״�� �־���
			}//��ȣ�ݱ�
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
	for (j = 1;j < height + 1;j++) { //�е� ���� �κп� ����
		for (i = 1;i < width + 1;i++) { // ���̿� ���� (�̹��� �κп� ����)
			if (filter[j*width + i] == 0 || filter[j*width + i] == 255) { // ����� �ִ� �̹����� ���� �ش����� ����, �� ���� ���� ���� ��� (salt-and-pepper)
				filter[j*width + i] = med(filter[(j - 1)*width + (i - 1)], filter[(j - 1)*width + i], filter[(j - 1)*width + (i + 1)], // 9������ �� med�Լ��� ȣ���� 
					filter[j*width + (i - 1)], filter[j*width + i], filter[j*width + (i + 1)], // �߰������� �ش����� ����
					filter[(j + 1)*width + (i - 1)], filter[(j + 1)*width + i], filter[(j + 1)*width + (i + 1)]); // ó���� �ֱ�
			}//��ȣ�ݱ�
			else {
				filter[j*width + i] =// Gaussian filter�� �������
					(filter[(j - 1)*width + (i - 1)] * 1 / 16 + filter[(j - 1)*width + i] * 1 / 8 + filter[(j - 1)*width + (i + 1)] * 1 / 16 + //9������ ������
						filter[j*width + (i - 1)] * 1 / 8 + filter[j*width + i] * 1 / 4 + filter[j*width + (i + 1)] * 1 / 8 + // 4:2:2:2:2:1:1:1:1
						filter[(j + 1)*width + (i - 1)] * 1 / 16 + filter[(j + 1)*width + i] * 1 / 8 + filter[(j + 1)*width + (i + 1)] * 1 / 16); //16���� ���� ������
			}//��ȣ�ݱ�
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
	for (j = 0;j < height;j++) { // �̹��� ũ�� ��ŭ�� ���̿� ����
		for (i = 0;i < width;i++) { // ����ŭ�� ���̿� ����
			outputImg[j*stride + 3 * i] = filter[(j + 1)*width + (i + 1)]; //B
			outputImg[j*stride + 3 * i + 1] = filter[(j + 1)*width + (i + 1)]; //G
			outputImg[j*stride + 3 * i + 2] = filter[(j + 1)*width + (i + 1)]; //R
		}//��ȣ�ݱ�
	}//��ȣ�ݱ�
	*/
	FILE *outputFile = fopen("19011824_�̿���.bmp", "wb"); //19011824_�̿��� �� bmp������ �� ��
	fwrite(&bmpFile, sizeof(BITMAPFILEHEADER), 1, outputFile); // bmgFile ������ ����� BITMAPFILEHEADER 1���� outputFile�� ����� ���Ͽ� ����
	fwrite(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, outputFile); // bmgInfo ������ ����� BITMAPINFOHEADER 1���� outputFile�� ����� ���Ͽ� ����
	fwrite(outputImg, sizeof(unsigned char), size, outputFile); // outputImg ������ ����� unsigned char��  size�� outputFile�� ����� ���Ͽ� ����
	free(outputImg); //output�̹����� �Ҵ� ����
	free(inputImg); //input�̹����� �Ҵ� ����
	//free(filter); //filter �Ҵ� ����
	fclose(inputFile); //input���� �ݾ��ֱ�
	fclose(outputFile); //output���� �ݾ��ֱ�
	return 0; //main�Լ� ����
}//��ȣ�ݱ�