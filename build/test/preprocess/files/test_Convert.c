#include "src/Convert.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"








void test_Convert_HexToString(void)

{

    char char_result[50];

    char string_test[] = "Khanh Linh";

    uint8_t hex_string[] = {0x4b, 0x68, 0x61, 0x6e, 0x68, 0x20, 0x4c, 0x69, 0x6e, 0x68};



    char* result = Convert_HexToString(hex_string, sizeof(hex_string));

    printf("Start_Test_Convert_HexToString\n");

        for(uint16_t i = 0 ; i < sizeof(hex_string); i++)

    {

        printf("%c",result[i] );

    }



    printf("\n");



    UnityAssertEqualString((const char*)((string_test)), (const char*)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(22));

    free(result);

    printf("End_Test_Convert_HexToString\n");

}
