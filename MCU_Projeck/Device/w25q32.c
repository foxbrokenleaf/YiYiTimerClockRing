/*
 * @Author: error: git config user.email & please set dead value or install git
 * @Date: 2024-09-23 23:37:06
 * @LastEditors: error: git config user.email & please set dead value or install git
 * @LastEditTime: 2024-09-24 00:43:09
 * @FilePath: \MCU_Projeck\Device\w25q32.c
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#include "REG52.h"
#include "./w25q32.h"

#define CE P4_0
#define SCL P4_1
#define SDA_O P4_2
#define SDA_I P4_3

uint8_t Read_Data_Page[256];

/*
 * @brief:向总线写入一个位
 * @param:要写入的电平
 * @return: 无
*/
void write_bit(uint8_t value){
    SCL = 0;
    if(value) SDA_O = 1;
    else SDA_O = 0;
    SCL = 1;
    SCL = 0;
}

/*
 * @brief: 从总线读取一个位
 * @param: 无
 * @return: 读取的位
*/
uint8_t read_bit(){
    uint8_t res = 0;
    SCL = 0;
    SCL = 1;
    if(SDA_I) res = 1;
    else res = 0;
    SCL = 0;
    return res;
}

/*
 * @brief: 向总线写入一个字节
 * @param: 要写入的字节
 * @return: 无
*/
void write_byte(uint8_t value){
    uint8_t i = 8;
    while(i--)
        write_bit(value & (0x01 << i));
}

/*
 * @brief: 从总线读取一个字节
 * @param: 无
 * @return: 读取的字节
*/
uint8_t read_byte(){
    uint8_t res = 0;
    uint8_t i = 8;
    while(i--)
        if(read_bit()) res |= (0x01 << i);
    return res;
}

/*
 * @brief: 向芯片写入数据
 * @param: 头地址的字节为指令，后3个字节为地址，剩下的全为要写入的数据*256个
 * @return: 无
*/
void write_data(uint8_t *value){
    uint8_t i = 255;
    CE = 0;
    write_byte(*(value++)); //指令
    write_byte(*(value++)); //地址
    write_byte(*(value++));
    write_byte(*(value++));
    while(i-- >= 0){
        if(i != 0) write_byte(*(value++));
        else write_byte(*(value));
    }
    CE = 1;
}

/*
 * @brief: 从芯片读取数据
 * @param: 地址
 * @return: 返回地址指向的数据
*/
uint8_t* read_data(uint8_t *value){
    uint8_t i = 0;
    CE = 0;
    write_byte(*(value++)); //指令
    write_byte(*(value++)); //地址
    write_byte(*(value++));
    write_byte(*(value++));    
    while(i <= 255) Read_Data_Page[i++] = read_byte();
    CE = 1;
}