type	node=record
		next,y:longint;
	end;
var	i,j,k,m,n:longint;
	a,e:array[0..maxn] of longint;
	h:array[1..maxn] of node;
procedure add(x,y:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].next:=e[x];
	e[x]:=tot;
end;
procedure cut(x,y:longint);
var	i:longint;
begin
	i:=e[x];
	while i<>0 do begin
		if (h[i].y=y) and (h[i].y<>0) then begin
			h[i].y:=0;
			break;
		end;
		i:=h[i].next;
	end;
end;
procedure init;
begin
	
end;
function dfs(x,y:longint):boolean;
var	i:longint;
begin
	i:=e[x];
	while i<>0 do begin
		if h[i].y<>0 then begin
			if h[i].y=y then exit(true);
			if dfs(h[i].y,y) then exit(true);
			
		end;
		i:=h[i].next;
	end;
	exit(false);
end;
procedure change(x,y:longint);
var	i:longint;
begin
	init;
	dfs(y,x);
	cut(a[a[0]-1],x);
	cut(x,a[a[0]-1]);
	add(x,y);
	add(y,x);
end;
function quary(x,y:longint):longint;
var	i,j,ans:longint;
begin
	init;
	dfs(y,x);
	ans:=a[0] div 2;
	for i:=1 to a[0] do begin
		ans:=max(ans,work(i));
	end;
	exit(ans);
end;
begin
	readln(n);
	for i:=1 to n-1 do begin
		readln(x,y);
		add(x,y);
		add(y,x);
	end;
	readln(m);
	for i:=1 to m do begin
		readln(ch,x,y);
		if ch='Q' then quary(x,y) else change(x,y);
	end;

end.
