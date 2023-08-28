#include "src/fsm_array_receive.h"
#include "src/Convert.h"
#include "src/Message.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






void Print_Data_Message(uint8_t *arr, uint8_t length);

void Print_Data_Detect(FrameMsg_t frame);







void test_MessageCreateFrameRound3x3(void)

{



    uint8_t count_arr_test = 0;

    uint8_t arr_data_round3x3_test[2 + 2] = {0xAA, 0x01, 0x02, 0x00};



    FrameMsg_t frame_test, frame_detect;

    uint8_t arr_create_frame_round3x3[30], length_arr = 0;



    frame_test.StartFrame = 0xAA;

    frame_test.TypeMessage = ROUND3x3;

    length_arr = SEC_Message_Create_Frame(frame_test, arr_create_frame_round3x3);



    printf("/*--------------------------------------------------------------------------------*/\n");

    printf("Start test_MessageCreateFrameRound3x3\n");

    printf("length_arr: %d\n", length_arr);

    Print_Data_Message(arr_create_frame_round3x3, length_arr);





    for (count_arr_test = 0; count_arr_test < 2 + 2; count_arr_test++)

    {

        UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((arr_data_round3x3_test[count_arr_test])), (UNITY_INT)(UNITY_UINT8 )((arr_create_frame_round3x3[count_arr_test])), (

       ((void *)0)

       ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_UINT8);

    }



    printf("End test_MessageCreateFrameRound3x3\n");









    void Print_Data_Message_Receive(uint8_t *arr, uint8_t length);



    count_arr_test = 0;

    uint8_t arr_data_fsm[50];

    while (1)

    {

        if (Fsm_Test_Array_Receive(arr_create_frame_round3x3[count_arr_test++], arr_data_fsm))

        {

            break;

        }

    }

    for (count_arr_test = 0; count_arr_test < 8 ; count_arr_test++)

    {

        UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((arr_create_frame_round3x3[count_arr_test])), (UNITY_INT)(UNITY_UINT8 )((arr_data_fsm[count_arr_test])), (

       ((void *)0)

       ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_UINT8);

    }

    Print_Data_Message_Receive(arr_data_fsm, length_arr);











    SEC_Message_Detect_Frame(arr_create_frame_round3x3 , &frame_detect, length_arr);



    frame_test.LengthData = Sec_Convert_From_Bytes_To_Uint16(arr_create_frame_round3x3[2],

                                                            arr_create_frame_round3x3[2 + 1 ]);

    frame_test.CheckFrame = Sec_Convert_From_Bytes_To_Uint16(arr_create_frame_round3x3[length_arr - 2],

                                                            arr_create_frame_round3x3[length_arr - 1 ]);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.StartFrame)), (UNITY_INT)(UNITY_INT8 )((frame_detect.StartFrame)), (

   ((void *)0)

   ), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.TypeMessage)), (UNITY_INT)(UNITY_INT8 )((frame_detect.TypeMessage)), (

   ((void *)0)

   ), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.LengthData)), (UNITY_INT)(UNITY_INT8 )((frame_detect.LengthData)), (

   ((void *)0)

   ), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((frame_test.CheckFrame)), (UNITY_INT)(UNITY_INT16)((frame_detect.CheckFrame)), (

   ((void *)0)

   ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_HEX16);



    Print_Data_Detect(frame_detect);





    printf("\nEnd test_SEC_Message_Detect_Frame_Round3x3\n");

    printf("/*--------------------------------------------------------------------------------*/\n\n");



}



void test_MessageCreateFrameRound5x5(void)

{



    uint8_t count_arr_test = 0;

    uint8_t arr_data_round5x5_test[2 + 2] = {0xAA , 0x02, 0x02, 0x00};



    FrameMsg_t frame_test, frame_detect;

    uint8_t arr_create_frame_out[30], length_arr = 0;



    frame_test.StartFrame = 0xAA;

    frame_test.TypeMessage = ROUND5x5;

    length_arr = SEC_Message_Create_Frame(frame_test, arr_create_frame_out);



    printf("/*--------------------------------------------------------------------------------*/\n");

    printf("Start test_MessageCreateFrameRound5x5\n");

    printf("length_arr: %d\n", length_arr);

    Print_Data_Message(arr_create_frame_out, length_arr);



    for (count_arr_test = 0; count_arr_test < 2 + 2; count_arr_test++)

    {

        UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((arr_data_round5x5_test[count_arr_test])), (UNITY_INT)(UNITY_UINT8 )((arr_create_frame_out[count_arr_test])), (

       ((void *)0)

       ), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_UINT8);

    }

    printf("End test_MessageCreateFrameRound5x5\n");













    SEC_Message_Detect_Frame(arr_data_round5x5_test , &frame_detect, length_arr);



    frame_test.LengthData = Sec_Convert_From_Bytes_To_Uint16(arr_data_round5x5_test[2],

                                                            arr_data_round5x5_test[2 + 1 ]);

    frame_test.CheckFrame = Sec_Convert_From_Bytes_To_Uint16(arr_data_round5x5_test[length_arr - 2],

                                                            arr_data_round5x5_test[length_arr -1 ]);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.StartFrame)), (UNITY_INT)(UNITY_INT8 )((frame_detect.StartFrame)), (

   ((void *)0)

   ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.TypeMessage)), (UNITY_INT)(UNITY_INT8 )((frame_detect.TypeMessage)), (

   ((void *)0)

   ), (UNITY_UINT)(118), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.LengthData)), (UNITY_INT)(UNITY_INT8 )((frame_detect.LengthData)), (

   ((void *)0)

   ), (UNITY_UINT)(119), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((frame_test.CheckFrame)), (UNITY_INT)(UNITY_INT16)((frame_detect.CheckFrame)), (

   ((void *)0)

   ), (UNITY_UINT)(120), UNITY_DISPLAY_STYLE_HEX16);



    Print_Data_Detect(frame_detect);







    printf("\nEnd test_SEC_Message_Detect_Frame_Round5X5\n");



    printf("/*--------------------------------------------------------------------------------*/\n\n");

}



void test_MessageCreateFrameRound7X7(void)

{



    uint8_t count_arr_test = 0;

    uint8_t arr_data_round7x7_test[2 + 2] = {0xAA , 0x03, 0x02, 0x00};



    FrameMsg_t frame_test, frame_detect;

    uint8_t arr_create_frame_out[30], length_arr = 0;



    frame_test.StartFrame = 0xAA;

    frame_test.TypeMessage = ROUND7X7;

    length_arr = SEC_Message_Create_Frame(frame_test, arr_create_frame_out);



    printf("/*--------------------------------------------------------------------------------*/\n");

    printf("Start test_MessageCreateFrameRound7x7\n");

    printf("length_arr: %d\n", length_arr);

    Print_Data_Message(arr_create_frame_out, length_arr);



    for (count_arr_test = 0; count_arr_test < 2 + 2; count_arr_test++)

    {

        UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((arr_data_round7x7_test[count_arr_test])), (UNITY_INT)(UNITY_UINT8 )((arr_create_frame_out[count_arr_test])), (

       ((void *)0)

       ), (UNITY_UINT)(151), UNITY_DISPLAY_STYLE_UINT8);

    }

    printf("End test_MessageCreateFrameRound7x7\n");











    SEC_Message_Detect_Frame(arr_data_round7x7_test , &frame_detect,length_arr);



    frame_test.LengthData = Sec_Convert_From_Bytes_To_Uint16(arr_data_round7x7_test[2],

                                                            arr_data_round7x7_test[2 + 1 ]);

    frame_test.CheckFrame = Sec_Convert_From_Bytes_To_Uint16(arr_data_round7x7_test[length_arr - 2],

                                                            arr_data_round7x7_test[length_arr -1 ]);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.StartFrame)), (UNITY_INT)(UNITY_INT8 )((frame_detect.StartFrame)), (

   ((void *)0)

   ), (UNITY_UINT)(165), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.TypeMessage)), (UNITY_INT)(UNITY_INT8 )((frame_detect.TypeMessage)), (

   ((void *)0)

   ), (UNITY_UINT)(166), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.LengthData)), (UNITY_INT)(UNITY_INT8 )((frame_detect.LengthData)), (

   ((void *)0)

   ), (UNITY_UINT)(167), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((frame_test.CheckFrame)), (UNITY_INT)(UNITY_INT16)((frame_detect.CheckFrame)), (

   ((void *)0)

   ), (UNITY_UINT)(168), UNITY_DISPLAY_STYLE_HEX16);



    Print_Data_Detect(frame_detect);







    printf("\nEnd test_SEC_Message_Detect_Frame_Round7X7\n");



    printf("/*--------------------------------------------------------------------------------*/\n\n");

}



void test_MessageCreateFrameNamePlayer1(void)

{



    uint8_t count_arr_test = 0;

    FrameMsg_t frame_test, frame_detect;

    uint8_t mystring[] = "Huong";

    uint8_t* start_address = (uint8_t*)0x00;

    uint8_t* end_address = start_address + 2 + sizeof(mystring);

    uint8_t arr_data_name_player1_test[2 + 2 + 16] = {0xAA , 0x04 ,(unsigned char)(uintptr_t)end_address, 0x00 };

    for(int i = 0; i < sizeof(mystring); i++)

    {

        arr_data_name_player1_test[i + 4] = mystring[i];

    }

    uint8_t arr_create_frame_name_player1[30], length_arr = 0;

    frame_test.StartFrame = 0xAA;

    frame_test.TypeMessage = NAME_PLAYER_1;

    memcpy(frame_test.Data, mystring, sizeof(mystring));



    length_arr = SEC_Message_Create_Frame(frame_test, arr_create_frame_name_player1);

    printf("/*--------------------------------------------------------------------------------*/\n");

    printf("Start test_MessageCreateFrameNamePlayer1\n");

    printf("length_arr: %d\n", length_arr);

    printf("length_data: %ld\n", sizeof(mystring)+2);

    Print_Data_Message(arr_create_frame_name_player1, length_arr);



    for (count_arr_test = 0; count_arr_test < 2 + 2; count_arr_test++)

    {

        UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((arr_data_name_player1_test[count_arr_test])), (UNITY_INT)(UNITY_UINT8 )((arr_create_frame_name_player1[count_arr_test])), (

       ((void *)0)

       ), (UNITY_UINT)(206), UNITY_DISPLAY_STYLE_UINT8);

    }

    printf("End test_MessageCreateFrameNamePlayer1\n");











    SEC_Message_Detect_Frame(arr_create_frame_name_player1 , &frame_detect, length_arr);



    frame_test.LengthData = Sec_Convert_From_Bytes_To_Uint16(arr_create_frame_name_player1[2],

                                                            arr_create_frame_name_player1[2 + 1 ]);

    frame_test.CheckFrame = Sec_Convert_From_Bytes_To_Uint16(arr_create_frame_name_player1[length_arr - 2],

                                                            arr_create_frame_name_player1[length_arr - 1 ]);

    printf("detect FrameNamePlayer1\n");



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.StartFrame)), (UNITY_INT)(UNITY_INT8 )((frame_detect.StartFrame)), (

   ((void *)0)

   ), (UNITY_UINT)(222), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.TypeMessage)), (UNITY_INT)(UNITY_INT8 )((frame_detect.TypeMessage)), (

   ((void *)0)

   ), (UNITY_UINT)(223), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.LengthData)), (UNITY_INT)(UNITY_INT8 )((frame_detect.LengthData)), (

   ((void *)0)

   ), (UNITY_UINT)(224), UNITY_DISPLAY_STYLE_HEX8);

    for(uint8_t i = 0; i < length_arr -2 - 2; i++ )

    {

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.Data[i])), (UNITY_INT)(UNITY_INT8 )((frame_detect.Data[i])), (

       ((void *)0)

       ), (UNITY_UINT)(227), UNITY_DISPLAY_STYLE_HEX8);

    }

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((frame_test.CheckFrame)), (UNITY_INT)(UNITY_INT16)((frame_detect.CheckFrame)), (

  ((void *)0)

  ), (UNITY_UINT)(229), UNITY_DISPLAY_STYLE_HEX16);

    Print_Data_Detect(frame_detect);







    printf("\nEnd test_SEC_Message_Detect_Frame_Name1\n");

}



void test_MessageCreateFrameNamePlayer2(void)

{

    uint8_t count_arr_test = 0;

    FrameMsg_t frame_test, frame_detect;

    uint8_t mystring[] = "Khanh Linh";

    uint8_t* start_address = (uint8_t*)0x00;

    uint8_t* end_address = start_address + 2 + sizeof(mystring);

    uint8_t arr_data_name_player2_test[2 + 2 + 16] = {0xAA , 0x05 ,(unsigned char)(uintptr_t)end_address, 0x00 };

    for(int i = 0; i < sizeof(mystring); i++)

    {

        arr_data_name_player2_test[i + 4] = mystring[i];

    }

    uint8_t arr_create_frame_name_player2[30], length_arr = 0;

    frame_test.StartFrame = 0xAA;

    frame_test.TypeMessage = NAME_PLAYER_2;

    memcpy(frame_test.Data, mystring, sizeof(mystring));



    length_arr = SEC_Message_Create_Frame(frame_test, arr_create_frame_name_player2);

    printf("/*--------------------------------------------------------------------------------*/\n");

    printf("Start test_MessageCreateFrameNamePlayer2\n");

    printf("length_arr: %d\n", length_arr);

    printf("length_data: %ld\n", sizeof(mystring));

    Print_Data_Message(arr_create_frame_name_player2, length_arr);



    for (count_arr_test = 0; count_arr_test < 2 + 2; count_arr_test++)

    {

        UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((arr_data_name_player2_test[count_arr_test])), (UNITY_INT)(UNITY_UINT8 )((arr_create_frame_name_player2[count_arr_test])), (

       ((void *)0)

       ), (UNITY_UINT)(263), UNITY_DISPLAY_STYLE_UINT8);

    }

    printf("End test_MessageCreateFrameNamePlayer2\n");











    SEC_Message_Detect_Frame(arr_create_frame_name_player2 , &frame_detect, length_arr);



    frame_test.LengthData = Sec_Convert_From_Bytes_To_Uint16(arr_create_frame_name_player2[2],

                                                            arr_create_frame_name_player2[2 + 1 ]);

    frame_test.CheckFrame = Sec_Convert_From_Bytes_To_Uint16(arr_create_frame_name_player2[length_arr - 2],

                                                            arr_create_frame_name_player2[length_arr - 1 ]);

    printf("detect FrameNamePlayer2\n");



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.StartFrame)), (UNITY_INT)(UNITY_INT8 )((frame_detect.StartFrame)), (

   ((void *)0)

   ), (UNITY_UINT)(279), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.TypeMessage)), (UNITY_INT)(UNITY_INT8 )((frame_detect.TypeMessage)), (

   ((void *)0)

   ), (UNITY_UINT)(280), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.LengthData)), (UNITY_INT)(UNITY_INT8 )((frame_detect.LengthData)), (

   ((void *)0)

   ), (UNITY_UINT)(281), UNITY_DISPLAY_STYLE_HEX8);

    for(uint8_t i = 0; i < length_arr -2 - 2; i++ )

    {

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((frame_test.Data[i])), (UNITY_INT)(UNITY_INT8 )((frame_detect.Data[i])), (

       ((void *)0)

       ), (UNITY_UINT)(284), UNITY_DISPLAY_STYLE_HEX8);

    }

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((frame_test.CheckFrame)), (UNITY_INT)(UNITY_INT16)((frame_detect.CheckFrame)), (

  ((void *)0)

  ), (UNITY_UINT)(286), UNITY_DISPLAY_STYLE_HEX16);

    Print_Data_Detect(frame_detect);







    printf("\nEnd test_SEC_Message_Detect_Frame_Name2\n");

     printf("/*--------------------------------------------------------------------------------*/\n\n");

}



void test_MessageCreateFramePoint1(void)

{



    uint8_t count_arr_test = 0;

    FrameMsg_t frame_test, frame_detect;

    uint8_t mystring = '1';

    uint8_t* start_address = (uint8_t*)0x00;

    uint8_t* end_address = start_address + 2 + sizeof(mystring)+1;

    uint8_t arr_data_point1_test[2 + 2 + 16] = {0xAA , 0x06 ,(unsigned char)(uintptr_t)end_address, 0x00 };

    arr_data_point1_test[4] = mystring;

    arr_data_point1_test[4+1]= '\0';

    uint8_t arr_create_frame_point1[30], length_arr = 0;

    frame_test.StartFrame = 0xAA;

    frame_test.TypeMessage = POINT1;

    frame_test.Data[0] = mystring;

    frame_test.Data[1] = '\0';

    length_arr = SEC_Message_Create_Frame(frame_test, arr_create_frame_point1);

    printf("/*--------------------------------------------------------------------------------*/\n");

    printf("Start test_MessageCreateFramePoint1\n");

    printf("length_arr: %d\n", length_arr);

    printf("length_data: %ld\n", sizeof(mystring));

    Print_Data_Message(arr_create_frame_point1, length_arr);



    for (count_arr_test = 0; count_arr_test < 2 + 2; count_arr_test++)

    {

        UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((arr_data_point1_test[count_arr_test])), (UNITY_INT)(UNITY_UINT8 )((arr_create_frame_point1[count_arr_test])), (

       ((void *)0)

       ), (UNITY_UINT)(320), UNITY_DISPLAY_STYLE_UINT8);

    }

    printf("End test_MessageCreateFramePoint1\n");

}



void test_MessageCreateFramePoint2(void)

{



    uint8_t count_arr_test = 0;

    FrameMsg_t frame_test, frame_detect;

    uint8_t mystring = '2';

    uint8_t* start_address = (uint8_t*)0x00;

    uint8_t* end_address = start_address + 2 + sizeof(mystring)+1;

    uint8_t arr_data_point2_test[2 + 2 + 16] = {0xAA , 0x07 ,(unsigned char)(uintptr_t)end_address, 0x00 };

    arr_data_point2_test[4] = mystring;

    arr_data_point2_test[4+1]= '\0';

    uint8_t arr_create_frame_point2[30], length_arr = 0;

    frame_test.StartFrame = 0xAA;

    frame_test.TypeMessage = POINT2;

    frame_test.Data[0] = mystring;

    frame_test.Data[1] = '\0';

    length_arr = SEC_Message_Create_Frame(frame_test, arr_create_frame_point2);

    printf("/*--------------------------------------------------------------------------------*/\n");

    printf("Start test_MessageCreateFramePoint2\n");

    printf("length_arr: %d\n", length_arr);

    printf("length_data: %ld\n", sizeof(mystring));

    Print_Data_Message(arr_create_frame_point2, length_arr);



    for (count_arr_test = 0; count_arr_test < 2 + 2; count_arr_test++)

    {

        UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((arr_data_point2_test[count_arr_test])), (UNITY_INT)(UNITY_UINT8 )((arr_create_frame_point2[count_arr_test])), (

       ((void *)0)

       ), (UNITY_UINT)(350), UNITY_DISPLAY_STYLE_UINT8);

    }

    printf("End test_MessageCreateFramePoint2\n");

}



void test_MessageCreateFrameScore1(void)

{



    uint8_t count_arr_test = 0;

    FrameMsg_t frame_test, frame_detect;

    uint8_t mystring = '3';

    uint8_t* start_address = (uint8_t*)0x00;

    uint8_t* end_address = start_address + 2 + sizeof(mystring)+1;

    uint8_t arr_data_score1_test[2 + 2 + 16] = {0xAA , 0x08 ,(unsigned char)(uintptr_t)end_address, 0x00 };

    arr_data_score1_test[4] = mystring;

    arr_data_score1_test[4+1]= '\0';

    uint8_t arr_create_frame_score1[30], length_arr = 0;

    frame_test.StartFrame = 0xAA;

    frame_test.TypeMessage = SCORE1;

    frame_test.Data[0] = mystring;

    frame_test.Data[1] = '\0';

    length_arr = SEC_Message_Create_Frame(frame_test, arr_create_frame_score1);

    printf("/*--------------------------------------------------------------------------------*/\n");

    printf("Start test_MessageCreateFrameScore1\n");

    printf("length_arr: %d\n", length_arr);

    printf("length_data: %ld\n", sizeof(mystring));

    Print_Data_Message(arr_create_frame_score1, length_arr);



    for (count_arr_test = 0; count_arr_test < 2 + 2; count_arr_test++)

    {

        UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((arr_data_score1_test[count_arr_test])), (UNITY_INT)(UNITY_UINT8 )((arr_create_frame_score1[count_arr_test])), (

       ((void *)0)

       ), (UNITY_UINT)(380), UNITY_DISPLAY_STYLE_UINT8);

    }

    printf("End test_MessageCreateFrameScore1\n");

}









void test_MessageCreateFrameScore2(void)

{



    uint8_t count_arr_test = 0;

    FrameMsg_t frame_test, frame_detect;

    uint8_t mystring = '2';

    uint8_t* start_address = (uint8_t*)0x00;

    uint8_t* end_address = start_address + 2 + sizeof(mystring)+1;

    uint8_t arr_data_score2_test[2 + 2 + 16] = {0xAA , 0x09 ,(unsigned char)(uintptr_t)end_address, 0x00 };

    arr_data_score2_test[4] = mystring;

    arr_data_score2_test[4+1]= '\0';

    uint8_t arr_create_frame_score2[30], length_arr = 0;

    frame_test.StartFrame = 0xAA;

    frame_test.TypeMessage = SCORE2;

    frame_test.Data[0] = mystring;

    frame_test.Data[1] = '\0';

    length_arr = SEC_Message_Create_Frame(frame_test, arr_create_frame_score2);

    printf("/*--------------------------------------------------------------------------------*/\n");

    printf("Start test_MessageCreateFrameScore2\n");

    printf("length_arr: %d\n", length_arr);

    printf("length_data: %ld\n", sizeof(mystring));

    Print_Data_Message(arr_create_frame_score2, length_arr);



    for (count_arr_test = 0; count_arr_test < 2 + 2; count_arr_test++)

    {

        UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((arr_data_score2_test[count_arr_test])), (UNITY_INT)(UNITY_UINT8 )((arr_create_frame_score2[count_arr_test])), (

       ((void *)0)

       ), (UNITY_UINT)(413), UNITY_DISPLAY_STYLE_UINT8);

    }

    printf("End test_MessageCreateFrameScore2\n");

}







void Print_Data_Message(uint8_t *arr, uint8_t length)

{

    printf("- Create -\n");



    for (uint8_t i = 0; i < length; i++)

    {

        if (arr[i] <= 0x0F)

        {

            printf("0%x ", arr[i]);

        }

        else

        {

            printf("%x ", arr[i]);

        }

    }

    printf("\n");

}



void Print_Data_Message_Receive(uint8_t *arr, uint8_t length)

{

    printf("\nGi tr phn t trong mng c truyn qua USART: ");

    for (uint8_t i = 0; i < length; i++)

    {

        if (arr[i] <= 0x0F)

        {

            printf("0%x ", arr[i]);

        }

        else

        {

            printf("%x ", arr[i]);

        }

    }

}



void Print_Data_Detect(FrameMsg_t frame)

{

    printf("\n- Detect -");

    printf("\n StartFrame   : %x ", frame.StartFrame);

    printf("\n TypeMessage  : %x ", frame.TypeMessage);

    printf("\n LengthData   : %x ", frame.LengthData);

    if(frame.LengthData > 2)

    {

        printf("\n Data   : %s ", frame.Data);

    }

    printf("\n CheckFrame   : %x ", frame.CheckFrame);

}
