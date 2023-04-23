#include <stdio.h>

int pr[256] = {
    ['*'] = 1, ['/'] = 1,
    ['+'] = 0, ['-'] = 0,
    ['('] = -1,
};

int main() {
    char src[128], dst[128];
    char *s = src, *d = dst;
    char st[1<<7], *sp = st;

    scanf("%s", src);

    while (*s) {
        if (*s >= 'A') {
            *d++ = *s;
        } else if (*s == ')') {
            while (*--sp != '(') *d++ = *sp;
        } else if (*s == '(') {
            *sp++ = '(';
        } else {
            while (sp != st && pr[sp[-1]] >= pr[*s]) {
                *d++ = *--sp;
            }
            *sp++ = *s;
        }
        ++s;
    }

    while (sp != st) *d++ = *--sp;

    fwrite(dst, d - dst, 1, stdout);
}