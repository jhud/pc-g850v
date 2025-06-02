/* Serial terminal program for SHARP PC-G850V calculator.*/

#define R_CM '~'

/* Map hardware keyboard to ASCII characters. Map unused keys to $ and & because we need it for AT commands.*/
const char mapping[8][8] = {
{ 0, 'A','Z', '$', '$', 'L', 'I', 'P'},
{'Q','S','X', '$', '$', ';', 'O', '<'},
{'W','D','C', '^', '$', '(',  'D', 'W'},
{'E','F','V', '&', '0', '1', '4', '7'},
{'R','G','B','\t', '.', '2', '5', '8'},
{'T','H','N', ' ', '=', '3', '6', '9'},
{'Y','J','M', '&', '+', '-', '*', '/'},
{'U','K','.', '&','\n', '(' , R_CM,')'}
};
 
 /* Scan keyboard, return first pressed key. */
 char keyscan(void) {
  unsigned char scanRow;
  int outBit, row;
  for (outBit=0; outBit<8; outBit++) {
   outport(0x11, 1<<outBit);
   scanRow = inport(0x10);
   if (scanRow == 0) {
	   continue;
   }
   row=-1;
   while (scanRow > 0) { 
	   row++;
	   scanRow >>= 1;
   }
   outport(0x11,0);
   /*printf("SC: %d %d\n", row, outBit);*/
   return mapping[row][outBit];
  }
  outport(0x11,0);
 return 0;
 }

 /* Inner loop to read KB and SIO. */
 void main(void) {
  char lastKeypress=-1, keypress=0;
  char readBuffer[2];
  char *ret;
  FILE *ser;
  ser = fopen("stdaux1", "a+");
  
  if (ser) {
	  printf("PCG-TERM started\nPress R-CM to exit\n");
  }
  
  while (keypress != R_CM) {
   keypress = keyscan();
   if (keypress != 0 && lastKeypress == 0) {
	  fputc(keypress, ser);
    }
	lastKeypress = keypress;

   if (!feof(ser)) {
    ret = fgets(readBuffer, 2, ser);
    if (ret) {
	 if (readBuffer[0] == 13) {
      printf("\n");
	 }
     printf(readBuffer);
    }
   }
  }
 fclose(ser);
}
