#include <iostream>  
#include <cstdio>  
#include <algorithm>  
#include <cstring>  
#include <cctype>  
#define For1(i, a, b) for(int i = a; i <= b; i++)  
#define For2(i, a, b) for(int i = a; i >= b; i--)  
using namespace std;  
  
int main()  
{  
    //freopen("in.txt", "r", stdin);  
    char ch[8010];  
    int n, sum = 0, ok = 1, c = -1;  
    scanf("%d%s", &n, ch);  
    int j = n - 1;  
    For1(i, 0, j-1){        //从左向右依次判断  
        For2(k, j, i){      //从最右边查找，看有无与当前字符相同的  
            if(k == i){     //没有找到与ch[i]相同的字符  
                if(n % 2 == 0 || c != -1){      //若n为偶数或ch[i]不是唯一无法匹配的字符  
                    ok = 0;  
                    break;  
                }  
                c = 1;              //n为奇数，ch[i]为第一个无法匹配的字符  
                sum += n / 2 - i;       //将它移到中间所需步数  
                break;  
            }  
            if(ch[k] == ch[i]){         //找到相同的  
                For1(t, k, j - 1) ch[t] = ch[t + 1];        //往后移到对称位置  
                sum += j - k;  
                j--;  
                break;  
            }  
        }  
        if(!ok) break;  
    }  
    if(!ok) printf("Impossible\n");  
    else printf("%d\n", sum);  
    return 0;  
}  