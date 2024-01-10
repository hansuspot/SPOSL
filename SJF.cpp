#include<iostream>
using namespace std;
void sjf(string pr[], int bt[], int at[], int n)
{
    int ft[20],tbt[20],ta[20],wt[20],count=0,count1=0;
    ft[0]=at[0];
    for(int i=0;i<n;i++)
    {
        if(at[i]!=0)
        {
            if(i>1)
            {
                string tpr;
                int tbt, tat;
                if(bt[i]<bt[i-1])
                {
                    tpr=pr[i];
                    tbt=bt[i];
                    tat=at[i];
                    pr[i]=pr[i-1];
                    bt[i]=bt[i-1];
                    at[i]=at[i-1];
                    pr[i-1]=tpr;
                    bt[i-1]=tbt;
                    at[i-1]=tat;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        tbt[i-1]=bt[i-1];
        ft[i]=bt[i-1]+ft[i-1];

    }
    cout<<"\nganttchart"<<endl;
    cout<<"   ";
    for(int j=0;j<n;j++)
    {
        cout<<pr[j]<<"      ";
    }
    cout<<endl;
    for(int j=0;j<=n;j++)
    {
        cout<<ft[j]<<"      ";
    }
    cout<<"\n\n Turn Around Time"<<endl;
    for(int i=0;i<n;i++)
    {
        ta[i]=ft[i+1]-at[i];
        cout<<"\n T. time of "<<pr[i]<<" is:"<<ta[i];
        count=count+ta[i];
    }
    cout<<"\nAverage T. time ="<<count/n<<" msec"<<endl;
    cout<<"\n Waiting Around Time"<<endl;
    for(int i=0;i<n;i++)
    {
        wt[i]=ta[i+1]-bt[i];
        cout<<"\n W. time of "<<pr[i]<<" is:"<<wt[i];
        count1=count1+wt[i];
    }
    cout<<"\nAverage W. time ="<<count1/n<<" msec"<<endl;
}
int main()
{
    string pr[20];
    int n,at[20],bt[20];
    cout<<"SJF"<<endl;
    for(int i=0;i<20;i++)
    {
        bt[i]=0;
    }
    cout<<"enter total number of process: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter processes["<<i+1<<"] : ";
        cin>>pr[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter B. Time of "<<pr[i]<<" : ";
        cin>>bt[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter A. Time of "<<pr[i]<<" : ";
        cin>>at[i];
    }
    cout<<"\nProceses"<<"\tB.Time"<<"\t   A. Time"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<pr[i]<<"\t\t"<<bt[i]<<"\t\t"<<at[i]<<endl;
    }
    sjf(pr,bt,at,n);
    return 0;
}