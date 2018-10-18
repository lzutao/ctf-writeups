#include <stdio.h>
#include <string.h>
#include <x86intrin.h>

char BIN[] = {
  0x7b, 0x18, 0xa6, 0x34, 0xd9, 0x3c, 0x2d, 0xa3, 0xff, 0xce, 0x86, 0xab, 0x92, 0xfb, 0x9a, 0x42,
  0x8b, 0x32, 0xa3, 0xaa, 0xfb, 0x96, 0x8a, 0x3b, 0x42, 0xa3, 0xfa, 0x86, 0x82, 0xbb, 0x26, 0xc3,
  0xba, 0x0e, 0x32, 0xca, 0xea, 0x63, 0x0c, 0x5b,
};

int main(void)
{
  size_t len = sizeof(BIN);
  printf("Size of BIN : %zu\n", len);
  size_t end = len - 3;

  for (size_t i = end - 1; i < end; --i) {
    char *ch = &BIN[i]; //ebp-0x4
    *(int *)ch = __rord(*(int *)ch, 0xb);
    *(short *)ch = __rolw(*(short *)ch, 0xd);
    *ch ^= 0xf8;
  }

  puts(BIN);

  return 0;
}