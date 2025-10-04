# CS:APP Data Lab

## 학생 안내

`bits.c`를 수정하여 모든 함수를 `btest`로 검증받고, 주어진 코딩 규칙을 위반하지 않는 것이 목표입니다.

## 0. 제공 파일

- `Makefile` – `btest`, `fshow`, `ishow`를 빌드
- `README` – 원본 안내 문서
- `bits.c` – 여러분이 수정하고 제출할 구현 파일
- `bits.h` – 퍼즐 함수 선언을 담은 헤더
- `btest.c` – 테스트 하네스의 메인 드라이버
  - `btest.h` – `btest` 빌드용 보조 파일
  - `decl.c` – `btest` 빌드용 보조 파일
  - `tests.c` – `btest` 빌드용 보조 파일
  - `tests-header.c` – `btest` 빌드용 보조 파일
- `dlc*` – 코딩 규칙을 검사하는 Data Lab Checker 바이너리
- `driver.pl*` – `btest`와 `dlc`를 실행해 자가 채점을 도와주는 스크립트
- `Driverhdrs.pm` – 선택 과제 “Beat the Prof” 지원 파일
- `fshow.c` – 부동소수점 비트 패턴을 확인하는 유틸리티
- `ishow.c` – 정수 표현을 확인하는 유틸리티

(`*`가 붙은 항목은 실행 파일 혹은 스크립트입니다.)

## 1. `bits.c` 편집과 `dlc` 사용법

작업을 시작하기 전에 `bits.c`에 포함된 주석을 반드시 읽으세요. 모든 코딩 제약이 여기에 정의되어 있습니다.

Data Lab Checker를 사용하면 풀이가 규칙을 만족하는지 확인할 수 있습니다.

```bash
./dlc bits.c
```

문제가 없으면 `dlc`는 아무 메시지 없이 종료합니다. 각 함수의 연산자 사용 개수를 보려면 `-e` 옵션을 사용하세요.

```bash
./dlc -e bits.c
```

규칙을 통과한 구현이라면 이어서 `btest`로 기능적 정확성을 점검하세요.

## 2. `btest`로 테스트하기

`Makefile`은 갱신된 `bits.c`와 지원 코드를 함께 컴파일하여 `btest` 실행 파일을 만들어 줍니다. `bits.c`를 수정할 때마다 다시 빌드하세요.

```bash
make btest
./btest [옵션]
```

다른 환경에서 작업을 이어갈 때는 아래처럼 완전히 다시 빌드하는 것이 안전합니다.

```bash
make clean
make btest
```

`btest`는 각 함수를 수백만 개의 입력으로 검증합니다. 정수 퍼즐의 `Tmin`, `0`과 같은 경계값, 부동소수점 퍼즐의 비정규값/정규값 경계 등을 집중적으로 시험합니다. 실패하면 문제를 일으킨 입력, 여러분의 결과, 기대 결과를 출력하고 해당 함수의 검증을 중단합니다.

명령줄 옵션은 다음과 같습니다.

```
./btest -h
Usage: ./btest [-hg] [-r <n>] [-f <name> [-1|-2|-3 <val>]*] [-T <time limit>]
  -1 <val>  Specify first function argument
  -2 <val>  Specify second function argument
  -3 <val>  Specify third function argument
  -f <name> Test only the named function
  -g        Format output for autograding with no error messages
  -h        Print this message
  -r <n>    Give uniform weight of n for all problems
  -T <lim>  Set timeout limit to lim
```

활용 예시는 아래와 같습니다.

- 모든 함수를 검사하고 오류 메시지를 보고 싶다면 `./btest`
- 자동 채점기 형태의 간단한 출력이 필요하면 `./btest -g`
- 특정 함수(예: `foo`)만 검사하려면 `./btest -f foo`
- 특정 인수로 `foo`를 시험하려면 `./btest -f foo -1 27 -2 0xf`

> `btest`는 코딩 스타일 준수를 검사하지 않습니다. 그 부분은 반드시 `dlc`로 확인하세요.

## 3. 도우미 프로그램

`ishow`와 `fshow`는 정수 및 부동소수점 표현을 분석할 때 유용합니다. 아래 명령으로 빌드할 수 있습니다.

```bash
make
```

사용 예시는 다음과 같습니다.

```bash
./ishow 0x27
# Hex = 0x00000027, Signed = 39, Unsigned = 39

./ishow 27
# Hex = 0x0000001b, Signed = 27, Unsigned = 27

./fshow 0x15213243
# Floating point value 3.255334057e-26
# Bit Representation 0x15213243, sign = 0, exponent = 0x2a, fraction = 0x213243
# Normalized.  +1.2593463659 × 2^(-85)

./fshow 15213243
# Floating point value 2.131829405e-38
# Bit Representation 0x00e822bb, sign = 0, exponent = 0x01, fraction = 0x6822bb
# Normalized.  +1.8135598898 × 2^(-126)
```

이 도구들을 활용하면 비트 단위 조작이 실제 숫자 표현에 어떤 영향을 주는지 직관적으로 확인할 수 있습니다.

## 퍼즐별 문제와 풀이

### bitAnd (함수: `bitAnd`, 배점 1점)
- **제약 조건**: 허용 연산 `~`, `|`; 최대 연산 수 8회; 난이도 1.
- **문제 요구**: `x & y`를 `~`와 `|`만 사용해서 구현하라.
- **풀이 설명**: 드모르간 법칙에 따라 `x & y`는 `~(~x | ~y)`와 같습니다. 각 입력을 NOT 한 뒤 OR 하고 마지막에 다시 NOT 하면 금지된 `&` 없이 동일한 결과를 얻을 수 있습니다.
- **구현 코드**:
```c
int bitAnd(int x, int y) {
  /* x&y = ~(~x | ~y) using De Morgan's law */
  return ~(~x | ~y);
}
```

### evenBits (함수: `evenBits`, 배점 1점)
- **제약 조건**: 허용 연산 `!`, `~`, `&`, `^`, `|`, `+`, `<<`, `>>`; 최대 연산 수 8회; 난이도 1.
- **문제 요구**: 모든 짝수 비트(0, 2, …, 30)가 1인 32비트 값을 반환하라.
- **풀이 설명**: 8비트 상수 `0x55`(01010101)를 준비한 뒤 8비트씩 왼쪽으로 확장하면서 OR 연산으로 이어 붙여 `0x55555555`를 만들었습니다. 결과적으로 짝수 비트만 1인 패턴이 완성됩니다.
- **구현 코드**:
```c
int evenBits(void) {
  /* Create pattern 0x55555555 by shifting and ORing */
  int result = 0x55;
  result = (result << 8) | 0x55;
  result = (result << 8) | 0x55;
  result = (result << 8) | 0x55;
  return result;
}
```

### bitNor (함수: `bitNor`, 배점 1점)
- **제약 조건**: 허용 연산 `~`, `&`; 최대 연산 수 8회; 난이도 1.
- **문제 요구**: `~(x | y)`를 `~`와 `&`만 사용해 계산하라.
- **풀이 설명**: 드모르간 법칙을 다시 적용해 `~(x | y)`를 `(~x) & (~y)`로 바꾸면 됩니다. 두 입력을 각각 NOT 하고 AND 하면 OR을 쓰지 않고도 NOR이 정의됩니다.
- **구현 코드**:
```c
int bitNor(int x, int y) {
  /* ~(x|y) = ~x & ~y using De Morgan's law */
  return ~x & ~y;
}
```

### isPositive (함수: `isPositive`, 배점 2점)
- **제약 조건**: 허용 연산 `!`, `~`, `&`, `^`, `|`, `+`, `<<`, `>>`; 최대 연산 수 8회; 난이도 2.
- **문제 요구**: `x`가 양수이면 1, 그렇지 않으면 0을 반환하라.
- **풀이 설명**: 산술 시프트로 부호 비트(`x >> 31`)를 확인하고, `!x`로 0 여부를 판단합니다. 부호 비트가 0이고 값이 0이 아닐 때만 1이 되도록 `!((x >> 31) | !x)` 형태로 결합했습니다.
- **구현 코드**:
```c
int isPositive(int x) {
  /* Check if x > 0: x is positive if sign bit is 0 and x is not zero */
  return !((x >> 31) | !x);
}
```

### getByte (함수: `getByte`, 배점 2점)
- **제약 조건**: 허용 연산 `!`, `~`, `&`, `^`, `|`, `+`, `<<`, `>>`; 최대 연산 수 6회; 난이도 2.
- **문제 요구**: 0~3 사이 인덱스 `n`에 해당하는 바이트를 `x`에서 추출해 반환하라.
- **풀이 설명**: 바이트 위치는 `n << 3`비트만큼 오른쪽으로 이동하면 하위 8비트로 내려옵니다. 그 후 `0xFF`로 마스킹하여 해당 바이트만 남겼습니다.
- **구현 코드**:
```c
int getByte(int x, int n) {
  /* Extract byte n from word x by shifting right by n*8 and masking */
  int shift = n << 3;  /* n * 8 */
  return (x >> shift) & 0xFF;
}
```

### isSymmetric (함수: `isSymmetric`, 배점 2점)
- **제약 조건**: 허용 연산 `!`, `~`, `&`, `^`, `|`, `+`, `<<`, `>>`; 최대 연산 수 7회; 난이도 2.
- **문제 요구**: 상위 16비트와 하위 16비트가 동일하면 1을 반환하라.
- **풀이 설명**: 8비트 상수만 사용 가능한 제약 때문에 `0xFF`를 단계적으로 확장해 `0xFFFF` 마스크를 만들었습니다. 이를 이용해 양쪽 16비트를 추출하고 XOR으로 비교한 뒤, 결과가 0이면 `!`로 1을 반환합니다.
- **구현 코드**:
```c
int isSymmetric(int x) {
  /* Compare upper and lower 16-bit halves using 8-bit friendly mask */
  int mask = 0xFF;
  mask = (mask << 8) | 0xFF;
  int lower = x & mask;
  int upper = (x >> 16) & mask;
  return !(lower ^ upper);
}
```

### sign (함수: `sign`, 배점 2점)
- **제약 조건**: 허용 연산 `!`, `~`, `&`, `^`, `|`, `+`, `<<`, `>>`; 최대 연산 수 10회; 난이도 2.
- **문제 요구**: 양수면 1, 0이면 0, 음수면 -1을 반환하라.
- **풀이 설명**: 산술 시프트 `x >> 31`은 음수일 때 -1, 양수일 때 0을 만들어 줍니다. 여기에 `!x`를 조합해 0일 때는 0, 양수일 때는 1, 음수일 때는 -1이 나오도록 논리식을 구성했습니다.
- **구현 코드**:
```c
int sign(int x) {
  /* Return 1 if positive, 0 if zero, -1 if negative */
  int sign_bit = x >> 31;
  int is_zero = !x;
  return sign_bit | (!is_zero & !sign_bit);
}
```

### allEvenBits (함수: `allEvenBits`, 배점 2점)
- **제약 조건**: 허용 연산 `!`, `~`, `&`, `^`, `|`, `+`, `<<`, `>>`; 최대 연산 수 12회; 난이도 2.
- **문제 요구**: 모든 짝수 비트가 1이면 1, 아니면 0을 반환하라.
- **풀이 설명**: `0x55555555` 마스크를 생성해 입력과 AND 했을 때 동일한지 XOR으로 확인했습니다. 차이가 없으면 모든 짝수 비트가 1이므로 `!`로 1을 돌려줍니다.
- **구현 코드**:
```c
int allEvenBits(int x) {
  /* Check if all even-numbered bits are set to 1 */
  int mask = 0x55;
  mask = (mask << 8) | 0x55;
  mask = (mask << 8) | 0x55;
  mask = (mask << 8) | 0x55;
  return !((x & mask) ^ mask);
}
```

### dividePower2 (함수: `dividePower2`, 배점 2점)
- **제약 조건**: 허용 연산 `!`, `~`, `&`, `^`, `|`, `+`, `<<`, `>>`; 최대 연산 수 15회; 난이도 2.
- **문제 요구**: `x / 2^n`을 0으로 향해 반올림하도록 계산하라 (0 ≤ n ≤ 30).
- **풀이 설명**: 음수에서 산술 시프트는 음의 무한대로 내림하므로 `2^n - 1` 편향을 더해 절댓값 기준 내림을 상쇄했습니다. 그 후 `>> n`을 적용하면 양수·음수 모두 0 방향으로 반올림됩니다.
- **구현 코드**:
```c
int dividePower2(int x, int n) {
  /* Divide x by 2^n, rounding toward zero */
  int sign_bit = x >> 31;
  int bias = (1 << n) + ~0;  /* (1 << n) - 1 */
  int biased_x = x + (sign_bit & bias);
  return biased_x >> n;
}
```

### subtractionOK (함수: `subtractionOK`, 배점 3점)
- **제약 조건**: 허용 연산 `!`, `~`, `&`, `^`, `|`, `+`, `<<`, `>>`; 최대 연산 수 20회; 난이도 3.
- **문제 요구**: `x - y`를 계산할 때 오버플로가 발생하지 않으면 1을 반환하라.
- **풀이 설명**: 뺄셈은 `x + (~y + 1)`으로 표현하고, 입력 부호가 다르면서 결과 부호가 `x`와 다르면 오버플로가 됩니다. 해당 조건을 감지해 없으면 1, 있으면 0을 반환했습니다.
- **구현 코드**:
```c
int subtractionOK(int x, int y) {
  /* Check if x - y can be computed without overflow */
  int diff = x + (~y + 1);  /* x - y */
  int x_s = x >> 31;
  int y_s = y >> 31;
  int diff_sign = diff >> 31;
  int signs_differ = x_s ^ y_s;
  int result_sign_differs = x_s ^ diff_sign;
  return !(signs_differ & result_sign_differs);
}
```

### isLessOrEqual (함수: `isLessOrEqual`, 배점 3점)
- **제약 조건**: 허용 연산 `!`, `~`, `&`, `^`, `|`, `+`, `<<`, `>>`; 최대 연산 수 24회; 난이도 3.
- **문제 요구**: `x <= y`이면 1, 아니면 0을 반환하라.
- **풀이 설명**: `y - x`의 부호를 확인하되, 입력 부호가 다를 때는 음수가 양수보다 작다는 사실로 결과를 결정했습니다. 부호가 같으면 `y - x`가 음수가 아닌지(`diff >= 0`)만 보면 됩니다.
- **구현 코드**:
```c
int isLessOrEqual(int x, int y) {
  /* Return 1 if x <= y, 0 otherwise */
  int diff = y + (~x + 1);  /* y - x */
  int x_s = x >> 31;
  int y_s = y >> 31;
  int sign_diff = x_s ^ y_s;
  int diff_sign = diff >> 31;
  int same_sign = !sign_diff;
  int d_n = !diff_sign;
  int x_neg_y_pos = x_s & (~y_s);
  int x_neg_y_pos_bool = !(!x_neg_y_pos);
  return x_neg_y_pos_bool | (same_sign & d_n);
}
```

### rotateRight (함수: `rotateRight`, 배점 3점)
- **제약 조건**: 허용 연산 `~`, `&`, `^`, `|`, `+`, `<<`, `>>`, `!`; 최대 연산 수 25회; 난이도 3.
- **문제 요구**: 32비트 값 `x`를 오른쪽으로 `n`비트 순환 회전시키라.
- **풀이 설명**: 산술 시프트가 부호 비트를 채우는 문제를 해결하기 위해 오른쪽 시프트 결과에서 부호가 채워진 상위 비트를 제거할 마스크를 만들었습니다. 동시에 하위 `n`비트를 왼쪽으로 `32 - n`만큼 이동해 상위로 올리고, 두 결과를 OR 해 순환 효과를 얻었습니다.
- **구현 코드**:
```c
int rotateRight(int x, int n) {
  /* Rotate x to the right by n positions */
  int logical_mask = ~(((1 << 31) >> n) << 1);
  int left_shift = (32 + (~n + 1)) & 31;
  int right_part = (x >> n) & logical_mask;
  int left_part = x << left_shift;
  return right_part | left_part;
}
```

### isAsciiAlpha (함수: `isAsciiAlpha`, 배점 3점)
- **제약 조건**: 허용 연산 `!`, `~`, `&`, `^`, `|`, `+`, `<<`, `>>`; 최대 연산 수 20회; 난이도 3.
- **문제 요구**: `x`가 ASCII 대문자(0x41~0x5A) 또는 소문자(0x61~0x7A)면 1을 반환하라.
- **풀이 설명**: 대소문자를 통합하기 위해 `x | 0x20`으로 대문자를 소문자 범위에 매핑했습니다. 이후 `folded - 0x61`과 `0x7A - folded`의 부호를 살펴 하한·상한 범위를 모두 만족하면 1을 반환합니다.
- **구현 코드**:
```c
int isAsciiAlpha(int x) {
  /* Fold to lowercase and check range 0x61-0x7A */
  int folded = x | 0x20;
  int lower_check = folded + (~0x61 + 1);
  int upper_check = 0x7A + (~folded + 1);
  return !((lower_check >> 31) | (upper_check >> 31));
}
```

### satMul3 (함수: `satMul3`, 배점 3점)
- **제약 조건**: 허용 연산 `!`, `~`, `&`, `^`, `|`, `+`, `<<`, `>>`; 최대 연산 수 25회; 난이도 3.
- **문제 요구**: `x * 3`을 계산하되 오버플로 시 `Tmin` 또는 `Tmax`로 포화(saturate)하라.
- **풀이 설명**: 중간 값 `x + x`와 최종 값 `x + x + x`의 부호 변화를 확인해 오버플로를 감지했습니다. 오버플로가 있으면 입력 부호에 따라 `0x80000000` 또는 `0x7FFFFFFF`를 반환하고, 없으면 `3x`를 그대로 돌려줍니다.
- **구현 코드**:
```c
int satMul3(int x) {
  /* Multiply by 3, saturating to Tmin or Tmax if overflow */
  int doubled = x + x;
  int tripled = doubled + x;
  int overflow_bits = (x ^ doubled) | (x ^ tripled);
  int overflow = (overflow_bits >> 31) & 1;
  int overfl_m = ~overflow + 1;
  int sign = x >> 31;
  int tmin = 1 << 31;
  int tmax = ~tmin;
  int saturated = (sign & tmin) | (~sign & tmax);
  return (overfl_m & saturated) | (~overfl_m & tripled);
}
```

### floatScale4 (함수: `floatScale4`, 배점 4점)
- **제약 조건**: 정수·unsigned 연산, 비교, 분기, 반복 모두 허용(단, 부동소수점 사용 금지); 최대 연산 수 30회; 난이도 4.
- **문제 요구**: 부동소수점 값 `f`(단정도)를 네 배(`4*f`)로 스케일링한 비트 패턴을 반환하라. NaN은 그대로 반환.
- **풀이 설명**: 부호/지수/가수를 분리하고, 지수가 255면 NaN/무한대이므로 그대로 반환했습니다. 정상 수는 지수를 두 단계 올리고 overflow 시 무한대로 포화시키며, 비정규 수는 가수를 4배로 키운 뒤 정규화 기준을 만족하면 지수를 1로 올리고 가수를 마스크로 정리했습니다.
- **구현 코드**:
```c
unsigned floatScale4(unsigned uf) {
  /* Return bit-level equivalent of 4*f for floating point f */
  unsigned sign = uf & 0x80000000;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x7FFFFF;

  if (exp == 0xFF) {
    return uf;
  }

  if (exp == 0) {
    frac = frac << 2;
    if (frac >= 0x800000) {
      while (frac >= 0x1000000) {
        frac = frac >> 1;
        exp = exp + 1;
      }
      exp = exp + 1;
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
```

### trueSevenSixteenths (함수: `trueSevenSixteenths`, 배점 4점)
- **제약 조건**: 허용 연산 `!`, `~`, `&`, `^`, `|`, `+`, `<<`, `>>`; 최대 연산 수 25회; 난이도 4.
- **문제 요구**: 오버플로 없이 `x * 7 / 16`을 0을 향해 반올림한 결과를 반환하라.
- **풀이 설명**: 먼저 `x >> 4`로 16으로 나눈 몫 `q`를 얻고, `x - q*16`으로 나머지를 계산했습니다. `q`에 대한 7배는 `(q<<2)+(q<<1)+q`로 안전하게 계산하고, 나머지 역시 7배한 뒤 `>> 4`로 추가 몫을 얻어 합쳤습니다. 남은 나머지가 존재하고 원래 값이 음수일 때만 1을 더해 toward-zero 반올림을 보정했습니다.
- **구현 코드**:
```c
int trueSevenSixteenths(int x)
{
  /* Multiply by 7/16, rounding toward zero, avoiding overflow */
  int q = x >> 4;
  int q_times_16 = q << 4;
  int remainder = x + (~q_times_16 + 1);
  int seven_q = (q << 2) + (q << 1) + q;
  int seven_remainder = (remainder << 2) + (remainder << 1) + remainder;
  int base = seven_q + (seven_remainder >> 4);
  int leftover = seven_remainder & 0xF;
  int has_leftover = !(!leftover);
  int neg = (x >> 31) & 1;
  int adjust = neg & has_leftover;
  return base + adjust;
}
```
