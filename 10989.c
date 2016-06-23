#include<stdio.h>
#include<stdlib.h>

typedef struct MYQ myq;
struct MYQ{
    char c;
    int row, col;
    int step;
};

char A[505][505];
int visit[505][505]={0};
myq Q[500000];

int main(){

    int N,i,R,C,j,k;
    char tmp;
    int s_r, s_c;
    int f_r, f_c;
    int head, tail;
    int ans=0;

    scanf("%d",&N);
        for(i=0;i<N;i++){
            scanf("%d %d",&R,&C);
            tmp=getchar();
            for(j=0;j<R;j++){
                for(k=0;k<C;k++){
                    tmp=getchar();
                    A[j][k]=tmp;
                    if(tmp=='S'){
                        s_r=j;
                        s_c=k;
                    }else if(tmp=='F'){
                        f_r=j;
                        f_c=k;
                    }
                }
                tmp=getchar();
            }
            Q[0].c='S';
            Q[0].row=s_r;
            Q[0].col=s_c;
            Q[0].step=0;
            head=0;
            tail=1;
                while(1){
                    if(visit[Q[head].row][Q[head].col]==1){
                        head++;
                        continue;
                    }
                    if(Q[head].col-1>=0&&A[Q[head].row][Q[head].col-1]!='#'
                       &&visit[Q[head].row][Q[head].col-1]==0){/*left*/

                        Q[tail].c=A[Q[head].row][Q[head].col-1];
                        Q[tail].row = Q[head].row;
                        Q[tail].col = Q[head].col-1;
                        Q[tail].step=Q[head].step+1;
                        if(Q[tail].c=='F'){
                            ans=Q[tail].step;
                            break;
                        }
                        tail++;
                    }
                    if(Q[head].col+1<C&&A[Q[head].row][Q[head].col+1]!='#'
                       &&visit[Q[head].row][Q[head].col+1]==0){/*right*/
                        Q[tail].c=A[Q[head].row][Q[head].col+1];
                        Q[tail].row = Q[head].row;
                        Q[tail].col = Q[head].col+1;
                        Q[tail].step=Q[head].step+1;
                        if(Q[tail].c=='F'){
                            ans=Q[tail].step;
                            break;
                        }
                        tail++;
                    }
                    if(Q[head].row-1>=0&&A[Q[head].row-1][Q[head].col]!='#'
                       &&visit[Q[head].row-1][Q[head].col]==0){/*up*/
                        Q[tail].c=A[Q[head].row-1][Q[head].col];
                        Q[tail].row = Q[head].row-1;
                        Q[tail].col = Q[head].col;
                        Q[tail].step=Q[head].step+1;
                        if(Q[tail].c=='F'){
                            ans=Q[tail].step;
                            break;
                        }
                         tail++;
                    }
                    if(Q[head].row+1<R&&A[Q[head].row+1][Q[head].col]!='#'
                       &&visit[Q[head].row+1][Q[head].col]==0){/*down*/
                        Q[tail].c=A[Q[head].row+1][Q[head].col];

                        Q[tail].row = Q[head].row+1;
                        Q[tail].col = Q[head].col;
                        Q[tail].step=Q[head].step+1;
                        if(Q[tail].c=='F'){
                            ans=Q[tail].step;
                            break;
                        }
                        tail++;
                    }
                    if(head>=tail){
                        ans=-1;
                        break;
                    }
                    visit[Q[head].row][Q[head].col]=1;
                    head++;
                }
            printf("%d\n",ans);
            for(j=0;j<505;j++){
                for(k=0;k<505;k++){
                    visit[j][k]=0;
                }
            }
            for(j=0;j<300000;j++){
                Q[j].step=0;
            }
            ans=0;
        }
return 0;
}
