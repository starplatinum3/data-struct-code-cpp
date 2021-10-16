// ==========================================================================
// CRC Generation Unit - Linear Feedback Shift Register implementation
// (c) Kay Gorontzi, GHSi.de, distributed under the terms of LGPL
// ==========================================================================

#include<string.h>

char *MakeCRC(char *BitString)
   {
   static char Res[5];                                 // CRC Result
   char CRC[4];
   int  i;
   char DoInvert;
   
   for (i=0; i<4; ++i)  CRC[i] = 0;                    // Init before calculation
   
   for (i=0; i<strlen(BitString); ++i)
      {
      DoInvert = ('1'==BitString[i]) ^ CRC[3];         // XOR required?

      CRC[3] = CRC[2];
      CRC[2] = CRC[1];
      CRC[1] = CRC[0] ^ DoInvert;
      CRC[0] = DoInvert;
      }
      
   for (i=0; i<4; ++i)  Res[3-i] = CRC[i] ? '1' : '0'; // Convert binary to ASCII
   Res[4] = 0;                                         // Set string terminator

   return(Res);
   }

// A simple test driver:

#include <stdio.h>

int main()
   {
   char *Data, *Result;                                       // Declare two strings

   Data = "1101000101000111";
   Result = MakeCRC(Data);                                    // Calculate CRC
//    P=[10011]  CRC polynomial
   printf("CRC of [%s] is [%s] with P=[10011]\n", Data, Result);
   
   return(0);
   }
