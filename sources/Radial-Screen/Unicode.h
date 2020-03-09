/* ************************************************************************************************
 *  ASCII CONVERSIONS
 *  
 * Convertit des caractères Unicode ou UTF-8 en ASCII-ÉTENDU (format supporté par la carte TFT)
 ************************************************************************************************ */

#ifndef UNICODE_H_INCLUDED

   #define UNICODE_H_INCLUDED

   unsigned char ConvertUnicodeToAscii(unsigned int lettre);
   unsigned char ConvertUtf8ToAscii(unsigned int lettre);

   char getUnitChar(int number);
   char getDozenChar(int number);
   char getHundrenChar(int number);

#endif // UNICODE_H_INCLUDED
