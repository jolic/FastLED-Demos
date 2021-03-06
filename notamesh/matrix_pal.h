#ifndef MATRIX_PAL_H
#define MATRIX_PAL_H


/* Usage - matrix_pal();
 *  
 *  This is one of the few routines I have with pixel counting.
 *  
 *  
 * currentPalette, targetPalette
 * thisrot
 * thisindex
 * bgclr
 * bgbri
 * thisdir
 * thisbright
 */

void matrix_pal() {                                           // One line matrix

  if (thisrot) thisindex++;                                   // Increase palette index to change colours on the fly
  
  if (random8(90) > 80) {
    if (thisdir == -1)
      leds[0] = ColorFromPalette(gCurrentPalette, thisindex, thisbright, currentBlending);          // Foreground matrix colour
    else
      leds[NUM_LEDS-1] = ColorFromPalette(gCurrentPalette, thisindex, thisbright, currentBlending);
  } else {
    if (thisdir == -1)
      leds[0] = CHSV(bgclr, thissat, bgbri);                                                        // Background colour
    else
      leds[NUM_LEDS-1] = CHSV(bgclr, thissat, bgbri);
  }

  if (thisdir == -1) {                                                                              // Move the foreground colour down the line.
    for (int i = NUM_LEDS-1; i >0 ; i-- ) leds[i] = leds[i-1];
  } else {
    for (int i = 0; i < NUM_LEDS-1 ; i++ ) leds[i] = leds[i+1];
  }

} // matrix_pal()


#endif
