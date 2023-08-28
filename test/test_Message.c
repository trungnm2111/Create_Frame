// #ifdef TEST

#include "unity.h"
#include "Message.h"
#include "Convert.h"
#include "fsm_array_receive.h"

void Print_Data_Message(uint8_t *arr, uint8_t length);
void Print_Data_Detect(FrameMsg_t frame);

/*---------------------------------------------------- TYPE --------------------------------------------------------------*/

void test_MessageCreateFrameRound3x3(void)
{
    /*---------------------------------------------------(START_CREAT_FRAME_ROUND3X3)--------------------------------------*/
    uint8_t count_arr_test = 0;
    uint8_t arr_data_round3x3_test[LENGTH_DEFAULT + LENGTH_ROUND] = {0xAA, 0x01, 0x02, 0x00}; 

    FrameMsg_t frame_test, frame_detect;
    uint8_t arr_create_frame_round3x3[30], length_arr = 0;

    frame_test.StartFrame   = START_BYTE;
    frame_test.TypeMessage  = ROUND3x3;
    length_arr              = SEC_Message_Create_Frame(frame_test, arr_create_frame_round3x3);

    printf("/*--------------------------------------------------------------------------------*/\n");
    printf("Start test_MessageCreateFrameRound3x3\n");
    printf("length_arr: %d\n", length_arr);
    Print_Data_Message(arr_create_frame_round3x3, length_arr);

    // tạo bản tin dạng frame từ arr
    for (count_arr_test = 0; count_arr_test < LENGTH_DEFAULT + LENGTH_ROUND; count_arr_test++)
    {
        TEST_ASSERT_EQUAL_UINT8(arr_data_round3x3_test[count_arr_test], arr_create_frame_round3x3[count_arr_test]);
    }

    printf("End test_MessageCreateFrameRound3x3\n");
    
    /*---------------------------------------------------(END_CREAT_FRAME_ROUND3X3)--------------------------------------*/

    /*------------------------------------------------------ TEST - FSM ------------------------------------------------*/
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
        TEST_ASSERT_EQUAL_UINT8(arr_create_frame_round3x3[count_arr_test],arr_data_fsm[count_arr_test]);
    }
    Print_Data_Message_Receive(arr_data_fsm, length_arr);

    /*------------------------------------------------------ END TEST - FSM ------------------------------------------------*/
    
    /*------------------------------------------------(START_DETECT_FRAME_ROUND3X3)--------------------------------------*/

    SEC_Message_Detect_Frame(arr_create_frame_round3x3 , &frame_detect, length_arr);

    frame_test.LengthData = Sec_Convert_From_Bytes_To_Uint16(arr_create_frame_round3x3[LENGTH_DEFAULT], 
                                                            arr_create_frame_round3x3[LENGTH_DEFAULT + 1 ]);
    frame_test.CheckFrame = Sec_Convert_From_Bytes_To_Uint16(arr_create_frame_round3x3[length_arr - 2],
                                                            arr_create_frame_round3x3[length_arr - 1 ]);
    TEST_ASSERT_EQUAL_HEX8(frame_test.StartFrame, frame_detect.StartFrame);
    TEST_ASSERT_EQUAL_HEX8(frame_test.TypeMessage, frame_detect.TypeMessage);
    TEST_ASSERT_EQUAL_HEX8(frame_test.LengthData, frame_detect.LengthData);
    TEST_ASSERT_EQUAL_HEX16(frame_test.CheckFrame, frame_detect.CheckFrame);

    Print_Data_Detect(frame_detect);
    /*------------------------------------------------(END_DETECT_FRAME_ROUND3X3)--------------------------------------*/

    printf("\nEnd test_SEC_Message_Detect_Frame_Round3x3\n");
    printf("/*--------------------------------------------------------------------------------*/\n\n");

}

void test_MessageCreateFrameRound5x5(void)
{
    /*---------------------------------------------------(START_CREAT_FRAME_ROUND5X5)--------------------------------------*/
    uint8_t count_arr_test = 0;
    uint8_t arr_data_round5x5_test[LENGTH_DEFAULT + LENGTH_ROUND] = {0xAA , 0x02, 0x02, 0x00};

    FrameMsg_t frame_test, frame_detect;
    uint8_t arr_create_frame_out[30], length_arr = 0;

    frame_test.StartFrame   = START_BYTE;
    frame_test.TypeMessage  = ROUND5x5;
    length_arr              = SEC_Message_Create_Frame(frame_test, arr_create_frame_out);
    
    printf("/*--------------------------------------------------------------------------------*/\n");
    printf("Start test_MessageCreateFrameRound5x5\n");
    printf("length_arr: %d\n", length_arr);
    Print_Data_Message(arr_create_frame_out, length_arr);

    for (count_arr_test = 0; count_arr_test < LENGTH_DEFAULT + LENGTH_ROUND; count_arr_test++)
    {
        TEST_ASSERT_EQUAL_UINT8(arr_data_round5x5_test[count_arr_test], arr_create_frame_out[count_arr_test]);
    }
    printf("End test_MessageCreateFrameRound5x5\n");
    

     /*---------------------------------------------------(END_CREAT_FRAME_ROUND5X5)--------------------------------------*/

     /*------------------------------------------------(START_DETECT_FRAME_ROUND5X5)--------------------------------------*/

    SEC_Message_Detect_Frame(arr_data_round5x5_test , &frame_detect, length_arr);

    frame_test.LengthData = Sec_Convert_From_Bytes_To_Uint16(arr_data_round5x5_test[LENGTH_DEFAULT], 
                                                            arr_data_round5x5_test[LENGTH_DEFAULT + 1 ]);
    frame_test.CheckFrame = Sec_Convert_From_Bytes_To_Uint16(arr_data_round5x5_test[length_arr - 2],
                                                            arr_data_round5x5_test[length_arr -1 ]);
    TEST_ASSERT_EQUAL_HEX8(frame_test.StartFrame, frame_detect.StartFrame);
    TEST_ASSERT_EQUAL_HEX8(frame_test.TypeMessage, frame_detect.TypeMessage);
    TEST_ASSERT_EQUAL_HEX8(frame_test.LengthData, frame_detect.LengthData);
    TEST_ASSERT_EQUAL_HEX16(frame_test.CheckFrame, frame_detect.CheckFrame);

    Print_Data_Detect(frame_detect);

    /*------------------------------------------------(END_DETECT_FRAME_ROUND3X3)--------------------------------------*/

    printf("\nEnd test_SEC_Message_Detect_Frame_Round5X5\n");

    printf("/*--------------------------------------------------------------------------------*/\n\n");
}

void test_MessageCreateFrameRound7X7(void)
{
    /*---------------------------------------------------(START_CREAT_FRAME_ROUND7X7)--------------------------------------*/
    uint8_t count_arr_test = 0;
    uint8_t arr_data_round7x7_test[LENGTH_DEFAULT + LENGTH_ROUND] = {0xAA , 0x03, 0x02, 0x00};

    FrameMsg_t frame_test, frame_detect;
    uint8_t arr_create_frame_out[30], length_arr = 0;

    frame_test.StartFrame   = START_BYTE;
    frame_test.TypeMessage  = ROUND7X7;
    length_arr              = SEC_Message_Create_Frame(frame_test, arr_create_frame_out);
    
    printf("/*--------------------------------------------------------------------------------*/\n");
    printf("Start test_MessageCreateFrameRound7x7\n");
    printf("length_arr: %d\n", length_arr);
    Print_Data_Message(arr_create_frame_out, length_arr);

    for (count_arr_test = 0; count_arr_test < LENGTH_DEFAULT + LENGTH_ROUND; count_arr_test++)
    {
        TEST_ASSERT_EQUAL_UINT8(arr_data_round7x7_test[count_arr_test], arr_create_frame_out[count_arr_test]);
    }
    printf("End test_MessageCreateFrameRound7x7\n");
    
     /*---------------------------------------------------(END_CREAT_FRAME_ROUND7X7)--------------------------------------*/

     /*------------------------------------------------(START_DETECT_FRAME_ROUND7X7)--------------------------------------*/

    SEC_Message_Detect_Frame(arr_data_round7x7_test , &frame_detect,length_arr);

    frame_test.LengthData = Sec_Convert_From_Bytes_To_Uint16(arr_data_round7x7_test[LENGTH_DEFAULT], 
                                                            arr_data_round7x7_test[LENGTH_DEFAULT + 1 ]);
    frame_test.CheckFrame = Sec_Convert_From_Bytes_To_Uint16(arr_data_round7x7_test[length_arr - 2],
                                                            arr_data_round7x7_test[length_arr -1 ]);
    TEST_ASSERT_EQUAL_HEX8(frame_test.StartFrame, frame_detect.StartFrame);
    TEST_ASSERT_EQUAL_HEX8(frame_test.TypeMessage, frame_detect.TypeMessage);
    TEST_ASSERT_EQUAL_HEX8(frame_test.LengthData, frame_detect.LengthData);
    TEST_ASSERT_EQUAL_HEX16(frame_test.CheckFrame, frame_detect.CheckFrame);

    Print_Data_Detect(frame_detect);

    /*------------------------------------------------(END_DETECT_FRAME_ROUND7X7)--------------------------------------*/

    printf("\nEnd test_SEC_Message_Detect_Frame_Round7X7\n");

    printf("/*--------------------------------------------------------------------------------*/\n\n");
}

void test_MessageCreateFrameNamePlayer1(void)
{
    /*---------------------------------------------------(START_CREAT_FRAME_NAMEPLAYER1)--------------------------------------*/
    uint8_t count_arr_test = 0;
    FrameMsg_t frame_test, frame_detect;
    uint8_t mystring[] = "Huong";
    uint8_t* start_address = (uint8_t*)0x00;
    uint8_t* end_address = start_address + 2 + sizeof(mystring);
    uint8_t arr_data_name_player1_test[LENGTH_DEFAULT + LENGTH_BASE + 16] = {0xAA , 0x04 ,(unsigned char)(uintptr_t)end_address, 0x00 };
    for(int i = 0; i < sizeof(mystring); i++)
    {
        arr_data_name_player1_test[i + 4] = mystring[i];
    }
    uint8_t arr_create_frame_name_player1[30], length_arr = 0;
    frame_test.StartFrame   = START_BYTE;
    frame_test.TypeMessage  = NAME_PLAYER_1;
    memcpy(frame_test.Data, mystring, sizeof(mystring));
    // frame_test.Data[sizeof(mystring)] = '\0';
    length_arr              = SEC_Message_Create_Frame(frame_test, arr_create_frame_name_player1);
    printf("/*--------------------------------------------------------------------------------*/\n");
    printf("Start test_MessageCreateFrameNamePlayer1\n");
    printf("length_arr: %d\n", length_arr);
    printf("length_data: %ld\n", sizeof(mystring)+2);
    Print_Data_Message(arr_create_frame_name_player1, length_arr);

    for (count_arr_test = 0; count_arr_test < LENGTH_DEFAULT + LENGTH_ROUND; count_arr_test++)
    {
        TEST_ASSERT_EQUAL_UINT8(arr_data_name_player1_test[count_arr_test], arr_create_frame_name_player1[count_arr_test]);
    }
    printf("End test_MessageCreateFrameNamePlayer1\n");

    /*---------------------------------------------------(END_CREAT_FRAME_NAMEPLAER1)--------------------------------------*/

    /*------------------------------------------------(START_DETECT_FRAME_PLAYER1)--------------------------------------*/

    SEC_Message_Detect_Frame(arr_create_frame_name_player1 , &frame_detect, length_arr);

    frame_test.LengthData = Sec_Convert_From_Bytes_To_Uint16(arr_create_frame_name_player1[LENGTH_DEFAULT], 
                                                            arr_create_frame_name_player1[LENGTH_DEFAULT + 1 ]);
    frame_test.CheckFrame = Sec_Convert_From_Bytes_To_Uint16(arr_create_frame_name_player1[length_arr - 2],
                                                            arr_create_frame_name_player1[length_arr - 1 ]);
    printf("detect FrameNamePlayer1\n");
    
    TEST_ASSERT_EQUAL_HEX8(frame_test.StartFrame, frame_detect.StartFrame);
    TEST_ASSERT_EQUAL_HEX8(frame_test.TypeMessage, frame_detect.TypeMessage);
    TEST_ASSERT_EQUAL_HEX8(frame_test.LengthData, frame_detect.LengthData);
    for(uint8_t i = 0; i < length_arr -2 - LENGTH_DEFAULT; i++ )
    {
        TEST_ASSERT_EQUAL_HEX8(frame_test.Data[i], frame_detect.Data[i]);
    }
   TEST_ASSERT_EQUAL_HEX16(frame_test.CheckFrame, frame_detect.CheckFrame);
    Print_Data_Detect(frame_detect);

    /*------------------------------------------------(END_DETECT_FRAME_NAME_PLAYER1)--------------------------------------*/

    printf("\nEnd test_SEC_Message_Detect_Frame_Name1\n");
}

void test_MessageCreateFrameNamePlayer2(void)
{
    uint8_t count_arr_test = 0;
    FrameMsg_t frame_test, frame_detect;
    uint8_t mystring[] = "Khanh Linh";
    uint8_t* start_address = (uint8_t*)0x00;
    uint8_t* end_address = start_address + 2 + sizeof(mystring);
    uint8_t arr_data_name_player2_test[LENGTH_DEFAULT + LENGTH_BASE + 16] = {0xAA , 0x05 ,(unsigned char)(uintptr_t)end_address, 0x00 };
    for(int i = 0; i < sizeof(mystring); i++)
    {
        arr_data_name_player2_test[i + 4] = mystring[i];
    }
    uint8_t arr_create_frame_name_player2[30], length_arr = 0;
    frame_test.StartFrame   = START_BYTE;
    frame_test.TypeMessage  = NAME_PLAYER_2;
    memcpy(frame_test.Data, mystring, sizeof(mystring));
    // frame_test.Data[sizeof(mystring)] = '\0';
    length_arr              = SEC_Message_Create_Frame(frame_test, arr_create_frame_name_player2);
    printf("/*--------------------------------------------------------------------------------*/\n");
    printf("Start test_MessageCreateFrameNamePlayer2\n");
    printf("length_arr: %d\n", length_arr);
    printf("length_data: %ld\n", sizeof(mystring));
    Print_Data_Message(arr_create_frame_name_player2, length_arr);

    for (count_arr_test = 0; count_arr_test < LENGTH_DEFAULT + LENGTH_ROUND; count_arr_test++)
    {
        TEST_ASSERT_EQUAL_UINT8(arr_data_name_player2_test[count_arr_test], arr_create_frame_name_player2[count_arr_test]);
    }
    printf("End test_MessageCreateFrameNamePlayer2\n");

    /*---------------------------------------------------(END_CREAT_FRAME_NAMEPLAER2)--------------------------------------*/

    /*------------------------------------------------(START_DETECT_FRAME_PLAYER2)--------------------------------------*/

    SEC_Message_Detect_Frame(arr_create_frame_name_player2 , &frame_detect, length_arr);

    frame_test.LengthData = Sec_Convert_From_Bytes_To_Uint16(arr_create_frame_name_player2[LENGTH_DEFAULT], 
                                                            arr_create_frame_name_player2[LENGTH_DEFAULT + 1 ]);
    frame_test.CheckFrame = Sec_Convert_From_Bytes_To_Uint16(arr_create_frame_name_player2[length_arr - 2],
                                                            arr_create_frame_name_player2[length_arr - 1 ]);
    printf("detect FrameNamePlayer2\n");
    
    TEST_ASSERT_EQUAL_HEX8(frame_test.StartFrame, frame_detect.StartFrame);
    TEST_ASSERT_EQUAL_HEX8(frame_test.TypeMessage, frame_detect.TypeMessage);
    TEST_ASSERT_EQUAL_HEX8(frame_test.LengthData, frame_detect.LengthData);
    for(uint8_t i = 0; i < length_arr -2 - LENGTH_DEFAULT; i++ )
    {
        TEST_ASSERT_EQUAL_HEX8(frame_test.Data[i], frame_detect.Data[i]);
    }
   TEST_ASSERT_EQUAL_HEX16(frame_test.CheckFrame, frame_detect.CheckFrame);
    Print_Data_Detect(frame_detect);

    /*------------------------------------------------(END_DETECT_FRAME_NAME_PLAYER1)--------------------------------------*/

    printf("\nEnd test_SEC_Message_Detect_Frame_Name2\n");  
     printf("/*--------------------------------------------------------------------------------*/\n\n");
}

void test_MessageCreateFramePoint1(void)
{
    /*---------------------------------------------------(START_CREAT_FRAME_POINT1)--------------------------------------*/
    uint8_t count_arr_test = 0;
    FrameMsg_t frame_test, frame_detect;
    uint8_t mystring = '1';
    uint8_t* start_address = (uint8_t*)0x00;
    uint8_t* end_address = start_address + 2 + sizeof(mystring)+1;
    uint8_t arr_data_point1_test[LENGTH_DEFAULT + LENGTH_BASE + 16] = {0xAA , 0x06 ,(unsigned char)(uintptr_t)end_address, 0x00 };
    arr_data_point1_test[4] = mystring;
    arr_data_point1_test[4+1]= '\0';
    uint8_t arr_create_frame_point1[30], length_arr = 0;
    frame_test.StartFrame   = START_BYTE;
    frame_test.TypeMessage  = POINT1;
    frame_test.Data[0] = mystring;
    frame_test.Data[1] = '\0';
    length_arr              = SEC_Message_Create_Frame(frame_test, arr_create_frame_point1);
    printf("/*--------------------------------------------------------------------------------*/\n");
    printf("Start test_MessageCreateFramePoint1\n");
    printf("length_arr: %d\n", length_arr);
    printf("length_data: %ld\n", sizeof(mystring));
    Print_Data_Message(arr_create_frame_point1, length_arr);

    for (count_arr_test = 0; count_arr_test < LENGTH_DEFAULT + LENGTH_ROUND; count_arr_test++)
    {
        TEST_ASSERT_EQUAL_UINT8(arr_data_point1_test[count_arr_test], arr_create_frame_point1[count_arr_test]);
    }
    printf("End test_MessageCreateFramePoint1\n");
}

void test_MessageCreateFramePoint2(void)
{
    /*---------------------------------------------------(START_CREAT_FRAME_POINT2)--------------------------------------*/
    uint8_t count_arr_test = 0;
    FrameMsg_t frame_test, frame_detect;
    uint8_t mystring = '2';
    uint8_t* start_address = (uint8_t*)0x00;
    uint8_t* end_address = start_address + 2 + sizeof(mystring)+1;
    uint8_t arr_data_point2_test[LENGTH_DEFAULT + LENGTH_BASE + 16] = {0xAA , 0x07 ,(unsigned char)(uintptr_t)end_address, 0x00 };
    arr_data_point2_test[4] = mystring;
    arr_data_point2_test[4+1]= '\0';
    uint8_t arr_create_frame_point2[30], length_arr = 0;
    frame_test.StartFrame   = START_BYTE;
    frame_test.TypeMessage  = POINT2;
    frame_test.Data[0] = mystring;
    frame_test.Data[1] = '\0';
    length_arr              = SEC_Message_Create_Frame(frame_test, arr_create_frame_point2);
    printf("/*--------------------------------------------------------------------------------*/\n");
    printf("Start test_MessageCreateFramePoint2\n");
    printf("length_arr: %d\n", length_arr);
    printf("length_data: %ld\n", sizeof(mystring));
    Print_Data_Message(arr_create_frame_point2, length_arr);

    for (count_arr_test = 0; count_arr_test < LENGTH_DEFAULT + LENGTH_ROUND; count_arr_test++)
    {
        TEST_ASSERT_EQUAL_UINT8(arr_data_point2_test[count_arr_test], arr_create_frame_point2[count_arr_test]);
    }
    printf("End test_MessageCreateFramePoint2\n");
}

void test_MessageCreateFrameScore1(void)
{
    /*---------------------------------------------------(START_CREAT_FRAME_SCORE1)--------------------------------------*/
    uint8_t count_arr_test = 0;
    FrameMsg_t frame_test, frame_detect;
    uint8_t mystring = '3';
    uint8_t* start_address = (uint8_t*)0x00;
    uint8_t* end_address = start_address + 2 + sizeof(mystring)+1;
    uint8_t arr_data_score1_test[LENGTH_DEFAULT + LENGTH_BASE + 16] = {0xAA , 0x08 ,(unsigned char)(uintptr_t)end_address, 0x00 };
    arr_data_score1_test[4] = mystring;
    arr_data_score1_test[4+1]= '\0';
    uint8_t arr_create_frame_score1[30], length_arr = 0;
    frame_test.StartFrame   = START_BYTE;
    frame_test.TypeMessage  = SCORE1;
    frame_test.Data[0] = mystring;
    frame_test.Data[1] = '\0';
    length_arr              = SEC_Message_Create_Frame(frame_test, arr_create_frame_score1);
    printf("/*--------------------------------------------------------------------------------*/\n");
    printf("Start test_MessageCreateFrameScore1\n");
    printf("length_arr: %d\n", length_arr);
    printf("length_data: %ld\n", sizeof(mystring));
    Print_Data_Message(arr_create_frame_score1, length_arr);

    for (count_arr_test = 0; count_arr_test < LENGTH_DEFAULT + LENGTH_ROUND; count_arr_test++)
    {
        TEST_ASSERT_EQUAL_UINT8(arr_data_score1_test[count_arr_test], arr_create_frame_score1[count_arr_test]);
    }
    printf("End test_MessageCreateFrameScore1\n");
}




void test_MessageCreateFrameScore2(void)
{
    /*---------------------------------------------------(START_CREAT_FRAME_SCORE2)--------------------------------------*/
    uint8_t count_arr_test = 0;
    FrameMsg_t frame_test, frame_detect;
    uint8_t mystring = '2';
    uint8_t* start_address = (uint8_t*)0x00;
    uint8_t* end_address = start_address + 2 + sizeof(mystring)+1;
    uint8_t arr_data_score2_test[LENGTH_DEFAULT + LENGTH_BASE + 16] = {0xAA , 0x09 ,(unsigned char)(uintptr_t)end_address, 0x00 };
    arr_data_score2_test[4] = mystring;
    arr_data_score2_test[4+1]= '\0';
    uint8_t arr_create_frame_score2[30], length_arr = 0;
    frame_test.StartFrame   = START_BYTE;
    frame_test.TypeMessage  = SCORE2;
    frame_test.Data[0] = mystring;
    frame_test.Data[1] = '\0';
    length_arr              = SEC_Message_Create_Frame(frame_test, arr_create_frame_score2);
    printf("/*--------------------------------------------------------------------------------*/\n");
    printf("Start test_MessageCreateFrameScore2\n");
    printf("length_arr: %d\n", length_arr);
    printf("length_data: %ld\n", sizeof(mystring));
    Print_Data_Message(arr_create_frame_score2, length_arr);

    for (count_arr_test = 0; count_arr_test < LENGTH_DEFAULT + LENGTH_ROUND; count_arr_test++)
    {
        TEST_ASSERT_EQUAL_UINT8(arr_data_score2_test[count_arr_test], arr_create_frame_score2[count_arr_test]);
    }
    printf("End test_MessageCreateFrameScore2\n");
}

/*------------------------------------------------------------------------------------------------------------*/
/* Hàm in data bản tin */
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
// ham in du lieu truyen nhan 
void Print_Data_Message_Receive(uint8_t *arr, uint8_t length)
{
    printf("\nGiá trị phần tử trong mảng được truyền qua USART: ");
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

// #endif // TEST
