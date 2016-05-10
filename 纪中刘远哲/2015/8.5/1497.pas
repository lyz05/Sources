const	maxn=100000;
type	node=record
		y,next,val:longint;
	end;
var	i,k,n,tot,x,y,z:longint;
	e:array[0..maxn] of longint;
	h:array[1..2*maxn] of node;
	p:array[1..maxn] of boolean;
	ans,size,num:array[0..maxn] of int64;
procedure add(x,y,z:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].val:=z;
	h[tot].next:=e[x];
	e[x]:=tot;
end;
procedure dfs(x:longint);
var	i:longint;
begin
	size[x]:=num[x];
	i:=e[x];
	while i<>0 do begin
		if p[h[i].y] then begin
			p[h[i].y]:=false;
			dfs(h[i].y);
			inc(size[x],size[h[i].y]);
			inc(ans[x],ans[h[i].y]);
			inc(ans[x],size[h[i].y]*h[i].val);
		end;
		i:=h[i].next;
	end;
end;
procedure work(x:longint);
var	i:longint;
begin
	i:=e[x];
	while i<>0 do begin
		if p[h[i].y] then begin
			p[h[i].y]:=false;
			ans[h[i].y]:=(num[0]-size[h[i].y])*h[i].val+ans[x]-size[h[i].y]*h[i].val;
			work(h[i].y);
		end;
		i:=h[i].next;
	end;
end;
begin
	assign(input,'1497.in');reset(input);
	//assign(output,'.out');rewrite(output);
	
	readln(n);
	for i:=1 to n do begin
		read(num[i]);
		inc(num[0],num[i]);
	end;
	for i:=1 to n-1 do begin
		readln(x,y,z);
		add(x,y,z);
		add(y,x,z);
	end;
	fillchar(p,sizeof(p),1);
	p[1]:=false;
	dfs(1);
	
	fillchar(p,sizeof(p),1);
	p[1]:=false;
	work(1);
	
	ans[0]:=(1<<62);		//change
	for i:=1 to n do 
		if ans[0]>ans[i] then begin
			ans[0]:=ans[i];
			k:=i;
		end;
	writeln(k);
	writeln(ans[0]);
	//close(input);close(output);
end.
