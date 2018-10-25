#include <stdio.h>
#include <stdint.h>
#include <string.h>

char *base64_encode(const uint8_t *data, size_t len, char *text, size_t *textlen)
{
    int off = 0;
    size_t i;

    if (!textlen || *textlen < 65)
        return NULL;

    for (i = 0; i < 32; i++)
        off += sprintf(text + off, "%02hhX", data[i]);

    *textlen = off;
    return text;
}

ssize_t base64_decode(const char *text, size_t textlen, uint8_t *data, size_t datalen)
{
    const char *pos = text;
    size_t len = textlen / 2;
    int i;

    if (textlen % 2 != 0 || datalen < len)
        return -1;

    for (i = 0; i < len; i++, pos += 2)
        sscanf(pos, "%2hhx", &data[i]);

    return len;
}
