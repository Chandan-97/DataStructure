// ChandyShot... 
// ZCO14001 (Video Game)

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout<<#x<<" = "<<x<<endl;
#define deb2(x, y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define sz 100010
#define szz 30
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define MX 1000000000
#define MN -MX
#define tc int t; cin>>t; while(t--)
#define hello cout<<"hello"<<endl;
#define clr(x) memset(x, 0, sizeof (x))
#define fill(x) memset(x, -1, sizeof(x))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define f(i, j, k, l) for(int (i)=(j); (i)<(k); (i)+=(l))
#define ff(i, j, k, l) for(int (i)=(j); (i)<=(k); (i)+=(l))
#define fin f(i, 0, n, 1)
#define fjn f(j, 0, n, 1)
#define fiin ff(i, 1, n, 1)
#define fjjn f(j, 1, n, 1)
using namespace std;


/*****************************/
int boxes = 0, height_limit = 0;
vector <int> height;
int command = -1;
int position = 0;
bool isPick = false;
/*****************************/

#define QUIT        0
#define MOVE_LEFT   1
#define MOVE_RIGHT  2
#define PICK        3
#define DROP        4

/************************************/
void output(){                      //
    for(int a : height)             //
        cout<<a<<" ";               //
    cout<<endl;                     //
}                                   //
/************************************/



/************************************/
bool isExtreamRight(){              //
    return position==boxes-1;       //
}                                   //
                                    //
void moveRight(){                   //
    if(isExtreamRight())            //
        return;                     //
    position++;                     //
}                                   //
/************************************/



/************************************/
bool isExtreamLeft(){               //
    return position==0;             //
}                                   //
                                    //
void moveLeft(){                    //
    if(isExtreamLeft())             //
        return;                     //
    position--;                     //
}                                   //
/************************************/



/************************************/
bool alreadyPicked(){               //
    return isPick==true;            //
}                                   //
                                    //
bool emptyStack(){                  //
    return height[position] == 0;   //
}                                   //
                                    //
void pick(){                        //
    if(alreadyPicked())             //
        return;                     //
    if(emptyStack())                //
        return;                     //
    height[position]--;             //
    isPick = true;                  //
}                                   //
/************************************/



/************************************************/
bool dontPick(){                                //
    return isPick==false;                       //
}                                               //
                                                //
bool fullStack(){                               //
    return height[position] == height_limit;    //
}                                               //
                                                //
void drop(){                                    //
    if(dontPick ())                             //
        return;                                 //
    if(fullStack())                             //
        return;                                 //
    height[position]++;                         //
    isPick = false;                             //
}                                               //
/************************************************/





int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.in", "r", stdin);
    
    cin>>boxes>>height_limit;

    height.assign(boxes, 0);

    for(int i=0; i<boxes; i++) cin>>height[i];

    while(true){
        cin>>command;
        if(command == QUIT){
            output();
            break;
        }

        switch(command){
            case MOVE_LEFT :
                    moveLeft();
                    break;
            case MOVE_RIGHT : 
                    moveRight();
                    break;
            case PICK : 
                    pick();
                    break;
            case DROP :
                    drop();
                    break;
        }
    }
    return 0;
}
