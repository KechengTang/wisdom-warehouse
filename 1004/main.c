#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[16] = "0123456789abcdef";
    char arr[1000] = {0};
    while(scanf("%s", arr) != EOF)
    {
        int len = strlen(arr);
        if(strchr(arr, '.') == NULL)
        {
            int num = 0;
            int i = 0;
            int flag = 1;
            if(arr[i] == '-')
            {
                flag = -1;
                i++;
            }
            for(; i<len; i++)
            {
                num = num *10 + arr[i] -'0';
            }
            num *= flag;
            for(i = 0; i<4; i++)
            {
                printf("%c%c%c", a[(num>>4)&(0xf)], a[num&(0xf)], i==3?'\n':' ');
                num = num >> 8;
            }

        }
        else
        {
            int i = 0;
            int flag = 1;
            if(arr[i] == '-')
            {
                flag = -1;
                i++;
            }
            double num = 0;
            while(arr[i] != '.')
            {
                num = num*10 + arr[i] - '0';
                i++;
            }
            i++;
            int l = 0;
            while(arr[i])
            {
                l++;
                num = num *10 + arr[i] -'0';
                i++;
            }
            long ten = 1;
            while(l)
            {
                l--;
                ten *= 10;
            }
            num = num *flag;
            num = num / ten;
            unsigned char *p = (unsigned char*)&num;
            for(int j = 0; j<8; j++)
            {
                printf("%02x%c",*p, j==7? '\n':' ');
                p++;
            }
        }
    }
    return 0;
}
