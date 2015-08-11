const	maxn=100;maxm=5;
var	i,j,k,m,n,tot,p,ans:longint;
	a:array[1..maxm] of longint;
	f:array[0..maxn,0..maxn] of longint;
procedure prepar;
var	i:longint;
begin
	f[1,1]:=1;
	for i:=2 to n+1 do begin
		for j:=1 to i do begin
			f[i,j]:=(f[i-1,j]+f[i-1,j-1]) mod p;
		end;
	end;
end;
function ksm(x,y:int64):int64;
begin
	ksm:=1;
	while y<>0 do begin
		if odd(y) then ksm:=(ksm*x) mod p;
		x:=(x*x) mod p;
		y:=y>>1;
	end;
end;
function jc(x:longint):int64;
var	i:longint;
begin
	jc:=1;
	for i:=2 to x do jc:=(jc*i) mod p;
end;
function c(n,m:longint):int64;
begin
	//c:=jc(n) div (jc(m)*jc(n-m));
	
	c:=jc(n);
	c:=(c*ksm(jc(m),p-2)) mod p;
	c:=(c*ksm(jc(n-m),p-2)) mod p;
	
end;
begin
	//assign(input,'3449.in');reset(input);

	tot:=0;
	readln(p);
	readln(n,m);
	for i:=1 to m do begin
		readln(a[i]);
		inc(tot,a[i]);
	end;
	
	ans:=c(n,tot);
	for i:=1 to m do begin
		ans:=(ans*c(tot,a[i])) mod p;
		dec(tot,a[i]);
	end;
	if ans=0 then ans:=1;
	writeln(ans);
end.

