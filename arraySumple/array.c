#include <stdio.h>
int main(void)
{
	int KokugoArray[8] = { 100, 89, 10, 23, 34, 56, 78, 14 };
	int SugakuArray[8] = { 100, 89, 10, 23, 34, 56, 78, 14 };
	int personalScore[8];

	int kokugoSum = 0;
	int sugakuSum = 0;
	int i;
	double kokugoAve = 0.0;
	double SugakuAve = 0.0;

	/* �e�X�g�̓_������͂����� */
	for (i = 0; i < 8; i++) {
		printf("�_������͂��Ă�������");
		scanf("%d", &KokugoArray[i]);
	}

	for (i = 0; i < 8; i++) {
		kokugoSum += KokugoArray[i];
		sugakuSum += SugakuArray[i];
		personalScore[i] = KokugoArray[i] + SugakuArray[i];
	}
	kokugoAve = kokugoSum / 8;
	printf("���ꕽ�ς�%lf", kokugoAve);
}