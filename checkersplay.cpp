#include"checkers.h"

void Skip::Test_isGameOver()
{
    cleardevice();
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            position[i][j] = EMPTY;
        }
    }
    position[1][0]=WHITECHESS;
    position[3][2]=WHITECHESS;

    //position[4][3]=BLACKCHESS;
    DrawBoard(position);
    side=1;
    if(isGameOver())
    {
        cout<<"GameOver!!"<<endl;
    }
}

Skip::Skip()
{
    InitSkip();
}

//��ȷ
void Skip::InitSkip()  //��ʼ����������
{
    cleardevice();
    int i,j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            position[i][j] = EMPTY;
        }
    }

    position[0][1] = BLACKCHESS;
    position[0][3] = BLACKCHESS;
    position[0][5] = BLACKCHESS;
    position[0][7] = BLACKCHESS;
    position[0][9] = BLACKCHESS;
    position[1][0] = BLACKCHESS;
    position[1][2] = BLACKCHESS;
    position[1][4] = BLACKCHESS;
    position[1][6] = BLACKCHESS;
    position[1][8] = BLACKCHESS;
    position[2][1] = BLACKCHESS;
    position[2][3] = BLACKCHESS;
    position[2][5] = BLACKCHESS;
    position[2][7] = BLACKCHESS;
    position[2][9] = BLACKCHESS;
    position[3][0] = BLACKCHESS;
    position[3][2] = BLACKCHESS;
    position[3][4] = BLACKCHESS;
    position[3][6] = BLACKCHESS;
    position[3][8] = BLACKCHESS;

    position[6][1] = WHITECHESS;
    position[6][3] = WHITECHESS;
    position[6][5] = WHITECHESS;
    position[6][7] = WHITECHESS;
    position[6][9] = WHITECHESS;
    position[7][0] = WHITECHESS;
    position[7][2] = WHITECHESS;
    position[7][4] = WHITECHESS;
    position[7][6] = WHITECHESS;
    position[7][8] = WHITECHESS;
    position[8][1] = WHITECHESS;
    position[8][3] = WHITECHESS;
    position[8][5] = WHITECHESS;
    position[8][7] = WHITECHESS;
    position[8][9] = WHITECHESS;
    position[9][0] = WHITECHESS;
    position[9][2] = WHITECHESS;
    position[9][4] = WHITECHESS;
    position[9][6] = WHITECHESS;
    position[9][8] = WHITECHESS;


//���Եľ���
/*
    /size!=0 Count=0  illeagle!!
    position[9][0]=WHITECHESS;
    position[9][2]=WHITECHESS;
    position[8][5]=WHITECHESS;
    position[7][4]=BLACKKING;
    */

/*
    position[0][1]=position[0][3]=position[0][5]=position[0][7]=BLACKCHESS;
    position[1][0]=position[1][2]=position[1][6]=BLACKCHESS;
    position[3][0]=BLACKCHESS;
    position[4][9]=WHITECHESS;
    position[6][1]=WHITECHESS;
    position[6][7]=BLACKKING;
    position[9][0]=position[9][2]=WHITECHESS;
*/

/*
    position[0][3]=WHITEKING;
    position[0][9]=position[1][0]=position[1][8]=position[2][3]=position[3][0]=BLACKCHESS;
*/

/*
    position[0][9]=position[1][6]=position[1][8]=position[5][0]=position[5][6]=position[8][3]=position[8][5]=WHITECHESS;
    position[8][7]=BLACKCHESS;
    position[9][2]=BLACKKING;
/*
    position[0][9]=position[5][0]=position[8][3]=position[8][5]=WHITECHESS;
    position[8][7]=BLACKCHESS;
    position[9][2]=BLACKKING;
*/

/*
    position[0][9]=position[1][6]=position[1][8]=position[2][5]=position[2][7]=position[2][9]=position[3][4]=position[3][8]=BLACKCHESS;
    position[7][0]=BLACKCHESS;
    position[6][1]=WHITEKING;
    //position[7][8]=WHITECHESS;
    position[8][1]=position[8][3]=position[8][5]=position[8][7]=position[8][9]=WHITECHESS;
    position[9][0]=position[9][2]=position[9][4]=position[9][6]=position[9][8]=WHITECHESS;
*/
    DrawBoard(position);
    side=1;
}

//��ȷ
void Skip::DrawBoard(int position[][10])
{
    int i,j;
    //���Ʊ���
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if((i+j)%2==0)
            {
                DrawBackGround(i,j);
            }
        }
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(position[i][j]==EMPTY)
            {

            }
            else
            {
                if(position[i][j] == BLACKCHESS)
                {
                    DrawBlack_pawn(j,i);
                }
                if(position[i][j] == WHITECHESS)
                {
                    DrawWhite_pawn(j,i);
                }
                if(position[i][j]==BLACKKING)
                {
                    DrawBlack_king(j,i);
                }
                if(position[i][j]==WHITEKING)
                {
                    DrawWhite_king(j,i);
                }
            }
        }
    }
    line(LEFT,TOP,WIDTH-LEFT,TOP);
    line(LEFT,TOP,LEFT,WIDTH-TOP);
    line(LEFT,WIDTH-TOP,WIDTH-LEFT,WIDTH-TOP);
    line(WIDTH-LEFT,TOP,WIDTH-LEFT,WIDTH-TOP);

    outtextxy(10,0*STEP+50,"0");outtextxy(0*STEP+50,4,"0");
    outtextxy(10,1*STEP+50,"1");outtextxy(1*STEP+50,4,"1");
    outtextxy(10,2*STEP+50,"2");outtextxy(2*STEP+50,4,"2");
    outtextxy(10,3*STEP+50,"3");outtextxy(3*STEP+50,4,"3");
    outtextxy(10,4*STEP+50,"4");outtextxy(4*STEP+50,4,"4");
    outtextxy(10,5*STEP+50,"5");outtextxy(5*STEP+50,4,"5");
    outtextxy(10,6*STEP+50,"6");outtextxy(6*STEP+50,4,"6");
    outtextxy(10,7*STEP+50,"7");outtextxy(7*STEP+50,4,"7");
    outtextxy(10,8*STEP+50,"8");outtextxy(8*STEP+50,4,"8");
    outtextxy(10,9*STEP+50,"9");outtextxy(9*STEP+50,4,"9");

    outtextxy(1*STEP+70,0*STEP+64,"1"); outtextxy(3*STEP+70,0*STEP+64,"2");outtextxy(5*STEP+70,0*STEP+64,"3");outtextxy(7*STEP+70,0*STEP+64,"4");outtextxy(9*STEP+70,0*STEP+64,"5");
    outtextxy(0*STEP+70,1*STEP+64,"6");outtextxy(2*STEP+70,1*STEP+64,"7");outtextxy(4*STEP+70,1*STEP+64,"8");outtextxy(6*STEP+70,1*STEP+64,"9");outtextxy(8*STEP+70,1*STEP+64,"10");
    outtextxy(1*STEP+70,2*STEP+64,"11");outtextxy(3*STEP+70,2*STEP+64,"12");outtextxy(5*STEP+70,2*STEP+64,"13");outtextxy(7*STEP+70,2*STEP+64,"14");outtextxy(9*STEP+70,2*STEP+64,"15");
    outtextxy(0*STEP+70,3*STEP+64,"16");outtextxy(2*STEP+70,3*STEP+64,"17");outtextxy(4*STEP+70,3*STEP+64,"18");outtextxy(6*STEP+70,3*STEP+64,"19");outtextxy(8*STEP+70,3*STEP+64,"20");
    outtextxy(1*STEP+70,4*STEP+64,"21");outtextxy(3*STEP+70,4*STEP+64,"22");outtextxy(5*STEP+70,4*STEP+64,"23");outtextxy(7*STEP+70,4*STEP+64,"24");outtextxy(9*STEP+70,4*STEP+64,"25");
    outtextxy(0*STEP+70,5*STEP+64,"26");outtextxy(2*STEP+70,5*STEP+64,"27");outtextxy(4*STEP+70,5*STEP+64,"28");outtextxy(6*STEP+70,5*STEP+64,"29");outtextxy(8*STEP+70,5*STEP+64,"30");
    outtextxy(1*STEP+70,6*STEP+64,"31");outtextxy(3*STEP+70,6*STEP+64,"32");outtextxy(5*STEP+70,6*STEP+64,"33");outtextxy(7*STEP+70,6*STEP+64,"34");outtextxy(9*STEP+70,6*STEP+64,"35");
    outtextxy(0*STEP+70,7*STEP+64,"36");outtextxy(2*STEP+70,7*STEP+64,"37");outtextxy(4*STEP+70,7*STEP+64,"38");outtextxy(6*STEP+70,7*STEP+64,"39");outtextxy(8*STEP+70,7*STEP+64,"40");

    outtextxy(1*STEP+70,8*STEP+64,"41");outtextxy(3*STEP+70,8*STEP+64,"42");outtextxy(5*STEP+70,8*STEP+64,"43");outtextxy(7*STEP+70,8*STEP+64,"44");outtextxy(9*STEP+70,8*STEP+64,"45");
    outtextxy(0*STEP+70,9*STEP+64,"46");outtextxy(2*STEP+70,9*STEP+64,"47");outtextxy(4*STEP+70,9*STEP+64,"48");outtextxy(6*STEP+70,9*STEP+64,"49");outtextxy(8*STEP+70,9*STEP+64,"50");
}

//��ȷ ������position[y][x]��
void Skip::DrawBackGround(int y,int x)
{
    int poly[8];
    poly[0] = x * STEP + LEFT;
    poly[1] = y * STEP + TOP;
    poly[2] = (x+1) * STEP + LEFT;
    poly[3] = y * STEP + TOP;
    poly[4] = (x+1) * STEP + LEFT;
    poly[5] = (y+1) * STEP + TOP;
    poly[6] = x * STEP + LEFT;
    poly[7] = (y+1) * STEP + TOP;
    setfillstyle(1,8);
    fillpoly(4,poly);
}

//��ȷ ������position[y][x]��
void Skip::DrawBlack_pawn(int x,int y)
{
    setfillstyle(1,1);
    fillellipse(LEFT + x*STEP + STEP/2,TOP + y*STEP + STEP/2, STEP/2 - 6,STEP/2 - 6);
}

//��ȷ ������position[y][x]��
void Skip::DrawWhite_pawn(int x,int y)
{
    setfillstyle(1,15);
    fillellipse(LEFT + x*STEP + STEP/2,TOP + y*STEP + STEP/2, STEP/2 - 6,STEP/2 - 6);
}

//��ȷ ����potsition[y][x]��
void Skip::DrawBlack_king(int x,int y)
{
    int poly[6],poly1[6],poly2[6];
    poly[0] = x*STEP + LEFT+STEP/2;
    poly[1] = y*STEP + TOP+15;
    poly[2] = x*STEP + LEFT+STEP/2+9;
    poly[3] = y*STEP+TOP+45;
    poly[4]= x*STEP + LEFT+STEP/2-9;
    poly[5]= y*STEP+TOP+45;

    poly1[0] = x*STEP + LEFT+STEP/2+4;
    poly1[1] = y*STEP + TOP+15+14;

    poly1[2] = x*STEP + LEFT+STEP/2+18;
    poly1[3] = y*STEP + TOP+15+8.2;

    poly1[4] = x*STEP + LEFT+STEP/2+9;
    poly1[5] = y*STEP+TOP+45;

    poly2[0]= x*STEP + LEFT+STEP/2-18;
    poly2[1]= y*STEP+TOP+15+8.2;

    poly2[2]= x*STEP + LEFT+STEP/2-4;
    poly2[3]= y*STEP+TOP+15+14;

    poly2[4]= x*STEP + LEFT+STEP/2-9;
    poly2[5]= y*STEP+TOP+45;

    setfillstyle(1,1);

    fillpoly(3,poly1);
    fillpoly(3,poly2);
    fillpoly(3,poly);
}

//��ȷ ����position[y][x]��
void Skip::DrawWhite_king(int x,int y)
{
    int poly[6],poly1[6],poly2[6];
    poly[0] = x*STEP + LEFT+STEP/2;
    poly[1] = y*STEP + TOP+15;
    poly[2] = x*STEP + LEFT+STEP/2+9;
    poly[3] = y*STEP+TOP+45;
    poly[4]= x*STEP + LEFT+STEP/2-9;
    poly[5]= y*STEP+TOP+45;

    poly1[0] = x*STEP + LEFT+STEP/2+4;
    poly1[1] = y*STEP + TOP+15+14;

    poly1[2] = x*STEP + LEFT+STEP/2+18;
    poly1[3] = y*STEP + TOP+15+8.2;

    poly1[4] = x*STEP + LEFT+STEP/2+9;
    poly1[5] = y*STEP+TOP+45;

    poly2[0]= x*STEP + LEFT+STEP/2-18;
    poly2[1]= y*STEP+TOP+15+8.2;

    poly2[2]= x*STEP + LEFT+STEP/2-4;
    poly2[3]= y*STEP+TOP+15+14;

    poly2[4]= x*STEP + LEFT+STEP/2-9;
    poly2[5]= y*STEP+TOP+45;

    setfillstyle(1,15);

    fillpoly(3,poly1);
    fillpoly(3,poly2);
    fillpoly(3,poly);
}

//��ȷ
//�ҳ����ߵ�����
void Skip::Find_Can_Move_Pieces(int position[][10],int side)   //side ���巽
{
    EATCOUNT temp;     //������ӵĽڵ�
    Walk_to_pieces.clear();  //�������
    if(side==1)     //�ڷ�
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(position[i][j]==BLACKKING)     //��ǰ����Ϊ����
                {
                    temp.height=king_eatcount(position,i,j);   //��������ӵĳ�����
                    temp.x=i;
                    temp.y=j;
//cout<<"������(��������)"<<temp.height<<endl;
                    /*
                    if(temp.height==0&&j==0&&position[i-1][j+1]!=EMPTY&&position[i+1][j+1]!=EMPTY)
                    {
                        continue;
                    }
                    else if(temp.height==0&&j==7&&position[i-1][j-1]!=EMPTY&&position[i+1][j-1]!=EMPTY)
                    {
                        continue;
                    }
                    else if(temp.height==0&&position[i-1][j-1]!=EMPTY&&position[i-1][j+1]!=EMPTY&&position[i+1][j-1]!=EMPTY&&position[i+1][j+1]!=EMPTY)
                    {
                        continue;
                    }*/
                    //���潫��������ķ��뵽Walk_to_pieces��
                    if(Walk_to_pieces.empty())     //���Walk_to_pieces�ǿյ�
                    {
                        Walk_to_pieces.push_back(temp);    //�����ӷ���������
//cout<<"chizi"<<Walk_to_pieces[0].height<<endl;
                    }
                    else
                    {
                        if(Walk_to_pieces[0].height<temp.height)  //�жϸ���ĳ������Ƿ��Walk_to_pieces�е����Ӷ�
                        {
                            Walk_to_pieces.clear();    //��ո�����
                            Walk_to_pieces.push_back(temp);  //�������ӷ��뵽Walk_to_pieces��
//cout<<"�ڳ�����1 "<<Walk_to_pieces[0].height<<endl;
                        }
                        else if(Walk_to_pieces[0].height==temp.height)//������ӳ������������б�������һ����
                        {
                            Walk_to_pieces.push_back(temp); //������Ҳ��ӵ�������
//cout<<"�ڳ�����2 "<<Walk_to_pieces[0].height<<endl;
                        }
                    }
                }//����
                else if(position[i][j]==BLACKCHESS)     //��ǰ����Ϊ�ڱ�
                {
                    temp.height=eatcount(position,i,j);   //������ӵĳ�����
                    temp.x=i;
                    temp.y=j;
                    //���潫��������ķ��뵽Walk_to_pieces��
                    if(Walk_to_pieces.empty())     //���Walk_to_pieces�ǿյ�
                    {
                        Walk_to_pieces.push_back(temp);    //�����ӷ���������
                    }
                    else
                    {
                        if(Walk_to_pieces[0].height<temp.height)  //�жϸ���ĳ������Ƿ��Walk_to_pieces�е����Ӷ�
                        {
                            Walk_to_pieces.clear();    //��ո�����
                            Walk_to_pieces.push_back(temp);  //�������ӷ��뵽Walk_to_pieces��
//cout<<"�ڳ�����1"<<Walk_to_pieces[0].height<<endl;
                        }
                        else if(Walk_to_pieces[0].height==temp.height)//������ӳ������������б�������һ����
                        {
                            Walk_to_pieces.push_back(temp); //������Ҳ��ӵ�������
//cout<<"�ڳ�����2"<<Walk_to_pieces[0].height<<endl;
                        }
                    }
                }//�ڱ�
            }//for j
        }//for i
    }//side=1
    else if(side==-1)     //�׷�
    {
        for(int i=0;i<10;i++)  //��������
        {
            for(int j=0;j<10;j++)
            {
                if(position[i][j]==WHITECHESS)     //��ǰ����Ϊ�ױ�
                {
                    temp.height=eatcount(position,i,j);   //������ӵĳ�����
                    temp.x=i;
                    temp.y=j;
                    //���潫��������ķ��뵽Walk_to_pieces��
                    if(Walk_to_pieces.empty())     //���Walk_to_pieces�ǿյ�
                    {
                        Walk_to_pieces.push_back(temp);    //�����ӷ���������
//cout<<"chizi"<<Walk_to_pieces[0].height<<endl;
                    }
                    else
                    {
                        if(Walk_to_pieces[0].height<temp.height)  //�жϸ���ĳ������Ƿ��Walk_to_pieces�е����Ӷ�
                        {
                            Walk_to_pieces.clear();    //��ո�����
                            Walk_to_pieces.push_back(temp);  //�������ӷ��뵽Walk_to_pieces��
//cout<<"�ڳ�����1"<<Walk_to_pieces[0].height<<endl;
                        }
                        else if(Walk_to_pieces[0].height==temp.height)//������ӳ������������б�������һ����
                        {
                            Walk_to_pieces.push_back(temp); //������Ҳ��ӵ�������
//cout<<"�ڳ�����2"<<Walk_to_pieces[0].height<<endl;
                        }
                    }
                }
                else if(position[i][j]==WHITEKING)     //��ǰ����Ϊ����
                {
                    temp.height=king_eatcount(position,i,j);   //��������ӵĳ�����
                    temp.x=i;
                    temp.y=j;
//cout<<"������(��������)"<<temp.height<<endl;
                    //���潫��������ķ��뵽Walk_to_pieces��
                    if(Walk_to_pieces.empty())     //���Walk_to_pieces�ǿյ�
                    {
                        Walk_to_pieces.push_back(temp);    //�����ӷ���������
                        //cout<<"chizi"<<Walk_to_pieces[0].height<<endl;
                    }
                    else
                    {
                        if(Walk_to_pieces[0].height<temp.height)  //�жϸ���ĳ������Ƿ��Walk_to_pieces�е����Ӷ�
                        {
                            Walk_to_pieces.clear();    //��ո�����
                            Walk_to_pieces.push_back(temp);  //�������ӷ��뵽Walk_to_pieces��
//cout<<"�ڳ�����1 "<<Walk_to_pieces[0].height<<endl;
                        }
                        else if(Walk_to_pieces[0].height==temp.height)//������ӳ������������б�������һ����
                        {
                            Walk_to_pieces.push_back(temp); //������Ҳ��ӵ�������
//cout<<"�ڳ�����2 "<<Walk_to_pieces[0].height<<endl;
                        }
                    }
                }
            }
        }
    }
}


//�ҳ����ߵ����ӣ���ÿ�����ߵ����Ӳ�����Ӧ���߷�   ��������ǰ�����Ӧ�������߷�
int Skip::CreatePossibleMove(int position[][10],int nSide,int nply)
{
    m_nMoveCount=0;
    //��Ҫ�ߵ����ӷ���������
    Find_Can_Move_Pieces(position,nSide);

    for(int i=0;i<Walk_to_pieces.size();i++)  //���η���Walk_to_pieces��ÿ�����ߵ�����
    {
        //cout<<eatcount(position,Walk_to_pieces[i].x,Walk_to_pieces[i].y)<<endl;
        switch(position[Walk_to_pieces[i].x][Walk_to_pieces[i].y])
        {
            case 1: //�ڱ�
            {
                if(Walk_to_pieces[i].height>0)  //�ڱ��ܳ���
                {
                    //�����ڱ����ӵ��߷�
                    Gen_Pawn_Eat_Move(position,Walk_to_pieces[i].x,Walk_to_pieces[i].y,NULL,Walk_to_pieces[i].height,nply);
                }
                else
                {
                    //cout<<"�ڱ�������"<<endl;
                    //�����ڱ������ӵ��߷�
                    Gen_Black_Pawn_Move(position,Walk_to_pieces[i].x,Walk_to_pieces[i].y,nply);
                }
                break;
            }
            case 2: //�ױ�
            {
                if(Walk_to_pieces[i].height>0) //�ױ��ܳ���
                {
                    //�����ױ������߷�
                    Gen_Pawn_Eat_Move(position,Walk_to_pieces[i].x,Walk_to_pieces[i].y,NULL,Walk_to_pieces[i].height,nply);
                }
                else  //�ױ����ܳ���
                {
                //�����ױ��������߷�
                    Gen_White_Pawn_Move(position,Walk_to_pieces[i].x,Walk_to_pieces[i].y,nply);
                }
                break;
            }
            case 3: //����
            {
                if(Walk_to_pieces[i].height>0)  //��������
                {
                    //�������������߷�
                    Gen_King_Eat_Move(position,Walk_to_pieces[i].x,Walk_to_pieces[i].y,NULL,Walk_to_pieces[i].height,nply);
                }
                else //�������ܳ���
                {
                    //���������������߷�
                    Gen_black_King_Move(position,Walk_to_pieces[i].x,Walk_to_pieces[i].y,nply);
                }
                break;
            }
            case 4:  //����
            {
                if(Walk_to_pieces[i].height>0)  //�����ܳ���
                {
                    //���������������߷�
                    Gen_King_Eat_Move(position,Walk_to_pieces[i].x,Walk_to_pieces[i].y,NULL,Walk_to_pieces[i].height,nply);
                }
                else //�������ܳ���
                {
                    //���������������߷�
                    Gen_white_King_Move(position,Walk_to_pieces[i].x,Walk_to_pieces[i].y,nply);
                }
                break;
            } //case 4������
        }//switch������
	} //���η���Walk_to_pieces��ÿ�����ߵ�����ѭ��������
    return m_nMoveCount;      //�����߷���
}

void Skip::Test_Gen_Black_Pawn_Move()
{
    InitSkip();
    Gen_Black_Pawn_Move(position,8,5,3);
}


//�����ڱ��߷�
void Skip::Gen_Black_Pawn_Move(int position[][10],int x,int y,int nply)
{
    //�ڷ������̵���
    if(x+1<=9&&y-1>=0&&position[x+1][y-1]==EMPTY)
    {
        //cout<<"���¿�"<<endl;
        //�жϸ��������·�λ���Ƿ�Ϸ���Ϊ��
        //�����ýڵ��Ӧ�߷�
        NODE*node1=(NODE*)malloc(sizeof(NODE));
        NODE*node2=(NODE*)malloc(sizeof(NODE));
        node1->parent=node2;
        node1->p1.x=x+1;
        node1->p1.y=y-1;
        node2->parent=NULL;
        node2->p1.x=x;
        node2->p1.y=y;
        node2->p2.x=x;
        node2->p2.y=y;
        m_MoveList[nply][m_nMoveCount++].head=node1;

        //cout<<"�����FROM��"<<node1->parent->p1.x<<" "<<node1->parent->p1.y<<endl;  //node2���
        //cout<<"board[2][4]:"<<position[2][4]<<endl;

        //DisplayBoard(position);
        //cout<<"�����TO�� "<<node1->p1.x<<" "<<node1->p1.y<<endl;
        //�����߷����뵽������
    }
    if(x+1<=9&&y+1<=9&&position[x+1][y+1]==EMPTY)
    {
        //cout<<"���¿�"<<endl;
        //�жϸ���������λ���Ƿ�Ϸ���Ϊ��
        //�����ýڵ��Ӧ�߷�
        NODE*node1=(NODE*)malloc(sizeof(NODE));
        NODE*node2=(NODE*)malloc(sizeof(NODE));
        node1->parent=node2;
        node1->p1.x=x+1;
        node1->p1.y=y+1;
        node2->parent=NULL;
        node2->p1.x=x;
        node2->p1.y=y;
        node2->p2.x=x;
        node2->p2.y=y;
        m_MoveList[nply][m_nMoveCount++].head=node1;
        //cout<<"@@@m_nMoveCount="<<m_nMoveCount<<endl;
        //�����߷����뵽�߷�������
    }
}

//�����ױ��߷�
void Skip::Gen_White_Pawn_Move(int position[][10],int x,int y,int nply)
{
    //�׷������̵���
    if(x-1>=0&&y-1>=0&&position[x-1][y-1]==EMPTY)
    {
        //�жϸ��������Ϸ�λ���Ƿ�Ϸ���Ϊ��
        //�����ýڵ��Ӧ�߷�
        NODE*node1=(NODE*)malloc(sizeof(NODE));
        NODE*node2=(NODE*)malloc(sizeof(NODE));
        node1->parent=node2;
        node1->p1.x=x-1;
        node1->p1.y=y-1;
        node2->parent=NULL;
        node2->p1.x=x;
        node2->p1.y=y;
        node2->p2.x=x;
        node2->p2.y=y;
        m_MoveList[nply][m_nMoveCount++].head=node1;
        //cout<<"�����FROM��"<<node1->parent->p1.x<<" "<<node1->parent->p1.y<<endl;
        //cout<<"�����TO�� "<<node1->p1.x<<" "<<node1->p1.y<<endl;
        //�����߷����뵽������
    }
    if(x-1>=0&&y+1<=9&&position[x-1][y+1]==EMPTY)
    {
        //�жϸ���������λ���Ƿ�Ϸ���Ϊ��
        //�����ýڵ��Ӧ�߷�
        NODE*node1=(NODE*)malloc(sizeof(NODE));
        NODE*node2=(NODE*)malloc(sizeof(NODE));
        node1->parent=node2;
        node1->p1.x=x-1;
        node1->p1.y=y+1;
        node2->parent=NULL;
        node2->p1.x=x;
        node2->p1.y=y;
        node2->p2.x=x;
        node2->p2.y=y;
        m_MoveList[nply][m_nMoveCount++].head=node1;
        //cout<<"�����FROM��"<<node1->parent->p1.x<<" "<<node1->parent->p1.y<<endl;
        //cout<<"�����TO�� "<<node1->p1.x<<" "<<node1->p1.y<<endl;
        //�����߷����뵽�߷�������
    }
}

//��ȷ
int Skip::Gen_Pawn_Eat_Move(int position[10][10],int x,int y,NODE* parentnode,int height,int nply)//�����������߷�
{
    //�ú�����eatcount�����ı���
    int h,h1,h2,h3,h4;            //h1,h2,h3,h4�ֱ�ָ��ǰ�ڵ���ĸ����������ĸ߶�
    int Type1,Type2;  //1����ǰ���ӣ�2�����Ե�������
    int c=can_eat(position,x,y);   //���ܳ��ӵķ���
   // cout<<"x y:"<<x<<y<<endl;
    if(c==1)            //û�����������ӵķ��򼴸ýڵ��Ҷ�ӽڵ�
    {
        //cout<<"Gen over"<<endl;
        if(height==0)
        {
            NODE*node;
            node=(NODE*)malloc(sizeof(NODE));
            node->parent=parentnode;
            node->p1.x=x;
            node->p1.y=y;
            m_MoveList[nply][m_nMoveCount++].head=node;
        }
        return 0;
    }
    if(c%2==0)   //�������·�����ڵ㲢Ϊ������洢�ռ�
    {
        NODE*node=(NODE*)malloc(sizeof(NODE));
        node->parent=parentnode;
        Type1=position[x][y];
        Type2=position[x+1][y-1];
        position[x][y]=EMPTY;
        position[x+1][y-1]=EMPTY;
        position[x+2][y-2]=Type1;
        h1=Gen_Pawn_Eat_Move(position,x+2,y-2,node,height-1,nply);
        //h1=eatcount(position,x+2,y-2);
        //cout<<"h1="<<h1<<endl;
        //������·������߶�
        if(h1==height-1)//�жϵ�ǰ�����ĸ߶��Ƿ�����Ըýڵ�Ϊ���ڵ����ĸ߶�
        {
            //����ýڵ���Ϊ�߷�ϵ�е�һ���ڵ�
            node->p1.x=x;
            node->p1.y=y;
            node->p2.x=x+1;
            node->p2.y=y-1;
            //cout<<"MOVE"<<temp->p1.x<<" "<<temp->p1.y<<endl;
            //cout<<""<<temp->parent->p1.x<<" "<<temp->parent->p1.y<<endl;
            //cout<<"m_nCount="<<m_nMoveCount<<endl;
            //cout<<"�����FROM��"<<node1->parent->p1.x<<" "<<node1->parent->p1.y<<endl;
            //cout<<"�����TO�� "<<node1->p1.x<<" "<<node1->p1.y<<endl;
        }
        else
        {
            free(node);             //������ýڵ㣬���ͷŸ��ڵ���ڴ�
        }
        position[x][y]=Type1;
        position[x+1][y-1]=Type2;           //�ָ�����
        position[x+2][y-2]=EMPTY;
    }
    else
    {
        h1=0;
    }

    if(c%3==0)
    {
        //�������·�����ڵ㲢Ϊ������洢�ռ�
        NODE*node=(NODE*)malloc(sizeof(NODE));
        node->parent=parentnode;
        Type1=position[x][y];
        Type2=position[x+1][y+1];
        position[x][y]=EMPTY;
        position[x+1][y+1]=EMPTY;
        position[x+2][y+2]=Type1;
        h2=Gen_Pawn_Eat_Move(position,x+2,y+2,node,height-1,nply);
        //h2=eatcount(position,x+2,y+2);
        //cout<<"��������h2="<<h2<<endl;
        //cout<<"height="<<height<<endl;
        //������·������߶�
        if(h2==height-1)//�жϵ�ǰ�����ĸ߶��Ƿ�����Ըýڵ�Ϊ���ڵ����ĸ߶�
        {
            //����ýڵ���Ϊ�߷�ϵ�е�һ���ڵ�
            node->p1.x=x;
            node->p1.y=y;
            node->p2.x=x+1;
            node->p2.y=y+1;
        }
        else
        {
            free(node);             //������ýڵ㣬���ͷŸ��ڵ���ڴ�
        }
        position[x][y]=Type1;           //�ָ�����
        position[x+1][y+1]=Type2;
        position[x+2][y+2]=EMPTY;
    }
    else
    {
        h2=0;
    }
    if(c%5==0)
    {   //�������Ϸ�����ڵ㲢Ϊ������洢�ռ�
        NODE*node=(NODE*)malloc(sizeof(NODE));
        node->parent=parentnode;
        Type1=position[x][y];
        Type2=position[x-1][y-1];

        position[x][y]=EMPTY;
        position[x-1][y-1]=EMPTY;
        position[x-2][y-2]=Type1;
        //h3=eatcount(position,x-2,y-2);
        h3=Gen_Pawn_Eat_Move(position,x-2,y-2,node,height-1,nply);
        //cout<<"h3="<<h3<<endl;
        //������Ϸ������߶�
        if(h3==height-1)//�жϵ�ǰ�����ĸ߶��Ƿ�����Ըýڵ�Ϊ���ڵ����ĸ߶�
        {               //����ýڵ���Ϊ�߷�ϵ�е�һ���ڵ�
            node->p1.x=x;
            node->p1.y=y;
            node->p2.x=x-1;
            node->p2.y=y-1;
        }
        else
        {
            free(node);             //������ýڵ㣬���ͷŸ��ڵ���ڴ�
        }
        position[x][y]=Type1;           //�ָ�����
        position[x-1][y-1]=Type2;
        position[x-2][y-2]=EMPTY;
    }
    else
    {
        h3=0;
    }

    if(c%7==0)
    {   //�������Ϸ�����ڵ㲢Ϊ������洢�ռ�
        NODE*node=(NODE*)malloc(sizeof(NODE));
        node->parent=parentnode;
        Type1=position[x][y];
        Type2=position[x-1][y+1];
        position[x][y]=EMPTY;
        position[x-1][y+1]=EMPTY;
        position[x-2][y+2]=Type1;
        //h4=eatcount(position,x-2,y+2);
        h4=Gen_Pawn_Eat_Move(position,x-2,y+2,node,height-1,nply);
        //cout<<"h4="<<h4<<endl;
        //������Ϸ������߶�
        if(h4==height-1)//�жϵ�ǰ�����ĸ߶��Ƿ�����Ըýڵ�Ϊ���ڵ����ĸ߶�
        {               //����ýڵ���Ϊ�߷�ϵ�е�һ���ڵ�
            node->p1.x=x;
            node->p1.y=y;
            node->p2.x=x-1;
            node->p2.y=y+1;
        }
        else
        {
            free(node);             //������ýڵ㣬���ͷŸ��ڵ���ڴ�
        }
        position[x][y]=Type1;           //�ָ�����
        position[x-1][y+1]=Type2;
        position[x-2][y+2]=EMPTY;
    }
    else
    {
        h4=0;
    }
    h=max_h(max_h(max_h(h1,h2),h3),h4);
    //cout<<"h="<<h+1<<endl;
    return h+1;
}

void Skip::Gen_black_King_Move(int position[][10],int x,int y,int nply)
{
    int a=SouthWest(position,x,y);  //����
    int b=SouthEast(position,x,y);  //����
    int d=NorthEast(position,x,y);  //����
    int e=NorthWest(position,x,y);  //����
    //cout<<"a b c d "<<a<<" "<<b<<" "<<d<<" "<<e<<endl;

    //����
    for(int n1=1;n1<=a;n1++)
    {
        if(x+n1<=9&&y-n1>=0&&position[x+n1][y-n1]==EMPTY)
        {
            //�жϸ��������·�λ���Ƿ�Ϸ���Ϊ��
            //�����ýڵ��Ӧ�߷�
            NODE*node1=(NODE*)malloc(sizeof(NODE));
            NODE*node2=(NODE*)malloc(sizeof(NODE));
            node1->parent=node2;
            node1->p1.x=x+n1;
            node1->p1.y=y-n1;
            node2->parent=NULL;
            node2->p1.x=x;
            node2->p1.y=y;
            m_MoveList[nply][m_nMoveCount++].head=node1;
            //�����߷����뵽������
        }
    }
    //����
    for(int n2=1;n2<=b;n2++)
    {
        if(x+n2<=9&&y+n2<=9&&position[x+n2][y+n2]==EMPTY)
        {
            //�жϸ���������λ���Ƿ�Ϸ���Ϊ��
            //�����ýڵ��Ӧ�߷�
            NODE*node1=(NODE*)malloc(sizeof(NODE));
            NODE*node2=(NODE*)malloc(sizeof(NODE));
            node1->parent=node2;
            node1->p1.x=x+n2;
            node1->p1.y=y+n2;
            node2->parent=NULL;
            node2->p1.x=x;
            node2->p1.y=y;
            m_MoveList[nply][m_nMoveCount++].head=node1;//�����߷������߷�������
            //�����߷����뵽�߷�������
        }
    }
    //����
    for(int n3=1;n3<=d;n3++)
    {
        if(x-n3>=0&&y+n3<=9&&position[x-n3][y+n3]==EMPTY)
        {
            //�жϸ���������λ���Ƿ�Ϸ���Ϊ��
            //�����ýڵ��Ӧ�߷�
            NODE*node1=(NODE*)malloc(sizeof(NODE));
            NODE*node2=(NODE*)malloc(sizeof(NODE));
            node1->parent=node2;
            node1->p1.x=x-n3;
            node1->p1.y=y+n3;
            node2->parent=NULL;
            node2->p1.x=x;
            node2->p1.y=y;
            m_MoveList[nply][m_nMoveCount++].head=node1;//�����߷������߷�������
            //�����߷����뵽�߷�������
        }
    }
    //����
    for(int n4=1;n4<=e;n4++)
    {
        if(x-n4>=0&&y-n4>=0&&position[x-n4][y-n4]==EMPTY)
        {
            //�жϸ���������λ���Ƿ�Ϸ���Ϊ��
            //�����ýڵ��Ӧ�߷�
            NODE*node1=(NODE*)malloc(sizeof(NODE));
            NODE*node2=(NODE*)malloc(sizeof(NODE));
            node1->parent=node2;
            node1->p1.x=x-n4;
            node1->p1.y=y-n4;
            node2->parent=NULL;
            node2->p1.x=x;
            node2->p1.y=y;
            m_MoveList[nply][m_nMoveCount++].head=node1;
            //�����߷������߷�������
            //�����߷����뵽�߷�������
        }
    }
}

void Skip::Gen_white_King_Move(int position[10][10],int x,int y,int nply)
{
    int a=SouthWest(position,x,y);
    int b=SouthEast(position,x,y);
    int d=NorthEast(position,x,y);
    int e=NorthWest(position,x,y);
//cout<<"a b c d "<<a<<" "<<b<<" "<<d<<" "<<e<<endl;
//����
    for(int n1=1;n1<=a;n1++)
    {
        if(x+n1<=9&&y-n1>=0&&position[x+n1][y-n1]==EMPTY)
        {
            //�жϸ��������·�λ���Ƿ�Ϸ���Ϊ��
            //�����ýڵ��Ӧ�߷�
            NODE*node1=(NODE*)malloc(sizeof(NODE));
            NODE*node2=(NODE*)malloc(sizeof(NODE));
            node1->parent=node2;
            node1->p1.x=x+n1;
            node1->p1.y=y-n1;
            node2->parent=NULL;
            node2->p1.x=x;
            node2->p1.y=y;

            m_MoveList[nply][m_nMoveCount++].head=node1;
            //�����߷����뵽������
        }
    }
    //����
    for(int n2=1;n2<=b;n2++)
    {
        if(x+n2<=9&&y+n2<=9&&position[x+n2][y+n2]==EMPTY)
        {
            //�жϸ���������λ���Ƿ�Ϸ���Ϊ��
            //�����ýڵ��Ӧ�߷�
            NODE*node1=(NODE*)malloc(sizeof(NODE));
            NODE*node2=(NODE*)malloc(sizeof(NODE));
            node1->parent=node2;
            node1->p1.x=x+n2;
            node1->p1.y=y+n2;
            node2->parent=NULL;
            node2->p1.x=x;
            node2->p1.y=y;
            m_MoveList[nply][m_nMoveCount++].head=node1;//�����߷������߷�������
            //�����߷����뵽�߷�������
        }
    }
    //����
    for(int n3=1;n3<=d;n3++)
    {
        if(x-n3>=0&&y+n3<=9&&position[x-n3][y+n3]==EMPTY)
        {
            //�жϸ���������λ���Ƿ�Ϸ���Ϊ��
            //�����ýڵ��Ӧ�߷�
            NODE*node1=(NODE*)malloc(sizeof(NODE));
            NODE*node2=(NODE*)malloc(sizeof(NODE));
            node1->parent=node2;
            node1->p1.x=x-n3;
            node1->p1.y=y+n3;
            node2->parent=NULL;
            node2->p1.x=x;
            node2->p1.y=y;
            m_MoveList[nply][m_nMoveCount++].head=node1;//�����߷������߷�������
            //�����߷����뵽�߷�������
        }
    }
    //����
    for(int n4=1;n4<=e;n4++)
    {
        if(x-n4>=0&&y-n4>=0&&position[x-n4][y-n4]==EMPTY)
        {
            //�жϸ���������λ���Ƿ�Ϸ���Ϊ��
            //�����ýڵ��Ӧ�߷�
            NODE*node1=(NODE*)malloc(sizeof(NODE));
            NODE*node2=(NODE*)malloc(sizeof(NODE));
            node1->parent=node2;
            node1->p1.x=x-n4;
            node1->p1.y=y-n4;
            node2->parent=NULL;
            node2->p1.x=x;
            node2->p1.y=y;
            m_MoveList[nply][m_nMoveCount++].head=node1;
            //�����߷������߷�������
            //�����߷����뵽�߷�������
        }
    }
}

int Skip::Gen_King_Eat_Move(int position[][10],int x,int y,NODE* parentnode,int height,int nply)//�����������߷�
{
    //�ú�����eatcount�����ı���
    int h,h0,h1=-1000,h2=-1000,h3=-1000,h4=-1000,m1=1,m2=1,m3=1,m4=1;//h1,h2,h3,h4�ֱ�ָ��ǰ�ڵ���ĸ����������ĸ߶�
    int Type1,Type2;          //1����ǰ���ӣ�2�����Ե�������
    int num1,num2; //�ո���
    int i;
    int c=king_can_eat(position,x,y);   //���ܳ��ӵķ���

   // cout<<"height"<<height<<endl;
    if(c==1)            //û�����������ӵķ��򼴸ýڵ��Ҷ�ӽڵ�
    {
        //cout<<"������"<<endl;
        if(height==0)
        {
            NODE*node;
            node=(NODE*)malloc(sizeof(NODE));
            node->parent=parentnode;
            node->p1.x=x;
            node->p1.y=y;
            m_MoveList[nply][m_nMoveCount++].head=node;
        }
        return 0;
    }
    if(c%2==0)   //�������·�����ڵ㲢Ϊ������洢�ռ�
    {
        num1=SouthWest(position,x,y);//��з�����
        num2=SouthWest(position,x+1+num1,y-1-num1);//�к�ո���

        while(m1<=num2)
        {
            Type1=position[x][y];            //���浱ǰ����
            Type2=position[x+1+num1][y-1-num1];
            NODE*node1=(NODE*)malloc(sizeof(NODE));
            node1->parent=parentnode;
            position[x][y]=EMPTY;
            position[x+1+num1][y-1-num1]=TT;
            position[x+1+m1+num1][y-1-m1-num1]=Type1;

            h0=Gen_King_Eat_Move(position,x+1+m1+num1,y-1-m1-num1,node1,height-1,nply);//������·������߶�

            if(h0==height-1)//�жϵ�ǰ�����ĸ߶��Ƿ�����Ըýڵ�Ϊ���ڵ����ĸ߶�
            {
                //����ýڵ���Ϊ�߷�ϵ�е�һ���ڵ�
                node1->p1.x=x;
                node1->p1.y=y;
                node1->p2.x=x+1+num1;
                node1->p2.y=y-1-num1;
                //m_MoveList[nply][m_nMoveCount++].head=node1;
            }
            else
            {
                free(node1);             //������ýڵ㣬���ͷŸ��ڵ���ڴ�
            }
            position[x+1+m1+num1][y-1-m1-num1]=EMPTY;
            position[x][y]=Type1;           //�ָ�����
            position[x+1+num1][y-1-num1]=Type2;
            if(h0>h1)
            {
                h1=h0;
            }
            m1++;
        }
    }//if(c%2==0)������  ����
	else
    {
        h1=0;
    }
    if(c%3==0)   //�������·�����ڵ㲢Ϊ������洢�ռ�
    {
        num1=SouthEast(position,x,y);//��з�����
        num2=SouthEast(position,x+1+num1,y+1+num1);//�к�ո���

        while(m2<=num2)
        {
            Type1=position[x][y];            //���浱ǰ����
            Type2=position[x+1+num1][y+1+num1];
            NODE*node2=(NODE*)malloc(sizeof(NODE));
            node2->parent=parentnode;
            position[x][y]=EMPTY;
            position[x+1+num1][y+1+num1]=TT;
            position[x+1+m2+num1][y+1+m2+num1]=Type1;
            h0=Gen_King_Eat_Move(position,x+1+m2+num1,y+1+m2+num1,node2,height-1,nply);//������·������߶�
            if(h0==height-1)//�жϵ�ǰ�����ĸ߶��Ƿ�����Ըýڵ�Ϊ���ڵ����ĸ߶�
            {
                //����ýڵ���Ϊ�߷�ϵ�е�һ���ڵ�
                node2->p1.x=x;
                node2->p1.y=y;
                node2->p2.x=x+1+num1;
                node2->p2.y=y+1+num1;
            }
            else
            {
                free(node2);             //������ýڵ㣬���ͷŸ��ڵ���ڴ�
            }
            position[x+1+m2+num1][y+1+m2+num1]=EMPTY;
            position[x][y]=Type1;           //�ָ�����
            position[x+1+num1][y+1+num1]=Type2;
            if(h0>h2)
            {
                h2=h0;
            }
            m2++;
        }
    } //if(c%3==0)������
	else
    {
        h2=0;
    }
    if(c%5==0)   //�������Ϸ�����ڵ㲢Ϊ������洢�ռ�
    {
        num1=NorthWest(position,x,y);//��з�����
        num2=NorthWest(position,x-1-num1,y-1-num1);//�к�ո���

        while(m3<=num2)
        {
            Type1=position[x][y];            //���浱ǰ����
            Type2=position[x-1-num1][y-1-num1];
            NODE*node3=(NODE*)malloc(sizeof(NODE));
            node3->parent=parentnode;
            position[x][y]=EMPTY;
            position[x-1-num1][y-1-num1]=TT;
            position[x-1-m3-num1][y-1-m3-num1]=Type1;
            h0=Gen_King_Eat_Move(position,x-1-m3-num1,y-1-m3-num1,node3,height-1,nply);//������·������߶�
            if(h0==height-1)//�жϵ�ǰ�����ĸ߶��Ƿ�����Ըýڵ�Ϊ���ڵ����ĸ߶�
            {
                //����ýڵ���Ϊ�߷�ϵ�е�һ���ڵ�
                node3->p1.x=x;
                node3->p1.y=y;
                node3->p2.x=x-1-num1;
                node3->p2.y=y-1-num1;
                //m_MoveList[nply][m_nMoveCount++].head=node3;
            }
            else
            {
                free(node3);             //������ýڵ㣬���ͷŸ��ڵ���ڴ�
            }
            position[x-1-m3-num1][y-1-m3-num1]=EMPTY;
            position[x][y]=Type1;           //�ָ�����
            position[x-1-num1][y-1-num1]=Type2;
            if(h0>h3)
            {
                h3=h0;
            }
            m3++;
        }
    }//if(c%5==0)
	else
    {
        h3=0;
    }
    if(c%7==0)   //�������Ϸ�����ڵ㲢Ϊ������洢�ռ�
    {
        //cout<<"�����ܳ�"<<endl;
        //cout<<"����height"<<height<<endl;
        num1=NorthEast(position,x,y);//��з�����  û��
        num2=NorthEast(position,x-1-num1,y+1+num1);//�к�ո���  û��

        //cout<<"���Ͼ��룬�к�"<<num1<<" "<<num2<<endl;
        while(m4<=num2)
        {
            Type1=position[x][y];            //���浱ǰ����
            Type2=position[x-1-num1][y+1+num1];
            NODE*node4=(NODE*)malloc(sizeof(NODE));
            node4->parent=parentnode;
            position[x][y]=EMPTY;
            position[x-1-num1][y+1+num1]=TT;
            position[x-1-m4-num1][y+1+m4+num1]=Type1;
            h0=Gen_King_Eat_Move(position,x-1-m4-num1,y+1+m4+num1,node4,height-1,nply);//������·������߶�

            if(h0==height-1)//�жϵ�ǰ�����ĸ߶��Ƿ�����Ըýڵ�Ϊ���ڵ����ĸ߶�
            {
                //����ýڵ���Ϊ�߷�ϵ�е�һ���ڵ�
                node4->p1.x=x;
                node4->p1.y=y;
                node4->p2.x=x-1-num1;
                node4->p2.y=y+1+num1;
                //m_MoveList[nply][m_nMoveCount++].head=node4;
            }
            else
            {
                free(node4);             //������ýڵ㣬���ͷŸ��ڵ���ڴ�
            }
            position[x-1-m4-num1][y+1+m4+num1]=EMPTY;
            position[x][y]=Type1;           //�ָ�����
            position[x-1-num1][y+1+num1]=Type2;
            if(h0>h4)
            {
                h4=h0;
            }
            m4++;
        }
    }//if(c%7==0)
	else
    {
        h4=0;
    }
    h=max_h( max_h(max_h(h1,h2),h3),h4 );

    return h+1;
}


//��ȷ
//����ͨ���ӵĳ�����
int Skip::eatcount(int position [][10],int i,int j)
{
    int h,h1,h2,h3,h4;//h��ǰ�ڵ�߶ȣ�h1���������߶ȣ�h2���������߶ȣ�h3���������߶ȣ�h4���������߶�
    int Type1,Type2;//Type1--��ǰ���ӣ�Type2--����������
    int curposition[10][10];
    for(int a=0;a<10;a++)
    {
        for(int b=0;b<10;b++)
        {
            curposition[a][b]=position[a][b];
        }
    }
    int c=can_eat(curposition,i,j);  //����ܳ��ӵķ���


    if(c==1)  //û�������Եķ���
    {
        return 0;    //���������߶�Ϊ0
    }
    else
    {
        if(c%2==0)    //����������
        {
            Type1=curposition[i][j];            //���浱ǰ����
            Type2=curposition[i+1][j-1];
            curposition[i][j]=EMPTY;           //��������
            curposition[i+1][j-1]=EMPTY;
            curposition[i+2][j-2]=Type1;       //���Ժ����
            h1=eatcount(curposition,i+2,j-2);  //�������Ժ�����������

            curposition[i+2][j-2]=EMPTY;
            curposition[i+1][j-1]=Type2;
            curposition[i][j]=Type1;          //�ָ�����
        }
        else
        {
            h1=0;
        }
        if(c%3==0)    //����������
        {
            Type1=curposition[i][j];            //���浱ǰ����
            Type2=curposition[i+1][j+1];
            curposition[i][j]=EMPTY;           //��������
            curposition[i+1][j+1]=EMPTY;
            curposition[i+2][j+2]=Type1;       //���Ժ����
            h2=eatcount(curposition,i+2,j+2);  //�������Ժ�����������

            curposition[i][j]=Type1;          //�ָ�����
            curposition[i+1][j+1]=Type2;
            curposition[i+2][j+2]=EMPTY;
        }
        else//���·�û������
        {
            h2=0;
        }
        if(c%5==0)   //����������
        {
            Type1=curposition[i][j];            //���浱ǰ����
            Type2=curposition[i-1][j-1];
            curposition[i][j]=EMPTY;           //��������
            curposition[i-1][j-1]=EMPTY;
            curposition[i-2][j-2]=Type1;       //���Ժ����
            h3=eatcount(curposition,i-2,j-2);  //�������Ժ�����������

            curposition[i][j]=Type1;          //�ָ�����
            curposition[i-1][j-1]=Type2;
            curposition[i-2][j-2]=EMPTY;
        }
        else
        {
            h3=0;
        }
        if(c%7==0)   //����������
        {
            Type1=curposition[i][j];            //���浱ǰ����
            Type2=curposition[i-1][j+1];
            curposition[i][j]=EMPTY;           //��������
            curposition[i-1][j+1]=EMPTY;
            curposition[i-2][j+2]=Type1;       //���Ժ����
            h4=eatcount(curposition,i-2,j+2);  //�������Ժ�����������

            curposition[i][j]=Type1;          //�ָ�����
            curposition[i-1][j+1]=Type2;
            curposition[i-2][j+2]=EMPTY;
        }
        else
        {
            h4=0;
        }
    }
    h=max_h( max_h(max_h(h1,h2),h3) ,h4); // h=h1,h2,h3,h4���ֵ
    //cout<<"chizishu: "<<h+1<<endl;
    return h+1;
}

//�����ĳ�����
int Skip::king_eatcount(int position[][10],int i,int j)
{
    int h,h0,h1=-1000,h2=-1000,h3=-1000,h4=-1000,m1=1,m2=1,m3=1,m4=1;//h��ǰ�ڵ�߶ȣ�h1���������߶ȣ�h2���������߶ȣ�h3���������߶ȣ�h4���������߶�
    int Type1,Type2;//Type1--��ǰ���ӣ�Type2--����������
    int c=king_can_eat(position,i,j);  //����ܳ��ӵķ���

    int H1,H2,H3,H4;//�к�ո���
    int leftdown,leftup,rightdown,rightup;

    leftdown=SouthWest(position,i,j);//����
    leftup=NorthWest(position,i,j);//����

    rightup=NorthEast(position,i,j);//����
    rightdown=SouthEast(position,i,j);//����

    if(c==1)  //û�������Եķ���
    {
        return 0;    //���������߶�Ϊ0
    }
    if(c%2==0)    //����������
    {
        H1=SouthWest(position,i+1+leftdown,j-1-leftdown);
        while(m1<=H1)
        {
            Type1=position[i][j];            //���浱ǰ����
            Type2=position[i+1+leftdown][j-(1+leftdown)];
            position[i][j]=EMPTY;           //��������
            position[i+1+leftdown][j-(1+leftdown)]=TT;
            position[i+1+m1+leftdown][j-(1+m1+leftdown)]=Type1;       //���Ժ����

            h0=king_eatcount(position,i+1+m1+leftdown,j-(1+m1+leftdown));  //�������Ժ�����������

            position[i][j]=Type1;          //�ָ�����
            position[i+1+leftdown][j-(1+leftdown)]=Type2;
            position[i+1+m1+leftdown][j-(1+m1+leftdown)]=EMPTY;
            if(h1<h0)
            {
                h1=h0;
            }
            m1++;
        }
    }
    else
    {
        h1=0;
    }
    if(c%3==0)    //����������
    {
        H2=SouthEast(position,i+1+rightdown,j+1+rightdown);
        while(m2<=H2)
        {
            Type1=position[i][j];            //���浱ǰ����
            Type2=position[i+1+rightdown][j+1+rightdown];
            position[i][j]=EMPTY;           //��������
            position[i+1+rightdown][j+1+rightdown]=TT;

            position[i+1+m2+rightdown][j+1+m2+rightdown]=Type1;       //���Ժ����

            h0=king_eatcount(position,i+1+m2+rightdown,j+1+m2+rightdown);  //�������Ժ�����������

            position[i][j]=Type1;          //�ָ�����
            position[i+1+rightdown][j+1+rightdown]=Type2;
            position[i+1+m2+rightdown][j+1+m2+rightdown]=EMPTY;
            if(h2<h0)
            {
                h2=h0;
            }
            m2++;
        }

    }
    else   //���·�û������
    {
        h2=0;
    }
    if(c%5==0)   //����������
    {

        H3=NorthWest(position,i-1-leftup,j-1-leftup);
//cout<<"H3 "<<H3<<endl;
        while(m3<=H3)
        {

            Type1=position[i][j];            //���浱ǰ����
            Type2=position[i-1-leftup][j-1-leftup];
            position[i][j]=EMPTY;           //��������
            position[i-1-leftup][j-1-leftup]=TT;

            position[i-1-m3-leftup][j-1-m3-leftup]=Type1;       //���Ժ����

            h0=king_eatcount(position,i-1-m3-leftup,j-1-m3-leftup);  //�������Ժ�����������

            position[i][j]=Type1;          //�ָ�����
            position[i-1-leftup][j-1-leftup]=Type2;
            position[i-1-m3-leftup][j-1-m3-leftup]=EMPTY;
            if(h3<h0)
            {
                h3=h0;
            }
            m3++;
        }
    }
    else
    {
        h3=0;
    }
    if(c%7==0)   //����������
    {
        H4=NorthEast(position,i-1-rightup,j+1+rightup);
        while(m4<=H4)
        {
            Type1=position[i][j];            //���浱ǰ����
            Type2=position[i-1-rightup][j+1+rightup];
            position[i][j]=EMPTY;           //��������
            position[i-1-rightup][j+1+rightup]=TT;

            position[i-1-m4-rightup][j+1+m4+rightup]=Type1;       //���Ժ����

            h0=king_eatcount(position,i-1-m4-rightup,j+1+m4+rightup);  //������������������

            position[i][j]=Type1;          //�ָ�����
            position[i-1-rightup][j+1+rightup]=Type2;
            position[i-1-m4-rightup][j+1+m4+rightup]=EMPTY;
            if(h4<h0)
            {
                h4=h0;
            }
            m4++;
        }
    }
    else
    {
        h4=0;
    }
    h=max_h( max_h(max_h(h1,h2), h3) ,h4); // h=h1,h2,h3,h4���ֵ
    return h+1;
}

//��������ӵķ���
int Skip::can_eat(int position[][10],int i,int j)
{
    int value=1;
    if(position[i][j]%2==1)      //����
    {
        if((i+2<10)&&(j-2>=0)&& ( position[i+1][j-1]==2 || position[i+1][j-1]==4 )&&(position[i+2][j-2]==EMPTY) ) //�ж����·���������
        {
            value=value*2;     //��¼���·������Ե�״̬
        }
        if((i+2<10)&&(j+2<10)&&( position[i+1][j+1]==2 || position[i+1][j+1]==4 ) &&(position[i+2][j+2]==EMPTY))  //�ж����·���������
        {
            value=value*3;     //��¼���·������Ե�״̬
        }
        if(i-2>=0&&j-2>=0&&( position[i-1][j-1]==2 || position[i-1][j-1]==4 )&&(position[i-2][j-2]==EMPTY))  //�ж����Ϸ���������
        {
            value=value*5;     //��¼���Ϸ������Ե�״̬
        }
        if(i-2>=0&&j+2<10&&( position[i-1][j+1]==2 || position[i-1][j+1]==4 )&&(position[i-2][j+2]==EMPTY))  //�ж����Ϸ���������
        {
            value=value*7;     //��¼���Ϸ������Ե�״̬
        }
    }
    else if(position[i][j]%2==0)   //����  �·�
    {

        if((i+2<10)&&(j-2>=0)&& ( position[i+1][j-1]==1 || position[i+1][j-1]==3 )&&(position[i+2][j-2]==EMPTY) ) //�ж����·���������
        {
            value=value*2;     //��¼���·������Ե�״̬
        }
        if((i+2<10)&&(j+2<10)&&( position[i+1][j+1]==1 || position[i+1][j+1]==3 ) &&(position[i+2][j+2]==EMPTY))  //�ж����·���������
        {
            value=value*3;     //��¼���·������Ե�״̬
        }
        if(i-2>=0&&j-2>=0&&( position[i-1][j-1]==1|| position[i-1][j-1]==3 )&&(position[i-2][j-2]==EMPTY))  //�ж����Ϸ���������
        {
            value=value*5;     //��¼���Ϸ������Ե�״̬
        }
        if(i-2>=0&&j+2<10&&( position[i-1][j+1]==1 || position[i-1][j+1]==3 )&&(position[i-2][j+2]==EMPTY))  //�ж����Ϸ���������
        {
            value=value*7;     //��¼���Ϸ������Ե�״̬
        }
    }
    return value;
}

//��������ӵķ���
int Skip::king_can_eat(int position[][10],int i,int j)
{
    int value=1;
    if(position[i][j]==3)   //����
    {
        int a=SouthWest(position,i,j);//����
        int b=SouthEast(position,i,j);//����

        int d=NorthWest(position,i,j);//����
        int e=NorthEast(position,i,j);//����


 //cout<<"a b d e "<<a<<" "<<b<<" "<<d<<" "<<e<<endl;

        //�ж����·���������
        if(i+2+a<10 && j-(2+a)>=0 && ( position[i+1+a][j-(1+a)]==2 || position[i+1+a][j-(1+a)]==4 ) && position[i+2+a][j-(2+a)]==EMPTY )
        {
            value=value*2;    //��¼���·������Ե�״̬
        }
        //�ж����·���������
        if(i+2+b<10 && j+2+b<10 && ( position[i+1+b][j+1+b]==2 || position[i+1+b][j+1+b]==4 ) && position[i+2+b][j+2+b]==EMPTY )
        {
            value=value*3;     //��¼���·������Ե�״̬
        }
        //�ж����Ϸ���������
        if(i-(2+d)>=0 && j-(2+d)>=0 && ( position[i-(1+d)][j-(1+d)]==2 || position[i-(1+d)][j-(1+d)]==4 ) && position[i-(2+d)][j-(2+d)]==EMPTY )
        {
            value=value*5;     //��¼���Ϸ������Ե�״̬
        }
        //�ж����Ϸ���������   //�����д�
        if(i-(2+e)>=0 && j+2+e<10 && ( position[i-(1+e)][j+1+e]==2 || position[i-(1+e)][j+1+e]==4 ) && position[i-(2+e)][j+2+e]==EMPTY )
        {
            value=value*7;     //��¼���Ϸ������Ե�״̬
        }
    }
    if(position[i][j]==4)    //����
    {
        int a=SouthWest(position,i,j);//����
        int b=SouthEast(position,i,j);//����

        int d=NorthWest(position,i,j);//����
        int e=NorthEast(position,i,j);//����

        //�ж����·���������
        if(i+2+a<10 && j-(2+a)>=0 && ( position[i+1+a][j-(1+a)]==1 || position[i+1+a][j-(1+a)]==3 ) && position[i+2+a][j-(2+a)]==EMPTY )
        {
            value=value*2;    //��¼���·������Ե�״̬
        }
        //�ж����·���������
        if(i+2+b<10 && j+2+b<10 && ( position[i+1+b][j+1+b]==1 || position[i+1+b][j+1+b]==3 ) && position[i+2+b][j+2+b]==EMPTY )
        {
            value=value*3;     //��¼���·������Ե�״̬
        }
        //�ж����Ϸ���������
        if(i-(2+d)>=0 && j-(2+d)>=0 && ( position[i-(1+d)][j-(1+d)]==1 || position[i-(1+d)][j-(1+d)]==3 ) && position[i-(2+d)][j-(2+d)]==EMPTY )
        {
            value=value*5;     //��¼���Ϸ������Ե�״̬
        }
        //�ж����Ϸ���������
        if(i-(2+e)>=0 && j+2+e<10 && ( position[i-(1+e)][j+1+e]==1 || position[i-(1+e)][j+1+e]==3 ) && position[i-(2+e)][j+2+e]==EMPTY )
        {
            value=value*7;     //��¼���Ϸ������Ե�״̬
        }
    }
    return value;
}

//�������Ϸ���Ŀո���
int Skip::NorthWest(int position[][10],int x,int y)
{
    int i;
    //�ж���������ϽǷ����м����ո�
    for(i=1;i<=min_h(x,y);i++)
    {
       if (position [x-i][y-i]!=EMPTY)
        {
            return i-1;
        }
        else
        {
            continue;
        }
    }
    return i-1;
}

//�������Ϸ���Ŀո���
int Skip::NorthEast(int position[][10],int x,int y)
{
    int i;
    //�ж���������ϽǷ����м����ո�
    for(i=1;i<=min_h(x,9-y);i++)
    {
        if (position [x-i][y+i]!=EMPTY)
        {
            return i-1;
        }
        else
        {
            continue;
        }

    }
    return i-1;
}

//�������·���Ŀո���
int Skip::SouthWest(int position[][10],int x,int y)
{
    int i;
    //�ж���������½Ƿ����м����ո�
    for(i=1;i<=min_h(9-x,y);i++)
    {
        if (position [x+i][y-i]!=EMPTY)
        {
            return i-1;
        }
        else
        {
            continue;
        }

    }
    return i-1;
}

//�������·���Ŀո���
int Skip::SouthEast(int position[][10],int x,int y)
{
    int i;
    //�ж���������½Ƿ����м����ո�
    for(i=1;i<=min_h(9-x,9-y);i++)
    {
        if (position [x+i][y+i]!=EMPTY)
        {
            return i-1;
        }
        else
        {
            continue;
        }
    }
    return i-1;
}

double Skip::Alphabetasearch(int depth,int side,int alpha,int beta)
{
    int count,value;

	int curposition[10][10];  //��ʱ����
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            curposition[i][j]=position[i][j];
        }
    }

    if(isGameOver()) //Game over!!!
    {
        if(side==isWin())
        {
            return 10000;
        }
        else
        {
            return -10000;
        }

    }

    if(depth==0)  //Ҷ�ӽڵ�
    {
        value=Value(position,side);
        return value;
    }
    count=CreatePossibleMove(position,side,depth);

    if(depth>0)
    {
        for(int i=0;i<count;i++)
        {
            if(Walk_to_pieces[0].height==0)	//�ƶ�
            {
                int Type1=position[m_MoveList[depth][i].head->parent->p1.x][m_MoveList[depth][i].head->parent->p1.y];
                if(m_MoveList[depth][i].head->p1.x==9&&side==1)
                {
                    position[m_MoveList[depth][i].head->p1.x][m_MoveList[depth][i].head->p1.y]=BLACKKING;
                }
                if(m_MoveList[depth][i].head->p1.x!=9&&side==1)
                {
                    position[m_MoveList[depth][i].head->p1.x][m_MoveList[depth][i].head->p1.y]=Type1;
                }
                if(m_MoveList[depth][i].head->p1.x==0&&side==-1)
                {
                    position[m_MoveList[depth][i].head->p1.x][m_MoveList[depth][i].head->p1.y]==WHITEKING;
                }
                if(m_MoveList[depth][i].head->p1.x!=0&&side==-1)
                {
                    position[m_MoveList[depth][i].head->p1.x][m_MoveList[depth][i].head->p1.y]=Type1;
                }
                position[m_MoveList[depth][i].head->parent->p1.x][m_MoveList[depth][i].head->parent->p1.y]=EMPTY;
                value = -Alphabetasearch(depth-1,-side,-beta,-alpha);
                //��������
                for(int i=0;i<10;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        position[i][j]=curposition[i][j];
                    }
                }
            }//height=0������
            else		//����
            {
                int Type;
                for(NODE*cnode=m_MoveList[depth][i].head->parent;;cnode=cnode->parent)
                {
                    if(cnode->parent==NULL)
                    {
                        Type = position[cnode->p1.x][cnode->p1.y];
                        position[cnode->p1.x][cnode->p1.y]=EMPTY;
                        position[cnode->p2.x][cnode->p2.y]=EMPTY;
                        if(m_MoveList[depth][i].head->p1.x==9&&side==1)
                        {
                            position[m_MoveList[depth][i].head->p1.x][m_MoveList[depth][i].head->p1.y]=BLACKKING;
                        }
                        if(m_MoveList[depth][i].head->p1.x!=9&&side==1)
                        {
                            position[m_MoveList[depth][i].head->p1.x][m_MoveList[depth][i].head->p1.y]=Type;
                        }
                        if(m_MoveList[depth][i].head->p1.x==0&&side==-1)
                        {
                            position[m_MoveList[depth][i].head->p1.x][m_MoveList[depth][i].head->p1.y]==WHITEKING;
                        }
                        if(m_MoveList[depth][i].head->p1.x!=0&&side==-1)
                        {
                            position[m_MoveList[depth][i].head->p1.x][m_MoveList[depth][i].head->p1.y]=Type;
                        }
                        break;
                    }
                    if(cnode->parent!=NULL)
                    {
                        position[cnode->p1.x][cnode->p1.y]=EMPTY;
                        position[cnode->p2.x][cnode->p2.y]=EMPTY;
//continue;
                    }
                }//for
                value = -Alphabetasearch(depth-1,-side,-beta,-alpha);
				//��������
                for(int i=0;i<10;i++)
                {
                    for(int j=0;j<10;j++)
                    {
                        position[i][j]=curposition[i][j];
                    }
                }
            }//height>0������


            if(value>alpha)
            {
                alpha=value;
				if(depth==Depth)
                {
					BestMove=m_MoveList[depth][i];//����ǰ�߷���Ϊ����߷�
                }
            }
           	if(alpha>=beta)
			{
				return alpha;   //����beta��֦
            }
    	}//�����߷�
	}//depth>0
    return alpha;
}


//���������ֵ
double Skip::Eval(int position[][10],int side)
{
    double x1,x2,x3,x4;

    double bAveGrade,wAveGrade;

    int white_pawn=0;  //�ױ�����
    int white_queen=0;  //��������
    int black_pawn=0;  //�ڱ�����
    int black_queen=0;  //��������
    int Em;    //em�������������Ĺ�ֵ

    int Bet=0;  //�ڷ��Ľ���ƽ������
    int Wet=0;  //�׷��Ľ���ƽ������
    int Et=0;   //��ǰ���̵Ľ���ƽ�����ӵĹ�ֵ

    int Wc=0;   //�������м�λ�����ӵĸ���
    int Bc=0;   //�������м�λ�����ӵĸ���
    int Ec=0;   //�����м�λ�����������Ĺ�ֵ

    int Wg=0;   //�׷�������
    int Bg=0;   //�ڷ�������
    int Eg=0;   //�����Ĺ�ֵ

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            switch (position[i][j])
            {
                case 1:  //�ڱ�
                {
                    black_pawn++;  //�ڱ�����+1
                    Bet+=(i+1);   //��ڷ�����ƽ������
					//�ж��Ƿ�����������
                    if(i>=2&&i<=7&&j>=2&&j<=7)
                    {
                        Bc++;   //�������м�λ��������+1
                    }
					//�жϵ�ǰ�����Ƿ񹹳���б����
                    if(i+3<=9&&j-3>=0&&position[i+1][j-1]==position[i][j]&&position[i+2][j-2]==position[i][j]&&position[i+3][j-3]==position[i][j])
                    {
                        Bg++;  //�ڷ�����+1
                    }
					//�жϵ�ǰ�����Ƿ񹹳���б����
                    if(i+3<=9&&j+3<=9&&position[i+1][j+1]==position[i][j]&&position[i+2][j+2]==position[i][j]&&position[i+3][j+3]==position[i][j])
                    {
                        Bg++;   //�ڷ�����+1
                    }
                    break;
                }
                case 2:	//�ױ�
                {
                    white_pawn++;		//�ױ�����+1
                    Wet+=(10-i);	//��׷�����ƽ������

                    if(i>=2&&i<=7&&j>=2&&j<=7)
                    {
                        Wc++;	//�������м�λ��������+1
                    }
					//�жϵ�ǰ�����Ƿ񹹳���б����
                    if(i+3<=9&&j-3>=0&&position[i+1][j-1]==position[i][j]&&position[i+2][j-2]==position[i][j]&&position[i+3][j-3]==position[i][j])
                    {
                        Wg++;	//�׷�����+1
                    }
					//�жϵ�ǰ�����Ƿ񹹳���б����
                    if(i+3<=9&&j+3<=9&&position[i+1][j+1]==position[i][j]&&position[i+2][j+2]==position[i][j]&&position[i+3][j+3]==position[i][j])
                    {
                        Wg++;	//�׷�����+1
                    }
				    break;
                }
                case 3:	//����
                {
                    black_queen++;		//��������+1
                    Bet+=(i+1);		//��ڷ�����ƽ������
                    //�ж��Ƿ�����������
                    if(i>=2&&i<=7&&j>=2&&j<=7)
                    {
                        Bc++;		//�������м�λ��������+1
                    }
                    //�жϵ�ǰ�����Ƿ񹹳���б����
                    if(i+3<=9&&j-3>=0&&position[i+1][j-1]==position[i][j]&&position[i+2][j-2]==position[i][j]&&position[i+3][j-3]==position[i][j])
                    {
                        Bg++;		//�ڷ�����+1
                    }
                    //�жϵ�ǰ�����Ƿ񹹳���б����
                    if(i+3<=9&&j+3<=9&&position[i+1][j+1]==position[i][j]&&position[i+2][j+2]==position[i][j]&&position[i+3][j+3]==position[i][j])
                    {
                        Bg++;		//�ڷ�����+1
                    }
                    break;
                }
                case 4: //����
                {
                    white_queen++;	//��������+1
                    Wet+=(10-i);	//��׷�����ƽ������
                    if(i>=2&&i<=7&&j>=2&&j<=7)
                    {
                        Wc++;	//�������м�λ��������+1
                    }
                    //�жϵ�ǰ�����Ƿ񹹳���б����
                    if(i+3<=9&&j-3>=0&&position[i+1][j-1]==position[i][j]&&position[i+2][j-2]==position[i][j]&&position[i+3][j-3]==position[i][j])
                    {
                        Wg++;	//�׷�����+1
                    }
                    //�жϵ�ǰ�����Ƿ񹹳���б����
                    if(i+3<=9&&j+3<=9&&position[i+1][j+1]==position[i][j]&&position[i+2][j+2]==position[i][j]&&position[i+3][j+3]==position[i][j])
                    {
                        Wg++;	//�׷�����+1
                    }
					break;
                }//case 4������
			}//switch������
        }//forѭ��j
    }//forѭ��i
    if(side==1)   //�ڷ�
    {
        bAveGrade=Bet/(black_pawn+black_queen);

        Em=(black_pawn-white_pawn)+30*(black_queen-white_queen); //�����������������Ĺ�ֵ

        if(bAveGrade<3)
        {
            Ec=Bc-Wc; //���������м�λ�����������Ĺ�ֵ
            Eg=Bg-Wg; //���������Ĺ�ֵ
            Et=Bet-Wet;  //��ǰ���̵Ľ���ƽ�����ӵĹ�ֵ,ӦΪ�ֶκ���
            return (10.0*Em+8.0*Et+3.0*Ec+20.0*Eg); //����Ҫ�Ż�
        }
        if(bAveGrade>=3&&bAveGrade<4)
        {
            Ec=Bc-Wc; //���������м�λ�����������Ĺ�ֵ
            Eg=Bg-Wg; //���������Ĺ�ֵ
            Et=0;
            return (30.0*Em+8.0*Et+3.0*Ec+50.0*Eg); //����Ҫ�Ż�
        }
        if(bAveGrade>=4)
        {
            Ec=Bc-Wc; //���������м�λ�����������Ĺ�ֵ
            Eg=Bg-Wg; //���������Ĺ�ֵ
            Et=Wet-Bet;
            return (50.0*Em+30.0*Et+3.0*Ec+10.0*Eg); //����Ҫ�Ż�
        }
    }
    else if(side==-1)  //�׷�
    {
        wAveGrade=Wet/(white_pawn+white_queen);

        Em=(white_pawn-black_pawn)+30*(white_queen-black_queen); //�����������������Ĺ�ֵ

        if(wAveGrade<3)
        {
            Ec=Wc-Bc; //���������м�λ�����������Ĺ�ֵ
            Eg=Wg-Bg; //���������Ĺ�ֵ
            Et=Wet-Bet;  //��ǰ���̵Ľ���ƽ�����ӵĹ�ֵ,ӦΪ�ֶκ���
            return (10.0*Em+8.0*Et+3.0*Ec+20.0*Eg); //����Ҫ�Ż�
        }
        if(wAveGrade>=3&&wAveGrade<4)
        {
            Ec=Wc-Bc; //���������м�λ�����������Ĺ�ֵ
            Eg=Wg-Bg; //���������Ĺ�ֵ
            Et=0;
            return (30.0*Em+8.0*Et+3.0*Ec+50.0*Eg); //����Ҫ�Ż�
        }
        if(wAveGrade>=4)
        {
            Ec=Wc-Bc; //���������м�λ�����������Ĺ�ֵ
            Eg=Wg-Bg; //���������Ĺ�ֵ
            Et=Bet-Wet;
            return (50.0*Em+30.0*Et+3.0*Ec+10.0*Eg); //����Ҫ�Ż�
        }
    }


}//��������


//��ֵ����
double Skip::Value(int position[][10],int side)
{
	int wp=0;	//�ױ�����
	int wk=0;	//��������
	int bp=0;	//�ڱ�����
	int bk=0;	//��������
	int em=0;	//����

	int bt=0;	//����ƽ������
	int wt=0;	//����ƽ������
	int et=0;	//����ƽ������

	int wc=0;	//�����м����
	int bc=0;	//�����м����
	int ec=0;	//�м�����

	int wg=0;	//������
	int bg=0;	//������
	int eg=0;	//��

	int wh=0;
	int bh=0;
	int eh=0;

	for(int i=0;i<10;i++)
    {
		for(int j=0;j<10;j++)
		{
			switch(position[i][j])
			{
			case BLACKCHESS:  //����
				bp++;
				bt=bt+(i+1);
				if(i>=2 && i<=7 && j>=2 && j<=7)
				{
					bc++;
				}
				if(i+2<10 && j-2>=0 && position[i][j]==position[i+1][j-1] && position[i][j]==position[i+2][j-2])
				{//����
					bg++;
				}
				if(i+2<10 && j+2<10 && position[i][j]==position[i+1][j+1] && position[i][j]==position[i+2][j+2])
				{//����
					bg++;
				}
				break;
			case WHITECHESS:    //
				wp++;
				wt=wt+(10-i);
				if(i>=2 && i<=7 && j>=2 && j<=7)
				{
					wc++;
				}
				if(i-2>=0 && j-2>=0 && position[i][j]==position[i-1][j-1] && position[i][j]==position[i-2][j-2])
				{//����
					wg++;
				}
				if(i-2>=0 && j+2>=0 && position[i][j]==position[i-1][j+1] && position[i][j]==position[i-2][j+2])
				{//����
					wg++;
				}
				break;
			case BLACKKING:
				bk++;
				bt=bt+(i+1);
				if(i>=2 && i<=7 && j>=2 && j<=7)
				{
					bc++;
				}
				if(i+2<10 && j-2>=0 && position[i][j]==position[i+1][j-1] && position[i][j]==position[i+2][j-2])
				{//����
					bg++;
				}
				if(i+2<10 && j+2<10 && position[i][j]==position[i+1][j+1] && position[i][j]==position[i+2][j+2])
				{//����
					bg++;
				}
				break;
			case WHITEKING:
				wk++;
				wt=wt+(10-i);
				if(i>=2 && i<=7 && j>=2 && j<=7)
				{
					wc++;
				}
				if(i-2>=0 && j-2>=0 && position[i][j]==position[i-1][j-1] && position[i][j]==position[i-2][j-2])
				{//����
					wg++;
				}
				if(i-2>=0 && j+2>=0 && position[i][j]==position[i-1][j+1] && position[i][j]==position[i-2][j+2])
				{//����
					wg++;
				}
				break;
			}
		}
		if(i%2==0)
        {
            if(position[i][1]%2==position[i][3]%2==position[i][5]%2==position[i][7]%2==position[i][9]%2==1)
            {
                bh++;
            }
            if(position[i][1]%2==position[i][3]%2==position[i][5]%2==position[i][7]%2==position[i][9]%2==0)
            {
                wh++;
            }

        }
        else if(i%2==1)
        {
            if(position[i][0]%2==position[i][2]%2==position[i][4]%2==position[i][6]%2==position[i][8]%2==1)
            {
                bh++;
            }
            if(position[i][0]%2==position[i][2]%2==position[i][4]%2==position[i][6]%2==position[i][8]%2==0)
            {
                wh++;
            }
        }

	}

	if (side==1)  //��������
    {
		int bt_ave=bt/(bp+bk);
		int wt_ave=wt/(wp+wk);

		if((bt_ave+wt_ave)/2>OET_END)
        {
			//cout<<"�о�"<<endl;
			et=bt-wt;
		}
		else if((bt_ave+wt_ave)/2>OET_MID)
		{
			//cout<<"�о�"<<endl;
			et=0;
		}
		else
        {
			//cout<<"����"<<endl;
			et=wt-bt;
		}
		em=(bp-wp)+5*(bk-wk);
		ec=bc-wc;
		eg=bg-wg;
		eh=bh-wh;

		return 12*em+4*et+3*ec+6*eg+3*eh+MatrixValue(position,side);
	}

	if(side==-1)  //��������
    {
		int bt_ave=bt/(bp+bk);
		int wt_ave=wt/(wp+wk);

		if((bt_ave+wt_ave)/2>OET_END)
        {
            //cout<<"�о�"<<endl;
			et=wt-bt;
		}
		else if((bt_ave+wt_ave)/2>OET_MID)
        {
            //cout<<"�о�"<<endl;
            et=0;
		}
		else
        {
			//cout<<"����"<<endl;
			et=bt-wt;
		}

		em=(wp-bp)+5*(wk-bk);
		ec=wc-bc;
		eg=wg-bg;
		eh=wh-bh;

		return 14*em+4*et+3*ec+6*eg+3*eh+MatrixValue(position,side);
	}
}


//��ֵ����
int Skip::MatrixValue(int position[][10],int nSide)
{
    int blackValue=0;
    int whiteValue=0;

    const int m=10,n=10;

    vector<vector<int> >b_Value(m,vector<int>(n));  //10X10����
    vector<vector<int> >w_Value(m,vector<int>(n));

    for(int i=0;i!=m;i++)
    {
        for(int j=0;j!=n;j++)
        {
            if((i+j)%2==0)
            {
                b_Value[i][j]=0;
                w_Value[i][j]=0;
            }
            if( (i==4&&j%2==1) || (i==5&&j%2==0) )
            {
                b_Value[i][j]=150;
                w_Value[i][j]=150;
            }

        }
    }//��������

    //��ֵ����
    b_Value[0][1]=90;
    b_Value[0][3]=b_Value[0][5]=b_Value[0][7]=b_Value[0][9]=110;
    b_Value[1][0]=100;
    b_Value[1][2]=b_Value[1][4]=b_Value[1][6]=b_Value[1][8]=120;
    b_Value[2][1]=140;
    b_Value[2][3]=b_Value[2][5]=b_Value[2][7]=130;
    b_Value[2][9]=110;
    b_Value[3][0]=120;
    b_Value[3][2]=b_Value[3][4]=b_Value[3][6]=b_Value[3][8]=140;

    b_Value[6][1]=b_Value[6][3]=b_Value[6][5]=b_Value[6][7]=160;
    b_Value[6][9]=170;
    b_Value[7][0]=b_Value[7][2]=b_Value[7][4]=b_Value[7][6]=b_Value[7][8]=170;
    b_Value[8][1]=b_Value[8][3]=b_Value[8][5]=b_Value[8][7]=180;
    b_Value[8][9]=190;
    b_Value[9][0]=190;
    b_Value[9][2]=b_Value[9][4]=b_Value[9][6]=b_Value[9][8]=200;

    w_Value[0][1]=w_Value[0][3]=w_Value[0][5]=w_Value[0][7]=200;
    w_Value[0][9]=190;
    w_Value[1][0]=190;
    w_Value[1][2]=w_Value[1][4]=w_Value[1][6]=w_Value[1][8]=180;
    w_Value[2][1]=w_Value[2][3]=w_Value[2][5]=w_Value[2][7]=w_Value[2][9]=170;
    w_Value[3][0]=170;
    w_Value[3][2]=w_Value[3][4]=w_Value[3][6]=w_Value[3][8]=160;

    w_Value[6][1]=w_Value[6][3]=w_Value[6][5]=w_Value[6][7]=140;
    w_Value[6][9]=120;
    w_Value[7][0]=110;
    w_Value[7][2]=w_Value[7][4]=w_Value[7][6]=130;
    w_Value[7][8]=140;
    w_Value[8][1]=w_Value[8][3]=w_Value[8][5]=w_Value[8][7]=120;
    w_Value[8][9]=100;
    w_Value[9][0]=90;
    w_Value[9][2]=w_Value[9][4]=w_Value[9][6]=w_Value[9][8]=110;

    if(nSide==1) //�ڷ�
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(position[i][j]%2==1)
                {
                    blackValue+=b_Value[i][j];
                }
            }
        }
        return blackValue;
    }
    else if(nSide==-1)
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(position[i][j]%2==0)
                {
                    whiteValue+=w_Value[i][j];
                }
            }
        }
        return whiteValue;
    }
}

void Skip::GetDepth(int position[][10])
{
	int k=0;
	int l=0;
	for(int i=0;i<10;i++)
    {
		for(int j=0;j<10;j++)
        {
			if(position[i][j]==WHITEKING||position[i][j]==BLACKKING)
            {
				k++;  //��������������
				l++;
			}
			if(position[i][j]==WHITECHESS||position[i][j]==BLACKCHESS)
            {
				l++;  //������������
			}
		}
	}

	//��
	if(k>=6)
    {
		Depth=6; //[6,  )  ���Ҫ��
	}
	else if(k>=3)
    {
		Depth=6; //[3,5]
	}
	else if(k>=1)
    {
		Depth=4; //[1,2]
	}
	else if(k==0)
	{
		if(l>20)
        {
            Depth=6; // 6  7  (20,40]
		}
		else if(l>=14)
		{
			Depth=6; // [14,20]
		}
		else if(l>10)
        {
			Depth=10; // (10,14)
		}
		else if(l>5)
		{
			Depth=12; // (5,10]
		}
		else if(l>0) // (0,5]
		{
			Depth=14;
		}
	}
}


void Skip::playManToMan()
{
    Skip();
    cleardevice();
    DrawBoard(position);
    int sideCount=0;
    //DisplayBoard(position);
    int depth=0;
	int n=1;
	string t1,t2;
	file();
	string fone,tone,ftwo,ttwo;
	string typeone,typetwo;

    while(1)
    {
        if(side==1)  //�ڷ�  �Ϸ�
        {
            //cout<<"m_nMovecount: "<<m_nMoveCount<<endl;
            int x1,y1,x2,y2;
            int Type;
            int xfrom,yfrom;
            int c;

            if(ismouseclick(WM_LBUTTONDOWN)&&sideCount==0)  //��ȷ
            {
                //Find_Can_Move_Pieces(position,side);
                CreatePossibleMove(position,side,depth);
                //cout<<"*m_nMoveCount"<<m_nMoveCount <<endl;
                x1 = mousex();
                y1 = mousey();

                if(x1<LEFT || x1>WIDTH-LEFT || y1<TOP || y1>WIDTH-TOP)
                {
                   cout<<"out of board!"<<endl;
                   clearmouseclick(WM_LBUTTONDOWN);
                   continue;
                }

                x1 = (x1 - LEFT)/STEP;
                y1 = (y1 - TOP)/STEP;
                //cout<<"x1 y1 : "<<y1<<" "<<x1<<endl;

                int leagle=0;

                /*
                cout<<"size "<<Walk_to_pieces.size()<<endl;
                for(int s=0;s<Walk_to_pieces.size();s++)
                {
                    cout<<"Walk_to_pieces: "<<Walk_to_pieces[s].x<<" "<<Walk_to_pieces[s].y<<" "<<Walk_to_pieces[s].height<<endl;
                }
                */

                /*
                for(int t=0;t<m_nMoveCount;t++)
                {
                    cout<<"m_MoveList: "<<m_MoveList[depth][t].head->p1.x<<" "<<m_MoveList[depth][t].head->p1.y<<endl;
                }
                */

                for(int i=0;i<m_nMoveCount;i++)
                {
                    for(NODE*cnode=m_MoveList[depth][i].head;;cnode=cnode->parent)
                    {
                        if(cnode->parent==NULL)
                        {
                            xfrom=cnode->p1.x;
                            yfrom=cnode->p1.y;
                            if(xfrom==y1&&yfrom==x1)
                            {
                                //cout<<"from  leagle "<<endl;
                                leagle=1;
                                cout<<"xfrom yfrom "<<xfrom<<" "<<yfrom<<endl;
                                //cout<<"xto yto "<<m_MoveList[depth][i].head->p1.x<<m_MoveList[depth][i].head->p1.y<<endl;
                                //cleardevice();
                                //DrawBoard(position);
                                line(yfrom*STEP+LEFT+STEP/2,xfrom*STEP+TOP+STEP/2,(m_MoveList[depth][i].head->p1.y)*STEP+LEFT+STEP/2,(m_MoveList[depth][i].head->p1.x)*STEP+TOP+STEP/2);

                            }
                            break;      //���ܻ�������   ��֪�������Ǹ�ѭ����
                        }
                    }
                }

                if(leagle==1)
                {
                    c=eatcount(position,y1,x1);
                    xfrom = y1;
                    yfrom = x1;
                    Type=position[y1][x1];
                    position[y1][x1]=EMPTY;

                    //cleardevice();
                    //DrawBoard(position);
                    sideCount++;
                }
                else if(leagle!=1)
                {
                    cout<<"illegal!!!"<<endl;
                    clearmouseclick(WM_LBUTTONDOWN);
                    continue;
                }
                clearmouseclick(WM_LBUTTONDOWN);
            }
            if(ismouseclick(WM_LBUTTONDOWN)&&sideCount==1)
            {
                x2 = mousex();
                y2 = mousey();
                //cout<<"x y: "<<y2<<" "<<x2<<endl;

                if(x2<LEFT|| x2>WIDTH-LEFT||y2<TOP||y2>WIDTH-TOP)
                {
                    cout<<"out of Board!"<<endl;
                    clearmouseclick(WM_LBUTTONDOWN);
                    continue;
                }
                x2 = (x2 - LEFT)/STEP;
                y2 = (y2 - TOP)/STEP;

                //cout<<"x2 y2: "<<y2<<" "<<x2<<endl;

                int leagle=0;
                int num;
                int t=0;

                for(int i=0;i<m_nMoveCount;i++)
                {
                    NODE*cnode=m_MoveList[depth][i].head;
                    while(cnode->parent!=NULL)
                    {
                        cnode=cnode->parent;
                        //cout<<"xfrom yfrom  x y "<<xfrom<<" "<<yfrom<<" "<<cnode->p1.x<<" "<<cnode->p1.y<<endl;
                        if(cnode->p1.x==xfrom&&cnode->p1.y==yfrom)
                        {
                            t=1;
                            break;
                        }
                    }

                    if(t==1&&m_MoveList[depth][i].head->p1.x==y2&&m_MoveList[depth][i].head->p1.y==x2)
                    {
                        num=i;
                        //cout<<"num: "<<num<<endl;
                        leagle=1;
                        break;
                    }
                }
                if(leagle==1)
                {

                    NODE*cnode=m_MoveList[depth][num].head;

                    while(cnode->parent!=NULL)
                    {
                        cnode=cnode->parent;
                        position[cnode->p1.x][cnode->p1.y]=EMPTY;
                        position[cnode->p2.x][cnode->p2.y]=EMPTY;
                    }

                    if(y2==9)
                    {
                        //cout<<"king chess"<<endl;
                        position[y2][x2]=BLACKKING;
                    }
                    else
                    {
                        //cout<<"common chess"<<endl;
                        position[y2][x2]=Type;
                    }
                    if(c==0)
                    {
                        typeone="-";
                    }
                    else
                    {
                        typeone="x";
                    }

					fone=Findnumber(y1,x1);
					tone=Findnumber(y2,x2);

                    cleardevice();
                    DrawBoard(position);
                    sideCount++;
                }
                else if(leagle!=1)
                {
                    cout<<"position to put chess    illeagle!!!"<<endl<<"please choose the farthest position."<<endl;
                    clearmouseclick(WM_LBUTTONDOWN);
                    continue;
                }
                clearmouseclick(WM_LBUTTONDOWN);
            }
            if(sideCount==2)
            {
                side*=-1;
                sideCount = 0;
                cout<<"side="<<side<<endl;
                cleardevice();
                DrawBoard(position);
            }
        }    //side=1 �Ҵ�����

        else if(side==-1)  //�׷�  �·�
        {
            //cout<<"m_nMovecount: "<<m_nMoveCount<<endl;
            /*
            for(int t=0;t<m_nMoveCount;t++)
            {
                cout<<"m_MoveList: "<<m_MoveList[depth][t].head->p1.x<<" "<<m_MoveList[depth][t].head->p1.y<<endl;
            }
            */
            int x1,y1,x2,y2;
            int Type;
            int xfrom,yfrom;
            int c;

            if(ismouseclick(WM_LBUTTONDOWN)&&sideCount==0)  //��ȷ
            {
                Find_Can_Move_Pieces(position,side);
                CreatePossibleMove(position,side,depth);
                x1 = mousex();
                y1 = mousey();
                //cout<<"x y: "<<x1<<" "<<y1<<endl;
                if(x1<LEFT||x1>WIDTH-LEFT||y1<TOP||y1>WIDTH-TOP)
                {
                   cout<<"out of board!"<<endl;
                   clearmouseclick(WM_LBUTTONDOWN);
                   continue;
                }

                x1 = (x1 - LEFT)/STEP;
                y1 = (y1 - TOP)/STEP;

                int leagle=0;
                for(int i=0;i<m_nMoveCount;i++)
                {
                    for(NODE*cnode=m_MoveList[depth][i].head;;cnode=cnode->parent)
                    {
                        if(cnode->parent==NULL)
                        {
                            xfrom=cnode->p1.x;
                            yfrom=cnode->p1.y;
                            if(xfrom==y1&&yfrom==x1)
                            {
                                cout<<"xfrom yfrom "<<xfrom<<" "<<yfrom<<endl;
                                leagle=1;
                                line(yfrom*STEP+LEFT+STEP/2,xfrom*STEP+TOP+STEP/2,(m_MoveList[depth][i].head->p1.y)*STEP+LEFT+STEP/2,(m_MoveList[depth][i].head->p1.x)*STEP+TOP+STEP/2);
                            }
                            break;
                        }
                    }
                }

                if(leagle==1)
                {
                    c=eatcount(position,y1,x1);
                    xfrom = y1;
                    yfrom = x1;
                    Type=position[y1][x1];
                    position[y1][x1]=EMPTY;
                    sideCount++;
                }
                else if(leagle!=1)
                {
                    cout<<"illegal!!!"<<endl;
                    clearmouseclick(WM_LBUTTONDOWN);
                    continue;
                }
                clearmouseclick(WM_LBUTTONDOWN);
            }
            if(ismouseclick(WM_LBUTTONDOWN)&&sideCount==1)
            {
                x2 = mousex();
                y2 = mousey();
                if(x2<LEFT|| x2>WIDTH-LEFT||y2<TOP||y2>WIDTH-TOP)
                {
                    cout<<"out of Board!"<<endl;
                    clearmouseclick(WM_LBUTTONDOWN);
                    continue;
                }
                x2 = (x2 - LEFT)/STEP;
                y2 = (y2 - TOP)/STEP;

                cout<<"x2 y2: "<<y2<<" "<<x2<<endl;
                int leagle=0;
                int num;
                int t=0;
                /*
                for(int t=0;t<m_nMoveCount;t++)
                {
                    cout<<"m_MoveList: "<<m_MoveList[depth][t].head->p1.x<<" "<<m_MoveList[depth][t].head->p1.y<<endl;
                }
                */

                for(int i=0;i<m_nMoveCount;i++)
                {
                    NODE*cnode=m_MoveList[depth][i].head;
                    while(cnode->parent!=NULL)
                    {
                        cnode=cnode->parent;
                        //cout<<"xfrom yfrom  x y "<<xfrom<<" "<<yfrom<<" "<<cnode->p1.x<<" "<<cnode->p1.y<<endl;
                        if(cnode->p1.x==xfrom&&cnode->p1.y==yfrom)
                        {
                            t=1;
                            break;
                        }
                    }

                    if(t==1&&m_MoveList[depth][i].head->p1.x==y2&&m_MoveList[depth][i].head->p1.y==x2)
                    {
                        num=i;
                        //cout<<"num: "<<num<<endl;
                        leagle=1;
                        break;
                    }
                }

                if(leagle==1)
                {
                    NODE*cnode=m_MoveList[depth][num].head;
                    while(cnode->parent!=NULL)
                    {
                        cnode=cnode->parent;
                        //cout<<"middle "<<cnode->p1.x<<" "<<cnode->p1.y<<endl;
                        position[cnode->p1.x][cnode->p1.y]=EMPTY;
                        position[cnode->p2.x][cnode->p2.y]=EMPTY;
                    }

                    if(y2==0)
                    {
                        position[y2][x2]=WHITEKING;
                    }
                    else
                    {
                        position[y2][x2]=Type;
                    }

                    if(c==0)
                    {
                        typetwo="-";
                    }
                    else
                    {
                        typetwo="x";
                    }

                    ftwo=Findnumber(y1,x1);
					ttwo=Findnumber(y2,x2);

                    Record(n,fone,tone,typeone,ftwo,ttwo,typetwo);
                    cleardevice();
                    DrawBoard(position);
                    sideCount++;
                }
                else if(leagle!=1)
                {
                    cout<<"position to put chess    illeagle!!!"<<endl<<"please choose the farthest position."<<endl;
                    clearmouseclick(WM_LBUTTONDOWN);
                    continue;
                }
                clearmouseclick(WM_LBUTTONDOWN);
            }
            if(sideCount==2)
            {
				n=n+1;
				cout<<"n= "<<n<<endl;
				side*=-1;
                sideCount = 0;
                cout<<"side="<<side<<endl;
                cleardevice();
                DrawBoard(position);
            }
        }    //side=-1 �Ҵ�����
        if(side==1&&isGameOver())
        {
            cout<<"WHITE WIN!!!"<<endl;
        }
        if(side==-1&&isGameOver())
        {
            cout<<"BLACK WIN!!!"<<endl;
        }
    }  //while�Ҵ�����
}

void Skip::playManToComputer()
{
    InitSkip();
    //m_nMoveCount=0;
    int sideCount=0;
    //Depth=6;
    int dph=0; //��һ�� �������

    int n=1;
    string t1,t2;
	file();
	string fone,tone,ftwo,ttwo;  //��λ��
	string typeone,typetwo;   //����

    f.open("location_out.txt",std::ios::out| std::ios::app);
    if(!f.is_open())
    {
        cout<<"file is not open"<<endl;
    }

    while(1)
    {
        if(side==1)  //�ڷ�  �Ϸ�   ��
        {
            if(side==1&&isGameOver())
            {
                f.close();
                cout<<"WHITE WIN!!!"<<endl;
            }
            int x1,y1,x2,y2;
            int Type;
            int xfrom,yfrom;
            int c;
            int leagle=0;
            NODE* fnode;
            int Count=0;
            if(ismouseclick(WM_LBUTTONDOWN)&&sideCount==0)  //��ȷ
            {

                Count=CreatePossibleMove(position,side,dph);
                //cout<<"size=: "<<Walk_to_pieces.size()<<endl;
                /*
                for(int s=0;s<Walk_to_pieces.size();s++)
                {
                    cout<<"x y height: "<<Walk_to_pieces[s].x<<" "<<Walk_to_pieces[s].y<<" "<<Walk_to_pieces[s].height<<endl;
                }
                */

                /*
                for(int t=0;t<m_nMoveCount;t++)
                {
                    cout<<"m_MoveList: "<<m_MoveList[dph][t].head->p1.x<<" "<<m_MoveList[dph][t].head->p1.y<<endl;
                }
                */

                //cout<<"Count: "<<Count<<endl;
                x1 = mousex();
                y1 = mousey();
                if(x1<LEFT||x1>WIDTH-LEFT||y1<TOP||y1>WIDTH-TOP)
                {
                   cout<<"out of board!"<<endl;
                   clearmouseclick(WM_LBUTTONDOWN);
                   continue;
                }

                x1 = (x1 - LEFT)/STEP;
                y1 = (y1 - TOP)/STEP;

                for(int i=0;i<Count;i++)
                {
                    for(NODE*cnode=m_MoveList[dph][i].head;;cnode=cnode->parent)
                    {
                        if(cnode->parent==NULL)
                        {
                            fnode=cnode;
                            xfrom=cnode->p1.x;
                            yfrom=cnode->p1.y;
                            if(xfrom==y1&&yfrom==x1)
                            {
                                //cout<<"from: "<<xfrom<<" "<<yfrom<<endl;
                                leagle=1;
                                line(yfrom*STEP+LEFT+STEP/2,xfrom*STEP+TOP+STEP/2,(m_MoveList[dph][i].head->p1.y)*STEP+LEFT+STEP/2,(m_MoveList[dph][i].head->p1.x)*STEP+TOP+STEP/2);
                            }
                            break;

                        } //endif

                    }//for

                }//for

                if(leagle==1)
                {
                    xfrom = y1;
                    yfrom = x1;
                    f<<n<<"."<<" "<<Findnumber(xfrom,yfrom);
                    if(position[xfrom][yfrom]==BLACKKING)
                    {
                        c=king_eatcount(position,y1,x1);
                    }
                    else
                    {
                        c=eatcount(position,y1,x1);
                    }

                    if(c!=0)
                    {
                        typeone="x";
                    }
                    else
                    {
                        typeone="-";
                    }
                    Type=position[y1][x1];
                    position[y1][x1]=EMPTY;
                    //cleardevice();
                    //DrawBoard(position);
                    sideCount++;
                }//endif leagle=1
                else if(leagle!=1)
                {

                    cout<<"illegal!!!"<<endl;
                    clearmouseclick(WM_LBUTTONDOWN);
                    continue;
                }
                clearmouseclick(WM_LBUTTONDOWN);
            } //endif  mouseclick&&sideCount==0
            if(ismouseclick(WM_LBUTTONDOWN)&&sideCount==1)
            {
                x2 = mousex();
                y2 = mousey();

                if(x2<LEFT|| x2>WIDTH-LEFT||y2<TOP||y2>WIDTH-TOP)
                {
                    cout<<"out of Board!"<<endl;
                    clearmouseclick(WM_LBUTTONDOWN);
                    continue;
                }
                x2 = (x2 - LEFT)/STEP;
                y2 = (y2 - TOP)/STEP;

                int leagle=0;
                int num;
                int t=0;
                /*
                for(int t=0;t<m_nMoveCount;t++)
                {
                    cout<<"m_MoveList: "<<m_MoveList[depth][t].head->p1.x<<" "<<m_MoveList[depth][t].head->p1.y<<endl;
                }
                */
                for(int i=0;i<m_nMoveCount;i++)
                {
                    NODE*cnode=m_MoveList[dph][i].head;
                    while(cnode->parent!=NULL)
                    {
                        cnode=cnode->parent;
                        if(cnode->p1.x==xfrom&&cnode->p1.y==yfrom)
                        {
                            t=1;
                            break;
                        }
                    }
                    if(t==1&&m_MoveList[dph][i].head->p1.x==y2&&m_MoveList[dph][i].head->p1.y==x2)
                    {
                        num=i;
                        //cout<<"num: "<<num<<endl;
                        leagle=1;
                        break;
                    }
                }
                if(leagle==1)
                {
                    NODE*cnode=m_MoveList[dph][num].head;

                    if(c==0)
                    {
                        f<<typeone<<Findnumber(y2,x2);
                    }
                    if(c==1)
                    {
                        f<<typeone<<Findnumber(y2,x2);
                        position[m_MoveList[dph][num].head->parent->p2.x][m_MoveList[dph][num].head->parent->p2.y]=EMPTY;
                    }
                    if(c==2)
                    {
                        f<<typeone<<Findnumber(m_MoveList[dph][num].head->parent->p1.x,m_MoveList[dph][num].head->parent->p1.y);
                        f<<typeone<<Findnumber(y2,x2);

                        position[m_MoveList[dph][num].head->parent->parent->p1.x][m_MoveList[dph][num].head->parent->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->parent->p2.x][m_MoveList[dph][num].head->parent->parent->p2.y]=EMPTY;

                        position[m_MoveList[dph][num].head->parent->p1.x][m_MoveList[dph][num].head->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->p2.x][m_MoveList[dph][num].head->parent->p2.y]=EMPTY;
                    }
                    if(c==3)
                    {
                        f<<typeone<<Findnumber(m_MoveList[dph][num].head->parent->parent->p1.x,m_MoveList[dph][num].head->parent->parent->p1.y);
                        f<<typeone<<Findnumber(m_MoveList[dph][num].head->parent->p1.x,m_MoveList[dph][num].head->parent->p1.y);
                        f<<typeone<<Findnumber(y2,x2);

                        position[m_MoveList[dph][num].head->parent->parent->parent->p1.x][m_MoveList[dph][num].head->parent->parent->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->parent->parent->p2.x][m_MoveList[dph][num].head->parent->parent->parent->p2.y]=EMPTY;

                        position[m_MoveList[dph][num].head->parent->parent->p1.x][m_MoveList[dph][num].head->parent->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->parent->p2.x][m_MoveList[dph][num].head->parent->parent->p2.y]=EMPTY;

                        position[m_MoveList[dph][num].head->parent->p1.x][m_MoveList[dph][num].head->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->p2.x][m_MoveList[dph][num].head->parent->p2.y]=EMPTY;
                    }
                    if(c==4)
                    {
                        f<<typeone<<Findnumber(m_MoveList[dph][num].head->parent->parent->parent->p1.x,m_MoveList[dph][num].head->parent->parent->parent->p1.y);
                        f<<typeone<<Findnumber(m_MoveList[dph][num].head->parent->parent->p1.x,m_MoveList[dph][num].head->parent->parent->p1.y);
                        f<<typeone<<Findnumber(m_MoveList[dph][num].head->parent->p1.x,m_MoveList[dph][num].head->parent->p1.y);
                        f<<typeone<<Findnumber(y2,x2);

                        position[m_MoveList[dph][num].head->parent->parent->parent->parent->p1.x][m_MoveList[dph][num].head->parent->parent->parent->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->parent->parent->parent->p2.x][m_MoveList[dph][num].head->parent->parent->parent->parent->p2.y]=EMPTY;

                        position[m_MoveList[dph][num].head->parent->parent->parent->p1.x][m_MoveList[dph][num].head->parent->parent->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->parent->parent->p2.x][m_MoveList[dph][num].head->parent->parent->parent->p2.y]=EMPTY;

                        position[m_MoveList[dph][num].head->parent->parent->p1.x][m_MoveList[dph][num].head->parent->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->parent->p2.x][m_MoveList[dph][num].head->parent->parent->p2.y]=EMPTY;

                        position[m_MoveList[dph][num].head->parent->p1.x][m_MoveList[dph][num].head->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->p2.x][m_MoveList[dph][num].head->parent->p2.y]=EMPTY;
                    }

                    if(y2==9)
                    {
                        position[y2][x2]=BLACKKING;
                    }
                    else
                    {
                        position[y2][x2]=Type;
                    }

                    //Record(n,fone,tone,typeone,ftwo,ttwo,typetwo);
                    cleardevice();
                    DrawBoard(position);
                    sideCount++;

                }
                else if(leagle!=1)
                {
                    cout<<"position to put chess illeagle!!!"<<endl<<"please choose the farthest position."<<endl;
                    clearmouseclick(WM_LBUTTONDOWN);
                    continue;
                }
                clearmouseclick(WM_LBUTTONDOWN);
            }
            if(sideCount==2)
            {
				cleardevice();
                DrawBoard(position);
				side*=-1;
                sideCount = 0;
                cout<<"side:"<<side<<endl;
                cout<<"����"<<PawnNumber(position)<<"  ����"<<KingNumber(position)<<endl;

            }

        }    //side=1 �Ҵ�����

        if(side==-1)   //�׷�
        {
            if(side==-1&&isGameOver())
            {
                f.close();
                cout<<"BLACK WIN!!!"<<endl;
            }
            GetDepth(position);
            Find_Can_Move_Pieces(position,side);
            int height=Walk_to_pieces[0].height;
            int Count=CreatePossibleMove(position,side,Depth);
            //cout<<"size=: "<<Walk_to_pieces.size()<<endl;
            //cout<<"Count=: "<<Count<<endl;
            /*
            for(int s=0;s<Walk_to_pieces.size();s++)
            {
                cout<<"x y height"<<Walk_to_pieces[s].x<<" "<<Walk_to_pieces[s].y<<" "<<Walk_to_pieces[s].height<<endl;
            }
            */

            /*
            for(int t=0;t<m_nMoveCount;t++)
            {
                cout<<"m_MoveList: "<<m_MoveList[Depth][t].head->p1.x<<" "<<m_MoveList[Depth][t].head->p1.y<<endl;
            }
            */


            if(Count==1)
            {

                BestMove.head=m_MoveList[Depth][0].head;
                //double value = Alphabetasearch(0,side,-1000,1000);
            }
            else if(Count>1)
            {
                double value = Alphabetasearch(Depth,side,-10000,10000);
                //cout<<"here"<<endl;
                //cout<<"BestTo:"<<BestMove.head->p1.x<<" "<<BestMove.head->p1.y<<endl;
            }


            if(height==0)     //�׷���������
            {
                //cout<<"white move"<<endl;
                //cout<<"BestFROM "<<BestMove.head->parent->p1.x<<" "<<BestMove.head->parent->p1.y<<endl;
                typetwo="-";
                if(BestMove.head->p1.x==0)
                {
                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->p1.x][BestMove.head->p1.y]=WHITEKING;
                }
                else
                {
                    int type=position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y];
                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->p1.x][BestMove.head->p1.y]=type;
                }
                //DisplayBoard(position);
                ftwo=Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                ttwo=Findnumber(BestMove.head->p1.x,BestMove.head->p1.y);

                f<<" "<<ftwo<<typetwo<<ttwo<<endl;
                //Record(n,fone,tone,typeone,ftwo,ttwo,typetwo);
                cleardevice();
                DrawBoard(position);
                side=-side;
                cout<<"side:"<<side<<endl;
                n=n+1;
                if(isGameOver())
                {
                    cout<<"Gameover !!!"<<endl;
                    //side=0;
                    f.close();
                    break;
                }
            }//height==0
            else    //�׷�������
            {
                //cout<<"white eat move"<<endl;
                typetwo="x";
                int Type;
                NODE * fnode;
                if(height==1)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y];
                    //cout<<"x,y"<<BestMove.head->parent->p1.x<<BestMove.head->parent->p1.y<<endl;
                    //cout<<"x,y"<<BestMove.head->parent->p2.x<<BestMove.head->parent->p2.y<<endl;
                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    if(BestMove.head->p1.x==0)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=WHITEKING;

                    }
                    else
                    {
                        //cout<<"computer   common  chess  "<<endl;
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }
                }
                else if(height==2)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->parent->p1.x,BestMove.head->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y];

                    position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->p2.x][BestMove.head->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;
                    if(BestMove.head->p1.x==0)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=WHITEKING;

                    }
                    else
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;

                    }
                }
                else if(height==3)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->p1.x,BestMove.head->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->p1.y];

                    position[BestMove.head->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->p2.x][BestMove.head->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    if(BestMove.head->p1.x==0)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=WHITEKING;
                    }
                    else
                    {

                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }
                }
                else if(height==4)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->p1.x,BestMove.head->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->parent->p1.y];

                    position[BestMove.head->parent->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->p2.x][BestMove.head->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    if(BestMove.head->p1.x==0)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=WHITEKING;
                    }
                    else
                    {

                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }

                }
                else if(height==5)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->parent->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->p1.x,BestMove.head->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y)<<endl;
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->parent->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->parent->parent->p1.y];

                    position[BestMove.head->parent->parent->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->p2.x][BestMove.head->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    if(BestMove.head->p1.x==9)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=BLACKKING;
                    }
                    else
                    {

                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }

                }


                cleardevice();
                DrawBoard(position);
                side=-side;
                cout<<"side:"<<side<<endl;
                n=n+1;

            }//height>0
        }//side==-1

    }//while

}//��������


void Skip::playComputerToMan()
{
    InitSkip();
    //m_nMoveCount=0;
    int sideCount=0;
    //Depth=8;
    int dph=0; //��һ�� �������

    int n=1;
    string t1,t2;
	file();
	string fone,tone,ftwo,ttwo;  //��λ��
	string typeone,typetwo;   //����

    f.open("location_out.txt",std::ios::out| std::ios::app);
    if(!f.is_open())
    {
        cout<<"file is not open"<<endl;
    }

    while(1)
    {

        if(side==1)   //�ڷ� ����
        {
            if(side==1&&isGameOver())
            {
                f.close();
                cout<<"WHITE WIN!!!"<<endl;
            }
            GetDepth(position);
            //cout<<"Depth"<<Depth<<endl;

            Find_Can_Move_Pieces(position,side);
            //cout<<"size: "<<Walk_to_pieces.size()<<endl;


            int height=Walk_to_pieces[0].height;
            int Count=CreatePossibleMove(position,side,Depth);

            //cout<<"Count: "<<Count<<endl;

            if(m_nMoveCount==1)
            {
                BestMove.head=m_MoveList[Depth][0].head;
                //double value = Alphabetasearch(0,side,-1000,1000);
            }
            else if(m_nMoveCount>1)
            {
                double value = Alphabetasearch(Depth,side,-10000,10000);
            }


            /*
            for(int s=0;s<Walk_to_pieces.size();s++)
            {
                cout<<"x y height"<<Walk_to_pieces[s].x<<" "<<Walk_to_pieces[s].y<<" "<<Walk_to_pieces[s].height<<endl;
            }
            */

            /*
            for(int t=0;t<m_nMoveCount;t++)
            {
                cout<<"m_MoveList: "<<m_MoveList[dph][t].head->p1.x<<" "<<m_MoveList[dph][t].head->p1.y<<endl;
            }
            */


            //cout<<"Best: "<<BestMove.head->p1.x<<" "<<BestMove.head->p1.y<<endl;

            //cout<<"height "<<Walk_to_pieces[0].height<<endl;

            if(height==0)     //��������
            {

                //cout<<"BestFROM "<<BestMove.head->parent->p1.x<<" "<<BestMove.head->parent->p1.y<<endl;
                typetwo="-";
                if(BestMove.head->p1.x==9)
                {
                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->p1.x][BestMove.head->p1.y]=BLACKKING;
                }
                else
                {
                    int type=position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y];
                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->p1.x][BestMove.head->p1.y]=type;
                }
                //DisplayBoard(position);
                ftwo=Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                ttwo=Findnumber(BestMove.head->p1.x,BestMove.head->p1.y);

                f<<" "<<ftwo<<typetwo<<ttwo<<endl;
                //Record(n,fone,tone,typeone,ftwo,ttwo,typetwo)
                cleardevice();
                DrawBoard(position);
                side=-side;
                cout<<"side:"<<side<<endl;
                n=n+1;
                if(isGameOver())
                {
                    cout<<"Gameover !!!"<<endl;
                    //side=0;
                    f.close();
                    break;
                }
            }//height==0
            else    //������
            {
                //cout<<"white eat move"<<endl;
                typetwo="x";
                int Type;
                NODE * fnode;
                //cout<<"����"<<height<<endl;
                if(height==1)
                {
                    //cout<<"height=1"<<endl;
                    f<<" "<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y];
                    //cout<<"x,y"<<BestMove.head->parent->p1.x<<BestMove.head->parent->p1.y<<endl;
                    //cout<<"x,y"<<BestMove.head->parent->p2.x<<BestMove.head->parent->p2.y<<endl;
                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    if(BestMove.head->p1.x==9)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=BLACKKING;

                    }
                    else
                    {
                        //cout<<"computer   common  chess  "<<endl;
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }
                }
                else if(height==2)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->parent->p1.x,BestMove.head->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y];

                    position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->p2.x][BestMove.head->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    cout<<"1"<<BestMove.head->parent->parent->p1.x<<" "<<BestMove.head->parent->parent->p1.y<<endl;
                    cout<<"2"<<BestMove.head->parent->parent->p2.x<<" "<<BestMove.head->parent->parent->p2.y<<endl;
                    cout<<"3"<<BestMove.head->parent->p1.x<<" "<<BestMove.head->parent->p1.y<<endl;
                    cout<<"4"<<BestMove.head->parent->p2.x<<" "<<BestMove.head->parent->p2.y<<endl;

                    if(BestMove.head->p1.x==9)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=BLACKKING;

                    }
                    else
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;

                    }
                }
                else if(height==3)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->p1.x,BestMove.head->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->p1.y];

                    position[BestMove.head->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->p2.x][BestMove.head->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    if(BestMove.head->p1.x==9)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=BLACKKING;
                    }
                    else
                    {

                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }
                }
                else if(height==4)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->p1.x,BestMove.head->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->parent->p1.y];

                    position[BestMove.head->parent->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->p2.x][BestMove.head->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    if(BestMove.head->p1.x==9)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=BLACKKING;
                    }
                    else
                    {

                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }

                }
                else if(height==5)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->parent->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->p1.x,BestMove.head->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y)<<endl;
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->parent->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->parent->parent->p1.y];

                    position[BestMove.head->parent->parent->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->p2.x][BestMove.head->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    if(BestMove.head->p1.x==9)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=BLACKKING;
                    }
                    else
                    {

                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }

                }
                cleardevice();
                DrawBoard(position);
                //QueryPerformanceCounter(&end);// ������ʱ
                //cout<<"ʱ�䣺"<<(end.QuadPart-start.QuadPart)*1000000/freq.QuadPart<<"΢����"<<endl;
                side=-side;
                cout<<"side:"<<side<<endl;
                n=n+1;

            }//height>0
        }//side==1

        if(side == -1)  //��
        {
            if(side==-1&&isGameOver())
            {
                f.close();
                cout<<"BLACK WIN!!!"<<endl;
            }
            int x1,y1,x2,y2;
            int Type;
            int xfrom,yfrom;
            int c;
            int leagle=0;
            NODE* fnode;
            int Count=0;
            if(ismouseclick(WM_LBUTTONDOWN)&&sideCount==0)  //��ȷ
            {

                Count=CreatePossibleMove(position,side,dph);
                //cout<<"size=: "<<Walk_to_pieces.size()<<endl;
                /*
                for(int s=0;s<Walk_to_pieces.size();s++)
                {
                    cout<<"x y height: "<<Walk_to_pieces[s].x<<" "<<Walk_to_pieces[s].y<<" "<<Walk_to_pieces[s].height<<endl;
                }
                */

                /*
                for(int t=0;t<m_nMoveCount;t++)
                {
                    cout<<"m_MoveList: "<<m_MoveList[dph][t].head->p1.x<<" "<<m_MoveList[dph][t].head->p1.y<<endl;
                }
                */

                //cout<<"Count: "<<Count<<endl;
                x1 = mousex();
                y1 = mousey();
                if(x1<LEFT||x1>WIDTH-LEFT||y1<TOP||y1>WIDTH-TOP)
                {
                   cout<<"out of board!"<<endl;
                   clearmouseclick(WM_LBUTTONDOWN);
                   continue;
                }

                x1 = (x1 - LEFT)/STEP;
                y1 = (y1 - TOP)/STEP;

                for(int i=0;i<Count;i++)
                {
                    for(NODE*cnode=m_MoveList[dph][i].head;;cnode=cnode->parent)
                    {
                        if(cnode->parent==NULL)
                        {
                            fnode=cnode;
                            xfrom=cnode->p1.x;
                            yfrom=cnode->p1.y;

                            //cout<<"from"<<xfrom<<" "<<yfrom<<endl;

                            if(xfrom==y1&&yfrom==x1)
                            {
                                //cout<<"from: "<<xfrom<<" "<<yfrom<<endl;
                                leagle=1;
                                line(yfrom*STEP+LEFT+STEP/2,xfrom*STEP+TOP+STEP/2,(m_MoveList[dph][i].head->p1.y)*STEP+LEFT+STEP/2,(m_MoveList[dph][i].head->p1.x)*STEP+TOP+STEP/2);
                            }
                            break;

                        } //endif

                    }//for

                }//for

                if(leagle==1)
                {
                    xfrom = y1;
                    yfrom = x1;
                    f<<n<<"."<<" "<<Findnumber(xfrom,yfrom);
                    if(position[xfrom][yfrom]==WHITEKING)
                    {
                        c=king_eatcount(position,y1,x1);
                    }
                    else
                    {
                        c=eatcount(position,y1,x1);
                    }

                    if(c!=0)
                    {
                        typeone="x";
                    }
                    else
                    {
                        typeone="-";
                    }
                    Type=position[y1][x1];
                    position[y1][x1]=EMPTY;
                    //cleardevice();
                    //DrawBoard(position);
                    sideCount++;
                }//endif leagle=1
                else if(leagle!=1)
                {

                    cout<<"illegal!!!"<<endl;
                    clearmouseclick(WM_LBUTTONDOWN);
                    continue;
                }
                clearmouseclick(WM_LBUTTONDOWN);
            } //endif  mouseclick&&sideCount==0
            if(ismouseclick(WM_LBUTTONDOWN)&&sideCount==1)
            {
                x2 = mousex();
                y2 = mousey();

                if(x2<LEFT|| x2>WIDTH-LEFT||y2<TOP||y2>WIDTH-TOP)
                {
                    cout<<"out of Board!"<<endl;
                    clearmouseclick(WM_LBUTTONDOWN);
                    continue;
                }
                x2 = (x2 - LEFT)/STEP;
                y2 = (y2 - TOP)/STEP;

                int leagle=0;
                int num;
                int t=0;
                /*
                for(int t=0;t<m_nMoveCount;t++)
                {
                    cout<<"m_MoveList: "<<m_MoveList[depth][t].head->p1.x<<" "<<m_MoveList[depth][t].head->p1.y<<endl;
                }
                */
                for(int i=0;i<m_nMoveCount;i++)
                {
                    NODE*cnode=m_MoveList[dph][i].head;
                    while(cnode->parent!=NULL)
                    {
                        cnode=cnode->parent;
                        if(cnode->p1.x==xfrom&&cnode->p1.y==yfrom)
                        {
                            t=1;
                            break;
                        }
                    }
                    if(t==1&&m_MoveList[dph][i].head->p1.x==y2&&m_MoveList[dph][i].head->p1.y==x2)
                    {
                        num=i;
                        //cout<<"num: "<<num<<endl;
                        leagle=1;
                        break;
                    }
                }
                if(leagle==1)
                {
                    NODE*cnode=m_MoveList[dph][num].head;

                    if(c==0)
                    {
                        f<<typeone<<Findnumber(y2,x2);
                    }
                    if(c==1)
                    {
                        f<<typeone<<Findnumber(y2,x2);
                        position[m_MoveList[dph][num].head->parent->p2.x][m_MoveList[dph][num].head->parent->p2.y]=EMPTY;
                    }
                    if(c==2)
                    {
                        f<<typeone<<Findnumber(m_MoveList[dph][num].head->parent->p1.x,m_MoveList[dph][num].head->parent->p1.y);
                        f<<typeone<<Findnumber(y2,x2);

                        position[m_MoveList[dph][num].head->parent->parent->p1.x][m_MoveList[dph][num].head->parent->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->parent->p2.x][m_MoveList[dph][num].head->parent->parent->p2.y]=EMPTY;

                        position[m_MoveList[dph][num].head->parent->p1.x][m_MoveList[dph][num].head->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->p2.x][m_MoveList[dph][num].head->parent->p2.y]=EMPTY;
                    }
                    if(c==3)
                    {
                        f<<typeone<<Findnumber(m_MoveList[dph][num].head->parent->parent->p1.x,m_MoveList[dph][num].head->parent->parent->p1.y);
                        f<<typeone<<Findnumber(m_MoveList[dph][num].head->parent->p1.x,m_MoveList[dph][num].head->parent->p1.y);
                        f<<typeone<<Findnumber(y2,x2);

                        position[m_MoveList[dph][num].head->parent->parent->parent->p1.x][m_MoveList[dph][num].head->parent->parent->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->parent->parent->p2.x][m_MoveList[dph][num].head->parent->parent->parent->p2.y]=EMPTY;

                        position[m_MoveList[dph][num].head->parent->parent->p1.x][m_MoveList[dph][num].head->parent->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->parent->p2.x][m_MoveList[dph][num].head->parent->parent->p2.y]=EMPTY;

                        position[m_MoveList[dph][num].head->parent->p1.x][m_MoveList[dph][num].head->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->p2.x][m_MoveList[dph][num].head->parent->p2.y]=EMPTY;
                    }
                    if(c==4)
                    {
                        f<<typeone<<Findnumber(m_MoveList[dph][num].head->parent->parent->parent->p1.x,m_MoveList[dph][num].head->parent->parent->parent->p1.y);
                        f<<typeone<<Findnumber(m_MoveList[dph][num].head->parent->parent->p1.x,m_MoveList[dph][num].head->parent->parent->p1.y);
                        f<<typeone<<Findnumber(m_MoveList[dph][num].head->parent->p1.x,m_MoveList[dph][num].head->parent->p1.y);
                        f<<typeone<<Findnumber(y2,x2);

                        position[m_MoveList[dph][num].head->parent->parent->parent->parent->p1.x][m_MoveList[dph][num].head->parent->parent->parent->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->parent->parent->parent->p2.x][m_MoveList[dph][num].head->parent->parent->parent->parent->p2.y]=EMPTY;

                        position[m_MoveList[dph][num].head->parent->parent->parent->p1.x][m_MoveList[dph][num].head->parent->parent->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->parent->parent->p2.x][m_MoveList[dph][num].head->parent->parent->parent->p2.y]=EMPTY;

                        position[m_MoveList[dph][num].head->parent->parent->p1.x][m_MoveList[dph][num].head->parent->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->parent->p2.x][m_MoveList[dph][num].head->parent->parent->p2.y]=EMPTY;

                        position[m_MoveList[dph][num].head->parent->p1.x][m_MoveList[dph][num].head->parent->p1.y]=EMPTY;
                        position[m_MoveList[dph][num].head->parent->p2.x][m_MoveList[dph][num].head->parent->p2.y]=EMPTY;
                    }

                    if(y2==0)
                    {
                        position[y2][x2]=WHITEKING;
                    }
                    else
                    {
                        position[y2][x2]=Type;
                    }

                    cleardevice();
                    DrawBoard(position);
                    sideCount++;

                }
                else if(leagle!=1)
                {
                    cout<<"position to put chess illegal!!!"<<endl<<"please choose the farthest position."<<endl;
                    clearmouseclick(WM_LBUTTONDOWN);
                    continue;
                }
                clearmouseclick(WM_LBUTTONDOWN);
            }
            if(sideCount==2)
            {
				cleardevice();
                DrawBoard(position);

				side*=-1;
                sideCount = 0;
                cout<<"side:"<<side<<endl;

                cout<<"����"<<PawnNumber(position)<<"  ����"<<KingNumber(position)<<endl;

            }
        }    //side=-1 �Ҵ�����

    }//while

}//��������

void Skip::playComputerToComputer()
{
    InitSkip();
    int sideCount=0;
    //Depth=10;
    int n=1;
    string t1,t2;
	file();
	string fone,tone,ftwo,ttwo;  //��λ��
	string typeone,typetwo;   //����

    f.open("location_out.txt",std::ios::out| std::ios::app);
    if(!f.is_open())
    {
        cout<<"file is not open"<<endl;
    }

    while(1)
    {
        if(side==1)   //�ڷ� ����
        {
            if(side==1&&isGameOver())
            {
                f.close();
                cout<<"WHITE WIN!!!"<<endl;
            }
            GetDepth(position);

            Find_Can_Move_Pieces(position,side);
            int height=Walk_to_pieces[0].height;
            int Count=CreatePossibleMove(position,side,Depth);
            //cout<<"Count: "<<Count<<endl;

            /*
            for(int s=0;s<Walk_to_pieces.size();s++)
            {
                cout<<"x y height"<<Walk_to_pieces[s].x<<" "<<Walk_to_pieces[s].y<<" "<<Walk_to_pieces[s].height<<endl;
            }
            */
            if(Count==1)
            {
                BestMove.head=m_MoveList[Depth][0].head;
                //double value = Alphabetasearch(0,side,-1000,1000);
            }
            else if(Count>1)
            {
                double value = Alphabetasearch(Depth,side,-99999,99999);
            }


            if(height==0)     //�ڷ���������
            {
                //cout<<"black move"<<endl;
                //cout<<"BestFROM "<<BestMove.head->parent->p1.x<<" "<<BestMove.head->parent->p1.y<<endl;
                typetwo="-";
                if(BestMove.head->p1.x==9)
                {
                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->p1.x][BestMove.head->p1.y]=BLACKKING;
                }
                else
                {
                    int type=position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y];
                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->p1.x][BestMove.head->p1.y]=type;
                }
                //DisplayBoard(position);
                ftwo=Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                ttwo=Findnumber(BestMove.head->p1.x,BestMove.head->p1.y);

                f<<" "<<ftwo<<typetwo<<ttwo<<endl;
                //Record(n,fone,tone,typeone,ftwo,ttwo,typetwo);
                cleardevice();
                DrawBoard(position);
                side=-side;
                cout<<"side:"<<side<<endl;
                cout<<"����"<<PawnNumber(position)<<"  ����"<<KingNumber(position)<<endl;
                //system("pause");
                n=n+1;
                if(isGameOver())
                {
                    cout<<"Gameover !!!"<<endl;
                    //side=0;
                    f.close();
                    break;
                }
            }//height==0
            else    //�ڷ�������
            {
                //cout<<"black eat move"<<endl;
                typetwo="x";
                int Type;
                NODE * fnode;
                if(height==1)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y];
                    //cout<<"x,y"<<BestMove.head->parent->p1.x<<BestMove.head->parent->p1.y<<endl;
                    //cout<<"x,y"<<BestMove.head->parent->p2.x<<BestMove.head->parent->p2.y<<endl;
                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    if(BestMove.head->p1.x==9)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=BLACKKING;
                    }
                    else
                    {
                        //cout<<"computer   common  chess  "<<endl;
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }
                }
                else if(height==2)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->parent->p1.x,BestMove.head->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y];

                    position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->p2.x][BestMove.head->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;
                    if(BestMove.head->p1.x==9)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=BLACKKING;
                    }
                    else
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }
                }
                else if(height==3)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->p1.x,BestMove.head->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->p1.y];

                    position[BestMove.head->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->p2.x][BestMove.head->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    if(BestMove.head->p1.x==9)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=BLACKKING;
                    }
                    else
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }
                }
                else if(height==4)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->p1.x,BestMove.head->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->parent->p1.y];

                    position[BestMove.head->parent->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->p2.x][BestMove.head->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    if(BestMove.head->p1.x==9)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=BLACKKING;
                    }
                    else
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }

                }
                cleardevice();
                DrawBoard(position);
                side=-side;
                cout<<"side:"<<side<<endl;
                cout<<"����"<<PawnNumber(position)<<"  ����"<<KingNumber(position)<<endl;
                //system("pause");
                n=n+1;

            }//height>0
        }

        if(side==-1)   //�׷�
        {
            //DisplayBoard(position);
            //system("pause");
            if(side==-1&&isGameOver())
            {
                f.close();
                cout<<"BLACK WIN!!!"<<endl;
            }
            GetDepth(position);
            Find_Can_Move_Pieces(position,side);
            int height=Walk_to_pieces[0].height;
            int Count=CreatePossibleMove(position,side,Depth);
            //cout<<"Count:"<<Count<<endl;

            /*
            for(int s=0;s<Walk_to_pieces.size();s++)
            {
                cout<<"x y height"<<Walk_to_pieces[s].x<<" "<<Walk_to_pieces[s].y<<" "<<Walk_to_pieces[s].height<<endl;
            }
            */

            if(m_nMoveCount==1)
            {
                BestMove.head=m_MoveList[Depth][0].head;
                //double value = Alphabetasearch(0,side,-1000,1000);
            }
            else if(m_nMoveCount>1)
            {
                double value = Alphabetasearch(Depth,side,-99999,99999);
            }
            //cout<<"BestTo: "<<BestMove.head->p1.x<<" "<<BestMove.head->p1.y<<endl;
            //cout<<"BestFrom: "<<BestMove.head->parent->p1.x<<" "<<BestMove.head->parent->p1.y<<endl;

            if(height==0)     //�׷���������
            {
                //cout<<"white move"<<endl;

                typetwo="-";
                if(BestMove.head->p1.x==0)
                {
                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->p1.x][BestMove.head->p1.y]=WHITEKING;
                }
                else
                {
                    int type=position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y];
                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->p1.x][BestMove.head->p1.y]=type;
                }

                ftwo=Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                ttwo=Findnumber(BestMove.head->p1.x,BestMove.head->p1.y);

                f<<" "<<ftwo<<typetwo<<ttwo<<endl;
                //Record(n,fone,tone,typeone,ftwo,ttwo,typetwo);
                cleardevice();
                DrawBoard(position);
                side=-side;
                cout<<"side:"<<side<<endl;
                cout<<"����"<<PawnNumber(position)<<"  ����"<<KingNumber(position)<<endl;
                //system("pause");
                n=n+1;
                if(isGameOver())
                {
                    cout<<"Gameover !!!"<<endl;
                    //side=0;
                    f.close();
                    break;
                }
            }//height==0
            else    //�׷�������
            {
                //cout<<"white eat move"<<endl;
                typetwo="x";
                int Type;
                NODE * fnode;
                if(height==1)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y];
                    //cout<<"x,y"<<BestMove.head->parent->p1.x<<BestMove.head->parent->p1.y<<endl;
                    //cout<<"x,y"<<BestMove.head->parent->p2.x<<BestMove.head->parent->p2.y<<endl;
                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    if(BestMove.head->p1.x==0)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=WHITEKING;

                    }
                    else
                    {
                        //cout<<"computer   common  chess  "<<endl;
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }
                }
                else if(height==2)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->parent->p1.x,BestMove.head->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y];

                    position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->p2.x][BestMove.head->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;
                    if(BestMove.head->p1.x==0)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=WHITEKING;

                    }
                    else
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;

                    }
                }
                else if(height==3)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->p1.x,BestMove.head->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->p1.y];

                    position[BestMove.head->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->p2.x][BestMove.head->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    if(BestMove.head->p1.x==0)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=WHITEKING;
                    }
                    else
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }
                }
                else if(height==4)
                {
                    f<<" "<<Findnumber(BestMove.head->parent->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->parent->p1.x,BestMove.head->parent->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->parent->p1.x,BestMove.head->parent->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->parent->p1.x,BestMove.head->parent->p1.y);
                    f<<typetwo<<Findnumber(BestMove.head->p1.x,BestMove.head->p1.y)<<endl;

                    Type=position[BestMove.head->parent->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->parent->p1.y];

                    position[BestMove.head->parent->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->parent->p1.x][BestMove.head->parent->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->parent->p2.x][BestMove.head->parent->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->parent->p1.x][BestMove.head->parent->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->parent->p2.x][BestMove.head->parent->parent->p2.y]=EMPTY;

                    position[BestMove.head->parent->p1.x][BestMove.head->parent->p1.y]=EMPTY;
                    position[BestMove.head->parent->p2.x][BestMove.head->parent->p2.y]=EMPTY;

                    if(BestMove.head->p1.x==0)
                    {
                        position[BestMove.head->p1.x][BestMove.head->p1.y]=WHITEKING;
                    }
                    else
                    {

                        position[BestMove.head->p1.x][BestMove.head->p1.y]=Type;
                    }

                }
                cleardevice();
                DrawBoard(position);
                side=-side;
                cout<<"side:"<<side<<endl;
                cout<<"����"<<PawnNumber(position)<<"  ����"<<KingNumber(position)<<endl;
                //system("pause");
                n=n+1;
            }//height>0
        }//side==-1
    }
}

//�ж���Ϸ�Ƿ����
bool Skip::isGameOver()
{
    Find_Can_Move_Pieces(position,side);
    if(Walk_to_pieces.size()==0)//game over
    {
        return true;
    }
    return false;
}


int Skip::isWin()
{
    Find_Can_Move_Pieces(position,side);
    if(side==1&&Walk_to_pieces.size()==0)
    {
        return 1;
    }
    else if(side==-1&&Walk_to_pieces.size()==0)
    {
        return -1;
    }
}


int Skip::PawnNumber(int position[][10])
{
    int pawn_num=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(position[i][j]==BLACKCHESS||position[i][j]==WHITECHESS)
            {
                pawn_num++;
            }
        }
    }
    return pawn_num;
}


int Skip::KingNumber(int position[][10])
{
    int king_num=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(position[i][j]==BLACKKING||position[i][j]==WHITEKING)
            {
                king_num++;
            }
        }
    }
    return king_num;
}


string Skip::Findnumber(int x,int y)
{
    if(x==0&&y==1)
    {
        return "01";
    }
    else if(x==0&&y==3)
    {
        return "02";
    }
    else if(x==0&&y==5)
    {
        return "03";
    }
    else if(x==0&&y==7)
    {
        return "04";
    }
    else if(x==0&&y==9)
    {
        return "05";
    }
    else if(x==1&&y==0)
    {
        return "06";
    }
    else if(x==1&&y==2)
    {
        return "07";
    }
    else if(x==1&&y==4)
    {
        return "08";
    }
    else if(x==1&&y==6)
    {
        return "09";
    }
    else if(x==1&&y==8)
    {
        return "10";
    }
    else if(x==2&&y==1)
    {
        return "11";
    }
    else if(x==2&&y==3)
    {
        return "12";
    }
    else if(x==2&&y==5)
    {
        return "13";
    }
    else if(x==2&&y==7)
    {
        return "14";
    }
    else if(x==2&&y==9)
    {
        return "15";
    }
    else if(x==3&&y==0)
    {
        return "16";
    }
    else if(x==3&&y==2)
    {
        return "17";
    }
    else if(x==3&&y==4)
    {
        return "18";
    }
    else if(x==3&&y==6)
    {
        return "19";
    }
    else if(x==3&&y==8)
    {
        return "20";
    }
    else if(x==4&&y==1)
    {
        return "21";
    }
    else if(x==4&&y==3)
    {
        return "22";
    }
    else if(x==4&&y==5)
    {
        return "23";
    }
    else if(x==4&&y==7)
    {
        return "24";
    }
    else if(x==4&&y==9)
    {
        return "25";
    }
    else if(x==5&&y==0)
    {
        return "26";
    }
    else if(x==5&&y==2)
    {
        return "27";
    }
    else if(x==5&&y==4)
    {
        return "28";
    }
    else if(x==5&&y==6)
    {
        return "29";
    }
    else if(x==5&&y==8)
    {
        return "30";
    }
    else if(x==6&&y==1)
    {
        return "31";
    }
    else if(x==6&&y==3)
    {
        return "32";
    }
    else if(x==6&&y==5)
    {
        return "33";
    }
    else if(x==6&&y==7)
    {
        return "34";
    }
    else if(x==6&&y==9)
    {
        return "35";
    }
    else if(x==7&&y==0)
    {
        return "36";
    }
    else if(x==7&&y==2)
    {
        return "37";
    }
    else if(x==7&&y==4)
    {
        return "38";
    }
    else if(x==7&&y==6)
    {
        return "39";
    }
    else if(x==7&&y==8)
    {
        return "40";
    }
    else if(x==8&&y==1)
    {
        return "41";
    }
    else if(x==8&&y==3)
    {
        return "42";
    }
    else if(x==8&&y==5)
    {
        return "43";
    }
    else if(x==8&&y==7)
    {
        return "44";
    }
    else if(x==8&&y==9)
    {
        return "45";
    }
    else if(x==9&&y==0)
    {
        return "46";
    }
    else if(x==9&&y==2)
    {
        return "47";
    }
    else if(x==9&&y==4)
    {
        return "48";
    }
    else if(x==9&&y==6)
    {
        return "49";
    }
    else if(x==9&&y==8)
    {
        return "50";
    }
}

int Skip::max_h(int a,int b)
{
    return a>b?a:b;
}

int Skip::min_h(int a,int b)
{
    return a>b?b:a;
}

int Skip::Record(int num,string record1,string record2,string type1,string record3,string record4,string type2)
{
	fstream files;
	files.open("location_out.txt",std::ios::out| std::ios::app);
    if(!files.is_open())
    {
        return 0;
    }
	stringstream  s;
	s<<num;
	string no=s.str();   //���   �ڼ���

	files<<no<<". "<<record1<<type1<<record2<<" "<<record3<<type2<<record4<<endl;

	files.close();

}

int Skip::file()
{
    ofstream location_out;   //����Ҫ��:  DR8-���ֲ�����Avs���ֲ�����B-��(��)��ʤ-����ʱ��ص�-��������      ��չ��.txt    ����Ӣ�����뷨��    ����UTF-8

    string time,first,group1,group2,result;
    time="ʱ��: 2018.03.10";
    first="���֣�1";     //�Ϸ��������߼�Ϊ1  �·��������߼�Ϊ2
    group1="���ַ�: ��������ѧ1��";
    group2="���ַ�: ��������ѧ2��";
    result="���: ";   //�Ϸ�����ʤ���� ���: 1-0   �·�����ʤ����  ���: 0-1     ƽ�ּ� ���: *

    location_out.open("location_out.txt",std::ios::out| std::ios::app);
    if(!location_out.is_open())
    {
        return 0;
    }
    location_out<<"\n"<<time<<"\n"<<first<<"\n"<<group1<<"\n"<<group2<<"\n"<<result<<"\n"<<endl;
    location_out.close();
}

