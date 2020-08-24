#include<bits/stdc++.h>
using namespace std;

class Grid
{
    vector<vector<int>> v;
    bool endgame;
    int nummoves;
    bool isitover;
    private:

        int spacesrequired(int n)
        {
            if(n==0)
            {
                return 0;
            }
            int ans=-1;
            while (n!=0)
            {
                ans++;
                n/=10;
            }
            return ans;
        }

        void printfunc()
        {
            int maxf = INT_MIN; 
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    maxf = max(maxf,v[i][j]);
                }
            }
            int spaces = -1;
            while (maxf!=0)
            {
                spaces++;
                maxf/=10;
            }
            for(int i=0;i<4;i++)
            {
                cout<<"|";
                for(int j=0;j<4;j++)
                {
                    cout<<v[i][j];
                    for(int k=0;k<spaces-spacesrequired(v[i][j]);k++)
                    {
                        cout<<" ";
                    }
                    cout<<"|";
                }
                cout<<"\n";
            }
            cout<<"\n\n";
        }

        void randomposgenerator()
        {
            bool flag = false;
            int numzeros = 0;
            int ipos;
            int jpos;
            for (int i = 0; i < 4; i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(!v[i][j])
                    {
                        numzeros++;
                        ipos = i;
                        jpos = j;
                    }
                }
            }

            if(numzeros==1)
            {
                v[ipos][jpos]=2;
                return;
            }
            
            while (!flag)
            {
                int i = rand()%4;
                int j = rand()%4;
                if(!v[i][j])
                {
                    v[i][j]=2;
                    flag = true;
                }
            }
            
            
        }

    public:

        Grid()
        {
            v={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
            randomposgenerator();
            randomposgenerator();
            printfunc();
            nummoves = 0;
            isitover = false;
            endgame = false;
        }

        void leftfunc()
        {
            nummoves=0;
            bool arr[4][4] = {false};
            for(int j=1;j<4;j++)
            {
                for(int i=0;i<4;i++)
                {
                    if(v[i][j])
                    {
                        for(int k=0;k<j;k++)
                        {
                            if(v[i][k]==0)
                            {
                                v[i][k]=v[i][j];
                                v[i][j]=0;
                                nummoves++;
                                break;
                            }
                            else
                            {
                                if(v[i][k]==v[i][j]&&!arr[i][k])
                                {
                                    if(j!=k+1&&v[i][k+1])
                                    {
                                        continue;
                                    }
                                    v[i][k]*=2;
                                    v[i][j]=0;
                                    arr[i][k]=true;
                                    nummoves++;
                                    break;
                                }
                            }
                            
                        }
                    }
                }
            }
            if(nummoves==0)
            {
                if(!endgame)
                    cout<<"\nYou can't move in this direction further\n";
                return;
            }
            randomposgenerator();
            printfunc();
        }

        void rightfunc()
        {
            nummoves=0;
            bool arr[4][4] = {false};
            for(int j=2;j>=0;j--)
            {
                for(int i=0;i<4;i++)
                {
                    if(v[i][j])
                    {
                        for(int k=3;k>j;k--)
                        {
                            if(v[i][k]==0)
                            {
                                v[i][k]=v[i][j];
                                v[i][j]=0;
                                nummoves++;
                                break;
                            }
                            else
                            {
                                if(v[i][k]==v[i][j]&&!arr[i][k])
                                {
                                    if(j!=k-1&&v[i][k-1])
                                    {
                                        continue;
                                    }
                                    v[i][k]*=2;
                                    v[i][j]=0;
                                    arr[i][k]=true;
                                    nummoves++;
                                    break;
                                }
                            }
                            
                        }
                    }
                }
            }
            if(nummoves==0)
            {
                if(!endgame)
                    cout<<"\nYou can't move in this direction further\n";
                return;
            }
            randomposgenerator();
            printfunc();
        }

        void upfunc()
        {
            nummoves=0;
            bool arr[4][4] = {false};
            for(int i=1;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(v[i][j])
                    {
                        for(int k=0;k<i;k++)
                        {
                            if(v[k][j]==0)
                            {
                                v[k][j]=v[i][j];
                                v[i][j]=0;
                                nummoves++;
                                break;
                            }
                            else
                            {
                                if(v[k][j]==v[i][j]&&!arr[k][j])
                                {
                                    if(i!=k+1&&v[k+1][j])
                                    {
                                        continue;
                                    }
                                    v[k][j]*=2;
                                    v[i][j]=0;
                                    arr[k][j]=true;
                                    nummoves++;
                                    break;
                                }
                            }
                            
                        }
                    }
                }
            }
            if(nummoves==0)
            {
                if(!endgame)
                    cout<<"\nYou can't move in this direction further\n";
                return;
            }
            randomposgenerator();
            printfunc();
        }

        void downfunc()
        {
            nummoves=0;
            bool arr[4][4] = {false};
            for(int i=2;i>=0;i--)
            {
                for(int j=0;j<4;j++)
                {
                    if(v[i][j])
                    {
                        for(int k=3;k>i;k--)
                        {
                            if(v[k][j]==0)
                            {
                                v[k][j]=v[i][j];
                                v[i][j]=0;
                                nummoves++;
                                break;
                            }
                            else
                            {
                                if(v[k][j]==v[i][j]&&!arr[k][j])
                                {
                                    if(i!=k-1&&v[k-1][j])
                                    {
                                        continue;
                                    }
                                    v[k][j]*=2;
                                    v[i][j]=0;
                                    arr[k][j]=true;
                                    nummoves++;
                                    break;
                                }
                            }
                            
                        }
                    }
                }
            }
            if(nummoves==0)
            {
                if(!endgame)
                    cout<<"\nYou can't move in this direction further\n";
                return;
            }
            randomposgenerator();
            printfunc();
        }
        bool isitoverfunc()
        {
            endgame = true;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(!v[i][j])
                    {
                        endgame = false;
                        return false;
                    }
                }
            }
            vector<vector<int>> temp = v;
            leftfunc();
            v= temp;
            if(nummoves>0)
            {
                endgame = false;
                return false;
            }
            rightfunc();
            v= temp;
            if(nummoves>0)
            {
                endgame = false;
                return false;
            }
            upfunc();
            v= temp;
            if(nummoves>0)
            {
                endgame = false;
                return false;
            }
            downfunc();
            v= temp;
            if(nummoves>0)
            {
                endgame = false;
                return false;
            }
            v=temp;
            return true;
        }

        int highscore()
        {
            int high=INT_MIN;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    high = max(high,v[i][j]);
                }
            }
            return high;
        }
};



int main()
{
    int maxscore = INT_MIN;
    srand(time(0));
    Grid ob;
    char c='p';
    while (c!='e'&&!ob.isitoverfunc())
    {
        cin>>c;
        cout<<"\n\n";
        if(c=='l')
        {
            ob.leftfunc();
        }    
        else if(c=='r')
        {
            ob.rightfunc();
        }
        else if(c=='u')
        {
            ob.upfunc();
        }
        else if(c=='d')
        {
            ob.downfunc();
        }
        maxscore = ob.highscore();
    }
    cout<<"\n\n\n THE HIGHEST SCORE IS "<<maxscore<<"\n";
    cout<<"\nbye\n";
    return 0;
}