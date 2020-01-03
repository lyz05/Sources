const max=50000;
var t,k,i,j,m,n,fang:longint;
    a,b,c,d:array[0..max] of longint;
    p:boolean;
procedure fj(x:longint);
var i:longint;
begin
  i:=2;k:=0;
  fillchar(c,sizeof(c),0);
  fillchar(d,sizeof(d),0);
  repeat
    if x mod i=0 then begin
      x:=x div i;
      if c[k]<>i then inc(k);
      c[k]:=i;
      inc(d[k]);
    end else inc(i);
  until x=1;
end;
function jc(x:longint):qword;
var i:longint;
begin
  jc:=1;
  for i:=2 to x do jc:=jc*i;

end;
function fans:qword;
var i,j:longint;
    x,y:qword;
begin
  x:=1;y:=1;j:=0;
  for i:=1 to k do begin
    y:=y*jc(d[i]);
    inc(j,d[i]);
  end;
  x:=jc(j);
  fans:=x div y;
end;
begin
  for i:=2 to max do
  begin
    fj(i);
    p:=true;
    for j:=2 to k do
     if (d[j-1]-d[j])<0 then begin
      p:=false;
      break;
     end;
    if p then
      fang:=fans;
      if a[fang]=0 then begin
        a[fang]:=i;
      end;

  end;
  readln(t);
  for i:=1 to t do begin
    readln(n);
    writeln(a[n]);
  end;
end.
