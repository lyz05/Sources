uses	math;
const	maxn=1000;
var	n,m,i,j,k,x,y,maxx:longint;
	//edge:array[1..maxm,1..2] of longint;
	vx,vy:array[1..maxn] of longint;
	f:array[0..maxn,0..maxn] of longint;
	flag:array[1..maxn,1..maxn] of boolean;
begin
	assign(input,'4006.in');reset(input);
	//assign(output,'.out');rewrite(output);

	fillchar(flag,sizeof(flag),false);
	readln(n,m);
	for i:=1 to m do begin
		readln(x,y);
		flag[x,y]:=true;
	end;
	for i:=1 to n do read(vy[i]);
	for i:=1 to n do read(vx[i]);

	fillchar(f,sizeof(f),0);
	for i:=1 to n do begin
		k:=0;maxx:=0;
		for j:=1 to n do begin
			if flag[i,j] then f[i,j]:=f[i-1,k]+vx[i]+vy[j];
			f[i,j]:=max(max(f[i,j],
				f[i-1,j]),max(f[i,j-1],f[i-1,j-1]));
			if f[i,j]>maxx then begin
				k:=j;
				maxx:=f[i,j];
			end;
		end;
	end;
	writeln(f[n,n]);
end.
