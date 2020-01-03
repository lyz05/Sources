uses	math;
const	maxn=50;maxm=maxn;oo=2105376125;
var	n,m,i,j,edge,minn,cnt:longint;
	map:array[1..maxn] of string[maxm];
	flag:array[0..maxn,0..maxm] of boolean;
	ans:array[1..maxn*maxm] of longint;
	{p:array[1..maxn*maxm] of longint;}
{function get(x,y:longint):longint;
begin
	exit((x-1)*m+y);
end;
function getfather(x:longint):longint;
begin
	if x=p[x] then exit(x);
	p[x]:=getfather(p[x]);
	exit(p[x]);
end;
procedure add(x,y:longint);
var	i,j:longint;
begin
	i:=getfather(x);
	j:=getfather(y);
	p[i]:=j;
end;}
procedure check;
var	i,j:longint;
begin
	{	for i:=1 to n*m do 
		p[i]:=i;
	for i:=1 to n do
		for j:=1 to m do begin
			if flag[i,j] and flag[i-1,j] then add(get(i,j),get(i-1,j));
			if flag[i,j] and flag[i,j-1] then add(get(i,j),get(i,j-1));
		end;
		}
	ans[cnt]:=min(ans[cnt],minn<<1+edge);
end;
procedure dfs(x,y:longint);
var	i,tminn,t:longint;
begin
	if y>m then begin
		inc(x);
		y:=1;
	end;
	if x>n then begin
		check;
		exit;
	end;
	
	if map[x,y]<>'X' then begin
		for i:=1 to 2 do begin
			if odd(i) then begin
				if map[x,y]='I' then inc(cnt);
				t:=x-1+y-1;
				tminn:=minn;
				if t<minn then minn:=t;
				inc(edge,4);
				if flag[x-1,y] then dec(edge,2);
				if flag[x,y-1] then dec(edge,2);
				flag[x,y]:=true;
			end else begin
				if map[x,y]='I' then dec(cnt);
				minn:=tminn;
				flag[x,y]:=false;
				if flag[x,y-1] then inc(edge,2);
				if flag[x-1,y] then inc(edge,2);
				dec(edge,4);
			end;
			dfs(x,y+1);
		end;
	end else dfs(x,y+1);
end;
begin
	assign(input,'enclosure.in');reset(input);
	assign(output,'enclosure.out');rewrite(output);

	i:=0;
	while not eof do begin
		inc(i);
		readln(map[i]);
	end;
	n:=i;
	m:=length(map[1]);
	
	minn:=maxlongint>>1;cnt:=0;
	fillchar(ans,sizeof(ans),125);

	dfs(1,1);

	i:=1;
	while ans[i]<>oo do begin
		writeln(ans[i]);
		inc(i);
	end;
	close(input);close(output);
end.
