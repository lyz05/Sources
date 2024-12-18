uses	math;
const	maxn=100000;
type	node=record
		y,next,val:longint;
	end;
var	i,j,m,n,tot,x,y,z,minn,tmp:longint;
	e:array[1..maxn] of longint;
	h:array[1..2*maxn] of node;
	w:array[1..maxn,1..maxn] of longint;
	v:array[1..maxn] of boolean;
procedure add(x,y,val:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].next:=e[x];
	h[tot].val:=val;
	e[x]:=tot;
end;
procedure dfs(x,root:longint);
var	i:longint;
begin
	v[x]:=true;
	w[root,x]:=tmp;
	i:=e[x];
	while i<>0 do begin
		if v[h[i].y] then begin
			i:=h[i].next;
			continue;
		end;
		inc(tmp,h[i].val);
			dfs(h[i].y,root);
		dec(tmp,h[i].val);
		i:=h[i].next;
	end;
end;
begin
	assign(input,'tree.in');reset(input);
	assign(output,'tree.out');rewrite(output);

	readln(n);
	for i:=1 to n-1 do begin
		readln(x,y,z);
		add(x,y,z);
		add(y,x,z);
	end;

	for i:=1 to n do begin
		tmp:=0;
		fillchar(v,sizeof(v),false);
		dfs(i,i);
	end;

	minn:=0;
	readln(m);
	for i:=1 to m do begin
		readln(x,y,z);
		z:=z xor minn;
		if (x<=z) and (z<=y) then begin
                        minn:=0;
                        writeln(0);
			continue;
		end;
		minn:=maxlongint;
		for j:=x to y do
			minn:=min(w[z,j],minn);
		writeln(minn);
	end;

	//close(input);close(output);
end.
