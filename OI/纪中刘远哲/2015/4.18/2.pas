const	maxa=1000000000000000;
var	i,j,k,m,n:longint;
	a:array[1..maxn] of longint;
	p:array[1..maxn] of boolean; 
	ans:int64;
procedure calc;
var	t:longint;
begin
	if odd(cnt) then t:=1 else t:=-1;
	ans:=ans+t*cnt*n div lcm;
end;
procedure dfs(dep:longint);
var	i:longint;
begin
	if dep>n then begin
		calc;
		exit;
	end;
	for i:=0 to 1 do begin
		if odd(i) then begin
			p[dep]:=true;
			inc(cnt);
				dfs(dep+1);
			dec(cnt);
			p[dep]:=false;
		end else dfs(dep+1);
	end;
end;
function judge(x:int64):boolean;
begin
	ans:=0;cnt:=0;
	dfs(1);
end;
function half:int64;
var	l,r,mid:int64;
begin
	l:=1;r:=maxa;
	while l<=r do begin
		mid:=(l+r)>>1;
		if judge(mid) then r:=mid-1 else l:=mid+1;
	end;
	exit(mid+1);
end;
begin
	readln(n,k);
	for i:=1 to n do read(a[i]);
	writeln(half);
end.
