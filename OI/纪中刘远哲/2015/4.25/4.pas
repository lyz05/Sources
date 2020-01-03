uses	math;
const	maxn=10000+3;maxm=50000+3;
type	node=record
		y,val,next:longint;
	end;
var	i,j,k,m,n,tot,s,ans,u,vv,x,y,z:longint;
	v,e:array[1..maxn] of longint;
	p:array[1..maxn] of boolean;
	h:array[1..2*maxm] of node;
procedure add(x,y,val:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].val:=val;
	h[tot].next:=e[x];
	e[x]:=tot;
end;
procedure dfs(dep,x,now,dis:longint);
var	i:longint;
begin
	if dis>s then exit;
	if x=vv then begin
		ans:=min(ans,now);
		exit;
	end;
	i:=e[x];
	while i<>0 do begin
		if not p[h[i].y] then begin
			p[h[i].y]:=true;
			dfs(dep+1,h[i].y,max(now,v[h[i].y]),dis+h[i].val);
			p[h[i].y]:=false;
		end;
		i:=h[i].next;
	end;
end;
begin
	assign(input,'4.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m,u,vv,s);
	for i:=1 to n do read(v[i]);
	for i:=1 to m do begin
		readln(x,y,z);
		add(x,y,z);
		add(y,x,z);
	end;
	ans:=maxlongint>>1;p[u]:=true;
	dfs(1,u,v[u],0);
	if ans<maxlongint>>1 then writeln(ans) else writeln(-1);
end.
