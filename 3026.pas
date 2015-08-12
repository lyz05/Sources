const	maxn=10+5;
type node=record
		a:array[0..maxn,0..maxn] of longint;
			end;
var	i,n:longint;
	now,tmp:node;
	load:array[1..maxn] of node;
	flag:boolean;
	tot:array[1..maxn] of longint;
	ttot:array[1..maxn,1..maxn] of longint;
	ans:array[1..maxn,1..3] of longint;
procedure init;
var	i,x:longint;
begin
	readln(n);
	for i:=1 to 5 do begin
		read(x);
		while x<>0 do begin
			inc(now.a[i,0]);
			now.a[i][now.a[i,0]]:=x;
			inc(tot[x]);
			read(x);
		end;
	end;
end;
procedure swap(var x,y:longint);
var	t:longint;
begin
	t:=x;
	x:=y;
	y:=t;
end;
procedure fall;
var	i,j,k:longint;
begin
	for i:=1 to 5 do 
		for j:=2 to 7 do 
			if (now.a[i,j]>0) and (now.a[i,j-1]=0) then begin
				k:=j-1;
				while (k>=1) and (now.a[i,k]=0) do dec(k) ;
				inc(k);
				swap(now.a[i,j],now.a[i,k]);
			end;
end;
procedure remark;
var	i,j:longint;
begin
	for i:=1 to 5 do 
		for j:=1 to 7 do begin
			if (now.a[i][j]>0) then begin
				if (now.a[i][j]=now.a[i][j+1]) and (now.a[i,j]=now.a[i,j-1]) then begin
					tmp.a[i,j-1]:=1;
					tmp.a[i,j]:=1;
					tmp.a[i,j+1]:=1;
				end;
				if (now.a[i][j]=now.a[i+1][j]) and (now.a[i,j]=now.a[i-1,j]) then begin
					tmp.a[i+1,j]:=1;
					tmp.a[i,j]:=1;
					tmp.a[i-1,j]:=1;
				end;
			end;
		end;
end;

procedure clean;
var	inf:boolean;
	i,j:longint;
begin
	remark;
	inf:=false;
	for i:=1 to 5 do 
		for j:=1 to 7 do 
			if (tmp.a[i,j]>0) then begin
				tmp.a[i,j]:=0;
				dec(tot[now.a[i,j]]);
				now.a[i,j]:=0;
				inf:=true;
			end;
	if inf then begin
		fall;
		clean;
	end;
end;
procedure move(x,y,k:longint);
begin
	swap(now.a[x,y],now.a[x+k][y]);
	fall;
	clean;
end;
function check:boolean;
var	i,cnt:longint;
begin
	cnt:=0;
	for i:=1 to 10 do 
		if tot[i]>0 then inc(cnt,tot[i]);
	exit(cnt=0);
end;
procedure dfs(step:longint);
var	i,j,k:longint;
begin
	if flag then exit;
	if step>n then begin
		flag:=check;
		exit;
	end;

	load[step]:=now;
	ttot[step]:=tot;

	for i:=1 to 5 do 
	for j:=1 to 7 do 
		if now.a[i,j]>0 then 
			for k:=1 downto -1 do begin
				if k=0 then continue;
				if ((k=-1)and(now.a[i-1][j]>0)) or (now.a[i+k][j]=now.a[i][j]) then continue;
				ans[step][1]:=i-1;ans[step][2]:=j-1;ans[step][3]:=k;
				move(i,j,k);
				dfs(step+1);
				if flag then exit;
				now:=load[step];
				tot:=ttot[step];
			end;
end;
begin
	assign(input,'3026.in');reset(input);
	
	init;
	dfs(1);
	if flag then begin
		for i:=1 to n do 
			writeln(ans[i,1],' ',ans[i,2],' ',ans[i,3]);
	end else 
		writeln(-1);
end.
