#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	BITMAPFILEHEADER bmpFile;
	BITMAPINFOHEADER bmpInfo;
	BITMAPFILEHEADER bmpFile2;
	BITMAPINFOHEADER bmpInfo2;
	FILE *inputFile = NULL, *inputFile2 = NULL;
	inputFile = fopen("L.bmp", "rb");
	inputFile2 = fopen("histogram.bmp", "rb");
	fread(&bmpFile, sizeof(BITMAPFILEHEADER), 1, inputFile);
	fread(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, inputFile);
	fread(&bmpFile2, sizeof(BITMAPFILEHEADER), 1, inputFile2);
	fread(&bmpInfo2, sizeof(BITMAPINFOHEADER), 1, inputFile2);
	int width = bmpInfo.biWidth;
	int height = bmpInfo.biHeight;
	int size = bmpInfo.biSizeImage;
	int bitCnt = bmpInfo.biBitCount;
	int stride = (((bitCnt / 8)*width) + 3) / 4 * 4;
	unsigned char *inputImg = NULL, *outputImg = NULL, *histogram = NULL;
	inputImg = (unsigned char *)calloc(size, sizeof(unsigned char));
	outputImg = (unsigned char *)calloc(size, sizeof(unsigned char));
	histogram = (unsigned char *)calloc(size, sizeof(unsigned char));
	fread(inputImg, sizeof(unsigned char), size, inputFile);
	fread(histogram, sizeof(unsigned char), size, inputFile2);

	int his[256] = { 0 };
	//double Y;
	for (int j = 0;j < height;j++) {
		for (int i = 0;i < width;i++) {
			//Y = 0.299*inputImg[j*stride + 3 * i + 2] + 0.587*inputImg[j*stride + 3 * i + 1] + 0.114*inputImg[j*stride + 3 * i + 0];
			outputImg[j*stride + 3 * i + 0] = 255;
			outputImg[j*stride + 3 * i + 1] = 255;
			outputImg[j*stride + 3 * i + 2] = 255;
			
			his[inputImg[j*stride + 3 * i + 0]]++;
			

		}
	}
	
	int max = 0, k = 0;
	for (int i = 0;i < 256;i++) {
		if (max < his[i]) {
			max = his[i];
			k = i;
		}
		his[i] = his[i]/71;
		
	}
	printf("%d %d\n",k, max);
	for (int j = 0;j < 255;j++) {
		for (int i = 0;i < his[j];i++) {
			outputImg[i*stride + 3 * 2 *j + 0] = 0;
			outputImg[i*stride + 3 * 2* j + 1] = 0;
			outputImg[i*stride + 3 * 2*j + 2] = 0;
			outputImg[i*stride + 3 * (2*j+1)+0] = 0;
			outputImg[i*stride + 3 * (2 * j + 1)+1] = 0;
			outputImg[i*stride + 3 * (2 * j + 1)+2] = 0;

		}
	}

	
	FILE *outputFile2 = fopen("L_Histogrsm.bmp", "wb");
	fwrite(&bmpFile2, sizeof(BITMAPFILEHEADER), 1, outputFile2);
	fwrite(&bmpInfo2, sizeof(BITMAPINFOHEADER), 1, outputFile2);
	fwrite(outputImg, sizeof(unsigned char), size, outputFile2);
	free(outputImg);
	free(inputImg);
	free(histogram);
\
	fclose(inputFile);
	fclose(inputFile2);
	fclose(outputFile2);
	return 0;
}