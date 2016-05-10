uses	math;
var x0,ans:int64;
    i,j,k,n:longint;
    a,c,d:array[0..100001] of int64;
    b,f:array[0..100001,1..26] of int64;
begin
	assign(input,'b.in');reset(input);
	assign(output,'b.out');rewrite(output);
	readln(n,x0);
	for i:=1 to n do read(a[i]);
	for i:=1 to n do c[a[i]]:=i;
	for i:=1 to n do for j:=1 to 26 do begin
		x0:=(100000005*x0+1532777326) mod 998244353;
		b[i,j]:=trunc(x0/100) mod 10000;
	end;
	for i:=1 to 26 do f[1,i]:=b[a[1],i];
	for i:=2 to n do
		for j:=1 to 26 do begin
			for k:=1 to j-1 do f[i,j]:=max(f[i,j],f[i-1,k]+b[a[i],j]);
			if c[a[i]+1]>c[a[i-1]+1] then f[i,j]:=max(f[i,j],f[i-1,j]+b[a[i],j]);
		end;
	for i:=1 to 26 do ans:=max(ans,f[n,i]);
	writeln(ans);
	close(input);close(output);
end.

