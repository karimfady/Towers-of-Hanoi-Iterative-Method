#include <iostream>
#include <cmath>

using namespace std;
class Hanoi{
public:
    int*Tower[3];
    int Top[3];
    int totalMoves;
    
    Hanoi(int n){
        int y=n;
        totalMoves=pow(2,n)-1;
        Top[0]=0;
        Top[1]=0;
        Top[2]=0;
        for(int i=0;i<3;i++)
            Tower[i]=new int[n];
        for(int i=0;((i<n)&&(y>0));i++)
        {
            Tower[0][i]=y;
            y--;
            Top[0]++;
        }
        Top[0]--;
        for(int i=1;i<=totalMoves;i++)
        {
            if(n%2==0)
            {
                if(i%3==1)
                { if(Tower[1][Top[1]]==0)
                    move(1,2);
                else if(Tower[0][Top[0]]==0)
                    move(2,1);
                else if((Tower[0][Top[0]]>Tower[1][Top[1]]))
                    move(2,1);
                else
                    move(1,2);
                }
                if(i%3==2)
                {
                    if(Tower[2][Top[2]]==0)
                        move(1,3);
                    else if(Tower[0][Top[0]]==0)
                        move(3,1);
                    
                    else if(Tower[0][Top[0]]>Tower[2][Top[2]])
                        move(3,1);
                    else
                        move(1,3);
                }

                if(i%3==0)
                {
                    if(Tower[2][Top[2]]==0)
                        move(2,3);
                    else if(Tower[1][Top[1]]==0)
                        move(3,2);
                    else if((Tower[1][Top[1]]>Tower[2][Top[2]]))
                        move(3,2);
                    else
                        move(2,3);
                }
            }
            else{
                
             if(i%3==1)//from 1 to 3
            {
                if(Tower[2][Top[2]]==0)
                    move(1,3);
                else if(Tower[0][Top[0]]==0)
                    move(3,1);
                
                else if(Tower[0][Top[0]]>Tower[2][Top[2]])
                    move(3,1);
                else
                    move(1,3);
            }
            /////////////////////////////////////////
            if(i%3==2)//from 1 to 2
            { if(Tower[1][Top[1]]==0)
                move(1,2);
            else if(Tower[0][Top[0]]==0)
                move(2,1);
            else if((Tower[0][Top[0]]>Tower[1][Top[1]]))
                move(2,1);
            else
                move(1,2);
            }
            if(i%3==0)//from 2 to 3
            {
                if(Tower[2][Top[2]]==0)
                    move(2,3);
                else if(Tower[1][Top[1]]==0)
                    move(3,2);
                else if((Tower[1][Top[1]]>Tower[2][Top[2]]))
                    move(3,2);
                else
                    move(2,3);
            }
            
        }
    }
    }
        

    
    
        void move(int S,int D)
    {
            cout<<"Disk "<<Tower[S-1][Top[S-1]]<<" moved from "<<S<<" to "<<D<<endl;
            Top[D-1]++;
            Tower[D-1][Top[D-1]]=Tower[S-1][Top[S-1]];
            Tower[S-1][Top[S-1]]=0;
            Top[S-1]--;
        }
};
    
int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    Hanoi H(n);
    return 0;
}
