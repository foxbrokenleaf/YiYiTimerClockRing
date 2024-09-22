<!--
 * @Author: error: git config user.email & please set dead value or install git
 * @Date: 2024-08-13 04:54:22
 * @LastEditors: error: git config user.email & please set dead value or install git
 * @LastEditTime: 2024-09-22 21:43:29
 * @FilePath: \YiYiTimerClockRing\README.md
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
-->
# 亦亦的小闹钟-可自定义铃声

## 编译环境
+ Windows11
+ Keil-C51
+ Visul Studio Code + EIDE

## 使用元器件
+ stc89c52
+ 4位时钟数码管
+ W25Q32
+ AMS1117


## 实现
+ 通过读取RTC获取时间，当RTC时间与设定的闹钟时间一致时启动闹钟，播放自定义音乐;
+ 播放器
    1. 初始化音量为Level 10.(指令为：7e ff 06 06 01 00 10 fe e4 ef)
    2. 播放歌曲.(指令为：7e ff 06 0d 01 00 02 fe eb ef)
+ 时间显示
    1. 4位时钟数码管显示
+ 存储信息
    1. 闹钟时间
    
    