#include "usart.h"

#include "stdio.h" 
#include "stdarg.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

void print(const char* format, ...)
{
    va_list args;
    va_start(args, format);
    char buf[256];
    vsprintf(buf, format, args);
    va_end(args);
    HAL_UART_Transmit(&huart1, (uint8_t*)buf, strlen(buf), 1000);
}

char* float2str(float x, uint8_t flen)
{
	uint32_t base;
	int64_t dn;
	char mc[32];

	base = pow(10,flen);
	dn = x*base;
    
    char *stra = (char *)malloc(32);
	sprintf(stra, "%d.", (int)(dn/base));
	dn = abs(dn);
	if(dn%base==0)
	{
		for(uint8_t j=1;j<=flen;j++)
		{
			stra = strcat(stra, "0");
		}
		return stra;
	}
	else
	{
		if(flen==1){
			sprintf(mc, "%d", (int)(dn%base));
			stra = strcat(stra, mc);
			return stra;
		}

		for(uint8_t j=1;j<flen;j++)
		{
			if((dn%base)<pow(10,j))
			{
				for(uint8_t k=1;k<=(flen-j);k++)
				{
					stra = strcat(stra, "0");
				}
				sprintf(mc, "%d", (int)(dn%base));
				stra = strcat(stra, mc);
				return stra;
			}
		}
		sprintf(mc, "%d", (int)(dn%base));
		stra = strcat(stra, mc);
		return stra;
	}
}