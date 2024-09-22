/*
 * @Author: 狐碎叶
 * @Date: 2024-09-22 22:42:35
 * @LastEditors: error: git config user.email & please set dead value or install git
 * @LastEditTime: 2024-09-23 00:33:00
 * @FilePath: \MCU_Projeck\Device\ds1302.c
 * @Description: DS1302模块
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */

#include <REG52.H>
#include "./ds1302.h"

#define CE P3_0
#define SCL P3_1
#define SDA P3_2
/*
 * @brief: 向芯片传入一位指定电平
 * @param: 电平(高/低)
 * @return: 无
*/
void write_bit(uint8_t value){
    SCL = 0;
    if(value) SDA = 1;
    else SDA = 0;
    SCL = 1;
    
}
/*
 * @brief: 读取一位数据
 * @param:无
 * @return: 返回一个字节的电平，但该字节中仅有一位数据
*/
uint8_t read_bit(){
    uint8_t res = 0;
    SCL = 0;
    res = SDA;
    SCL = 1;
    return res;
}
/*
 * @brief: 向芯片传入一个字节数据
 * @param: 传入的字节数据
 * @return: 无
*/
void write_byte(uint8_t value){
    uint8_t i = 8;
    while(i--){
        if(value & (0x80 >> i)) write_bit(1);
        else write_bit(0);
    }
}
/*
 * @brief: 读取一个字节
 * @param:无
 * @return: 返回一个字节数据
*/
uint8_t read_byte(){
    uint8_t res = 0;
    uint8_t i = 8;
    while(i--) 
        if(read_bit()) res |= (0x80 >> i);
}

/*
 * @brief: 写入数据(同时进行解锁和上锁操作)
 * @param: 要写入的数据（地址、数据）
 * @return: 返回一个字节数据
*/
void DS1302_Write(uint8_t *value){
    CE = 1;
    write_byte(0x8E);
    write_byte(0x00);
    CE = 0;
    CE = 1;
    write_byte(*(value++));
    write_byte(*(value));
    CE = 0;
    CE = 1;
    write_byte(0x8E);
    write_byte(0x80);
    CE = 0;    
}
/*
 * @brief: 读取数据
 * @param: 要读取的数据的目标地址
 * @return: 返回一个字节数据
*/
uint8_t DS1302_Read(uint8_t address){
    uint8_t res = 0;
    CE = 1;
    write_byte(address);
    res = read_data();
    CE = 0;
}