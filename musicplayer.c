#include <stdio.h>
#include <stdlib.h>

struct Node
{
 int data;
 struct Node *next;
 struct Node *prev;
}*first=NULL,*a=NULL;

int count(struct Node *p)
{
 int l=0;
 while(p)
 {
 l++;
 p=p->next;
 }
 return l;
}

void Display(struct Node *p)
{
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
}

void insert(struct Node *p,int pos, int x)
{
    struct Node *t;
    int i;
if(pos < 0)
{
  printf("not possible");
 return;
}
t=(struct Node *)malloc(sizeof(struct Node));
t->data=x;

 if(pos==0)
 {

     t->prev=NULL;
     t->next=first;
     first =t;

}
 else
 {
     for(i=0;i<pos-1;i++)
     {
        p=p->next;
     }

    t->prev=p;
    t->next=p->next;
    if(p->next)
    {
        p->next->prev=t;
    }
    p->next=t;
 }
}
int Delete(struct Node *p,int index)
{
 int x,i;

 if(index < 1 || index > count(p))
 return -1;
 if(index==1)
 {
 first=first->next;
 if(first)first->prev=NULL;

 x=p->data;

 free(p);
 return x;
 }
  else
 {
 for(i=0;i<index-1;i++)
 {
 p=p->next;
 }
 p->prev->next=p->next;
 if(p->next)
    p->next->prev=p->prev;
 x=p->data;
 free(p);
 }
 return x;
}

void playfirst(struct Node *p)
{

    printf("playing first song\n song number: %d",first->data);
    a=p;

}
void playlast(struct Node *p)
{
    int x=-1;
 while(p->next!=NULL)
 {
 p=p->next;
 }
 x=p->data;
    printf("playing last song. song number:%d",x);
    a=p;
}

void playspecific(struct Node *p, int pos)
{

    int i,x=-1;
    for(i=0;i<pos-1;i++)
    {
      p=p->next;
    }
    x=p->data;
    printf("playing specific song. song number:%d",x);
    a=p;

}

void playprevious(struct Node *p)
{
    int x=-1;
    x=a->prev->data;
    printf("playing previous song: %d",x);
    a=a->prev;
}
void playnext(struct Node *p)
{
    int x=-1;
    if(p == NULL)
    {
        printf("no more songs");
    }
    else
    {
    x=a->next->data;
    printf("playing next song: %d",x);

    }


}
int main()
{
 int ch,pos,data,k;

 while(1)
 {
 printf("\n enter choice \n 1.add song to  list\n 2. display\n 3. delete song from list\n 4. play first song\n 5. play last song\n 6.enter song no you want to play\n 7.play previous\n 8.play next\n");
 scanf("%d",&ch);
 switch(ch)
 {
     case 1:
         printf("\n enter position and data\n ");
        scanf("%d %d",&pos,&data);
        insert(first,pos,data);
        break;

     case 2:
          Display(first);
          break;
     case 3:
         printf("\n enter position \n ");
        scanf("%d",&pos);
        Delete(first,pos);
        break;
     case 4:
         playfirst(first);
         break;
     case 5:

        playlast(first);
        break;
     case 6:
        printf("\n enter position \n ");
        scanf("%d",&pos);
        playspecific(first,pos);
        break;
     case 7:
        playprevious(first);
        break;
     case 8:
        playnext(first);
        break;
 }
}
}

