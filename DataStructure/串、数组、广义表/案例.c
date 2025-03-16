//1. 病毒感染检测（在人的基因序列中找病毒序列  若找到 即感染）：在主串中找子串 BF/KMP算法
#include <stdio.h>
#include <string.h>

// BF（暴力匹配）算法
int BF_Search(const char *mainStr, const char *subStr) {
    int mainLen = strlen(mainStr);
    int subLen = strlen(subStr);
    
    for (int i = 0; i <= mainLen - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (mainStr[i + j] != subStr[j]) {
                break;
            }
        }
        if (j == subLen) {
            return i; // 找到匹配，返回位置
        }
    }
    return -1; // 未找到
}

// 计算 KMP 的部分匹配表（Next 数组）
void computeNextArray(const char *subStr, int *next, int subLen) {
    int j = 0;
    next[0] = 0;
    
    for (int i = 1; i < subLen; i++) {
        while (j > 0 && subStr[i] != subStr[j]) {
            j = next[j - 1];
        }
        if (subStr[i] == subStr[j]) {
            j++;
        }
        next[i] = j;
    }
}

// KMP 算法
int KMP_Search(const char *mainStr, const char *subStr) {
    int mainLen = strlen(mainStr);
    int subLen = strlen(subStr);
    int next[subLen];
    
    computeNextArray(subStr, next, subLen);
    
    int j = 0;
    for (int i = 0; i < mainLen; i++) {
        while (j > 0 && mainStr[i] != subStr[j]) {
            j = next[j - 1];
        }
        if (mainStr[i] == subStr[j]) {
            j++;
        }
        if (j == subLen) {
            return i - subLen + 1; // 找到匹配，返回位置
        }
    }
    return -1; // 未找到
}

// 主函数进行测试
int main() {
    const char *humanDNA = "ACGTAGCTAGCTAGCTGACGATCG";
    const char *virusDNA = "GCTAGC";
    
    printf("人类基因序列: %s\n", humanDNA);
    printf("病毒基因序列: %s\n", virusDNA);
    
    // 测试 BF 算法
    int bf_result = BF_Search(humanDNA, virusDNA);
    if (bf_result != -1) {
        printf("[BF]病毒基因检测位置： %d\n", bf_result);
    } else {
        printf("[BF]未监测到\n");
    }
    
    // 测试 KMP 算法
    int kmp_result = KMP_Search(humanDNA, virusDNA);
    if (kmp_result != -1) {
        printf("[KMP]病毒基因检测位置： %d\n", kmp_result);
    } else {
        printf("[KMP]未监测到\n");
    }
    
    return 0;
}
