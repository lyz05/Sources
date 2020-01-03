uses	math;
const   dir:array[1..4,1..2] of longint=((0,1),(0,-1),(1,0),(-1,0));
	maxn=1000+2;
var	i,j,k,m,n,tot,l,r,mid:longint;
	a:array[1..maxn,1..maxn] of longint;
	num:array[0..(maxn-2)*maxn] of longint;
	p:array[1..maxn,1..maxn] of boolean;
procedure sort(l,r:longint);
var     i,j,m:longint;
begin
        i:=l;
        j:=r;
        m:=num[(l+r) shr 1];
        while i<j do begin
                while num[i]<m do inc(i);
                while num[j]>m do dec(j);
                if i<=j then begin
                        num[0]:=num[i];
                        num[i]:=num[j];
                        num[j]:=num[0];
                        inc(i);dec(j);
                end;
        end;
        if i<r then sort(i,r);
        if j>l then sort(l,j);
end;
function dfs(x,y,top:longint):boolean;
var	i,tx,ty:longint;
begin
	if x=n-1 then exit(true);
	for i:=1 to 4 do begin
		tx:=x+dir[i,1];ty:=y+dir[i,2];
		if (tx<1)or(tx>n)or(ty<1)or(ty>m) then continue;
		if p[tx,ty] then continue;
		if a[tx,ty]>top then continue;
		p[tx,ty]:=true;
		if dfs(tx,ty,top) then exit(true);
	end;
	exit(false);
end;
begin
	assign(input,'3428.in');reset(input);

	tot:=0;
	readln(n,m);
	for i:=1 to n do
		for j:=1 to m do begin
			read(a[i,j]);
		end;
	for i:=2 to n-1 do
		for j:=1 to m do begin
			inc(tot);
			num[tot]:=a[i,j];
		end;
	sort(1,tot);

	l:=1;r:=tot;
	while l<>r do begin
		fillchar(p,sizeof(p),0);
		mid:=(l+r)>>1;
		if dfs(1,1,num[mid]) then r:=mid else l:=mid+1;
	end;
	writeln(num[l]);
end.
