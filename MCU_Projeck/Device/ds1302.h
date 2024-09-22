/*
 * @Author: 狐碎叶
 * @Date: 2024-09-22 22:42:41
 * @LastEditors: error: git config user.email & please set dead value or install git
 * @LastEditTime: 2024-09-23 00:29:21
 * @FilePath: \MCU_Projeck\Device\ds1302.h
 * @Description: DS1302模块
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef __DS1302_H__
#define __DS1302_H__
#include "./data_type.h"

void DS1302_Read(uint8_t address);
void DS1302_Write(uint8_t *value);

#endif // !__DS1302_H__