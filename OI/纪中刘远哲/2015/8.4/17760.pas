var
 x:array[1..200000] of extended;[x�����洢����Ƶ��]
 n:longint;
 m:extended;
procedure init;[�����]
var
 i:longint;
begin
 readln(n,m);
 m:=1/m;
 for i:=1 to n do begin
  readln(x[i]);
  x[i]:=x[i]*m;
 end;
end;

procedure swap(var a,b:extended);[����]
var
 tmp:extended;
begin
 tmp:=a;
 a:=b;
 b:=tmp;
end;

procedure down(r,l:longint);
[��һ���ǰ���С�ķŵ�ǰ�棨�����ټӸ�ѭ���ͱ������......��]
var
 j:longint;
begin
 j:=r shl 1;[shl 1=��2��ֻ�Ǹ���]
 while j<=l do begin
  if (j<l)and(x[j+1]<x[j]) then inc(j);
  if x[j]<x[r] then begin
   swap(x[j],x[r]);
   r:=j;
   j:=r shl 1;
  end else break;
 end;
end;

procedure work;
var
 i:longint;
 ans:extended;
begin
 for i:=n downto 1 do down(i,n);
 ans:=0;
 for i:=n downto 2 do begin
  swap(x[i],x[1]);
  down(1,i-1);
  x[1]:=x[1]+x[i];[�ϲ�]
  ans:=ans+x[1];
  down(1,i-1);
 end;
 writeln(ans:0:6);
end;

begin
 init;
 work;
end.
