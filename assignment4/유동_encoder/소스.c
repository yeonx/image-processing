#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
	BITMAPFILEHEADER bmpFile;
	BITMAPINFOHEADER bmpInfo;
	FILE *inputFile = NULL;
	FILE *fp = fopen("bitstream.txt", "w");
	inputFile = fopen("AICenterY_Org.bmp", "rb");
	fread(&bmpFile, sizeof(BITMAPFILEHEADER), 1, inputFile);
	fread(&bmpInfo, sizeof(BITMAPINFOHEADER), 1, inputFile);
	int width = bmpInfo.biWidth;
	int height = bmpInfo.biHeight;
	int size = bmpInfo.biSizeImage;
	int bitCnt = bmpInfo.biBitCount;
	int stride = (((bitCnt / 8)*width) + 3) / 4 * 4;

	unsigned char *inputImg = NULL, *Y = NULL;
	inputImg = (unsigned char *)calloc(size, sizeof(unsigned char));
	Y = (unsigned char *)calloc(width*height, sizeof(unsigned char));
	fread(inputImg, sizeof(unsigned char), size, inputFile);
	char s1[2] = "", s2[3] = "", s3[4] = "",s4[5]="";
	char s5[6] = "", s6[7] = "", s7[8] = "", s8[9] = "";
	char s9[10] = "", s10[11] = "", s11[12] = "", s12[13] = "";
	char s13[14] = "", s14[15] = "", s15[16] = "", s16[17] = "", s17[18] = "", s18[19] = "", s19[20] = "";
	char s20[21] = "", s21[22] = "", s22[23] = "", s23[24] = "", s24[25] = "", s25[26] = "";
	char s26[27] = "", s27[28] = "", s28[29] = "", s29[30] = "", s30[31] = "", s31[32] = "";
	char s32[33] = "", s33[34] = "", s34[35] = "";
	int i, j, count = 0;
	int k, num, number, diff;


	for (j = 0;j < height;j ++) {
		for (i = 0;i < width;i++) {

			if (i == 0) {
				number = inputImg[j*stride + 3 * i];
				num = number;
				for (k = 7;k >= 0;k--, num = num / 2) {
					if (num % 2 == 0)
						s8[k] = '0';
					else
						s8[k] = '1';
				}
				fwrite(s8, strlen(s8), 1, fp);
			}

			else {
				num = inputImg[j*stride + 3 * i]-number;
				num = num / 15;
				number = number + num * 15;
				if (num == 0) {
					strcpy(s1, "0");
					fwrite(s1, strlen(s1), 1, fp);
				}
				else if (num == 1) {
					strcpy(s2, "10");
					fwrite(s2, strlen(s2), 1, fp);
				}
				else if (num == -1) {
					strcpy(s3, "110");
					fwrite(s3, strlen(s3), 1, fp);
				}
				else if (num == 2) {
					strcpy(s4, "1110");
					fwrite(s4, strlen(s4), 1, fp);
				}
				else if (num == -2) {
					strcpy(s5, "11110");
					fwrite(s5, strlen(s5), 1, fp);
				}
				else if (num == 3) {
					strcpy(s6, "111110");
					fwrite(s6, strlen(s6), 1, fp);
				}
				else if (num == -3) {
					strcpy(s7, "1111110");
					fwrite(s7, strlen(s7), 1, fp);
				}
				else if (num == 4) {
					strcpy(s8, "11111110");
					fwrite(s8, strlen(s8), 1, fp);
				}
				else if (num == -4) {
					strcpy(s9, "111111110");
					fwrite(s9, strlen(s9), 1, fp);
				}
				else if (num == 5) {
					strcpy(s10, "1111111110");
					fwrite(s10, strlen(s10), 1, fp);
				}
				else if (num == -5) {
					strcpy(s11, "11111111110");
					fwrite(s11, strlen(s11), 1, fp);
				}
				else if (num == 6) {
					strcpy(s12, "111111111110");
					fwrite(s12, strlen(s12), 1, fp);
				}
				else if (num == -6) {
					strcpy(s13, "1111111111110");
					fwrite(s13, strlen(s13), 1, fp);
				}
				else if (num == 7) {
					strcpy(s14, "11111111111110");
					fwrite(s14, strlen(s14), 1, fp);
				}
				else if (num == -7) {
					strcpy(s15, "111111111111110");
					fwrite(s15, strlen(s15), 1, fp);
				}
				else if (num == 8) {
					strcpy(s16, "1111111111111110");
					fwrite(s16, strlen(s16), 1, fp);
				}
				else if (num == -8) {
					strcpy(s17, "11111111111111110");
					fwrite(s17, strlen(s17), 1, fp);
				}
				else if (num == 9) {
					strcpy(s18, "111111111111111110");
					fwrite(s18, strlen(s18), 1, fp);
				}
				else if (num == -9) {
					strcpy(s19, "1111111111111111110");
					fwrite(s19, strlen(s19), 1, fp);
				}
				else if (num == 10) {
					strcpy(s20, "11111111111111111110");
					fwrite(s20, strlen(s20), 1, fp);
				}
				else if (num == -10) {
					strcpy(s21, "111111111111111111110");
					fwrite(s21, strlen(s21), 1, fp);
				}
				else if (num == 11) {
					strcpy(s22, "1111111111111111111110");
					fwrite(s22, strlen(s22), 1, fp);
				}
				else if (num == -11) {
					strcpy(s23, "11111111111111111111110");
					fwrite(s23, strlen(s23), 1, fp);
				}
				else if (num == 12) {
					strcpy(s24, "111111111111111111111110");
					fwrite(s24, strlen(s24), 1, fp);
				}
				else if (num == -12) {
					strcpy(s25, "1111111111111111111111110");
					fwrite(s25, strlen(s25), 1, fp);
				}
				else if (num == 13) {
					strcpy(s26, "11111111111111111111111110");
					fwrite(s26, strlen(s26), 1, fp);
				}
				else if (num == -13) {
					strcpy(s27, "111111111111111111111111110");
					fwrite(s27, strlen(s27), 1, fp);
				}
				else if (num == 14) {
					strcpy(s28, "1111111111111111111111111110");
					fwrite(s28, strlen(s28), 1, fp);
				}
				else if (num == -14) {
					strcpy(s29, "11111111111111111111111111110");
					fwrite(s29, strlen(s29), 1, fp);
				}
				else if (num == 15) {
					strcpy(s30, "111111111111111111111111111110");
					fwrite(s30, strlen(s30), 1, fp);
				}
				else if (num == -15) {
					strcpy(s31, "1111111111111111111111111111110");
					fwrite(s31, strlen(s31), 1, fp);
				}
				else if (num == 16) {
					strcpy(s32, "11111111111111111111111111111110");
					fwrite(s32, strlen(s32), 1, fp);
				}
				else if (num == -16) {
					strcpy(s33, "111111111111111111111111111111110");
					fwrite(s33, strlen(s33), 1, fp);
				}
				else
					printf("%d ", num);
			}
		}
	}
 
	free(inputImg);
	fclose(inputFile);
	fclose(fp);
	return 0;
}