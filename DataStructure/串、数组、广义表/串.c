//顺序串（SString） 

#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0

#define MAXLEN 255
#define CHUNKSIZE 80

//顺序串的定义
typedef struct {
    char ch1[MAXLEN + 1]; //存储串的一维数组
    int length; //串的当前长度
}SString;

//串的块链结构
typedef struct Chunk{
    char ch2[CHUNKSIZE];
    struct Chunk *next;
}Chunk;

typedef struct {
    Chunk *head, *tail; //串的头指针和尾指针
    int curlen; //长度
}LString;

//串的匹配算法：确定主串中所含子串第一次出现的位置（定位）
//1. BF暴力算法 简单匹配法 穷举法
//设目标串S=‘aaaaab’ 子串T=‘aaab’ S长度n=6 T长度m=4
int Index_BF(SString S, SString T){
    int i = 1, j = 1;
    while(i <= S.length && j <= T.length){
        if(S.ch1[i] == T.ch1[j]){ //主串和子串依次匹配下一个字符
            ++i; ++j;
        }else{ //主串子串指针回溯重新开始下一次匹配
            i = i - j + 2; j = 1;
        }
    }
    if(j >= T.length) return i - T.length; //返回匹配的第一个字符的下标
    else return 0;
}

//2. KMP算法