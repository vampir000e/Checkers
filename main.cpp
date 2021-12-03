#include"checkers.h"

int main()
{
    initwindow(WIDTH,WIDTH,"Skip");
    ShowBanner();
    int select;
    while(cin>>select)
    {
        if(select == -1)
        {
            break;
        }
        else
        {
            Play(select);
        }
        ShowBanner();
    }

    Skip();

    system("pause");
    return 0;
}

void ShowBanner()
{
    cout<<"Input what kind of game you want to play:"<<endl;
    cout<<"1. Man to man."<<endl;
    cout<<"2. Man to computer"<<endl;
    cout<<"3. Computer to Man."<<endl;
    cout<<"4. Computer to computer with AlphaBeta."<<endl;
    cout<<"5. Test."<<endl;
}

void Play(int select)
{
    Skip skip;
    switch(select)
    {
    case 1:
        skip.playManToMan();
        break;
    case 2:
        skip.playManToComputer();
        break;
    case 3:
        skip.playComputerToMan();
        break;
    case 4:
        skip.playComputerToComputer();
        break;
    case 5:
        skip.Test_Gen_Black_Pawn_Move();
        //skip.Test_isGameOver();
        //skip.Test_eatcount();
        //skip.Test_Flank_Num(4,9);
        //skip.Test_can_eat(3,5);
        //skip.Test();
        break;
    }
}

//ÕýÈ·
void DisplayBoard(int position[][10])
{
    cout<<endl;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(j==9)
            {
                cout<<"\t"<<position[i][j];
                cout<<endl;
            }
            else
            {
                cout<<"\t"<<position[i][j];
            }
        }
    } cout<<endl;
}
