#include <stdio.h>

/* エラーコード */
enum {
	ERRCD_SUCCESS,		/* エラーなし */
	ERRCD_FILE_OPEN,	/* ファイルオープンエラー */
	ERRCD_FILE_WRITE,	/* ファイル書き込みエラー */
	ERRCD_FILE_READ,	/* ファイル読み込みエラー */
	ERRCD_FILE_CLOSE,	/* ファイルクローズエラー */
	ERRCD_MAX,
};

int testProc()
{
	int result = ERRCD_SUCCESS;		/* 処理結果 */
	FILE* fp;						/* ファイルディスクリプタ */

	fp = fopen("test.txt", "r");
	if (fp == NULL) {
		/* ファイルを開くことに失敗 */
		result = ERRCD_FILE_OPEN;
	}
	else {
		if (fclose(fp) != 0) {
			/* ファイルを閉じることに失敗 */
			result = ERRCD_FILE_CLOSE;
		}
	}

	return result;
}

void showErrMsg(int errCd) 
{
	switch (errCd) {
	case ERRCD_SUCCESS:
		printf("エラーなし\n");
		break;
	case ERRCD_FILE_OPEN:
		printf("ファイルを開けませんでした\n");
		break;
	case ERRCD_FILE_WRITE:
		printf("ファイルに書き込めませんでした\n");
		break;
	case ERRCD_FILE_READ:
		printf("ファイルから読みだせませんでした\n");
		break;
	case ERRCD_FILE_CLOSE:
		printf("ファイルを閉じられませんでした\n");
		break;
	default:
		printf("予期せぬエラーコード\n");
		break;
	}
}

void main(void)
{
	int result;		/* 処理結果 */
	result = testProc();

	/* 処理結果を表示 */
	showErrMsg(result);
}
