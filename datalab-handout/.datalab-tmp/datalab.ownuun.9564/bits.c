#line 179 "bits.c"
int bitAnd(int x, int y) {
  return ~(~x | ~y);
#line 0 "<command-line>"
#include "/usr/include/stdc-predef.h"
#line 181 "bits.c"
}
#line 196
int evenBits(void) {
  int result=  0x55;
  result =( result << 8) | 0x55;
  result =( result << 8) | 0x55;
  result =( result << 8) | 0x55;
  return result;
}
#line 220
int bitNor(int x, int y) {
  return ~x & ~y;
}
#line 238
int isPositive(int x) {
  return !((x >> 31) | !x);
}
#line 260
int getByte(int x, int n) {
  int s=  n << 3;
  return (x >> s) & 0xFF;
}
#line 282
int isSymmetric(int x) {
  int k=  0xFF;
  k =( k << 8) | 0xFF;
  return !(( x & k) ^(( x >> 16) & k));
}
#line 307
int sign(int x) {
  int s=  x >> 31;
  int z=  !x;
  return s |( !z & !s);
}
#line 335
int allEvenBits(int x) {
  int k=  0x55;
  k =( k << 8) | 0x55;
  k =( k << 8) | 0x55;
  k =( k << 8) | 0x55;
  return !((x & k) ^ k);
}
#line 363
int dividePower2(int x, int n) {
  int s=  x >> 31;
  int b=(  1 << n) + ~0;
  int bx=  x +( s & b);
  return bx >> n;
}
#line 434
int subtractionOK(int x, int y) {
  int diff=  x +( ~y + 1);
  int x_sign=  x >> 31;
  int y_sign=  y >> 31;
  int diff_sign=  diff >> 31;
  int signs_differ=  x_sign ^ y_sign;
  int result_sign_differs=  x_sign ^ diff_sign;
  return !(signs_differ & result_sign_differs);
}
#line 476
int isLessOrEqual(int x, int y) {
  int x_sign=  x >> 31;
  int y_sign=  y >> 31;
  int diff=  x +( ~y + 1);
  int diff_sign=  diff >> 31;
  int same_sign=  !(x_sign ^ y_sign);
  int x_neg_y_pos=  x_sign &( ~y_sign);
  int x_pos_y_neg=(  ~x_sign) & y_sign;
  return (same_sign &( ~diff_sign)) | x_neg_y_pos |(( ~x_pos_y_neg) &( ~diff_sign));
}
#line 531
int rotateRight(int x, int n) {
  int mask=(  1 << n) + ~0;
  int right_bits=  x & mask;
  int left_part=  x >> n;
  int shift_left=  32 + ~n + 1;
  int rotated_right=  right_bits << shift_left;
  return left_part | rotated_right;
}
#line 575
int isAsciiAlpha(int x) {
  int upper_lower=  x + ~0x40;
  int upper_upper=  0x5a + ~x;
  int lower_lower=  x + ~0x60;
  int lower_upper=  0x7a + ~x;
  int is_upper=  !((upper_lower >> 31) |( upper_upper >> 31));
  int is_lower=  !((lower_lower >> 31) |( lower_upper >> 31));
  return is_upper | is_lower;
}
#line 625
int satMul3(int x) {
  int x2=  x + x;
  int result=  x2 + x;
  int x2_sign=  x2 >> 31;
  int x_sign=  x >> 31;
  int result_sign=  result >> 31;
  int overflow=(  x2_sign ^ result_sign) &( ~(x2_sign ^ x_sign));
  int tmax=  ~(1 << 31);
  int tmin=  1 << 31;
  int pos_overflow=  overflow &( ~x_sign);
  int neg_overflow=  overflow & x_sign;
  return (pos_overflow & tmax) |( neg_overflow & tmin) |(( ~overflow) & result);
}
#line 684
unsigned floatScale4(unsigned uf) {
  unsigned sign=  uf & 0x80000000;
  unsigned exp=(  uf >> 23) & 0xFF;
  unsigned frac=  uf & 0x7FFFFF;

  if (exp == 0xFF) {
    return uf;
  }

  if (exp == 0) {
    frac = frac << 2;
    if (frac & 0x800000) {
      exp = 1;
      frac = frac & 0x7FFFFF;
    }
  } else {
    exp = exp + 2;
    if (exp >= 0xFF) {
      exp = 0xFF;
      frac = 0;
    }
  }

  return sign |( exp << 23) | frac;
}
#line 750
int trueSevenSixteenths(int x)
{
  int sign_bit=  x >> 31;
  int abs_x=(  x ^ sign_bit) + ~sign_bit + 1;
  int result=(  abs_x >> 1) +( abs_x >> 2) +( abs_x >> 4);
  result =( result ^ sign_bit) + ~sign_bit + 1;
  return result;
}
