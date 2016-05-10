const	maxn=40;maxm=102334155;mo=258280327;
var	i,j,k,n,T,ans,st:longint;
	m:int64;
	f:array[1..maxm] of longint;
	g:array[1..maxn] of longint;
procedure prepar;
begin
	f[1]:=0;f[2]:=0;f[3]:=1;f[4]:=1;
	g[1]:=1;g[2]:=1;
	for i:=3 to n do g[i]:=g[i-1]+g[i-2];

	j:=3;i:=5;st:=f[i-1];
	while i<=m do begin
		for k:=1 to g[j] do begin
			f[i]:=(st+k) mod mo;
			inc(i);
			if i>m then break;
		end;
		for k:=1 to g[j] do begin
			f[i]:=(st+k) mod mo;
			inc(i);
			if i>m then break;
		end;
		inc(j);
		st:=f[i-1];
	end;
end;
begin
	assign(input,'love.in');reset(input);
	assign(output,'love.out');rewrite(input);
	m:=maxm;n:=maxn;
	prepar;
	readln(T);

	while T<>0 do begin
		readln(n,m);
		if n<=2 then begin
			writeln(0);
			dec(T);
			continue;
		end;
		//for i:=1 to m do writeln(f[i]);
		writeln(f[m]);
		dec(T);
	end;
end.
