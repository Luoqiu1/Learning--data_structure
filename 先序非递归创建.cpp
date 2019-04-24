Status CreateBiTree(BiTree &T)
{
 char ch;
 SqStack S;
 InitStack(S);
 scanf("%c", &ch);
 if (ch == '#')T = NULL;
 else
 {
  if (!(T = (BiTree)malloc(sizeof(BiTNode))))exit(OVERFLOW);
  BiTree p;
  bool flat = true; //true则创建左孩子，false则创建右孩子
  p = T;
  p->data = ch;
  Push(S, p);
  while (!StackEmpty(S))
  {
   GetTop(S, p);
   scanf("%c", &ch);
   if (ch != '#')
   {
    if (flat == true)            //第一种
    {
     if (!(p->lchild = (BiTNode*)malloc(sizeof(BiTNode))))exit(OVERFLOW);
     p = p->lchild;
    }
    else                         //第二种
    {
     if (!(p->rchild = (BiTNode*)malloc(sizeof(BiTNode))))exit(OVERFLOW);
     p = p->rchild;
     flat = true;
    }
    p->data = ch;
    Push(S, p);
   }
   else
   {
    Pop(S, p);
    if (flat == true)            //第三种
    {
     p->lchild = NULL;
     Push(S, p);
     flat = false;
    }
    else                         //第四种
    {
     p->rchild = NULL;
     flat = true;
     if (!StackEmpty(S))
     {
      BiTree q;
      GetTop(S, q);
      if (q->lchild != NULL)flat = false;
      while (q->rchild == p)//右结点连续出栈
      {
       Pop(S, p);
       GetTop(S, q);
       if(!StackEmpty(S))flat = false;
      }
     }
    }
   }
  }
 }
 return OK;
}