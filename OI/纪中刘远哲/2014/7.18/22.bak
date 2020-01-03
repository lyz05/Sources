const max=100000;
type sz=array[1..max] of longint;
var i,n,k:qword;
    j:longint;
    a,b,ans,tmp:sz;
    p:boolean;
function len(var x:sz):longint;
var i:longint;
begin
  i:=max;
  while x[i]=0 do dec(i);
  len:=i;
end;
function jf(x,y:sz):sz;//高精度加法
var i,j,lenx,leny,lenmax,k:longint;
    z:sz;
begin
  fillchar(z,sizeof(z),0);
  lenx:=len(x);leny:=len(y);
  if lenx>leny then lenmax:=lenx else lenmax:=leny;
  k:=0;
  for i:=1 to lenmax do
  begin
    z[i]:=x[i]+y[i]+k;
    k:=z[i] div 10;
    z[i]:=z[i] mod 10;
  end;
  if k>0 then z[i+1]:=k;
  jf:=z;
end;
function unjf(a,b:sz):sz;
var i,l:longint;
begin
    fillchar(unjf,sizeof(unjf),0);
    l:=len(a);
    if len(b)>l then l:=len(b);
    for i:=1 to l do
    begin
     if a[i]<b[i]  then
       begin
         a[i+1]:=a[i+1]-1;
         a[i]:=a[i]+10 ;
       end;
     unjf[i]:=a[i]-b[i];
    end;
end;
begin
  readln(n,k);
  if n=1 then
  begin
    if k=1 then writeln(1) else writeln(-1);
    exit;
  end;
  if n=2 then
  begin
    if k<=3 then writeln(k) else writeln(-1);
    exit;
  end;

  a[1]:=1;b[1]:=n;
  i:=1; tmp[1]:=1;
  while i<=k do
  begin
    ans:=jf(ans,jf(unjf(b,a),tmp));
    p:=false;
    if len(k)<=len(ans) then p:=true;
    if p then
     for j:=len(k) downto 1 do
      if ans[j]>k[j] then break else
       if ans[j]<k[j] then p:=false;

    if p then begin
      fillchar(tmp,sizeof(tmp),0);
      tmp:=jf(unjf(b,ans),k);
      for j:=len(tmp) downto 1 do write(tmp[j]);
      exit;
    end;
    fillchar(tmp,sizeof(tmp),0);
    tmp[1]:=1;
    a:=jf(jf(a,a),tmp);
    b:=unjf(jf(b,b),1);
    inc(i);
  end;
  writeln(-1);
end.
