uses	math;
const	maxn=50000+5;
type	node=record
		y,next:longint;
	end;
var	i,j,k,m,n,tot,x,y,ans:longint;
	e:array[1..maxn] of longint;
	h:array[1..maxn] of node;
	p,s:array[0..maxn] of boolean;
	f,g:array[0..maxn,1..2] of longint;
procedure add(x,y:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].next:=e[x];
	e[x]:=tot;
end;
procedure dfs(x:longint);
var	f1,f2,i:longint;
begin
	f1:=1;
	f2:=0;
	p[x]:=true;
	i:=e[x];
	while i<>0 do begin
		if not p[h[i].y] then begin
			dfs(h[i].y);
			f1:=f1+min(f[h[i].y,1],f[h[i].y,2]);
			if f[h[i].y,1]=f[h[i].y,2] then begin
				inc(g[x,1],g[h[i].y,1]);inc(g[x,1],g[h[i].y,1]);
			end else 
			if f[h[i].y,1]<f[h[i].y,2] then inc(g[x,1],g[h[i].y,1]) 
			else inc(g[x,1],g[h[i].y,1]);
			f2:=f2+f[h[i].y,1];
			inc(g[x,2],g[h[i].y,1]);
		end;
		i:=h[i].next;
	end;
	if (f1=1) and (f2=0) then begin
		g[x,1]:=1;g[x,2]:=0;
	end;
	f[x,1]:=f1;
	f[x,2]:=f2;
end;
procedure search(x:longint);
var	i:longint;
	f1,f2:array[1..2] of longint;
begin
	p[x]:=true;
	if f[x,1]>ans then s[x]:=true;//把当前节点炸了结果并不优
	i:=e[x];
	while i<>0 do begin
		if not p[h[i].y] then begin
			f1:=f[x];
			f2:=f[h[i].y];

                        f[x,1]:=f[x,1]-min(f[h[i].y,1],f[h[i].y,2]);
                        f[x,2]:=f[x,2]-f[h[i].y,1];
			//root去除root与叶子结点的边
                        f[h[i].y,1]:=f[h[i].y,1]+min(f[x,1],f[x,2]);
                        f[h[i].y,2]:=f[h[i].y,2]+f[x,1];
			//将root加在叶子结点的叶子上
			//此时叶子为root，root为叶

			search(h[i].y);

			f[x]:=f1;
			f[h[i].y]:=f2;
		end;
		i:=h[i].next;
	end;
end;
begin
	assign(input,'3482.in');//assign(output,'city.out');
	reset(input);//rewrite(output);
	readln(n);
	for i:=1 to n-1 do begin
		readln(x,y);
		add(x,y);
		add(y,x);
	end;
	dfs(1);
	ans:=min(f[1,1],f[1,2]);
	writeln(ans);

	fillchar(p,sizeof(p),0);
	fillchar(s,sizeof(s),0);
	search(1);
	for i:=1 to n do 
		if s[i] then write(i,' ');
	writeln;
	close(input);close(output);
end.
