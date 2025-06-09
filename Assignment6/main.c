#include <stdint.h>
#include <stdio.h>

/*******************************************************************************
* Definitions
******************************************************************************/

/* 1U = 0000 0001, Shift the value 1 to the left n times
and perform an OR operation with the value at address add  */
#define REG_BIT_SET32(add, n) (*((volatile uint32_t *)(add)) |= (1U << (n)))      

/* Example: ~(1U << (3)) = 1111 1011, Shift the value 1 to the left n times,
then invert all the bits, then perform AND with the value at address add */
#define REG_BIT_CLEAR32(add, n) (*((volatile uint32_t *)(add)) &= ~(1U << (n)))

/* 0x000000FF = 00000000 00000000 00000000 11111111, keep the lowest byte << 24 bit (3 byte) to the highest byte position
   0x0000FF00 = 00000000 00000000 11111111 00000000, keep the second byte << 8 bit (1 byte) to the third byte position
   0x00FF0000 = 00000000 11111111 00000000 00000000, keep the third byte >> 8 bit (1 byte) to the second byte position
   0xFF000000 = 11111111 00000000 00000000 00000000, keep the highest byte >> 24 bit (3 byte) to the lowest byte position */
#define SWAP_BYTE32(add) (*((volatile uint32_t *)(add)) = \
                         (((*((volatile uint32_t *)(add)) & 0x000000FF) << 24) | \
                         ((*((volatile uint32_t *)(add)) & 0x0000FF00) << 8)  | \
                         ((*((volatile uint32_t *)(add)) & 0x00FF0000) >> 8)  | \
                         ((*((volatile uint32_t *)(add)) & 0xFF000000) >> 24)))

/* 0X00FF = 0000 0000 1111 1111, Perform AND operation with 0x00FF to retain the low bit, 
   then shift left 8 bits to push up the high bit position
   0xFF00 = 1111 1111 0000 0000, Perform AND operation with 0xFF00 to retain the high bit, 
   then shift right 8 bits to push to the low bit position */
#define SWAP_BYTE16(add) (*((volatile uint16_t *)(add)) = \
                         (((*((volatile uint16_t *)(add)) & 0x00FF) << 8) | \
                         ((*((volatile uint16_t *)(add)) & 0xFF00) >> 8)))


/*******************************************************************************
* Set the nth bit in a register given an address
* REG_BIT_SET32(add,n)
* set a single bit, without changing the values of the remaining bits
* REG_BIT_CLEAR32(add,n)
* clear a single bit, without changing the values of the remaining bits
* SWAP_BYTE32(add)
* convert from big endian to little endian
* SWAP_BYTE16(add)
* convert from big endian to little endian
* add: address
* n: position from right to left, from the LSB to the MSB, compared to 0
******************************************************************************/
int main(int argc, char* argv[])
{
    uint32_t a = 0x12345678;
    SWAP_BYTE32(&a);                    /* 0x78000000 | 0x00560000 | 0x00003400 | 0x00000012 */
    printf("a = 0x%08X\n", a);          /* a = 0x78563412 */

    uint16_t b = 0x1234;       
    SWAP_BYTE16(&b);                /* 0x3400 | 0x0012 */
    printf("b = 0x%04X\n", b);      /* 0x3412 */

    uint32_t c = 0;                /* c = 0x00000000 */
    REG_BIT_SET32(&c, 2);          /* c = 0x00000100 */
    printf("c = %d\n", c);         /* c = 4 */

    REG_BIT_CLEAR32(&c, 2);                                      /* c = 0x00000100 & 0x11111011 */
    printf("c after clearing the 2nd bit = 0x%08X\n", c);        /* c = 0 */

    return 0;
}
