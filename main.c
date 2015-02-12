/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Thu 12 Feb 2015 12:07:20 PM PST
 ************************************************************************/

#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include "tree.h"

#ifndef LOG
#define LOG(str,...) fprintf(stdout,str,##__VA_ARGS__)
#define LOGE(str) perror(str)
#define NEW(t) (t*)malloc(sizeof(t))
#endif

int main(int argc , char** argv){
    char buf[10];
    
    while( fgets(buf) ){
        switch(*buf){
            case '1':
            break;
            case '2':
            break;
            case '3':
            break;
            case '4':
            break;
        }
    }
}
