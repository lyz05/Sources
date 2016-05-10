uses	math;
const	maxn=5000;maxm=maxn;
var	i,j,k,m,n,x,y,z:longint;
	f:array[0..maxn-1,0..maxm-1] of longint;
begin
	readln(n,m,k);
	for i:=1 to k do begin
		readln(x,y,z);
		f[x,y]:=z;
	end;
	for i:=0 to n-1 do begin
		for j:=0 to m-1 do begin
                        if (i=j) and (i=0) then continue;
			if i=0 then f[i,j]:=f[i,j-1]+f[i,j] else
			if j=0 then f[i,j]:=f[i-1,j]+f[i,j] else
                        f[i,j]:=max(f[i,j]+f[i-1,j],f[i,j]+f[i,j-1]);
		end;
	end;

	writeln(f[n-1,m-1]);
end.
