var n:integer;
    a:array[1..100] of int64;
    k,ans:qword;
function pc(v1,k:integer):boolean;{����ȫ����,���غ���}
var i:integer;
begin
   for i:=1 to v1-1 do
      if a[i]=k then
         begin pc:=false;exit;end;
   pc:=true;
end;
procedure out; {����ȫ���У��������}
var i,c:integer;
begin
   c:=c+1;
   for i:=1 to n do
      write(a[i],' ');
   halt;
end;
procedure szqplss(v:integer);  {����ȫ��������}
var i:integer;
begin
   if v>n then begin
    inc(ans);
    if ans=k then out;
    exit;
   end;
   for i:=1 to n do
    if pc(v,i) then begin
     a[v]:=i;
     szqplss(v+1);
     end;
end;
begin
  k:=0;
  ans:=0;
  readln(n,k);
  szqplss(1);
end.
