#include <iostream>
#include <cstring>
#include "RC.h"
using namespace std;


// Remote 멤버 함수
Remote::Remote(int num, char* nm, char* cp, char* pst, int tr_mode, int a, int b, int tm)
{
    name = new char[strlen(nm)+1];
    strcpy(name, nm);
    company = new char[strlen(cp)+1];
    strcpy(company, cp);
    position = new char[strlen(pst)+1];
    strcpy(position, pst);
    number = num;
    turn_mode = tr_mode;
    etc1 = a;
    etc2 = b;
    time = tm;
}

int Remote::on(int num, int tr_mode)
{
    tr_mode = 1;
    cout << "#" << num << "번 ON" << endl;
    cout << position << "에 있는 " << company << " " << name << " 켜졌습니다." << endl << endl;
    return tr_mode;
}

int Remote::off(int num, int tr_mode)
{
    tr_mode = 0;
    cout << "#" << num << "번 OFF" << endl;
    cout << position << "에 있는 " << company << " " << name << " 꺼졌습니다." << endl << endl;
    return tr_mode;
}

int Remote::up1(int up_thing, int tr_mode)
{
    if (tr_mode == 1)
    {
        up_thing += 1;
    }
    else
    {
        cout << "꺼져있습니다." << endl << endl;
    }
    return up_thing;
}

int Remote::down1(int down_thing, int tr_mode)
{
    if (tr_mode == 1)
    {
        down_thing -= 1;
    }
    else
    {
        cout << "꺼져있습니다." << endl << endl;
    }
    return down_thing;
}

int Remote::up2(int up_thing, int tr_mode)
{
    if (tr_mode == 1)
    {
        up_thing += 1;
    }
    else
    {
        cout << "꺼져있습니다." << endl << endl;
    }
    return up_thing;
}

int Remote::down2(int down_thing, int tr_mode)
{
    if (tr_mode == 1)
    {
        down_thing -= 1;
    }
    else
    {
        cout << "꺼져있습니다." << endl << endl;
    }
    return down_thing;
}

int Remote::mode(int tr_mode, int tm)
{
    int want_hours = 0;
    int want_mins = 0;
    if (tr_mode == 0)
    {
        cout << "꺼져있습니다." << endl << endl;
    }
    else
    {
        cout << "원하시는 시간을 작성해주십시오.(example. 8시 30분 -> 8): ";
        cin >> want_hours;
        cout << "원하시는 분을 작성해주십시오.(example. 8시 30분 -> 30): ";
        cin >> want_mins;
        tm = want_hours*60 + want_mins;
    }
    return tm;
}


// TV 멤버 함수
int TV::channel(int remote_num, int channel_num, int tr_mode)
{
    if(remote_num == 4)
    {
        channel_num = up1(channel_num, tr_mode);
        if(tr_mode == 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 채널이 +1 올라갑니다." << endl;
            cout << "현재 채널: " << channel_num << endl << endl;
        }
    }
    else
    {
        channel_num = down1(channel_num, tr_mode);
        if(tr_mode == 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 채널이 -1 내려갑니다." << endl;
            cout << "현재 채널: " << channel_num << endl << endl;
        }
    }
    return channel_num;
}

int TV::sound(int remote_num, int sound_num, int tr_mode)
{
    if(remote_num == 6)
    {
        sound_num = up2(sound_num, tr_mode);
        if(tr_mode == 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 음량이 +1 증가합니다." << endl;
            cout << "현재 음량: " << sound_num << endl << endl;
        }
    }
    else
    {
        sound_num = down2(sound_num, tr_mode);
        if(tr_mode == 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 음량이 -1 감소합니다." << endl;
            cout << "현재 음량: " << sound_num << endl << endl;
        }
    }
    return sound_num;
}


// AirCondition 멤버 함수
int AirCondition::temperature(int remote_num, int temperature_num, int tr_mode)
{
    if(remote_num = 4)
    {
        temperature_num = up1(temperature_num, tr_mode);
        if(tr_mode == 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 온도가 +1 올라갑니다." << endl;
            cout << "현재 온도: " << temperature_num << endl << endl;
        }
    }
    else
    {
        temperature_num = down1(temperature_num, tr_mode);
        if(tr_mode == 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 온도가 -1 내려갑니다." << endl;
            cout << "현재 온도: " << temperature_num << endl << endl;
        }
    }
    return temperature_num;
}


int AirCondition::wind_strength(int remote_num, int wind_strength_num, int tr_mode)
{
    if(remote_num = 6)
    {
        wind_strength_num = up2(wind_strength_num, tr_mode);
        if(tr_mode == 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 바람세기가 +1 증가합니다." << endl;
            cout << "현재 바람세기: " << wind_strength_num << endl << endl;
        }
    }
    else
    {
        wind_strength_num = down2(wind_strength_num, tr_mode);
        if(tr_mode == 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 바람세기가 -1 감소합니다." << endl;
            cout << "현재 바람세기: " << wind_strength_num << endl << endl;
        }
    }
    return wind_strength_num;
}


// AirCleaner 멤버 함수
int AirCleaner::wind_direction(int remote_num, int wind_dir_num, int tr_mode)
{
    if(remote_num = 4)
    {
        wind_dir_num = up1(wind_dir_num, tr_mode);
        if(tr_mode == 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 방향이 +1 상승합니다." << endl;
            cout << "현재 바람 방향: " << wind_dir_num << endl << endl;
        }
    }
    else
    {
        wind_dir_num = down1(wind_dir_num, tr_mode);
        if(tr_mode == 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 방향이 -1 하강합니다." << endl;
            cout << "현재 바람 방향: " << wind_dir_num << endl << endl;
        }
    }
    return wind_dir_num;
}

int AirCleaner::wind_strength(int remote_num, int wind_strength_num, int tr_mode)
{
    if(remote_num = 6)
    {
        wind_strength_num = up2(wind_strength_num, tr_mode);
        if(tr_mode == 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 바람세기가 +1 증가합니다." << endl;
            cout << "현재 바람세기: " << wind_strength_num << endl << endl;
        }
    }
    else
    {
        wind_strength_num = down2(wind_strength_num, tr_mode);
        if(tr_mode == 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 바람세기가 -1 감소합니다." << endl;
            cout << "현재 바람세기: " << wind_strength_num << endl << endl;
        }
    }
    return wind_strength_num;
}


// 시계 멤버 함수
int Clock::change_hour(int remote_num, int hour, int tr_mode)
{
    if(remote_num = 4)
    {
        hour = up1(hour, tr_mode);
        if(tr_mode == 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 시간이 +1시간 증가합니다." << endl;
            cout << "현재 시간: " << hour << endl << endl;
        }
    }
    else
    {
        hour = down1(hour, tr_mode);
        if(tr_mode == 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 시간이 -1시간 감소합니다." << endl;
            cout << "현재 시간: " << hour << endl << endl;
        }
    }
    return hour;
}

int Clock::change_minute(int remote_num, int minute, int tr_mode)
{
    if(remote_num == 6)
    {
        minute = up2(minute, tr_mode);
        if(tr_mode = 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 분이 +1분 증가합니다." << endl;
            cout << "현재 분: " << minute << endl << endl;
        }
    }
    else
    {
        minute = down2(minute, tr_mode);
        if(tr_mode = 1)
        {
            cout << number+1 << "번에 " << position << "의 " << company << " " << name << "의 분이 -1분 감소합니다." << endl;
            cout << "현재 분: " << minute << endl << endl;
        }
    }
    return minute;
}