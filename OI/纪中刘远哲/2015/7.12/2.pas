const	maxn=30+2;
var	i,j,k,m,n,tmp,ans:longint;
	a:array[1..maxn,1..maxn] of longint;
	h,l:array[1..maxn] of integer;
procedure dfs(x,y:longint);
var	i:longint;
begin
	if y>m then begin
		inc(x);y:=1;
	end;
	if x>n then begin
		if tmp>ans then
                        ans:=tmp;
		exit;
	end;
	for i:=0 to 1 do begin
		if odd(i) then begin
			if (h[x]=2) or (l[y]=2) then continue;
			inc(h[x]);inc(l[y]);
			tmp:=tmp+a[x,y];
				dfs(x,y+1);
			tmp:=tmp-a[x,y];
			dec(h[x]);dec(l[y]);
		end else dfs(x,y+1);
	end;
end;
begin
	assign(input,'pick.in');reset(input);
	assign(output,'pick.out');rewrite(output);

	readln(n,m);
	for i:=1 to n do
		for j:=1 to m do
			read(a[i,j]);
	dfs(1,1);
	writeln(ans);

	close(input);close(output);
end.
