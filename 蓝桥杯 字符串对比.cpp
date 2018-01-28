#include<stdio.h>
#include<string.h>
int main()
{
    int len1,len2;
    char ch1[10],ch2[10];//定义字符串数组 
    scanf("%s%s",ch1,ch2);
    len1=strlen(ch1);//求字符串长度 
    len2=strlen(ch2);
    if(len1==len2)//判断字符串长度是否相等 
    {
        int flag=1;//定义一个标识符 
        for(int i=0;i<len1;i++)
            if(ch1[i]!=ch2[i])//判断如果不相同 
                flag=0;//使标识符变化 
        if(flag)    printf("2");//判断，如果标识符没有改变，则符合条件2
        else 
        {
            flag=1;//重新定义标识符 
            for(int i=0;i<len1;i++)//判断，如果在忽略大小写的情况下是否还是不同
            if(ch1[i]+32!=ch2[i]&&ch1[i]-32!=ch2[i]&&ch1[i]!=ch2[i])
                 flag=0;//使标识符改变 
            if(flag)   printf("3");//如果标识符没有改变 ，则符合条件3 
            else    printf("4");//否则符合条件4 
        }
    }
    else    printf("1");//否则符合条件1 
}