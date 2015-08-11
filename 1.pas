var
n,l,r,i,ans1,ans:longint;
a,b:array[0..20]of longint;
function gcd(x,y:longint):longint;
begin
if y<>0 then exit(gcd(y,x mod y));
exit(x);
end;
procedure search(x,y,m:longint);
var
lc,i,j:longint;
begin
if x=y then
begin
for i:=1 to n do if b[i]<>0 then
begin
lc:=b[i];
break;
end;
for i:=i+1 to n do if b[i]<>0 then
lc:=(lc*b[i])div(gcd(lc,b[i]));
if (y and 1)=1 then inc(ans,m div lc)
else dec(ans,m div lc);
end else
begin
j:=0;
for i:=1 to n do if b[i]<>0 then j:=i;
for i:=j+1 to n do
begin
if n-i+1<y-x then break;
b[i]:=a[i];
search(x+1,y,m);
b[i]:=0;
end;
end;
end;
begin
assign(input,'number3.in');reset(input);
readln(n,l,r);
for i:=1 to n do read(a[i]);
ans:=0;
for i:=1 to n do search(0,i,r);
ans1:=ans;
ans:=0;
if l-1>0 then for i:=1 to n do search(0,i,l-1);
writeln((r-l+1)-(ans1-ans));
close(input);
end. 
