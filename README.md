<!--
 * @Author: error: git config user.email & please set dead value or install git
 * @Date: 2024-08-13 04:54:22
 * @LastEditors: error: git config user.email & please set dead value or install git
 * @LastEditTime: 2024-08-13 05:38:00
 * @FilePath: \MCU_Projeckd:\DevelopProject\YiYiTimerClock\YiYiTimerClockRing\README.md
 * @Description: 
 * 
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
-->
# 亦亦的小闹钟-可自定义铃声

## 编译环境
+ Windows11
+ Keil-arm
+ Visul Studio Code + EIDE

## 使用元器件
+ stm32f103c8t6
+ ...

## 实现原理
### 方案一 （省钱、省电）
+ 通过读取RTC获取时间，当RTC时间与设定的闹钟时间一致时启动闹钟，播放自定义音乐;
+ 设置时间显示方式
    1. 自动刷新(每隔一分钟刷新一次)
    2. 手动刷新(手动按下按钮刷新显示的时间)

### 方案二
+ 通过读取RTC获取时间，当RTC时间与设定的闹钟时间一致时启动闹钟，播放自定义音乐;
+ 设置时间显示方式
    1. 自动刷新(每隔一秒刷新一次)
    2. 开启/关闭显示