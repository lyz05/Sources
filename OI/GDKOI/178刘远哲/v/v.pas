const	maxn=50000;
type	node=record
		y,next:longint;
	end;
var	i,j,k,m,n,tot,x,q,u,v,ans:longint;
	e:array[1..maxn,1..3] of longint;//fa,dep
	h:array[1..2*maxn] of node;
	path:array[1..3,0..maxn] of longint;
procedure add(x,y:longint);
begin
	inc(tot);
	h[tot].y:=y;
	h[tot].next:=e[x,1];
	e[x,1]:=tot;
end;
procedure dfs(x,dep:longint);
var	i:longint;
begin
	e[x,3]:=dep;
	i:=e[x,1];
	while i<>0 do begin
		dfs(h[i].y,dep+1);
		i:=h[i].next;	
	end;
end;
procedure find(x,y:longint);
begin
	fillchar(path,sizeof(path),0);
	path[1,0]:=1;path[2,0]:=1;
	path[1,1]:=x;path[2,1]:=y;
	while e[x,3]>e[y,3] do begin
		x:=e[x,2];
		inc(path[1,0]);
		path[1,path[1,0]]:=x;
	end;
	while e[x,3]<e[y,3] do begin
		y:=e[y,2];
		inc(path[2,0]);
		path[2,path[2,0]]:=y;
	end;
	while e[x,3]=e[y,3] do begin
		if x=y then break;
		x:=e[x,2];
		inc(path[1,0]);
		path[1,path[1,0]]:=x;
		y:=e[y,2];
		inc(path[2,0]);
		path[2,path[2,0]]:=y;
	end;
	//path[3,0]:=path[1,0]+path[2,0]-1;
	for i:=1 to path[1,0] do begin
		inc(path[3,0]);
		path[3,path[3,0]]:=path[1,i];
	end;
	for i:=path[2,0]-1 downto 1 do begin
		inc(path[3,0]);
		path[3,path[3,0]]:=path[2,i];
	end;
end;
function work:longint;
var	i:longint;
begin
	i:=1;
	while (i<path[3,0]) and (path[3,i]>path[3,i+1]) do inc(i);
	while (i<path[3,0]) and (path[3,i]<path[3,i+1]) do inc(i);
	work:=i;
        i:=1;
	while (i<path[3,0]) and (path[3,i]<path[3,i+1]) do inc(i);
	while (i<path[3,0]) and (path[3,i]>path[3,i+1]) do inc(i);
	if i>work then work:=i;
end;
{
function work:longint;
var	j,k,len,kk:longint;
	flag:boolean;
begin
	len:=path[3,0];
	j:=2;
	flag:=false;
	while (j<=len) and (path[3,j-1]<path[3,j]) do inc(j);
        dec(j);
        if j=1 then
		while (j<=len) and (path[3,j-1]>path[3,j]) do inc(j)
	else flag:=true;
	for kk:=path[3,0] downto j do begin
		k:=kk;
		if flag then
			while (path[3,k-1]>path[3,k]) and (k>j) do dec(k)
		else
			while (path[3,k-1]<path[3,k]) and (k>j) do dec(k);
		if k=j+1 then break;
	end;
	exit(kk);
end;}
begin
	assign(input,'v.in');reset(input);
	assign(output,'v.out');rewrite(output);

	readln(n);
	//h[1].fa:=0;h[1].dep:=1;
	for i:=2 to n do begin
		read(x);
		//add(i,x);
		add(x,i);
		e[i,2]:=x;
	end;
	dfs(1,1);
	ans:=0;
	readln(q);
	for k:=1 to q do begin
		readln(u,v);
		u:=u xor ans;v:=v xor ans;
		find(u,v);
		ans:=work;
		writeln(ans);
	end;
	close(input);close(output);
end.
