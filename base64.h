#ifndef __BASE64_H__
#define __BASE64_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Base64 binary to text encoder.
 *
 * @param
 *      data        [in] The data buffer to be encode.
 * @param
 *      len         [in] The data length in the buffer.
 * @param
 *      text        [out] The encoded text buffer, caller provided.
 * @param
 *      textlen     [in] The text buffer size.
 *                  [out] The encoded text result length.
 *
 * @return
 *      The encoded text, or NULL if the text buffer too small.
 */
char *base64_encode(const uint8_t *data, size_t len, char *text, size_t *textlen);

/**
 * Base64 binary to text decoder.
 *
 * @param
 *      text        [in] The text buffer to be decode.
 * @param
 *      textlen     [in] The text length.
 * @param
 *      data        [in] The binary date buffer, caller provided.
 * @param
 *      datalen     [in] The data buffer size.
 *
 * @return
 *      The decoded bytes in thr data buffer, or -1 if the data buffer is
 *      too small.
 */
ssize_t base64_decode(const char *text, size_t textlen, void *uint8_t, size_t datalen);

#ifdef __cplusplus
}
#endif

#endif /* __BASE64_H__ */
