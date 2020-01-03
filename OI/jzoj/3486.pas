const	maxn=1500;maxm=100000;
type	node=record
		y,k,next:longint;
	end;
var	i,j,k,m,n,ans,tot,tot1,tmp,x,y:longint;
	e,a:array[1..maxn] of longint;
	h:array[1..2*maxm] of node;
	vis,flag:array[1..maxn] of boolean;
function dfs(x,y,k:longint):boolean;
var	i:longint;
begin
	vis[x]:=true;
	dfs:=false;
	if x=y then exit(true);
	i:=e[x];
	while i<>0 do begin
		if ((h[i].k=0) or (h[i].k=k)) and (not vis[h[i].y]) then 
		begin
			if dfs(h[i].y,y,k) then exit(true);
		end;
		i:=h[i].next;
	end;
	vis[x]:=false;
end;
function judge(x,y,k:longint):boolean;
begin
	fillchar(vis,sizeof(vis),0);
	judge:=dfs(x,y,k);
	fillchar(vis,sizeof(vis),0);
	judge:=judge and dfs(y,x,k);
end;
procedure add(x,y,z:longint);
begin
	inc(tot1);
	h[tot1].y:=y;
	h[tot1].k:=z;
	h[tot1].next:=e[x];
	e[x]:=tot1;
end;
begin
	assign(input,'3486.in');reset(input);

	readln(n,m);
	for i:=1 to m do begin
		readln(x,y);
		add(x,y,0);
		add(y,x,i);
	end;
	tot:=0;
	for k:=1 to m do begin
		fillchar(flag,sizeof(flag),0);
		tmp:=0;
		for i:=1 to n do 
		for j:=i+1 to n do
			if judge(i,j,k) then begin
				if not flag[i] then begin
					inc(tmp);
					flag[i]:=true;
				end;
				if not flag[j] then begin
					inc(tmp);
					flag[j]:=true;
				end;
			end;
		if tmp>tot then begin
			tot:=tmp;
			ans:=0;
		end;
		if tmp=tot then begin
			inc(ans);
			a[ans]:=k;
		end;
	end;
	writeln(tot);
	writeln(ans);
	for i:=1 to ans do write(a[i],' ');
	writeln;
end.
