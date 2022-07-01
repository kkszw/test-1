#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void PreDate()
{
    int year,month,date,yy,mm,dd;
    char y[10],m[10],d[10];
    printf("请输入日期(1800 01 02 - 2022 12 31):");
    scanf("%s",y);
    scanf("%s",m);
    scanf("%s",d);
    year=atoi(y);
    month=atoi(m);
    date=atoi(d);
    if(year<1800||year>2022)
    {
        printf("年不合法\n");
        return;
    }
    if(month<1||month>12)
    {
        printf("月不合法\n");
        return;
    }
    if(date<1||date>31)
    {
        printf("日不合法\n");
        return;
    }
    dd=date-1;
    if(dd!=0)
    {
        mm=month;
        yy=year;
    }
    else
    {
        mm=month-1;
        yy=year;
        if(mm!=0)
        {
            if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
            {
                dd=31;
            }
            else if(mm==2)
            {
                if((yy%4==0&&yy%100!=0)||yy%400==0)
                    dd=29;
                else
                    dd=28;
            }
            else
                dd=30;
        }
        else
        {
            yy=yy-1;
            if(yy<1800)
            {
                printf("超出最低范围！\n");
                return;
            }
            mm=12;
            dd=31;
        }
    }
    printf("%d %.2d %.2d\n",yy,mm,dd);
}
void main()
{
    PreDate();
}
