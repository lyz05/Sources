uses math;
const	maxn=100+5;
type	node=record
		fa,l,r,size:longint;
	end;
var	i,k,n,x,y:longint;
	tree:array[1..maxn] of node;
	f:array[1..maxn,1..maxn] of int64;
	a:array[1..maxn] of longint;
procedure dp(x:longint);
var	i,j:longint;
	flag:boolean;
begin
	if tree[x].l<>0 then dp(tree[x].l);
	if tree[x].r<>0 then dp(tree[x].r);
	f[x,0]:=0;
	f[x,1]:=a[x];
	for i:=2 to tree[x].size do begin
		flag:=false;
		if (tree[x].l<>0) and (tree[x].r<>0) then begin
			for j:=0 to i-1 do begin
				if (j>tree[tree[x].l].size) or ((i-j-1)>(tree[tree[x].r].size)) then continue;
				if flag then
					f[x][i]:=max(f[x][i],f[tree[x].l][j]+f[tree[x].r][i-j-1]+a[x])
				else begin
					f[x][i]:=f[tree[x].l][j]+f[tree[x].r][i-j-1]+a[x];
					flag:=true;
				end;
			end;
		end else begin
			if (tree[x].l<>0) then
				f[x][i]:=f[tree[x].l,i-1]+a[x];
			if (tree[x].r<>0) then
				f[x][i]:=f[tree[x].r,i-1]+a[x];
		end;
	end;
end;
procedure dfs(x:longint);
begin
	if tree[x].l<>0 then dfs(tree[x].l);
	if tree[x].r<>0 then dfs(tree[x].r);
	tree[x].size:=tree[tree[x].l].size+tree[tree[x].r].size+1;
end;
begin
        //assign(input,'3914.in');reset(input);
	readln(n,k);
	a[1]:=0;
	for i:=1 to n-1 do read(a[i+1]);
	for i:=1 to n do begin
		readln(x,y);
		tree[i].l:=x;tree[i].r:=y;
		tree[x].fa:=i;tree[y].fa:=i;
	end;
	dfs(1);
	for i:=1 to n do f[i,0]:=0;
	dp(1);
	writeln(f[1,k+1]);
end.
