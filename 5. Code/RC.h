#ifndef __RC_H__
#define __RC_H__

#include <iostream>
using namespace std;

class Remote
{
public:
    int number;
    char* name;
    char* company;
    char* position;
    int turn_mode;
    int etc1;
    int etc2;
    int time;
    Remote(int, char* nm, char* cp, char* pst, int tr_mode, int a, int b, int tm);

    int on(int, int);
    int off(int, int);
    int up1(int, int);
    int down1(int, int);
    int up2(int, int);
    int down2(int, int);
    int mode(int, int);
    // ~Remote();
};

class TV : public Remote
{
public:
    TV(int number, char* name, char*company, char* position, int turn_mode, int channel_num, int sound_num, int sleep_time)
    : Remote(number, name, company, position, turn_mode, channel_num, sound_num, sleep_time)
    { }
    int channel(int, int, int);
    int sound(int, int, int);
};

class AirCondition : public Remote
{
public:
    AirCondition(int number, char* name, char*company, char* position, int turn_mode, int temperature_num, int wind_strength_num, int sleep_time)
    : Remote(number, name, company, position, turn_mode, temperature_num, wind_strength_num, sleep_time)
    { }
    int temperature(int, int, int);
    int wind_strength(int, int, int);
};

class AirCleaner : public Remote
{
public:
    AirCleaner(int number, char* name, char*company, char* position, int turn_mode, int wind_dir_num, int wind_strength_num, int sleep_time)
    : Remote(number, name, company, position, turn_mode, wind_dir_num, wind_strength_num, sleep_time)
    { }
    int wind_direction(int, int, int);
    int wind_strength(int, int, int);
};

class Lamp : public Remote
{
public:
    Lamp(int number, char* name, char*company, char* position, int turn_mode, int null1, int null2, int sleep_time)
    : Remote(number, name, company, position, turn_mode, null1, null2, sleep_time)
    { }
};


class Clock : public Remote
{
public:
    Clock(int number, char* name, char*company, char* position, int turn_mode, int hour, int minute, int sleep_time)
    : Remote(number, name, company, position, turn_mode, hour, minute, sleep_time)
    { }
    int change_hour(int, int, int);
    int change_minute(int, int, int);
};

#endif