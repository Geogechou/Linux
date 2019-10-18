#include<stdio.h>
//字符分类函数
#include<ctype.h>

int main(void)
{
				//是字母返回非0，否则返回0
				printf("%u\n",isalpha('A'));
				printf("%u\n",isalpha('1'));
				printf("%u\n",isalpha('/'));
				//当ch是字母和数字时返回非0，否则返回0
				printf("%u\n",isalnum('9'));
				printf("%u\n",isalnum('a'));
				printf("%u\n",isalnum('/'));
				//小写字母返回非0，否则返回0
				printf("islower:%u\n",islower('A'));
				printf("islower:%u\n",islower('1'));
				printf("islower:%u\n",islower('a'));
				//大写字母返回非0，否则返回0
				printf("isupper:%u\n",isupper('A'));
				printf("isupper:%u\n",isupper('1'));
				printf("isupper:%u\n",isupper('a'));
				//toupper
				printf("toupper,%u\n",toupper('b'));
				printf("toupper,%u\n",toupper('A'));
				return 0;
}
