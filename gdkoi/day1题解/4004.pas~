const	maxn=10000+5;
var	i,j,m,n:longint;
	e:array[0..maxn div 2,1..2] of longint;
	ans:array[0..maxn] of longint;
procedure dfs(x:longint);
var	i,nx,now:longint;
begin
	now:=x;
	x:=x mod (n div 2);
	for i:=2 downto 1 do begin
		if e[x,i]=-1 then continue;
		nx:=e[x,i];
		e[x,i]:=-1;
		dfs(nx);
	end;
	inc(ans[0]);
	ans[ans[0]]:=now;
end;
begin
	readln(n);
	if odd(n) then writeln(-1) else begin
		for i:=0 to n div 2-1 do begin
			e[i,1]:=i*2;
			e[i,2]:=i*2+1;
		end;
		dfs(0);
		if ans[0]<>0 then begin
			for i:=ans[0] downto 1 do write(ans[i],' ');
			writeln;
		end else writeln(-1);
	end;
end.
