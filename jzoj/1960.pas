uses math;
const maxn=100000;maxl=trunc(ln(maxn)/ln(2))+1;
var	i,j,k,m,n,x,y,z,l,r,ans:longint;
	a:array[1..maxn] of longint;
	f:array[0..maxn,0..maxl] of longint;
procedure prepar;
var i,j:longint;
begin
	fillchar(f,sizeof(f),0);
	for i:=1 to maxn do f[i,0]:=a[i];
	for j:=1 to Trunc(Ln(n)/Ln(2)) do
		for i:=1 to n-1 shl j+1 do
			f[i,j]:=Max(f[i,j-1],f[i+1 shl (j-1),j-1]);
end;
procedure change(l,r,x:longint);
var i:longint;
begin
	for j:=l to Trunc(Ln(r)/Ln(2)) do
		for i:=l to r-1 shl j+1 do
			inc(f[i,j],x);
end;
begin

	readln(n);
	for i:=1 to n do read(a[i]);
	readln(m);

	prepar;
        for i:=1 to m do begin
		read(k);
		if k=2 then begin
			read(l,r);
			k:=trunc(ln(r-l+1)/ln(2));
			ans:=max(F[l,k],F[r-1 shl k+1,k]);
                        writeln(ans);
		end else begin
			read(x,y,z);
			change(x,y,z);
		end;
		
	end;
	
end.
