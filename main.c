#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "base58.h"
#include "base64.h"

static void usage(void)
{
    printf("Usage: base58 [OPTION] ...\n");
    printf("\n");
    printf("  --base64=BASE58_VAL       Convert base58-based string to base64-based string.\n");
    printf("  --base58=BASE64_VAL       Convert base64-based string to base58-based string.\n");
    printf("  -h, --help                Show this help usage.");
    printf("\n");
}

static char *base58_conv(const char *base64, char *base58, size_t length)
{
    uint8_t buf[32];
    size_t textlen = length;
    int rc;

    rc = base64_decode(base64, strlen(base64), buf, sizeof(buf));
    if (rc < 0)
        return NULL;

    return base58_encode(buf, sizeof(buf), base58, &textlen);
}

static char *base64_conv(const char *base58, char *base64, size_t length)
{
    uint8_t buf[32];
    size_t textlen = length;
    ssize_t rc;

    rc = base58_decode(base58, strlen(base58), buf, sizeof(buf));
    if (rc != sizeof(buf))
        return NULL;

    return base64_encode(buf, sizeof(buf), base64, &textlen);
}

int main(int argc, char *argv[])
{
    int opt;
    int idx;
    struct option options[] = {
        { "base64",         required_argument,  NULL, 'B' },
        { "base58",         required_argument,  NULL, 'b' },
        { "help",           no_argument,        NULL, 'h' },
        { NULL,             0,                  NULL,  0  }
    };

    const char *base64_str = NULL;
    const char *base58_str = NULL;

    while ((opt = getopt_long(argc, argv, "B:b:h?", options, &idx)) != -1) {
        switch (opt) {
        case 'B':
            base64_str = optarg;
            break;

        case 'b':
            base58_str = optarg;
            break;

        case 'h':
        case '?':
        default:
            usage();
            exit(-1);
        }
    }

    char base64[65] = {0};
    char base58[46] = {0};
    char *ret64;
    char *ret58;

    if (base64_str) {
        ret58 = base58_conv(base64_str, base58, sizeof(base58));
        printf("base64:<%s> => base58:<%s>\n", base64_str, ret58 ? ret58 : "N/A");
    }
    if (base58_str) {
        ret64 = base64_conv(base58_str, base64, sizeof(base64));
        printf("base58:<%s> => base64:<%s>\n", base58_str, ret64 ? ret64 : "N/A");
    }

    return 0;
}
