uses	math;
const	maxn=100000;maxk=5;
var	i,j,k,m,n,root,top:longint;
	f:array[0..maxn,0..maxk] of int64;
	t:array[1..maxn,0..2] of longint;
	fa:array[1..maxn] of longint;
	c,h:array[1..maxn] of int64;
	stack:array[0..maxn] of longint;
	ans:int64;
procedure dfs(x:longint);
var	l,r:longint;
begin
	if x=0 then exit;
	dfs(t[x,1]);
	dfs(t[x,2]);
	for l:=0 to k do 
		for r:=0 to k-l do begin
			f[x,l+r]:=min(max(f[t[x,1],l],f[t[x,2],r])+c[x],f[x,l+r]);
			if l+r+1<=k then 
				f[x,l+r+1]:=Min(Max(f[t[x,1],l],f[t[x,2],r]),f[x,l+r+1]);
		end;
end;
begin
	readln(n,k);
	for i:=1 to n do readln(h[i],c[i]);
	top:=0;
	for i:=1 to n do begin
		j:=top;
		while (j>0) and (h[stack[j]]<h[i]) do dec(j);
		if j<>top then begin
			fa[stack[j+1]]:=i;
		end;
		if j<>0 then fa[i]:=stack[j];
		top:=j+1;
		stack[top]:=i
	end;
	for i:=1 to n do 
		if fa[i]=0 then begin
			root:=i;
		end else begin
			inc(t[fa[i],0]);
			t[fa[i],t[fa[i],0]]:=i;
		end;
	fillchar(f,sizeof(f),$7f div 3);
	f[0,0]:=0;
	dfs(root);
	ans:=high(int64);
	for i:=0 to k do 
		ans:=min(ans,f[root,i]);
	writeln(ans);
end.
