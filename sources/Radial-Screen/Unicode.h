#ifndef UNICODE_H_INCLUDED
#define UNICODE_H_INCLUDED

unsigned char ConvertUnicodeToAscii(unsigned int lettre);
unsigned char ConvertUtf8ToAscii(unsigned int lettre);

char getUnitChar(int number);
char getDozenChar(int number);
char getHundrenChar(int number);


#endif // UNICODE_H_INCLUDED
