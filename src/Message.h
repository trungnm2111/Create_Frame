    #ifndef MESSAGE_H
#define MESSAGE_H

#include "stdint.h"
#include "string.h"

#define START_BYTE          0xAA
#define LENGTH_DEFAULT      2 /* StartFrame 1 + TypeMessage 1 */
#define LENGTH_ROUND        2 /* CheckFrame 2 */
#define LENGTH_BASE         2 /* CheckFrame 2 */

// #define END_STRING          0x21 /* Dấu chấm than !*/
/* TypeMessage */
typedef enum
{
    ROUND3x3        = 1,
    ROUND5x5        = 2,
    ROUND7X7        = 3,
    NAME_PLAYER_1   = 4,
    NAME_PLAYER_2   = 5,
    POINT1          = 6,
    POINT2          = 7,
    SCORE1          = 8,
    SCORE2          = 9,
    ROUND           = 10,  
} type_message_e;

/* Bản tin cập nhật */
typedef struct
{
    uint8_t StartFrame;
    uint8_t TypeMessage;
    uint16_t LengthData; 
    uint8_t  Data[16];
    uint16_t CheckFrame;
} FrameMsg_t;

/*
    @brief: Hàm tạo Frame data chuẩn.
    @node: Chức năng của hàm là chuyển data từ dạng struct về dạng arr.
    @param datain: Là một struct chưa các thông tin được người dùng chỉ định để tạo bản tin.
    @param dataout: Là con trỏ dùng để lấy mảng sao khi tạo thành công.
    @retval: Trả về 0 là lỗi, Lớn hơn 0 là thành công.
*/
uint8_t SEC_Message_Create_Frame(FrameMsg_t DataIn, uint8_t *DataOut);

/*
    @brief: Hàm tách Frame data.
    @node: Chức năng của hàm là chuyển data từ dạng arr về dạng struct.
    @param datain: Là một mảng chứa data.
    @param dataout: Là một struct chứa data đầu ra.
    @retval: trả về 1 thành công, trả về 0 là lỗi.
*/
uint8_t SEC_Message_Detect_Frame(uint8_t *DataIn, FrameMsg_t *DataOut, uint16_t length_arr);

uint16_t CheckSum(uint8_t *buf, uint8_t len);

#endif // MESSAGE_H
