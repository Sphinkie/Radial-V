/* ************************************************************************************************
 *  ASCII CONVERSIONS
 *  
 * Convertit des caractères Unicode ou UTF-8 en ASCII-ÉTENTDU (format supporté par la carte TFT)
 ************************************************************************************************ */

#include "Unicode.h"

// ----------------------------------------------------------------------------      
// Convertit un code Unicode-Point en Extended-Ascii
// ----------------------------------------------------------------------------      
unsigned char ConvertUnicodeToAscii(unsigned int lettre)
{
     switch (lettre)
       {
		   case 0xFFC0: return 'A';  break;  // U+00C0  À   LATIN CAPITAL LETTER A WITH GRAVE
		   case 0xFFC1: return 'A';  break;  // U+00C1  Á   LATIN CAPITAL LETTER A WITH ACUTE
		   case 0xFFC2: return 'A';  break;  // U+00C2  Â   LATIN CAPITAL LETTER A WITH CIRCUMFLEX
		   case 0xFFC3: return 'A';  break;  // U+00C3  Ã   LATIN CAPITAL LETTER A WITH TILDE
		   case 0xFFC4: return 0x8E; break;  // U+00C4  Ä   LATIN CAPITAL LETTER A WITH DIAERESIS
		   case 0xFFC5: return 0x8F; break;  // U+00C5  Å   LATIN CAPITAL LETTER A WITH RING ABOVE
		   case 0xFFC6: return 0x92; break;  // U+00C6  Æ   LATIN CAPITAL LETTER AE
		   case 0xFFC7: return 0x80; break;  // U+00C7  Ç   LATIN CAPITAL LETTER C WITH CEDILLA
		   case 0xFFC8: return 'E';  break;  // U+00C8  È   LATIN CAPITAL LETTER E WITH GRAVE
		   case 0xFFC9: return 0x90; break;  // U+00C9  É   LATIN CAPITAL LETTER E WITH ACUTE
		   case 0xFFCA: return 'E';  break;  // U+00CA  Ê   LATIN CAPITAL LETTER E WITH CIRCUMFLEX
		   case 0xFFCB: return 'E';  break;  // U+00CB  Ë   LATIN CAPITAL LETTER E WITH DIAERESIS
		   case 0xFFCC: return 'I';  break;  // U+00CC  Ì   LATIN CAPITAL LETTER I WITH GRAVE
		   case 0xFFCD: return 'I';  break;  // U+00CD  Í   LATIN CAPITAL LETTER I WITH ACUTE
		   case 0xFFCE: return 'I';  break;  // U+00CE  Î   LATIN CAPITAL LETTER I WITH CIRCUMFLEX
		   case 0xFFCF: return 'I';  break;  // U+00CF  Ï   LATIN CAPITAL LETTER I WITH DIAERESIS
		   case 0xFFD0: return 'D';  break;  // U+00D0  Ð   LATIN CAPITAL LETTER ETH
		   case 0xFFD1: return 0xA5; break;  // U+00D1  Ñ   LATIN CAPITAL LETTER N WITH TILDE
		   case 0xFFD2: return 'O';  break;  // U+00D2  Ò   LATIN CAPITAL LETTER O WITH GRAVE
		   case 0xFFD3: return 'O';  break;  // U+00D3  Ó   LATIN CAPITAL LETTER O WITH ACUTE
		   case 0xFFD4: return 'O';  break;  // U+00D4  Ô   LATIN CAPITAL LETTER O WITH CIRCUMFLEX
		   case 0xFFD5: return 'O';  break;  // U+00D5  Õ   LATIN CAPITAL LETTER O WITH TILDE
		   case 0xFFD6: return 'O';  break;  // U+00D6  Ö   LATIN CAPITAL LETTER O WITH DIAERESIS
		   case 0xFFD7: return 'x';  break;  // U+00D7  ×   MULTIPLICATION SIGN
		   case 0xFFD8: return 0xED; break;  // U+00D8  Ø   LATIN CAPITAL LETTER O WITH STROKE
		   case 0xFFD9: return 'U';  break;  // U+00D9  Ù   LATIN CAPITAL LETTER U WITH GRAVE
		   case 0xFFDA: return 'U';  break;  // U+00DA  Ú   LATIN CAPITAL LETTER U WITH ACUTE
		   case 0xFFDB: return 'U';  break;  // U+00DB  Û   LATIN CAPITAL LETTER U WITH CIRCUMFLEX
		   case 0xFFDC: return 'U';  break;  // U+00DC  Ü   LATIN CAPITAL LETTER U WITH DIAERESIS
		   case 0xFFDD: return 'Y';  break;  // U+00DD  Ý   LATIN CAPITAL LETTER Y WITH ACUTE
		   case 0xFFDE: return 'b';  break;  // U+00DE  Þ   LATIN CAPITAL LETTER THORN
		   case 0xFFDF: return 0xE1; break;  // U+00DF  ß   LATIN SMALL LETTER SHARP S
		   case 0xFFE0: return 0x85; break;  // U+00E0  à   LATIN SMALL LETTER A WITH GRAVE
		   case 0xFFE1: return 0xA0; break;  // U+00E1  á   LATIN SMALL LETTER A WITH ACUTE   
		   case 0xFFE2: return 0x83; break;  // U+00E2  â   LATIN SMALL LETTER A WITH CIRCUMFLEX
		   case 0xFFE3: return 0x84; break;  // U+00E3  ã   LATIN SMALL LETTER A WITH TILDE
		   case 0xFFE4: return 0x84; break;  // U+00E4  ä   LATIN SMALL LETTER A WITH DIAERESIS
		   case 0xFFE5: return 0x86; break;  // U+00E5  å   LATIN SMALL LETTER A WITH RING ABOVE
		   case 0xFFE6: return 0x91; break;  // U+00E6  æ   LATIN SMALL LETTER AE
		   case 0xFFE7: return 0x87; break;  // U+00E7  ç   LATIN SMALL LETTER C WITH CEDILLA
		   case 0xFFE8: return 0x8A; break;  // U+00E8  è   LATIN SMALL LETTER E WITH GRAVE
		   case 0xFFE9: return 0x82; break;  // U+00E9  é   LATIN SMALL LETTER E WITH ACUTE
		   case 0xFFEA: return 0x88; break;  // U+00EA  ê   LATIN SMALL LETTER E WITH CIRCUMFLEX
		   case 0xFFEB: return 0x89; break;  // U+00EB  ë   LATIN SMALL LETTER E WITH DIAERESIS
		   case 0xFFEC: return 0x8D; break;  // U+00EC  ì   LATIN SMALL LETTER I WITH GRAVE
		   case 0xFFED: return 0xA1; break;  // U+00ED  í   LATIN SMALL LETTER I WITH ACUTE
		   case 0xFFEE: return 0x8C; break;  // U+00EE  î   LATIN SMALL LETTER I WITH CIRCUMFLEX
		   case 0xFFEF: return 0x8B; break;  // U+00EF  ï   LATIN SMALL LETTER I WITH DIAERESIS
		   case 0xFFF0: return 0xEB; break;  // U+00F0  ð   LATIN SMALL LETTER ETH
		   case 0xFFF1: return 0xA4; break;  // U+00F1  ñ   LATIN SMALL LETTER N WITH TILDE
		   case 0xFFF2: return 0x95; break;  // U+00F2  ò   LATIN SMALL LETTER O WITH GRAVE
		   case 0xFFF3: return 0xA2; break;  // U+00F3  ó   LATIN SMALL LETTER O WITH ACUTE
		   case 0xFFF4: return 0x93; break;  // U+00F4  ô   LATIN SMALL LETTER O WITH CIRCUMFLEX
		   case 0xFFF5: return 0x94; break;  // U+00F5  õ   LATIN SMALL LETTER O WITH TILDE
		   case 0xFFF6: return 0x94; break;  // U+00F6  ö   LATIN SMALL LETTER O WITH DIAERESIS
		   case 0xFFF7: return 0xF6; break;  // U+00F7  ÷   DIVISION SIGN
		   case 0xFFF8: return 0xED; break;  // U+00F8  ø   LATIN SMALL LETTER O WITH STROKE
		   case 0xFFF9: return 0x97; break;  // U+00F9  ù   LATIN SMALL LETTER U WITH GRAVE
		   case 0xFFFA: return 0xA3; break;  // U+00FA  ú   LATIN SMALL LETTER U WITH ACUTE
		   case 0xFFFB: return 0x96; break;  // U+00FB  û   LATIN SMALL LETTER U WITH CIRCUMFLEX
		   case 0xFFFC: return 0x81; break;  // U+00FC  ü   LATIN SMALL LETTER U WITH DIAERESIS
		   case 0xFFFD: return 'y';  break;  // U+00FD  ý   LATIN SMALL LETTER Y WITH ACUTE
		   case 0xFFFE: return 'b';  break;  // U+00FE  þ   LATIN SMALL LETTER THORN
		   case 0xFFFF: return 0x98; break;  // U+00FF  ÿ   LATIN SMALL LETTER Y WITH DIAERESIS
       default: return (unsigned char)lettre;  // caractères non-accentués 
	   }
}
       
// ----------------------------------------------------------------------------      
// Convertit un code utf-8 en Extended-Ascii
// Le mot précédent doit avior été 0xFFC3
// ----------------------------------------------------------------------------      
unsigned char ConvertUtf8ToAscii(unsigned int lettre)
{
     switch (lettre)
       {
		   case 0xFF80: return 'A';  break;  //  À   c3 80  LATIN CAPITAL LETTER A WITH GRAVE
		   case 0xFF81: return 'A';  break;  //  Á   c3 81  LATIN CAPITAL LETTER A WITH ACUTE
		   case 0xFF82: return 'A';  break;  //  Â   c3 82  LATIN CAPITAL LETTER A WITH CIRCUMFLEX
		   case 0xFF83: return 'A';  break;  //  Ã   c3 83  LATIN CAPITAL LETTER A WITH TILDE
		   case 0xFF84: return 0x8E; break;  //  Ä   c3 84  LATIN CAPITAL LETTER A WITH DIAERESIS
		   case 0xFF85: return 0x8F; break;  //  Å   c3 85  LATIN CAPITAL LETTER A WITH RING ABOVE
		   case 0xFF86: return 0x92; break;  //  Æ   c3 86  LATIN CAPITAL LETTER AE
		   case 0xFF87: return 0x80; break;  //  Ç   c3 87  LATIN CAPITAL LETTER C WITH CEDILLA
		   case 0xFF88: return 'E';  break;  //  È   c3 88  LATIN CAPITAL LETTER E WITH GRAVE
		   case 0xFF89: return 0x90; break;  //  É   c3 89  LATIN CAPITAL LETTER E WITH ACUTE
		   case 0xFF8A: return 'E';  break;  //  Ê   c3 8a  LATIN CAPITAL LETTER E WITH CIRCUMFLEX
		   case 0xFF8B: return 'E';  break;  //  Ë   c3 8b  LATIN CAPITAL LETTER E WITH DIAERESIS
		   case 0xFF8C: return 'I';  break;  //  Ì   c3 8c  LATIN CAPITAL LETTER I WITH GRAVE
		   case 0xFF8D: return 'I';  break;  //  Í   c3 8d  LATIN CAPITAL LETTER I WITH ACUTE
		   case 0xFF8E: return 'I';  break;  //  Î   c3 8e  LATIN CAPITAL LETTER I WITH CIRCUMFLEX
		   case 0xFF8F: return 'I';  break;  //  Ï   c3 8f  LATIN CAPITAL LETTER I WITH DIAERESIS
		   case 0xFF90: return 'D';  break;  //  Ð   c3 90  LATIN CAPITAL LETTER ETH
		   case 0xFF91: return 0xA5; break;  //  Ñ   c3 91  LATIN CAPITAL LETTER N WITH TILDE
		   case 0xFF92: return 'O';  break;  //  Ò   c3 92  LATIN CAPITAL LETTER O WITH GRAVE
		   case 0xFF93: return 'O';  break;  //  Ó   c3 93  LATIN CAPITAL LETTER O WITH ACUTE
		   case 0xFF94: return 'O';  break;  //  Ô   c3 94  LATIN CAPITAL LETTER O WITH CIRCUMFLEX
		   case 0xFF95: return 'O';  break;  //  Õ   c3 95  LATIN CAPITAL LETTER O WITH TILDE
		   case 0xFF96: return 'O';  break;  //  Ö   c3 96  LATIN CAPITAL LETTER O WITH DIAERESIS
		   case 0xFF97: return 'x';  break;  //  ×   c3 97  MULTIPLICATION SIGN
		   case 0xFF98: return 0xED; break;  //  Ø   c3 98  LATIN CAPITAL LETTER O WITH STROKE
		   case 0xFF99: return 'U';  break;  //  Ù   c3 99  LATIN CAPITAL LETTER U WITH GRAVE
		   case 0xFF9A: return 'U';  break;  //  Ú   c3 9a  LATIN CAPITAL LETTER U WITH ACUTE
		   case 0xFF9B: return 'U';  break;  //  Û   c3 9b  LATIN CAPITAL LETTER U WITH CIRCUMFLEX
		   case 0xFF9C: return 'U';  break;  //  Ü   c3 9c  LATIN CAPITAL LETTER U WITH DIAERESIS
		   case 0xFF9D: return 'Y';  break;  //  Ý   c3 9d  LATIN CAPITAL LETTER Y WITH ACUTE
		   case 0xFF9E: return 'b';  break;  //  Þ   c3 9e  LATIN CAPITAL LETTER THORN
		   case 0xFF9F: return 0xE1; break;  //  ß   c3 9f  LATIN SMALL LETTER SHARP S
		   case 0xFFA0: return 0x85; break;  //  à   c3 a0  LATIN SMALL LETTER A WITH GRAVE
		   case 0xFFA1: return 0xA0; break;  //  á   c3 a1  LATIN SMALL LETTER A WITH ACUTE   
		   case 0xFFA2: return 0x83; break;  //  â   c3 a2  LATIN SMALL LETTER A WITH CIRCUMFLEX
		   case 0xFFA3: return 0x84; break;  //  ã   c3 a3  LATIN SMALL LETTER A WITH TILDE
		   case 0xFFA4: return 0x84; break;  //  ä   c3 a4  LATIN SMALL LETTER A WITH DIAERESIS
		   case 0xFFA5: return 0x86; break;  //  å   c3 a5  LATIN SMALL LETTER A WITH RING ABOVE
		   case 0xFFA6: return 0x91; break;  //  æ   c3 a6  LATIN SMALL LETTER AE
		   case 0xFFA7: return 0x87; break;  //  ç   c3 a7  LATIN SMALL LETTER C WITH CEDILLA
		   case 0xFFA8: return 0x8A; break;  //  è   c3 a8  LATIN SMALL LETTER E WITH GRAVE
		   case 0xFFA9: return 0x82; break;  //  é   c3 a9  LATIN SMALL LETTER E WITH ACUTE
		   case 0xFFAA: return 0x88; break;  //  ê   c3 aa  LATIN SMALL LETTER E WITH CIRCUMFLEX
		   case 0xFFAB: return 0x89; break;  //  ë   c3 ab  LATIN SMALL LETTER E WITH DIAERESIS
		   case 0xFFAC: return 0x8D; break;  //  ì   c3 ac  LATIN SMALL LETTER I WITH GRAVE
		   case 0xFFAD: return 0xA1; break;  //  í   c3 ad  LATIN SMALL LETTER I WITH ACUTE
		   case 0xFFAE: return 0x8C; break;  //  î   c3 ae  LATIN SMALL LETTER I WITH CIRCUMFLEX
		   case 0xFFAF: return 0x8B; break;  //  ï   c3 af  LATIN SMALL LETTER I WITH DIAERESIS
		   case 0xFFB0: return 0xEB; break;  //  ð   c3 b0  LATIN SMALL LETTER ETH
		   case 0xFFB1: return 0xA4; break;  //  ñ   c3 b1  LATIN SMALL LETTER N WITH TILDE
		   case 0xFFB2: return 0x95; break;  //  ò   c3 b2  LATIN SMALL LETTER O WITH GRAVE
		   case 0xFFB3: return 0xA2; break;  //  ó   c3 b3  LATIN SMALL LETTER O WITH ACUTE
		   case 0xFFB4: return 0x93; break;  //  ô   c3 b4  LATIN SMALL LETTER O WITH CIRCUMFLEX
		   case 0xFFB5: return 0x94; break;  //  õ   c3 b5  LATIN SMALL LETTER O WITH TILDE
		   case 0xFFB6: return 0x94; break;  //  ö   c3 b6  LATIN SMALL LETTER O WITH DIAERESIS
		   case 0xFFB7: return 0xF6; break;  //  ÷   c3 b7  DIVISION SIGN
		   case 0xFFB8: return 0xED; break;  //  ø   c3 b8  LATIN SMALL LETTER O WITH STROKE
		   case 0xFFB9: return 0x97; break;  //  ù   c3 b9  LATIN SMALL LETTER U WITH GRAVE
		   case 0xFFBA: return 0xA3; break;  //  ú   c3 ba  LATIN SMALL LETTER U WITH ACUTE
		   case 0xFFBB: return 0x96; break;  //  û   c3 bb  LATIN SMALL LETTER U WITH CIRCUMFLEX
		   case 0xFFBC: return 0x81; break;  //  ü   c3 bc  LATIN SMALL LETTER U WITH DIAERESIS
		   case 0xFFBD: return 'y';  break;  //  ý   c3 bd  LATIN SMALL LETTER Y WITH ACUTE
		   case 0xFFBE: return 'b';  break;  //  þ   c3 be  LATIN SMALL LETTER THORN
		   case 0xFFBF: return 0x98; break;  //  ÿ   c3 bf  LATIN SMALL LETTER Y WITH DIAERESIS
       default: return (unsigned char)lettre;  // caractères non-accentués 
	   }
}
       
       
// ----------------------------------------------------------------------------      
// On renvoie les unités sous forme de char entre '0' et '9'
// ----------------------------------------------------------------------------      
char getUnitChar(int number)
{
   int unites = number %10;
   return (unites + '0');
}

// ----------------------------------------------------------------------------      
// On renvoie les dizaines sous forme de char entre '0' et '9'
// ----------------------------------------------------------------------------      
char getDozenChar(int number)
{
   int dizaines = number %100;
   dizaines = dizaines/10;    // division entière
   return (dizaines + '0');
}

// ----------------------------------------------------------------------------      
// On renvoie les centaines sous forme de char entre '0' et '9'
// ----------------------------------------------------------------------------      
char getHundrenChar(int number)
{
   int centaines = number %1000;
   centaines = centaines/100;    // division entière
   return (centaines + '0');
}
