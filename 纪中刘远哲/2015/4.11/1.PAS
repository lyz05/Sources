const	maxn=50;maxm=50;
	dit:array[1..4,1..2] of integer=((1,0),(0,1),(-1,0),(0,-1));
type	arr=array[1..maxn,1..maxm] of longint;
var	n,m,i,j,x,y,z,ans:longint;
	a1,a2:arr;
	map:array[1..maxn] of string;
	//flag:array[1..maxn,1..maxm] of boolean;
	dir:array[1..3,1..2] of longint;
	list:array[1..1000*maxn*maxm,1..2] of longint;
	//有多个*，需要多次处理
function check(x,y:longint):boolean;
begin
	if (x>n) or (y>m) or (x<1) or (y<1) then exit(false) else begin
		if (map[x,y]='X') or (map[x,y]='D') then
		       	exit(false) else exit(true);
	end;
end;
function check1(x,y:longint):boolean;
begin
	if (x>n) or (y>m) or (x<1) or (y<1) then exit(false) else begin
		if (map[x,y]='X') then
		       	exit(false) else exit(true);
	end;
end;
procedure bfs(x,y:longint;var a:arr);
var	i,l,r,tx,ty:longint;
begin
	l:=1;r:=1;
	list[1,1]:=x;list[1,2]:=y;
	a[x,y]:=0;
	while l<=r do begin
		x:=list[l,1];y:=list[l,2];
		for i:=1 to 4 do begin
			tx:=x+dit[i,1];ty:=y+dit[i,2];
			if check(tx,ty) then begin
				if a[tx,ty]<=(a[x,y]+1) then continue;
				inc(r);
				list[r,1]:=tx;list[r,2]:=ty;
				a[tx,ty]:=a[x,y]+1;
			end;
		end;
                inc(l);
	end;
end;

procedure bfs1(x,y:longint;var a:arr);
var	i,l,r,tx,ty:longint;
begin
	l:=1;r:=1;
	list[1,1]:=x;list[1,2]:=y;
	a[x,y]:=0;
	while l<=r do begin
		x:=list[l,1];y:=list[l,2];
		for i:=1 to 4 do begin
			tx:=x+dit[i,1];ty:=y+dit[i,2];
			if check1(tx,ty) and (a1[x,y]-a[x,y]>0) then begin
                                if a[tx,ty]<=(a[x,y]+1) then continue;
                                inc(r);
				list[r,1]:=tx;list[r,2]:=ty;
				a[tx,ty]:=a[x,y]+1;
				if (tx=dir[2,1]) and (ty=dir[2,2]) then
				begin
					writeln(a[tx,ty]);
					halt;
				end;
			end;
		end;
                inc(l);
	end;
end;
begin
	assign(input,'1.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(n,m);
	fillchar(a1,sizeof(a1),125);
	for i:=1 to n do begin
		readln(map[i]);
		for j:=1 to m do begin
			case map[i,j] of
				'D':begin
					dir[2,1]:=i;dir[2,2]:=j;
				end;
				'S':begin
					dir[1,1]:=i;dir[1,2]:=j;
				end;
			end;
		end;
	end;
	for i:=1 to n do
		for j:=1 to m do
			if map[i,j]='*' then bfs(i,j,a1);
	ans:=-1;
        fillchar(a2,sizeof(a2),125);
	bfs1(dir[1,1],dir[1,2],a2);
	writeln('KAKTUS');
end.
