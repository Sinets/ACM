#include<stdio.h>
#include<string.h>
int main()
{
    int len1,len2;
    char ch1[10],ch2[10];//�����ַ������� 
    scanf("%s%s",ch1,ch2);
    len1=strlen(ch1);//���ַ������� 
    len2=strlen(ch2);
    if(len1==len2)//�ж��ַ��������Ƿ���� 
    {
        int flag=1;//����һ����ʶ�� 
        for(int i=0;i<len1;i++)
            if(ch1[i]!=ch2[i])//�ж��������ͬ 
                flag=0;//ʹ��ʶ���仯 
        if(flag)    printf("2");//�жϣ������ʶ��û�иı䣬���������2
        else 
        {
            flag=1;//���¶����ʶ�� 
            for(int i=0;i<len1;i++)//�жϣ�����ں��Դ�Сд��������Ƿ��ǲ�ͬ
            if(ch1[i]+32!=ch2[i]&&ch1[i]-32!=ch2[i]&&ch1[i]!=ch2[i])
                 flag=0;//ʹ��ʶ���ı� 
            if(flag)   printf("3");//�����ʶ��û�иı� �����������3 
            else    printf("4");//�����������4 
        }
    }
    else    printf("1");//�����������1 
}