#include "Message.h"
#include "Convert.h"


uint8_t SEC_Message_Create_Frame(FrameMsg_t DataIn, uint8_t *DataOut)
{
    FrameMsg_t *temp_datain;
    uint8_t *arr_temp;
    uint16_t count_arr = 0;
    uint16_t data_leng ;
    temp_datain = &DataIn;
    arr_temp = (uint8_t *)temp_datain;

    if(DataIn.StartFrame != START_BYTE )
    {
       return 0;
    }
    switch (DataIn.TypeMessage)
    {
        case ROUND3x3:
            DataIn.LengthData = LENGTH_ROUND;
            break;
        case ROUND5x5:
            DataIn.LengthData = LENGTH_ROUND;
            break;
        case ROUND7X7:
            DataIn.LengthData = LENGTH_ROUND;
            break;
        case NAME_PLAYER_1:
            data_leng = strlen(DataIn.Data);
            DataIn.Data[data_leng] = '\0';
            DataIn.LengthData = 2 + data_leng +1;
            break;
        case NAME_PLAYER_2:
            data_leng = strlen(DataIn.Data);
            DataIn.Data[data_leng] = '\0';
            DataIn.LengthData = 2 + data_leng +1;
            break;
        case POINT1:
            data_leng = strlen(DataIn.Data);
            DataIn.Data[data_leng] = '\0';
            DataIn.LengthData = 2 + data_leng +1;
            break;
        case POINT2:
            data_leng = strlen(DataIn.Data);
            DataIn.Data[data_leng] = '\0';
            DataIn.LengthData = 2 + data_leng +1;
            break;
        case SCORE1:
            data_leng = strlen(DataIn.Data);
            DataIn.Data[data_leng] = '\0';
            DataIn.LengthData = 2 + data_leng +1;
            break;
        case SCORE2:
            data_leng = strlen(DataIn.Data);
            DataIn.Data[data_leng] = '\0';
            DataIn.LengthData = 2 + data_leng +1;
            break;
    }
    DataIn.CheckFrame = CheckSum(arr_temp, LENGTH_DEFAULT+ DataIn.LengthData);
    // copy arr_temp vao mang data out
    for (count_arr = 0; count_arr < (LENGTH_DEFAULT + DataIn.LengthData) ; count_arr++)
    {
        DataOut[count_arr] = arr_temp[count_arr];
    }
    DataOut[count_arr] = (DataIn.CheckFrame & 0xff);
    DataOut[count_arr + 1] = ((DataIn.CheckFrame >> 8) & 0xff);
    count_arr+=2;
    return count_arr;
}      

uint8_t SEC_Message_Detect_Frame(uint8_t *DataIn, FrameMsg_t *DataOut, uint16_t length_arr )
{
    FrameMsg_t *temp_datain;
    uint8_t count = 0;
    char* string_out = Convert_HexToString(DataIn, length_arr);  // chuoi ky tu thong tin sau khi chuyen tu byte 

    /* ép kiểu uint8_t về kiểu temp_datain, mục đích để chuyển từ arr* -> struct* */

    temp_datain = (FrameMsg_t *)DataIn;
    DataOut->StartFrame  = DataIn[count];
    count += 1;
    DataOut->TypeMessage = DataIn[count];
    count += 1;
    DataOut->LengthData  = Sec_Convert_From_Bytes_To_Uint16(DataIn[count], DataIn[count+1]);
    count += 2;
    switch (DataOut->TypeMessage)
    {
        case NAME_PLAYER_1:
            for(uint16_t i = 0 ; i < length_arr - count- 2; i++)
            {
                DataOut->Data[i] = string_out[count+ i];
            }
            count = count +length_arr - count- 2;
            free(string_out);
            break;
        case NAME_PLAYER_2:
            for(uint16_t i = 0 ; i < length_arr - count- 2; i++)
            {
                DataOut->Data[i] = string_out[count+ i];
            }
            count = count +length_arr - count- 2;
            free(string_out);
            break;   
    }
    DataOut->CheckFrame  = Sec_Convert_From_Bytes_To_Uint16(DataIn[length_arr - 2] , DataIn[length_arr -1]);

    return 0;
}



/*-------------------------------------------------------------------------------------------------------*/
uint16_t CheckSum(uint8_t *buf, uint8_t len)
{
    uint16_t crc = 0xFFFF, pos = 0, i = 0;
    for (pos = 0; pos < len; pos++)
    {
        crc ^= (uint16_t)buf[pos]; // XOR byte into least sig. byte of crc
        for (i = 8; i != 0; i--)   // Loop over each bit
        {
            if ((crc & 0x0001) != 0) // If the LSB is set
            {
                crc >>= 1; // Shift right and XOR 0xA001
                crc ^= 0xA001;
            }
            else // Else LSB is not set
            {
                crc >>= 1; // Just shift right
            }
        }
    }
    return crc;
}
