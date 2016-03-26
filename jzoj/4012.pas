const	maxn=1000;maxm=maxn;maxk=10;mo=1000000007;
var	i,j,k,n,m,clr:longint;
	map:array[1..maxn,1..maxm] of longint;
	pp:array[1..maxn,1..maxm] of boolean;
	p:array[1..maxk,1..2] of longint;
function dfs(x,y:longint):longint;
var	i,j,cnt,tx,ty:longint;
begin
	if y=m+1 then begin
		inc(x);
		y:=1;
	end;
	if x=n+1 then begin
		exit(1);
	end;
	dfs:=0;
	if pp[x,y] then begin
		i:=map[x,y];
		if (p[i,1]<>0) and ((p[i,1]<=x) and (p[i,2]<=y)) 
			and ((p[i,1]<>x) or (p[i,2]<>y)) then exit(0);
		tx:=p[i,1];ty:=p[i,2];
		p[i,1]:=x;p[i,2]:=y;	
			dfs:=dfs(x,y+1);
		p[i,1]:=tx;p[i,2]:=ty;
        end else begin
		cnt:=0;
		for i:=1 to k do begin
			if p[i,1]=0 then begin	//没有选过
				inc(cnt);
				j:=i;
			end else begin
				if (p[i,1]<=x) and (p[i,2]<=y) then 
					continue;	//选过，无法再选
				tx:=p[i,1];ty:=p[i,2];
				p[i,1]:=x;p[i,2]:=y;	//选过，再选
				map[x,y]:=i;
				dfs:=(dfs+dfs(x,y+1)) mod mo;
				map[x,y]:=0;
				p[i,1]:=tx;p[i,2]:=ty;
			end;
		end;
		if cnt>0 then begin
			tx:=p[j,1];ty:=p[j,2];
			p[j,1]:=x;p[j,2]:=y;
			map[x,y]:=j;
			dfs:=(dfs+cnt*dfs(x,y+1)) mod mo;
			map[x,y]:=0;
			p[j,1]:=tx;p[j,2]:=ty;
		end;
	end;
end;
procedure print;
begin
	writeln(0);
	halt;
end;
begin
	assign(input,'4012.in');reset(input);
	//assign(output,'4012.out');rewrite(output);

	readln(n,m,k);
	for i:=1 to n do 
		for j:=1 to m do begin
			read(map[i,j]);
			clr:=map[i,j];
			if clr<>0 then begin
				pp[i,j]:=true;
				if (p[clr,1]<>0) and 
					(p[clr,1]<=i) and
				       	(p[clr,2]<=j) then print;
				p[clr,1]:=i;
				p[clr,2]:=j;
			end;
			
		end;
	if n+m-1>k then writeln(0) else begin
		writeln(dfs(1,1));
	end;
end.
