#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include <climits>
#include <cctype>
#include <cstdlib>
using namespace std;
enum All {Aircon_geosil=0,Aircon_anbang=1,TV_geosil=2,TV_anbang=3,Refresher=4,
        Light_geosil=5,Light_anbang=6,Light_bath=7,Watch_geosil=8,Watch_anbang=9};
enum Run{off,low,mid,high};

int name [10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

class Appliances{
    bool geosil_air_oper = 0;
    int geosil_air_temp = 0;
    int geosil_air_power = 0;
    int geosil_air_sleep = 0;

    bool anbang_air_oper = 0;
    int anbang_air_temp = 0;
    int anbang_air_power = 0;
    int anbang_air_sleep = 0;

    bool geosil_tv_oper = 0;
    int geosil_tv_channel = 0;
    int geosil_tv_volume = 0;
    int geosil_tv_sleep = 0;

    bool anbang_tv_oper = 0;
    int anbang_tv_channel = 0;
    int anbang_tv_volume = 0;
    int anbang_tv_sleep = 0;

    bool ref_oper = 0;
    int ref_wind_locate = 0;
    int ref_wind_power = 0;
    int ref_wind_sleep = 0;
public:
    void on(int num){
        if(name[num] == Aircon_geosil){
            cout<<"H사 거실 에어컨 ON."<<endl;
            geosil_air_oper = true;
            geosil_air_temp = 24;
            geosil_air_power = low;
        }
        else if(name[num] == Aircon_anbang){
            cout<<"M사 안방 에어컨 ON."<<endl;
            anbang_air_oper = true;
            anbang_air_temp = 24;
            anbang_air_power = low;
        }
        else if(name[num] == TV_geosil){
            cout<<"H사 거실 티비 ON."<<endl;
            geosil_tv_oper = true;
            geosil_tv_channel = 1;
        }
        else if(name[num] == TV_anbang){
            cout<<"M사 안방 티비 ON."<<endl;
            anbang_tv_oper = true;
            anbang_tv_channel = 1;
        }
        else if(name[num] == Refresher){
            cout<<"H사 공기청정기 ON."<<endl;
            ref_oper = true;
            ref_wind_power = low;
            ref_wind_locate = low;
        } 
    }
    void on(char company){
        if(company =='h' || company =='H'){
            cout<<"H사 거실 에어컨 ON."<<endl;
            geosil_air_oper = true;
            geosil_air_temp = 24;
            geosil_air_power = low;

            cout<<"H사 거실 티비 ON."<<endl;
            geosil_tv_oper = true;
            geosil_tv_channel = 1;

            cout<<"H사 공기청정기 ON."<<endl;
            ref_oper = true;
            ref_wind_power = low;
            ref_wind_locate = low;
        }
        else if (company =='m' || company =='M'){
            cout<<"M사 안방 에어컨 ON."<<endl;
            anbang_air_oper = true;
            anbang_air_temp = 24;
            anbang_air_power = low;
            
            cout<<"M사 안방 티비 ON."<<endl;
            anbang_tv_oper = true;
            anbang_tv_channel = 1;
        }
        else cout<<"잘못된 회사명을 입력하셨습니다."<<endl;
    }
    void off(int num){
        if(name[num] == Aircon_geosil){
            cout<<"H사 거실 에어컨 off."<<endl;
            geosil_air_oper = false;
            geosil_air_temp = 24;
        }
        else if(name[num] == Aircon_anbang){
            cout<<"M사 안방 에어컨 off."<<endl;
            anbang_air_oper = false;
            anbang_air_temp = Run::off;
        }
        else if(name[num] == TV_geosil){
            cout<<"H사 거실 티비 off."<<endl;
            geosil_tv_oper = false;
            geosil_tv_channel = Run::off;
        }
        else if(name[num] == TV_anbang){
            cout<<"M사 안방 티비 off."<<endl;
            anbang_tv_oper = false;
            anbang_tv_channel = Run::off;
        }
        else if(name[num] == Refresher){
            cout<<"H사 공기청정기 off."<<endl;
            ref_oper = false;
            ref_wind_power = Run::off;
            ref_wind_locate = Run::off;
        }
    }
    void off(char company){
        if(company =='h' || company =='H'){
            cout<<"H사 거실 에어컨 off."<<endl;
            geosil_air_oper = false;
            geosil_air_temp = Run::off;
            geosil_air_power = Run::off;

            cout<<"H사 거실 티비 off."<<endl;
            geosil_tv_oper = false;
            geosil_tv_channel = Run::off;

            cout<<"H사 공기청정기 off."<<endl;
            ref_oper = false;
            ref_wind_power = Run::off;
            ref_wind_locate = Run::off;
        }
        else if (company =='m' || company =='M'){
            cout<<"M사 안방 에어컨 off."<<endl;
            anbang_air_oper = false;
            anbang_air_temp = Run::off;
            
            cout<<"M사 안방 티비 off."<<endl;
            anbang_tv_oper = false;
            anbang_tv_channel = Run::off;
        }
        else cout<<"잘못된 회사명을 입력하셨습니다."<<endl;
    }
    void up1(int num){
        
        switch (name[num])
        {
            case Aircon_geosil:
                if(geosil_air_oper == true)
                    if(geosil_air_temp>=28){
                        geosil_air_temp= 28;
                        cout<<"최고온도입니다.(거실 에어컨) 현재온도 : "<<geosil_air_temp<<endl;
                    }
                    else{
                        geosil_air_temp++;
                        cout<<"온도가 올라갑니다.(거실 에어컨) 현재온도 : "<<geosil_air_temp<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(거실 에어컨)"<<endl;
                break;

            case Aircon_anbang:
                if(anbang_air_oper == true)
                    if(anbang_air_temp>=28){
                        anbang_air_temp= 28;
                        cout<<"최고온도입니다.(안방 에어컨) 현재온도 : "<<anbang_air_temp<<endl;
                    }
                    else{
                        anbang_air_temp++;
                        cout<<"온도가 올라갑니다.(안방 에어컨) 현재온도 : "<<anbang_air_temp<<endl;                    
                    }
                else cout<<"전원이 꺼져있습니다.(안방 에어컨)"<<endl;
                break;

            case TV_geosil:
                if(geosil_tv_oper ==true)
                    if(geosil_tv_volume>=50){
                        geosil_tv_volume =50;
                        cout<<"최고 볼륨입니다.(거실 티비) vol : "<<geosil_tv_volume<<endl;
                    }
                    else{
                        geosil_tv_volume++;
                        cout<<"볼륨을 올립니다.(거실 티비) vol : "<<geosil_tv_volume<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(거실 티비)"<<endl;
                break;

            case TV_anbang:
                if(anbang_tv_oper ==true)
                    if(anbang_tv_volume>=50){
                        anbang_tv_volume =50;
                        cout<<"최고 볼륨입니다.(안방 티비) vol : "<<anbang_tv_volume<<endl;
                    }
                    else{
                        anbang_tv_volume++;
                        cout<<"볼륨을 올립니다.(안방 티비) vol : "<<anbang_tv_volume<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(안방 티비)"<<endl;
                break; 

            case Refresher:
                if(ref_oper ==true)
                    if(ref_wind_locate>=high){
                        ref_wind_locate = high;
                        cout<<"최고 풍향입니다.(공기청정기)"<<endl; 
                    }
                    else{ref_wind_locate++; cout<<"풍향을 올립니다.(공기청정기)"<<endl;}
                else cout<<"전원이 꺼져있습니다.(공기청정기)"<<endl;
                break;

            default:
                cout<<"등록된 제품이 없습니다."<<endl;
                
        }
        
    }
    void Down1(int num){
        switch (name[num])
        {
            case Aircon_geosil:
                if(geosil_air_oper == true)
                    if(geosil_air_temp<=16){
                        geosil_air_temp = 16;
                        cout<<"최저온도입니다.(거실 에어컨) 현재온도 : "<<geosil_air_temp<<endl;
                    }
                    else{
                        geosil_air_temp++;
                        cout<<"온도가 올라갑니다.(거실 에어컨) 현재온도 : "<<geosil_air_temp<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(거실 에어컨)"<<endl;
                break;

            case Aircon_anbang:
                if(anbang_air_oper == true)
                    if(anbang_air_temp<=16){
                        anbang_air_temp = 16;
                        cout<<"최저온도입니다.(안방 에어컨) 현재온도 : "<<anbang_air_temp<<endl;
                    }
                    else{
                        anbang_air_temp++;
                        cout<<"온도가 올라갑니다.(안방 에어컨) 현재온도 : "<<anbang_air_temp<<endl;
                    }                    
                else cout<<"전원이 꺼져있습니다.(안방 에어컨) : "<<endl;
                break;

            case TV_geosil:
                if(geosil_tv_oper ==true)
                    if(geosil_tv_volume<=0){
                        geosil_tv_volume = 0;
                        cout<<"최저 볼륨입니다.(거실 티비) vol : "<<geosil_tv_volume<<endl;
                    }
                    else{
                        geosil_tv_volume--;
                        cout<<"볼륨을 내립니다.(거실 티비) vol : "<<geosil_tv_volume<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(거실 티비)"<<endl;
                break;

            case TV_anbang:
                if(geosil_tv_oper ==true)
                    if(anbang_tv_volume<=0){
                        anbang_tv_volume =0;
                        cout<<"최저 볼륨입니다.(안방 티비) vol : "<<anbang_tv_volume<<endl;
                    }
                    else{
                        anbang_tv_volume--;
                        cout<<"볼륨을 내립니다.(안방 티비) vol : "<<anbang_tv_volume<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(안방 티비)"<<endl;
                break; 

            case Refresher:
                if(ref_oper ==true)
                    if(ref_wind_locate<=low){
                        ref_wind_locate = low;
                        cout<<"최저 풍향입니다.(공기청정기)"<<endl; 
                    }
                    else{ref_wind_locate--; cout<<"풍향을 내립니다.(공기청정기)"<<endl;}
                else cout<<"전원이 꺼져있습니다.(공기청정기)"<<endl;
                break;        

            default:
                cout<<"등록된 제품이 없습니다."<<endl;
        }
        
    }
    void up2(int num){
        switch (name[num])
        {
            case Aircon_geosil:
                if(geosil_air_oper == true)
                    if(geosil_air_power >= high){
                        geosil_air_power = high;
                        cout<<"최고 풍량입니다.(거실 에어컨)";
                    }
                    else{
                        geosil_air_power++;
                        cout<<"풍량가 올라갑니다.(거실 에어컨) 현재풍량 : "<<geosil_air_power<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(거실 에어컨)"<<endl;
                break;

            case Aircon_anbang:
                if(anbang_air_oper == true)
                    if(anbang_air_power >= high){
                        anbang_air_power= high;
                        cout<<"최고 풍량입니다.(안방 에어컨)";
                    }
                    else{
                        anbang_air_power++;
                        cout<<"풍량이 올라갑니다.(안방 에어컨) 현재풍량 : "<<anbang_air_power<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(안방 에어컨)"<<endl;
                break;

            case TV_geosil:
                if(geosil_tv_oper ==true)
                    if(geosil_tv_channel>=500){
                        geosil_tv_channel =1;
                    }
                    else{
                        geosil_tv_channel++;
                        cout<<"채널을 올립니다 (거실 티비) 현재 채널 : "<<geosil_tv_channel<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(거실 티비)"<<endl;
                break;

            case TV_anbang:
                if( anbang_tv_oper ==true)
                    if(anbang_tv_channel>=500){
                        anbang_tv_channel =1;
                    }
                    else{
                        anbang_tv_channel++;
                        cout<<"채널을 올립니다 (안방 티비) 현재 채널 : "<<anbang_tv_channel<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(안방 티비)"<<endl;
                break; 

            case Refresher:
                if(ref_oper ==true)
                    if(ref_wind_locate>=high){
                        ref_wind_locate= high;
                        cout<<"최고 강도입니다.(공기청정기)";
                    }
                    else{
                        ref_wind_locate++;
                        cout<<"강도를 올립니다.(공기청정기) 현재강도 : "<<ref_wind_locate<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(공기청정기)"<<endl;
                break;                

            default:
                cout<<"등록된 제품이 없습니다."<<endl;
        }
    }
    void Down2(int num){

        switch (name[num])
        {
            case Aircon_geosil:
                if(geosil_air_oper == true)
                    if(geosil_air_power<=low){
                        geosil_air_power = low;
                        cout<<"최저 풍량입니다.(거실 에어컨)";
                    }
                    else{
                        geosil_air_power--;
                        cout<<"풍량이 올라갑니다.(거실 에어컨) 현재풍량 : "<<geosil_air_power<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(거실 에어컨)"<<endl;
                break;

            case Aircon_anbang:
                if(anbang_air_oper == true)
                    if(anbang_air_power<=low){
                        anbang_air_power= low;
                        cout<<"최고 풍량입니다.(안방 에어컨)";
                    }
                    else{
                        anbang_air_power--;
                        cout<<"풍량이 올라갑니다.(안방 에어컨) 현재풍량 : "<<anbang_air_power<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(거실 에어컨)"<<endl;
                break;

            case TV_geosil:
                if(geosil_tv_oper ==true)
                    if(geosil_tv_channel<1){
                        geosil_tv_channel = 500;
                    }
                    else{
                        geosil_tv_channel--;
                        cout<<"채널을 내립니다 (거실 티비) 현재 채널 : "<<geosil_tv_channel<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(거실 티비)"<<endl;
                break;

            case TV_anbang:
                if(anbang_tv_oper ==true)
                    if(anbang_tv_channel<1){
                        anbang_tv_channel = 500;
                    }
                    else{
                        anbang_tv_channel--;
                        cout<<"채널을 내립니다 (안방 티비) 현재 채널 : "<<anbang_tv_channel<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(안방 티비)"<<endl;
                break; 

            case Refresher:
                if(ref_oper ==true)
                    if(ref_wind_locate<=low){
                        ref_wind_locate= low;
                        cout<<"최저 강도입니다.(공기청정기)";
                    }
                    else{
                        ref_wind_locate--;
                        cout<<"강도를 내립니다.(공기청정기) 현재강도 : "<<ref_wind_locate<<endl;
                    }
                else cout<<"전원이 꺼져있습니다.(공기청정기)"<<endl;
                break;                
        
            default:
                cout<<"등록된 제품이 없습니다."<<endl;
        }
    }
    void mode(int num){
        switch (name[num])
        {
            case Aircon_geosil:
                if(geosil_air_oper == true){
                    cout<<"취침시간을 시간단위로 입력하세요. (거실 에어컨)" <<endl;
                    cin>>geosil_air_sleep;
                    cin.ignore();
                    cout<<"설정 완료. (거실 에어컨) 취침시간 : "<<geosil_air_sleep<<"시간 뒤."<<endl;
                }
                else cout<<"전원이 꺼져있습니다.(거실 에어컨)"<<endl;
                break;

            case Aircon_anbang:
                    if(anbang_air_oper == true){
                    cout<<"취침시간을 시간단위로 입력하세요. (안방 에어컨)" <<endl;
                    cin>>anbang_air_sleep;
                    cin.ignore();
                    cout<<"설정 완료. (안방 에어컨) 취침시간 : "<<anbang_air_sleep<<"시간 뒤."<<endl;
                }
                else cout<<"전원이 꺼져있습니다.(안방 에어컨)"<<endl;
                break;

            case TV_geosil:
                if(geosil_tv_oper == true){
                    cout<<"취침시간을 시간단위로 입력하세요. (거실 티비)" <<endl;
                    cin>>geosil_air_sleep;
                    cin.ignore();
                    cout<<"설정 완료. (거실 티비) 취침시간 : "<<geosil_air_sleep<<"시간 뒤."<<endl;
                }
                else cout<<"전원이 꺼져있습니다.(거실 티비)"<<endl;
                break;

            case TV_anbang:
                if(anbang_tv_oper ==true){
                    cout<<"취침시간을 시간단위로 입력하세요. (안방 티비)" <<endl;
                    cin>>anbang_tv_oper;
                    cin.ignore();
                    cout<<"설정 완료. (안방 티비) 취침시간 : "<<anbang_tv_oper<<"시간 뒤."<<endl;
                }
                else cout<<"전원이 꺼져있습니다.(안방 티비)"<<endl;
                break;

            case Refresher:
                if(ref_oper == true){
                    cout<<"취침시간을 시간단위로 입력하세요. (공기청정기)" <<endl;
                    cin>>ref_wind_sleep;
                    cin.ignore();
                    cout<<"설정 완료. (공기청정기) 취침시간 : "<<ref_wind_sleep<<"시간 뒤."<<endl;
                }
                else cout<<"전원이 꺼져있습니다.(공기청정기)"<<endl;
                break;               
        
            default:
                cout<<"등록된 제품이 없습니다."<<endl;
        }
    }
};
class Light{

    bool geosil_light_oper = false;
    bool anbang_light_oper = false;
    bool bath_light_oper = false;

public:
    void on(int num){
        if(name[num] == Light_geosil){
            cout<<"H사 거실 전등 ON."<<endl;
            geosil_light_oper = true;
        }
        else if(name[num] ==Light_anbang){
            cout<<"M사 안방 전등 ON."<<endl;
            anbang_light_oper = true;
        }
        else if(name[num] == Light_bath){
            cout<<"H사 욕실 전등 ON."<<endl;
            anbang_light_oper = true;
        }
    }
    void on(char company){
        if(company =='h' || company =='H'){
            cout<<"H사 거실 전등 ON."<<endl;
            geosil_light_oper = true;
            cout<<"H사 욕실 전등 ON."<<endl;
            bath_light_oper = true;
        }
        else if(company =='M' || company =='m'){
            cout<<"m사 안방 전등 ON."<<endl;
            anbang_light_oper = true;        
        }        
    } 
    void off(int num){
        if(name[num] == Light_geosil){
            cout<<"H사 거실 전등 OFF."<<endl;
            geosil_light_oper = false;
        }
        else if(name[num] ==Light_anbang){
            cout<<"M사 안방 전등 OFF."<<endl;
            anbang_light_oper = false;
        }
        else if(name[num] == Light_bath){
            cout<<"H사 욕실 전등 OFF."<<endl;
            bath_light_oper = false;
        }
    }
    void off(char company){
        if(company =='h' || company =='H'){
            cout<<"H사 거실 전등 off."<<endl;
            geosil_light_oper = false;
            cout<<"H사 욕실 전등 off."<<endl;
            bath_light_oper = false;
        }
        else if(company =='M' || company =='m'){
            cout<<"m사 안방 전등 off."<<endl;
            anbang_light_oper = false;        
        }        
    }
};
class Watch{

    bool geosil_watch_oper = false;
    int geosil_watch_hour=10;
    int geosil_watch_min =11;
    int geosil_watch_alarm_hour=0;
    int geosil_watch_alarm_min=0;

    bool anbang_watch_oper = false;
    int anbang_watch_hour=20;
    int anbang_watch_min =21;
    int anbang_watch_alarm_hour=0;
    int anbang_watch_alarm_min=0;

public:
    void on(int num){
        if(name[num] == Watch_geosil){
            cout<<"H사 거실 시계 ON."<<endl;
            geosil_watch_oper = true;
        }
        else if(name[num] ==Watch_anbang){
            cout<<"M사 안방 시계 ON."<<endl;
            anbang_watch_oper = true;
        }
    }
    void on(char company){
        if(company =='h' || company =='H'){
            cout<<"H사 거실 시계 ON."<<endl;
            geosil_watch_oper = true;

        }
        else if(company =='M' || company =='m'){
            cout<<"M사 안방 시계 ON."<<endl;
            anbang_watch_oper = true;      
        }        
    } 
    void off(int num){
        if(name[num] == Watch_geosil){
            cout<<"H사 거실 시계 OFF."<<endl;
            geosil_watch_oper = false;
        }
        else if(name[num] ==Watch_anbang){
            cout<<"M사 안방 시계 OFF."<<endl;
            anbang_watch_oper = false;
        }

    }
    void off(char company){
        if(company =='h' || company =='H'){
            cout<<"H사 거실 시계 OFF."<<endl;
            geosil_watch_oper = false;

        }
        else if(company =='M' || company =='m'){
            cout<<"M사 안방 시계 OFF."<<endl;
            anbang_watch_oper = false;      
        }        
    } 
    void up1(int num){
        if(name[num] == Watch_geosil){
            if(geosil_watch_oper == true){
                cout<<"변경할 시각을 입력하세요 (거실 시계) : "<<endl;
                cin>>geosil_watch_hour;
                cin.ignore();
                cout<<"시각 변경이 완료되었습니다. (거실 시계) 현재 시각 = "
                    <<geosil_watch_hour<<" : "<<geosil_watch_min<<endl;
            }
            else cout<<"전원이 꺼져있습니다.(거실 시계)"<<endl;
        }
        else if (name[num] == Watch_anbang){
            if(anbang_watch_oper == true){
                cout<<"변경할 시각을 입력하세요 (안방 시계) : "<<endl;
                cin>>anbang_watch_hour;
                cin.ignore();
                cout<<"시각 변경이 완료되었습니다.(안방 시계) 현재 시각 = "
                    <<anbang_watch_hour<<" : "<<anbang_watch_min<<endl;
            }
            else cout<<"전원이 꺼져있습니다.(안방 시계)"<<endl;
        }
        else cout<<"등록된 제품이 없습니다."<<endl;
    }
    void Down1(int num){
        if(name[num] == Watch_geosil){
            if(geosil_watch_oper == true){
                cout<<"변경할 분을 입력하세요 (거실 시계) : "<<endl;
                cin>>geosil_watch_min;
                cin.ignore();
                cout<<"분 변경이 완료되었습니다. (거실 시계) 현재 시각 = "
                    <<geosil_watch_hour<<" : "<<geosil_watch_min<<endl;
            }
            else cout<<"전원이 꺼져있습니다.(거실 시계)"<<endl;
        }
        else if (name[num] == Watch_anbang){
            if(anbang_watch_oper == true){
                cout<<"변경할 분을 입력하세요 (안방 시계) : "<<endl;
                cin>>anbang_watch_min;
                cin.ignore();
                cout<<"분 변경이 완료되었습니다.(안방 시계) 현재 시각 = "
                    <<anbang_watch_hour<<" : "<<anbang_watch_min<<endl;
            }
            else cout<<"전원이 꺼져있습니다.(안방 시계)"<<endl;
        }       
        else cout<<"등록된 제품이 없습니다."<<endl;
    }
    void mode(int num){
        if(name[num] == Watch_geosil){
            if(geosil_watch_oper == true){
                cout<<"알람설정할 시간을 입력하세요 (거실 시계) : "<<endl;
                cout<<" 시각 : "<<endl; 
                cin>>geosil_watch_alarm_hour;
                cin.ignore();
                cout<<" 분 : "<<endl; 
                cin>>geosil_watch_alarm_min;
                cin.ignore();
                cout<<"알람설정 완료되었습니다. (거실 시계) "
                    <<geosil_watch_alarm_hour<<" : "<<geosil_watch_alarm_min<<endl;
            }
            else cout<<"전원이 꺼져있습니다.(거실 시계)"<<endl;
        }
        else if (name[num] == Watch_anbang){
            if(anbang_watch_oper == true){
                cout<<"알람설정할 시간을 입력하세요 (안방 시계) : "<<endl;
                cout<<" 시각 : "<<endl; 
                cin>>anbang_watch_alarm_hour;
                cin.ignore();
                cout<<" 분 : "<<endl; 
                cin>>geosil_watch_alarm_min;
                cin.ignore();
                cout<<"알람설정 완료되었습니다. (안방 시계) "
                    <<anbang_watch_alarm_hour<<" : "<<geosil_watch_alarm_min<<endl;
            }
            else cout<<"전원이 꺼져있습니다.(안방 시계)"<<endl;
        }      
        else cout<<"등록된 제품이 없습니다."<<endl;
    }

};
class Remote : public Appliances, public Light, public Watch{
    int enroll_count = 0;   //등록횟수
    int enroll_num = 0;     //등록번호
public:
    void Register(){
        int num = 0;
        if(enroll_count >10){
            cout<<"등록 가능한 공간이 없습니다."<<endl;
            enroll_count=10;
        }
        else{
            for(int i = 0; i<=9 ; i++){
                int flag = 0;
                // system("clear");
                cout<<endl<<"\t\t등록 창"<<endl;
                cout<<endl<<"0)거실 에어컨\t\t 1)안방 에어컨\n2)거실 티비\t\t 3)안방 티비\n4)공기청정기\t\t 5)거실 전등\n6)안방 전등\t\t 7)욕실 전등\n8)거실 시계\t\t 9)안방 시계"<<endl<<endl;
                cout<<i<<"번째로 등록할 제품번호을 입력하세요. : ";
                cin>>enroll_num;
                cin.ignore();
                for(int j = 0 ; j<=enroll_count ; j++){
                    if(name[j] == enroll_num)
                        flag =1;
                }

                if(!cin){
                    cout<<"잘못된 번호입니다."<<endl;
                    i--;
                }
                else if(flag == 1){
                    cout<<"이미 등록된 번호입니다. 다시선택해주세요."<<endl;
                    i--;
                }
                else{
                    num = enroll_num;
                    string prod[10];
                    name[enroll_count] = num;
                    cout<<endl;
                    cout<<endl;
                    prod[0] ="H사 거실 에어컨";  prod[1] = "M사 안방 에어컨"; prod[2] = "H사 거실 티비";    //0,2,4,5,7,8 = H
                    prod[3] ="M사 안방 티비"  ;  prod[4] = "H사 공기청정기" ; prod[5] = "H사 거실 전등";    //1,3,5,6,9 = M
                    prod[6] ="M사 안방 전등"  ;  prod[7] = "H사 욕실 전등"  ; prod[8] = "H사 거실 시계";
                    prod[9] ="M사 안방 시계";
                    cout<<enroll_count<<"번에 "<<prod[num]<<"(이)가 등록되었습니다."<<endl;
                    enroll_count++;
                }
            }
        }
    }
    void Remove(){
        enroll_count = 0;
        for(int i = 0; i <=9 ; i++)
            name [i] = -1;
        cout<<"모든 제품을 등록해제 하였습니다."<<endl;
    }
    void on(){
        for(int i = 0; i<=9 ; i++){
            Appliances::on(i);
            Light::on(i);
            Watch::on(i);
        }
    }
    void on_company(){
        char company;
        cout<<"전원을 킬 회사명을 입력하세요.(H, M)"<<endl;
        cin>>company;
        cin.ignore();
        Appliances::on(company);
        Watch::on(company);
        Light::on(company);
    }
    void off(){
        for(int i = 0; i<=10 ; i++){
            Appliances::off(i);
            Light::on(i);
            Watch::on(i);
        }
    }
    void off_company(){
        char company;
        cout<<"전원을 끌 회사명을 입력하세요."<<endl;
        cin>>company;
        cin.ignore();
        Appliances::off(company);
        Watch::off(company);
        Light::off(company);
    }
};
