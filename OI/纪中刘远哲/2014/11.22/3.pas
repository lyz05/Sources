const	maxn=20000;maxx=maxlongint-123;
type	node=record
		next,y,val:longint;
	end;
var	i,j,k,m,n,q,tot,tmp,x,y,z:longint;
	e:array[1..maxn] of longint;
	h:array[1..maxn] of node;
	ok,p:array[1..maxn] of boolean;
	ans,ans1,ans2:int64;
procedure add(x,y,z:longint);
begin
	inc(tot);
	h[tot].val:=z;
	h[tot].y:=y;
	h[tot].next:=e[x];
	e[x]:=tot;
end;
procedure dfs(deep,x,y:longint);
var	i,yy,val:longint;
begin
	if deep>n then exit;
	if tmp>ans then exit;
	if x=y then begin
		ans:=tmp;
		exit;
	end;

	i:=e[x];
	while i<>0 do begin
		yy:=h[i].y;
		val:=h[i].val;
		if ((not ok[yy]) or p[yy]) and (yy<>y) then begin
			i:=h[i].next;
			continue;
		end;

		inc(tmp,val);
		p[yy]:=true;
	 		dfs(deep+1,yy,y);
		p[yy]:=false;
		dec(tmp,val);

		i:=h[i].next;
	end;
end;
begin
	readln(n,m,k,q);
	for i:=1 to m do begin
		readln(x,y,z);
		add(x,y,z);
	end;
	for i:=1 to k do begin
		read(x);
		ok[x]:=true;
	end;
	for i:=1 to q do begin
		readln(x,y);
		tmp:=0;ans:=maxx;
		p[x]:=true;
		dfs(1,x,y);
		if ans<>maxx then begin
			inc(ans1);
			inc(ans2,ans);
		end;
                p[x]:=false;
	end;
	writeln(ans1);
	writeln(ans2);
end.
