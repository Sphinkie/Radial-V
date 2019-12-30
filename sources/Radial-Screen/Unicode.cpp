
#include "Unicode.h"

unsigned char UnicodeToAscii(unsigned int lettre)
{
     switch (lettre)
       {
		   case 0xFFC0: return 'A'; break;  // U+00C0  À   LATIN CAPITAL LETTER A WITH GRAVE
		   case 0xFFC1: return 'A'; break;  // U+00C1  Á   LATIN CAPITAL LETTER A WITH ACUTE
		   case 0xFFC2: return 'A'; break;  // U+00C2  Â   LATIN CAPITAL LETTER A WITH CIRCUMFLEX
		   case 0xFFC3: return 'A'; break;  // U+00C3  Ã   LATIN CAPITAL LETTER A WITH TILDE
		   case 0xFFC4: return 'A'; break;  // U+00C4  Ä   LATIN CAPITAL LETTER A WITH DIAERESIS
		   case 0xFFC5: return 'A'; break;  // U+00C5  Å   LATIN CAPITAL LETTER A WITH RING ABOVE
		   case 0xFFC6: return 'A'; break;  // U+00C6  Æ   LATIN CAPITAL LETTER AE
		   case 0xFFC7: return 'C'; break;  // U+00C7  Ç   LATIN CAPITAL LETTER C WITH CEDILLA
		   case 0xFFC8: return 'E'; break;  // U+00C8  È   LATIN CAPITAL LETTER E WITH GRAVE
		   case 0xFFC9: return 'E'; break;  // U+00C9  É   LATIN CAPITAL LETTER E WITH ACUTE
		   case 0xFFCA: return 'E'; break;  // U+00CA  Ê   LATIN CAPITAL LETTER E WITH CIRCUMFLEX
		   case 0xFFCB: return 'E'; break;  // U+00CB  Ë   LATIN CAPITAL LETTER E WITH DIAERESIS
		   case 0xFFCC: return 'I'; break;  // U+00CC  Ì   LATIN CAPITAL LETTER I WITH GRAVE
		   case 0xFFCD: return 'I'; break;  // U+00CD  Í   LATIN CAPITAL LETTER I WITH ACUTE
		   case 0xFFCE: return 'I'; break;  // U+00CE  Î   LATIN CAPITAL LETTER I WITH CIRCUMFLEX
		   case 0xFFCF: return 'I'; break;  // U+00CF  Ï   LATIN CAPITAL LETTER I WITH DIAERESIS
		   case 0xFFD0: return 'D'; break;  // U+00D0  Ð   LATIN CAPITAL LETTER ETH
		   case 0xFFD1: return 'N'; break;  // U+00D1  Ñ   LATIN CAPITAL LETTER N WITH TILDE
		   case 0xFFD2: return 'O'; break;  // U+00D2  Ò   LATIN CAPITAL LETTER O WITH GRAVE
		   case 0xFFD3: return 'O'; break;  // U+00D3  Ó   LATIN CAPITAL LETTER O WITH ACUTE
		   case 0xFFD4: return 'O'; break;  // U+00D4  Ô   LATIN CAPITAL LETTER O WITH CIRCUMFLEX
		   case 0xFFD5: return 'O'; break;  // U+00D5  Õ   LATIN CAPITAL LETTER O WITH TILDE
		   case 0xFFD6: return 'O'; break;  // U+00D6  Ö   LATIN CAPITAL LETTER O WITH DIAERESIS
		   case 0xFFD7: return 'x'; break;  // U+00D7  ×   MULTIPLICATION SIGN
		   case 0xFFD8: return '0'; break;  // U+00D8  Ø   LATIN CAPITAL LETTER O WITH STROKE
		   case 0xFFD9: return 'U'; break;  // U+00D9  Ù   LATIN CAPITAL LETTER U WITH GRAVE
		   case 0xFFDA: return 'U'; break;  // U+00DA  Ú   LATIN CAPITAL LETTER U WITH ACUTE
		   case 0xFFDB: return 'U'; break;  // U+00DB  Û   LATIN CAPITAL LETTER U WITH CIRCUMFLEX
		   case 0xFFDC: return 'U'; break;  // U+00DC  Ü   LATIN CAPITAL LETTER U WITH DIAERESIS
		   case 0xFFDD: return 'Y'; break;  // U+00DD  Ý   LATIN CAPITAL LETTER Y WITH ACUTE
		   case 0xFFDE: return 'b'; break;  // U+00DE  Þ   LATIN CAPITAL LETTER THORN
		   case 0xFFDF: return 'B'; break;  // U+00DF  ß   LATIN SMALL LETTER SHARP S
		   case 0xFFE0: return 'a'; break;  // U+00E0  à   LATIN SMALL LETTER A WITH GRAVE
		   case 0xFFE1: return 'a'; break;  // U+00E1  á   LATIN SMALL LETTER A WITH ACUTE   
		   case 0xFFE2: return 'a'; break;  // U+00E2  â   LATIN SMALL LETTER A WITH CIRCUMFLEX
		   case 0xFFE3: return 'a'; break;  // U+00E3  ã   LATIN SMALL LETTER A WITH TILDE
		   case 0xFFE4: return 'a'; break;  // U+00E4  ä   LATIN SMALL LETTER A WITH DIAERESIS
		   case 0xFFE5: return 'a'; break;  // U+00E5  å   LATIN SMALL LETTER A WITH RING ABOVE
		   case 0xFFE6: return 'a'; break;  // U+00E6  æ   LATIN SMALL LETTER AE
		   case 0xFFE7: return 'c'; break;  // U+00E7  ç   LATIN SMALL LETTER C WITH CEDILLA
		   case 0xFFE8: return 'e'; break;  // U+00E8  è   LATIN SMALL LETTER E WITH GRAVE
		   case 0xFFE9: return 'e'; break;  // U+00E9  é   LATIN SMALL LETTER E WITH ACUTE
		   case 0xFFEA: return 'e'; break;  // U+00EA  ê   LATIN SMALL LETTER E WITH CIRCUMFLEX
		   case 0xFFEB: return 'e'; break;  // U+00EB  ë   LATIN SMALL LETTER E WITH DIAERESIS
		   case 0xFFEC: return 'i'; break;  // U+00EC  ì   LATIN SMALL LETTER I WITH GRAVE
		   case 0xFFED: return 'i'; break;  // U+00ED  í   LATIN SMALL LETTER I WITH ACUTE
		   case 0xFFEE: return 'i'; break;  // U+00EE  î   LATIN SMALL LETTER I WITH CIRCUMFLEX
		   case 0xFFEF: return 'i'; break;  // U+00EF  ï   LATIN SMALL LETTER I WITH DIAERESIS
		   case 0xFFF0: return 'd'; break;  // U+00F0  ð   LATIN SMALL LETTER ETH
		   case 0xFFF1: return 'n'; break;  // U+00F1  ñ   LATIN SMALL LETTER N WITH TILDE
		   case 0xFFF2: return 'o'; break;  // U+00F2  ò   LATIN SMALL LETTER O WITH GRAVE
		   case 0xFFF3: return 'o'; break;  // U+00F3  ó   LATIN SMALL LETTER O WITH ACUTE
		   case 0xFFF4: return 'o'; break;  // U+00F4  ô   LATIN SMALL LETTER O WITH CIRCUMFLEX
		   case 0xFFF5: return 'o'; break;  // U+00F5  õ   LATIN SMALL LETTER O WITH TILDE
		   case 0xFFF6: return 'o'; break;  // U+00F6  ö   LATIN SMALL LETTER O WITH DIAERESIS
		   case 0xFFF7: return '/'; break;  // U+00F7  ÷   DIVISION SIGN
		   case 0xFFF8: return '0'; break;  // U+00F8  ø   LATIN SMALL LETTER O WITH STROKE
		   case 0xFFF9: return 'u'; break;  // U+00F9  ù   LATIN SMALL LETTER U WITH GRAVE
		   case 0xFFFA: return 'u'; break;  // U+00FA  ú   LATIN SMALL LETTER U WITH ACUTE
		   case 0xFFFB: return 'u'; break;  // U+00FB  û   LATIN SMALL LETTER U WITH CIRCUMFLEX
		   case 0xFFFC: return 'u'; break;  // U+00FC  ü   LATIN SMALL LETTER U WITH DIAERESIS
		   case 0xFFFD: return 'y'; break;  // U+00FD  ý   LATIN SMALL LETTER Y WITH ACUTE
		   case 0xFFFE: return 'b'; break;  // U+00FE  þ   LATIN SMALL LETTER THORN
		   case 0xFFFF: return 'y'; break;  // U+00FF  ÿ   LATIN SMALL LETTER Y WITH DIAERESIS
       default: return lettre;  // caractères non-accentués 
	   }
}
       
unsigned char Utf8ToAscii(unsigned int lettre)
{
	// La premiere lettre est un C3
     switch (lettre)
       {
		   case 0x80: return 'A'; break;  //  À   c3 80  LATIN CAPITAL LETTER A WITH GRAVE
		   case 0x81: return 'A'; break;  //  Á   c3 81  LATIN CAPITAL LETTER A WITH ACUTE
		   case 0x82: return 'A'; break;  //  Â   c3 82  LATIN CAPITAL LETTER A WITH CIRCUMFLEX
		   case 0x83: return 'A'; break;  //  Ã   c3 83  LATIN CAPITAL LETTER A WITH TILDE
		   case 0x84: return 'A'; break;  //  Ä   c3 84  LATIN CAPITAL LETTER A WITH DIAERESIS
		   case 0x85: return 'A'; break;  //  Å   c3 85  LATIN CAPITAL LETTER A WITH RING ABOVE
		   case 0x86: return 'A'; break;  //  Æ   c3 86  LATIN CAPITAL LETTER AE
		   case 0x87: return 'C'; break;  //  Ç   c3 87  LATIN CAPITAL LETTER C WITH CEDILLA
		   case 0x88: return 'E'; break;  //  È   c3 88  LATIN CAPITAL LETTER E WITH GRAVE
		   case 0x89: return 'E'; break;  //  É   c3 89  LATIN CAPITAL LETTER E WITH ACUTE
		   case 0x8A: return 'E'; break;  //  Ê   c3 8a  LATIN CAPITAL LETTER E WITH CIRCUMFLEX
		   case 0x8B: return 'E'; break;  //  Ë   c3 8b  LATIN CAPITAL LETTER E WITH DIAERESIS
		   case 0x8C: return 'I'; break;  //  Ì   c3 8c  LATIN CAPITAL LETTER I WITH GRAVE
		   case 0x8D: return 'I'; break;  //  Í   c3 8d  LATIN CAPITAL LETTER I WITH ACUTE
		   case 0x8E: return 'I'; break;  //  Î   c3 8e  LATIN CAPITAL LETTER I WITH CIRCUMFLEX
		   case 0x8F: return 'I'; break;  //  Ï   c3 8f  LATIN CAPITAL LETTER I WITH DIAERESIS
		   case 0x90: return 'D'; break;  //  Ð   c3 90  LATIN CAPITAL LETTER ETH
		   case 0x91: return 'N'; break;  //  Ñ   c3 91  LATIN CAPITAL LETTER N WITH TILDE
		   case 0x92: return 'O'; break;  //  Ò   c3 92  LATIN CAPITAL LETTER O WITH GRAVE
		   case 0x93: return 'O'; break;  //  Ó   c3 93  LATIN CAPITAL LETTER O WITH ACUTE
		   case 0x94: return 'O'; break;  //  Ô   c3 94  LATIN CAPITAL LETTER O WITH CIRCUMFLEX
		   case 0x95: return 'O'; break;  //  Õ   c3 95  LATIN CAPITAL LETTER O WITH TILDE
		   case 0x96: return 'O'; break;  //  Ö   c3 96  LATIN CAPITAL LETTER O WITH DIAERESIS
		   case 0x97: return 'x'; break;  //  ×   c3 97  MULTIPLICATION SIGN
		   case 0x98: return '0'; break;  //  Ø   c3 98  LATIN CAPITAL LETTER O WITH STROKE
		   case 0x99: return 'U'; break;  //  Ù   c3 99  LATIN CAPITAL LETTER U WITH GRAVE
		   case 0x9A: return 'U'; break;  //  Ú   c3 9a  LATIN CAPITAL LETTER U WITH ACUTE
		   case 0x9B: return 'U'; break;  //  Û   c3 9b  LATIN CAPITAL LETTER U WITH CIRCUMFLEX
		   case 0x9C: return 'U'; break;  //  Ü   c3 9c  LATIN CAPITAL LETTER U WITH DIAERESIS
		   case 0x9D: return 'Y'; break;  //  Ý   c3 9d  LATIN CAPITAL LETTER Y WITH ACUTE
		   case 0x9E: return 'b'; break;  //  Þ   c3 9e  LATIN CAPITAL LETTER THORN
		   case 0x9F: return 'B'; break;  //  ß   c3 9f  LATIN SMALL LETTER SHARP S
		   case 0xA0: return 'a'; break;  //  à   c3 a0  LATIN SMALL LETTER A WITH GRAVE
		   case 0xA1: return 'a'; break;  //  á   c3 a1  LATIN SMALL LETTER A WITH ACUTE   
		   case 0xA2: return 'a'; break;  //  â   c3 a2  LATIN SMALL LETTER A WITH CIRCUMFLEX
		   case 0xA3: return 'a'; break;  //  ã   c3 a3  LATIN SMALL LETTER A WITH TILDE
		   case 0xA4: return 'a'; break;  //  ä   c3 a4  LATIN SMALL LETTER A WITH DIAERESIS
		   case 0xA5: return 'a'; break;  //  å   c3 a5  LATIN SMALL LETTER A WITH RING ABOVE
		   case 0xA6: return 'a'; break;  //  æ   c3 a6  LATIN SMALL LETTER AE
		   case 0xA7: return 'c'; break;  //  ç   c3 a7  LATIN SMALL LETTER C WITH CEDILLA
		   case 0xA8: return 'e'; break;  //  è   c3 a8  LATIN SMALL LETTER E WITH GRAVE
		   case 0xA9: return 'e'; break;  //  é   c3 a9  LATIN SMALL LETTER E WITH ACUTE
		   case 0xAA: return 'e'; break;  //  ê   c3 aa  LATIN SMALL LETTER E WITH CIRCUMFLEX
		   case 0xAB: return 'e'; break;  //  ë   c3 ab  LATIN SMALL LETTER E WITH DIAERESIS
		   case 0xAC: return 'i'; break;  //  ì   c3 ac  LATIN SMALL LETTER I WITH GRAVE
		   case 0xAD: return 'i'; break;  //  í   c3 ad  LATIN SMALL LETTER I WITH ACUTE
		   case 0xAE: return 'i'; break;  //  î   c3 ae  LATIN SMALL LETTER I WITH CIRCUMFLEX
		   case 0xAF: return 'i'; break;  //  ï   c3 af  LATIN SMALL LETTER I WITH DIAERESIS
		   case 0xB0: return 'd'; break;  //  ð   c3 b0  LATIN SMALL LETTER ETH
		   case 0xB1: return 'n'; break;  //  ñ   c3 b1  LATIN SMALL LETTER N WITH TILDE
		   case 0xB2: return 'o'; break;  //  ò   c3 b2  LATIN SMALL LETTER O WITH GRAVE
		   case 0xB3: return 'o'; break;  //  ó   c3 b3  LATIN SMALL LETTER O WITH ACUTE
		   case 0xB4: return 'o'; break;  //  ô   c3 b4  LATIN SMALL LETTER O WITH CIRCUMFLEX
		   case 0xB5: return 'o'; break;  //  õ   c3 b5  LATIN SMALL LETTER O WITH TILDE
		   case 0xB6: return 'o'; break;  //  ö   c3 b6  LATIN SMALL LETTER O WITH DIAERESIS
		   case 0xB7: return '/'; break;  //  ÷   c3 b7  DIVISION SIGN
		   case 0xB8: return '0'; break;  //  ø   c3 b8  LATIN SMALL LETTER O WITH STROKE
		   case 0xB9: return 'u'; break;  //  ù   c3 b9  LATIN SMALL LETTER U WITH GRAVE
		   case 0xBA: return 'u'; break;  //  ú   c3 ba  LATIN SMALL LETTER U WITH ACUTE
		   case 0xBB: return 'u'; break;  //  û   c3 bb  LATIN SMALL LETTER U WITH CIRCUMFLEX
		   case 0xBC: return 'u'; break;  //  ü   c3 bc  LATIN SMALL LETTER U WITH DIAERESIS
		   case 0xBD: return 'y'; break;  //  ý   c3 bd  LATIN SMALL LETTER Y WITH ACUTE
		   case 0xBE: return 'b'; break;  //  þ   c3 be  LATIN SMALL LETTER THORN
		   case 0xBF: return 'y'; break;  //  ÿ   c3 bf  LATIN SMALL LETTER Y WITH DIAERESIS
       default: return lettre;  // caractères non-accentués 
	   }
}
       
       
       
       
       
       
       /*
       case -23  : { texteOUT[I] = 'e'; break;} // U+00E9  é
       case -24  : { texteOUT[I] = 'e'; break;} // U+00E8  è
       case -32  : { texteOUT[I] = 'a'; break;} // U+00E0  à
       
       case -68  : { texteOUT[I] = 'u'; break;} // ü
       case -69  : { texteOUT[I] = 'u'; break;} // û
       case -71  : { texteOUT[I] = 'u'; break;} // ù
       case -74  : { texteOUT[I] = 'o'; break;} // ö
       case -75  : { texteOUT[I] = 'u'; break;} // µ
       case -76  : { texteOUT[I] = 'o'; break;} // ô
       case -81  : { texteOUT[I] = 'i'; break;} // ï
       case -82  : { texteOUT[I] = 'i'; break;} // î
       case -85  : { texteOUT[I] = 'e'; break;} // ë
       case -86  : { texteOUT[I] = 'e'; break;} // ê
       case -87  : { texteOUT[I] = 'e'; break;} // é
       case -88  : { texteOUT[I] = 'e'; break;} // è
       case -89  : { texteOUT[I] = 'c'; break;} // ç        
       case -92  : { texteOUT[I] = 'a'; break;} // ä      
       case -94  : { texteOUT[I] = 'a'; break;} // â
       case -96  : { texteOUT[I] = 'a'; break;} // à
       case -109 : { texteOUT[I] = 'o'; break;} // œ         
       case -126 : { texteOUT[I] = 'A'; break;} // Â
       case -128 : { texteOUT[I] = 'A'; break;} // À
       case -108 : { texteOUT[I] = 'O'; break;} // Ô
       case -114 : { texteOUT[I] = 'I'; break;} // Î
       case -118 : { texteOUT[I] = 'E'; break;} // Ê
       case -119 : { texteOUT[I] = 'E'; break;} // É            
       case -120 : { texteOUT[I] = 'E'; break;} // È             
       case -121 : { texteOUT[I] = 'C'; break;} // Ç
	   */
