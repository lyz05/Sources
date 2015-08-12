const
	Maxn=105;
	Maxm=105;
	Maxs=0;
	Maxt=Maxn*Maxm<<1+1;
	Maxe=(Maxn*Maxm*10+Maxn*Maxm)<<1;
	Maxl=60;
	Inf=Maxlongint>>1;
	Alpha='abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
var
	Direct:array[1..8,1..2]of longint=((1,0),(-1,0),(0,1),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1));
	Tov,Next,f,v,Re:array[1..Maxe]of longint;
	Mat:array[1..Maxn,1..Maxm]of longint;
	Last,d:array[Maxs..Maxt]of longint;
	Ch:array[1..Maxn,1..Maxm]of char;
	Que:array[1..Maxt]of longint;
	p:array[1..Maxl]of longint;
	w:array[1..Maxl]of char;
	Tot,n,m,Len,s,t,Cnt:longint;
	MaxFlow:int64;
function Min(x,y:longint):longint;
begin
	if x<y then
		exit(x)
	else
		exit(y);
end;

function Get(x,y:longint):longint;
begin
	exit((x-1)*m+y);
end;

function ID1(x,y:longint):longint;
begin
	exit(Get(x,y)<<1-1);
end;

function ID2(x,y:longint):longint;
begin
	exit(Get(x,y)<<1);
end;

procedure Insert(x,y,Full,Rev:longint);
begin
	inc(Tot);
	Tov[Tot]:=y;
	f[Tot]:=Full;
	Re[Tot]:=Tot+Rev;
	Next[Tot]:=Last[x];
	Last[x]:=Tot;
end;

procedure Build(x,y,Full:longint);
begin
	Insert(x,y,Full,1);
	Insert(y,x,0,-1);
end;

function Bfs:boolean;
var
	i,x,y,Head,Tail:longint;
begin
	Head:=0;
	Tail:=1;
	Que[1]:=s;
	fillchar(d,sizeof(d),0);
	d[s]:=1;
	repeat
		inc(Head);
		x:=Que[Head];
		i:=Last[x];
		while i<>0 do
		begin
			y:=Tov[i];
			if (f[i]-v[i]>0) and (d[y]=0) then
			begin
				d[y]:=d[x]+1;
				inc(Tail);
				Que[Tail]:=y;
			end;
			i:=Next[i];
		end;
	until Head=Tail;
	exit(d[t]<>0);
end;

function Aug(x,Flow:longint):longint;
var
	Temp,i,y:longint;
begin
	if x=t then
		exit(Flow);
	Aug:=0;
	i:=Last[x];
	while i<>0 do
	begin
		y:=Tov[i];
		if (f[i]-v[i]>0) and (d[y]=d[x]+1) then
		begin
			Temp:=Aug(y,Min(Flow,f[i]-v[i]));
			if Temp>0 then
			begin
				inc(v[i],Temp);
				dec(v[Re[i]],Temp);
				inc(Aug,Temp);
				dec(Flow,Temp);
				if Flow=0 then
					break;
			end;
		end;
		i:=Next[i];
	end;
end;

procedure NetWork_Flow;
begin
	MaxFlow:=0;
	while Bfs do
		inc(MaxFlow,Aug(s,Inf));
end;

procedure Scanf;
var
	i,j:longint;
	St:string;
begin
	inc(Cnt);
	fillchar(Tov,sizeof(Tov),0);
	fillchar(Next,sizeof(Next),0);
	fillchar(f,sizeof(f),0);
	fillchar(v,sizeof(v),0);
	fillchar(Re,sizeof(Re),0);
	fillchar(Last,sizeof(Last),0);
	fillchar(p,sizeof(p),0);
	Tot:=0;
	readln(n,m);
	for i:=1 to n do
	begin
		for j:=1 to m do
			read(Ch[i,j]);
		readln;
	end;
	for i:=1 to n do
	begin
		for j:=1 to m do
			read(Mat[i,j]);
		readln;
	end;
	readln(St);
	Len:=length(St);
	for i:=1 to Len do
	begin
		w[i]:=St[i];
		p[pos(w[i],Alpha)]:=i;
	end;
end;

procedure Solve;
var
	x,y,Drt,Newx,Newy:longint;
begin
	s:=0;
	t:=n*m*2+1;
	for x:=1 to n do
		for y:=1 to m do
		begin
			if Ch[x,y]=w[1] then
				Build(s,ID1(x,y),Inf);
			if Ch[x,y]=w[Len] then
				Build(ID2(x,y),t,Inf);
			Build(ID1(x,y),ID2(x,y),Mat[x,y]);
			for Drt:=1 to 8 do
			begin
				Newx:=x+Direct[Drt,1];
				Newy:=y+Direct[Drt,2];
				if (1<=Newx) and (Newx<=n) and (1<=Newy) and (Newy<=m) then
					if (p[pos(Ch[x,y],Alpha)]<>0) and (p[pos(Ch[Newx,Newy],Alpha)]<>0) then
						if p[pos(Ch[x,y],Alpha)]+1=p[pos(Ch[Newx,Newy],Alpha)] then
							Build(ID2(x,y),ID1(Newx,Newy),Inf);
			end;
		end;
	NetWork_Flow;
end;

procedure Printf;
begin
	writeln('Case #',Cnt,': ',MaxFlow);
end;

procedure Main;
var
	t:longint;
begin
	//assign(input,'wordcount.in');
	//assign(output,'wordcount.out');
	//reset(input);
	//rewrite(output);
	readln(t);
	Cnt:=0;
	while t>0 do
	begin
		Scanf;
		Solve;
		Printf;
		dec(t);
	end;
	//close(input);
	//close(output);
end;

begin
	Main;
end.
