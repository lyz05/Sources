uses	math;
const	maxn=1000+5;maxm=1000+5;
var	i,j,k,m,n,top:longint;
	a,map,s:array[1..maxm,1..maxn] of int64;
	f,g,stack,id:array[1..maxn] of int64;
	ans:int64;
begin
	assign(input,'4260.in');reset(input);
	readln(m,n);
	for i:=1 to m do 
		for j:=1 to n do 
			read(a[i,j]);

	for i:=1 to m-1 do
		for j:=1 to n-1 do begin
			if a[i,j]+a[i+1,j+1]<=a[i+1,j]+a[i,j+1] then 
			begin
				map[i,j]:=1;
			end;
		end;
	for j:=1 to n do begin
		s[m+1,j]:=1;
		for i:=m downto 1 do begin
			if map[i][j]=0 then s[i][j]:=1
			else s[i][j]:=s[i+1][j]+map[i][j];
		end;
	end;
	ans:=0;
	for i:=1 to m do begin
		top:=0;
		for j:=1 to n do begin
			while (top>0) and (stack[top]>=s[i][j]) do dec(top);
			if top>0 then f[j]:=id[top] else f[j]:=0;
			inc(top);
			stack[top]:=s[i][j];
			id[top]:=j;
		end;
		top:=0;
		for j:=n downto 1 do begin
			while (top>0) and (stack[top]>=s[i][j]) do dec(top);
			if top>0 then g[j]:=id[top] else g[j]:=n+1;
			inc(top);
			stack[top]:=s[i][j];
			id[top]:=j;
		end;
		for j:=1 to n do begin
			ans := max((g[j]-f[j])*s[i][j],ans);
		end;
	end;
	writeln(ans);
end.
