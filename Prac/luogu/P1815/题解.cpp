#include <bits/stdc++.h>
using namespace std;

struct node{
    int x;
    int y;
};

int n;
string instruction;
bool chessBoard[51][51] = {false};
queue<node> snake;

int go_east()
{
    node head = snake.back();
    node tail = snake.front();
    head.x++;
    if(head.x > 50) return 2;
    
    chessBoard[tail.x][tail.y] = false;
    if(chessBoard[head.x][head.y]) return 1;
    
    chessBoard[head.x][head.y] = true;
    snake.pop();
    snake.push(head);

    return 0;
}

int go_north()
{
    node head = snake.back();
    node tail = snake.front();
    head.y--;
    if(head.y < 1) return 2;
    
    chessBoard[tail.x][tail.y] = false;
    if(chessBoard[head.x][head.y]) return 1;
    
    chessBoard[head.x][head.y] = true;
    snake.pop();
    snake.push(head);

    return 0;
}

int go_west()
{
    node head = snake.back();
    node tail = snake.front();
    head.x--;
    if(head.x < 1) return 2;
    
    chessBoard[tail.x][tail.y] = false;
    if(chessBoard[head.x][head.y]) return 1;
    
    chessBoard[head.x][head.y] = true;
    snake.pop();
    snake.push(head);

    return 0;
}

int go_south()
{
    node head = snake.back();
    node tail = snake.front();
    head.y++;
    if(head.y > 50) return 2;
    
    chessBoard[tail.x][tail.y] = false;
    if(chessBoard[head.x][head.y]) return 1;
    
    chessBoard[head.x][head.y] = true;
    snake.pop();
    snake.push(head);

    return 0;
}

void init_queue()
{
    memset(chessBoard, false, sizeof(chessBoard));
    while(!snake.empty()) snake.pop();
    for(int i=11;i<=30;i++)
    {
        chessBoard[i][25] = true;
        snake.push({i,25});
    }
}

int main()
{
    int flag;
    while(true)
    {
        init_queue();
        
        cin >> n;
        if(!n) break;

        cin >> instruction;

        for(int i=0;i<n;i++)
        {   
            switch(instruction[i])
            {
                case('W'):
                    flag = go_west();
                    break;
                case('E'):
                    flag = go_east();
                    break;
                case('S'):
                    flag = go_south();
                    break;
                case('N'):
                    flag = go_north();
                    break;
            }
            if(flag == 1) 
            {
                cout << "The worm ran into itself on move " << i+1 << '.' << endl;
                break;
            }
            if(flag == 2) 
            {
                cout << "The worm ran off the board on move " << i+1 << '.' << endl;
                break;
            }
        }
        if(flag == 0) cout << "The worm successfully made all " << n << " moves." << endl;
    }
    return 0;
}

/*
纯纯的模拟
*/