#include "src/Message.h"
#include "src/Convert.h"
#include "src/fsm_array_receive.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








void test_Fsm_Test_Array_Receive(void)

{





    uint8_t test_data[] = {0xaa, 0x01, 0x02, 0x00, 0x71, 0x5c};

    uint8_t expected_output[] = {0xaa, 0x01, 0x02, 0x00, 0x71, 0x5c};

    uint8_t output[16];

    uint8_t result;



    for (int i = 0; i < sizeof(test_data); i++)

    {

        result = Fsm_Test_Array_Receive(test_data[i], output);



        if (result == 1)

        {



            UnityAssertEqualIntArray(( const void*)((expected_output)), ( const void*)((output)), (UNITY_UINT32)((sizeof(expected_output))), (

           ((void *)0)

           ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

            for(int i =0 ; i< length_arr_recerive ; i++)

            {

                printf("%x ", output[i]);

            }

            memset(output, 0, sizeof(output));

        }

    }

}
