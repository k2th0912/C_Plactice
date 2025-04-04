/*############################################################################################*/
/*      整数値を入力し、以下の四つの分類から該当するものを表示するプログラムを作成しなさい。  */
/*                                                                                            */
/*            “正の偶数”、“正の奇数”、“負の偶数”、“負の奇数”                          */
/*                                                                                            */
/*※ 	負の数であっても、2で割り切れれば偶数、そうでなければ奇数とする。                     */
/*※ 	0は“正の偶数”であるとする。                                                         */
/*※ 	2で割った余りを0と比較するようにした方が良い。（1と比較しない）                       */
/*############################################################################################*/

#include<stdio.h>

int main(void)

{
	int num;    /*入力される値の変数*/

	printf("数値を入力してください\n");
	scanf_s("%d", &num);

	/*正の数の場合*/
	if (0 <= num) {
		if (num % 2 == 0) {
			printf("入力された数(%d)は正の偶数です\n", num);
		}
		else {
			printf("入力された数(%d)は正の奇数です\n", num);
		}
	}

	/*負の数の場合*/

	else {
		if (num % 2 == 0) {
			printf("入力された数(%d)は負の偶数です\n", num);
		}
		else {
			printf("入力された数(%d)は負の奇数です\n", num);
		}
	}
	return 0;
}