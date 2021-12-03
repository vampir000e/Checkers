#ifndef SKIP_H_INCLUDED
#define SKIP_H_INCLUDED

#include<iostream>
#include<winbgim.h>
#include<vector>
#include<list>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include<algorithm>
#include<stdlib.h>
#include<fstream>
#include<vector>

using namespace std;

#define WIDTH 640
#define LEFT 20
#define TOP 20
#define STEP 60

#define EMPTY -1

#define OET_END 6 //残局界定值
#define OET_MID 4 //中局界定值
//开局时初始值是2.5


/*
#define KET	15	//平衡因子
#define KEM	27	//棋力
#define KEC	23  //中间位置
#define KEG	35	//列数
*/


const int BLACKCHESS = 1;
const int WHITECHESS = 2;
const int BLACKKING = 3;
const int WHITEKING = 4;
const int TT=22;

struct EATCOUNT
{
    int height;  //吃子数
    short x;
    short y;
};

struct STONEPOS
{
    short int x;
    short int y;
};

typedef struct Node
{
    STONEPOS p1,p2;
    Node*parent;
}NODE,*NodeLink;

struct STONEMOVE
{
    Node * head;
    int score;
};

void ShowBanner();
void Play(int select);
void DisplayBoard(int position[][10]);

class Skip
{
private:
    int side;
    int count;
    int sideCount;
    int Depth;
    int m_nMoveCount;   //走法数初始为0
    int height;
    //int no;
    int mside;
    ofstream f;


public:
    vector <EATCOUNT> Walk_to_pieces;

    STONEMOVE BestMove;
    STONEMOVE m_MoveList[40][300];
    EATCOUNT move[100];

    STONEMOVE  filemove[100];

    Skip();
    int position[10][10];

    void Test();
    void InitSkip();
    void DrawBlack_pawn(int x,int y);
    void DrawWhite_pawn(int x,int y);
    void DrawBlack_king(int x,int y);
    void DrawWhite_king(int x,int y);
    void DrawBackGround(int x,int y);

    void DrawBoard(int position[][10]);
    void ExchangeBlack_king(int x,int y);
    void ExchangeWhite_king(int x,int y);
    int CreatePossibleMove(int position[][10],int nSide,int nply);

    void Find_Can_Move_Pieces(int position[][10],int Type);
    void Find_Can_Move_Pieces1(int position[][10],int Type);

    int eatcount(int position[][10],int i,int j);
    int king_eatcount(int position [][10],int i,int j);
    int can_eat(int position[][10],int i,int j);

    void Test_can_eat(int x,int y);

    int king_can_eat(int position[][10],int i,int j);
    void Gen_Black_Pawn_Move(int position[][10],int x,int y,int nply);
    void Gen_White_Pawn_Move(int position[][10],int x,int y,int nply);
    int Gen_Pawn_Eat_Move(int position[][10],int x,int y, NODE*parentnode,int height,int nply);
    void Gen_black_King_Move(int position[][10],int x,int y,int nPly);
    void Gen_white_King_Move(int position[][10],int x,int y,int nPly);

    int Gen_King_Eat_Move(int position[][10],int x,int y,NODE* parentnode,int height,int nply);
    bool can_white_move(int position [][10]);
    bool can_black_move(int position [][10]);

    bool whiteking_can_move(int position[][10]);
    bool blackking_can_move(int position[][10]);

    bool isGameOver();

    int isWin();


    int WHITENUM(int position[][10]);
    int BLACKNUM(int position[][10]);

    int min_h(int a,int b);
    int max_h(int a,int b);

    int NorthWest(int position[][10],int x,int y);
    int NorthEast(int position[][10],int x,int y);
    int SouthWest(int position[][10],int x,int y);
    int SouthEast(int position[][10],int x,int y);

    double Alphabetasearch(int depth,int side,int alpha,int beta);
    double alphabetasearch(int depth,int side,int alpha,int beta);//原来的
    double Eval(int position[][10],int side);

    double Value(int position[][10],int side);
    void GetDepth(int position[][10]);
    int MatrixValue(int position[][10],int nSide);


    int PawnNumber(int position[][10]);
    int KingNumber(int position[][10]);

    void playManToMan();
    void playComputerToComputer();
    void playManToComputer();
    void playComputerToMan();

    int randomPlay(int position[][10],int side,int count);
    //POSITION generatorRandomPosition(BYTE position[][10],unsigned seed);
    void generatorTempPosition(int position[][10],int tempPosition[][10],int x,int y,int side,int count);
    int computerGo(int position[][10],int side,int count);
    void computerToComputerProb();

    string Findnumber(int x,int y);

    int Result(string result);
    int file();
    int Record(int num,string record1,string record2,string type1,string record3,string record4,string type2);

    void FindMiddle(NODE* tnode,NODE* fnode,string type);

    void Test_isGameOver();
    void Test_Gen_Black_Pawn_Move();

};


#endif // CHECKERS_H_INCLUDED
