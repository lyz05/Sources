type sz=array[1..100000] of longint;
var t,i,j,p:longint;
    n,m,ans,nn,mm:qword;
procedure fj(var a:sz;x:qword;var len:longint);
var y,i:qword;
begin
  i:=2;
  while i<=trunc(sqrt(x)) do
  begin
   if x mod i=0 then
   begin
     a[len]:=i;
     inc(len);
     y:=x div i;
     fj(a,y,len);
     exit;
   end;
   inc(i);
  end;
  a[len]:=x;
  inc(len);
end;
function c(n,m:qword):qword;
var a,b:sz;
    lena,lenb,j:longint;
    i:qword;
begin
  //a=(m+1)*...*n
  //b=1*2*...*(n-m)
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);

  j:=1;
  i:=1;
  while i<=(n-m) do
  begin
    fj(b,i,j);
    inc(i);
  end;
  lenb:=j-1;

  c:=0;
  j:=1;
  i:=m+1-1;
  repeat
   inc(i);
   if lenb<>1 then begin
     fj(a,i,j);
   end else begin
    c:=1;
    c:=c*i;
   end;

  until i>=n;
  lena:=j-1;
  if c<>0 then exit(c);


  i:=1;
  repeat
  j:=1;

   while (b[j]=1) do inc(j);
   if b[j]=0 then break;
   if a[i] mod b[j]=0 then
   begin
     a[i]:=a[i] div b[j];
     b[j]:=1;
   end;
   inc(i);
   if i>lena then i:=i-lena;
  until false;
  c:=1;
  for j:=1 to lena do c:=c*a[j];
end;
begin
    readln(nn,mm,p);
    n:=nn+mm;m:=mm;
    if n-m>m then m:=n-m;
    if n=m then ans:=1 else ans:=c(n,m);
    writeln(ans mod p);
end.
