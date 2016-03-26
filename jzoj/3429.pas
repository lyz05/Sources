uses	math;
const	dir:array[1..4,1..2] of longint=((1,0),(-1,0),(0,1),(0,-1));
	maxn=100;
var	i,j,k,m,n,l,r,mid,minn,maxx,ans:longint;
	a:array[1..maxn,1..maxn] of longint;
	p:array[1..maxn,1..maxn] of boolean;
function dfs(x,y,l,r:longint):boolean;
var	i,tx,ty:longint;
begin
	if (a[x,y]<l) or (a[x,y]>r) then exit(false);
	if (x=n) and (y=m) then exit(true);
	for i:=1 to 4 do begin
		tx:=x+dir[i,1];
		ty:=y+dir[i,2];
		if (tx<1)or(tx>n)or(ty<1)or(ty>m)or(p[tx,ty]) then
			continue;
		if (a[tx,ty]<l) or (a[tx,ty]>r) then continue;
		p[tx,ty]:=true;
		if dfs(tx,ty,l,r) then exit(true);	
	end;
	exit(false);
end;
begin
	assign(input,'3429.in');reset(input);

	minn:=maxlongint;maxx:=0;
	readln(n,m);
	for i:=1 to n do 
		for j:=1 to m do begin
			read(a[i,j]);
			if a[i,j]<minn then minn:=a[i,j];
			if a[i,j]>maxx then maxx:=a[i,j];
		end;
	ans:=maxlongint>>1;
	for i:=minn to maxx do begin
		l:=i;r:=maxx;
		while l<>r do begin
			fillchar(p,sizeof(p),0);
			mid:=(l+r)>>1;
			p[1,1]:=true;
			if dfs(1,1,i,mid) then begin
				ans:=min(ans,mid-i);
				r:=mid;
			end else l:=mid+1;
		end;
	end;
	writeln(ans);
end.
