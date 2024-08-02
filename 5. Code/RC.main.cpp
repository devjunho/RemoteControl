#include <iostream>
#include <cstring>
#include "RC.h"
#include "RC.cpp"
using namespace std;
const int MAX = 10;

int remocon(int);
int enrolling(Remote**, int, int);
void onoff(Remote**, int, int);
void updown(Remote**, int, int);
void time_mode(Remote**, int, int);

int main(void)
{
    int choice = 0;
    int keep = 0;           // 선택 값 저장
    int order = 0;          // 리모콘 내의 0~9번까지 저장 순서
    Remote* enroll[MAX] = {0};
    while(1)
    {
        choice = keep = remocon(choice);
        switch(choice)
        {
            case 1: order = enrolling(enroll, choice, order);
                break;
            case 2: onoff(enroll, choice, order);
                break;
            case 3: onoff(enroll, choice, order);
                break;
            case 4: updown(enroll, order, keep);
                break;
            case 5: updown(enroll, order, keep);
                break;
            case 6: updown(enroll, order, keep);
                break;
            case 7: updown(enroll, order, keep);
                break;
            case 8: time_mode(enroll, choice, order);
                break;
        }
    }
    return 0;
}

int remocon(int choice)
{
    cout << "1) 등록" << endl;
    cout << "2) ON              3) OFF" << endl;
    cout << "4) UP1             5) DOWN1" << endl;
    cout << "6) UP2             7) DOWN2" << endl;
    cout << "8) MODE" << endl << ": ";
    cin >> choice;
    return choice;
}

int enrolling(Remote** enroll, int choice, int order)
{
    cout << "등록하려는 가전제품을 선택하십시오: " << endl;
    cout << "1) TV              2) AirCondition" << endl;
    cout << "3) AirCleaner      4) Lamp" << endl;
    cout << "5) Clock" << endl << ": ";
    cin >> choice;
    if(choice == 1)               // TV
    {
        choice = 0;
        cout << "제품의 회사를 선택하십시오: " << endl;
        cout << "1) L사              2) S사" << endl << ": ";
        cin >> choice;
        if (choice == 1)
        {
            enroll[order] = new TV (order, "TV", "L사", "거실", 0, 7, 15, 0);
            cout << order+1 << "번에 " << enroll[order]->position << "의 " << enroll[order]->company << " " << enroll[order]->name << "를 등록하였습니다." << endl;
            order++;
            cout << endl;
        }
        else
        {
            enroll[order] = new TV (order, "TV", "S사", "안방", 0, 11, 8, 0);
            cout << order+1 << "번에 " << enroll[order]->position << "의 " << enroll[order]->company << " " << enroll[order]->name << "를 등록하였습니다." << endl;
            order++;
            cout << endl;
        }
    }
    else if(choice == 2)          // AirCondition
    {
        choice = 0;
        cout << "제품의 회사를 선택하십시오: " << endl;
        cout << "1) L사              2) S사" << endl << ": ";
        cin >> choice;
        if (choice == 1)
        {
            enroll[order] = new AirCondition (order, "AirCondition", "L사", "거실", 0, 27, 1, 0);
            cout << order+1 << "번에 " << enroll[order]->position << "의 " << enroll[order]->company << " " << enroll[order]->name << "를 등록하였습니다." << endl;
            order++;
            cout << endl;
        }
        else
        {
            enroll[order] = new AirCondition (order, "AirCondition", "S사", "안방", 0, 29, 1, 0);
            cout << order+1 << "번에 " << enroll[order]->position << "의 " << enroll[order]->company << " " << enroll[order]->name << "를 등록하였습니다." << endl;
            order++;
            cout << endl;
        }
    }
    else if(choice == 3)          // AirCleaner
    {
        enroll[order] = new AirCleaner (order, "AirCleaner", "L사", "거실", 0, 1, 1, 0);
        cout << order+1 << "번에 " << enroll[order]->position << "의 " << enroll[order]->company << " " << enroll[order]->name << "를 등록하였습니다." << endl;
        order++;
        cout << endl;
    }
    else if(choice == 4)          // Lamp
    {
        choice = 0;
        cout << "전등의 위치를 선택하십시오: " << endl;
        cout << "1) 거실             2) 안방" << endl;
        cout << "3) 현관             4) 화장실" << endl << ": ";
        cin >> choice;
        if (choice == 1)
        {
            enroll[order] = new Lamp (order, "Lamp", "null", "거실", 0, 0, 0, 0);
            cout << order+1 << "번에 " << enroll[order]->position << "의 " << enroll[order]->name << "을 등록하였습니다." << endl;
            order++;
            cout << endl;
        }
        else
        {
            enroll[order] = new Lamp (order, "Lamp", "null", "거실", 0, 0, 0, 0);
            cout << order+1 << "번에 " << enroll[order]->position << "의 " << enroll[order]->name << "을 등록하였습니다." << endl;
            order++;
            cout << endl;
        }
    }
    else                        // 시계
    {
        choice = 0;
        cout << "전등의 위치를 선택하십시오: " << endl;
        cout << "1) 거실             2) 안방" << endl << ": ";
        cin >> choice;
        if (choice == 1)
        {
            enroll[order] = new Clock (order, "Clock", "null", "거실", 0, 12, 30, 0);
            cout << order+1 << "번에 " << enroll[order]->position << "의 " << enroll[order]->name << "를 등록하였습니다." << endl;
            order++;
            cout << endl;
        }
        else
        {
            enroll[order] = new Clock (order, "Clock", "null", "안방", 0, 12, 30, 0);
            cout << order+1 << "번에 " << enroll[order]->position << "의 " << enroll[order]->name << "를 등록하였습니다." << endl;
            order++;
            cout << endl;
        }
    }
    return order;
}

void onoff(Remote** enroll, int choice, int order)
{
    if(order == 0)
    {
        cout << "등록된 제품이 없습니다." << endl;
    }
    else
    {
        for(int i=0; i<order; i++)
        {
            if(enroll[i]->turn_mode == 1)
            {
                cout << i+1 << ") " << enroll[i]->position << "에 있는 " << enroll[i]->company << " " << enroll[i]->name << " : " << "켜져있습니다" << endl;
            }
            else
            {
                cout << i+1 << ") " << enroll[i]->position << "에 있는 " << enroll[i]->company << " " << enroll[i]->name << " : " << "꺼져있습니다" << endl;
            }
        }
        if(choice == 2)
        {
            cout << "동일한 회사 제품들을 일괄 on 하시겠습니까?" << endl;
            cout << "YES: 7             NO: 4       : ";
            cin >> choice;
            if(choice == 7)
            {
                cout << "1) L사             2) S사" << endl;
                cout << ": ";
                cin >> choice;
                if(choice == 1)             // L사 일괄 on
                {
                    for(int i=0; i<order; i++)
                    {
                        if(strcmp(enroll[i]->company,"L사") == 0)
                        {
                            enroll[i]->turn_mode = 1;
                            cout << i+1 << ") " << enroll[i]->position << "에 있는 " << enroll[i]->company << " " << enroll[i]->name << " : " << "켜졌습니다." << endl;
                        }
                    }
                }
                else                        // S사 일괄 off
                {
                    for(int i=0; i<order; i++)
                    {
                        if(strcmp(enroll[i]->company,"S사") == 0)
                        {
                            enroll[i]->turn_mode = 1;
                            cout << i+1 << ") " << enroll[i]->position << "에 있는 " << enroll[i]->company << " " << enroll[i]->name << " : " << "켜졌습니다." << endl;
                        }
                    }
                }
            }
            else
            {
                cout << "어떤 제품을 켜시겠습니까? ";
                cin >> choice;
                enroll[choice-1]->turn_mode = enroll[choice-1]->Remote::on(choice, enroll[choice-1]->turn_mode);
            }
        }
        else
        {
            cout << "동일한 회사 제품들을 일괄 off 하시겠습니까?" << endl;
            cout << "YES: 7             NO: 4       : ";
            cin >> choice;
            if(choice == 7)
            {
                cout << "1) L사             2) S사" << endl;
                cout << ": ";
                cin >> choice;
                if(choice == 1)             // L사 일괄 off
                {
                    for(int i=0; i<order; i++)
                    {
                        if(strcmp(enroll[i]->company,"L사") == 0)
                        {
                            enroll[i]->turn_mode = 0;
                            cout << i+1 << ") " << enroll[i]->position << "에 있는 " << enroll[i]->company << " " << enroll[i]->name << " : " << "꺼졌습니다." << endl;
                        }
                    }
                }
                else
                {
                    for(int i=0; i<order; i++)
                    {
                        if(strcmp(enroll[i]->company,"S사") == 0)
                        {
                            enroll[i]->turn_mode = 0;
                            cout << i+1 << ") " << enroll[i]->position << "에 있는 " << enroll[i]->company << " " << enroll[i]->name << " : " << "꺼졌습니다." << endl;
                        }
                    }
                }
            }
            else
            {
                cout << "어떤 제품을 끄시겠습니까? ";
                cin >> choice;
                enroll[choice-1]->turn_mode = enroll[choice-1]->Remote::off(choice, enroll[choice-1]->turn_mode);
            }
        }
    }
}

void updown(Remote** enroll, int order, int keep)
{
    int choice;
    if(order == 0)              // 아무 것도 저장되있지 않았을 경우
    {
        cout << "등록된 제품이 없습니다." << endl;
    }
    else
    {
        for(int i=0; i<order; i++)
        {
            cout << i+1 << ") " << enroll[i]->position << "에 있는 " << enroll[i]->company << " " << enroll[i]->name << endl;
        }
        cout << "어떤 제품을 선택하시겠습니까? ";
        cin >> choice;
        if(keep == 4 || keep == 5)
        {
            if(strcmp(enroll[choice-1]->name, "TV") == 0)
            {
                TV tv(enroll[choice-1]->number, enroll[choice-1]->name, enroll[choice-1]->company, enroll[choice-1]->position, enroll[choice-1]->turn_mode, enroll[choice-1]->etc1, enroll[choice-1]->etc2, enroll[choice-1]->time);
                enroll[choice-1]->etc1 = tv.channel(keep, enroll[choice-1]->etc1, enroll[choice-1]->turn_mode);
            }
            else if(strcmp(enroll[choice-1]->name, "AirCondition") == 0)
            {
                AirCondition aircon(enroll[choice-1]->number, enroll[choice-1]->name, enroll[choice-1]->company, enroll[choice-1]->position, enroll[choice-1]->turn_mode, enroll[choice-1]->etc1, enroll[choice-1]->etc2, enroll[choice-1]->time);
                enroll[choice-1]->etc1 = aircon.temperature(keep, enroll[choice-1]->etc1, enroll[choice-1]->turn_mode);
            }
            else if(strcmp(enroll[choice-1]->name, "AirCleaner") == 0)
            {
                AirCleaner airclean(enroll[choice-1]->number, enroll[choice-1]->name, enroll[choice-1]->company, enroll[choice-1]->position, enroll[choice-1]->turn_mode, enroll[choice-1]->etc1, enroll[choice-1]->etc2, enroll[choice-1]->time);
                enroll[choice-1]->etc1 = airclean.wind_direction(keep, enroll[choice-1]->etc1, enroll[choice-1]->turn_mode);
            }
            else if(strcmp(enroll[choice-1]->name, "Clock") == 0)
            {
                Clock cl(enroll[choice-1]->number, enroll[choice-1]->name, enroll[choice-1]->company, enroll[choice-1]->position, enroll[choice-1]->turn_mode, enroll[choice-1]->etc1, enroll[choice-1]->etc2, enroll[choice-1]->time);
                enroll[choice-1]->etc1 = cl.change_hour(keep, enroll[choice-1]->etc1, enroll[choice-1]->turn_mode);
            }
            else
            {
                cout << "해당 기능이 없습니다." << endl;
            }
        }
        else
        {
            if(strcmp(enroll[choice-1]->name, "TV") == 0)
            {
                TV tv(enroll[choice-1]->number, enroll[choice-1]->name, enroll[choice-1]->company, enroll[choice-1]->position, enroll[choice-1]->turn_mode, enroll[choice-1]->etc1, enroll[choice-1]->etc2, enroll[choice-1]->time);
                enroll[choice-1]->etc1 = tv.sound(keep, enroll[choice-1]->etc1, enroll[choice-1]->turn_mode);
            }
            else if(strcmp(enroll[choice-1]->name, "AirCondition") == 0)
            {
                AirCondition aircon(enroll[choice-1]->number, enroll[choice-1]->name, enroll[choice-1]->company, enroll[choice-1]->position, enroll[choice-1]->turn_mode, enroll[choice-1]->etc1, enroll[choice-1]->etc2, enroll[choice-1]->time);
                enroll[choice-1]->etc1 = aircon.wind_strength(keep, enroll[choice-1]->etc1, enroll[choice-1]->turn_mode);
            }
            else if(strcmp(enroll[choice-1]->name, "AirCleaner") == 0)
            {
                AirCleaner airclean(enroll[choice-1]->number, enroll[choice-1]->name, enroll[choice-1]->company, enroll[choice-1]->position, enroll[choice-1]->turn_mode, enroll[choice-1]->etc1, enroll[choice-1]->etc2, enroll[choice-1]->time);
                enroll[choice-1]->etc1 = airclean.wind_strength(keep, enroll[choice-1]->etc1, enroll[choice-1]->turn_mode);
            }
            else if(strcmp(enroll[choice-1]->name, "Clock") == 0)
            {
                Clock cl(enroll[choice-1]->number, enroll[choice-1]->name, enroll[choice-1]->company, enroll[choice-1]->position, enroll[choice-1]->turn_mode, enroll[choice-1]->etc1, enroll[choice-1]->etc2, enroll[choice-1]->time);
                enroll[choice-1]->etc1 = cl.change_minute(keep, enroll[choice-1]->etc1, enroll[choice-1]->turn_mode);
            }
            else
            {
                cout << "해당 기능이 없습니다." << endl;
            }
        }
    }
}

void time_mode(Remote** enroll, int choice, int order)
{
    int hours;
    int mins;
    if(order == 0)
    {
        cout << "등록된 제품이 없습니다." << endl;
    }
    else
    {
        for(int i=0; i<order; i++)
        {
            if(enroll[i]->turn_mode == 1)
            {
                cout << i+1 << ") " << enroll[i]->position << "에 있는 " << enroll[i]->company << " " << enroll[i]->name << " : " << "켜져있습니다" << endl;
            }
            else
            {
                cout << i+1 << ") " << enroll[i]->position << "에 있는 " << enroll[i]->company << " " << enroll[i]->name << " : " << "꺼져있습니다" << endl;
            }
        }
        cout << "어떤 제품을 선택하시겠습니까? ";
        cin >> choice;
        cout << enroll[choice-1]->name;
        if(strcmp(enroll[choice-1]->name, "LAMP"))
        {
            cout << "시간 기능이 없습니다." << endl << endl;
        }
        else
        {
            enroll[choice-1]->time = enroll[choice-1]->Remote::mode(enroll[choice-1]->turn_mode, enroll[choice-1]->time);
            hours = enroll[choice-1]->time / 60;
            mins = enroll[choice-1]->time % 60;
            cout << hours << "시 " << mins << "분으로 시간 예약되셨습니다." << endl << endl;
        }
    }
}