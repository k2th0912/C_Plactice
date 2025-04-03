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

/* �G���[���b�Z�[�W */
const char *ErrMsg[100] = {
	"�G���[�Ȃ�\n",
	"�t�@�C�����J���܂���ł���\n",
	"�t�@�C���ɏ������߂܂���ł���\n",
	"�t�@�C������ǂ݂����܂���ł���\n",
	"�t�@�C��������܂���ł���\n",
	"�\�����ʃG���[�R�[�h\n",
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
	/* �G���[���b�Z�[�W�\�� */
	printf(ErrMsg[errCd]);
}

void main(void)
{
	int result;		/* �������� */
	result = testProc();

	/* �������ʂ�\�� */
	showErrMsg(result);
}
