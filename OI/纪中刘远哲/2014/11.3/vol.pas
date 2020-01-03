const 	maxn=500000;
type	node=record
		fa,val:longint;
	end;
var	i,j,k,m,n:longint;
	h:array[1..maxn] of node;
	fa:array[1..maxn,0..deep] of longint;
	kk:array[1..maxn] of longint;
	p:array[1..maxn] of boolean;
procedure up(x:longint;bj:boolean);
var i,xx:longint;
begin
	if fa[x,0]<>0 then exit;
	xx:=x;
	while xx.fa<>0 do begin
		inc(fa[x,0]);
		fa[fa[x,0],xx];
		if bj then p[xx]:=true;
		xx:=xx.fa;
	end;
end;
begin
	//assign(input,'vol.in');reset(input);
	//assign(output,'vol.out');rewrite(output);
	readln(n,k);
	for i:=1 to n-1 do begin
		readln(x,y,z);
		if x.fa=0 then swap(x,y);
		y.fa:=x;
		y.val:=z;
	end;
	for i:=1 to k do begin
		readln(kk[i]);
		up(kk[i],true);
	end;
	for i:=1 to n do begin
		ans:=0;
		up(i,false);
		for j:=1 to fa[i,0] do begin
			if p[fa[i,j]] then break;
			inc(ans,fa[i,j].val);
		end;
		dfs(fa[i,fa[i,0]]);
		writeln(ans);
	end;
	//close(input);close(output);
end.

