#include "Convert.h"

/*
    @brief: Chuyển mảng các biến kiểu bytes sang chuoi ky tu 
    @node: Chức năng hàm được sử dụng để Chuyển mảng các biến kiểu bytes sang chuoi ky tu
    @param data0: mang byte truyen vao .
    @param data1: Chuoi ky tu dau ra .
    @retval: chuoi ky tu.
*/

char* Convert_HexToString(uint8_t* arr_in, size_t arr_size)
{
    char* result = (char*)malloc(arr_size + 1);
    for (size_t i = 0; i < arr_size; i++) 
    {
        result[i] = (char)arr_in[i];
    }
    result[arr_size] = '\0';
    return result;
}

/*
    @brief: Chuyển biến kiểu int sang dạng mảng byte
    @node: Chức năng hàm được sử dụng để Chuyển biến kiểu int sang dạng mảng byte 4 phần tử
    @param data: Là một biến kiểu int cần được chuyển sang mảng byte.
    @retval: Mảng bytes.
*/
uint8_t *Sec_Convert_From_Int_To_Bytes(int data)
{
    static data_format_int_bytes input_convert;
    input_convert.data_int = data;
    return input_convert.bytes;
}
/*
    @brief: Chuyển mảng các biến kiểu bytes sang biến kiểu uint16_t
    @node: Chức năng hàm được sử dụng để Chuyển mảng các biến kiểu bytes sang biến kiểu uint16_t
    @param data0: Biến đầu tiên của mảng .
    @param data1: Biến thứ hai của mảng .
    @retval: Biến Uint16_t.
*/
uint16_t Sec_Convert_From_Bytes_To_Uint16(uint8_t data1, uint8_t data2)
{
    data_format_uint8_16_t input_convert;
    input_convert.bytes[0] = data1;
    input_convert.bytes[1] = data2;

    return input_convert.data_uint16;
}


//void Convert_From_String_To_Byte() 