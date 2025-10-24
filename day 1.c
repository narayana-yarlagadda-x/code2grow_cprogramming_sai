#include<stdio.h>
int main()
{
float basicsalary, hrapercent, dapercent, taxpercent;
float hra, da, tax, grosssalary;
printf("enter the basicsalary\n");
scanf("%f",&basicsalary);
printf("enter hrapercent\n");
scanf("%f",&hrapercent);
printf("enter dapercent\n");
scanf("%f",&dapercent);
printf("enter taxpercent\n");
scanf("%f",&taxpercent);
hra=basicsalary*(hrapercent/100);
da=basicsalary*(dapercent/100);
tax=basicsalary*(taxpercent/100);
grosssalary=basicsalary+hra+da-tax;
printf("the hra value is %.2f\n,hra");
printf("the da value is %.2f\n",da);
printf("the tax value is %.2f\n,tax");
printf("the gross salary is %.2f\n",grosssalary);
return 0;
}
