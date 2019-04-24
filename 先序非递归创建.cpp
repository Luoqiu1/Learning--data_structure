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
  bool flat = true; //true�򴴽����ӣ�false�򴴽��Һ���
  p = T;
  p->data = ch;
  Push(S, p);
  while (!StackEmpty(S))
  {
   GetTop(S, p);
   scanf("%c", &ch);
   if (ch != '#')
   {
    if (flat == true)            //��һ��
    {
     if (!(p->lchild = (BiTNode*)malloc(sizeof(BiTNode))))exit(OVERFLOW);
     p = p->lchild;
    }
    else                         //�ڶ���
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
    if (flat == true)            //������
    {
     p->lchild = NULL;
     Push(S, p);
     flat = false;
    }
    else                         //������
    {
     p->rchild = NULL;
     flat = true;
     if (!StackEmpty(S))
     {
      BiTree q;
      GetTop(S, q);
      if (q->lchild != NULL)flat = false;
      while (q->rchild == p)//�ҽ��������ջ
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