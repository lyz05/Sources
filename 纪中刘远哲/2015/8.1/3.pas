const	maxn=5000;maxm=5;
var	i,j,k,m,n,tot,p,ans:longint;
	a:array[1..maxm] of longint;
	f:array[0..maxn,0..maxn] of longint;
procedure prepar;
var	i:longint;
begin
	f[1,1]:=1;
	for i:=2 to maxn do begin
		for j:=1 to i do begin
			f[i,j]:=(f[i-1,j]+f[i-1,j-1]) mod p;
		end;
	end;
end;
function c(n,m:longint):longint;
begin
	if n<m then exit(0);
	if (n<maxn) and (m<maxn) then exit(f[n+1,m+1])
	else c:=(c(n-1,m)+c(n-1,m-1)) mod p;
end;
begin
	assign(input,'3.in');reset(input);
	assign(input,'3.out');reset(input);

	tot:=0;
	readln(p);
	readln(n,m);
	for i:=1 to m do begin
		readln(a[i]);
		inc(tot,a[i]);
	end;
	prepar;
	ans:=c(n,tot);
	for i:=1 to m do begin
		ans:=(ans*c(tot,a[i])) mod p;
		dec(tot,a[i]);
	end;
	writeln(ans);
end.
