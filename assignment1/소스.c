#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
	BITMAPFILEHEADER bmpFile;
	BITMAPINFOHEADER bmpInfo;
	BITMAPFILEHEADER bmpFile2;
	BITMAPINFOHEADER bmpInfo2;
	FILE *inputFile = NULL, *inputFile2 = NULL;
	inputFile = fopen("cafe.bmp", "rb");
	inputFile2 = fopen("what.bmp", "rb");
	fread(&bmpFile, sizeof(BITMAPFILEHEADER), 1, inputFile);
	fread(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, inputFile);
	fread(&bmpFile2, sizeof(BITMAPFILEHEADER), 1, inputFile2);
	fread(&bmpInfo2, sizeof(BITMAPINFOHEADER), 1, inputFile2);
	int width = bmpInfo.biWidth;
	int height = bmpInfo.biHeight;
	int size = bmpInfo.biSizeImage;
	int bitCnt = bmpInfo.biBitCount;
	int stride = (((bitCnt / 8)*width) + 3) / 4 * 4;
	int width2 = bmpInfo2.biWidth;
	int height2 = bmpInfo2.biHeight;
	int size2 = bmpInfo2.biSizeImage;
	int bitCnt2 = bmpInfo2.biBitCount;
	int stride2 = (((bitCnt2 / 8)*width2) + 3) / 4 * 4;
	printf("W: %d(%d)\nH: %d\nS: %d\nD: %d\n", width, stride, height, size, bitCnt);
	unsigned char *inputImg = NULL, *outputImg = NULL, *inputImg2 = NULL;
	inputImg = (unsigned char *)calloc(size, sizeof(unsigned char));
	inputImg2 = (unsigned char *)calloc(size, sizeof(unsigned char));
	outputImg = (unsigned char *)calloc(size, sizeof(unsigned char));
	fread(inputImg, sizeof(unsigned char), size, inputFile);
	fread(inputImg2, sizeof(unsigned char), size, inputFile2);

	//YCbCr
	double Y1, Y2, Y, Cb, Cr, R, G, B, I;
	for (int j = 0;j < height;j++) {
		for (int i = 0;i < width;i++) {
			Y1 = 0.299*inputImg[j*stride + 3 * i + 2] + 0.587*inputImg[j*stride + 3 * i + 1] + 0.114*inputImg[j*stride + 3 * i + 0];
			Cb = -0.169*inputImg[j*stride + 3 * i + 2] - 0.331*inputImg[j*stride + 3 * i + 1] + 0.500*inputImg[j*stride + 3 * i + 0];
			Cr = 0.500*inputImg[j*stride + 3 * i + 2] - 0.419*inputImg[j*stride + 3 * i + 1] - 0.0813*inputImg[j*stride + 3 * i + 0];
			I = (unsigned char)((inputImg[j*stride + 3 * i + 0] + inputImg[j*stride + 3 * i + 1] + inputImg[j*stride + 3 * i + 2]) / 3);
			R = Y1 + 1.402*Cr + 50;
			G = Y1 - 0.714*Cr - 0.344*Cb + 50;
			B = Y1 + 1.772*Cb + 50;
			Y2 = 0.299*inputImg2[j*stride2 + 3 * i + 2] + 0.587*inputImg2[j*stride2 + 3 * i + 1] + 0.114*inputImg2[j*stride2 + 3 * i + 0];

			/*if (Y2 == 0) {
				Y = 0;
				outputImg[j*stride + 3 * i + 2] = (unsigned char)(Y > 255 ? 255 : (Y < 0 ? 0 : Y));
				outputImg[j*stride + 3 * i + 1] = (unsigned char)(Y > 255 ? 255 : (Y < 0 ? 0 : Y));
				outputImg[j*stride + 3 * i + 0] = (unsigned char)(Y > 255 ? 255 : (Y < 0 ? 0 : Y));
			}
			else {*/
				outputImg[j*stride + 3 * i + 2] = (unsigned char)(R > 255 ? 255 : (R < 0 ? 0 : R));
				outputImg[j*stride + 3 * i + 1] = (unsigned char)(G > 255 ? 255 : (G < 0 ? 0 : G));
				outputImg[j*stride + 3 * i + 0] = (unsigned char)(B > 255 ? 255 : (B < 0 ? 0 : B));
			//}

		}
	}

	FILE *outputFile = fopen("Output.bmp", "wb");
	fwrite(&bmpFile, sizeof(BITMAPFILEHEADER), 1, outputFile);
	fwrite(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, outputFile);
	fwrite(outputImg, sizeof(unsigned char), size, outputFile);

	free(outputImg);
	free(inputImg);
	free(inputImg2);
	fclose(inputFile);
	fclose(inputFile2);
	fclose(outputFile);
	return 0;
}