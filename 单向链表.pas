Type
  link=^data;
  data=record
    ch:char;
    next:link;
  End;
Var
  i:integer;
  a:char;
  h,p,q:link;
Begin
  Read(a);{�����һ��aֵ}
  While a<>'@' do
  Begin
    new(p);
    p^.ch:=a;
    p^.next:=q;
    q:=p;
    Read(a);
  End;
  While p<>nil do
  Begin
    Write(p^.ch,' ');
    p:=p^.next;
  End;
End.
