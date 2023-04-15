#include <stdio.h>
#include <stdlib.h>
struct list
{
    char name[100];
    int mark;
    int reg;
    struct list *next;
};
void endinsert(struct list **n)
{
    printf("\n\n\n\n\n\n\n\n");
    struct list *new;
    new = (struct list *)malloc(sizeof(struct list));
    printf("enter name : ");
    scanf("%s", &new->name);
    printf("enter reg_no. : ");
    scanf("%d", &new->reg);
    printf("enter mark : ");
    scanf("%d", &new->mark);
    new->next = NULL;
    struct list *last = *n;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new;
    return;
    printf("\n\n\n\n\n\n\n\n");
}
void see(struct list *n)
{
    printf("\n\n\n\n\n\n\n\n");
    n = n->next;
    while (n != NULL)
    {
        printf("name : %s \n", n->name);
        printf("reg_no. : %d \n", n->reg);
        printf("marks : %d \n", n->mark);
        n = n->next;
        printf("\n");
    }
    printf("\n\n\n\n\n\n\n\n");
}
void insert(struct list **n)
{
    int pos;
    printf("enter the position :");
    scanf("%d", &pos);
    struct list *in = *n, *out = *n;
    for (int i = 0; i < pos - 1; i++)
    {
        in = in->next;
    }
    struct list *new;
    new = (struct list *)malloc(sizeof(struct list));
    printf("enter name : ");
    scanf("%s", &new->name);
    printf("enter reg_no. : ");
    scanf("%d", &new->reg);
    printf("enter mark : ");
    scanf("%d", &new->mark);
    new->next = in->next;
    in->next = new;
    return;
}
void update(struct list *n)
{
    printf("Enter the refg_no. :");
    int m, cheak = (-1);
    scanf("%d", &m);

    while (n != NULL)
    {
        if (n->reg == m)
        {
            m = 5;
            break;
        }
        else
        {
            n = n->next;
        }
    }
    if (m == (-1))
    {
        printf("    Not presents    \n");
    }
    else
    {
        printf("enter name : ");
        scanf("%s", &n->name);
        printf("enter reg_no. : ");
        scanf("%d", &n->reg);
        printf("enter mark : ");
        scanf("%d", &n->mark);
    }
}
void enddelete(struct list **n)
{
    struct list *tr = *n;
    while (tr->next->next != NULL)
    {
        tr = tr->next;
    }
    tr->next = NULL;
}
void middelete(struct list **n)
{
    int pos;
    printf("enter the position :");
    scanf("%d", &pos);
    struct list *in = *n;
    for (int i = 0; i < pos - 1; i++)
    {
        in = in->next;
    }
    in->next=in->next->next;
    
}
int main()
{
    struct list *head;
    head = (struct list *)malloc(sizeof(struct list));
    head->next = NULL;
    do
    {
        int m;
        printf("chose\n  1.insert\n  2.view \n  3.update\n  4.delete \n 5.exit\n");
        scanf("%d", &m);
        if (m == 1)
        {
            printf("chose\n  1.insert at end\n  2.insert at position\n");
            int in;
            scanf("%d", &in);
            if (in == 1)
            {
                endinsert(&head);
            }
            else if (in == 2)
            {
                insert(&head);
            }
        }
        else if (m == 2)
        {
            see(head);
        }
        else if (m == 3)
        {
            update(head);
        }
        else if (m == 5)
        {
            break;
        }
        else if (m == 4)
        {
            printf("chose\n  1.delete at end \n  2.delete at position\n");
            int j;
            scanf("%d", &j);
            if(j==1){
                enddelete(&head);
            }else if (j==2)
            {
                middelete(&head);
            }
            
        }

    } while (1);
}