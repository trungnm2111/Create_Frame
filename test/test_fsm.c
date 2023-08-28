#ifdef TEST

#include "unity.h"
#include "fsm_array_receive.h"
#include "stdint.h"
#include "Convert.h"
#include "Message.h"

void test_Fsm_Test_Array_Receive(void)
{
    // uint8_t test_data[] = {0xA5, 0x01, 0x00, 0x00, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12};
    // uint8_t expected_output[] = {0xA5, 0x01, 0x00, 0x00, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12};
    uint8_t test_data[] = {0xaa, 0x01, 0x02, 0x00, 0x71, 0x5c};
    uint8_t expected_output[] = {0xaa, 0x01, 0x02, 0x00, 0x71, 0x5c};
    uint8_t output[16];
    uint8_t result;

    for (int i = 0; i < sizeof(test_data); i++)
    {
        result = Fsm_Test_Array_Receive(test_data[i], output);

        if (result == 1)
        {
            // Kiểm tra kết quả đầu ra
            TEST_ASSERT_EQUAL_UINT8_ARRAY(expected_output, output, sizeof(expected_output));
            for(int i =0 ; i< length_arr_recerive ; i++)
            {
                printf("%x ", output[i]);
            }
            memset(output, 0, sizeof(output));
        }
    }
}


#endif // TEST
