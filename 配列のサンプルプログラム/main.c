#include <stdio.h>

/* �G���[�R�[�h */
enum {
	ERRCD_SUCCESS,		/* �G���[�Ȃ� */
	ERRCD_FILE_OPEN,	/* �t�@�C���I�[�v���G���[ */
	ERRCD_FILE_WRITE,	/* �t�@�C���������݃G���[ */
	ERRCD_FILE_READ,	/* �t�@�C���ǂݍ��݃G���[ */
	ERRCD_FILE_CLOSE,	/* �t�@�C���N���[�Y�G���[ */
	ERRCD_MAX,
};

int testProc()
{
	int result = ERRCD_SUCCESS;		/* �������� */
	FILE* fp;						/* �t�@�C���f�B�X�N���v�^ */

	fp = fopen("test.txt", "r");
	if (fp == NULL) {
		/* �t�@�C�����J�����ƂɎ��s */
		result = ERRCD_FILE_OPEN;
	}
	else {
		if (fclose(fp) != 0) {
			/* �t�@�C������邱�ƂɎ��s */
			result = ERRCD_FILE_CLOSE;
		}
	}

	return result;
}

void showErrMsg(int errCd) 
{
	switch (errCd) {
	case ERRCD_SUCCESS:
		printf("�G���[�Ȃ�\n");
		break;
	case ERRCD_FILE_OPEN:
		printf("�t�@�C�����J���܂���ł���\n");
		break;
	case ERRCD_FILE_WRITE:
		printf("�t�@�C���ɏ������߂܂���ł���\n");
		break;
	case ERRCD_FILE_READ:
		printf("�t�@�C������ǂ݂����܂���ł���\n");
		break;
	case ERRCD_FILE_CLOSE:
		printf("�t�@�C��������܂���ł���\n");
		break;
	default:
		printf("�\�����ʃG���[�R�[�h\n");
		break;
	}
}

void main(void)
{
	int result;		/* �������� */
	result = testProc();

	/* �������ʂ�\�� */
	showErrMsg(result);
}
