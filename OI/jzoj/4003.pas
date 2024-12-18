uses	math;
type	node=record
		tov,next,f,v,re:longint;
	end;
const	maxn=100+5;maxm=maxn;
	maxt=maxn*maxm<<1+1;maxs=0;
	maxe=(maxn*maxm*11)<<1;
	maxl=55;
	maxx=maxlongint>>1;
	Direct:array[1..8,1..2]of longint=(
		(1,0),(-1,0),(0,1),(0,-1),
		(1,1),(-1,-1),(1,-1),(-1,1));
	Alpha='abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
var	i,m,n,tt:longint;
	s,t,tot,len:longint;
	e,dis:array[maxs..maxt] of longint;
	h:array[1..maxe] of node;
	ch:array[1..maxn,1..maxm] of char;
	cnt:Array[1..maxn,1..maxm] of longint;
	p:array[1..maxl] of longint;
	stack:array[1..maxt] of longint;
	w:string;
	maxflow:int64;
function get(x,y:longint):longint;
begin
	exit((x-1)*m+y);
end;
function id1(x,y:longint):longint;
begin
	exit(get(x,y)<<1-1);
end;
function id2(x,y:longint):longint;
begin
	exit(get(x,y)<<1);
end;

procedure add(x,y,full,rev:longint);
begin
	inc(tot);
	h[tot].tov:=y;
	h[tot].f:=full;
	h[tot].re:=tot+rev;
	h[tot].next:=e[x];
	e[x]:=tot;
end;

procedure build(x,y,full:longint);
begin
	add(x,y,full,1);
	add(y,x,0,-1);
end;

function bfs:boolean;
var	i,x,y,head,tail:longint;
begin
	head:=0;
	tail:=1;
	stack[1]:=s;
	fillchar(dis,sizeof(dis),0);
	dis[s]:=1;
	repeat
		inc(head);
		x:=stack[head];
		i:=e[x];
		while i<>0 do begin
			y:=h[i].tov;
			if (h[i].f-h[i].v>0) and (dis[y]=0) then begin
				dis[y]:=dis[x]+1;
				inc(tail);
				stack[tail]:=y;
			end;
			i:=h[i].next;
		end;
	until head=tail;
	exit(dis[t]<>0);
end;

function aug(x,flow:longint):longint;
var	tmp,i,y:longint;
begin
	if x=t then exit(flow);
	aug:=0;
	i:=e[x];
	while i<>0 do begin
		y:=h[i].tov;
		if (h[i].f-h[i].v>0) and (dis[y]=dis[x]+1) then begin
			tmp:=aug(y,min(flow,h[i].f-h[i].v));
			if tmp>0 then begin
				inc(h[i].v,tmp);
				dec(h[h[i].re].v,tmp);
				inc(aug,tmp);
				dec(flow,tmp);
				if flow=0 then break;	
			end;
		end;
		i:=h[i].next;
	end;

end;

procedure scanf;
var	i,j:longint;
begin
	fillchar(h,sizeof(h),0);
	fillchar(e,sizeof(e),0);
	fillchar(p,sizeof(p),0);
	tot:=0;
	readln(n,m);
	for i:=1 to n do begin
		for j:=1 to m do read(ch[i,j]);
		readln;
	end;
	for i:=1 to n do begin
		for j:=1 to m do read(cnt[i,j]);
		readln;
	end;
	readln(w);

	len:=length(w);
	for i:=1 to len do p[pos(w[i],alpha)]:=i;
end;

procedure solve;
var	x,y,drt,newx,newy:longint;
begin
	s:=0;
	t:=n*m*2+1;
	for x:=1 to n do 
		for y:=1 to m do begin
			if ch[x,y]=w[1] then 
				build(s,id1(x,y),maxx);
			if ch[x,y]=w[len] then 
				build(id2(x,y),t,maxx);
			build(id1(x,y),id2(x,y),cnt[x,y]);
			for drt:=1 to 8 do begin
				newx:=x+direct[drt,1];
				newy:=y+direct[drt,2];
				if (1<=newx)and(newx<=n) and (1<=newy)and(newy<=m)
				then
				if (p[pos(ch[x,y],alpha)]<>0)and(p[pos(ch[newx,newy],alpha)]<>0) then
				if p[pos(ch[x,y],alpha)]+1=p[pos(ch[newx,newy],alpha)] then
					build(id2(x,y),id1(newx,newy),maxx);
			end;

		end;
	maxflow:=0;
	while bfs do
		inc(maxflow,aug(s,maxx));
end;

begin
	//assign(input,'4003.in');reset(input);
	//assign(output,'4003.out');rewrite(output);

	readln(tt);
	for i:=1 to tt do begin
		scanf;
		solve;
		writeln('Case #',i,': ',maxflow);
	end;
	//close(input);close(output);
end.
