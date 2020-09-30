#include <stdio.h>
#include <math.h>

int basic(char a);
int running_pay(char g, int BS, int E);
int rent_A(int RP);
int security(int BS);
int ad_hoc(char g, int age);
int Gross_P(RP, HRA, SSB, ARA);
float tax_P(int AI);
int tot_tax(int GP, float ITP);
int genaral_fund(int GP);
int don(int GP);
int deduct(int IT, int GPF, int donations);
int net(int GP, int deduct);
int main()
{
    char grade; int age, exp, basic_S, Run_P,HRA, SSB, ARA, GP,GP1, AI;
    int IT, GPF, donations, tot_deduct,net_pay; float ITP;
    printf("Enter your grade(W-Z): ");
    scanf("%c", &grade);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your years of experience: ");
    scanf("%d", &exp);
    printf("_______________________________________________");
    basic_S=basic(grade);
    Run_P=running_pay(grade, basic_S, exp);
    HRA=rent_A(Run_P);
    SSB=security(basic_S);
    ARA=ad_hoc(grade, age);
    GP=Gross_P(Run_P, HRA, SSB, ARA);
    AI=GP*12;
    ITP=tax_P(AI);
    IT=tot_tax(GP, ITP);
    GPF=genaral_fund(GP);
    donations=don(GP);
    tot_deduct=deduct(IT, GPF, donations);
    net_pay=net(GP, tot_deduct);
    printf("\nBasic Pay");
    printf("\n_______________________________________________");
    printf("\nBasic Salary:                 Rs %d", basic_S);
    printf("\nNumber of Increments:            %d", exp);
    printf("\nRunning Pay:                  Rs %d", Run_P);
    printf("\n\nAllowances");
    printf("\n_______________________________________________");
    printf("\nHouse Rent Allowance:         Rs %d", HRA);
    printf("\nSocial Security Benefit:      Rs %d", SSB);
    printf("\nAdhoc Relief Allowance:       Rs %d", ARA);
    printf("\n\nGross Pay:                    Rs %d", GP);
    printf("\n\nDeductions");
    printf("\n_______________________________________________");
    printf("\nIncome Tax %%:                  %.2f%%", ITP);
    printf("\nIncome Tax:                   Rs %d", IT);
    printf("\nGeneral Provident Fund:       Rs %d", GPF);
    printf("\nDonations:                    Rs %d", donations);
    printf("\n\nTotal Deductions:             Rs %d", tot_deduct);
    printf("\n\n\nNet Pay:                      Rs %d", net_pay);
    printf("\n\n\n_________________________________________________");
    return 0;
}

int basic(char a)
{
    int b;
    if(a=='W'||a=='w')
        b=10000;
    else if(a=='X'||a=='x')
        b=12900;
    else if(a=='Y'||a=='y')
        b=21700;
    else b=32600;
    return b;
}

int running_pay(char g,int BS, int E)
{
    int per_inc, RP;
    if (g=='W'||g=='w')
        per_inc=700;
    else if(g=='X'||g=='x')
        per_inc=910;
    else if(g=='Y'||g=='y')
        per_inc=1500;
    else per_inc=2800;
    RP=BS+(E*per_inc);
    return RP;
}

int rent_A(int RP)
{
    int rent;
    rent=RP*(45/(float)100);
    return rent;
}

int security(int BS)
{
    int sec;
    sec=BS*(30/(float)100);
    return sec;
}

int ad_hoc(char g, int age)
{
    int relief;
    if ((g=='W'||g=='w')&& age >40)
        relief = 3000;
    else relief = 1500;
    return relief;
}

int Gross_P(RP, HRA, SSB, ARA)
{
    int GP;
    GP=RP+HRA+SSB+ARA;
    return GP;
}

float tax_P(int AI)
{
    float IT;
    if(AI<=400000)
        IT=0;
    else if(AI>400000&&AI<=650000)
        IT=2.5;
    else if(AI>650000&&AI<=1000000)
        IT=4.75;
    else if(AI>1000000&&AI<=1500000)
        IT=7;
    else IT=11.5;
    return IT;
}

int tot_tax(int GP, float ITP)
{
    int IT;
    IT=GP*(ITP/(float)100);
    return IT;
}

int genaral_fund(int GP)
{
    int fund;
    fund=GP*(10/(float)100);
    return fund;
}
int don(int GP)
{
    int donation;
    donation=GP%100;
    return donation;
}
int deduct(int IT, int GPF, int donations)
{
    int deductions;
    deductions=IT+GPF+donations;
    return deductions;
}
int net(int GP, int deduct)
{
    int pay;
    pay=GP-deduct;
    return pay;
}
