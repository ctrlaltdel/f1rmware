#ifndef _PRINT_H
#define _PRINT_H 1

#include <stdint.h>
void lcdPrint(const char *string);
void lcdNl(void);
void lcdCheckNl(void);
void lcdPrintln(const char *string);
void lcdPrintInt(const int num);
void lcdPrintIntHex(const int num);
void lcdPrintCharHex(const uint8_t num);
void lcdPrintShortHex(const uint16_t num);
void lcdClear();
void lcdRefresh();
void lcdMoveCrsr(signed int dx,signed int dy);
void lcdSetCrsr(int dx,int dy);
void lcdSetCrsrX(int dx);
void setSystemFont(void);
int lcdGetVisibleLines(void);

#endif /* _PRINT_H */
