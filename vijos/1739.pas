var x:array[0..3000,0..3000]of longint;{(ax+by)^k--x^n*y^m}
c,sx,sy,s,f,f1,f2,a,b,k,n,m:longint;
begin
{assign(input,'factor.in');
reset(input);
assign(output,'factor.out');
rewrite(output);}
read(a,b,k,n,m);
a:=a mod 10007;
b:=b mod 10007;
sx:=1;sy:=1;
for f:=1 to n do sx:=(sx*a) mod 10007;
for f:=1 to m do sy:=(sy*b) mod 10007;
s:=(sx*sy) mod 10007;//writeln(s);
x[1,1]:=1;
for f:=2 to k+1 do
for f1:=1 to f do
begin
x[f,f1]:=x[f,f1] mod 10007;
x[f-1,f1-1]:=x[f-1,f1-1]mod 10007; // begin
x[f,f1]:=x[f-1,f1]+x[f-1,f1-1]mod 10007;// write(x[f,f1]);end;
end;
x[k+1,1+k-n]:=x[k+1,k+1-n]mod 10007;
s:=s*x[k+1,1+k-n]mod 10007;
write(s mod 10007);
{close(input);
close(output);}
end.
