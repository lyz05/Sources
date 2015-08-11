const	dir:array[1..4,1..2] of longint=((1,0),(-1,0),(0,1),(0,-1));
	maxn=500+5;
type	arr=record
		x,y,v:longint;
	end;
var	i,j,m,n,d,tot,ans,low,maxx:longint;
	p:array[0..maxn,0..maxn] of boolean;
	map,ok:array[0..maxn,0..maxn] of longint;
	inf:array[0..maxn*maxn] of arr;
	flag:boolean;
procedure qsort(l,r:longint);
var	m,i,j:longint;
begin
	m:=inf[(l+r) div 2].v;
	i:=l;j:=r;
	repeat
		while inf[i].v>m do inc(i);
		while inf[j].v<m do dec(j);
		if i<=j then begin
			inf[0]:=inf[i];
			inf[i]:=inf[j];
			inf[j]:=inf[0];
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;
procedure dfs(x,y,f:longint);
var	xx,yy,i:longint;
begin
	if not flag then exit;
	for i:=1 to 4 do begin
		xx:=x+dir[i,1];yy:=y+dir[i,2];
		if (xx>0) and (xx<=n) and (yy>0) and (yy<=m) and
		(ok[xx,yy]<f) and (map[xx,yy]>low) then begin
			if (map[xx,yy]>inf[f].v) or (not p[xx,yy]) then
			begin			
			//找到一个(xx,yy)被访问过且不是答案，与此点联通的答案的v值>
			//map[xx,yy],inf[f].v<map[xx,yy],所以inf.v<联通的答案
				flag:=false;
				exit;
			end;
			ok[xx,yy]:=f;
			dfs(xx,yy,f);
			if not flag then begin
				p[x][y]:=false;
				exit;
			end;
		end;
	end;
end;
begin
        assign(input,'3450.in');reset(input);
	
	tot:=0;maxx:=0;
	readln(n,m,d);
	for i:=1 to n do 
		for j:=1 to m do begin
			read(map[i,j]);
			inc(tot);
			inf[tot].x:=i;inf[tot].y:=j;inf[tot].v:=map[i,j];
			if map[i,j]>maxx then maxx:=map[i,j];
		end;
	qsort(1,tot);
	fillchar(p,sizeof(p),true);
	ans:=0;
	for i:=1 to tot do begin
		if p[inf[i].x][inf[i].y] then begin
			if inf[i].v=maxx then inc(ans) else begin
				flag:=true;
				ok[inf[i].x,inf[i].y]:=i;
				low:=inf[i].v-d;
				dfs(inf[i].x,inf[i].y,i);
				if flag then inc(ans) else
					p[inf[i].x,inf[i].y]:=false;
			end;
		end;
	end;
	writeln(ans);
end.
