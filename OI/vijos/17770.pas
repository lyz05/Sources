program aa;
const
 t:array[1..4,1..2]of -1..1=((0,1),(1,0),(0,-1),(-1,0));
var
 a:Array[0..510,0..510]of int64;
 b:array[0..510,0..510]of boolean;
 c:Array[0..510,0..510]of int64;
 d:array[0..510,0..510]of int64;
 e:array[0..510]of boolean;
 n,m,i,j,k,l,o,p,ans,max:longint;
procedure try(x,y:longint);
 var
  j:longint;
 begin
  if(x=1)then e[y]:=false;
  if(x=n)then begin
   inc(c[y,0]);
   c[y,c[y,0]]:=i;
  end;
  for j:=1 to 4 do
   if(x+t[j,1]>0)and(x+t[j,1]<n+1)and(y+t[j,2]>0)and(y+t[j,2]<m+1)then
    if(b[x+t[j,1],y+t[j,2]])and(a[x,y]>a[x+t[j,1],y+t[j,2]])then begin
     b[x+t[j,1],y+t[j,2]]:=false;
     try(x+t[j,1],y+t[j,2]);
    end;
 end;
begin
 assign(input,'1777.in');reset(input);
 //assign(output,'flow.out');rewrite(output);
 readln(n,m);
 for i:=1 to n do
  for j:=1 to m do read(a[i,j]);
 fillchar(e,sizeof(e),true);
 for i:=1 to m do
  if(e[i])then begin
  fillchar(b,sizeof(b),true);
  b[1,i]:=false;
  try(1,i);
 end;
 for i:=1 to m do
  if(c[i,0]=0)then inc(ans);
 if(ans<>0)then begin
  writeln('0');
  writeln(ans);
  close(input);close(output);
  exit;
 end;
 fillchar(e,sizeof(e),true);
 ans:=0;  k:=0;
 repeat
  fillchar(d,sizeof(d),0);
  for i:=1 to m do
   if(e[i])then
    for j:=1 to c[i,0] do begin
     inc(d[c[i,j],0]);
     d[c[i,j],d[c[i,j],0]]:=i;
    end;
  max:=-maxlongint;
  for i:=1 to m do
   if(d[i,0]>max)then begin
    max:=d[i,0];
    p:=i;
   end;
  for i:=1 to d[p,0] do begin
   e[d[p,i]]:=false;
   inc(k);
  end;
  inc(ans);
 until(k=m);
 writeln('1');
 writeln(ans);
 close(input);close(output);
end.
