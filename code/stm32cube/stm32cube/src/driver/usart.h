#ifndef _UART_H_
#define _UART_H_
 

#include "driver.h"
 
void print(const char* format, ...);
char* float2str(float x, uint8_t flen);

#define LOG(format, ...) print("[%s] (%d): " format, __FUNCTION__ , __LINE__, ##__VA_ARGS__)
#endif