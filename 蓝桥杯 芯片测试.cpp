#include <stdio.h>
#define MAXS 20

int main()
{
    int n, text[20][20], i, j, s;//sΪ��оƬ����
    scanf("%d", &n);
   
    if (n >= 2 && n <= 20)
    {   
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &text[i][j]);
            }
        }
        //�޳���оƬ�����º�оƬ
        for (j = 0; j < n; j++)
        {
            s = 0;
            for (i = 0; i < n; i++)
            {
                s += text[i][j];               
            }
            if (s > n/2)
                printf("%d ", j+1);
           
        }           
    }   
    return 0;
}
