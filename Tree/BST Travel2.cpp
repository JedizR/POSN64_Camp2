//bst travel2
#include <bits/stdc++.h>

using namespace std;
typedef struct node{
    int num;
    struct node *l,*r;
}node;
node *root,*run,*now;
node* newnode(int num){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->num=num;
    temp->l=temp->r=NULL;
    return temp;
}
void pre(node*run)
{
    if(run==NULL) return;
    cout << run->num << " ";
    pre(run->l);
    pre(run->r);
}
void post(node*run)
{
    if(run==NULL) return;
    post(run->l);
    post(run->r);
    cout << run->num << " ";
}
void in(node*run)
{
    if(run==NULL) return;
    in(run->l);
    cout << run->num << " ";
    in(run->r);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,num,i;
    cin >> n >> num;
    root=newnode(num);
    run=newnode(num);
    for(i=0;i<n-1;i++)
    {
        cin >> num;
        now=newnode(num);
        run=root;
        while(1)
        {
            if(num<run->num)
            {
                if(run->l==NULL)
                {
                    run->l=now;
                    break;
                }
                run=run->l;
            }
            else
            {
                if(run->r==NULL)
                {
                    run->r=now;
                    break;
                }
                run=run->r;
            }
        }
    }
    pre(root); cout << "\n";
    post(root); cout << "\n";
    in(root); cout << "\n";

    return 0;
}
