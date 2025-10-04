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
     Note that assment ('=') is not counted; you may use as many of
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
 *   Bytes numbered from 0 (least sificant) to 3 (most sificant)
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
 * s - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: s(130) = 1
 *            s(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int s(int x) {
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
 *   where bits are numbered from 0 (least sificant) to 31 (most sificant)
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
양수는 그냥 오른쪽 시프트하면 2^n으로 나눈 것과 같지만,
음수는 시프트할 때 버림 방향이 0에서 멀어지기 때문에 보정값(bias)이 필요하다.

먼저 s = x >> 31로 부호를 읽어온다. 양수면 0, 음수면 -1이 된다.
바이어스 후보 b는 (1 << n) - 1과 같으니 (1 << n) + ~0으로 만들었다.

음수일 때만 bias를 더해야 하므로 s & b를 이용해 bias를 결정한다.
양수면 0이 되고, 음수면 (2^n - 1)만큼 더해져서 0 쪽으로 반올림되는 효과가 난다.

마지막으로 (x + bias) >> n을 수행하면 원하는 결과를 얻을 수 있다.
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
   * 2. 바이어스 추가 조건: s_bit & bias
   *    - 양수일 때: s_bit = 0 → 0 & bias = 0 (바이어스 추가 안함)
   *    - 음수일 때: s_bit = -1 → (-1) & bias = bias (바이어스 추가)
   * 
   * 3. 최종 계산: (x + bias) >> n
   * 
   * 예시 분석:
   * a) dividePower2(15, 1): x=15, n=1
   *    - s_bit = 0 (양수)
   *    - bias = (1 << 1) - 1 = 1
   *    - biased_x = 15 + (0 & 1) = 15 + 0 = 15
   *    - 결과: 15 >> 1 = 7 ✓
   * 
   * b) dividePower2(-15, 1): x=-15, n=1  
   *    - s_bit = -1 (음수)
   *    - bias = (1 << 1) - 1 = 1
   *    - biased_x = -15 + ((-1) & 1) = -15 + 1 = -14
   *    - 결과: -14 >> 1 = -7 ✓
   * 
   * c) dividePower2(-33, 4): x=-33, n=4
   *    - s_bit = -1 (음수)
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
  int x_s = x >> 31;
  int y_s = y >> 31;
  int diff_s = diff >> 31;
  int ss_differ = x_s ^ y_s;
  int result_s_differs = x_s ^ diff_s;
  return !(ss_differ & result_s_differs);
}
/* 
일단 x - y를 계산해야 한다.
그런데 뺄셈 연산자는 사용할 수 없으므로 2의 보수를 이용해서 더하기로 바꾼다.
x - y = x + (~y + 1) 이므로 diff = x + (~y + 1)로 계산한다.

그 다음에 각각의 부호 비트를 추출한다.
x_s = x >> 31로 x의 부호 비트를 얻고
y_s = y >> 31로 y의 부호 비트를 얻고  
diff_s = diff >> 31로 결과의 부호 비트를 얻는다.

이제 오버플로우가 발생하는 조건을 확인해야 한다.
오버플로우는 x와 y의 부호가 다르면서 결과의 부호가 x와 다를 때 발생한다.

ss_differ = x_s ^ y_s로 x와 y의 부호가 다른지 확인한다.
x와 y가 같은 부호면 0이 나오고, 다른 부호면 1이 나온다.

result_s_differs = x_s ^ diff_s로 결과의 부호가 x와 다른지 확인한다.
결과가 x와 같은 부호면 0이 나오고, 다른 부호면 1이 나온다.

오버플로우가 발생하는 경우는 ss_differ가 1이고 result_s_differs도 1인 경우다.
따라서 ss_differ & result_s_differs로 오버플로우 여부를 확인한다.
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
  int x_s = x >> 31;
  int y_s = y >> 31;
  int s_diff = x_s ^ y_s;
  int diff = y + (~x + 1);
  int diff_s = diff >> 31;
  int d_n = !(diff_s & 1);ㄴㅇㄻㄴㄹ
  return (s_diff & (x_s & 1)) | ((!s_diff) & d_n);
}
/* 
일단 부호가 다르면 x가 음수고 y가 양수인 상황만 따지면 된다.
그래서 x_s과 y_s을 비교해서 다르면 s_diff가 1이 된다.
s_diff가 1이면서 x_s의 최하위 비트가 1이면(x < 0, y >= 0) 무조건 x <= y이다.

부호가 같다면 이제 y - x가 음수인지 아닌지만 보면 된다.
바로 빼면 안 되니까 2의 보수로 diff = y + (~x + 1)을 구한다.
이때 diff_s은 diff의 부호이고, 음수면 최상위 비트가 1이다.

diff가 음수일 때만 diff_s & 1이 1이 되므로
d_n = !(diff_s & 1)을 만들어서 diff >= 0이면 1이 나오게 했다.

정리하면 s_diff가 1이고 x가 음수면 바로 참,
s_diff가 0이면 d_n로 y - x가 음수인지 판단해서 결론을 낸다.
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
  int l_m = (1 << n) + ~0;
  int r_b = x & l_m;
  int shift = (32 + (~n + 1)) & 31;
  int r_l = r_b << shift;
  int l_m = ~(((1 << 31) >> n) << 1);
  int r_p = (x >> n) & l_m;
  return r_l | r_p;
}
/* 
오른쪽 회전은 하위 n비트를 떼어서 위쪽으로 붙이고, 나머지는 논리 시프트로 이동시키면 된다.
우선 l_m = (1 << n) + ~0으로 하위 n비트만 1인 마스크를 만들고 r_b에 저장한다.

r_b를 왼쪽 끝으로 보내야 하니까 32-n만큼 이동해야 하는데,
shift = (32 + (~n + 1)) & 31로 32-n을 계산하면서 0~31 범위를 유지했다.
r_l = r_b << shift로 잘라낸 비트를 위쪽으로 옮긴다.

왼쪽에 남은 비트들은 단순히 산술 시프트하면 부호비트가 채워지니 안 된다.
그래서 l_m = ~(((1 << 31) >> n) << 1)로 오른쪽 이동 뒤에 남겨야 할 비트만 1인 마스크를 만들었다.
r_p = (x >> n) & l_m로 산술 시프트 뒤에 남은 비트들을 깨끗하게 만들어준다.

마지막으로 r_l | r_p로 두 조각을 합치면 오른쪽 회전이 완성된다.
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
  int upper = x & ~0x20;
  int lower_cmp = upper + ~0x40;
  int upper_cmp = 0x5A + (~upper + 1);
  return !((lower_cmp >> 31) | (upper_cmp >> 31));
}
/* 
대소문자 둘 다 처리하고 싶어서 먼저 x의 5번째 비트를 지웠다.
ASCII에서 소문자는 대문자보다 0x20만큼 크니까 upper = x & ~0x20을 하면 무조건 대문자 범위로 맞춰진다.

그 상태에서 'A'(0x41) 이상인지, 'Z'(0x5A) 이하인지 두 번 비교하면 된다.
lower_cmp = upper - 0x41을 2의 보수로 계산했고, upper_cmp = 0x5A - upper도 마찬가지다.

둘 중 하나라도 음수가 나오면 범위를 벗어난 것이므로 부호 비트를 보고 판단한다.
결국 두 부호 비트가 모두 0이어야만 알파벳이니까, or로 묶은 뒤 !를 씌워서 결과를 얻는다.
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
  int d = x + x;
  int t = d + x;
  int o_b = (x ^ d) | (d ^ t);
  int o_m = o_b >> 31;
  int s = x >> 31;
  int tmin = 1 << 31;
  int tmax = ~tmin;
  int sat = (s & tmin) | ((~s) & tmax);
  return (o_m & sat) | ((~o_m) & t);
}
/* 
3배는 결국 x + x + x이지만, 중간과 최종 덧셈에서 오버플로가 났는지 확인해야 한다.
그래서 d = x + x, t = d + x로 계산하고
(x ^ d) | (d ^ t)로 두 번의 연산 중 하나라도 부호가 바뀌었는지를 살핀다.

o_b를 31만큼 오른쪽으로 밀면 o_m가 부호 확장으로 가득 차게 된다.
0이면 정상이고, -1이면 오버플로가 있었다는 뜻이다.

오버플로가 났다면 x의 부호에 맞춰 Tmin 혹은 Tmax로 포화시켜야 한다.
s = x >> 31로 원래 부호를 얻고, sat = (s & Tmin) | (~s & Tmax)로 적절한 끝값을 만든다.

마지막으로 o_m가 -1이면 sat를, 0이면 t를 선택하도록
(o_m & sat) | ((~o_m) & t)로 결과를 조립했다.
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
  unsigned s = uf & 0x80000000;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x7FFFFF;

  if (exp == 0xFF) {
    return uf;
  }

  if (exp == 0) {
    frac <<= 1;
    if (frac & 0x800000) {
      exp = 1;
      frac &= 0x7FFFFF;
    }
  } else {
    exp += 1;
    if (exp == 0xFF) {
      return s | (0xFF << 23);
    }
  }

  if (exp == 0) {
    frac <<= 1;
    if (frac & 0x800000) {
      exp = 1;
      frac &= 0x7FFFFF;
    }
  } else {
    exp += 1;
    if (exp >= 0xFF) {
      return s | (0xFF << 23);
    }
  }

  return s | (exp << 23) | frac;
}
/* 
4배를 바로 하려면 한 번에 지수를 2만큼 올리거나, 정규/비정규 경계에서 가수를 조정해야 한다.
그래서 2배를 두 번 하는 방식으로 나눠서 생각했다.

먼저 s, exp, frac을 각각 분리하고 exp가 0xFF면 그대로 반환한다.

첫 번째 2배 단계:
exp가 0이면(비정규 수면) frac을 한 칸 왼쪽으로 밀어서 값만 키운다.
이때 24번째 비트가 생기면 exp를 1로 올리고 frac에서 해당 비트를 지워서 정규 수 상태를 만든다.

exp가 0이 아니라면 지수를 1만큼 올리면 2배가 된다.
올렸더니 곧바로 0xFF에 도달하면 이미 무한대가 되었으므로 s | (0xFF << 23)을 반환한다.

두 번째 2배 단계도 동일한 과정을 반복한다.
여전히 exp가 0이면 frac을 한 번 더 올리고, 정규화되는 순간 exp=1로 설정한다.
exp가 양수라면 다시 exp를 1 증가시키고, 0xFF 이상으로 올라가면 바로 무한대로 포화시킨다.

두 단계를 모두 통과했다면 마지막으로 s | (exp << 23) | frac으로 4배 결과를 만들어낸다.
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
  int s = x >> 31;
  int n_s = ~s + 1;
  int a = (x ^ s) + n_s;
  int m = (1 << 28) + ~0;
  int b = (a >> 4) & m;
  int b_p = b + (b << 1) + (b << 2);
  int r = a & 0xF;
  int r_p = (r + (r << 1) + (r << 2)) >> 4;
  int magnitude = b_p + r_p;
  return (magnitude ^ s) + n_s;
}
/* 
7/16은 4/16 + 2/16 + 1/16이니까 결국 세 번의 나눗셈 결과를 더하면 된다.
다만 음수는 0 쪽으로 반올림해야 하므로 먼저 절댓값으로 계산하고 마지막에 부호를 복원한다.

s = x >> 31에서 부호를 뽑고, n_s = ~s + 1을 써서 (s이 0이면 0, -1이면 1)이 되게 했다.
a = (x ^ s) + n_s으로 절댓값을 구한다.

a를 16으로 나눌 때 상위로 전파되는 비트가 생기면 안 되므로 m = (1 << 28) + ~0을 사용해서
(b << 1)이나 (b << 2)를 해도 오버플로로 망가지지 않게 상위 네 비트를 미리 0으로 만든다.
b = (a >> 4) & m로 16으로 나눈 몫을 구하고,
b_p = b + (b << 1) + (b << 2)로 몫에 7을 곱한 값을 만든다.

나머지 r = a & 0xF를 따로 계산해서
r_p = (r + (r << 1) + (r << 2)) >> 4로 7/16을 반영했다.

둘을 더한 magnitude가 절댓값 결과이고,
마지막에 (magnitude ^ s) + n_s을 해서 원래 부호를 붙여준다.
*/
