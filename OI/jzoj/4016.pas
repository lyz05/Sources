uses	math;
const	maxn=50+2;maxl=10;
	dir:array[1..4,1..2] of integer=((0,1),(0,-1),(1,0),(-1,0));
var	n,m,i,j,k,tot:longint;
	s:array[1..maxn] of string;
	num:array[1..maxl,1..2] of longint;
	ans:array[0..maxl] of longint;
	f:array[1..maxn*maxn*(1 shl maxl),0..3] of longint;
	p:array[1..maxn,1..maxn,0..1 shl maxl] of boolean;
procedure bfs(x,y:longint);
var	l,r,state,now,i,sum,x1,y1:longint;
	flag:boolean;
	//state表示num中的点的向上射线的奇偶性
	//state为now单独取出的一位
begin
	l:=0;r:=1;
	f[1,1]:=x;f[1,2]:=y;
	while l<r do begin
		inc(l);
		x:=f[l,1];
		y:=f[l,2];
		state:=f[l,0];now:=0;
		if (x=0) and (y=0) and (l<>1) then begin //找到一条回路
			flag:=true;
			i:=0;sum:=0;
			while state<>0 do begin	//取出状态，统计信息
				now:=state mod 2;
				state:=state>>1;
				inc(i);
				if now=1 then begin//num[i]被包含
					if s[num[i,1],num[i,2]]='X' then
				       	begin
						flag:=false;//非法包含
						break;
					end else inc(sum);
				end;
			end;
			if (flag) and (ans[sum]=0) then ans[sum]:=f[l,3];
			//广搜找到最小值
			continue;
		end;
		for i:=1 to 4 do begin
			x1:=x+dir[i,1];
			y1:=y+dir[i,2];
			if (x1<0)or(y1<0)or(x1>n)or(y1>m) then continue;
			now:=state;
			if (i<=2) then begin//将对射线的奇偶性造成影响
				for j:=1 to tot do 
					if (num[j,2]=max(y,y1))and(num[j,1]>x1)
					then 
						now:=now xor (1<<(j-1));
			end;
			if p[x1,y1,now] then continue;
			p[x1,y1,now]:=true;
			inc(r);
			f[r,1]:=x1;
			f[r,2]:=y1;
			f[r,0]:=now;
			f[r,3]:=f[l,3]+1;
			//对于向下或左右都会造成距离的增加1
		end;
	end;

end;
begin
	//assign(input,'4016.in');reset(input);
	//assign(output,'.out');rewrite(output);

	n:=0;tot:=0;
	while not eof do begin
		inc(n);
		readln(s[n]);
		if n=1 then m:=length(s[n]);
		for i:=1 to m do begin
			if s[n][i]<>'.' then begin
				inc(tot);
				num[tot,1]:=n;
				num[tot,2]:=i;
				if s[n][i]='I' then inc(ans[0])
			end;
		end;
	end;
	bfs(0,0);
	for i:=1 to ans[0] do writeln(ans[i]);
end.

