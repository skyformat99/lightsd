#include "jsonrpc.c"

#include "test_jsonrpc_utils.h"

static void
test_float(const char *json)
{
    jsmntok_t tokens[8];
    parse_json(tokens, LGTD_ARRAY_SIZE(tokens), json, strlen(json));
    if (!lgtd_jsonrpc_type_float_between_0_and_1(tokens, json)) {
        errx(1, "%s wasn't considered as a valid float >= 0 and <= 1", json);
    }
}

int
main(void)
{
    test_float("0.1234");
    test_float("1.0000000");
    test_float("0.9999");
    test_float("0.01");
    test_float("000.01");

    return 0;
}