// ---------------- Bit Manipulation Macros ----------------

// Sets (makes 1) the bit at Bit Position (BP) in WORD
#define SETBIT(WORD,BP)        WORD |= (1 << BP)

// Clears (makes 0) the bit at Bit Position (BP) in WORD
#define CLRBIT(WORD,BP)        WORD &= ~(1 << BP)

// Toggles (complements) the bit at Bit Position (BP) in WORD
#define CPLBIT(WORD,BP)        WORD ^= (1 << BP)

// Writes a single BIT (0 or 1) at Bit Position (BP) in WORD
#define WRITEBIT(WORD,BP,BIT)  WORD = ((WORD & ~(1 << BP)) | (BIT << BP))

// Writes a 4-bit value (nibble) starting at Start Bit Position (SBP)
#define WRITENIBBLE(WORD,SBP,NIBBLE) \
        WORD = ((WORD & ~(0xF << SBP)) | (NIBBLE << SBP))

// Writes an 8-bit value (byte) starting at Start Bit Position (SBP)
#define WRITEBYTE(WORD,SBP,BYTE) \
        WORD = ((WORD & ~(0xFF << SBP)) | (BYTE << SBP))

// Writes a 16-bit value (half-word) starting at Start Bit Position (SBP)
#define WRITEHWORD(WORD,SBP,HWORD) \
        WORD = ((WORD & ~(0xFFFF << SBP)) | (HWORD << SBP))
