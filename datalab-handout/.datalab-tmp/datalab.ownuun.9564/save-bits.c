/* 
 * CS:APP Data Lab 
 * 
 * <서원준 / 2024315332>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y);
}
/* 
&는 둘 다 1이면 1이 나오고, 하나라도 0이면 0이 나온다. 
|은 둘 다 0이면 0이 나오고, 하나라도 1이면 1이 나온다.
따라서 ~x | ~y 하면 둘 다 1을 넣으면 0이 나오고, 하나라도 0이 들어가면 1이 나온다.
따라서 ~(~x | ~y)하면 둘 다 1을 넣으면 1이 나오고, 하나라도 0이 들어가면 0이 나온다.
이는 즉 x&y와 같다.
*/
//-----------------------------------------------------------------------------
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  int result = 0x55;
  result = (result << 8) | 0x55;
  result = (result << 8) | 0x55;
  result = (result << 8) | 0x55;
  return result;
}
/* 
32비트의 짝수번째 비트를 1로 만들어야 한다.
짝수번째 비트는 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30번째 비트이다.
0x55는 01010101이다.
0x55를 8비트씩 왼쪽으로 옮기면 0x5500, 0x550000, 0x55000000이 된다.
이를 OR연산하면 0x5555, 0x555500, 0x55550000, 0x5555000000이 된다.
따라서 0x55555555가 된다.
이는 즉 32비트의 짝수번째 비트를 1로 만든 값이다.
*/
//-----------------------------------------------------------------------------
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
  return ~x & ~y;
}
/*
|은 둘 다 0이면 0이 나오고, 하나라도 1이면 1이 나온다.
따라서 ~(x | y) 하면 둘 다 0을 넣으면 1이 나오고, 하나라도 1이 들어가면 0이 나온다.
&는 둘 다 1이면 1이 나오고, 하나라도 0이면 0이 나온다.
따라서 ~x & ~y 하면 둘 다 0을 넣으면 1이 나오고, 하나라도 1이 들어가면 0이 나온다.
이는 즉 ~(x|y)와 같다.
*/
//-----------------------------------------------------------------------------
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int isPositive(int x) {
  return !((x >> 31) | !x);
}
/* 
일단 양수가 되기 위한 조건은 부호 비트가 0이고, 값이 0이 아니어야 한다.
부호 비트는 x >> 31이다.
양수라면 부호비트는 0이다.
그리고 !x을 했을 때 0이라면 1이 나오고, 0이 아니라면 0이 나온다.
부호비트가 0이고 값이 0이 아니라는 것을 나타내면서 양수라면 1을 반환하게 하려면,
둘 다 0이 들어오면 양수라는 의미이기 때문에, |를 사용하고 밖에 !를 사용하면 
양수를 판정하여 양수면 1이 나오게 된다. 
따라서 !((x >> 31) | !x)와 같다.
*/
//-----------------------------------------------------------------------------
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  int s = n << 3;  
  return (x >> s) & 0xFF;  
}
/* 
일단 n이 1 증가할수록 1바이트씩 오른쪽으로 올라가서 잘라내야하기 때문에 
8비트씩 올라가야한다. 
8비트는 3비트 시프트를 해야한다. 
그래서 n << 3을 해야한다.
그러면 원하는 바이트가 하위 8비트 위치에 오게 된다.
그렇게 한 다음 나머지를 없애햐하기 때문에 
그러면 0xFF로 &를 씌워서 나머지를 없애야한다.
그러면 원하는 바이트가 나오게 된다.
*/
//-----------------------------------------------------------------------------
/*
 * isSymmetric - return 1 if x is symmetrical, 0 otherwise
 * Example: isSymtetric(0x12341234) = 1 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 7
 *   Rating: 2
 */
int isSymmetric(int x) {
  int k = 0xFF;
  k = (k << 8) | 0xFF;  
  return !(((x & k) ^ ((x >> 16) & k)));  
}
/* 
우선 상위 16비트와 하위 16비트를 비교해야한다. 
일단 0xFFFF를 만들어서 1111111111111111를 만든 후
x와 &를 씌우고 우선 오른쪽 16비트중에서 1인 것들만 남긴다.
그 다음은 x를 오른쪽으로 16자리 시프트를 해서 위와 같은 절차를 하여
상위 16비트중에서 1인 것들만 남긴다.
그 다음은 둘을 xor로 비교하면 같으면 0이 나오고 다르면 1이 나오게 한다.
그러면 같으면 0이 나오고 다르면 0이 아닌 값이 나오게 된다.
그 다음은 not을 씌워서 모두 같아서 대칭이라면 1이 나오게 하고 
하나라도 다르다면 0이 나오게 한다.
*/
//-----------------------------------------------------------------------------
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
  int s = x >> 31; 
  int z = !x; 
  return s | (!z & !s); 
}
/* 
일단 x의 부호를 추출한다.
그러기 위해서는 오른쪽으로 31번 시프르를 진행하여 부호 비트를 추출한다.
그렇게 해서 부호비트가 0이면 양수고 1로만 채워져있으면 음수이다.
일단 부호비트가 1로만 채워져있으면 무조건 음수이다.
그 다음 부호비트가 0이면 양수인지 0인지 확인해야한다.
그러기 위해서는 !x를 해야한다.
그러면 x가 0이면 1이 나오고 x가 0이 아니면 0이 나오게 된다.
일단 z=0이면 x가 0이 아니고, z=1이면 x가 0이다.
그렇게 하고  s | (!z & !s)를 하면 
일단 음수면 s는 1로만 이루어져있고, !s는 0, !z는 1이 된다. 따라서 리턴값은 -1이 나온다
0이라면 s는 0이고, z는1이다. 따라서 리턴값은 0이 나온다.
양수라면 s는 0이고, z는 0이다. 따라서 리턴값은 1이 나온다.
*/
//-----------------------------------------------------------------------------
/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
  int k = 0x55;
  k = (k << 8) | 0x55;
  k = (k << 8) | 0x55;
  k = (k << 8) | 0x55;
  return !((x & k) ^ k);
} 
/* 
일단 짝수 번째 비트가 1로 설정되어 있는 패턴을 만들고
그것과 and로 비교하고 
그 비교한 것을 다시 짝수번째 비트가 1로 설정되어있는것과 비교해야한다.
우선 둘이 같으면 1이 나오게 하고
같지않으면 0이 나와야하므로
일단 xor로 비교한다.
짝수번째 비트가 모두 1이었다면 0이 나올 것이고, 하나라도 0이 있었다면 0이 아니고 1이 섞여있을 것이다.
따라서 나온 결과를 !로 취해주면 
짝수번째 비트가 모두 1이었다면 1이 나오고
짝수번째 비트중에 하나라도 0이 있었다면 0이 나오게 된다.
*/
//-----------------------------------------------------------------------------
/* 
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: dividePower2(15,1) = 7, dividePower2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dividePower2(int x, int n) {
  int s = x >> 31; 
  int b = (1 << n) + ~0;
  int bx = x + (s & b);
  return bx >> n;
}
/* 
일단 반올림을 고려한 수를 만든 이후에 시프트를 진행하고자 한다.
우선은 x의 부호를 추출한다.
그러기 위해서는 오른쪽으로 31번 시프르를 진행하여 부호 비트를 추출한다.
그렇게 해서 부호비트가 0이면 양수고 1로만 채워져있으면 음수이다.
그 다음 반올림을 고려한 수를 만들어보자
1 << n을 하고 그 다음에 ~0(-1)을 더하면 n의 개수만큼 1이 이루어진 값에서 
-1을 더한 값이 된다.
그렇게 하면 s는 0이면 양수고 1로만 채워져있으면 음수이고
b는 0이면 양수고 1로만 채워져있으면 음수이다.

그 다음에 &를 씌워서 양수일 때는 0이 나오고 음수일 때는 bias가 나오게 한다.
그 다음에 x에 바이어스를 추가하고 그 다음에 n비트만큼 오른쪽으로 시프트를 하면 된다.
*/
/* 
   * x를 2^n으로 나누는 함수 (0 방향으로 반올림)
   * 
   * 0 방향 반올림의 필요성:
   * 1. 양수의 경우: 단순히 오른쪽 시프트하면 됨
   *    - 예: 15 >> 1 = 7 (15/2 = 7.5 → 7로 반올림)
   * 
   * 2. 음수의 경우: 문제 발생
   *    - 예: -15 >> 1 = -8 (하지만 -15/2 = -7.5 → -7로 반올림해야 함)
   *    - 음수에서 시프트만 하면 더 작은 음수가 됨 (0에서 멀어짐)
   * 
   * 바이어스 추가 방법:
   * 1. 바이어스 계산: (1 << n) - 1
   *    - n=1일 때: (1 << 1) - 1 = 2 - 1 = 1
   *    - n=2일 때: (1 << 2) - 1 = 4 - 1 = 3
   *    - n=4일 때: (1 << 4) - 1 = 16 - 1 = 15
   * 
   * 2. 바이어스 추가 조건: sign_bit & bias
   *    - 양수일 때: sign_bit = 0 → 0 & bias = 0 (바이어스 추가 안함)
   *    - 음수일 때: sign_bit = -1 → (-1) & bias = bias (바이어스 추가)
   * 
   * 3. 최종 계산: (x + bias) >> n
   * 
   * 예시 분석:
   * a) dividePower2(15, 1): x=15, n=1
   *    - sign_bit = 0 (양수)
   *    - bias = (1 << 1) - 1 = 1
   *    - biased_x = 15 + (0 & 1) = 15 + 0 = 15
   *    - 결과: 15 >> 1 = 7 ✓
   * 
   * b) dividePower2(-15, 1): x=-15, n=1  
   *    - sign_bit = -1 (음수)
   *    - bias = (1 << 1) - 1 = 1
   *    - biased_x = -15 + ((-1) & 1) = -15 + 1 = -14
   *    - 결과: -14 >> 1 = -7 ✓
   * 
   * c) dividePower2(-33, 4): x=-33, n=4
   *    - sign_bit = -1 (음수)
   *    - bias = (1 << 4) - 1 = 15
   *    - biased_x = -33 + ((-1) & 15) = -33 + 15 = -18
   *    - 결과: -18 >> 4 = -2 ✓
   */
//-----------------------------------------------------------------------------
/* 
 * subtractionOK - Determine if can compute x-y without overflow
 *   Example: subtractionOK(0x80000000,0x80000000) = 1,
 *            subtractionOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subtractionOK(int x, int y) {
  int diff = x + (~y + 1);
  int x_sign = x >> 31;
  int y_sign = y >> 31;
  int diff_sign = diff >> 31;
  int signs_differ = x_sign ^ y_sign;
  int result_sign_differs = x_sign ^ diff_sign;
  return !(signs_differ & result_sign_differs);
}
/* 
일단 x - y를 계산해야 한다.
그런데 뺄셈 연산자는 사용할 수 없으므로 2의 보수를 이용해서 더하기로 바꾼다.
x - y = x + (~y + 1) 이므로 diff = x + (~y + 1)로 계산한다.

그 다음에 각각의 부호 비트를 추출한다.
x_sign = x >> 31로 x의 부호 비트를 얻고
y_sign = y >> 31로 y의 부호 비트를 얻고  
diff_sign = diff >> 31로 결과의 부호 비트를 얻는다.

이제 오버플로우가 발생하는 조건을 확인해야 한다.
오버플로우는 x와 y의 부호가 다르면서 결과의 부호가 x와 다를 때 발생한다.

signs_differ = x_sign ^ y_sign로 x와 y의 부호가 다른지 확인한다.
x와 y가 같은 부호면 0이 나오고, 다른 부호면 1이 나온다.

result_sign_differs = x_sign ^ diff_sign로 결과의 부호가 x와 다른지 확인한다.
결과가 x와 같은 부호면 0이 나오고, 다른 부호면 1이 나온다.

오버플로우가 발생하는 경우는 signs_differ가 1이고 result_sign_differs도 1인 경우다.
따라서 signs_differ & result_sign_differs로 오버플로우 여부를 확인한다.
오버플로우가 발생하면 1이 나오고, 발생하지 않으면 0이 나온다.

마지막에 !를 씌워서 오버플로우가 없으면 1을 반환하고, 있으면 0을 반환하도록 한다.
*/
//-----------------------------------------------------------------------------
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int x_sign = x >> 31;
  int y_sign = y >> 31;
  int diff = x + (~y + 1);
  int diff_sign = diff >> 31;
  int same_sign = !(x_sign ^ y_sign);
  int x_neg_y_pos = x_sign & (~y_sign);
  int x_pos_y_neg = (~x_sign) & y_sign;
  return (same_sign & (~diff_sign)) | x_neg_y_pos | ((~x_pos_y_neg) & (~diff_sign));
}
/* 
일단 x <= y를 판단하려면 x - y를 계산해서 그 결과가 0 이하인지 확인하면 된다.
그런데 단순히 x - y를 계산하면 오버플로우가 발생할 수 있으므로 경우를 나눠서 생각해야 한다.

먼저 각 값의 부호 비트를 추출한다.
x_sign = x >> 31로 x의 부호 비트를 얻고
y_sign = y >> 31로 y의 부호 비트를 얻는다.

그 다음에 x - y를 계산한다.
diff = x + (~y + 1)로 2의 보수를 이용해서 뺄셈을 한다.
diff_sign = diff >> 31로 차이의 부호 비트를 얻는다.

이제 경우를 나눠서 생각한다.

첫 번째 경우는 x와 y의 부호가 같은 경우다.
same_sign = !(x_sign ^ y_sign)로 부호가 같은지 확인한다.
부호가 같으면 1이 나오고, 다르면 0이 나온다.
부호가 같으면 오버플로우가 발생하지 않으므로 diff_sign만 확인하면 된다.
diff_sign이 1이면 x - y가 음수 또는 0이므로 x <= y가 참이다.
그런데 우리는 diff_sign이 0일 때(x > y)를 제외해야 하므로 ~diff_sign을 사용한다.

두 번째 경우는 x가 음수이고 y가 양수인 경우다.
x_neg_y_pos = x_sign & (~y_sign)로 확인한다.
이 경우는 항상 x <= y가 참이므로 이것만으로도 1을 반환해야 한다.

세 번째 경우는 x가 양수이고 y가 음수인 경우다.
x_pos_y_neg = (~x_sign) & y_sign으로 확인한다.
이 경우는 항상 x > y이므로 x <= y가 거짓이다.
따라서 이 경우를 제외해야 하므로 ~x_pos_y_neg를 사용한다.

마지막으로 이 세 가지 경우를 조합한다.
(same_sign & (~diff_sign))은 부호가 같고 x - y가 양수인 경우를 의미하고
x_neg_y_pos는 x가 음수이고 y가 양수인 경우를 의미하고
((~x_pos_y_neg) & (~diff_sign))은 x가 양수이고 y가 음수가 아니면서 diff가 양수가 아닌 경우를 의미한다.
이 세 가지를 or로 연결해서 하나라도 참이면 1을 반환한다.
*/
//-----------------------------------------------------------------------------
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x187654321
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
  int mask = (1 << n) + ~0;
  int right_bits = x & mask;
  int left_part = x >> n;
  int shift_left = 32 + ~n + 1;
  int rotated_right = right_bits << shift_left;
  return left_part | rotated_right;
}
/* 
일단 오른쪽으로 회전시킨다는 것은 오른쪽 끝에서 밀려나는 비트들을 왼쪽 끝으로 가져온다는 의미다.
그래서 두 부분으로 나눠서 생각해야 한다.

첫 번째는 오른쪽 끝에서 밀려날 하위 n개 비트를 추출해야 한다.
이를 위해서 마스크를 만들어야 한다.
mask = (1 << n) + ~0으로 하위 n개 비트만 1인 마스크를 만든다.
예를 들어 n = 4이면 (1 << 4) + ~0 = 16 - 1 = 15 = 0x0000000F가 된다.

그 다음에 이 마스크와 x를 and 연산해서 하위 n개 비트를 추출한다.
right_bits = x & mask로 오른쪽 끝에서 밀려날 비트들을 저장한다.

두 번째는 나머지 비트들을 오른쪽으로 n만큼 시프트해야 한다.
left_part = x >> n으로 x를 오른쪽으로 n만큼 시프트한다.
이렇게 하면 상위 (32-n)개 비트가 오른쪽으로 이동한다.

세 번째는 추출한 하위 n개 비트를 왼쪽 끝으로 보내야 한다.
이를 위해서는 (32-n)만큼 왼쪽으로 시프트해야 한다.
shift_left = 32 + ~n + 1로 32 - n을 계산한다.
이것은 2의 보수를 이용한 뺄셈이다.

그 다음에 추출한 비트들을 왼쪽으로 시프트한다.
rotated_right = right_bits << shift_left로 하위 비트들을 상위로 이동시킨다.

마지막으로 두 부분을 합친다.
left_part | rotated_right로 오른쪽 시프트한 부분과 왼쪽으로 이동한 부분을 or 연산으로 결합한다.
*/
//-----------------------------------------------------------------------------
/*
 * isAsciiAlpha - return 1 if 0x41 <= x <= 0x5a or 0x61 <= x <= 0x7a (ASCII
 * codes for characters 'a' to 'z' and 'A' to 'Z') Example:
 * isAsciiAlpha(0x45) = 1. isAsciiAlpha(0x3a) = 0. isAsciiAlpha(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int isAsciiAlpha(int x) {
  int upper_lower = x + ~0x40;
  int upper_upper = 0x5a + ~x;
  int lower_lower = x + ~0x60;
  int lower_upper = 0x7a + ~x;
  int is_upper = !((upper_lower >> 31) | (upper_upper >> 31));
  int is_lower = !((lower_lower >> 31) | (lower_upper >> 31));
  return is_upper | is_lower;
}
/* 
일단 x가 알파벳 문자인지 확인하려면 두 가지 범위를 확인해야 한다.
대문자 'A'부터 'Z'까지(0x41부터 0x5A까지)와 소문자 'a'부터 'z'까지(0x61부터 0x7A까지)다.

먼저 대문자 범위를 확인한다.
upper_lower = x + ~0x40으로 x - 0x41을 계산한다.
x가 0x41보다 크거나 같으면 이 값은 0 이상이 되고, 작으면 음수가 된다.

upper_upper = 0x5a + ~x로 0x5A - x를 계산한다.
x가 0x5A보다 작거나 같으면 이 값은 0 이상이 되고, 크면 음수가 된다.

그 다음에 이 두 값의 부호 비트를 확인한다.
(upper_lower >> 31)로 upper_lower의 부호 비트를 얻고
(upper_upper >> 31)로 upper_upper의 부호 비트를 얻는다.
둘 중 하나라도 음수면 or 연산으로 1이 나온다.

is_upper = !((upper_lower >> 31) | (upper_upper >> 31))로 대문자 범위인지 확인한다.
둘 다 양수면 0 | 0 = 0이 되고 !0 = 1이 된다.
하나라도 음수면 1이 섞여있으므로 !1 = 0이 된다.

이제 소문자 범위도 똑같은 방식으로 확인한다.
lower_lower = x + ~0x60으로 x - 0x61을 계산하고
lower_upper = 0x7a + ~x로 0x7A - x를 계산한다.

is_lower = !((lower_lower >> 31) | (lower_upper >> 31))로 소문자 범위인지 확인한다.

마지막으로 대문자 범위이거나 소문자 범위이면 알파벳이므로
is_upper | is_lower로 둘 중 하나라도 참이면 1을 반환한다.
*/
//-----------------------------------------------------------------------------
/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {
  int x2 = x + x;
  int result = x2 + x;
  int x2_sign = x2 >> 31;
  int x_sign = x >> 31;
  int result_sign = result >> 31;
  int overflow = (x2_sign ^ result_sign) & (~(x2_sign ^ x_sign));
  int tmax = ~(1 << 31);
  int tmin = 1 << 31;
  int pos_overflow = overflow & (~x_sign);
  int neg_overflow = overflow & x_sign;
  return (pos_overflow & tmax) | (neg_overflow & tmin) | ((~overflow) & result);
}
/* 
일단 x에 3을 곱해야 한다.
곱셈은 사용할 수 없으므로 x + x + x로 계산한다.
x2 = x + x로 2*x를 구하고
result = x2 + x로 3*x를 구한다.

그런데 이 과정에서 오버플로우가 발생할 수 있다.
오버플로우가 발생하면 Tmin이나 Tmax로 값을 제한해야 한다.

먼저 각각의 부호 비트를 추출한다.
x2_sign = x2 >> 31로 2*x의 부호 비트를 얻고
x_sign = x >> 31로 x의 부호 비트를 얻고
result_sign = result >> 31로 결과의 부호 비트를 얻는다.

이제 오버플로우를 감지해야 한다.
오버플로우는 x2와 x의 부호가 같은데 결과의 부호가 다를 때 발생한다.
(x2_sign ^ result_sign)로 x2와 result의 부호가 다른지 확인하고
~(x2_sign ^ x_sign)로 x2와 x의 부호가 같은지 확인한다.
이 둘을 and로 연결하면 overflow 여부를 알 수 있다.

그 다음에 Tmax와 Tmin 값을 만든다.
tmax = ~(1 << 31)로 0x7FFFFFFF를 만들고
tmin = 1 << 31로 0x80000000을 만든다.

이제 오버플로우가 양수에서 발생했는지 음수에서 발생했는지 확인한다.
pos_overflow = overflow & (~x_sign)로 양수 오버플로우를 확인하고
neg_overflow = overflow & x_sign으로 음수 오버플로우를 확인한다.

마지막으로 결과를 조합한다.
양수 오버플로우면 tmax를 반환하고
음수 오버플로우면 tmin을 반환하고
오버플로우가 없으면 result를 반환한다.
(pos_overflow & tmax) | (neg_overflow & tmin) | ((~overflow) & result)로 세 가지 경우를 or로 연결한다.
*/
//-----------------------------------------------------------------------------
/* 
 * floatScale4 - Return bit-level equivalent of expression 4*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale4(unsigned uf) {
  unsigned sign = uf & 0x80000000;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x7FFFFF;
  
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
  
  return sign | (exp << 23) | frac;
}
/* 
일단 부동소수점 수에 4를 곱해야 한다.
부동소수점은 부호 비트, 지수 부분, 가수 부분으로 나뉜다.

먼저 각 부분을 추출한다.
sign = uf & 0x80000000으로 부호 비트를 추출하고
exp = (uf >> 23) & 0xFF로 지수 부분(8비트)을 추출하고
frac = uf & 0x7FFFFF로 가수 부분(23비트)을 추출한다.

그 다음에 특수한 경우를 처리한다.
exp == 0xFF면 NaN이거나 무한대이므로 그대로 반환한다.

이제 일반적인 경우를 처리한다.
exp == 0이면 비정규화된 수다.
비정규화된 수는 가수 부분만 왼쪽으로 2칸 시프트해서 4배를 만든다.
frac = frac << 2로 가수를 4배로 만든다.
그런데 이렇게 하면 가수가 23비트를 넘어갈 수 있다.
frac & 0x800000로 24번째 비트가 1인지 확인한다.
1이면 정규화된 수로 바뀌어야 하므로 exp = 1로 설정하고
frac = frac & 0x7FFFFF로 24번째 비트를 제거한다.

exp가 0이 아니면 정규화된 수다.
정규화된 수는 지수에 2를 더해서 4배를 만든다.
exp = exp + 2로 지수를 2 증가시킨다.
그런데 이렇게 하면 지수가 0xFF 이상이 될 수 있다.
exp >= 0xFF면 무한대가 되므로 exp = 0xFF로 설정하고 frac = 0으로 만든다.

마지막으로 부호, 지수, 가수를 다시 조합한다.
sign | (exp << 23) | frac로 세 부분을 or 연산으로 결합한다.
*/
//-----------------------------------------------------------------------------
/*
 * trueSevenSixteenths - multiplies by 7/16 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueSevenSixteenths(11) = 4
 *            trueSevenSixteenths(-9) = -3
 *            trueSevenSixteenths(0x30000000) = 0x15000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueSevenSixteenths(int x)
{
  int sign_bit = x >> 31;
  int abs_x = (x ^ sign_bit) + ~sign_bit + 1;
  int result = (abs_x >> 1) + (abs_x >> 2) + (abs_x >> 4);
  result = (result ^ sign_bit) + ~sign_bit + 1;
  return result;
}
/* 
일단 x에 7/16을 곱해야 한다.
7/16 = 1/2 + 1/4 + 1/16이므로 (x >> 1) + (x >> 2) + (x >> 4)로 계산할 수 있다.

그런데 음수의 경우 오른쪽 시프트를 하면 반올림 방향이 0이 아니라 음의 무한대 방향이 된다.
따라서 0 방향으로 반올림하려면 절댓값으로 계산한 다음 부호를 다시 붙여야 한다.

먼저 부호 비트를 추출한다.
sign_bit = x >> 31로 x의 부호 비트를 얻는다.
x가 양수면 0이 나오고, 음수면 -1(모든 비트가 1)이 나온다.

그 다음에 절댓값을 구한다.
abs_x = (x ^ sign_bit) + ~sign_bit + 1로 x의 절댓값을 구한다.
x가 양수면 x ^ 0 = x이고 ~0 + 1 = 0이므로 x + 0 = x가 된다.
x가 음수면 x ^ -1은 비트 반전이고 ~(-1) + 1 = 1이므로 반전된 값에 1을 더하면 절댓값이 된다.

이제 절댓값에 7/16을 곱한다.
result = (abs_x >> 1) + (abs_x >> 2) + (abs_x >> 4)로 abs_x * (1/2 + 1/4 + 1/16)를 계산한다.
abs_x >> 1은 abs_x / 2이고
abs_x >> 2는 abs_x / 4이고
abs_x >> 4는 abs_x / 16이므로
이를 모두 더하면 abs_x * 7/16이 된다.

마지막으로 원래의 부호를 다시 붙인다.
result = (result ^ sign_bit) + ~sign_bit + 1로 부호를 적용한다.
result가 양수였고 원래 x도 양수였으면 그대로 양수로 유지되고
result가 양수였고 원래 x가 음수였으면 음수로 변환된다.
*/
